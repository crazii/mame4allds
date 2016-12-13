/****************/
/* Neogeo games */
/****************/

/* SNK */
extern struct GameDriver driver_nam1975;
extern struct GameDriver driver_bstars;
extern struct GameDriver driver_tpgolf;
extern struct GameDriver driver_mahretsu;
extern struct GameDriver driver_ridhero;
extern struct GameDriver driver_alpham2;
extern struct GameDriver driver_cyberlip;
extern struct GameDriver driver_superspy;
extern struct GameDriver driver_mutnat;
extern struct GameDriver driver_kotm;
extern struct GameDriver driver_sengoku;
extern struct GameDriver driver_sengokh;
extern struct GameDriver driver_burningf;
extern struct GameDriver driver_burningh;
extern struct GameDriver driver_lbowling;
extern struct GameDriver driver_gpilots;
extern struct GameDriver driver_joyjoy;
extern struct GameDriver driver_quizdais;
extern struct GameDriver driver_lresort;
extern struct GameDriver driver_eightman;
extern struct GameDriver driver_legendos;
extern struct GameDriver driver_2020bb;
extern struct GameDriver driver_2020bbh;
extern struct GameDriver driver_socbrawl;
extern struct GameDriver driver_fatfury1;
extern struct GameDriver driver_roboarmy;
extern struct GameDriver driver_fbfrenzy;
extern struct GameDriver driver_kotm2;
extern struct GameDriver driver_sengoku2;
extern struct GameDriver driver_bstars2;
extern struct GameDriver driver_quizdai2;
extern struct GameDriver driver_3countb;
extern struct GameDriver driver_aof;
extern struct GameDriver driver_samsho;
extern struct GameDriver driver_tophuntr;
extern struct GameDriver driver_fatfury2;
extern struct GameDriver driver_ssideki;
extern struct GameDriver driver_kof94;
extern struct GameDriver driver_aof2;
extern struct GameDriver driver_fatfursp;
extern struct GameDriver driver_savagere;
extern struct GameDriver driver_ssideki2;
extern struct GameDriver driver_samsho2;
extern struct GameDriver driver_fatfury3;
extern struct GameDriver driver_ssideki3;
extern struct GameDriver driver_kof95;
extern struct GameDriver driver_samsho3;
extern struct GameDriver driver_rbff1;
extern struct GameDriver driver_aof3;
extern struct GameDriver driver_kof96;
extern struct GameDriver driver_ssideki4;
extern struct GameDriver driver_kizuna;
extern struct GameDriver driver_samsho4;
extern struct GameDriver driver_rbffspec;
extern struct GameDriver driver_kof97;
extern struct GameDriver driver_lastblad;
extern struct GameDriver driver_irrmaze;
extern struct GameDriver driver_rbff2;
extern struct GameDriver driver_mslug2;
extern struct GameDriver driver_kof98;
extern struct GameDriver driver_lastbld2;
extern struct GameDriver driver_neocup98;
extern struct GameDriver driver_mslugx;
extern struct GameDriver driver_kof99;
extern struct GameDriver driver_garou;

/* Alpha Denshi Co. / ADK (changed name in 1993) */
extern struct GameDriver driver_maglord;
extern struct GameDriver driver_maglordh;
extern struct GameDriver driver_ncombat;
extern struct GameDriver driver_bjourney;
extern struct GameDriver driver_crsword;
extern struct GameDriver driver_trally;
extern struct GameDriver driver_ncommand;
extern struct GameDriver driver_wh1;
extern struct GameDriver driver_wh2;
extern struct GameDriver driver_wh2j;
extern struct GameDriver driver_aodk;
extern struct GameDriver driver_whp;
extern struct GameDriver driver_mosyougi;
extern struct GameDriver driver_overtop;
extern struct GameDriver driver_ninjamas;
extern struct GameDriver driver_twinspri;

/* Aicom */
extern struct GameDriver driver_janshin;
extern struct GameDriver driver_pulstar;

/* Data East Corporation */
extern struct GameDriver driver_spinmast;
extern struct GameDriver driver_wjammers;
extern struct GameDriver driver_karnovr;
extern struct GameDriver driver_strhoop;
extern struct GameDriver driver_magdrop2;
extern struct GameDriver driver_magdrop3;

/* Face */
extern struct GameDriver driver_gururin;
extern struct GameDriver driver_miexchng;

/* Hudson Soft */
extern struct GameDriver driver_panicbom;
extern struct GameDriver driver_kabukikl;
extern struct GameDriver driver_neobombe;

/* Monolith Corp. */
extern struct GameDriver driver_minasan;
extern struct GameDriver driver_bakatono;

/* Nazca */
extern struct GameDriver driver_turfmast;
extern struct GameDriver driver_mslug;

/* NMK */
extern struct GameDriver driver_zedblade;

/* Sammy */
extern struct GameDriver driver_viewpoin;

/* Saurus */
extern struct GameDriver driver_quizkof;
extern struct GameDriver driver_stakwin;
extern struct GameDriver driver_ragnagrd;
extern struct GameDriver driver_pgoal;
extern struct GameDriver driver_stakwin2;
extern struct GameDriver driver_shocktro;
extern struct GameDriver driver_shocktr2;

/* Sunsoft */
extern struct GameDriver driver_galaxyfg;
extern struct GameDriver driver_wakuwak7;

/* Taito */
extern struct GameDriver driver_pbobble;
extern struct GameDriver driver_pbobbl2n;

