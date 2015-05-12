package RTPCSimulinkLib;

# ########################################################################
# Package RTPCSimulinkLib
# 
# Perl package to build the simulinklib on the LabCar RTPC using the
# sources on the User PC
#
# (c) 2003,2004 ETAS GmbH, Germany
# 
# The function check_and_build() has to be called to check if a
# simulink lib is existing on the RTPC and to build it if neccessary.
# 
#
#
# ########################################################################

use strict;
use Cwd;

my ($ftp, $telnet);

sub upload_hfiles($directory)
{
	my ($startdir) = &cwd;
    my ($directory) = @_;
    print  "bs-rtpc-info: Directory $directory\n";
    chdir $directory or die $!;

    opendir DIRHANDLE, "." or die $!;
    my @direntries = readdir DIRHANDLE;
    close DIRHANDLE;

    my $fn;
    foreach $fn ( @direntries )
    {
        if ( $fn =~ /\.h$/ )
        {
            $fn = lc($fn);
            printf  "bs-rtpc-lib-upload: - %-32s", $fn;
            $ftp->put("$fn") or die $!;
            my $short_name = lc(Win32::GetShortPathName("$fn"));
            if ( $short_name ne $fn )
            {
                print  "   \t($short_name)";
                $telnet->cmd("ln -s $fn $short_name");
            }
            print  "\n";
        }
    }
	chdir($startdir);

    
}

sub upload_files($path)
{
    my ($path) = @_;
    my @files = glob ($path);

    my $fn;
    foreach $fn ( @files )
    {
        {
            $fn = lc($fn);
            printf  "bs-rtpc-lib-upload: - %-32s\n", $fn;
#            $ftp->put("$fn") or die $!;
            $ftp->put("$fn");
        }
    }


    
}




# #######################################################################
#   C H E C K   A N D   B U I L D 
# #######################################################################
sub check_and_build($arg_telnet)
{

    use RTPCAccess;
    use Win32;
    use Win32::TieRegistry;
    
    ($telnet) = @_;

    
    #my ($MATLAB_ROOT);      # 2006-01-16 [Du] {LCO V3.2::DI_GEN_12} Commented out
    my ($MATLAB_REL);
    my @lines;
    my $line;
    my $TARGET_DIR;          # 2006-01-16 [Du] {LCO V3.2::DI_GEN_12} added

    # ######################################################################
    # Arguments:
    my $force_rebuild = 0;

    # #######################################################################
    {
    	$MATLAB_REL=$ENV{MATLAB_RELEASE};
    }
    unless ($MATLAB_REL)
    {
        print "bs-rtpc-info: Simulink library not required.\n";
        return 0;
    }

    # 2006-01-16 [Du] {LCO V3.2::DI_GEN_12} Commented out
    #
    # Determine MATLAB_ROOT:
    #{
    #	$MATLAB_ROOT=$ENV{MATLAB_PATH};
    #}
    #unless ($MATLAB_ROOT)
    #{
    #    print "bs-rtpc-info: Simulink library not required or unsupported Matlab version found\n";
    #    return 0;
    #}

    # 2006-01-16 [Du] {LCO V3.2::DI_GEN_12} added
    {
    	$TARGET_DIR=$ENV{TARGET_MAIN_ROOT};
    }
    unless ($TARGET_DIR)
    {
        print "bs-rtpc-info: Environment Variable TARGET_MAIN_ROOT is not defined! \n";
        return 0;
    }

     
    #print  "bs-rtpc-info: Matlab Root Directory: $MATLAB_ROOT\n\n";
    print  "bs-rtpc-info: Checking for simulink library on RTPC...\n";

    my $REMOTE_BASE_DIR = "/home/labcar";
    #my $SIMULINK_DIR = "$REMOTE_BASE_DIR/simulink/${MATLAB_REL}";
    my $SIMULINK_DIR = "$REMOTE_BASE_DIR/simulink";
    
    # 2006-01-16 [Du] {LCO V3.2::DI_GEN_12} added
    my $LIBRARY_SRC_DIR = "$TARGET_DIR/SimulinkModels/libSrc";
    my $TAR_FILE = "$LIBRARY_SRC_DIR/$MATLAB_REL.tar.gz";

    
    # #############################################################################
    # Check for an already existing simulink library:
    unless ($force_rebuild)
    {
        @lines = $telnet->cmd("labcar_check_lib -d /home/labcar/lib/simulink simulink_$MATLAB_REL");
        if ( $lines[0] =~ /^Found:/)
        {
            print "bs-rtpc-info: Required simulink library found on RTPC\n";
            return 0;
        }

        print "bs-rtpc-info: No simulink library found on RTPC. Building.\n";
    }
    else
    {
        print  "bs-rtpc-info: Building of simulink library forced!\n";
    }
    print  "bs-rtpc-info: Cleaning up...\n";

    $telnet->cmd("mkdir -p $SIMULINK_DIR");
    $telnet->cmd("cd $SIMULINK_DIR");
    #$telnet->cmd("rm -rf *");

    # #############################################################################
    $ftp = &RTPCAccess::ftp_login() or die $!;
    $ftp->cwd($SIMULINK_DIR);

    # #############################################################################

    print  "bs-rtpc-libbuild-start: Building and installing library... (Note: This may take a while)\n";

     
    # 2006-01-16 [Du] {LCO V3.2::DI_GEN_12} added

    if(!(-e $TAR_FILE))
    {
    	 print  "bs-rtpc-error: File not found: $TAR_FILE\n";
    	 die $!;
    }
    
    &upload_files("$TAR_FILE");
    $telnet->cmd("tar -xzf $MATLAB_REL.tar.gz");
    
    
    my @COUNT = $telnet->cmd("ls -l ./$MATLAB_REL/src/*.c | wc -l");
        print  "bs-rtpc-info: Starting compilation: @COUNT files\n";
    
        $telnet->cmd("export CCOPT_ADD='-I $SIMULINK_DIR/$MATLAB_REL/include'");
    $telnet->cmd("cd $SIMULINK_DIR/$MATLAB_REL/src");
    
    $telnet->print("labcar_build_simulink_lib -d /home/labcar/lib/simulink simulink_$MATLAB_REL\n");
    
    
    # BUGFIX: For some strange reason perl is outputting garbage from the previous command. So we just ignore it.
    $line = $telnet->getline( Timeout => 600 );
    do 
    {
      $line = $telnet->getline( Timeout => 600 );
      print $line;
    } until ( $line =~ /^\S*?@\S*?:.*\$\s*$/ );

    #print  "\nbs-rtpc-info: Additional upload of .c Files for inclusion...\n";
    
    # 2006-01-16 [Du] {LCO V3.2::DI_GEN_12} Commented out
    #&upload_files("$MATLAB_ROOT/rtw/c/src/*.c");   
    
    # 2006-01-16 [Du] {LCO V3.2::DI_GEN_12} added
    #$telnet->cmd("unzip additional.zip");

    $ftp->quit();
    print  "\nbs-rtpc-libbuild-end: Compilation ended.\n";
    
    return 0;

}


1;
