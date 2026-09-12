#include "overlay18_pokedex_area_ui_private.h"

void ov18_021F1D58(void *p);
void ov18_021F1D98(void *p, int idx);
void ov18_021F1DE4(void *p, int species, int idx, int spriteIdx);
void ov18_021F1F74(void *p);
void ov18_021F1FDC(void *p, int idx);
void ov18_021F2308(void *p);
void ov18_021F2348(void *p);
void ov18_021F23E4(void *p);
void ov18_021F2424(void *p, int idx, const ManagedSpriteTemplate *tmpl);
void ov18_021F2468(void *p);
void ov18_021F24E0(void *p, int a1, int idx);
void ov18_021F2530(void *p, int a1, int a2);
void ov18_021F2270(void *p);
void ov18_021F1CB4(void *p);
void ov18_021F1E70(void *p);
void ov18_021F209C(void *p, int a1, int a2, int a3);
void ov18_021F2648(void *p);
void ov18_021F26E4(void *p);
void ov18_021F2724(void *p);
void ov18_021F281C(void *p);
void ov18_021F2880(void *p);
void ov18_021F2964(void *p);
void ov18_021F299C(void *p);
void ov18_021F2A2C(void *p, int idx, int draw);
void ov18_021F2A84(void *p, int idx, int draw);
void ov18_021F2AC0(void *p, int idx);
BOOL ov18_021F2AF8(void *p, u32 x, u32 y);
void ov18_021F2B3C(void *p, int idx, s16 dx);
void ov18_021F2B70(void *p, int idx, s16 x);

void ov18_021F2648(void *p) {
    SpriteSystem_LoadCharResObjFromOpenNarc(*(SpriteSystem **)((u8 *)p + 0x668), *(SpriteManager **)((u8 *)p + 0x66C), *(NARC **)((u8 *)p + 0x854), 12, 1, 1, 0xC590);
    SpriteSystem_LoadPaletteBufferFromOpenNarc(*(PaletteData **)((u8 *)p + 0x850), (PaletteBufferId)2, *(SpriteSystem **)((u8 *)p + 0x668), *(SpriteManager **)((u8 *)p + 0x66C), *(NARC **)((u8 *)p + 0x854), 15, 0, 5, 1, 0xC556);
    SpriteSystem_LoadCellResObjFromOpenNarc(*(SpriteSystem **)((u8 *)p + 0x668), *(SpriteManager **)((u8 *)p + 0x66C), *(NARC **)((u8 *)p + 0x854), 13, 1, 0xC552);
    SpriteSystem_LoadAnimResObjFromOpenNarc(*(SpriteSystem **)((u8 *)p + 0x668), *(SpriteManager **)((u8 *)p + 0x66C), *(NARC **)((u8 *)p + 0x854), 14, 1, 0xC552);
}

void ov18_021F26E4(void *p) {
    SpriteManager_UnloadCharObjById(*(SpriteManager **)((u8 *)p + 0x66C), 0xC590);
    SpriteManager_UnloadPlttObjById(*(SpriteManager **)((u8 *)p + 0x66C), 0xC556);
    SpriteManager_UnloadCellObjById(*(SpriteManager **)((u8 *)p + 0x66C), 0xC552);
    SpriteManager_UnloadAnimObjById(*(SpriteManager **)((u8 *)p + 0x66C), 0xC552);
}

