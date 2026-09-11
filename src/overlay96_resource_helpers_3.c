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

void ov96_021F8D98(u8 *obj, u8 *window, s32 corner) {
    void *printer;
    InitWindow(window);
    AddTextWindowTopLeftCorner(PTR(obj,8), window, corner, 2, 0, 0);
    printer = sub_02013910(window, PTR(obj,0));
    PTR(window,0x10) = printer;
    PTR(window,0x14) = sub_02013948(printer, 1);
}

void ov96_021F8DD4(u8 *obj) {
    ov96_021F8D98(obj, obj + 0x2fc, 8);
    ov96_021F8D98(obj, obj + 0x314, 0x18);
}
