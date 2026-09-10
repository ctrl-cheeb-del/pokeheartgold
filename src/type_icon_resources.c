#include "global.h"

#include "unk_02077678.h"
extern const int _02100048[23];
extern const u8 _021000A4[23];
extern const int _0210003C[3];
extern const u8 _02100038[3];
int sub_02077678(int type);
int sub_02077690(void);
int sub_02077694(void);
int sub_02077698(void);
u32 sub_0207769C(u32 type);
NarcId sub_020776B4(void);
void sub_020776B8(SpriteSystem *system, SpriteManager *manager, NNS_G2D_VRAM_TYPE vram, int type, int resource);
void sub_020776EC(SpriteSystem *system, SpriteManager *manager, int vram, int resource);
void sub_02077720(PaletteData *palette, int buffer, SpriteSystem *system, SpriteManager *manager, int vram, int resource);
void sub_0207775C(SpriteSystem *system, SpriteManager *manager, int cell, int animation);
void sub_020777A4(SpriteManager *manager, int resource);
void sub_020777AC(SpriteManager *manager, int resource);
void sub_020777B4(SpriteManager *manager, int cell, int animation);
ManagedSprite *sub_020777C8(SpriteSystem *system, SpriteManager *manager, int type, ManagedSpriteTemplate *template);
void thunk_ManagedSprite_DeleteAndFreeResources(ManagedSprite *sprite);
int sub_02077800(u32 category);
u32 sub_02077818(u32 category);
NarcId sub_02077830(void);
void sub_02077834(SpriteSystem *system, SpriteManager *manager, int vram, int category, int resource);
void sub_02077868(SpriteManager *manager, int resource);
void sub_02077870(ManagedSprite *sprite);
int sub_02077678(int type) {
    GF_ASSERT((u32)type < 23);
    return _02100048[type];
}
int sub_02077690(void) {
    return 74;
}
int sub_02077694(void) {
    return 242;
}
int sub_02077698(void) {
    return 243;
}
u32 sub_0207769C(u32 type) {
    GF_ASSERT(type < 23);
    return _021000A4[type];
}
NarcId sub_020776B4(void) {
    return (NarcId)8;
}
void sub_020776B8(SpriteSystem *system, SpriteManager *manager, NNS_G2D_VRAM_TYPE vram, int type, int resource) {
    NarcId narc = sub_020776B4();
    int file = sub_02077678(type);
    SpriteSystem_LoadCharResObj(system, manager, narc, file, TRUE, vram, resource);
}
void sub_020776EC(SpriteSystem *system, SpriteManager *manager, int vram, int resource) {
    NarcId narc = sub_020776B4();
    int file = sub_02077690();
    SpriteSystem_LoadPlttResObj(system, manager, narc, file, FALSE, 3, vram, resource);
}
void sub_02077720(PaletteData *palette, int buffer, SpriteSystem *system, SpriteManager *manager, int vram, int resource) {
    NarcId narc = sub_020776B4();
    int file = sub_02077690();
    SpriteSystem_LoadPaletteBuffer(palette, (PaletteBufferId)buffer, system, manager, narc, file, FALSE, 3, vram, resource);
}
void sub_0207775C(SpriteSystem *system, SpriteManager *manager, int cell, int animation) {
    NarcId narc = sub_020776B4();
    int file = sub_02077694();
    SpriteSystem_LoadCellResObj(system, manager, narc, file, TRUE, cell);
    narc = sub_020776B4();
    file = sub_02077698();
    SpriteSystem_LoadAnimResObj(system, manager, narc, file, TRUE, animation);
}
void sub_020777A4(SpriteManager *manager, int resource) {
    SpriteManager_UnloadCharObjById(manager, resource);
}
void sub_020777AC(SpriteManager *manager, int resource) {
    SpriteManager_UnloadPlttObjById(manager, resource);
}
void sub_020777B4(SpriteManager *manager, int cell, int animation) {
    SpriteManager_UnloadCellObjById(manager, cell);
    SpriteManager_UnloadAnimObjById(manager, animation);
}
ManagedSprite *sub_020777C8(SpriteSystem *system, SpriteManager *manager, int type, ManagedSpriteTemplate *template) {
    ManagedSpriteTemplate copy = *template;
    copy.pal = sub_0207769C(type);
    return SpriteSystem_NewSprite(system, manager, &copy);
}
void thunk_ManagedSprite_DeleteAndFreeResources(ManagedSprite *sprite) {
    Sprite_DeleteAndFreeResources(sprite);
}
int sub_02077800(u32 category) {
    GF_ASSERT(category < 3);
    return _0210003C[category];
}
u32 sub_02077818(u32 category) {
    GF_ASSERT(category < 3);
    return _02100038[category];
}
NarcId sub_02077830(void) {
    return (NarcId)8;
}
void sub_02077834(SpriteSystem *system, SpriteManager *manager, int vram, int category, int resource) {
    NarcId narc = sub_02077830();
    int file = sub_02077800(category);
    SpriteSystem_LoadCharResObj(system, manager, narc, file, TRUE, vram, resource);
}
void sub_02077868(SpriteManager *manager, int resource) {
    SpriteManager_UnloadCharObjById(manager, resource);
}
void sub_02077870(ManagedSprite *sprite) {
    Sprite_DeleteAndFreeResources(sprite);
}
