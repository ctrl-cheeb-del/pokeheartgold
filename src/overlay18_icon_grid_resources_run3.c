#include "overlay18_icon_grid_resources_internal.h"

void ov18_021F17FC(void *p) {
    SpriteSystem_LoadCharResObj(PTR(p, 0x668, SpriteSystem), PTR(p, 0x66C, SpriteManager), (NarcId)8, 0x4C, FALSE, 2, 0xC58C);
    SpriteSystem_LoadCharResObj(PTR(p, 0x668, SpriteSystem), PTR(p, 0x66C, SpriteManager), (NarcId)8, 0x4C, FALSE, 2, 0xC58D);
    SpriteSystem_LoadPaletteBuffer(PTR(p, 0x850, PaletteData), (PaletteBufferId)3, PTR(p, 0x668, SpriteSystem), PTR(p, 0x66C, SpriteManager), (NarcId)8, 0x4B, FALSE, 1, 2, 0xC552);
    SpriteSystem_LoadPaletteBuffer(PTR(p, 0x850, PaletteData), (PaletteBufferId)3, PTR(p, 0x668, SpriteSystem), PTR(p, 0x66C, SpriteManager), (NarcId)8, 0x4B, FALSE, 1, 2, 0xC553);
    SpriteSystem_LoadCellResObj(PTR(p, 0x668, SpriteSystem), PTR(p, 0x66C, SpriteManager), (NarcId)8, 0x4D, FALSE, 0xC551);
    SpriteSystem_LoadAnimResObj(PTR(p, 0x668, SpriteSystem), PTR(p, 0x66C, SpriteManager), (NarcId)8, 0x4E, FALSE, 0xC551);
}

void ov18_021F18E0(void *p) {
    SpriteManager_UnloadCharObjById(PTR(p, 0x66C, SpriteManager), 0xC58C);
    SpriteManager_UnloadCharObjById(PTR(p, 0x66C, SpriteManager), 0xC58D);
    SpriteManager_UnloadPlttObjById(PTR(p, 0x66C, SpriteManager), 0xC552);
    SpriteManager_UnloadPlttObjById(PTR(p, 0x66C, SpriteManager), 0xC553);
    SpriteManager_UnloadCellObjById(PTR(p, 0x66C, SpriteManager), 0xC551);
    SpriteManager_UnloadAnimObjById(PTR(p, 0x66C, SpriteManager), 0xC551);
}

void ov18_021F193C(void *p) {
    SpriteSystem_LoadCharResObj(PTR(p, 0x668, SpriteSystem), PTR(p, 0x66C, SpriteManager), (NarcId)8, 0x4C, FALSE, 2, 0xC58E);
    SpriteSystem_LoadCharResObj(PTR(p, 0x668, SpriteSystem), PTR(p, 0x66C, SpriteManager), (NarcId)8, 0x4C, FALSE, 2, 0xC58F);
    SpriteSystem_LoadPaletteBuffer(PTR(p, 0x850, PaletteData), (PaletteBufferId)3, PTR(p, 0x668, SpriteSystem), PTR(p, 0x66C, SpriteManager), (NarcId)8, 0x4B, FALSE, 1, 2, 0xC554);
    SpriteSystem_LoadPaletteBuffer(PTR(p, 0x850, PaletteData), (PaletteBufferId)3, PTR(p, 0x668, SpriteSystem), PTR(p, 0x66C, SpriteManager), (NarcId)8, 0x4B, FALSE, 1, 2, 0xC555);
}

void ov18_021F19EC(void *p) {
    SpriteManager_UnloadCharObjById(PTR(p, 0x66C, SpriteManager), 0xC58E);
    SpriteManager_UnloadCharObjById(PTR(p, 0x66C, SpriteManager), 0xC58F);
    SpriteManager_UnloadPlttObjById(PTR(p, 0x66C, SpriteManager), 0xC554);
    SpriteManager_UnloadPlttObjById(PTR(p, 0x66C, SpriteManager), 0xC555);
}

void ov18_021F1A30(void *p, int idx) {
    SPR(p, idx) = SpriteSystem_NewSpriteWithYOffset(PTR(p, 0x668, SpriteSystem), PTR(p, 0x66C, SpriteManager), &ov18_021FABC0, 0x200000);
    *(ManagedSprite **)((u8 *)p + 0x674 + idx * 4) = SpriteSystem_NewSpriteWithYOffset(PTR(p, 0x668, SpriteSystem), PTR(p, 0x66C, SpriteManager), &ov18_021FABF4, 0x200000);
}
