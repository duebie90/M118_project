####################################################################
# generic makefile for the top-level libraries
#
# Expected variables on entry:
#   UTILITY_DIR
#
# Prerequisites: 
#   make.lmi: Include file describing the subdirectories to be used
#
# 2004-08-02 -Fra-
####################################################################

### Global include directory
MAKE_INCDIR := $(UTILITY_DIR)/make/includes

### Local include file where the SUBDIR variable is defined
include make.lmi
-include options.lmi

### Just do the subdirs
include $(MAKE_INCDIR)/subdirs.mk