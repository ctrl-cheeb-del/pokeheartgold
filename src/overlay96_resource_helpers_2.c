#include "overlay96_resource_helpers_private.h"

struct R21SpriteTemplate {
    void *spriteList;
    void *resource;
    u32 zero08;
    u32 zero0c;
    u32 zero10;
    s32 scaleX;
    s32 scaleY;
    s32 scaleZ;
    u16 rotation;
    u16 pad22;
    u32 affine;
    u32 priority;
    void *heap;
};

void ov96_021F8BC0(u8 *obj, s32 index, u8 *pair) {
    void *profile = PokeathlonCourse_GetPlayerProfileFromData(PTR(obj, 4), index);
    void *name = PlayerProfile_GetPlayerName_NewString(profile, *(u32 *)obj);
    ov96_021F8DF4(obj, obj + 0x2fc, name, 0, -56, -16, PTR(pair, 0), pair + 0x10);
    String_Delete(name);
}

void ov96_021F8C04(u8 *obj, void *window, u8 *pair) {
    ov96_021F8DF4(obj, obj + 0x314, window, 0, -56, 0, PTR(pair, 0), pair + 0x20);
}

void ov96_021F8C2C(u8 *obj) {
    ov96_021F8C88(*(s32 *)(obj+0x38), *(s32 *)(obj+0x3c), obj);
    Sprite_SetPaletteOverride(PTR(obj, 0), *(s32 *)(obj+0x40) + 2);
    Sprite_SetAnimCtrlSeq(PTR(obj, 4), *(u16 *)(obj+0x44) + 5);
}

void ov96_021F8C54(BOOL third, BOOL draw, u8 *obj) {
    Sprite_SetDrawFlag(PTR(obj,0), draw);
    Sprite_SetDrawFlag(PTR(obj,4), draw);
    if (third) Sprite_SetDrawFlag(PTR(obj,8), draw);
    TextOBJ_SetSpritesDrawFlag(PTR(obj,0x10), draw);
    TextOBJ_SetSpritesDrawFlag(PTR(obj,0x20), draw);
}
