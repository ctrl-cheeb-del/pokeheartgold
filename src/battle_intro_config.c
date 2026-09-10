#include "constants/sndseq.h"
#include "constants/species.h"
#include "constants/trainer_class.h"

#include "battle_intro_config_internal.h"

const PackedBattleParam _020FC3B4[11] = {
    { SPECIES_RAIKOU,   22 },
    { SPECIES_ENTEI,    23 },
    { SPECIES_SUICUNE,  24 },
    { SPECIES_LUGIA,    26 },
    { SPECIES_HO_OH,    25 },
    { SPECIES_GROUDON,  27 },
    { SPECIES_KYOGRE,   27 },
    { SPECIES_RAYQUAZA, 27 },
    { SPECIES_MEWTWO,   28 },
    { SPECIES_LATIOS,   28 },
    { SPECIES_LATIAS,   28 },
};

const PackedBattleParam _020FC3CA[32] = {
    { TRAINERCLASS_LEADER_FALKNER,   0  },
    { TRAINERCLASS_LEADER_BUGSY,     1  },
    { TRAINERCLASS_LEADER_WHITNEY,   2  },
    { TRAINERCLASS_LEADER_MORTY,     3  },
    { TRAINERCLASS_LEADER_JASMINE,   4  },
    { TRAINERCLASS_LEADER_CHUCK,     5  },
    { TRAINERCLASS_LEADER_PRYCE,     6  },
    { TRAINERCLASS_LEADER_CLAIR,     7  },
    { TRAINERCLASS_LEADER_BROCK,     8  },
    { TRAINERCLASS_LEADER_MISTY,     9  },
    { TRAINERCLASS_LEADER_LT_SURGE,  10 },
    { TRAINERCLASS_LEADER_ERIKA,     11 },
    { TRAINERCLASS_LEADER_JANINE,    12 },
    { TRAINERCLASS_LEADER_SABRINA,   13 },
    { TRAINERCLASS_LEADER_BLAINE,    14 },
    { TRAINERCLASS_LEADER_BLUE,      15 },
    { TRAINERCLASS_ELITE_FOUR_WILL,  16 },
    { TRAINERCLASS_ELITE_FOUR_KOGA,  17 },
    { TRAINERCLASS_ELITE_FOUR_BRUNO, 18 },
    { TRAINERCLASS_ELITE_FOUR_KAREN, 19 },
    { TRAINERCLASS_CHAMPION,         20 },
    { TRAINERCLASS_RIVAL,            21 },
    { TRAINERCLASS_PASSERBY,         21 },
    { TRAINERCLASS_EXECUTIVE_ARCHER, 32 },
    { TRAINERCLASS_EXECUTIVE_ARIANA, 33 },
    { TRAINERCLASS_EXECUTIVE_PROTON, 31 },
    { TRAINERCLASS_EXECUTIVE_PETREL, 30 },
    { TRAINERCLASS_ROCKET_BOSS,      34 },
    { TRAINERCLASS_TEAM_ROCKET,      29 },
    { TRAINERCLASS_TEAM_ROCKET_F,    29 },
    { TRAINERCLASS_KIMONO_GIRL,      43 },
    { TRAINERCLASS_PKMN_TRAINER_RED, 44 },
};

