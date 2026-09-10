#include "field_overlay_effects_internal.h"

void ov01_021EFC94(void *arg0, void *arg1, void *arg2) {
    u8 *p;
    SysTask *task;
    void *done;
    *(void **)(ov01_02209B64 + 4) = arg0;
    *(u32 *)(ov01_02209B64 + 8) = 0;
    task = CreateSysTaskAndEnvironment((void (*)(SysTask *, void *))ov01_021EFB38, 0x24, 5, 4);
    p = SysTask_GetData(task);
    *(void **)(p + 0x10) = arg1;
    *(void **)(p + 0x14) = arg2;
    *(void **)(p + 0x20) = NARC_New(0x6D, 4);
    done = *(void **)(p + 0x14);
    if (done) {
        *(u32 *)done = 0;
    }
    *(u32 *)(p + 0x18) = 0;
}

void ov01_021EFCDC(void *p, void *task) {
    NARC_Delete(*(void **)((u8 *)p + 0x20));
    Heap_FreeExplicit(4, *(void **)((u8 *)p + 0xC));
    DestroySysTaskAndEnvironment(task);
}

void ov01_021EFCF8(void *a, void *b, void *c, void *done, void *arg4) {
    u8 *p = Heap_Alloc(4, 0x4C);
    memset(p, 0, 0x4C);
    SysTask_CreateOnMainQueue((void (*)(SysTask *, void *))ov01_021EFD3C, p, 5);
    *(void **)(p + 0x48) = done;
    if (done) {
        *(u32 *)done = 0;
    }
    *(void **)(p + 0xC) = a;
    *(void **)(p + 0x10) = b;
    *(void **)(p + 0x14) = c;
    *(void **)(p + 4) = arg4;
}
