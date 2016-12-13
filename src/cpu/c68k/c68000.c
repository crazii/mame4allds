#include "c68000.h"
#include "driver.h"
#include "cpuintrf.h"
#include "fame.h"

void c68k_reset(void *param)
{
}

unsigned int c68k_get_pc(void)
{
}

void c68k_set_context(void *src)
{
}

unsigned c68k_get_context(void *dst)
{
}

int c68k_execute(int cycles)
{
}

void c68k_exit(void)
{
}

void c68k_set_pc(unsigned val)
{
}
unsigned c68k_get_sp(void)
{
}

void c68k_set_sp(unsigned val)
{
}

unsigned c68k_get_reg(int regnum)
{
}

void c68k_set_reg(int regnum, unsigned val)
{
}

void c68k_set_nmi_line(int state)
{
}

void c68k_set_irq_line(int irqline, int state)
{
}

void c68k_set_irq_callback(int (*callback)(int irqline))
{
}

const char *c68k_info(void *context, int regnum)
{
	switch( regnum )
	{
		case CPU_INFO_NAME: return "c68k";
		case CPU_INFO_FAMILY: return "Motorola 68K";
		case CPU_INFO_VERSION: return "v0.80";
		case CPU_INFO_FILE: return __FILE__;
		case CPU_INFO_CREDITS: return "Copyright 2003-2004 Stephane Dallongeville. All rights reserved";
	}
	return "";
}

unsigned c68k_dasm(char *buffer, unsigned pc)
{
	return 2;
}
