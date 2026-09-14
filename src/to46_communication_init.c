#include "global.h"

typedef struct CommManagerScratch {
    u8 initialized;
    u8 updateLock;
    u8 pad02[2];
    void *allocation;
    u8 *work;
} CommManagerScratch;

extern CommManagerScratch _021D4140;
extern void GF_AssertFail(void);
extern int sub_0203993C(void);
extern int sub_02033FC4(u16);
extern int sub_02034044(int);
extern void sub_020379A0(int);
extern void sub_02033F44(void *, int, void *);
extern void sub_02033AE0(void *, const void *, u32);
extern void sub_02033F70(void *);
extern void sub_02035DA4(void);
extern void sub_0203778C(void *);
extern void sub_020360EC(void);
extern void *Heap_Alloc(int, u32);
extern void *SysTask_CreateOnVBlankQueue(void *, void *, int);

int sub_02035900(int, int);
void sub_02035AE0(void);

int sub_02035900(int enabled, int value) {
    int existing = 0;
    int count;
    int i;

    _021D4140.updateLock = 0;
    if (enabled != 0) {
        count = sub_02033FC4((u16)sub_0203993C()) + 1;
        if (_021D4140.work != NULL) {
            return 1;
        }

        sub_020379A0(15);
        _021D4140.allocation = Heap_Alloc(15, 0x6e0);
        _021D4140.work = (u8 *)(32 - ((u32)_021D4140.allocation & 31)) + (u32)_021D4140.allocation;
        MI_CpuFill8(_021D4140.work, 0, 0x6c0);

        if (sub_02034044(sub_0203993C())) {
            *(u32 *)(_021D4140.work + 0x690) = value * 2 + 0x40;
        } else {
            *(u32 *)(_021D4140.work + 0x690) = value + 0x40;
        }
        *(u32 *)(_021D4140.work + 0x68c) = *(u32 *)(_021D4140.work + 0x690) * count;
        _021D4140.work[0x6ad] = 0;
        value = 42;
        _021D4140.work[0x6ae] = value;
        *(void **)(_021D4140.work + 0x490) = Heap_Alloc(15, *(u32 *)(_021D4140.work + 0x690) * 2);
        *(void **)(_021D4140.work + 0x494) = Heap_Alloc(15, *(u32 *)(_021D4140.work + 0x690));
        *(void **)(_021D4140.work + 0x48c) = Heap_Alloc(15, *(u32 *)(_021D4140.work + 0x68c));
        *(void **)(_021D4140.work + 0x488) = Heap_Alloc(15, *(u32 *)(_021D4140.work + 0x68c));

        if (sub_0203993C() == 10) {
            sub_02033F44(_021D4140.work + 0x580, 100, _021D4140.work + 0x498);
            sub_02033F44(_021D4140.work + 0x5a0, 800, _021D4140.work + 0x510);
        } else {
            sub_02033F44(_021D4140.work + 0x580, 20, _021D4140.work + 0x498);
            sub_02033F44(_021D4140.work + 0x5a0, value + 238, _021D4140.work + 0x510);
        }
    } else {
        existing = 1;
        if (_021D4140.work == NULL) {
            GF_AssertFail();
        }
    }

    *(u16 *)(_021D4140.work + 0x694) = 0;
    for (i = 0; i < 4; i++) {
        _021D4140.work[0x6a6 + i] = 0xff;
    }
    if (existing == 0) {
        sub_02035DA4();
    }
    sub_0203778C(_021D4140.work + 0x62c);
    if (existing == 0) {
        *(void **)(_021D4140.work + 0x57c) = SysTask_CreateOnVBlankQueue(sub_020360EC, NULL, 0);
    }
    _021D4140.work[0x6b6] = 0;
    return 1;
}
