#include <stdlib.h>
#include <stdio.h> 

#include "ds2io.h"

void nds_set_clock(unsigned int mhz) 
{
/*  if (mhz == 300) ds2_setCPUclocklevel(9);
  else */
  if (mhz == 336) ds2_setCPUclocklevel(10);
  else if (mhz == 360) ds2_setCPUclocklevel(11);
  else if (mhz == 384) ds2_setCPUclocklevel(12);
  else if (mhz == 396) ds2_setCPUclocklevel(13);
  else ds2_setCPUclocklevel(10);
}
