####################################################################
# generic source-level makefile 
#
# Expected variables on entry:
#   UTILITY_DIR
#
# Optional:
#   NO_DEPS: If defined, no dependency information is generated
#
# Prerequisites: 
#   make.lmi: Include file with local definitions. Must at least
#             contain TARGET_FILE (path to target library)
#             Should contain LOCAL_SRCS. If not, all .c are used
#             to build the library
#
# Input:
#   LOCAL_SRCS or all .c files
#
# Output:
#   OBJ_DIR/TARGET_FILE
#
# 2004-02-15 -Fra-
####################################################################

### Global include directory
MAKE_INCDIR := $(UTILITY_DIR)/make/includes

### Common includes
include $(MAKE_INCDIR)/common.mk

### Local include file where needed definitions are to be found
include make.lmi
-include options.lmi

### If source files are defined in make.lmi, used them
SRCS := $(LOCAL_SRCS)

### Build .o files from all .c files
OBJS := $(filter %.o, $(SRCS:%.c=$(OBJ_DIR)/%.o) $(SRCS:%.cpp=$(OBJ_DIR)/%.o) $(SRCS:%.cxx=$(OBJ_DIR)/%.o) $(SRCS:%.cc=$(OBJ_DIR)/%.o))

### Build dependency files from all .c files
ifeq ($(MAKE_DEPS),1)
DEPS := $(SRCS:%.c=$(DEP_DIR)/%.d) 
endif

### Full path to the target file
MYTARGET := $(OBJ_DIR)/$(TARGET_FILE_SRC)

### Libraries to be installed in the global library directory
### Here: Just our target
PUB_LIBS := $(MYTARGET)

### Add local paths found in make.lmi (if any) to the global ones
CPPFLAGS += $(LOCAL_CPPFLAGS)
CFLAGS += $(LOCAL_CFLAGS)
CXXFLAGS += $(LOCAL_CXXFLAGS)
CONLYFLAGS += $(LOCAL_CONLYFLAGS)

INC_PATH := $(LOCAL_INCPATH)
INC_PATH += $(TARGET_INCPATH)

CPPFLAGS += $(INC_PATH)

LIB_PATH := -L$(OBJ_DIR)
LIB_PATH += -L$(TARGET_LIBPATH)
LIB_PATH += -L$(LOCAL_LIBPATH)

LDFLAGS += $(LIB_PATH)

### These targets are not "physical" files
.PHONY:	all binary install uninstall clean realclean test objdir

### Note: Always include the following makefiles in reverse order how they
### are ordered in the "all" rule

include $(MAKE_INCDIR)/install.mk
ifeq ("$(LOCAL_PREPROCESSING)","")
include $(MAKE_INCDIR)/build.mk
else
include $(MAKE_INCDIR)/build_pre.mk
endif
include $(MAKE_INCDIR)/objdir.mk

### Build the object directory if needed, compile the library, copy it
### to the global library directory
all: binary install

binary: objdir $(MYTARGET)

$(MYTARGET): $(OBJS) 
	@$(ECHO) bs-build-lib:$(TARGET_FILE)
### Add files to the archive, overwrite existing, create archive if needed
	$(AR) -rcs $@ $(OBJS) 

clean:  uninstall
	@$(ECHO) bs-clean:$(OBJ_DIR)
	@$(RM) $(OBJS) $(MYTARGET)

realclean: clean
	@$(RM) -r $(OBJ_DIR)

### Automatic creation of dependencies -- should be at the end of the Makefile
ifeq ($(MAKE_DEPS),1)
include $(MAKE_INCDIR)/dep.mk
endif