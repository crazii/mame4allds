# engage tiny mame
CFLAGS+=-DTINY_COMPILE

# uses these CPUs
CPUS+=Z80@
CPUS+=M68000@

# SOUNDs
SOUNDS+=AY8910@
SOUNDS+=YM2610@

OBJS= \
	$(OBJ)/drivers/neogeo.o

# MAME specific core objs
COREOBJS += $(OBJ)/driver.o

