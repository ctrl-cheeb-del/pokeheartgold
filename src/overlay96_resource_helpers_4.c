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

void ov96_021F8E94(u8 *obj) {
    if (PTR(obj,0) != 0) {
        TextOBJ_Destroy(PTR(obj,0));
        sub_02021B5C(obj+4);
        PTR(obj,0)=0;
    }
}

void *ov96_021F8EB0(u32 heapId, void *bg, void *value) {
    u8 *obj = Heap_Alloc(heapId, 0xc4);
    u8 *window;
    void *printer;
    MI_CpuFill8(obj, 0, 0xc4);
    *(u32 *)obj = heapId;
    PTR(obj,8) = FontSystem_NewInit(4, heapId);
    PTR(obj,4) = value;
    window = obj + 0xc;
    InitWindow(window);
    AddTextWindowTopLeftCorner(bg, window, 8, 2, 0, 0);
    printer = sub_02013910(window, PTR(obj,0));
    PTR(window,0x10) = printer;
    PTR(window,0x14) = sub_02013948(printer, 2);
    return obj;
}

void ov96_021F8F0C(u8 *obj) {
    s32 i;
    u8 *p;
    u8 *window;
    i = 0;
    p = obj;
    p += 0x34;
    for (;i<4;i++,p+=0x28) ov96_021F91CC(p);
    window = obj + 0xc;
    sub_02013938(PTR(window,0x10));
    RemoveWindow(window);
    sub_020135AC(PTR(obj,8));
    Heap_Free(obj);
}

void ov96_021F8F44(u8 *obj, s32 arg) {
    ov96_021EB29C(PTR(obj,4), arg, 0x68);
    ov96_021EB2BC(PTR(obj,4), 0xa1, 3, 0x68, 2);
    ov96_021EB2F4(PTR(obj,4), 0xa1, 0, 0x68, 2, 5);
    ov96_021EB334(PTR(obj,4), 0xa1, 2, 0x68);
    ov96_021EB36C(PTR(obj,4), 0xa1, 1, 0x68);
}
