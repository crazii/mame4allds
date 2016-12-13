# engage tiny mame
CFLAGS+=-DTINY_COMPILE

# uses these CPUs
CPUS+=Z80@
CPUS+=8080@
CPUS+=8085A@
CPUS+=I8035@
CPUS+=I8039@
CPUS+=S2650@
CPUS+=M6502@
CPUS+=M65C02@
CPUS+=M6802@
CPUS+=M6808@
CPUS+=M6809@
CPUS+=HD6309@
CPUS+=HD63701@
CPUS+=M68705@
CPUS+=N2A03@
CPUS+=TMS9980@
CPUS+=N7751@
CPUS+=M68000@
CPUS+=ADSP2105@
CPUS+=Z8000@

# uses these SOUNDs
SOUNDS+=SAMPLES@
SOUNDS+=SN76496@
SOUNDS+=SN76477@
SOUNDS+=AY8910@
SOUNDS+=NAMCO@
SOUNDS+=NES@
SOUNDS+=TMS36XX@
SOUNDS+=TMS5220@
SOUNDS+=DAC@
SOUNDS+=ASTROCADE@
SOUNDS+=CUSTOM@
SOUNDS+=YM2151@
SOUNDS+=YM2203@
SOUNDS+=YM3526@
SOUNDS+=YM3812@
SOUNDS+=HC55516@
SOUNDS+=OKIM6295@
SOUNDS+=MSM5205@
SOUNDS+=ADPCM@

OBJS= \
	$(OBJ)/drivers/8080bw.o \
	$(OBJ)/drivers/amidar.o  \
	$(OBJ)/drivers/arkanoid.o \
	$(OBJ)/drivers/astrocde.o $(OBJ)/sndhrdw/gorf.o \
	$(OBJ)/drivers/bagman.o \
	$(OBJ)/drivers/bombjack.o \
	$(OBJ)/drivers/cclimber.o  \
	$(OBJ)/drivers/cheekyms.o \
	$(OBJ)/drivers/citycon.o \
	$(OBJ)/drivers/cosmic.o \
	$(OBJ)/drivers/ddragon.o \
	$(OBJ)/drivers/ddragon3.o \
	$(OBJ)/drivers/digdug.o \
	$(OBJ)/drivers/dkong.o  \
	$(OBJ)/drivers/docastle.o \
	$(OBJ)/drivers/espial.o \
	$(OBJ)/drivers/exerion.o \
	$(OBJ)/drivers/fastfred.o \
	$(OBJ)/drivers/frogger.o \
	$(OBJ)/drivers/galaga.o \
	$(OBJ)/drivers/galaxian.o \
	$(OBJ)/drivers/gaplus.o \
	$(OBJ)/drivers/jrpacman.o \
	$(OBJ)/drivers/ladybug.o \
	$(OBJ)/drivers/lazercmd.o \
	$(OBJ)/drivers/mappy.o  \
	$(OBJ)/drivers/marineb.o  \
	$(OBJ)/drivers/mario.o  \
	$(OBJ)/drivers/mcr1.o \
	$(OBJ)/drivers/mcr2.o \
	$(OBJ)/drivers/mcr3.o \
	$(OBJ)/drivers/mcr68.o \
	$(OBJ)/drivers/meadows.o \
	$(OBJ)/drivers/meteor.o \
	$(OBJ)/drivers/mexico86.o \
	$(OBJ)/drivers/mrdo.o \
	$(OBJ)/drivers/naughtyb.o  \
	$(OBJ)/drivers/nova2001.o  \
	$(OBJ)/drivers/pacland.o \
	$(OBJ)/drivers/pacman.o \
	$(OBJ)/drivers/pengo.o $(OBJ)/machine/segacrpt.o \
	$(OBJ)/drivers/phoenix.o $(OBJ)/sndhrdw/pleiads.o \
	$(OBJ)/drivers/pkunwar.o \
	$(OBJ)/drivers/polepos.o \
	$(OBJ)/drivers/popeye.o \
	$(OBJ)/drivers/redalert.o \
	$(OBJ)/drivers/renegade.o \
	$(OBJ)/drivers/scobra.o \
	$(OBJ)/drivers/scramble.o \
	$(OBJ)/drivers/snowbros.o \
	$(OBJ)/drivers/solomon.o \
	$(OBJ)/drivers/spacefb.o  \
	$(OBJ)/drivers/tankbatt.o \
	$(OBJ)/drivers/tecmo.o \
	$(OBJ)/drivers/tecmo16.o \
	$(OBJ)/drivers/toki.o \
	$(OBJ)/drivers/tnzs.o \
	$(OBJ)/drivers/williams.o $(OBJ)/machine/mcr.o $(OBJ)/sndhrdw/mcr.o $(OBJ)/vidhrdw/mcr3.o $(OBJ)/vidhrdw/mcr12.o \
	$(OBJ)/drivers/xevious.o \
	$(OBJ)/drivers/z80bw.o

# MAME specific core objs
COREOBJS += $(OBJ)/driver.o
