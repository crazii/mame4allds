/****************/
/* Capcom games */
/****************/

/* 1942 */
extern struct GameDriver driver_1942;
extern struct GameDriver driver_1942a;
extern struct GameDriver driver_1942b;
/* 1943 */
extern struct GameDriver driver_1943;
extern struct GameDriver driver_1943j;
extern struct GameDriver driver_1943kai;
/* Black Tiger */
extern struct GameDriver driver_blktiger;
extern struct GameDriver driver_bktigerb;
extern struct GameDriver driver_blkdrgon;
extern struct GameDriver driver_blkdrgnb;
/* Commando */
extern struct GameDriver driver_commando;
extern struct GameDriver driver_commandu;
extern struct GameDriver driver_commandj;
extern struct GameDriver driver_spaceinv;
/* Exed Exes */
extern struct GameDriver driver_exedexes;
extern struct GameDriver driver_savgbees;
/* Ghosts 'n Goblins */
extern struct GameDriver driver_gng;
extern struct GameDriver driver_gnga;
extern struct GameDriver driver_gngt;
extern struct GameDriver driver_makaimur;
extern struct GameDriver driver_makaimuc;
extern struct GameDriver driver_makaimug;
extern struct GameDriver driver_diamond;
/* Gunsmoke */
extern struct GameDriver driver_gunsmoke;
extern struct GameDriver driver_gunsmrom;
extern struct GameDriver driver_gunsmoka;
extern struct GameDriver driver_gunsmokj;
/* Higemaru */
extern struct GameDriver driver_higemaru;
/* Legendary Wings */
extern struct GameDriver driver_lwings;
extern struct GameDriver driver_lwings2;
extern struct GameDriver driver_lwingsjp;
extern struct GameDriver driver_sectionz;
extern struct GameDriver driver_sctionza;
extern struct GameDriver driver_trojan;
extern struct GameDriver driver_trojanr;
extern struct GameDriver driver_trojanj;
extern struct GameDriver driver_avengers;
extern struct GameDriver driver_avenger2;
/* Son Son */
extern struct GameDriver driver_sonson;
/* The Speed Rumbler */
extern struct GameDriver driver_srumbler;
extern struct GameDriver driver_srumblr2;
extern struct GameDriver driver_rushcrsh;
/* Sidearms */
extern struct GameDriver driver_sidearms;
extern struct GameDriver driver_sidearmr;
extern struct GameDriver driver_sidearjp;
extern struct GameDriver driver_turtship;
extern struct GameDriver driver_dyger;
extern struct GameDriver driver_dygera;
/* Vulgus */
extern struct GameDriver driver_vulgus;
extern struct GameDriver driver_vulgus2;
extern struct GameDriver driver_vulgusj;
#if 0
/* Taito Japan */
extern struct GameDriver driver_spaceskr;
extern struct GameDriver driver_junglek;
extern struct GameDriver driver_junglkj2;
extern struct GameDriver driver_jungleh;
extern struct GameDriver driver_alpine;
extern struct GameDriver driver_alpinea;
extern struct GameDriver driver_timetunl;
extern struct GameDriver driver_wwestern;
extern struct GameDriver driver_wwester1;
extern struct GameDriver driver_frontlin;
extern struct GameDriver driver_elevator;
extern struct GameDriver driver_elevatob;
extern struct GameDriver driver_tinstar;
extern struct GameDriver driver_waterski;
extern struct GameDriver driver_bioatack;
extern struct GameDriver driver_sfposeid;
extern struct GameDriver driver_hwrace;
/* psychic5 */
extern struct GameDriver driver_psychic5;
#endif

