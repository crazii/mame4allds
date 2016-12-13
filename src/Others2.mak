# engage tiny mame
CFLAGS+=-DTINY_COMPILE

# uses these CPUs
CPUS+=ADSP2105@
CPUS+=H6280@
CPUS+=I186@
CPUS+=M68000@
CPUS+=M6502@
CPUS+=M6809@
CPUS+=Z80@
CPUS+=TMS320C10@
CPUS+=TMS34010@
CPUS+=MIPS@
CPUS+=KONAMI@

# uses these SOUNDs
SOUNDS+=AY8910@
SOUNDS+=HC55516@
SOUNDS+=YM2151@
SOUNDS+=YM2203@
SOUNDS+=YM2610@
SOUNDS+=YM3812@
SOUNDS+=YMZ280B@
SOUNDS+=OKIM6295@
SOUNDS+=YM2151@
SOUNDS+=CUSTOM@
SOUNDS+=SAMPLES@
SOUNDS+=ADPCM@
SOUNDS+=DAC@

OBJS= \
	$(OBJ)/drivers/ataxx.o \
	$(OBJ)/drivers/blockhl.o $(OBJ)/vidhrdw/konamiic.o \
	$(OBJ)/drivers/blockout.o \
	$(OBJ)/drivers/cabal.o \
	$(OBJ)/drivers/cave.o \
	$(OBJ)/drivers/cischeat.o \
	$(OBJ)/drivers/exterm.o $(OBJ)/sndhrdw/gottlieb.o \
	$(OBJ)/drivers/jack.o \
	$(OBJ)/drivers/leland.o \
	$(OBJ)/drivers/madmotor.o \
	$(OBJ)/drivers/megasys1.o \
	$(OBJ)/drivers/rainbow.o \
	$(OBJ)/drivers/rastan.o \
	$(OBJ)/drivers/superman.o $(OBJ)/machine/cchip.o \
	$(OBJ)/drivers/toaplan1.o \
	$(OBJ)/drivers/toaplan2.o \
	$(OBJ)/drivers/twincobr.o $(OBJ)/vidhrdw/crtc6845.o \
	$(OBJ)/drivers/wardner.o \
	$(OBJ)/drivers/wmstunit.o $(OBJ)/sndhrdw/williams.o \
	$(OBJ)/drivers/wmswolfu.o \
	$(OBJ)/drivers/wmsyunit.o 


# MAME specific core objs
COREOBJS += $(OBJ)/driver.o
