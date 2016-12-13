# engage tiny mame
CFLAGS+=-DTINY_COMPILE

# uses these CPUs
CPUS+=8080@
CPUS+=I86@
#CPUS+=I186@
CPUS+=I8039@
#CPUS+=H6280@
CPUS+=M6502@
CPUS+=M65C02@
CPUS+=M6802@
CPUS+=M6803@
CPUS+=M6808@
CPUS+=M6809@
CPUS+=M68000@
CPUS+=M68010@
CPUS+=M68EC020@
CPUS+=M68705@
CPUS+=N2A03@
CPUS+=NSC8105@
CPUS+=V30@
CPUS+=Z80@

# uses these SOUNDs
SOUNDS+=AY8910@
SOUNDS+=YM2151@
SOUNDS+=YM2203@
SOUNDS+=YM2413@
SOUNDS+=YM2608@
SOUNDS+=YM2610@
SOUNDS+=YM2610B@
SOUNDS+=YM2612@
SOUNDS+=YM3438@
SOUNDS+=YM3526@
SOUNDS+=YM3812@
SOUNDS+=Y8950@
SOUNDS+=OKIM6295@
SOUNDS+=ADPCM@
SOUNDS+=DAC@
SOUNDS+=CUSTOM@
SOUNDS+=NAMCO@
SOUNDS+=HC55516@
SOUNDS+=SAMPLES@
SOUNDS+=SN76477@
SOUNDS+=SN76496@
SOUNDS+=QSOUND@
SOUNDS+=MSM5205@
SOUNDS+=TMS5220@
SOUNDS+=UPD7759@
SOUNDS+=NES@
SOUNDS+=VLM5030@
SOUNDS+=CEM3394@

