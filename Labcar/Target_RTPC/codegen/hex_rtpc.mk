####################################################################
# generic makefile for the top-level executable
#
# Expected variables on entry:
#   UTILITY_DIR
#   TARGET_NAME
#
# Prerequisites: 
#   make.lmi: Include file with local definitions
#
# 2004-10-22 -Fra-
####################################################################

### Global include directory
MAKE_INCDIR := $(UTILITY_DIR)/make/includes

### Common includes
include $(MAKE_INCDIR)/common.mk

### Local include file where needed definitions are to be found
include make.lmi
-include options.lmi

ifndef TARGET_NAME
$(error hex.mk: TARGET_NAME is not defined)
endif

### Object files to be linked together
### We just collect all the .lib, .o, .obj and .a files in the lib directory
WHOLEARCHLIBS := $(wildcard $(TARGET_LIBDIR)/whole-archive/lib*.a) 
 
OBJS := $(wildcard $(TARGET_LIBDIR)/*.o $(TARGET_LIBDIR)/*.a) $(LOCAL_OBJS)

### Path to the resulting executable
MYTARGET := $(TARGET_BINDIR)/$(TARGET_NAME).bin
MYTARGET_REC := $(TARGET_BINDIR)/$(TARGET_NAME).out

### C-Compiler flags
CFLAGS += $(LOCAL_CFLAGS)

### Compose the preprocessor's include path
INC_PATH := $(LOCAL_INCPATH)
INC_PATH += $(TARGET_INCPATH)

CPPFLAGS += $(LOCAL_CPPFLAGS)
CPPFLAGS += $(INC_PATH)

### Compose the compiler's library include path
LIB_PATH := -L$(OBJ_DIR)
LIB_PATH += $(TARGET_LIBINCPATH)
LIB_PATH += $(LOCAL_LIBPATH)

### Linker flags
LDFLAGS += $(LIB_PATH)
### Add the locator file describing on which addresses the code segments shall be located
LDFLAGS +=$(COMP_LDFLAGS)  -Ur


MAPFILE := -Wl,-Map=$(TARGET_BINDIR)/$(TARGET_NAME).map

.PHONY:	all install clean realclean test

include $(MAKE_INCDIR)/build.mk

### Build the record file
all: $(MYTARGET_REC)

$(MYTARGET_REC) : $(MYTARGET)
	@$(ECHO) bs-rec:$(@F)
	-etarget-hex-file-creator -o $(MYTARGET_REC:.out=.hex) $(MYTARGET)
	@$(OBJCOPY) -I binary -O srec $(MYTARGET) $(MYTARGET_REC)
	
	
$(MYTARGET) : $(OBJS) $(WHOLEARCHLIBS)
	@$(ECHO) bs-build:$(@F)
	$(LD) -o $(MYTARGET) $(LDFLAGS) $(EX_LDFLAGS) -L./lib $(MAPFILE) -Wl,--start-group \
		                -Wl,--whole-archive $(WHOLEARCHLIBS) -Wl,--no-whole-archive \
                     		$(OBJS) $(EX_OBJS) $(LOCAL_LIBS) $(EX_LIBS) -Wl,--end-group \
				$(LDFLAGS_END) $(EX_LDFLAGS_END)

clean:  
	@$(ECHO) "bs-clean:$(notdir $(MYTARGET))"
	@$(RM) $(MYTARGET)
	@$(RM) $(TARGET_BINDIR)/$(TARGET_NAME).map

realclean: clean

test:
	@$(ECHO) $(OBJS) $(WHOLEARCHLIBS)
	

