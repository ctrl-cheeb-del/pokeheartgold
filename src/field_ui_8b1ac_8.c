#include "field_ui_8b1ac_internal.h"

void sub_0208BDC8(u8 *work) {
    u8 i;
    for (i = 0; i < 5; i++) {
        if ((work[0x7BE] & (1 << i)) != 0) {
            Sprite_SetDrawFlag(*(void **)(work + 0x4A8 + i * 4), 1);
        }
    }
}

void sub_0208BE00(u8 *work, void *mon, int spriteIndex) {
    void *charData;
    void *allocation;
    u32 location = NNS_G2dGetImageLocation(Sprite_GetImageProxy(*(void **)(work + 0x404 + spriteIndex * 4)), 2);
    int fileId;
    if ((*(u8 **)(work + 0x22C))[0x11] == 2) {
        fileId = Boxmon_GetIconNaix(mon);
    } else {
        fileId = Pokemon_GetIconNaix(mon);
    }
    allocation = GfGfxLoader_GetCharData(20, fileId, 0, &charData, 19);
    DC_FlushRange(*(void **)((u8 *)charData + 0x14), 0x200);
    GXS_LoadOBJ(*(void **)((u8 *)charData + 0x14), location, 0x200);
    Heap_Free(allocation);
}

void sub_0208BE70(u8 *work) {
    void *mon = (void *)sub_0208A520(work);
    u32 flags;
    int palette;
    sub_0208BE00(work, mon, 19);
    flags = *(u32 *)(work + 0x280);
    palette = GetMonIconPaletteEx(*(u16 *)(work + 0x23C), *(u16 *)(work + 0x27E), (flags << 3) >> 31);
    thunk_Sprite_SetPaletteOverride(*(void **)(work + 0x450), palette + 12);
    Sprite_SetFlipMode(*(void **)(work + 0x450), 1 ^ GetMonBaseStat_HandleAlternateForm(*(u16 *)(work + 0x23C), *(u16 *)(work + 0x27E), 28));
}
