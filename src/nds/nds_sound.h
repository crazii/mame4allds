#ifndef __NDS_SOUND_H__
#define __NDS_SOUND_H__

extern void nds_sound_volume(int left, int right);
extern void nds_sound_thread_mute(void);
extern void nds_sound_thread_start(void);
extern void nds_sound_thread_stop(void);
extern void nds_sound_set_rate(int rate);
extern void nds_sound_set_stereo(int stereo);

#endif
