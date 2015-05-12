package RTPCAccess;

# #############################################################
#  HOSTNAME : IP Address or name of the RTPC
#  
$HOSTNAME = "192.168.40.14";

# #############################################################
#  USERNAME/PASSWORD : Login information for ftp and telnet
#  
my $USERNAME = "labcar";
my $PASSWORD = "";

# #############################################################

use Net::Telnet;
use Net::Ftp;


# #############################################################
#  Open a telnet connection to the RTPC and return the telnet 
#  handle
#  
sub telnet_login_base()
{
    my $telnet = new Net::Telnet( );

    my $rc;
    $rc = $telnet->open( Host => $HOSTNAME,
            Timeout => 8,
         ) or die "bs-rtpc-errconnect: Error: $!";

        
    # No password required for 'labcar', do not use standard login
    $rc = $telnet->waitfor(-match => '/login[: ]*$/i') or die "bs-rtpc-errconnect: Error: $!";
    $rc = $telnet->print($USERNAME) or die $!;


    return $telnet;
}



# #############################################################
#  Open a telnet connection to the RTPC and return the telnet 
#  handle.
#  Also, synchronized the time on RTPC with the time on
#  the host PC.
#  
sub telnet_login()
{

    my $telnet = telnet_login_base();

    my @lines = $telnet->cmd("who am i");
    @lines = $telnet->cmd("labcar_version -b");
    print "bs-rtpc-connect: LABCAR-RTPC $lines[0]";
    print "bs-rtpc-connect: Telnet connection to $HOSTNAME established\n";

    # Set the system time and the current timezone
    {
        my $t = time;
        my $gmt = gmtime($t);
        # Timezone:
        my ($h,$d) = (gmtime($t))[2,6];
        my $gmhours = 24*$d + $h;
        
        ($h,$d) = (localtime($t))[2,6];
        my $localhours = 24*$d + $h;
        my $timezone = ($localhours - $gmhours ) % 24;
        if ($timezone > 12)
        {
            $timezone -= 24;
        }
        $timezone = sprintf("UTC%+i", $timezone);

        $telnet->cmd("set_system_time -z $timezone \"$gmt\"");
    }
    return $telnet;

}

# #############################################################
#  Open a FTP connection to the RTPC and return the telnet 
#  handle - Base version
#  
sub ftp_login_base()
{
    my $ftp = Net::FTP->new($HOSTNAME, Debug => 0, Passive => 1);
    my $rc = $ftp->login($USERNAME);
    $ftp->binary();
    return $ftp;
}


# #############################################################
#  Open a FTP connection to the RTPC and return the telnet 
#  handle and print out the working directory.
#  
sub ftp_login()
{
    my $ftp = ftp_login_base();
    print  "bs-rtpc-info: pwd: " . $ftp->pwd() . "\n";
    return $ftp;
}


1;
