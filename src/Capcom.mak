# engage tiny mame
CFLAGS+=-DTINY_COMPILE

# uses these CPUs
CPUS+=Z80@
CPUS+=M6809@
CPUS+=M68000@
CPUS+=M68010@
CPUS+=M68EC020@

# uses these SOUNDs
SOUNDS+=AY8910@
SOUNDS+=YM2203@

#SOUNDS+=YM2608@
#SOUNDS+=YM2610@
#SOUNDS+=YM2610B@
#SOUNDS+=YM2612@
#SOUNDS+=YM3438@
#SOUNDS+=YMZ280B@
#SOUNDS+=YM3526@
#SOUNDS+=Y8950@

SOUNDS+=YM2151@
SOUNDS+=YM2413@
SOUNDS+=YM3812@

SOUNDS+=SN76496@
SOUNDS+=ADPCM@
SOUNDS+=QSOUND@
SOUNDS+=OKIM6295@
SOUNDS+=MSM5205@
SOUNDS+=DAC@

OBJS= \
	$(OBJ)/drivers/1942.o \
	$(OBJ)/drivers/1943.o \
	$(OBJ)/drivers/blktiger.o \
	$(OBJ)/drivers/commando.o \
	$(OBJ)/drivers/exedexes.o \
	$(OBJ)/drivers/gng.o \
	$(OBJ)/drivers/gunsmoke.o \
	$(OBJ)/drivers/higemaru.o \
	$(OBJ)/drivers/lwings.o \
	$(OBJ)/drivers/sonson.o \
	$(OBJ)/drivers/srumbler.o \
	$(OBJ)/drivers/sidearms.o \
	$(OBJ)/drivers/vulgus.o \
	$(OBJ)/drivers/cps1.o \
	$(OBJ)/drivers/bionicc.o \
	$(OBJ)/drivers/mitchell.o \
	$(OBJ)/drivers/sf1.o $(OBJ)/machine/kabuki.o \
	$(OBJ)/drivers/capbowl.o \
	$(OBJ)/drivers/lastduel.o \
	$(OBJ)/drivers/cbasebal.o
  
#s	$(OBJ)/drivers/system1.o $(OBJ)/machine/segacrpt.o

# MAME specific core objs
COREOBJS += $(OBJ)/driver.o
