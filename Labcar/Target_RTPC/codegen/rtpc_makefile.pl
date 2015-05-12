
# ###############################################################
#  rtpc_make.pl
#
#  Perl script to do a make on the LabCar RTPC.
#  (c) 2003 ETAS GmbH
#
# ###############################################################

{
	$|=1 ;
	use strict;
    use RTPCAccess;
    use RTPCSimulinkLib;

    my $BUILD_TOOLS_DIR=$ENV{UTILITY_DIR};
    my $REMOTE_CODEGEN_DIR="/home/labcar/codegen";
    
    # Fixing ACL issues
    $ENV{'CYGWIN'} = 'nontsec';
    
    # ###############################################################
    #    Local cleanup
    # ###############################################################
    unlink("compiled.tar");  # Remove any existing compiled.tar

	  # ###############################################################
	  #   Connect via telnet
	  # ###############################################################
    my $telnet = &RTPCAccess::telnet_login();

    # ###############################################################
    #    Check and build simulink library
    # ###############################################################
    {
        &RTPCSimulinkLib::check_and_build($telnet);
    }        

	  # ###############################################################
	  #   Create RTPC directory
	  # ###############################################################
    {
        $telnet->cmd("mkdir -p $REMOTE_CODEGEN_DIR");
        $telnet->cmd("cd $REMOTE_CODEGEN_DIR");
    }

	  # ###############################################################
	  #   Transfer codegen via rsync to target
	  # ###############################################################
    {
       my $excludeFrom = "";
       if( -e "../exclude.txt" )
       {
          $excludeFrom = "--delete-excluded --exclude-from ../exclude.txt";
       }
       system("$BUILD_TOOLS_DIR/rsync/rsync.exe -rltD --delete $excludeFrom . 192.168.40.14::codegen") && 
             die "rsync: Transfer of codegen directory to target failed";
    }

    # ###############################################################
    #   Start make on RTPC
    # ###############################################################
    {
        print  "\nbs-rtpc-start: Starting make on the RTPC...\n";
        my $line;

        # Using print() instead of cmd to see the output line by line
        # during (long time) execution of the command
        print "bs-rtpc-telnet:";
        $telnet->cmd("export TARGET_NAME=$ENV{TARGET_NAME}");
        $telnet->cmd("export MATLAB_RELEASE=$ENV{MATLAB_RELEASE}");
        $telnet->print("labcar_si_make @ARGV\n");
        
        # Read and print the command output line by line 
        do 
        {
            $line = $telnet->getline( Timeout => 600 );
            print $line;
        } until ( $line =~ /^\S*?@\S*?:.*\$\s*$/ );
        # Stop, if the prompt has been reached

        $telnet->close;
    }
    
    # ###############################################################
    #   Transfer compile results back to host
    # ###############################################################
    {
        system("$BUILD_TOOLS_DIR/rsync/rsync.exe -rltD --delete 192.168.40.14::codegen .") && 
           die "rsync: Transfer of codegen directory to host failed";
    }
    
    # ###############################################################
    #   Create Hex File
    # ###############################################################
	## .bin = ELF File
	## .out = SRecord
	## .hex = ETAS specific
    my $TARGET=$ENV{TARGET_NAME};
    my $do_create_hexfile = ( -r "./exe/$TARGET.bin" );
    if ($do_create_hexfile and  -r "./exe/$TARGET.hex" and -r "./exe/$TARGET.bin" )
    {
        # Compare modification time of .hex and .bin file:
        my $mtime_hex = (stat("./exe/$TARGET.hex"))[9];
        my $mtime_bin = (stat("./exe/$TARGET.bin"))[9];

        if ($mtime_hex >= $mtime_bin)
        {
            # .hex file is newer that .bin file => No need to create it
            $do_create_hexfile = 0;
            print "bs-hex: $TARGET.hex has already been created on the target...\n";
        }
    }

    if ($do_create_hexfile)
    {
        my $hexTool = "$BUILD_TOOLS_DIR/hexfilecreator-v1.0/etargethexfilecreator.exe";
        my $loaderRec = "$BUILD_TOOLS_DIR/etarget/rtpc/loader.rec";
        
        print "bs-hex: Create $TARGET.hex ...\n";
        
        system("$hexTool $loaderRec ./exe/$TARGET.out ./exe/$TARGET.hex" ) &&
            die "Could not create $TARGET.hex";
    }
}



