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

void ov96_021F91CC(u8 *obj) {
    if (PTR(obj,0) != 0) {
        TextOBJ_Destroy(PTR(obj,0));
        sub_02021B5C(obj+4);
        PTR(obj,0)=0;
    }
}

void ov96_021F91E8(u8 *obj, s32 value) {
    s32 hundreds=value/100;
    s32 remainder=value-hundreds*100;
    s32 tens=remainder/10;
    void *sprite=ov96_021EB5B8(PTR(obj,4));
    Sprite_SetAnimCtrlSeq(sprite,hundreds+1);
    sprite=ov96_021EB5B8(PTR(obj,8));
    Sprite_SetAnimCtrlSeq(sprite,tens+1);
    sprite=ov96_021EB5B8(PTR(obj,0xc));
    Sprite_SetAnimCtrlSeq(sprite,remainder-tens*10+1);
}