/* others */
extern struct GameDriver driver_area88;
extern struct GameDriver driver_bionicc;
extern struct GameDriver driver_bionicc2;
extern struct GameDriver driver_blockj;
extern struct GameDriver driver_block;
extern struct GameDriver driver_blockbl;
extern struct GameDriver driver_bbros;
extern struct GameDriver driver_dinoj;
extern struct GameDriver driver_dino;
extern struct GameDriver driver_cbasebal;
extern struct GameDriver driver_capbowl;
extern struct GameDriver driver_capbowl2;
extern struct GameDriver driver_cworld;
extern struct GameDriver driver_cworld2j;
extern struct GameDriver driver_captcomj;
extern struct GameDriver driver_captcomu;
extern struct GameDriver driver_captcomm;
extern struct GameDriver driver_cawing;
extern struct GameDriver driver_chikij;
extern struct GameDriver driver_dokaben;
extern struct GameDriver driver_ffightj;
extern struct GameDriver driver_ffightu;
extern struct GameDriver driver_ffight;
extern struct GameDriver driver_forgottn;
extern struct GameDriver driver_ghoulsu;
extern struct GameDriver driver_ghouls;
extern struct GameDriver driver_kodj;
extern struct GameDriver driver_kod;
extern struct GameDriver driver_kodb;
extern struct GameDriver driver_knightsj;
extern struct GameDriver driver_knights;
extern struct GameDriver driver_lostwrld;
extern struct GameDriver driver_madgearj;
extern struct GameDriver driver_madgear;
extern struct GameDriver driver_mswordj;
extern struct GameDriver driver_mswordu;
extern struct GameDriver driver_msword;
extern struct GameDriver driver_megaman;
extern struct GameDriver driver_mercsu;
extern struct GameDriver driver_mercs;
extern struct GameDriver driver_mbomberj;
extern struct GameDriver driver_mbombrdj;
extern struct GameDriver driver_mbombrd;
extern struct GameDriver driver_nemoj;
extern struct GameDriver driver_nemo;
extern struct GameDriver driver_qadj;
extern struct GameDriver driver_qad;
extern struct GameDriver driver_qsangoku;
extern struct GameDriver driver_qtono1;
extern struct GameDriver driver_qtono2;
extern struct GameDriver driver_rockmanj;
extern struct GameDriver driver_sf1jp;
extern struct GameDriver driver_sf1us;
extern struct GameDriver driver_sf1;
extern struct GameDriver driver_sf2jb;
extern struct GameDriver driver_sf2j;
extern struct GameDriver driver_sf2a;
extern struct GameDriver driver_sf2b;
extern struct GameDriver driver_sf2e;
extern struct GameDriver driver_sf2;
extern struct GameDriver driver_sf2accp2;
extern struct GameDriver driver_sf2cej;
extern struct GameDriver driver_sf2rb;
extern struct GameDriver driver_sf2red;
extern struct GameDriver driver_sf2cea;
extern struct GameDriver driver_sf2ceb;
extern struct GameDriver driver_sf2ce;
extern struct GameDriver driver_sf2t;
extern struct GameDriver driver_sf2tj;
extern struct GameDriver driver_strider;
extern struct GameDriver driver_striderj;
extern struct GameDriver driver_stridrja;
extern struct GameDriver driver_dwj;
extern struct GameDriver driver_wofj;
extern struct GameDriver driver_3wonders;
extern struct GameDriver driver_topsecrt;
extern struct GameDriver driver_unsquad;
extern struct GameDriver driver_cawingj;
extern struct GameDriver driver_varthj;
extern struct GameDriver driver_varthu;
extern struct GameDriver driver_varth;
extern struct GameDriver driver_willow;
extern struct GameDriver driver_willowj;
extern struct GameDriver driver_wonder3;
extern struct GameDriver driver_lastduel;
extern struct GameDriver driver_lstduela;
extern struct GameDriver driver_lstduelb;

extern struct GameDriver driver_1941j;
extern struct GameDriver driver_1941;

