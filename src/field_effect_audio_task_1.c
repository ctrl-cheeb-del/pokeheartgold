#include "field_effect_audio_task_internal.h"
void *ov01_022051EC(u32 arg) {
    u8 *p = ov01_021F1430(arg, 0xC4, 0, 0);
    *(u32 *)p = arg;
    ov01_02205218(p);
    return p;
}
void ov01_02205208(void *p) {
    ov01_022052A4(p);
    ov01_021F1448(p);
}
void ov01_02205218(void *v) {
    u8 *p = v;
    HeapExp_FndInitAllocator(p + 4, 4, 0x20);
    Field3dModel_LoadFromFilesystem(p + 0x14, 0x67, 0x84, 4);
    Field3dModelAnimation_LoadFromFilesystem(p + 0x24, p + 0x14, 0x67, 0xA8, 4, p + 4);
    Field3dModelAnimation_LoadFromFilesystem(p + 0x38, p + 0x14, 0x67, 0xA6, 4, p + 4);
    Field3dObject_InitFromModel(p + 0x4c, p + 0x14);
    Field3dObject_AddAnimation(p + 0x4c, p + 0x24);
    Field3dObject_AddAnimation(p + 0x4c, p + 0x38);
    ov01_022053C4(p + 0x24, 2, 0);
    Field3dObject_SetActiveFlag(p + 0x4c, FALSE);
}
void ov01_022052A4(void *v) {
    u8 *p = v;
    Field3dModelAnimation_Unload(p + 0x38, p + 4);
    Field3dModelAnimation_Unload(p + 0x24, p + 4);
    Field3dModel_Unload(p + 0x14);
}
void ov01_022052C4(void *ctx, void *arg) {
    SpawnArgs a;
    a.ctx = ctx;
    a.renderer = ov01_021F1450(ctx, 0x16);
    ov01_021F1620(ctx, ov01_022096CC, arg, 0, &a, 0xFF);
}
void *ov01_022052F4(void *task) {
    return *(void **)sub_02068D74(task);
}
BOOL ov01_02205300(void *task, void *v) {
    u8 *p = v;
    u8 *ctx;
    Vec3 pos;
    void *args = sub_02068D98(task);
    *(void **)(p + 4) = *(void **)((u8 *)args + 4);
    *(u32 *)p = 0;
    ctx = *(u8 **)((u8 *)args + 4);
    ov01_022053C4(ctx + 0x24, 2, 0);
    Field3dObject_SetActiveFlag(ctx + 0x4c, TRUE);
    sub_02068DB8(task, &pos);
    Field3dObject_SetPosEx(ctx + 0x4c, pos.x, pos.y, pos.z);
    PlaySE(0x910);
    return TRUE;
}
void ov01_02205350(void) {
}
void ov01_02205354(void *task, void *v) {
    Field3dObject_SetActiveFlag(*(u8 **)((u8 *)v + 4) + 0x4c, FALSE);
}
void ov01_02205364(void *task, void *v) {
    u8 *p = v;
    u8 *ctx = *(u8 **)(p + 4);
    if (ov01_02205388(ctx + 0x24, 2)) {
        *(u32 *)p = 1;
    }
    Field3dObject_Draw(ctx + 0x4c);
}
BOOL ov01_02205388(void *v, u32 count) {
    u8 *p = v;
    u8 i, done = 0;
    for (i = 0; i < count; i++) {
        if (Field3dModelAnimation_FrameAdvanceAndCheck(p + i * 0x14, 1 << 12)) {
            done++;
        }
    }
    return done == count;
}
void ov01_022053C4(void *v, u32 count, s32 frame) {
    u8 *p = v;
    u8 i;
    for (i = 0; i < count; i++) {
        Field3dModelAnimation_FrameSet(p + i * 0x14, frame);
    }
}
