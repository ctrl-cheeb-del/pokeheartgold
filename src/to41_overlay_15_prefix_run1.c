#include "to41_overlay_15_prefix_private.h"

#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))

void BagApp_GetSaveStructPtrs(void *work) {
    void *save = PTR(PTR(work, 0x234), 0);
    PTR(work, 0x238) = Save_Bag_Get(save);
    save = PTR(PTR(work, 0x234), 0);
    PTR(work, 0x23c) = Save_PlayerData_GetProfile(save);
    save = PTR(PTR(work, 0x234), 0);
    PTR(work, 0x240) = Save_PlayerData_GetOptionsAddr(save);
}

void *BagApp_GetSaveRoamers(void *work) {
    return Save_Roamers_Get(PTR(PTR(work, 0x234), 0));
}

void BagApp_GetRepelStepCountAddr(void *work, u8 value) {
    *RoamerSave_GetRepelAddr(BagApp_GetSaveRoamers(work)) = value;
}

void BagApp_SetFlute(void *work, u8 value) {
    RoamerSave_SetFlute(BagApp_GetSaveRoamers(work), value);
}
