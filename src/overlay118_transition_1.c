#include "global.h"
typedef struct {
    u8 raw[0x24];
} Ov118Task;
typedef struct {
    s32 value;
    u8 pad[0x14];
    u32 count;
    u32 active;
} Ov118Work;
extern const u8 _0225F270[28];
extern const u8 ov118_0225F28C[28];
extern void *Heap_Alloc(int, u32);
extern void Heap_Free(void *);
extern void GfGfx_EngineATogglePlanes(int, int);
extern void FreeBgTilemapBuffer(void *, int);
extern void InitBgFromTemplate(void *, int, const void *, int);
extern void BgClearTilemapBufferAndCommit(void *, int);
extern void ov01_021F0500(void *, int, int, int, int, int, void *, int, int);
extern void SetBgPriority(int, int);
extern void BG_SetMaskColor(int, int);
extern void BgSetPosTextAndCommit(void *, int, int, int);
extern void GfGfx_EngineASetPlanes(int);
extern void ov01_021EFCF8(int, int, int, u32 *, int);
extern void ov01_021EFEC8(void *, s32, s32, s32, int);
extern int ov01_021EFF28(void *);
extern void sub_0200FC20(void);
extern void ov01_021EFCDC(void *, void *);
extern void ScheduleSetBgPosText(void *, int, int, int);
void ov118_0225F020(void *, Ov118Task *);

const u8 __attribute__((aligned(4))) _0225F270[28] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0x10, 0, 0, 0, 0, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0
};
const u8 __attribute__((aligned(4))) ov118_0225F28C[28] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0x10, 0, 0, 0, 0, 0, 0, 3, 0, 2, 2, 1, 0, 0, 0, 0, 0, 0, 0
};

void ov118_0225F020(void *caller, Ov118Task *task) {
    Ov118Work *work = *(Ov118Work **)((u8 *)task + 0xc);
    switch (*(u32 *)task) {
    case 0:
        *(void **)((u8 *)task + 0xc) = Heap_Alloc(4, 0x20);
        memset(*(void **)((u8 *)task + 0xc), 0, 0x20);
        work = *(Ov118Work **)((u8 *)task + 0xc);
        GfGfx_EngineATogglePlanes(2, 1);
        GfGfx_EngineATogglePlanes(8, 1);
        *(volatile u32 *)0x04000000 = (*(volatile u32 *)0x04000000 & 0xffffe0ff) | 0x1500;
        FreeBgTilemapBuffer(*(void **)((u8 *)*(void **)((u8 *)task + 0x10) + 8), 1);
        InitBgFromTemplate(*(void **)((u8 *)*(void **)((u8 *)task + 0x10) + 8), 1, _0225F270, 0);
        BgClearTilemapBufferAndCommit(*(void **)((u8 *)*(void **)((u8 *)task + 0x10) + 8), 1);
        FreeBgTilemapBuffer(*(void **)((u8 *)*(void **)((u8 *)task + 0x10) + 8), 3);
        InitBgFromTemplate(*(void **)((u8 *)*(void **)((u8 *)task + 0x10) + 8), 3, ov118_0225F28C, 0);
        BgClearTilemapBufferAndCommit(*(void **)((u8 *)*(void **)((u8 *)task + 0x10) + 8), 3);
        ov01_021F0500(*(void **)((u8 *)task + 0x20), 0xa8, 0xa7, 0xa6, 0, 0, *(void **)((u8 *)*(void **)((u8 *)task + 0x10) + 8), 1, 3);
        SetBgPriority(2, 0);
        SetBgPriority(8, 0);
        BG_SetMaskColor(1, 0);
        BgSetPosTextAndCommit(*(void **)((u8 *)*(void **)((u8 *)task + 0x10) + 8), 1, 0, 0x80);
        BgSetPosTextAndCommit(*(void **)((u8 *)*(void **)((u8 *)task + 0x10) + 8), 3, 0, 0x100);
        GfGfx_EngineASetPlanes(0x15);
        *(u32 *)task = 1;
        break;
    case 1:
        ov01_021EFCF8(1, -16, -16, (u32 *)((u8 *)task + 4), 2);
        *(u32 *)task = 2;
        break;
    case 2:
        if (*(u32 *)((u8 *)task + 4)) {
            *(u32 *)task = 3;
        }
        break;
    case 3:
        ov01_021EFEC8(work, 0x80000, 0, 0x5000, 0x12);
        GfGfx_EngineATogglePlanes(2, 1);
        GfGfx_EngineATogglePlanes(8, 1);
        work->active = 1;
        *(u32 *)task = 4;
        break;
    case 4:
        if (ov01_021EFF28(work)) {
            *(u32 *)task = 5;
        }
        break;
    case 5:
        BgSetPosTextAndCommit(*(void **)((u8 *)*(void **)((u8 *)task + 0x10) + 8), 1, 0, 0);
        BgSetPosTextAndCommit(*(void **)((u8 *)*(void **)((u8 *)task + 0x10) + 8), 3, 0, 0x180);
        work->active = 0;
        if (work->count++ > 5) {
            GfGfx_EngineATogglePlanes(1, 0);
            work->active = 1;
            work->count = 0;
            *(u32 *)task = 6;
        }
        break;
    case 6:
        ov01_021EFEC8(work, 0, 0x80000, 0x5000, 0x12);
        work->active = 1;
        *(u32 *)task = 7;
        break;
    case 7:
        if (ov01_021EFF28(work)) {
            *(u32 *)task = 8;
        }
        break;
    case 8:
        work->active = 0;
        sub_0200FC20();
        if (*(u32 *)((u8 *)task + 0x14)) {
            **(u32 **)((u8 *)task + 0x14) = 1;
        }
        ov01_021EFCDC(task, caller);
        return;
    }
    if (work->active) {
        ScheduleSetBgPosText(*(void **)((u8 *)*(void **)((u8 *)task + 0x10) + 8), 1, 0, work->value >> 12);
        ScheduleSetBgPosText(*(void **)((u8 *)*(void **)((u8 *)task + 0x10) + 8), 1, 3, 0);
        ScheduleSetBgPosText(*(void **)((u8 *)*(void **)((u8 *)task + 0x10) + 8), 3, 0, 0x180 - (work->value >> 12));
        ScheduleSetBgPosText(*(void **)((u8 *)*(void **)((u8 *)task + 0x10) + 8), 3, 3, 0);
    }
}
