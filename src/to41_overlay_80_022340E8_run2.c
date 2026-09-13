#include "to41_overlay_80_022340E8_private.h"

#if 0
#endif

#if 0
#endif

#if 0
#endif

#if 0
#endif

#if 0
#endif

#if 0
#endif

#if 0
#endif

void ov80_022344D4(void *ctx) {
    u8 *p = ctx;
    u8 count = Party_GetCount(*(void **)(p + 0x70));
    s32 i;
    for (i = 0; i < count; i++) {
        void *mon = Party_GetMonByIndex(*(void **)(p + 0x70), i);
        u16 species = sub_02030F34(*(void **)(p + 8), 4, (u8)i, 0, NULL);
        SetMonData(mon, 6, &species);
    }
}

void BattleArcadeData_Free(void *ctx) {
    u8 *p = ctx;
    if (p != NULL) {
        if (*(void **)(p + 0x70) != NULL) {
            Heap_Free(*(void **)(p + 0x70));
        }
        if (*(void **)(p + 0x74) != NULL) {
            Heap_Free(*(void **)(p + 0x74));
        }
        MI_CpuFill8(p, 0, 0xA88);
        Heap_Free(p);
    }
}

void ov80_02234550(void *ctx, const void *data) {
    u8 *p = ctx;
    s32 i;
    for (i = 0; i < 6; i++) {
        *(u16 *)(p + 0x418) = ov80_02234574(data, (u8)i);
        p += 2;
    }
}

u16 ov80_02234574(const void *data, u32 index) {
    if (index >= 6) {
        GF_AssertFail();
        return 0;
    }
    return *(const u16 *)((const u8 *)data + 0x38);
}
