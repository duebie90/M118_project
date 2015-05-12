####################################################################
# the mother of all makefiles
#
# Makes the whole executable by:
# 1. building the libraries
# 2. linking all files together
#
# Prerequisites: See common.mk
#
# 2004-08-12 -Fra-
####################################################################

export EX_CFLAGS :=
export EX_CPPFLAGS :=
export EX_CONLYFLAGS :=

export EX_LDFLAGS :=
export EX_OBJS :=
export EX_LIBS :=
export EX_LDFLAGS_END :=

.PHONY:	rtpc_build

MAKE_INCDIR := $(UTILITY_DIR)/make/includes
include $(MAKE_INCDIR)/common.mk

all install uninstall clean realclean test:
	$(MAKE) -f libs.mk $@
	$(MAKE) -f hex_$(ETAS_HW_TARGET).mk $@
	
rtpc_build:
	$(LC_PERL) -I. rtpc_Makefile.pl
	$(MAKE) -f rtpc_postprocess.mk

rtpc_clean:
	$(LC_PERL) -I. rtpc_clean.pl
	
rtpc_clean_lib:
	$(LC_PERL) -I. rtpc_clean_lib.pl
