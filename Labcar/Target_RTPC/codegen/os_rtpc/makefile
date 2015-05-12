####################################################################
# Makefile for the os_rtpc directory 
#
# Expected variables on entry:
#   UTILITY_DIR
#
# Optional:
#   NO_DEPS: If defined, no dependency information is generated
#
#
# Input:
#   LOCAL_SRCS or all .c files
#
# Output:
#   ./TARGET_FILE
#
# 2004-10-22 -Fra-
####################################################################

### Global include directory
MAKE_INCDIR := $(UTILITY_DIR)/make/includes

### Common includes
include $(MAKE_INCDIR)/common.mk



OBJ_DIR  := .
OBJS     := rtpc_os_config.o
MYTARGET := librtpc_os_config.a


# The C file is generated from the .los file:
GENERATED_C_FILE := $(patsubst %.o,%.c, $(OBJS))



### Libraries to be installed in the global library directory
### Here: Just our target
PUB_LIBS := $(MYTARGET)

LOCAL_INCLUDES := $(COMP_INCPATH)


### These targets are not "physical" files
.PHONY:	all binary install uninstall clean realclean test objdir

### Note: Always include the following makefiles in reverse order how they
### are ordered in the "all" rule

include $(MAKE_INCDIR)/install.mk
include $(MAKE_INCDIR)/build.mk
include $(MAKE_INCDIR)/objdir.mk


### Build the object directory if needed, compile the library, copy it
### to the global library directory
all: binary install

binary: $(MYTARGET)

$(MYTARGET): $(OBJS) $(GENERATED_C_FILE)
	@$(ECHO) bs-build-lib:$(TARGET_FILE)
### Add files to the archive, overwrite existing, create archive if needed
	$(AR) -rcs $@ $(OBJS)

clean:  uninstall
	@$(ECHO) bs-clean:$(OBJ_DIR)
	@$(RM) $(OBJS) $(MYTARGET) $(GENERATED_C_FILE)

realclean: clean

$(GENERATED_C_FILE): default.los
	labcar_osconfig_parse $< $@

### Automatic creation of dependencies -- should be at the end of the Makefile
ifeq ($(MAKE_DEPS),1)
include $(MAKE_INCDIR)/dep.mk
endif
