#include <sys/cachectl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
//#include <sys/stat.h>
//#include <unistd.h>
#include <sched.h>
//#include <dirent.h>
#include "minimal.h"
#include "nds_frontend_list.h"

#include "ds2io.h"
#include "fs_api.h"

#define COMPATCORES 1

#if   MODULE_VectSega
#define MAMECFG "mameVectSega.cfg"
#elif   MODULE_Capcom
#define MAMECFG "mameCapcom.cfg"
#elif   MODULE_Konami
#define MAMECFG "mameKonami.cfg"
#elif   MODULE_Classic
#define MAMECFG "mameClassic.cfg"
#elif   MODULE_DeasIrem
#define MAMECFG "mameDeasIrem.cfg"
#elif   MODULE_AtarNamco
#define MAMECFG "mameAtarNamco.cfg"
#elif   MODULE_Others
#define MAMECFG "mameOthers.cfg"
#elif   MODULE_Others2
#define MAMECFG "mameOthers2.cfg"
#else
#define MAMECFG "mameNeogeo.cfg"
#endif

int game_num_avail=0;
static int last_game_selected=0;
char playemu[16] = "mame\0";
char playgame[16] = "builtinn\0";

int nds_freq=336;		/* default nds Mhz */ /* value 9 10 11 12 13 for 300 336 360 384 396 */
int nds_video_depth=8;	/* MAME video depth */
int nds_video_aspect=2;	/* Scale best */
int nds_video_sync=0;	/* No vsync */
int nds_brightness=70;	/* Screen Brightness */
int nds_sound = 7;		/* 22050hz, Mono */
int nds_clock_cpu=100;	/* Emulated Main CPU clock percentage */
int nds_clock_sound=100;	/* Emulated Sound CPU clock percentage */
int nds_cpu_cores=0;		/* Compatible cores */
int nds_volume=1;		/* NDS Volume = Max */
int nds_cheat=0;		/* Enable MAME cheat modes */
int nds_profilemode=0;	/* Disable profile mode */

//int master_volume = 50;		/* Needed by minimal.cpp */

unsigned char *ndsmenu_bmp;

static void load_bmp_8bpp(unsigned short *out, unsigned char *in) 
{
	int i,x,y;
	unsigned char r,g,b,c;
	in+=14; /* Skip HEADER */
	in+=40; /* Skip INFOHD */
	/* Set Palette */
	for (i=0;i<256;i++) {
		b=*in++;
		g=*in++;
		r=*in++;
		c=*in++;
//                b>>=3;g>>=3;r>>=3; 
		nds_video_color8(i,r,g,b);
	}
	/* Set Bitmap */	
	for (y=191;y!=-1;y--) {
		for (x=0;x<256;x++) {
			*out++=nds_palette[in[x+y*256]];
		}
	}
}

static void nds_intro_screen(void) {
  char name[256];
  FILE *f;
  unsigned char *bmpF;

  bmpF = (unsigned char *) malloc(50230);

  sprintf(name,"%s/skins/ndssplash.bmp",gameDir);
  f=fopen(name,"rb");
  if (f) {
    fread(bmpF,1,50230,f);
    fclose(f);
  }
  load_bmp_8bpp(nds_screen15,bmpF);
  free(bmpF);
}

 void nds_ingame_screen(void) {
  char name[256];
  FILE *f;
  unsigned char *bmpF;

  bmpF = (unsigned char *) malloc(50230);

  sprintf(name,"%s/skins/ndsingame.bmp",gameDir);
  f=fopen(name,"rb");
  if (f) {
    fread(bmpF,1,50230,f);
    fclose(f);
  }
  load_bmp_8bpp(nds_screen15_down,bmpF);
  free(bmpF);
}

