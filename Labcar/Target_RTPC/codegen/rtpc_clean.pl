
# ###############################################################
#  rtpc_clean.pl
#
#  Perl script to do a make clean on the LabCar RTPC.
#  (c) 2004 ETAS GmbH
#
# ###############################################################

{
	$|=1 ;
	use strict;
    use RTPCAccess;

    my $REMOTE_DIR="/home/labcar";
    my $CODEGEN_DIR="codegen";


	# ###############################################################
	#   Connect via telnet
	# ###############################################################
    my $telnet = &RTPCAccess::telnet_login();

	# ###############################################################
	#   Cleanup RTPC directory
	# ###############################################################
    {
        $telnet->cmd("cd $REMOTE_DIR");
        # Cleanup before compiling...
        $telnet->cmd(String => "rm -rf $CODEGEN_DIR/*", Timeout => 60);
    }

}



