# mame4allds
mame4all for supercard DSTWO by Alekmaul

--------------------------------------------------------------------------------

alekmaul at portabledev.com
http://www.portabledev.com
--------------------------------------------------------------------------------

MAME4ALL DsTwo is a port of MAME 0.37b5 emulator (originally by Nicola Salmoria) 
for the Nds with Supercard DSTwo. MAME4ALL is also available for the GP2X, Wiz, PSP 
, Linux and GP32.  Please refer to the MAME license at the end of this document.
Mame4ALL Os Native base on Slaanesh Dingux source code, which is based on source code 
from the GP2X port of MAME4ALL.
The original MAME4ALL is based on MAME 0.37b5.


--------------------------------------------------------------------------------
Configuration options:
--------------------------------------------------------------------------------
-- Nds Clock --
Overclocking. Try this if the game is too slow.

-- Video Depth --
Sets MAME's internal video depth (NOT the NdsTwo's video depth).
8-bit is generally faster though some games require 16-bit.
Some games may be faster in 16-bit mode - it's dependant on the game driver!
Auto: The emulator uses the most suitable video depth.
8 bit: MAME uses 8 bit color (DEFAULT).
16 bit: MAME uses 16 bit color.

-- Video Scale/Aspect --
The video aspect is configured with the following combination of options:

Normal:
Nominal video resolution (256x192). Games with a resolution less than this 
have a black border. Games with a resolution higher are cropped.

Scale Half Size:
Useful for high resolution games like Rampage and Tapper, etc. 8-bit video 
mode is quickest as extra pixels are just truncated. 16-bit mode does pixel 
mixing resulting in a nicer, but slightly slower display. Should still be 
quick enough for most games.

Scale Horizontal:
Useful for games like R-Type and Final Fight, etc. Other smaller resolution 
games will stretch out to fill the screen. Take from MAME4ALL Wiz version 
(code originally from Notaz & Franxis).

Scale Best:
This is a generic rescale that can resize any screen to fit the NdsTwo's native 
320x240 resolution. It produces the best quality scaled display as pixels are 
merged both horizontally and vertically. The downside is that it may be slow.

Scale Fast:
his is a generic rescale that can resize any screen to fit the NdsTwo's native 320x240
resolution. It produces a good scaled display as pixels are merged horizontally. 
Speed should be somewhat quicker than "Scale Best".

Rotate:
The display is rotated from landscape to portrait orientation. All the above scale
options are present for screen rotation.

-- Video Sync --
Normal: Single buffer and dirty buffer is used (DEFAULT).
VSync: VSync activated (Unlikely to be ever implemented due to lack of hardware support).
DblBuf: Double buffer without dirty buffer (NOT IMPLEMENTED YET).
OFF: No video synchronization, use manual frameskip.

-- Brightness --
No Brightness actually. 

-- Sound --
The sound options are the following ones:
ON: The sound is activated. 8, 16, 24, 32 KHz sound mixing rates are available in 
both mono and stereo, (22050hz mono DEFAULT).
OFF: The sound is disabled. This can vastly improve the speed of the game.
Fast sound: Improve performance at the cost of sound quality.

-- CPU Clock --
The clock of the CPUs can be adjusted from 50% to 200%. The nominal value is 100% 
(DEFAULT) and the CPU is emulated accurately.
The clock can be safely underclocked to about 80% to gain performance in almost all 
games (be careful because some games could not run correctly). Use lower values to get 
more performance but probably several more games would not run correctly. Also the clock 
can be overclocked up to 200%.

-- Audio Clock --
The clock of the audio CPUs can also be adjusted from 50% to 200%. The nominal 
value is 100% (DEFAULT). See "CPU Clock" above.

-- CPU Cores --
(NOT IMPLEMENTED YET)

-- Volume --
(NOT IMPLEMENTED YET)

-- Cheats --
ON: The cheats are enabled. To access in game press SELECT+START and enter the "Cheats" menu.
OFF: The cheats are disabled.
Note: The high scores are not saved if cheats are enabled!!!.

-- Auto-Fire --
To access the auto-fire configuration, during game press SELECT+START and enter the "Auto-Fire" menu.


--------------------------------------------------------------------------------
Credits
--------------------------------------------------------------------------------
Special thanks to :
  Supercard DSTwo team for sdk.
  Slaanesh for Dingux port of mame (http://www.slaanesh.net/).
  Franxis: Originally porting MAME to GP32, GP2X and Wiz (http://www.talfi.net/gp32_franxis/).
Without the help of the infos from these people, this emulator can't be here.