static void game_list_init_nocache(void)
{
	int i;
	FILE *f;
	char game[32];
        char tempString[256];
        struct stat st;

	sprintf(tempString, "%s/roms",gameDir);
	DIR *d=opendir(tempString);
	if (d)
	{
		dirent *actual=readdir_ex(d,&st);
		while(actual)
		{
                        char *file_name=actual->d_name;
			for (i=0;i<NUMGAMES;i++)
			{
				if (driversfe[i].available==0)
				{
					sprintf(game,"%s.zip",driversfe[i].name);
					if (strcasecmp(file_name,game)==0)
					{
						driversfe[i].available=1;
						game_num_avail++;
						break;
					}
				}
			}
			actual=readdir(d);
		}
		closedir(d);
	}
#if 0
  char tempString[256];
	fsys_file_info_t fd;
	sprintf(tempString, "%s\\roms\\*.zip",gameDir);
	if (fsys_findfirst(tempString, FSYS_FIND_FILE, &fd) == 0)
	{
  	do
  	{ 
			for (i=0;i<NUMGAMES;i++)
			{
				if (driversfe[i].available==0)
				{
					sprintf(game,"%s.zip",driversfe[i].name);
					if (strcasecmp(fd.name,game)==0)
					{
						driversfe[i].available=1;
						game_num_avail++;
						break;
					}
				}
			}
  	} while (fsys_findnext(&fd) == 0);
	}
	fsys_findclose(&fd);

	if (game_num_avail)
	{
                sprintf(tempString, "%s/frontend/mame.lst",gameDir);
		remove(tempString);
		f=fopen(tempString,"w");
		if (f)
		{
			for (i=0;i<NUMGAMES;i++)
			{
				fputc(driversfe[i].available,f);
			}
			fclose(f);
		}
	}
	else
	{
		printf("No games found!\n");
	}
#endif
}

static void game_list_init_cache(void)
{
#if 0
  FILE *f;
	int i;
	struct stat buf;
	f=fopen("frontend/mame.lst","r");
	if (f)
	{
		stat("frontend/mame.lst", &buf);
		if (buf.st_size == NUMGAMES)
		{
			for (i=0;i<NUMGAMES;i++)
			{
				driversfe[i].available=fgetc(f);
				if (driversfe[i].available)
					game_num_avail++;
			}
			fclose(f);
			return; /* Success */
		}
	}
#endif
	/* Create a new cache file */
	game_list_init_nocache();
}

static void game_list_init(int argc)
{
	if (argc==1)
		game_list_init_nocache();
	else
		game_list_init_cache();
}

static void game_list_view(int *pos) {
	char text[32];
	int i;
	int view_pos;
	int aux_pos=0;
	int screen_y = 30;
	int screen_x = 18;

	/* Draw background image */
	load_bmp_8bpp(nds_screen15_down,ndsmenu_bmp);

	/* Check Limits */
	if (*pos<0)
		*pos=game_num_avail-1;
	if (*pos>(game_num_avail-1))
		*pos=0;
					   
	/* Set View Pos */
	if (*pos<10) {
		view_pos=0;
	} else {
		if (*pos>game_num_avail-11) {
                        //view_pos=game_num_avail-21;
			view_pos=game_num_avail-18;
			view_pos=(view_pos<0?0:view_pos);
		} else {
			view_pos=*pos-10;
		}
	}

	/* Show List */
	for (i=0;i<NUMGAMES;i++) {
		if (driversfe[i].available==1) {
//			if (aux_pos>=view_pos && aux_pos<=view_pos+20) {
			if (aux_pos>=view_pos && aux_pos<=view_pos+17) {
				strncpy (text,driversfe[i].description,29);
				text[28]='\0';
				nds_gamelist_text_out( screen_x, screen_y, text);
//				nds_gamelist_text_out( screen_x, screen_y, driversfe[i].description);
				if (aux_pos==*pos) {
					nds_gamelist_text_out( screen_x-10, screen_y,">" );
					nds_gamelist_text_out( screen_x-13, screen_y-1,"-" );
				}
				screen_y+=8;
			}
			aux_pos++;
		}
	}
}

static void game_list_select (int index, char *game, char *emu) {
	int i;
	int aux_pos=0;
	for (i=0;i<NUMGAMES;i++)
	{
		if (driversfe[i].available==1)
		{
			if(aux_pos==index)
			{
				strcpy(game,driversfe[i].name);
				//strcpy(emu,driversfe[i].exe);
        strcpy(emu,"mame");
				//nds_cpu_cores=driversfe[i].cores;
				break;
			}
			aux_pos++;
		}
	}
}