void ov18_021F2724(void *p) {
    SpriteSystem_LoadCharResObjFromOpenNarc(*(SpriteSystem **)((u8 *)p + 0x668), *(SpriteManager **)((u8 *)p + 0x66C), *(NARC **)((u8 *)p + 0x854), 26, 1, 2, 0xC591);
    SpriteSystem_LoadPaletteBufferFromOpenNarc(*(PaletteData **)((u8 *)p + 0x850), (PaletteBufferId)3, *(SpriteSystem **)((u8 *)p + 0x668), *(SpriteManager **)((u8 *)p + 0x66C), *(NARC **)((u8 *)p + 0x854), 32, 0, 1, 2, 0xC557);
    SpriteSystem_LoadCellResObjFromOpenNarc(*(SpriteSystem **)((u8 *)p + 0x668), *(SpriteManager **)((u8 *)p + 0x66C), *(NARC **)((u8 *)p + 0x854), 27, 1, 0xC553);
    SpriteSystem_LoadAnimResObjFromOpenNarc(*(SpriteSystem **)((u8 *)p + 0x668), *(SpriteManager **)((u8 *)p + 0x66C), *(NARC **)((u8 *)p + 0x854), 28, 1, 0xC553);
    SpriteSystem_LoadCharResObjFromOpenNarc(*(SpriteSystem **)((u8 *)p + 0x668), *(SpriteManager **)((u8 *)p + 0x66C), *(NARC **)((u8 *)p + 0x854), 29, 1, 2, 0xC592);
    SpriteSystem_LoadCellResObjFromOpenNarc(*(SpriteSystem **)((u8 *)p + 0x668), *(SpriteManager **)((u8 *)p + 0x66C), *(NARC **)((u8 *)p + 0x854), 30, 1, 0xC554);
    SpriteSystem_LoadAnimResObjFromOpenNarc(*(SpriteSystem **)((u8 *)p + 0x668), *(SpriteManager **)((u8 *)p + 0x66C), *(NARC **)((u8 *)p + 0x854), 31, 1, 0xC554);
}

void ov18_021F281C(void *p) {
    SpriteManager_UnloadCharObjById(*(SpriteManager **)((u8 *)p + 0x66C), 0xC591);
    SpriteManager_UnloadPlttObjById(*(SpriteManager **)((u8 *)p + 0x66C), 0xC557);
    SpriteManager_UnloadCellObjById(*(SpriteManager **)((u8 *)p + 0x66C), 0xC553);
    SpriteManager_UnloadAnimObjById(*(SpriteManager **)((u8 *)p + 0x66C), 0xC553);
    SpriteManager_UnloadCharObjById(*(SpriteManager **)((u8 *)p + 0x66C), 0xC592);
    SpriteManager_UnloadCellObjById(*(SpriteManager **)((u8 *)p + 0x66C), 0xC554);
    SpriteManager_UnloadAnimObjById(*(SpriteManager **)((u8 *)p + 0x66C), 0xC554);
}

void ov18_021F2880(void *p) {
    int a;
    int b;
    ov18_021F2964(p);
    ov18_021F1424(p, 24);
    ov18_021F1620(p, 24);
    ov18_021F299C(p);
    if (*(int *)((u8 *)p + 0x1860) == 0) {
        ManagedSprite_SetDrawFlag(*(ManagedSprite **)((u8 *)p + 0x670), FALSE);
    } else {
        ov18_021F2AC0(p, 0);
    }
    ov18_021F2BB0(p, 5);
    ov18_021F2C10(p, 2, 1);
    ov18_021F2C5C(p, 1, 1);
    ov18_021F2E80(p, 1, 1);
    a = ov18_021F8838(p);
    b = ov18_021F8824(p);
    ov18_021F1A30(p, 11);
    ov18_021F1CAC(p, a, 11, 10);
    ov18_021F1FDC(p, 14);
    ov18_021F209C(p, a, b, 14);
    ov18_021F1D98(p, 13);
    ov18_021F1DE4(p, a, b, 13);
    ov18_021F2EC8(p, b, 9);
    ov18_021F2468(p);
    ov18_021F2530(p, a, 18);
    ov18_021F24E0(p, a, 8);
    ManagedSprite_SetDrawFlag(*(ManagedSprite **)((u8 *)p + 0x690), FALSE);
}

void ov18_021F2964(void *p) {
    ov18_021F1324(p, 60);
    ov18_021F2648(p);
    ov18_021F2270(p);
    ov18_021F17FC(p);
    ov18_021F1CB4(p);
    ov18_021F1E70(p);
    ov18_021F2724(p);
    ov18_021F2348(p);
}
