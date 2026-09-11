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

void ov96_021F910C(u8 *obj, void *value, u32 index) {
    if (index >= 4) GF_AssertFail();
    PTR(obj + index*0x28, 0x44) = value;
    ov96_021F91E8(obj + 0x24 + index*0x28, (s32)value);
}
