# engage tiny mame
CFLAGS+=-DTINY_COMPILE

# uses these CPUs
CPUS+=M6800@
CPUS+=M68000@
CPUS+=M6808@
CPUS+=M6803@
CPUS+=M6809@
CPUS+=HD6309@
CPUS+=M6502@
CPUS+=H6280@
CPUS+=V30@
CPUS+=V33@
CPUS+=Z80@

# uses these SOUNDs
SOUNDS+=SAMPLES@
SOUNDS+=DAC@
SOUNDS+=AY8910@
SOUNDS+=YM2203@
SOUNDS+=YM3812@
SOUNDS+=YM3526@
SOUNDS+=YM2151@
SOUNDS+=MSM5205@
SOUNDS+=OKIM6295@

OBJS= \
	$(OBJ)/drivers/actfancr.o  \
	$(OBJ)/drivers/astrof.o \
	$(OBJ)/drivers/btime.o \
	$(OBJ)/drivers/battlera.o  \
	$(OBJ)/drivers/brkthru.o  \
	$(OBJ)/drivers/cbuster.o \
	$(OBJ)/drivers/cninja.o \
	$(OBJ)/drivers/darkseal.o  \
	$(OBJ)/drivers/dec0.o \
	$(OBJ)/drivers/dec8.o  \
	$(OBJ)/drivers/exprraid.o  \
	$(OBJ)/drivers/firetrap.o  \
	$(OBJ)/sndhrdw/irem.o \
	$(OBJ)/drivers/kchamp.o  \
	$(OBJ)/drivers/karnov.o \
	$(OBJ)/drivers/kingobox.o \
	$(OBJ)/drivers/m62.o  \
	$(OBJ)/drivers/m72.o  \
	$(OBJ)/drivers/m92.o  \
	$(OBJ)/drivers/m107.o  \
	$(OBJ)/drivers/mpatrol.o  \
	$(OBJ)/drivers/olibochu.o  \
	$(OBJ)/drivers/pcktgal.o  \
	$(OBJ)/drivers/sidepckt.o  \
	$(OBJ)/drivers/shootout.o  \
	$(OBJ)/drivers/skychut.o  \
	$(OBJ)/drivers/stadhero.o \
	$(OBJ)/drivers/supbtime.o \
	$(OBJ)/drivers/travrusa.o \
	$(OBJ)/drivers/troangel.o \
	$(OBJ)/drivers/tumblep.o \
	$(OBJ)/drivers/vigilant.o \
	$(OBJ)/drivers/vaportra.o \
	$(OBJ)/drivers/yard.o

# MAME specific core objs
COREOBJS += $(OBJ)/driver.o
