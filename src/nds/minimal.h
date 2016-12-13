/*
  Dingoo minimal library by Slaanesh
*/

//#include <fcntl.h>
//#include <stdlib.h>
//#include <stdio.h>
//#include <string.h>

//#include <sys/time.h>
//#include <unistd.h>

#ifndef __MINIMAL_H__
#define __MINIMAL_H__

#include <stdarg.h>

//#include "ds2io.h"
#include "ds2_malloc.h"
#include "fs_api.h"

/* System defines */
#define NDS_DEFAULT_MHZ	        336
#define NDS_DEFAULT_BRIGHT	70
#define NDS_SCREEN_WIDTH	256
#define NDS_SCREEN_HEIGHT	192
#define NDS_BLACK		0x0000	/* Black 16-bit pixel */
#define NDS_WHITE		0xFFFF	/* White 16-bit pixel */

#define BITX(x) (0x01 << (x)) 

#define RGB15M4ALL(r,g,b) ((((r) >>3)     ) |\
                           (((g) >>3) << 5) |\
                           (((b) >>3) << 10) | BITX(15))

/* Handy Macros */
#define nds_video_color8(C,R,G,B) (nds_palette[C] = RGB15M4ALL(R,G,B))
#define nds_video_color15(R,G,B) (RGB15M4ALL((R),(G),(B)))

#define nds_video_getr15(C) (((C)<<3)&0xFF)
#define nds_video_getg15(C) (((C)>>2)&0xFF)
#define nds_video_getb15(C) (((C)>>7)&0xFF)

enum  {
  NDS_UP =	BITX(6),
  NDS_DOWN =	BITX(7),
  NDS_LEFT =	BITX(5),
  NDS_RIGHT =	BITX(4),
  NDS_B =	BITX(1), //1<<31,	/* remapped A to match GP2X */
  NDS_X =	BITX(10),	/* remapped B to match GP2X */
  NDS_Y =	BITX(11),	/* remapped X to match GP2X */
  NDS_A =	BITX(0),	/* remapped Y to match GP2X */
  NDS_L = 	BITX(9),
  NDS_R =	BITX(8),
  NDS_START =	BITX(3),	/* actually pin 17, merged gpio2 and gpio3 */
  NDS_SELECT =	BITX(2),

  NDS_TOUCH  = BITX(12),

  NDS_POWER =  1<<7,
  /* Virtual keys
 * SELECT + 'button'
 * Same as base values except shifted << 7 */
  NDS_SEL_B =	1<<28,//(NDS_B)<<7,	
  NDS_SEL_X =	1<<23,//(NDS_X)<<7,
  NDS_SEL_Y =	1<<13,//(NDS_Y)<<7,
  NDS_SEL_A =	1<<7,//(NDS_A)<<7,
  NDS_SEL_L = 	1<<15,//(NDS_L)<<7,
  NDS_SEL_R =	1<<5,//(NDS_R)<<7,
  NDS_SEL_START =1<<18//(NDS_START)<<7
};
                                            
extern unsigned short		nds_palette[256];
extern unsigned char 		*nds_screen8;
extern unsigned short 		*nds_screen15,*nds_screen15_down;
extern int			nds_sound_rate;
extern int			nds_sound_stereo;

extern void nds_init(int rate, int bits, int stereo, unsigned int mhz, unsigned int brightness);
extern void nds_deinit(void);
extern void nds_timer_delay(unsigned int milliseconds);
extern void nds_sound_play(void *buff, int len);
extern void nds_video_flip(void);
extern void nds_video_flip_single(void);
extern void nds_video_setpalette(void);
extern unsigned long nds_joystick_read(void);
extern unsigned long nds_stylus_read(void);
extern void nds_joystick_press (void);
extern void nds_sound_volume(int left, int right);
extern void nds_sound_thread_mute(void);
extern void nds_sound_thread_start(void);
extern void nds_sound_thread_stop(void);
extern void nds_sound_set_rate(int rate);
extern void nds_sound_set_stereo(int stereo);
extern unsigned int nds_timer_read(void);
extern void nds_timer_profile(void);
extern void nds_set_video_mode(int bpp,int width,int height);
extern void nds_set_clock(unsigned int mhz);
extern void nds_video_wait_vsync(void);
//extern void nds_clear_video(enum SCREEN_ID screen);
extern void nds_flush_video_up(void);
extern void nds_flush_video_down(void);

extern void nds_printf(char* fmt, ...);
extern void nds_printf_init(void);
extern void nds_gamelist_text_out(int x, int y, char *eltexto);
extern void nds_gamelist_text_out_fmt(int x, int y, char* fmt, ...);

extern char gameDir[MAX_PATH];
//extern display*     gameDisplay;

#endif
