#include "to41_overlay_96_residual_93_private.h"

void ov96_0220A5DC(void *course, u32 value) {
    u8 *p;
    void *fmt;
    void *msg;
    void *s;
    p = PokeathlonCourse_GetHeapAllocPtr4(course);
    fmt = PTR(p, 0x25c);
    msg = PTR(p, 0x258);
    ov96_021E8318(course, (u16)value);
    FillWindowPixelBuffer(p + 0x238, 0);
    BufferIntegerAsString(fmt, 0, value, 3, 0, 1);
    s = ReadMsgData_ExpandPlaceholders(fmt, (u32)msg, 0x9f, U32(p, 0));
    AddTextPrinterParameterizedWithColor(p + 0x238, 4, s, 0, 0, 0xff, 0x000f0e00, NULL);
    String_Delete(s);
    CopyWindowToVram(p + 0x238);
}

void ov96_0220A660(void *task, void *p) {
    s32 d;
    s32 v;
    if (*((u8 *)p + 0x26e)) {
        v = 1;
    } else {
        v = -1;
    }
    d = *(s8 *)((u8 *)p + 0x26c) * v;
    ScheduleSetBgPosText(PTR(p, 4), 0, 3, d);
    ScheduleSetBgPosText(PTR(p, 4), 1, 3, d);
    G2dRenderer_SetMainSurfaceCoords(SpriteSystem_GetRenderer(PTR(p, 8)), 0, -d << 12);
    *((u8 *)p + 0x26c) = (u8)(*(s8 *)((u8 *)p + 0x26c) - *((u8 *)p + 0x26d));
    *((u8 *)p + 0x26e) = (u8)(*((u8 *)p + 0x26e) ^ 1);
    if (*(s8 *)((u8 *)p + 0x26c) <= 0) {
        ScheduleSetBgPosText(PTR(p, 4), 0, 3, 0x10);
        ScheduleSetBgPosText(PTR(p, 4), 1, 3, 0);
        G2dRenderer_SetMainSurfaceCoords(SpriteSystem_GetRenderer(PTR(p, 8)), 0, 0);
        U32(p, 0x268) = 0;
        SysTask_Destroy(task);
    }
}

void ov96_0220A704(u8 *p, int a, int b) {
    if (U32(p, 0x268)) {
        SysTask_Destroy(PTR(p, 0x268));
    }
    p[0x26e] = 0;
    p[0x26c] = (u8)a;
    p[0x26d] = (u8)b;
    PTR(p, 0x268) = SysTask_CreateOnMainQueue(ov96_0220A660, p, 2);
}

void *ov96_0220A744(void *course, void *a, void *b, void *c) {
    u8 *p;
    s32 i;
    u8 *q;
    p = Heap_Alloc((u32)course, 0x184);
    MI_CpuFill8(p, 0, 0x184);
    U32(p, 0x180) = (U32(p, 0x180) & ~0xf) | 1;
    U32(p, 0x180) &= ~0xf0;
    PTR(p, 4) = a;
    PTR(p, 8) = b;
    PTR(p, 0) = c;
    PTR(p, 0xc) = ov96_0220D13C(a, b, 0, 0, 7, 1);
    ManagedSprite_SetDrawFlag(PTR(p, 0xc), 0);
    PTR(p, 0x10) = ov96_0220D13C(a, b, 0, 0, 0x12, 1);
    ManagedSprite_SetDrawFlag(PTR(p, 0x10), 0);
    for (i = 0, q = p; i < 10; i++, q += 4) {
        PTR(q, 0x154) = ov96_0220AE40(course, a, b, (u16)i);
    }
    ov96_0220B178(p + 0x14, a, b);
    return p;
}

void ov96_0220A7F8(u8 *p) {
    s32 i;
    u8 *q;
    if (!p) {
        GF_AssertFail();
    }
    if (!PTR(p, 0xc)) {
        GF_AssertFail();
    }
    Sprite_DeleteAndFreeResources(PTR(p, 0xc));
    Sprite_DeleteAndFreeResources(PTR(p, 0x10));
    for (i = 0, q = p; i < 10; i++, q += 4) {
        ov96_0220AF30(PTR(q, 0x154));
    }
    ov96_0220B1B8(p + 0x14);
    Heap_Free(p);
}

void ov96_0220A840(u8 *p) {
    if (!p) {
        GF_AssertFail();
    }
    switch ((u32)((s32)(U32(p, 0x180) << 28)) >> 28) {
    case 1:
        ov96_0220AD64(p);
        break;
    case 2:
        ov96_0220AE28(p);
        break;
    default:
        GF_AssertFail();
        break;
    }
    p += 0x14;
    ov96_0220B324(p);
}

void ov96_0220A87C(u8 *p) {
    s32 i;
    u8 *q;
    ManagedSprite_SetAnimateFlag(PTR(p, 0x10), 0);
    ManagedSprite_SetAnimateFlag(PTR(p, 0xc), 0);
    for (i = 0, q = p; i < 10; i++, q += 4) {
        if ((U32(PTR(q, 0x154), 0x10) << 4) >> 31) {
            ManagedSprite_SetAnimateFlag(PTR(PTR(q, 0x154), 0), 0);
            ManagedSprite_SetAnimateFlag(PTR(PTR(q, 0x154), 4), 0);
        }
    }
    p += 0x14;
    ov96_0220B354(p);
}

BOOL ov96_0220A8CC(u8 *p, void *a) {
    if (!p) {
        GF_AssertFail();
    }
    if (((U32(p, 0x180) << 24) >> 28) == 0) {
        GF_AssertFail();
    }
    if (ov96_0220B0A4(PTR((u8 *)p + (((U32(p, 0x180) << 24) >> 28) << 2), 0x150), a)) {
        return TRUE;
    }
    return FALSE;
}
