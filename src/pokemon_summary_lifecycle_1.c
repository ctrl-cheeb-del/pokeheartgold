#include "pokemon_summary_lifecycle_internal.h"

BOOL PokemonSummary_Init(void *manager, u32 *state) {
    void *narc27;
    void *narcA2;
    u8 *data;
    (void)state;
    Main_SetVBlankIntrCB(NULL, NULL);
    HBlankInterruptDisable();
    GfGfx_DisableEngineAPlanes();
    GfGfx_DisableEngineBPlanes();
    *(volatile u32 *)0x04000000 &= 0xffffe0ff;
    *(volatile u32 *)0x04001000 &= 0xffffe0ff;
    *(volatile u32 *)0x04000000 &= 0xffff1fff;
    *(volatile u32 *)0x04001000 &= 0xffff1fff;
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    SetKeyRepeatTimers(4, 8);
    Heap_Create(3, 0x13, 0x45000);
    narc27 = NARC_New(0x27, 0x13);
    narcA2 = NARC_New(0xa2, 0x13);
    data = OverlayManager_CreateAndGetData(manager, 0x7d8, 0x13);
    memset(data, 0, 0x7d8);
    *(void **)(data + 0x22c) = OverlayManager_GetArgs(manager);
    *(void **)data = BgConfig_Alloc(0x13);
    *(u32 *)((u8 *)*(void **)(data + 0x22c) + 0x38) = 0;
    *(void **)(data + 0x2cc) = sub_02016EDC(0x13, 1, 1);
    *(void **)(data + 0x7b8) = NARC_New(0xb4, 0x13);
    FontID_SetAccessDirect(0, 0x13);
    sub_020210BC();
    sub_02021148(4);
    sub_02088610();
    sub_02088630(*(void **)data);
    sub_020887C4(data, narc27, narcA2);
    sub_0208887C();
    sub_0208DE40(data);
    FontID_Alloc(4, 0x13);
    sub_02088894(data);
    sub_020889D0(data, narcA2);
    sub_020897C0(data);
    sub_0208B1AC(data);
    sub_0208B2C0(data);
    sub_0208E3AC(data);
    sub_0208B48C(data);
    sub_0208B4EC(data);
    sub_0208BECC(data);
    sub_0208C3E4(data);
    sub_02089CB4(data);
    sub_0208DF2C(data);
    Main_SetVBlankIntrCB(sub_020885DC, data);
    *(volatile u16 *)0x04000304 |= 0x8000;
    GfGfx_BothDispOn();
    Sound_SetSceneAndPlayBGM(0x3d, 0, 0);
    sub_0203A964();
    NARC_Delete(narcA2);
    NARC_Delete(narc27);
    return TRUE;
}

BOOL PokemonSummary_Main(void *manager, u32 *state) {
    u8 *data = OverlayManager_GetData(manager);
    switch (*state) {
    case 0:
        sub_020880CC(0, 0x13);
        Pokepic_SetAttr(*(void **)(data + 0x2d0), 6, 0);
        *state = 1;
        break;
    case 1:
        *state = sub_02088B08(data);
        break;
    case 2:
        *state = sub_02088B40(data);
        break;
    case 3:
        *state = sub_02088D18(data);
        break;
    case 4:
        *state = sub_02088D34(data);
        break;
    case 5:
        *state = sub_02088D48(data);
        break;
    case 7:
        *state = sub_02088E68(data);
        break;
    case 6:
        *state = sub_02088E98(data);
        break;
    case 8:
        *state = sub_02089028(data);
        break;
    case 9:
        *state = sub_02089208(data);
        break;
    case 10:
        *state = sub_020892F4(data);
        break;
    case 11:
        *state = sub_02089308(data);
        break;
    case 12:
        *state = sub_0208931C(data);
        break;
    case 13:
        *state = sub_0208942C(data);
        break;
    case 14:
        *state = sub_02089454(data);
        break;
    case 15:
        *state = sub_02089698(data);
        break;
    case 16:
        *state = sub_02089478(data);
        break;
    case 17:
        *state = sub_02089608(data);
        break;
    case 18:
        *state = sub_02089658(data);
        break;
    case 21:
        *state = sub_02089670(data);
        break;
    case 22:
        if (sub_02089680(data) == 1) {
            return TRUE;
        }
        break;
    case 19:
        Pokepic_SetAttr(*(void **)(data + 0x2d0), 6, 0);
        *state = 2;
        break;
    case 20:
        *state = sub_02089794(data);
        break;
    }
    sub_0208B278(data);
    sub_0208C3C0(data);
    SpriteSystem_DrawSprites(*(void **)(data + 0x400));
    sub_0208DEDC(data);
    return FALSE;
}

BOOL PokemonSummary_Exit(void *manager, u32 *state) {
    u8 *data = OverlayManager_GetData(manager);
    (void)state;
    Main_SetVBlankIntrCB(NULL, NULL);
    sub_0208DEFC(data);
    sub_0208B258(data);
    sub_0208C560(data);
    sub_0208877C(*(void **)data);
    sub_02021238();
    GF_DestroyVramTransferManager();
    sub_02088AF8(data);
    sub_0208895C(data);
    FontID_Release(4);
    NARC_Delete(*(void **)(data + 0x7b8));
    FontID_SetAccessLazy(0);
    *(volatile u16 *)0x04000050 = 0;
    OverlayManager_FreeData(manager);
    Heap_Destroy(0x13);
    return TRUE;
}
