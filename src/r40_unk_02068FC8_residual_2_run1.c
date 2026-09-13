#include "r40_unk_02068FC8_residual_2_private.h"

u8 sub_020691E8(void *fieldSystem) {
    void *saveData = FieldSystem_GetSaveData(fieldSystem);
    void *varsFlags;
    u8 count;
    void *frontier;

    Save_GameStats_Get(saveData);
    varsFlags = Save_VarsFlags_Get(saveData);
    frontier = Save_Frontier_GetStatic(saveData);
    count = 0;

    if (CheckGameClearFlag(varsFlags)) {
        count++;
    }
    if (Pokedex_NationalDexIsComplete(Save_Pokedex_Get(saveData))) {
        count++;
    }
    if (FrontierSave_GetStat(frontier, 0, 0xFF) >= 100
        || FrontierSave_GetStat(frontier, 2, 0xFF) >= 100
        || FrontierSave_GetStat(frontier, 4, 0xFF) >= 100
        || FrontierSave_GetStat(frontier, 6, 0xFF) >= 100
        || FrontierSave_GetStat(frontier, 8, 0xFF) >= 100) {
        count++;
    }
    if (Save_VarsFlags_CheckFlagInArray(varsFlags, 0xF1)) {
        count++;
    }
    if (Save_VarsFlags_CheckFlagInArray(varsFlags, 0x184)) {
        count++;
    }
    return count;
}
