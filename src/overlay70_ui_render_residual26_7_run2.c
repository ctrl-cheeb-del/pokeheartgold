#include "overlay70_ui_render_residual26_7_private.h"

void ov70_0223F6E4(void *dstv, void *srcv) {
    u8 *dst = dstv;
    u8 *src = srcv;
    if (ov70_0223E490(*(u16 *)(src + 0x120))) {
        Mon_UpdateShayminForm(*(void **)(src + 0x124), 0);
        MIi_CpuCopyFast(*(const u32 **)(src + 0x124), (u32 *)dst, SizeOfStructPokemon());
    } else {
        BoxMon_UpdateShayminForm(*(void **)(src + 0x124), 0);
        CopyBoxPokemonToPokemon(*(void **)(src + 0x124), dst);
    }
    CopyU16StringArrayN((u16 *)(dst + 0x10C), PlayerProfile_GetNamePtr(*(PlayerProfile **)(*(u8 **)src + 0x1C)), 8);
    *(u16 *)(dst + 0x11C) = PlayerProfile_GetTrainerID_VisibleHalf(*(PlayerProfile **)(*(u8 **)src + 0x1C));
    *(u8 *)(dst + 0x11E) = WifiHistory_GetPlayerCountry(*(void **)(*(u8 **)src + 0x18));
    *(u8 *)(dst + 0x11F) = WiFiHistory_GetPlayerRegion(*(void **)(*(u8 **)src + 0x18));
    *(u8 *)(dst + 0x120) = PlayerProfile_GetAvatar(*(PlayerProfile **)(*(u8 **)src + 0x1C));
    *(u8 *)(dst + 0xF6) = PlayerProfile_GetTrainerGender(*(PlayerProfile **)(*(u8 **)src + 0x1C));
    *(u8 *)(dst + 0x122) = GAME_VERSION;
    *(u8 *)(dst + 0x123) = 2;
}
