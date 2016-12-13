# engage tiny mame
CFLAGS+=-DTINY_COMPILE

# uses these CPUs
CPUS+=Z80@
CPUS+=M68000@
CPUS+=M6809@
CPUS+=HD6309@
CPUS+=I8039@
CPUS+=KONAMI@

# uses these SOUNDs
SOUNDS+=K007232@
SOUNDS+=UPD7759@
SOUNDS+=SN76496@
SOUNDS+=YM3812@
SOUNDS+=YM2151@
SOUNDS+=YM2203@
SOUNDS+=AY8910@
SOUNDS+=VLM5030@
SOUNDS+=ADPCM@
SOUNDS+=DAC@
SOUNDS+=K051649@
SOUNDS+=K005289@
SOUNDS+=K053260@
SOUNDS+=K054539@
SOUNDS+=CUSTOM@
SOUNDS+=SAMPLES@
SOUNDS+=NAMCO@

OBJS= \
	$(OBJ)/drivers/88games.o \
	$(OBJ)/drivers/ajax.o \
	$(OBJ)/drivers/aliens.o \
	$(OBJ)/drivers/battlnts.o \
	$(OBJ)/drivers/bladestl.o \
	$(OBJ)/drivers/blockhl.o \
	$(OBJ)/drivers/bottom9.o \
	$(OBJ)/drivers/contra.o \
	$(OBJ)/drivers/circusc.o \
	$(OBJ)/drivers/combatsc.o \
	$(OBJ)/drivers/crimfght.o \
	$(OBJ)/drivers/ddrible.o \
	$(OBJ)/drivers/fastlane.o \
	$(OBJ)/drivers/finalizr.o \
	$(OBJ)/drivers/flkatck.o \
	$(OBJ)/drivers/gyruss.o \
	$(OBJ)/drivers/gberet.o \
	$(OBJ)/drivers/gbusters.o \
	$(OBJ)/drivers/gradius3.o \
	$(OBJ)/drivers/hcastle.o \
	$(OBJ)/drivers/hyperspt.o \
	$(OBJ)/drivers/ironhors.o \
	$(OBJ)/drivers/jailbrek.o \
	$(OBJ)/drivers/jackal.o \
	$(OBJ)/drivers/junofrst.o \
	$(OBJ)/drivers/labyrunr.o \
	$(OBJ)/drivers/locomotn.o \
	$(OBJ)/drivers/megazone.o \
	$(OBJ)/vidhrdw/konamiic.o $(OBJ)/drivers/mainevt.o \
	$(OBJ)/drivers/mikie.o \
	$(OBJ)/drivers/nemesis.o \
	$(OBJ)/drivers/pandoras.o \
	$(OBJ)/drivers/parodius.o \
	$(OBJ)/drivers/pingpong.o \
	$(OBJ)/drivers/pooyan.o \
	$(OBJ)/drivers/rallyx.o \
	$(OBJ)/drivers/rocnrope.o \
	$(OBJ)/drivers/rockrage.o \
	$(OBJ)/drivers/rollerg.o \
	$(OBJ)/drivers/sbasketb.o \
	$(OBJ)/drivers/shaolins.o \
	$(OBJ)/drivers/simpsons.o \
	$(OBJ)/drivers/surpratk.o \
	$(OBJ)/drivers/spy.o \
	$(OBJ)/drivers/timeplt.o \
	$(OBJ)/machine/konami.o $(OBJ)/drivers/trackfld.o \
	$(OBJ)/drivers/tmnt.o \
	$(OBJ)/drivers/tp84.o \
	$(OBJ)/drivers/twin16.o \
	$(OBJ)/drivers/tutankhm.o \
	$(OBJ)/drivers/thunderx.o \
	$(OBJ)/drivers/vendetta.o \
	$(OBJ)/drivers/wecleman.o \
	$(OBJ)/drivers/xmen.o \
	$(OBJ)/drivers/yiear.o

# MAME specific core objs
COREOBJS += $(OBJ)/driver.o
