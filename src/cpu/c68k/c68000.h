#ifndef C68000_H
#define C68000_H

extern int *c68k_cycles;
#define c68k_ICount (*c68k_cycles)

#define c68k_INT_NONE 0							  
#define c68k_IRQ_1    1
#define c68k_IRQ_2    2
#define c68k_IRQ_3    3
#define c68k_IRQ_4    4
#define c68k_IRQ_5    5
#define c68k_IRQ_6    6
#define c68k_IRQ_7    7
#define c68k_INT_ACK_AUTOVECTOR    -1
#define c68k_STOP     0x10

extern void c68k_reset(void *param);                      
extern int  c68k_execute(int cycles);                     
extern void c68k_set_context(void *src);
extern unsigned c68k_get_context(void *dst);
extern unsigned int c68k_get_pc(void);                      
extern void c68k_exit(void);
extern void c68k_set_pc(unsigned val);
extern unsigned c68k_get_sp(void);
extern void c68k_set_sp(unsigned val);
extern unsigned c68k_get_reg(int regnum);
extern void c68k_set_reg(int regnum, unsigned val);
extern void c68k_set_nmi_line(int state);
extern void c68k_set_irq_line(int irqline, int state);
extern void c68k_set_irq_callback(int (*callback)(int irqline));
extern const char *c68k_info(void *context, int regnum);
extern unsigned c68k_dasm(char *buffer, unsigned pc);

#endif
