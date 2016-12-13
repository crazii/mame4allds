# a tiny compile is without Neogeo games
COREDEFS += -DTINY_COMPILE=1 -DTINY_NAME=driver_pengo
# uses these CPUs
CPUS+=Z80@
#CPUS+=M68705@

# uses these SOUNDs
SOUNDS+=AY8910@
SOUNDS+=NAMCO@
SOUNDS+=SN76477@
SOUNDS+=SN76496@
#SOUNDS+=YM2203@

OBJS = $(OBJ)/drivers/1942.o $(OBJ)/drivers/pacman.o $(OBJ)/drivers/pengo.o $(OBJ)/machine/segacrpt.o

# MAME specific core objs
COREOBJS += $(OBJ)/driver.o