static char *game_list_description (int index)
{
	int i;
	int aux_pos=0;
	for (i=0;i<NUMGAMES;i++) {
		if (driversfe[i].available==1) {
			if(aux_pos==index) {
				return(driversfe[i].description);
			}
			aux_pos++;
		   }
	}
	return ((char *)0);
}

static int show_options(char *game)
{
	unsigned long ExKey=0;
	int selected_option=0;
	int x_Pos = 13;
	int y_Pos = 22;
	int options_count = 11;
	char text[256];
	FILE *f;
	int i=0;

	/* Read game configuration */
  sprintf(text,"%s/cfg/%s",gameDir,MAMECFG);
  f=fopen(text,"r");
	if (f) {
    fread(&nds_freq,1,sizeof(nds_freq),f);
    fread(&nds_video_depth,1,sizeof(nds_video_depth),f);
    fread(&nds_video_aspect,1,sizeof(nds_video_aspect),f);
    fread(&nds_video_sync,1,sizeof(nds_video_sync),f);
    fread(&nds_brightness,1,sizeof(nds_brightness),f);
    fread(&nds_sound,1,sizeof(nds_sound),f);
    fread(&nds_clock_cpu,1,sizeof(nds_clock_cpu),f);
    fread(&nds_clock_sound,1,sizeof(nds_clock_sound),f);
    fread(&nds_cpu_cores,1,sizeof(nds_cpu_cores),f);
    fread(&nds_volume,1,sizeof(nds_volume),f);
    fread(&i,1,sizeof(i),f);
    fread(&nds_cheat,1,sizeof(nds_cheat),f);
		fclose(f);
	}
	/* Convert from old settings */
	if (nds_brightness < 10)
	{
		nds_brightness = 70;
	}
#ifdef COMPATCORES
	if (nds_cpu_cores != 0)
	{
		nds_cpu_cores = 0;
	}
#endif

	while(1)
	{
		/* Draw background image */
		load_bmp_8bpp(nds_screen15_down,ndsmenu_bmp);

		/* Draw the options */
//		strncpy (text,game_list_description(last_game_selected),33);
//		text[32]='\0';
		strncpy (text,game_list_description(last_game_selected),29);
		text[28]='\0';
		nds_gamelist_text_out(x_Pos,y_Pos+10,text);

		/* (0) Dingoo Clock */
		nds_gamelist_text_out_fmt(x_Pos,y_Pos+30, "Nds Clock  %d MHz", nds_freq);

		/* (1) Video Depth */
		switch (nds_video_depth)
		{
			case -1: nds_gamelist_text_out_fmt(x_Pos,y_Pos+40,"Video Depth   Auto"); break;
			case 8:  nds_gamelist_text_out_fmt(x_Pos,y_Pos+40,"Video Depth   8 bit"); break;
			case 16: nds_gamelist_text_out_fmt(x_Pos,y_Pos+40,"Video Depth   16 bit"); break;
		}

		/* (2) Video Aspect */
		switch (nds_video_aspect)
		{
			case 0: nds_gamelist_text_out_fmt(x_Pos,y_Pos+50,"Video Aspect  Normal"); break;
			case 1: nds_gamelist_text_out_fmt(x_Pos,y_Pos+50,"Video Aspect  Scale Horizontal"); break;
			case 2: nds_gamelist_text_out_fmt(x_Pos,y_Pos+50,"Video Aspect  Scale Best"); break;
			case 3: nds_gamelist_text_out_fmt(x_Pos,y_Pos+50,"Video Aspect  Scale Fast"); break;
			case 4: nds_gamelist_text_out_fmt(x_Pos,y_Pos+50,"Video Aspect  Scale Halfsize"); break;
			case 5: nds_gamelist_text_out_fmt(x_Pos,y_Pos+50,"Video Aspect  Rotate Normal"); break;
			case 6: nds_gamelist_text_out_fmt(x_Pos,y_Pos+50,"Video Aspect  Rotate Scale Horiz"); break;
			case 7: nds_gamelist_text_out_fmt(x_Pos,y_Pos+50,"Video Aspect  Rotate Best"); break;
			case 8: nds_gamelist_text_out_fmt(x_Pos,y_Pos+50,"Video Aspect  Rotate Fast"); break;
			case 9: nds_gamelist_text_out_fmt(x_Pos,y_Pos+50,"Video Aspect  Rotate Halfsize"); break;
		}
		
		/* (3) Video Sync */
		switch (nds_video_sync)
		{
			case 0: nds_gamelist_text_out(x_Pos,y_Pos+60, "Video Sync    Normal"); break;
			case 1: nds_gamelist_text_out(x_Pos,y_Pos+60, "Video Sync    DblBuf"); break;
			case -1: nds_gamelist_text_out(x_Pos,y_Pos+60,"Video Sync    OFF"); break;
		}
		
		/* (4) Screeen Brightness */
		nds_gamelist_text_out_fmt(x_Pos,y_Pos+70,"Brightness    %d%%",nds_brightness);

		/* (5) Sound - Max is 48000hz, multiples of this is best */
		switch(nds_sound)
		{
			case 0: nds_gamelist_text_out_fmt(x_Pos,y_Pos+80,"Sound         %s","OFF"); break;
			case 1: nds_gamelist_text_out_fmt(x_Pos,y_Pos+80,"Sound         %s","ON 8khz fast"); break;
			case 2: nds_gamelist_text_out_fmt(x_Pos,y_Pos+80,"Sound         %s","ON 16khz fast"); break;
			case 3: nds_gamelist_text_out_fmt(x_Pos,y_Pos+80,"Sound         %s","ON 22.5khz fast"); break;
			case 4: nds_gamelist_text_out_fmt(x_Pos,y_Pos+80,"Sound         %s","ON 48khz fast"); break;
			case 5: nds_gamelist_text_out_fmt(x_Pos,y_Pos+80,"Sound         %s","ON 80khz mono"); break;
			case 6: nds_gamelist_text_out_fmt(x_Pos,y_Pos+80,"Sound         %s","ON 16khz mono"); break;
			case 7: nds_gamelist_text_out_fmt(x_Pos,y_Pos+80,"Sound         %s","ON 22.5khz mono"); break;
			case 8: nds_gamelist_text_out_fmt(x_Pos,y_Pos+80,"Sound         %s","ON 48khz mono"); break;
			case 9: nds_gamelist_text_out_fmt(x_Pos,y_Pos+80,"Sound         %s","ON 8khz stereo"); break;
			case 10: nds_gamelist_text_out_fmt(x_Pos,y_Pos+80,"Sound         %s","ON 16khz stereo"); break;
			case 11: nds_gamelist_text_out_fmt(x_Pos,y_Pos+80,"Sound         %s","ON 22.5hz stereo"); break;
			case 12: nds_gamelist_text_out_fmt(x_Pos,y_Pos+80,"Sound         %s","ON 48khz stereo"); break;
		}

		/* (6) CPU Clock */
		nds_gamelist_text_out_fmt(x_Pos,y_Pos+90,"CPU Clock     %d%%",nds_clock_cpu);

		/* (7) Audio Clock */
		nds_gamelist_text_out_fmt(x_Pos,y_Pos+100,"Audio Clock   %d%%",nds_clock_sound);

		/* (8) CPU cores */
#ifdef COMPATCORES
		nds_gamelist_text_out(x_Pos,y_Pos+110, "CPU Cores     Normal");
#else
		switch (nds_cpu_cores)
		{
			case 0: nds_gamelist_text_out(x_Pos,y_Pos+110, "CPU Cores     Normal"); break;
			case 1: nds_gamelist_text_out(x_Pos,y_Pos+110, "CPU Cores     Fast M68000"); break;
			case 2: nds_gamelist_text_out(x_Pos,y_Pos+110, "CPU Cores     Fast Z80"); break;
			case 3: nds_gamelist_text_out(x_Pos,y_Pos+110, "CPU Cores     Fast M68000/Z80"); break;
		}
#endif

		/* (9) Volume */
		if (nds_sound == 0)
		{
			nds_gamelist_text_out(x_Pos,y_Pos+120,"Volume        OFF");
		}
		else
		{
			switch (nds_volume)
			{
				case 1: nds_gamelist_text_out(x_Pos,y_Pos+120,"Volume        Max"); break;
				case 2: nds_gamelist_text_out(x_Pos,y_Pos+120,"Volume        Medium"); break;
				case 3: nds_gamelist_text_out(x_Pos,y_Pos+120,"Volume        Low"); break;
				case 4: nds_gamelist_text_out(x_Pos,y_Pos+120,"Volume        Quiet"); break;
			}
		}

		/* (10) Cheats */
		if (nds_cheat)
			nds_gamelist_text_out(x_Pos,y_Pos+130,"Cheats        ON");
		else
			nds_gamelist_text_out(x_Pos,y_Pos+130,"Cheats        OFF");
	
		nds_gamelist_text_out(x_Pos,y_Pos+148,"Key A to confirm, B to return");

		/* Show currently selected item */
		nds_gamelist_text_out(x_Pos-16,y_Pos+(selected_option*10)+30," >");

		nds_flush_video_down();
		while(nds_joystick_read()) { nds_timer_delay(150); }
		while(!(ExKey=nds_joystick_read())) { /*sched_yield();*/ }
		if(ExKey & NDS_DOWN){
			selected_option++;
			selected_option = selected_option % options_count;
		}
		else if(ExKey & NDS_UP){
			selected_option--;
			if(selected_option<0)
				selected_option = options_count - 1;
		}
		else if(ExKey & NDS_RIGHT || ExKey & NDS_LEFT)
		{
			switch(selected_option) {
			case 0:
				/* Nds Clock */
				if(ExKey & NDS_RIGHT){
					switch (nds_freq) {
						case 300: nds_freq=336;break;
						case 336: nds_freq=360;break;
						case 360: nds_freq=384;break;
						case 384: nds_freq=396;break;
						case 396: nds_freq=300;break;
					}
				} else {
					switch (nds_freq) {
						case 396: nds_freq=384;break;
						case 384: nds_freq=360;break;
						case 360: nds_freq=336;break;
						case 336: nds_freq=300;break;
						case 300: nds_freq=396;break;
					}
				}
				break;
			case 1:
				switch (nds_video_depth)
				{
					case -1: nds_video_depth=8; break;
					case 8: nds_video_depth=16; break;
					case 16: nds_video_depth=-1; break;
				}
				break;
			case 2:
				if(ExKey & NDS_RIGHT)
				{
					nds_video_aspect++;
					if (nds_video_aspect>9)
						nds_video_aspect=0;
				}
				else
				{
					nds_video_aspect--;
					if (nds_video_aspect<0)
						nds_video_aspect=9;
				}
				break;
			case 3:
				nds_video_sync=nds_video_sync+1;
				if (nds_video_sync>1)
					nds_video_sync=-1;
				break;
			case 4:
				/* "Brightness" */
				if(ExKey & NDS_RIGHT)
				{
					nds_brightness+=10;
					if (nds_brightness > 100)
						nds_brightness = 100;
				}
				else {
					nds_brightness-=10;
					if (nds_brightness < 0)
						nds_brightness = 0;
				}
				break;
			case 5:
				if(ExKey & NDS_RIGHT)
				{
					nds_sound ++;
					if ((nds_sound==4) || (nds_sound==8) || (nds_sound==12))
                                          nds_sound++; 
					if (nds_sound>12)
						nds_sound=0;
				}
				else
				{
					nds_sound--;
					if (nds_sound<0)
						nds_sound=12;
					if ((nds_sound==4) || (nds_sound==8) || (nds_sound==12))
                                          nds_sound--; 
				}
				break;
			case 6:
				/* "CPU Clock" */
				if(ExKey & NDS_RIGHT)
				{
					nds_clock_cpu += 10; /* Add 10% */
					if (nds_clock_cpu > 200) /* 200% is the max */
						nds_clock_cpu = 200;
				}
				else
				{
					nds_clock_cpu -= 10; /* Subtract 10% */
					if (nds_clock_cpu < 10) /* 10% is the min */
						nds_clock_cpu = 10;
				}
				break;
			case 7:
				/* "Audio Clock" */
				if(ExKey & NDS_RIGHT)
				{
					nds_clock_sound += 10; /* Add 10% */
					if (nds_clock_sound > 200) /* 200% is the max */
						nds_clock_sound = 200;
				}
				else{
					nds_clock_sound -= 10; /* Subtract 10% */
					if (nds_clock_sound < 10) /* 10% is the min */
						nds_clock_sound = 10;
				}
				break;
			case 8:
#ifdef COMPATCORES
				nds_cpu_cores=0;
#else
				nds_cpu_cores=(nds_cpu_cores+1)%4;
#endif
				break;
			case 9:
				/* Volume */
				if(ExKey & NDS_RIGHT)
				{
					nds_volume++;
					if (nds_volume > 4)
						nds_volume = 1;
				}
				else {
					nds_volume--;
					if (nds_volume < 1)
						nds_volume = 4;
				}
				break;
			case 10:
				nds_cheat=!nds_cheat;
				break;
			}
		}

		if ((ExKey & NDS_A) || (ExKey & NDS_X) || (ExKey & NDS_START)) 
		{
			if (ExKey & NDS_START)
			{
				/* Do not write game config in profile mode */
				nds_profilemode = 1;
			}
			else
			{
				/* Write game configuration */
        sprintf(text,"%s/cfg/%s",gameDir,MAMECFG);
        //sprintf(text,"cfg\\%s",MAMECFG);
				f=fopen(text,"w");
				if (f) {
          fwrite(&nds_freq,1,sizeof(nds_freq),f);
          fwrite(&nds_video_depth,1,sizeof(nds_video_depth),f);
          fwrite(&nds_video_aspect,1,sizeof(nds_video_aspect),f);
          fwrite(&nds_video_sync,1,sizeof(nds_video_sync),f);
          fwrite(&nds_brightness,1,sizeof(nds_brightness),f);
          fwrite(&nds_sound,1,sizeof(nds_sound),f);
          fwrite(&nds_clock_cpu,1,sizeof(nds_clock_cpu),f);
          fwrite(&nds_clock_sound,1,sizeof(nds_clock_sound),f);
          fwrite(&nds_cpu_cores,1,sizeof(nds_cpu_cores),f);
          fwrite(&nds_volume,1,sizeof(nds_volume),f);
          fwrite(&i,1,sizeof(i),f);
          fwrite(&nds_cheat,1,sizeof(nds_cheat),f);
					fclose(f);
				}
			}

			/* Selected game will be run */
			return 1;
		}
		else if ((ExKey & NDS_B) || (ExKey & NDS_Y) || (ExKey & NDS_SELECT))
		{
			/* Return To Menu */
			return 0;
		}
	}
}