const struct GameDriver *drivers[] =
{
	&driver_1942,
	&driver_1942a,
	&driver_1942b,
	&driver_1943,
	&driver_1943j,
	&driver_1943kai,
	&driver_blktiger,
	&driver_bktigerb,
	&driver_blkdrgon,
	&driver_blkdrgnb,
	&driver_commando,
	&driver_commandu,
	&driver_commandj,
	&driver_spaceinv,
	&driver_exedexes,
	&driver_savgbees,
	&driver_gng,
	&driver_gnga,
	&driver_gngt,
	&driver_makaimur,
	&driver_makaimuc,
	&driver_makaimug,
	&driver_diamond,
	&driver_gunsmoke,
	&driver_gunsmrom,
	&driver_gunsmoka,
	&driver_gunsmokj,
	&driver_higemaru,
	&driver_lwings,
	&driver_lwings2,
	&driver_lwingsjp,
	&driver_sectionz,
	&driver_sctionza,
	&driver_trojan,
	&driver_trojanr,
	&driver_trojanj,
	&driver_avengers,
	&driver_avenger2,
	&driver_sonson,
	&driver_srumbler,
	&driver_srumblr2,
	&driver_rushcrsh,
	&driver_sidearms,
	&driver_sidearmr,
	&driver_sidearjp,
	&driver_turtship,
	&driver_dyger,
	&driver_dygera,
	&driver_vulgus,
	&driver_vulgus2,
	&driver_vulgusj,

  &driver_area88,
  &driver_bionicc,
  &driver_bionicc2,
  &driver_blockj,
  &driver_block,
  &driver_blockbl,
  &driver_bbros,
  &driver_dinoj,
  &driver_dino,
  &driver_cbasebal,
  &driver_capbowl,
  &driver_capbowl2,
  &driver_cworld,
  &driver_cworld2j,
  &driver_captcomj,
  &driver_captcomu,
  &driver_captcomm,
  &driver_cawing,
  &driver_chikij,
  &driver_dokaben,
  &driver_ffightj,
  &driver_ffightu,
  &driver_ffight,
  &driver_forgottn,
  &driver_ghoulsu,
  &driver_ghouls,
  &driver_kodj,
  &driver_kod,
  &driver_kodb,
  &driver_knightsj,
  &driver_knights,
  &driver_lostwrld,
  &driver_madgearj,
  &driver_madgear,
  &driver_mswordj,
  &driver_mswordu,
  &driver_msword,
  &driver_megaman,
  &driver_mercsu,
  &driver_mercs,
  &driver_mbomberj,
  &driver_mbombrdj,
  &driver_mbombrd,
  &driver_nemoj,
  &driver_nemo,
  &driver_qadj,
  &driver_qad,
  &driver_qsangoku,
  &driver_qtono1,
  &driver_qtono2,
  &driver_rockmanj,
  &driver_sf1jp,
  &driver_sf1us,
  &driver_sf1,
  &driver_sf2jb,
  &driver_sf2j,
  &driver_sf2a,
  &driver_sf2b,
  &driver_sf2e,
  &driver_sf2,
  &driver_sf2accp2,
  &driver_sf2cej,
  &driver_sf2rb,
  &driver_sf2red,
  &driver_sf2cea,
  &driver_sf2ceb,
  &driver_sf2ce,
  &driver_sf2t,
  &driver_sf2tj,
  &driver_strider,
  &driver_striderj,
  &driver_stridrja,
  &driver_dwj,
  &driver_wofj,
  &driver_3wonders,
  &driver_topsecrt,
  &driver_unsquad,
  &driver_cawingj,
  &driver_varthj,
  &driver_varthu,
  &driver_varth,
  &driver_willow,
  &driver_willowj,
  &driver_wonder3,
  &driver_lastduel,
  &driver_lstduela,
  &driver_lstduelb,

  &driver_1941j,
  &driver_1941,

#if 0
	&driver_chplftb,
	&driver_chplftbl,
	&driver_chplft,
	&driver_seganinj,
	&driver_seganinu,
	&driver_nprinces,
	&driver_nprincsu,
	&driver_nprincsb,

	&driver_starjack,
	&driver_starjacs,
	&driver_regulus,
	&driver_regulusu,
	&driver_upndown,
	&driver_mrviking,
	&driver_mrvikinj,
	&driver_swat,
	&driver_flicky,
	&driver_flicky2,
	&driver_bullfgtj,
	&driver_pitfall2,
	&driver_pitfallu,
	&driver_imsorry,
	&driver_imsorryj,
	&driver_teddybb,
	&driver_hvymetal,
	&driver_myhero,
	&driver_myheroj,
	&driver_myherok,
	&driver_4dwarrio,
	&driver_brain,
	&driver_wboy,
	&driver_wboy2,
	&driver_wboy4,
	&driver_wboyu,
	&driver_wboy4u,
	&driver_wbdeluxe,
	&driver_tokisens,
	&driver_wbml,
	&driver_wbmlju,
	&driver_dakkochn,
	&driver_ufosensi,
#endif

	0	/* end of array */
};
