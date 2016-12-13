#ifndef FAME_H
#define FAME_H

#include "fame.h"

/*
typedef struct
{
	struct M68K_CONTEXT;
	int pending_interrupts;
} FAME_Regs;
*/

typedef struct M68K_CONTEXT FAME_Regs;

extern void FAME_Reset(void);                      
extern int  FAME_Execute(int);
extern void FAME_SetRegs(FAME_Regs *);          
extern void FAME_GetRegs(FAME_Regs *);          
extern void FAME_Cause_Interrupt(int);             
extern void FAME_Clear_Pending_Interrupts(void);   
extern int  FAME_GetPC(void);                      

#define FAME_IO_CYCLE io_cycle_counter

extern int FAME_IO_CYCLE;

#define FAME_ICount FAME_IO_CYCLE

#define FAME_INT_NONE 0							  
#define FAME_IRQ_1    1
#define FAME_IRQ_2    2
#define FAME_IRQ_3    3
#define FAME_IRQ_4    4
#define FAME_IRQ_5    5
#define FAME_IRQ_6    6
#define FAME_IRQ_7    7

#define FAME_STOP     0x10

#endif
