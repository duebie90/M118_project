####################################################################
# generic makefile for the top-level executable, RTPC postprocessing
#
# Expected variables on entry:
#   UTILITY_DIR
#   TARGET_NAME
#
# Prerequisites: 
#   make.lmi: Include file with local definitions
#
# 2004-11-03 -Fra-
####################################################################

### Global include directory
MAKE_INCDIR := $(UTILITY_DIR)/make/includes

### Common includes
include $(MAKE_INCDIR)/common.mk

### Local include file where needed definitions are to be found
include make.lmi
-include build.opt

ifndef TARGET_NAME
$(error hex.mk: TARGET_NAME is not defined)
endif

### Object files to be linked together
### We just collect all the .lib, .o, .obj and .a files in the lib directory
 
### Path to the resulting executable delivered by RTPC
MYTARGET := $(TARGET_BINDIR)/$(TARGET_NAME).out
### Path to the patched hex file
MYTARGET_HEX := $(TARGET_BINDIR)/$(TARGET_NAME).hex

### Build the record file
all: $(MYTARGET_HEX)

$(MYTARGET_HEX) : $(MYTARGET)
	@$(ECHO) bs-hex:$(@F)
	$(HEX_PATCHER) $(ETAS_TARGET_DEFS)/$(ETAS_HW_TARGET)/loader.rec $(MYTARGET) $(MYTARGET_HEX)

clean:  
	@$(ECHO) "bs-clean:$(notdir $(MYTARGET))"
	@$(RM) $(MYTARGET)
	@$(ECHO) "bs-clean:$(notdir $(MYTARGET_HEX))"
	@$(RM) $(MYTARGET_HEX)

realclean: clean

test:
	@$(ECHO) $(OBJS)
	