const BattleIntroMusic _020FC40A[45] = {
    { 12,     SEQ_GS_VS_GYMREADER       },
    { 13,     SEQ_GS_VS_GYMREADER       },
    { 14,     SEQ_GS_VS_GYMREADER       },
    { 15,     SEQ_GS_VS_GYMREADER       },
    { 16,     SEQ_GS_VS_GYMREADER       },
    { 17,     SEQ_GS_VS_GYMREADER       },
    { 18,     SEQ_GS_VS_GYMREADER       },
    { 19,     SEQ_GS_VS_GYMREADER       },
    { 20,     SEQ_GS_VS_GYMREADER_KANTO },
    { 21,     SEQ_GS_VS_GYMREADER_KANTO },
    { 22,     SEQ_GS_VS_GYMREADER_KANTO },
    { 23,     SEQ_GS_VS_GYMREADER_KANTO },
    { 24,     SEQ_GS_VS_GYMREADER_KANTO },
    { 25,     SEQ_GS_VS_GYMREADER_KANTO },
    { 26,     SEQ_GS_VS_GYMREADER_KANTO },
    { 27,     SEQ_GS_VS_GYMREADER_KANTO },
    { 29,     SEQ_GS_VS_GYMREADER       },
    { 30,     SEQ_GS_VS_GYMREADER       },
    { 31,     SEQ_GS_VS_GYMREADER       },
    { 32,     SEQ_GS_VS_GYMREADER       },
    { 33,     SEQ_GS_VS_CHAMP           },
    { 28,     SEQ_GS_VS_RIVAL           },
    { 0xffff, SEQ_GS_VS_RAIKOU          },
    { 0xffff, SEQ_GS_VS_ENTEI           },
    { 0xffff, SEQ_GS_VS_SUICUNE         },
    { 35,     SEQ_GS_VS_HOUOU           },
    { 36,     SEQ_GS_VS_LUGIA           },
    { 34,     SEQ_GS_VS_KODAI           },
    { 34,     SEQ_GS_VS_NORAPOKE_KANTO  },
    { 39,     SEQ_GS_VS_ROCKET          },
    { 40,     SEQ_GS_VS_ROCKET          },
    { 41,     SEQ_GS_VS_ROCKET          },
    { 42,     SEQ_GS_VS_ROCKET          },
    { 43,     SEQ_GS_VS_ROCKET          },
    { 44,     SEQ_GS_VS_ROCKET          },
    { 37,     SEQ_GS_VS_TRAINER         },
    { 37,     SEQ_GS_VS_TRAINER         },
    { 38,     SEQ_GS_VS_TRAINER         },
    { 38,     SEQ_GS_VS_NORAPOKE        },
    { 37,     SEQ_GS_BA_BRAIN           },
    { 38,     SEQ_GS_VS_GYMREADER       },
    { 0xffff, SEQ_GS_VS_TRAINER         },
    { 0xffff, SEQ_GS_VS_NORAPOKE        },
    { 45,     SEQ_GS_VS_TRAINER         },
    { 46,     SEQ_GS_VS_CHAMP           },
};

u32 BattleSetup_GetTransitionAndMusicParam(BattleSetupLite *setup) {
    u32 battleType = setup->battleType;
    u32 param;
    if (battleType & 1) {
        param = NPCTrainerGetBattleIntroAndMusicParam(setup->trainerClass);
        if (battleType & 0x80) {
            if (param == 39) {
                return param;
            }
            return (battleType & 2) ? 37 : 35;
        }
        if (param >= 29 && param <= 34) {
            return param;
        }
        if (param == 43) {
            return param;
        }
        if (param == 44) {
            return param;
        }
        if (battleType & 2) {
            return 37;
        }
        if (battleType & 4) {
            return 36;
        }
    } else {
        param = WildPokemonGetBattleIntroAndMusicParam(setup->enemyParty, setup->mapId);
        if (param >= 42 && (battleType & 2)) {
            return 38;
        }
    }
    return param;
}

u32 BattleStartGetTransition(u32 param, BattleSetupLite *setup) {
    u32 result;
    if (param >= 45) {
        GF_AssertFail();
    }
    result = _020FC40A[param].transition;
    if (result == 0xffff) {
        result = ov01_021F0D20(setup);
    }
    return result;
}

u32 BattleStartGetMusic(u32 param, BattleSetupLite *setup) {
    if (param >= 45) {
        GF_AssertFail();
    }
    return _020FC40A[param].music;
}

u32 BattleSetup_GetWildTransitionEffect(BattleSetupLite *setup) {
    return BattleStartGetTransition(BattleSetup_GetTransitionAndMusicParam(setup), setup);
}

BOOL sub_020517F8(u32 param) {
    return TRUE;
}

u32 BattleSetup_GetWildBattleMusic(BattleSetupLite *setup) {
    u32 param = BattleSetup_GetTransitionAndMusicParam(setup);
    u32 music = BattleStartGetMusic(param, setup);
    void *varsFlags = Save_VarsFlags_Get(setup->saveData);
    if (Save_VarsFlags_FlypointFlagAction(varsFlags, 2, 5) == TRUE && MapHeader_GetRegionNo(setup->mapId) != 0) {
        if (music == 0x45c) {
            music = 0x465;
        } else if (music == 0x45d) {
            music = 0x466;
        } else if (music == 0x45e && !sub_020517F8(param)) {
            music = 0x467;
        }
    }
    return music;
}

u32 NPCTrainerGetBattleIntroAndMusicParam(u32 trainerClass) {
    u32 i;
    for (i = 0; i < 32; i++) {
        if (_020FC3CA[i].key == trainerClass) {
            return _020FC3CA[i].param;
        }
    }
    return 41;
}

u32 WildPokemonGetBattleIntroAndMusicParam(void *party, u32 mapId) {
    u32 i;
    u32 species = GetMonData(GetFirstAliveMonInParty_CrashIfNone(party), 5, NULL);
    if (mapId == 109) {
        return 42;
    }
    for (i = 0; i < 11; i++) {
        if (_020FC3B4[i].key == species) {
            return _020FC3B4[i].param;
        }
    }
    return 42;
}