/* Takara */
extern struct GameDriver driver_marukodq;

/* Technos */
extern struct GameDriver driver_doubledr;
extern struct GameDriver driver_gowcaizr;
extern struct GameDriver driver_sdodgeb;

/* Tecmo */
extern struct GameDriver driver_tws96;

/* Yumekobo */
extern struct GameDriver driver_blazstar;

/* Viccom */
extern struct GameDriver driver_fightfev;

/* Video System Co. */
extern struct GameDriver driver_pspikes2;
extern struct GameDriver driver_sonicwi2;
extern struct GameDriver driver_sonicwi3;
extern struct GameDriver driver_popbounc;

/* Visco */
extern struct GameDriver driver_androdun;
extern struct GameDriver driver_puzzledp;
extern struct GameDriver driver_neomrdo;
extern struct GameDriver driver_goalx3;
extern struct GameDriver driver_neodrift;
extern struct GameDriver driver_breakers;
extern struct GameDriver driver_puzzldpr;
extern struct GameDriver driver_breakrev;
extern struct GameDriver driver_flipshot;
extern struct GameDriver driver_ctomaday;

const struct GameDriver *drivers[] =
{

/* SNK */
  &driver_nam1975,
  &driver_bstars,
  &driver_tpgolf,
  &driver_mahretsu,
  &driver_ridhero,
  &driver_alpham2,
  &driver_cyberlip,
  &driver_superspy,
  &driver_mutnat,
  &driver_kotm,
  &driver_sengoku,
  &driver_sengokh,
  &driver_burningf,
  &driver_burningh,
  &driver_lbowling,
  &driver_gpilots,
  &driver_joyjoy,
  &driver_quizdais,
  &driver_lresort,
  &driver_eightman,
  &driver_legendos,
  &driver_2020bb,
  &driver_2020bbh,
  &driver_socbrawl,
  &driver_fatfury1,
  &driver_roboarmy,
  &driver_fbfrenzy,
  &driver_kotm2,
  &driver_sengoku2,
  &driver_bstars2,
  &driver_quizdai2,
  &driver_3countb,
  &driver_aof,
  &driver_samsho,
  &driver_tophuntr,
  &driver_fatfury2,
  &driver_ssideki,
  &driver_kof94,
  &driver_aof2,
  &driver_fatfursp,
  &driver_savagere,
  &driver_ssideki2,
  &driver_samsho2,
  &driver_fatfury3,
  &driver_ssideki3,
  &driver_kof95,
  &driver_samsho3,
  &driver_rbff1,
  &driver_aof3,
  &driver_kof96,
  &driver_ssideki4,
  &driver_kizuna,
  &driver_samsho4,
  &driver_rbffspec,
  &driver_kof97,
  &driver_lastblad,
  &driver_irrmaze,
  &driver_rbff2,
  &driver_mslug2,
  &driver_kof98,
  &driver_lastbld2,
  &driver_neocup98,
  &driver_mslugx,
  &driver_kof99,
  &driver_garou,

/* Alpha Denshi Co. / ADK (changed name in 1993) */
  &driver_maglord,
  &driver_maglordh,
  &driver_ncombat,
  &driver_bjourney,
  &driver_crsword,
  &driver_trally,
  &driver_ncommand,
  &driver_wh1,
  &driver_wh2,
  &driver_wh2j,
  &driver_aodk,
  &driver_whp,
  &driver_mosyougi,
  &driver_overtop,
  &driver_ninjamas,
  &driver_twinspri,

/* Aicom */
  &driver_janshin,
  &driver_pulstar,

/* Data East Corporation */
  &driver_spinmast,
  &driver_wjammers,
  &driver_karnovr,
  &driver_strhoop,
  &driver_magdrop2,
  &driver_magdrop3,

/* Face */
  &driver_gururin,
  &driver_miexchng,

/* Hudson Soft */
  &driver_panicbom,
  &driver_kabukikl,
  &driver_neobombe,

/* Monolith Corp. */
  &driver_minasan,
  &driver_bakatono,

/* Nazca */
  &driver_turfmast,
  &driver_mslug,

/* NMK */
  &driver_zedblade,

/* Sammy */
  &driver_viewpoin,

/* Saurus */
  &driver_quizkof,
  &driver_stakwin,
  &driver_ragnagrd,
  &driver_pgoal,
  &driver_stakwin2,
  &driver_shocktro,
  &driver_shocktr2,

/* Sunsoft */
  &driver_galaxyfg,
  &driver_wakuwak7,

/* Taito */
  &driver_pbobble,
  &driver_pbobbl2n,

/* Takara */
  &driver_marukodq,

/* Technos */
  &driver_doubledr,
  &driver_gowcaizr,
  &driver_sdodgeb,

/* Tecmo */
  &driver_tws96,

/* Yumekobo */
  &driver_blazstar,

/* Viccom */
  &driver_fightfev,

/* Video System Co. */
  &driver_pspikes2,
  &driver_sonicwi2,
  &driver_sonicwi3,
  &driver_popbounc,

/* Visco */
  &driver_androdun,
  &driver_puzzledp,
  &driver_neomrdo,
  &driver_goalx3,
  &driver_neodrift,
  &driver_breakers,
  &driver_puzzldpr,
  &driver_breakrev,
  &driver_flipshot,
  &driver_ctomaday,

	0	/* end of array */
};

