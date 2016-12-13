#include <stddef.h>

#include "ds2io.h"

#include "nds_sound.h"

#define MAX_SAMPLE_RATE (22050*2)

static volatile int sndlen=(MAX_SAMPLE_RATE*2)/60;// Current sound buffer length
unsigned short *nds_sound_buffers;

void dstwo_sound_play(void) {
  //assume 16-bit and stereo audio
  unsigned short *audio_buffer_addr;
  unsigned short *src;
  unsigned short *dst0;
  unsigned short *dst1;
  int n;

  //Maintance the audio buffer queue not more than 2
  //assume each audio queue have 512 samples, then at 22.05KHz, 2 queues can playing 46.44ms. 
  // it more than 2 video frame time
  if (ds2_checkAudiobuff() >= 2)
//  if (ds2_checkAudiobuff() > 4)
    return;

  //In fact, there is no neccessary to check whether the IO layer's audio buffers are busy or not, 
  //we updating audio not frequently as the example with DS2SDK did.
  audio_buffer_addr = (unsigned short*) ds2_getAudiobuff();
  if (audio_buffer_addr) 
  {
	  src = nds_sound_buffers;
	  dst0 = audio_buffer_addr;
	  dst1 = audio_buffer_addr + audio_samples_per_trans;

	  //Fill the buffer
	  n = 0;
          if (sndlen>audio_samples_per_trans) {
            while (n++ < audio_samples_per_trans) {
	      *dst0++ = *src;
              *dst1++ = *src++;
	    }
          }
          else {
            while (n++ < sndlen) {
	      *dst0++ = *src;
              *dst1++ = *src++;
	    }
            while (n++ < audio_samples_per_trans) {
	      *dst0++ = 0;
              *dst1++ = 0;
	    }
          } 
	  
	  //Update audio  
	  ds2_updateAudio();
   }
}

void nds_sound_play(void *buff, int len)
{
    nds_sound_buffers = buff;	 // Write the sound buffer
    sndlen=len;			// Update the sound buffer length
    dstwo_sound_play();
}

void nds_sound_thread_mute(void)
{
//	memset(nds_sound_buffers_total,0,(MAX_SAMPLE_RATE*16*2)/30);
	sndlen=(nds_sound_rate*2)/60;
}

void nds_sound_thread_start(void)
{
  nds_sound_set_stereo(nds_sound_stereo);
  nds_sound_set_rate(nds_sound_rate);
  sndlen=(nds_sound_rate*2)/60;
  nds_sound_thread_mute();
}

void nds_sound_thread_stop(void)
{
  ds2_setVolume(0);
  nds_sound_thread_mute();
}

void nds_sound_set_rate(int rate)
{

}

void nds_sound_set_stereo(int stereo)
{
}