static void nds_exit(void)
{
#if 0
	remove("frontend/mame.lst");
	sync();
#endif	
  nds_deinit();
  
  /* close devices */
  ds2_plug_exit();
}

static int select_game(char *emu, char *game)
{

	unsigned long ExKey;

	/* No Selected game */
	strcpy(game,"builtinn");

  /* load background */
  char name[256];
  FILE *f;
  sprintf(name,"%s/skins/ndsmenu.bmp",gameDir);
  f=fopen(name,"rb");
  if (f) {
    fread(ndsmenu_bmp,1,50230,f);
    fclose(f);
  }
  
	/* Wait until user selects a game */
	while(1)
	{
		game_list_view(&last_game_selected);
		nds_flush_video_down();

		if( nds_joystick_read()) nds_timer_delay(150); 
		while(!(ExKey=nds_joystick_read())) { /*sched_yield();*/ }

		if (ExKey & NDS_UP) last_game_selected--;
		if (ExKey & NDS_DOWN) last_game_selected++;
		if (ExKey & NDS_LEFT) last_game_selected-=21;
		if (ExKey & NDS_RIGHT) last_game_selected+=21;
		if ((ExKey & NDS_L) && (ExKey & NDS_R)) return 1;

		if ((ExKey & NDS_A) || (ExKey & NDS_START))
		{
			/* Select the game */
			game_list_select(last_game_selected, game, emu);

			/* Emulation Options */
			if(show_options(game))
			{
				break;
			}
		}
	}
  return 0;
}

