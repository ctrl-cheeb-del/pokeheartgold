#include "global.h"

#include "easy_chat.h"
#include "overlay_02.h"
#include "player_data.h"

int ov02_0224CAB8(WallpaperPasswordBank *bank, u16 trainerId, u16 word1, u16 word2, u16 word3, u16 word4);
int ov02_0224CBF8(WallpaperPasswordBank *bank, u16 trainerId, u16 word1, u16 word2, u16 word3, u16 word4);

int ov02_0224CD38(PlayerProfile *profile, u16 word1, u16 word2, u16 word3, u16 word4, enum HeapID heapID) {
    WallpaperPasswordBank *bank = WallpaperPasswordBank_Create(heapID);
    int result = ov02_0224CAB8(bank, PlayerProfile_GetTrainerID_VisibleHalf(profile), word1, word2, word3, word4);
    WallpaperPasswordBank_Delete(bank);
    return result;
}

int ov02_0224CD74(PlayerProfile *profile, u16 word1, u16 word2, u16 word3, u16 word4, enum HeapID heapID) {
    WallpaperPasswordBank *bank = WallpaperPasswordBank_Create(heapID);
    int result = ov02_0224CBF8(bank, PlayerProfile_GetTrainerID_VisibleHalf(profile), word1, word2, word3, word4);
    WallpaperPasswordBank_Delete(bank);
    return result;
}
