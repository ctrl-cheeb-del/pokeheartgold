#include "overlay_37_helpers_internal.h"

typedef struct Ov37Hw {
    u8 pad[0x3FF8];
    u32 flag;
} Ov37Hw;

#define OV37_HW     ((volatile u32 *)0x027E0000)
#define OV37_BLDCNT (*(volatile u16 *)0x04000050)

typedef struct Ov37AnimEntry {
    u16 unk_00;
    u16 unk_02;
    u16 seq;
} Ov37AnimEntry;

extern const Ov37AnimEntry ov37_021E7A80[];

void ov37_021E5F20(Ov37Work *work) {
    int i;
    Heap_Free(work->unk_43C8);
    YesNoPrompt_Destroy(work->yesNoPrompt);
    for (i = 0; i < 5; i++) {
        String_Delete(work->strbuf[i]);
    }
    String_Delete(work->unk_002C);
    String_Delete(work->unk_0028);
}

void ov37_021E5F5C(void *bgConfig) {
    FreeBgTilemapBuffer(bgConfig, 5);
    FreeBgTilemapBuffer(bgConfig, 4);
    FreeBgTilemapBuffer(bgConfig, 3);
    FreeBgTilemapBuffer(bgConfig, 2);
    FreeBgTilemapBuffer(bgConfig, 1);
    FreeBgTilemapBuffer(bgConfig, 0);
    Heap_Free(bgConfig);
}
