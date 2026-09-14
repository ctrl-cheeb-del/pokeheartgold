#include "to47_overlay49_palette_tasks_private.h"

// Address order: 0x0225BA40, 0x0225BA5C, 0x0225BABC.

SysTask *ov49_0225BA40(void *data, u32 unused, u16 memberNo, u16 heapId) {
    U16_AT(data, 0x154) = memberNo;
    U16_AT(data, 0x156) = heapId;
    return SysTask_CreateOnVWaitQueue(ov49_0225BA5C, data, 0);
}

void ov49_0225BA5C(SysTask *task, void *data) {
    NarcId narcId;
    int memberNo;

    GfGfxLoader_GXLoadPalFromOpenNarc(PTR_AT(data, 0x14c), U16_AT(data, 0x154), GF_PAL_LOCATION_SUB_BG, GF_PAL_SLOT_0_OFFSET, 0, (enum HeapID)U16_AT(data, 0x156));
    LoadFontPal0(GF_PAL_LOCATION_SUB_BG, GF_PAL_SLOT_5_OFFSET, (enum HeapID)U16_AT(data, 0x156));
    narcId = sub_020776B4();
    memberNo = sub_02077690();
    GfGfxLoader_GXLoadPal(narcId, memberNo, GF_PAL_LOCATION_SUB_BG, GF_PAL_SLOT_11_OFFSET, 0x60, (enum HeapID)U16_AT(data, 0x156));
    SysTask_Destroy(task);
}

void ov49_0225BABC(void *unused, void *obj, NARC *narc, u32 which, enum HeapID heapId) {
    if (which == 0) {
        GfGfxLoader_GXLoadPalFromOpenNarc(narc, 0x56, GF_PAL_LOCATION_SUB_BG, GF_PAL_SLOT_0_OFFSET, 0, heapId);
    } else {
        GfGfxLoader_GXLoadPalFromOpenNarc(narc, 0x57, GF_PAL_LOCATION_SUB_BG, GF_PAL_SLOT_0_OFFSET, 0, heapId);
    }
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 0x36, PTR_AT(obj, 0), GF_BG_LYR_SUB_0, 0, 0, FALSE, heapId);
    LoadFontPal0(GF_PAL_LOCATION_SUB_BG, GF_PAL_SLOT_5_OFFSET, heapId);
}
