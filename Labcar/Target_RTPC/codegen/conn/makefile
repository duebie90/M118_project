####################################################################
# generic makefile for mid-level directories which do not
# include any source files
#
# If no subdirs are defined (that is, make.lmi is not present),
# this files defaults into the "src" subdir.
#
# Expected variables on entry:
#   UTILITY_DIR
#
# Prerequisites: 
#   make.lmi: Optional
#
# 2004-08-02 -Fra-
####################################################################

MAKE_INCDIR := $(UTILITY_DIR)/make/includes

### Local include file. If not present, it's ignored
### Note for the interested reader: "-" ignores the error when
### the file is not present
-include make.lmi
-include options.lmi

### If SUBDIRS is not defined (due to a missing make.lmi), just use "src"
SUBDIRS ?= src

include $(MAKE_INCDIR)/subdirs.mk
