# engage tiny mame
CFLAGS+=-DTINY_COMPILE

# uses these CPUs
CPUS+=M68000@
CPUS+=Z80@
CPUS+=M6809@
CPUS+=M6502@
CPUS+=CCPU@
CPUS+=I8035@
CPUS+=I8039@
CPUS+=N7751@

# uses these SOUNDs
SOUNDS+=POKEY@
SOUNDS+=TMS5220@
SOUNDS+=AY8910@
SOUNDS+=CUSTOM@
SOUNDS+=SAMPLES@
SOUNDS+=SN76496@
SOUNDS+=DAC@
SOUNDS+=TMS36XX@
SOUNDS+=YM2151@
SOUNDS+=YM2203@
SOUNDS+=YM2413@
SOUNDS+=YM2612@
SOUNDS+=YM3812@
SOUNDS+=YM3438@
SOUNDS+=UPD7759@
SOUNDS+=RF5C68@
SOUNDS+=SEGAPCM@

OBJS= $(OBJ)/machine/atari_vg.o $(OBJ)/drivers/asteroid.o $(OBJ)/vidhrdw/llander.o $(OBJ)/sndhrdw/llander.o \
	$(OBJ)/drivers/aztarac.o \
	$(OBJ)/drivers/bwidow.o $(OBJ)/sndhrdw/redbaron.o \
	$(OBJ)/drivers/bzone.o \
	$(OBJ)/drivers/congo.o \
	$(OBJ)/drivers/foodf.o \
	$(OBJ)/drivers/cchasm.o \
	$(OBJ)/drivers/cinemat.o \
	$(OBJ)/drivers/mhavoc.o  \
	$(OBJ)/drivers/omegrace.o \
	$(OBJ)/drivers/quantum.o \
	$(OBJ)/drivers/sega.o \
	$(OBJ)/drivers/segar.o \
	$(OBJ)/drivers/suprloco.o \
	$(OBJ)/drivers/system1.o \
	$(OBJ)/drivers/system16.o \
	$(OBJ)/drivers/starwars.o $(OBJ)/machine/slapstic.o  \
	$(OBJ)/drivers/tempest.o $(OBJ)/machine/segacrpt.o \
	$(OBJ)/drivers/turbo.o \
	$(OBJ)/drivers/vicdual.o  $(OBJ)/sndhrdw/carnival.o $(OBJ)/sndhrdw/pulsar.o $(OBJ)/sndhrdw/invinco.o $(OBJ)/sndhrdw/depthch.o \
	$(OBJ)/drivers/zaxxon.o  


# MAME specific core objs
COREOBJS += $(OBJ)/driver.o
