####################################################################
# generic object-level makefile 
#
# Contrary to a source-level makefile, this one just puts object
# files and libraries together. No compiling is done.
#
# Expected variables on entry:
#   UTILITY_DIR
#
# Prerequisites: 
#   make.lmi: Include file with local definitions. Must at least
#             contain TARGET_FILE (path to target library)
#             and LOCAL_OBJS (object files to be linked together)
#
# Input:
#   LOCAL_OBJS
#
# Output:
#   OBJ_DIR/TARGET_FILE
#
# 2004-08-02 -Fra-
####################################################################

### Global include directory
MAKE_INCDIR := $(UTILITY_DIR)/make/includes

### Common includes
include $(MAKE_INCDIR)/common.mk

### Local include file where needed definitions are to be found
include make.lmi
-include options.lmi

### No source files!
SRCS :=

### Object files are found in the object directory
OBJS := $(LOCAL_OBJS:%=$(OBJ_DIR)/%)

### Full path to the target file
MYTARGET := $(OBJ_DIR)/$(TARGET_FILE_OBJ)

### Libraries to be installed in the global library directory

MYLIBS := $(LOCAL_LIBS:%=$(OBJ_DIR)/%)
PUB_LIBS := $(MYTARGET) $(MYLIBS)

### Add local paths found in make.lmi (if any) to the global ones
CPPFLAGS += $(LOCAL_CPPFLAGS)
CFLAGS += $(LOCAL_CFLAGS)

INC_PATH := $(LOCAL_INCPATH)
INC_PATH += $(TARGET_INCPATH)

CPPFLAGS += $(INC_PATH)

LIB_PATH := -L$(OBJ_DIR)
LIB_PATH += -L$(TARGET_LIBPATH)
LIB_PATH += -L$(LOCAL_LIBPATH)

LDFLAGS += $(LIB_PATH)

### These targets are not "physical" files
.PHONY:	all install uninstall clean realclean test objdir

### Note: Always include the following makefiles in reverse order how they
### are ordered in the "all" rule

include $(MAKE_INCDIR)/install.mk
include $(MAKE_INCDIR)/build.mk
include $(MAKE_INCDIR)/objdir.mk

### Construct the library, copy it
### to the global library directory
all: $(MYTARGET) install

$(MYTARGET): $(OBJS)
	@$(ECHO) bs-build-lib:$(TARGET_FILE)
### Add files to the archive, overwrite existing, create archive if needed
	$(AR) -rcs $@ $(OBJS)

clean:  uninstall
	@$(ECHO) bs-clean:$(notdir $(MYTARGET))
	@$(RM) $(MYTARGET)

realclean: clean
