#include "overlay49_scene_setup_r26_private.h"

void ov49_0225B450(void *state, void *display, void *arg, void *profile, u32 heapId) {
    u32 gender = PlayerProfile_GetTrainerGender(profile);

    PTR_AT(state, 0x14C) = NARC_New(0xD1, heapId);
    ov49_0225BABC(state, arg, PTR_AT(state, 0x14C), gender, heapId);
    ov49_0225BB84((u8 *)state + 8, arg, PTR_AT(state, 0x14C), heapId);
    ov49_0225C844((u8 *)state + 0x114, arg, PTR_AT(state, 0x14C), heapId);
    U8_AT(state, 2) = 0;
    U8_AT(state, 1) = 0;
    if (U16_AT(display, 6) == 0) {
        U8_AT(state, 0) = 0;
        BG_SetMaskColor(4);
        GfGfx_EngineBTogglePlanes(1, FALSE);
        GfGfx_EngineBTogglePlanes(2, FALSE);
        GfGfx_EngineBTogglePlanes(4, FALSE);
        GfGfx_EngineBTogglePlanes(8, FALSE);
    } else {
        U8_AT(state, 0) = 5;
    }
}

void ov49_0225B4E4(void *state, void *arg1, void *arg2) {
    ov49_0225C8A8((u8 *)state + 0x114);
    ov49_0225BBA8((u8 *)state + 8, arg1, arg2);
    ov49_0225BB10(state, arg2);
    NARC_Delete(PTR_AT(state, 0x14C));
}