void execute_game (char *playemu, char *playgame)
{
	char *args[255];
	char str[8][64];
	int n=0;
	int i=0;
	
	/* executable */
	args[n]=playemu; n++;

	/* playgame */
	args[n]=playgame; n++;

	/* nds_freq */
	args[n]="-clock"; n++;
	sprintf(str[i],"%d",nds_freq);
	args[n]=str[i]; i++; n++;

	/*
	 * This is NOT the Dingoo's video depth!
	 * This is MAME's internal video depth.
	 * The Nds LCD can only display 16-bit so MAME's 8-bit video
	 * is mapped to Nds's 16-bit when blitting (see blit.cpp).
	 */
	if (nds_video_depth==8)
	{
		args[n]="-depth"; n++;
		args[n]="8"; n++;
	}
	if (nds_video_depth==16)
	{
		args[n]="-depth"; n++;
		args[n]="16"; n++;
	}

	/* nds_video_aspect */
	if ((nds_video_aspect==1) || (nds_video_aspect==6))
	{
		args[n]="-horizscale"; n++;
		args[n]="-nodirty"; n++;
	}
	if ((nds_video_aspect==2) || (nds_video_aspect==7))
	{
		args[n]="-bestscale"; n++;
		args[n]="-nodirty"; n++;
	}
	if ((nds_video_aspect==3) || (nds_video_aspect==8))
	{
		args[n]="-fastscale"; n++;
		args[n]="-nodirty"; n++;
	}
	if ((nds_video_aspect==4) || (nds_video_aspect==9))
	{
		args[n]="-halfscale"; n++;
		args[n]="-nodirty"; n++;
	}
	if ((nds_video_aspect>=5) && (nds_video_aspect<=9))
	{
		args[n]="-rotatecontrols"; n++;
		args[n]="-ror"; n++;
	}
	
	/* nds_video_sync */
	if (nds_video_sync==1)
	{
		args[n]="-nodirty"; n++;
		args[n]="-dblbuf"; n++;
	}
	else if (nds_video_sync==-1)
	{
		args[n]="-nothrottle"; n++;
	}
	
	/* nds_brightness */
	if (nds_brightness)
	{
		args[n]="--brightness"; n++;
		sprintf(str[i],"%d",nds_brightness);
		args[n]=str[i]; i++; n++;
	}

	/* nds_sound */
	if (nds_sound==0)
	{
		args[n]="-soundcard"; n++;
		args[n]="0"; n++;
	}
	if ((nds_sound==1) || (nds_sound==5) || (nds_sound==9))
	{
		args[n]="-samplerate"; n++;
		args[n]="8000"; n++;
	}
	if ((nds_sound==2) || (nds_sound==6) || (nds_sound==10))
	{
		args[n]="-samplerate"; n++;
		args[n]="16000"; n++;
	}
	if ((nds_sound==3) || (nds_sound==7) || (nds_sound==11))
	{
		args[n]="-samplerate"; n++;
		args[n]="22050"; n++;
	}
	if ((nds_sound==4) || (nds_sound==8) || (nds_sound==12))
	{
		args[n]="-samplerate"; n++;
		args[n]="48000"; n++;
	}
	if ((nds_sound>=1) && (nds_sound<=4))
	{
		args[n]="-fastsound"; n++;
	}
	if (nds_sound>=9)
	{
		args[n]="-stereo"; n++;
	}

	/* nds_clock_cpu */
	if (nds_clock_cpu!=100)
	{
		args[n]="-uclock"; n++;
		sprintf(str[i],"%d",100-nds_clock_cpu);
		args[n]=str[i]; i++; n++;
	}

	/* nds_clock_sound */
	if (nds_clock_cpu!=100)
	{
		args[n]="-uclocks"; n++;
		sprintf(str[i],"%d",100-nds_clock_sound);
		args[n]=str[i]; i++; n++;
	}
	
	/* nds_cpu_cores */
	if ((nds_cpu_cores==1) || (nds_cpu_cores==3))
	{
		args[n]="-fast_68000"; n++;
	}
	if ((nds_cpu_cores==2) || (nds_cpu_cores==3))
	{
		args[n]="-fast_z80"; n++;
	}

	switch (nds_volume)
	{
		case 1: break; /* nothing, default to maximum volume */
		case 2: args[n]="-volume"; n++; args[n]="-4"; n++; break;
		case 3: args[n]="-volume"; n++; args[n]="-8"; n++; break;
		case 4: args[n]="-volume"; n++; args[n]="-10"; n++; break;
	}
	
	if (nds_cheat)
	{
		args[n]="-cheat"; n++;
	}

	if (nds_profilemode)
	{
		args[n]="-profilemode"; n++;
	}

	args[n]=NULL;
	
#if 0
	for (i=0; i<n; i++)
	{
		printf("%s ",args[i]);
	}
	printf("\n");
#endif

  main_run_game (n,args);
}


