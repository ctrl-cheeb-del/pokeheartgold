#include "r40_overlay_96_residual_17_private.h"

void *ov96_021E92E0(u32 heapId);
void ov96_021E9320(Ov96R17Work *work);
Ov96R17Record *ov96_021E9344(Ov96R17Work *work);
Ov96R17Record *ov96_021E9370(Ov96R17Work *work, u32 index);
void ov96_021E9394(Ov96R17Work *work);
void *ov96_021E94EC(Ov96R17Work *work, u32 index);

void *ov96_021E92E0(u32 heapId) {
    Ov96R17Work *work = Heap_Alloc(heapId, sizeof(Ov96R17Work));
    u8 *record;
    int i;

    MI_CpuFill8(work, 0, sizeof(Ov96R17Work));
    record = (u8 *)work;
    for (i = 0; i < 12; i++, record += 0x18) {
        *(void **)(record + 0x34) = String_New(0x25, heapId);
        *(void **)(record + 0x38) = String_New(0xB, heapId);
    }
    return work;
}

void ov96_021E9320(Ov96R17Work *work) {
    int i = 0;
    u8 *record = (u8 *)work;

    do {
        String_Delete(*(void **)(record + 0x34));
        String_Delete(*(void **)(record + 0x38));
        i++;
        record += 0x18;
    } while (i < 12);
    Heap_Free(work);
}

Ov96R17Record *ov96_021E9344(Ov96R17Work *work) {
    if (work->next >= 4) {
        GF_AssertFail();
    }
    if (work->next >= work->count) {
        GF_AssertFail();
    }
    return &work->records[work->next++];
}

Ov96R17Record *ov96_021E9370(Ov96R17Work *work, u32 index) {
    if (index >= 4) {
        GF_AssertFail();
    }
    if ((s32)index >= work->count) {
        GF_AssertFail();
    }
    return &work->records[index];
}

void ov96_021E9394(Ov96R17Work *work) {
    int i;
    work->count = 0;
    work->unk_04 = 0;
    work->next = 0;
    work->unk_0C = 0;
    work->unk_10 = 0;
    for (i = 0; i < 12; i++) {
        work->ordered[i] = NULL;
    }
}
