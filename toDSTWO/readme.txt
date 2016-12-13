title	Bucky O'Hare (ver UA)
set name	buckyua
manufacturer	Konami
year	1992
genre	Shooter (hof)
category	Shooter / Walking (hof)
driver status	good
driver source	moo.c




MAME4ALL DsTwo V1.10 for Nds with Supercard DSTwo
--------------------------------------------------------------------------------
MAME4ALL DsTwo is a port of MAME 0.37b5 emulator (originally by Nicola Salmoria) 
for the Nds with Supercard DSTwo. MAME4ALL is also available for the GP2X, Wiz, PSP 
, Linux and GP32.  Please refer to the MAME license at the end of this document.
Mame4ALL Os Native base on Slaanesh Dingux source code, which is based on source code 
from the GP2X port of MAME4ALL.
The original MAME4ALL is based on MAME 0.37b5.
This readme file is also based on Slaanesh readme.txt file.
FAQ.txt file also based on Slaanesh FAQ.txt file.

SOURCE CODE WILL BE AVAILABLE SOON

Features :
----------
MAME4ALL DsTwo currently emulates lots of arcade games supported by original MAME 0.37b5 
plus some additional games from newer MAME versions. Some larger games currently do 
not work due to lack of system RAM.

Missing :
---------
Adding all Mame4All games
Some games hang DsTwo, sorry about that :(
Sound is not really nice but i think it's a speed problem ...

Check updates on my web site : http://www.portabledev.com

--------------------------------------------------------------------------------
History :
--------------------------------------------------------------------------------
V1.10  : xx/02/2011
  Add neogeo games (but lots of games need too much memory and too much speed,
   sorry about that, it's only a DS :/)
  Add sound management in menu (don't know why it was comment)
  Fix bug in tilemap free memory function, sf1 no more hangs but can't be run because
   we do not have enough memory
  Change to last s2dsdk tools
  Add FrameSkip icon

V1.0  : 26/10/2010
  1st public release

V1.0 *TEST * : 16/10/2010
  Initiale release for *test* purpose

--------------------------------------------------------------------------------
How to use this emulator :
--------------------------------------------------------------------------------
Unzip Mame4AllDsTwo_V10.zip in root directory of DSTWO, you will have a MAME directory 
and 24 files in _dstwoplug to put in your _dstwoplug directory.

Put roms in /MAME/roms directory. Roms must be compatible with mame0.37b5 !

Controls :

Standard in-game MAME controls:

- D-Pad: UP, DOWN, LEFT and RIGHT.
- Buttons A,B,X,Y,L,R: MAME buttons 1,2,3,4,5,6.
- Button SELECT+START: Insert credit.
- Button START: Start game.


Extended controls in game (to access menus and options)
All use the SELECT button + an additional button.
This is analagous to pressing "SHIFT" and another key on a regular keyboard.

- Buttons SELECT+L: Show profiler.
- Buttons SELECT+R: Show FPS.     
- Buttons SELECT+Y: Pause.
- Buttons SELECT+X: Enter/Exit Volume menu.
- Buttons SELECT+B: Enter/Exit MAME menu

Also 
- Buttons START+L+R: Exit (to Mame4All menu).
- Button B mapped to Enter
- Button X mapped to Space

The botton screen allows you to take a screen shot or add coins to play.

The "MAME menu" (see above) can be used to:

- Redefine DEFAULT keys for all games.
- Redefine keys for the current game.
- Display game information.
- Set Auto-fire options.
- Enable cheats.

Controller Notes:

- All keys can be redefined, including the "shifted" SELECT keys.
  In some cases this is essential. ie. Robotron.
- To type OK when MAME requires it, press LEFT and then RIGHT.


The Game Selector will search for MAME ROMs found in the ./roms directory. 
Games found will be displayed in the game list.

- Use UP and DOWN to select a game.
- Use LEFT and RIGHT to page up and page down.
- Press A to select the game to play.
- Press SELECT+L+R to exit.

After selecting a game, configuration options are available:

- Use UP and DOWN to select the option you want to change.
- Use LEFT and RIGHT to change the option.
- Press A to start the game (and save the configured options).
- Press X to go back to the game list.

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


The following files and directories may exist in the mame4all directory.
Optional entries are noted with [*].

mame<name>.app  -> Mame emulator version for each type of games.
cheat.dat       -> [*] Cheats definition file
hiscore.dat     -> [*] High Scores definition file
artwork/        -> [*] Artwork directory
cfg/            -> MAME configuration files directory
frontend/       -> Frontend configuration files
hi/             -> [*] High Scores directory
inp/            -> [*] Game recordings directory
memcard/        -> [*] Memory card files directory
nvram/          -> NVRAM files directory
roms/           -> ROMs directory
samples/        -> [*] Samples directory
skins/          -> [*] Frontend skins directory
snap/           -> [*] Screen snapshots directory
sta/            -> [*] Save states directory

--------------------------------------------------------------------------------
Supported games :
--------------------------------------------------------------------------------
The original version of MAME 0.37b5 supported 2260 romsets. For more details, see "gamelist.txt" file.
Games must be copied into the <installdir>/roms/ folder.

Neo Geo games are currently not included. Use Standard emulator instead for these.


ROM NAMES :
------------
Folder names or ZIP file names are listed on "gamelist.txt" file.
Romsets have to be MAME 0.37b5 ones (July 2000).
Additionaly there are additional romsets from newer MAME versions.

Please use "clrmame.dat" file to convert romsets from other MAME versions to the ones 
used by this version for NdsTwo, using ClrMAME Pro utility, available in next webpage:

http://mamedev.emulab.it/clrmamepro/

NOTE: File and directory names in Linux are case-sensitive. Put all file and directory names using low case!.

!!!! THE MOST COMMON PROBLEM FOR NOT GETTING A SUPPORTED GAME TO RUN IS INCOMPATIBLE ROMS. !!!!


SOUND SAMPLES
----------------
The sound samples are used to get complete sound in some games.
They are placed into the 'samples' directory compressed into ZIP files.
The directory and the ZIP files are named using low case!.

The sound samples collection can be downloaded in the following link:
http://archive.gp2x.de/cgi-bin/cfiles.cgi?0,0,0,0,5,2511

You can also use "clrmame.dat" file with ClrMAME Pro utility to get the samples pack.


ARTWORK
----------
Artwork is used to improve the visualization for some games. Download it here:
http://archive.gp2x.de/cgi-bin/cfiles.cgi?0,0,0,0,5,2512


ORIGINAL CREDITS
-------------------
- MAME 0.37b5 original version by Nicola Salmoria and the MAME Team (http://www.mame.net).

- Z80 emulator Copyright (c) 1998 Juergen Buchmueller, all rights reserved.
- M6502 emulator Copyright (c) 1998 Juergen Buchmueller, all rights reserved.
- Hu6280 Copyright (c) 1999 Bryan McPhail, mish@tendril.force9.net
- I86 emulator by David Hedley, modified by Fabrice Frances (frances@ensica.fr)
- M6809 emulator by John Butler, based on L.C. Benschop's 6809 Simulator V09.
- M6808 based on L.C. Benschop's 6809 Simulator V09.
- M68000 emulator Copyright 1999 Karl Stenerud.  All rights reserved.
- 80x86 M68000 emulator Copyright 1998, Mike Coates, Darren Olafson.
- 8039 emulator by Mirko Buffoni, based on 8048 emulator by Dan Boris.
- T-11 emulator Copyright (C) Aaron Giles 1998
- TMS34010 emulator by Alex Pasadyn and Zsolt Vasvari.
- TMS9900 emulator by Andy Jones, based on original code by Ton Brouwer.
- Cinematronics CPU emulator by Jeff Mitchell, Zonn Moore, Neil Bradley.
- Atari AVG/DVG emulation based on VECSIM by Hedley Rainnie, Eric Smith and Al Kossow.
- TMS5220 emulator by Frank Palazzolo.
- AY-3-8910 emulation based on various code snippets by Ville Hallik, Michael Cuddy, Tatsuyuki Satoh, Fabrice Frances, Nicola Salmoria.
- YM-2203, YM-2151, YM3812 emulation by Tatsuyuki Satoh.
- POKEY emulator by Ron Fries (rfries@aol.com). Many thanks to Eric Smith, Hedley Rainnie and Sean Trowbridge.
- NES sound hardware info by Jeremy Chadwick and Hedley Rainne.
- YM2610 emulation by Hiromitsu Shioya.


SKINS
---------
The frontend graphic skin used in the emulator can be changed by adding two new files:
skins/ndssplash.bmp   -> Game selector intro screen.
skins/ndsmenu.bmp     -> Game selector background screen.
skins/ndsingame.bmp   -> Game options background screen during play.

Bitmaps MUST be 256x192 pixels x 256 colors (8 bit).
The resulting file should be exactly 50230 bytes in size. If it is not, then
it's not in the right format. Paint Shop Pro saves BMPs in the correct format.

Previous versions of splash screens are included in the skins/previous directory.

--------------------------------------------------------------------------------
Credits
--------------------------------------------------------------------------------
Special thanks to :
  Supercard DSTwo team for sdk.
  Slaanesh for Dingux port of mame (http://www.slaanesh.net/).
  Franxis: Originally porting MAME to GP32, GP2X and Wiz (http://www.talfi.net/gp32_franxis/).
Without the help of the infos from these people, this emulator can't be here.

--------------------------------------------------------------------------------
Alekmaul
alekmaul@portabledev.com
http://www.portabledev.com
--------------------------------------------------------------------------------


--------------------------------------------------------------------------------
MAME LICENSE
--------------------------------------------------------------------------------

http://www.mame.net
http://www.mamedev.com

Copyright © 1997-2009, Nicola Salmoria and the MAME team. All rights reserved. 

Redistribution and use of this code or any derivative works are permitted provided that the following 
conditions are met: 

* Redistributions may not be sold, nor may they be used in a commercial product or activity. 

* Redistributions that are modified from the original source must include the complete source code, 
including the source code for all components used by a binary built from the modified sources. However,
 as a special exception, the source code distributed need not include anything that is normally distributed
 (in either source or binary form) with the major components (compiler, kernel, and so on) of the operating
 system on which the executable runs, unless that component itself accompanies the executable.  
* Redistributions must reproduce the above copyright notice, this list of conditions and the following disclaimer
 in the documentation and/or other materials provided with the distribution. 

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
 DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
 SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
 WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE 
 USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 