int mainMame (int argc, char **argv)
{
	FILE *f;
  char text[256];

  /* Dingoo Initialization */
  nds_init(22050,16,0, NDS_DEFAULT_MHZ, NDS_DEFAULT_BRIGHT);

  /* Show intro screen */
  nds_intro_screen();

  /* Initialize list of available games */
  game_list_init(argc);
  nds_gamelist_text_out(0, 0, "V1.10");
  if (game_num_avail==0)
  {
 	nds_gamelist_text_out(128-strlen("ERROR: NO GAMES FOUND")*4, 92, "ERROR: NO GAMES FOUND");
	nds_flush_video_up();
	nds_flush_video_down();
	nds_joystick_press();
  }
  else {
   nds_flush_video_up();

    /* Read default configuration */
    sprintf(text,"%s/cfg/%s",gameDir,MAMECFG);
    f=fopen(text,"r");
    if (f) {
      fread(&nds_freq,1,sizeof(nds_freq),f);
      fread(&nds_video_depth,1,sizeof(nds_video_depth),f);
      fread(&nds_video_aspect,1,sizeof(nds_video_aspect),f);
      fread(&nds_video_sync,1,sizeof(nds_video_sync),f);
      fread(&nds_brightness,1,sizeof(nds_brightness),f);
      fread(&nds_sound,1,sizeof(nds_sound),f);
      fread(&nds_clock_cpu,1,sizeof(nds_clock_cpu),f);
      fread(&nds_clock_sound,1,sizeof(nds_clock_sound),f);
      fread(&nds_cpu_cores,1,sizeof(nds_cpu_cores),f);
      fread(&nds_volume,1,sizeof(nds_volume),f);
      fread(&last_game_selected,1,sizeof(last_game_selected),f);
      fread(&nds_cheat,1,sizeof(nds_cheat),f);
      fclose(f);
    }

    /* Convert from old settings */
    if (nds_brightness < 10)
    {
      nds_brightness = 70;
    }
    
    while(1) {
      /* Select Game */
      nds_intro_screen(); nds_flush_video_up();
      ndsmenu_bmp = (unsigned char *) malloc(50230);
      int res = select_game(playemu,playgame); 
      free(ndsmenu_bmp); // to have more memory

      if (!res) {
        /* Write default configuration */
        f=fopen(text,"w");
        if (f) {
          fwrite(&nds_freq,1,sizeof(nds_freq),f);
          fwrite(&nds_video_depth,1,sizeof(nds_video_depth),f);
          fwrite(&nds_video_aspect,1,sizeof(nds_video_aspect),f);
          fwrite(&nds_video_sync,1,sizeof(nds_video_sync),f);
          fwrite(&nds_brightness,1,sizeof(nds_brightness),f);
          fwrite(&nds_sound,1,sizeof(nds_sound),f);
          fwrite(&nds_clock_cpu,1,sizeof(nds_clock_cpu),f);
          fwrite(&nds_clock_sound,1,sizeof(nds_clock_sound),f);
          fwrite(&nds_cpu_cores,1,sizeof(nds_cpu_cores),f);
          fwrite(&nds_volume,1,sizeof(nds_volume),f);
          fwrite(&last_game_selected,1,sizeof(last_game_selected),f);
          fwrite(&nds_cheat,1,sizeof(nds_cheat),f);
          fclose(f);
        }
        
        /* Execute Game */
	ds2_clearScreen(UP_SCREEN, 0); ds2_flipScreen(UP_SCREEN, 1);ds2_clearScreen(UP_SCREEN, 0); ds2_flipScreen(UP_SCREEN, 1);
	nds_clear_video(DUAL_SCREEN);
        nds_printf_init();
        execute_game (playemu,playgame);
        
        /* wait releasing key */
        while(nds_joystick_read()) { nds_timer_delay(150); }
      }
      else {
        nds_deinit();
        break;
      }
    }
  }

	
  /* close devices */
  ds2_plug_exit();

  return 0;
}

