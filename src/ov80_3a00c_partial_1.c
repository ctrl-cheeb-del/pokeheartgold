#include "ov80_3a00c_partial_internal.h"

void ov80_0223A00C(int variant, void *bg, void *spriteSystem, void *spriteManager, void *palette, void *done, s16 x, s16 y) {
    void *task = CreateSysTaskAndEnvironment(ov80_0223A144, 0x168, 0x3E8, 0x65);
    u8 *p = SysTask_GetData(task);
    *(void **)(p + 0x10) = bg;
    *(void **)(p + 0x14) = spriteSystem;
    *(void **)(p + 0x18) = spriteManager;
    *(void **)(p + 0x1C) = palette;
    *(void **)(p + 0x20) = done;
    *(s16 *)(p + 0x28) = x;
    *(s16 *)(p + 0x2A) = y;
    *(void **)(p + 0x24) = NARC_New(0x6D, 0x65);
    if (*(void **)(p + 0x20) != NULL) {
        *(u16 *)*(void **)(p + 0x20) = 0;
    }
    p[0x2C] = variant - 1;
    MIi_CpuClear32(0, BgGetCharPtr(1), 0x8000);
    ScheduleSetBgPosText(bg, 1, 0, 0);
    ScheduleSetBgPosText(bg, 1, 3, 0);
    ov80_0223A938(p, ov80_0223DB98 + p[0x2C] * 12);
    *(void **)(p + 0x34) = SysTask_CreateOnVWaitQueue(ov80_0223A0EC, p, 1);
}

void ov80_0223A0C0(void *data, void *task) {
    u8 *p = data;
    SysTask_Destroy(*(void **)(p + 0x140));
    SysTask_Destroy(*(void **)(p + 0x34));
    NARC_Delete(*(void **)(p + 0x24));
    Heap_FreeExplicit(0x65, *(void **)(p + 0xC));
    DestroySysTaskAndEnvironment(task);
}
