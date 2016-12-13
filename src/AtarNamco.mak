# engage tiny mame
CFLAGS+=-DTINY_COMPILE

# uses these CPUs
CPUS+=8080@
CPUS+=HD63701@
CPUS+=HD63705@
CPUS+=M6502@
CPUS+=M6800@
CPUS+=M6808@
CPUS+=M6809@
CPUS+=M68000@
CPUS+=M68010@
CPUS+=Z80@
CPUS+=T11@

# uses these SOUNDs
SOUNDS+=POKEY@
SOUNDS+=SAMPLES@
SOUNDS+=TMS5220@
SOUNDS+=YM2151@
SOUNDS+=YM3812@
SOUNDS+=YM2413@
SOUNDS+=OKIM6295@
SOUNDS+=C140@
SOUNDS+=DAC@
SOUNDS+=AY8910@
SOUNDS+=DISCRETE@
SOUNDS+=CUSTOM@
SOUNDS+=NAMCO@

OBJS= \
	$(OBJ)/machine/atarigen.o $(OBJ)/machine/slapstic.o $(OBJ)/machine/atari_vg.o \
	$(OBJ)/sndhrdw/atarijsa.o \
	$(OBJ)/drivers/atarifb.o \
	$(OBJ)/drivers/atarisy1.o \
	$(OBJ)/drivers/atarisy2.o \
	$(OBJ)/drivers/arcadecl.o \
	$(OBJ)/drivers/atetris.o \
	$(OBJ)/drivers/avalnche.o \
	$(OBJ)/drivers/badlands.o \
	$(OBJ)/drivers/baraduke.o \
	$(OBJ)/drivers/bosco.o \
	$(OBJ)/drivers/bsktball.o \
	$(OBJ)/drivers/batman.o \
	$(OBJ)/drivers/blstroid.o \
	$(OBJ)/drivers/canyon.o \
	$(OBJ)/drivers/ccastles.o  \
	$(OBJ)/drivers/centiped.o \
	$(OBJ)/drivers/cloak.o \
	$(OBJ)/drivers/cloud9.o \
	$(OBJ)/drivers/copsnrob.o \
	$(OBJ)/drivers/cyberbal.o \
	$(OBJ)/drivers/dominos.o \
	$(OBJ)/drivers/eprom.o \
	$(OBJ)/drivers/firetrk.o \
	$(OBJ)/drivers/foodf.o \
	$(OBJ)/drivers/gauntlet.o \
	$(OBJ)/drivers/geebee.o \
	$(OBJ)/drivers/grobda.o \
	$(OBJ)/drivers/hydra.o \
	$(OBJ)/drivers/irobot.o \
	$(OBJ)/drivers/jedi.o \
	$(OBJ)/drivers/klax.o \
	$(OBJ)/drivers/liberatr.o \
	$(OBJ)/drivers/milliped.o \
	$(OBJ)/drivers/missile.o \
	$(OBJ)/drivers/namcos1.o \
	$(OBJ)/drivers/namcos2.o \
	$(OBJ)/drivers/namcos86.o \
	$(OBJ)/drivers/nitedrvr.o \
	$(OBJ)/drivers/offtwall.o \
	$(OBJ)/drivers/phozon.o \
	$(OBJ)/drivers/qwakprot.o \
	$(OBJ)/drivers/rampart.o \
	$(OBJ)/drivers/rallyx.o \
	$(OBJ)/drivers/relief.o \
	$(OBJ)/drivers/sbrkout.o \
	$(OBJ)/drivers/skullxbo.o \
	$(OBJ)/drivers/skydiver.o \
	$(OBJ)/drivers/skykid.o \
	$(OBJ)/drivers/sprint2.o \
	$(OBJ)/drivers/subs.o \
	$(OBJ)/drivers/superpac.o \
	$(OBJ)/drivers/thunderj.o \
	$(OBJ)/drivers/toobin.o \
	$(OBJ)/drivers/toypop.o \
	$(OBJ)/drivers/vindictr.o \
	$(OBJ)/drivers/warlord.o \
	$(OBJ)/drivers/warpwarp.o \
	$(OBJ)/drivers/xybots.o


# MAME specific core objs
COREOBJS += $(OBJ)/driver.o
