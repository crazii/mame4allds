ENDIAN  = EL
#OFORMAT = elf32-littlemips

# Modules are one of: Capcom, VectSega, Classic, Konami, DeasIrem, AtarNamco, Others and Others2 Neogeo
ifeq ($(MODULE),)
MODULE = Classic
endif

TARGET = mame$(MODULE)

# set this the operating system you're building for
# (actually you'll probably need your own main makefile anyways)
# MAMEOS = msdos
MAMEOS = nds

# extension for executables
EXE =

# toolchain path

# CPU core include paths
VPATH=src $(wildcard src/cpu/*)

# compiler, linker and utilities
CROSS := /opt/mipsel-4.1.2-nopic/bin/
CC = $(CROSS)mipsel-linux-gcc
CPP = $(CROSS)mipsel-linux-g++
LD =  $(CROSS)mipsel-linux-ld
ASM =  $(CROSS)mipsel-linux-gcc
OBJCOPY	= $(CROSS)mipsel-linux-objcopy
NM	= $(CROSS)mipsel-linux-nm
OBJDUMP	= $(CROSS)mipsel-linux-objdump
MD = @mkdir
RM = @rm -f
FIND = @find

TOPDIR = .
FS_DIR = $(TOPDIR)/../libsrc/fs
CONSOLE_DIR = $(TOPDIR)/../libsrc/console
KEY_DIR = $(TOPDIR)/../libsrc/key
ZIP_DIR = $(TOPDIR)/../libsrc/zlib
DEVINC = -I../include -I$(FS_DIR) -I$(CONSOLE_DIR) -I$(KEY_DIR) -I$(ZIP_DIR)

#TARGET = downenv
IMAGE_ELF  = $(TARGET).elf
IMAGE_BIN  = $(TARGET).bin
IMAGE_MAP  = $(TARGET).map
IMAGE_PLG  = $(TARGET).plg
IMAGE_SYM  = $(TARGET).sym
IMAGE_DUMP = $(TARGET).dump

EMULATOR = $(TARGET)$(EXE)

#DEFS = -DINLINE="static inline" -Dasm="__asm__ __volatile__" -DLSB_FIRST -DALIGN_INTS -DALIGN_SHORTS -DDINGOO -DMAME_UNDERCLOCK -DMAME_FASTSOUND -DENABLE_AUTOFIRE -DBIGCASE -DMODULE_$(MODULE) -DNDEBUG -D_DEBUG -DMPU_JZ4740
DEFS = -DINLINE="static inline" -Dasm="__asm__ __volatile__" -DLSB_FIRST -DALIGN_INTS -DALIGN_SHORTS -DNDS -DMAME_UNDERCLOCK -DMAME_FASTSOUND -DENABLE_AUTOFIRE -DBIGCASE -DMODULE_$(MODULE) -DNDEBUG
#-DMALLOC_DEBUG=1

W_OPTS    = -Wall -Wno-write-strings -Wno-sign-compare

F_OPTS = -falign-functions -falign-loops -falign-labels -falign-jumps \
	-ffast-math -fsingle-precision-constant -funsafe-math-optimizations \
	-fomit-frame-pointer -fno-builtin -fno-exceptions -fno-common \
	-fstrict-aliasing  -fexpensive-optimizations \
	-finline -finline-functions -fpeel-loops
  
#-mbranch-likely  ? REVIST ?
#CC_OPTS	= -G0 -O3 -mips32 -mtune=mips32 -mno-mips16 -msoft-float -mno-abicalls -mbranch-likely -fno-pic $(W_OPTS) $(F_OPTS) 
#CC_OPTS	= -G0 -O3 -mips32 -march=mips32 -mtune=r4600 -mno-mips16 -msoft-float -msoft-float -mno-abicalls -fno-pic $(W_OPTS) $(F_OPTS) 
CC_OPTS	= -O3 -mips32 -march=mips32 -G 4 -mno-mips16 -msoft-float -mno-abicalls -fno-pic  -mlong-calls $(W_OPTS) $(F_OPTS) 

#DSTWO CC_OPTS	= -mips32 -O3 -mno-abicalls -fno-pic -fno-builtin \
#	   -fno-exceptions -ffunction-sections -mlong-calls\
#	   -fomit-frame-pointer -msoft-float -G 4 -fsigned-char

#CFLAGS = $(DEVINC) $(DEVLIBS) -Isrc -Isrc/$(MAMEOS) -Isrc/zlib $(CC_OPTS)
CFLAGS = $(DEVINC) $(DEVLIBS) -Isrc -Isrc/$(MAMEOS) $(CC_OPTS)

# Add the following for excellent debug info on linking
#-v -Wl,-verbose

LINKS := ../specs/link.xn
STARTS := ../specs/start.S
STARTO := start.o

LIBS := ../lib/libds2a.a ../lib/libds2b.a -lc -lm -lgcc

OBJ = obj
OBJDIRS = $(OBJ) $(OBJ)/cpu $(OBJ)/sound $(OBJ)/$(MAMEOS) \
	$(OBJ)/drivers $(OBJ)/machine $(OBJ)/vidhrdw $(OBJ)/sndhrdw \
	$(OBJ)/lib/stdlib $(OBJ)/lib

all:	maketree $(EMULATOR)

# include the various .mak files
include src/core.mak
#include src/$(TARGET).mak
include src/$(MODULE).mak
include src/rules.mak
include src/$(MAMEOS)/$(MAMEOS).mak



# combine the various definitions to one
CDEFS = $(DEFS) $(COREDEFS) $(CPUDEFS) $(SOUNDDEFS) $(ASMDEFS)

$(EMULATOR) : $(IMAGE_ELF)
	$(OBJCOPY) -O binary $(IMAGE_ELF) $(IMAGE_BIN)
	$(OBJDUMP) -d $(IMAGE_ELF) > $(IMAGE_DUMP)
	$(NM) $(IMAGE_ELF) | sort > $(IMAGE_SYM)
	$(OBJDUMP) -h $(IMAGE_ELF) > $(IMAGE_MAP)
	../tools/makeplug $(IMAGE_BIN) $(IMAGE_PLG)
	mv $(IMAGE_PLG) ./toDSTWO/_dstwoplug
  
$(IMAGE_ELF): $(OBJS) $(LIBOBJS) $(COREOBJS) $(OSOBJS) $(STARTO) $(DRVOBJS) $(DEBUG_MALLOC_OBJ) $(LD_SCRIPT) 
	$(CC) -nostdlib -static -T $(LINKS) -o $@ $(STARTO) $(OBJS) $(LIBOBJS) $(COREOBJS) $(OSOBJS) $(LIBS) $(DRVOBJS) $(DEBUG_MALLOC_OBJ) $(EXTLIBS) $(LIBS)

$(STARTO):
	$(CC) $(CC_OPTS) $(DEVINC) -o $@ -c $(STARTS)
 
$(OBJ)/%.o: src/%.c
	@echo Compiling $<...
	$(CC) $(CDEFS) $(CFLAGS) -c $< -o $@

$(OBJ)/%.o: src/%.cpp
	@echo Compiling $<...
	$(CPP) $(CDEFS) $(CFLAGS) -c $< -o $@

$(OBJ)/%.o: src/%.s
	@echo Assembling $<...
	$(CPP) $(CDEFS) $(CFLAGS) -c $< -o $@

$(OBJ)/%.o: src/%.S
	@echo Assembling $<...
	$(CPP) $(CDEFS) $(CFLAGS) -c $< -o $@

$(OBJ)/%.a:
	@echo Library $<...
	$(RM) $@
	$(AR) cr $@ $^

$(sort $(OBJDIRS)):
	$(MD) $@

maketree: $(sort $(OBJDIRS))

clean:
	$(FIND) $(OBJ) -name "*.o" -exec rm {} \;
	$(FIND) -name "*.elf" -exec rm {} \;
	$(FIND) -name "*.dump" -exec rm {} \;
	$(FIND) -name "*.map" -exec rm {} \;
	$(FIND) -name "*.sym" -exec rm {} \;
	$(FIND) -name "*.bin" -exec rm {} \;
	$(RM) $(EMULATOR)
	$(RM) $(FRONT)