OBJS= \
	$(OBJ)/drivers/aeroboto.o \
	$(OBJ)/drivers/aerofgt.o \
	$(OBJ)/drivers/airbustr.o \
	$(OBJ)/drivers/alpha68k.o \
	$(OBJ)/drivers/ambush.o \
	$(OBJ)/drivers/appoooh.o \
	$(OBJ)/drivers/arabian.o \
	$(OBJ)/drivers/argus.o \
	$(OBJ)/drivers/armedf.o \
	$(OBJ)/drivers/balsente.o \
	$(OBJ)/drivers/bankp.o \
	$(OBJ)/drivers/battlane.o \
	$(OBJ)/drivers/berzerk.o \
	$(OBJ)/drivers/bjtwin.o \
	$(OBJ)/drivers/bking2.o \
	$(OBJ)/drivers/blockade.o \
	$(OBJ)/drivers/bloodbro.o \
	$(OBJ)/drivers/blueprnt.o \
	$(OBJ)/drivers/bogeyman.o \
	$(OBJ)/drivers/bublbobl.o \
	$(OBJ)/drivers/capbowl.o \
	$(OBJ)/drivers/champbas.o \
	$(OBJ)/drivers/circus.o \
	$(OBJ)/drivers/cop01.o \
	$(OBJ)/drivers/crbaloon.o \
	$(OBJ)/drivers/dcon.o \
	$(OBJ)/drivers/dday.o \
	$(OBJ)/drivers/deniam.o \
	$(OBJ)/drivers/dlair.o \
	$(OBJ)/drivers/dotrikun.o \
	$(OBJ)/drivers/dynduke.o $(OBJ)/sndhrdw/seibu.o \
	$(OBJ)/drivers/exctsccr.o \
	$(OBJ)/drivers/exidy.o \
	$(OBJ)/drivers/exidy440.o \
	$(OBJ)/drivers/flstory.o \
	$(OBJ)/drivers/funkybee.o \
	$(OBJ)/drivers/gaelco.o \
	$(OBJ)/drivers/gaiden.o \
	$(OBJ)/drivers/galivan.o \
	$(OBJ)/drivers/galpanic.o \
	$(OBJ)/drivers/gameplan.o \
	$(OBJ)/drivers/ginganin.o \
	$(OBJ)/drivers/gladiatr.o \
	$(OBJ)/drivers/goindol.o \
	$(OBJ)/drivers/gottlieb.o \
	$(OBJ)/drivers/gotya.o \
	$(OBJ)/drivers/gsword.o \
	$(OBJ)/drivers/gundealr.o \
	$(OBJ)/drivers/hal21.o \
	$(OBJ)/drivers/hanaawas.o \
	$(OBJ)/drivers/hexa.o \
	$(OBJ)/drivers/kaneko16.o \
	$(OBJ)/drivers/kangaroo.o \
	$(OBJ)/drivers/kncljoe.o $(OBJ)/sndhrdw/irem.o \
	$(OBJ)/drivers/kopunch.o \
	$(OBJ)/drivers/kyugo.o \
	$(OBJ)/drivers/lasso.o \
	$(OBJ)/drivers/lastduel.o \
	$(OBJ)/drivers/leprechn.o \
	$(OBJ)/drivers/lkage.o \
	$(OBJ)/drivers/lsasquad.o \
	$(OBJ)/drivers/m79amb.o \
	$(OBJ)/drivers/macross.o \
	$(OBJ)/drivers/magix.o \
	$(OBJ)/drivers/marvins.o \
	$(OBJ)/drivers/matmania.o \
	$(OBJ)/drivers/megazone.o $(OBJ)/machine/konami.o \
	$(OBJ)/drivers/mermaid.o \
	$(OBJ)/drivers/minivadr.o \
	$(OBJ)/drivers/mitchell.o $(OBJ)/machine/kabuki.o \
	$(OBJ)/drivers/mnight.o \
	$(OBJ)/drivers/mole.o \
	$(OBJ)/drivers/momoko.o \
	$(OBJ)/drivers/mrjong.o \
	$(OBJ)/drivers/munchmo.o \
	$(OBJ)/drivers/mystston.o \
	$(OBJ)/drivers/ninjakd2.o \
	$(OBJ)/drivers/ohmygod.o \
	$(OBJ)/drivers/pbaction.o \
	$(OBJ)/drivers/pinbo.o \
	$(OBJ)/drivers/pipedrm.o \
	$(OBJ)/drivers/polyplay.o \
	$(OBJ)/drivers/powerins.o \
	$(OBJ)/drivers/prehisle.o \
	$(OBJ)/drivers/psikyo.o \
	$(OBJ)/drivers/psychic5.o \
	$(OBJ)/drivers/punchout.o \
	$(OBJ)/drivers/qix.o \
	$(OBJ)/drivers/raiden.o \
	$(OBJ)/drivers/retofinv.o \
	$(OBJ)/drivers/rockola.o \
	$(OBJ)/drivers/route16.o \
	$(OBJ)/drivers/royalmah.o \
	$(OBJ)/drivers/rpunch.o \
	$(OBJ)/drivers/safarir.o \
	$(OBJ)/drivers/sauro.o \
	$(OBJ)/drivers/scregg.o $(OBJ)/vidhrdw/btime.o \
	$(OBJ)/drivers/seicross.o \
	$(OBJ)/drivers/senjyo.o $(OBJ)/machine/segacrpt.o \
	$(OBJ)/drivers/seta.o \
	$(OBJ)/drivers/shangha3.o \
	$(OBJ)/drivers/shanghai.o \
	$(OBJ)/drivers/sharkatt.o \
	$(OBJ)/drivers/shisen.o $(OBJ)/sndhrdw/m72.o \
	$(OBJ)/drivers/shuuz.o $(OBJ)/machine/atarigen.o $(OBJ)/machine/slapstic.o \
	$(OBJ)/drivers/skyfox.o \
	$(OBJ)/drivers/slapfght.o \
	$(OBJ)/drivers/snk.o \
	$(OBJ)/drivers/snk68.o \
	$(OBJ)/drivers/speedbal.o \
	$(OBJ)/drivers/spiders.o \
	$(OBJ)/drivers/splash.o \
	$(OBJ)/drivers/ssozumo.o \
	$(OBJ)/drivers/stactics.o \
	$(OBJ)/drivers/starcrus.o \
	$(OBJ)/drivers/starfire.o \
	$(OBJ)/drivers/stfight.o \
	$(OBJ)/drivers/suna8.o \
	$(OBJ)/drivers/superqix.o \
	$(OBJ)/drivers/tagteam.o \
	$(OBJ)/drivers/tail2nos.o $(OBJ)/vidhrdw/konamiic.o \
	$(OBJ)/drivers/taito_b.o $(OBJ)/sndhrdw/rastan.o \
	$(OBJ)/drivers/taito_f2.o $(OBJ)/vidhrdw/taitoic.o $(OBJ)/machine/cchip.o \
	$(OBJ)/drivers/taito_l.o  $(OBJ)/sndhrdw/taitosnd.o \
	$(OBJ)/drivers/taitosj.o \
	$(OBJ)/drivers/tehkanwc.o \
	$(OBJ)/drivers/terracre.o \
	$(OBJ)/drivers/thepit.o \
	$(OBJ)/drivers/tigeroad.o \
	$(OBJ)/drivers/tsamurai.o \
	$(OBJ)/drivers/ttmahjng.o \
	$(OBJ)/drivers/ultraman.o \
	$(OBJ)/drivers/vastar.o \
	$(OBJ)/drivers/victory.o \
	$(OBJ)/drivers/wc90.o \
	$(OBJ)/drivers/wc90b.o \
	$(OBJ)/drivers/wiping.o \
	$(OBJ)/drivers/wiz.o \
	$(OBJ)/drivers/xain.o \
	$(OBJ)/drivers/xexex.o \
	$(OBJ)/drivers/yamato.o $(OBJ)/vidhrdw/cclimber.o \
	$(OBJ)/drivers/zaccaria.o \
	$(OBJ)/drivers/zerozone.o \
	$(OBJ)/drivers/zodiack.o $(OBJ)/vidhrdw/galaxian.o $(OBJ)/drivers/espial.o


# MAME specific core objs
COREOBJS += $(OBJ)/driver.o
