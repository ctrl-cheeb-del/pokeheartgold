#include "overlay_80_02236B78_opus_partial_internal.h"

int ov80_022370F4(int a0) {
    switch (a0) {
    case 0:
        return 0x81;
    case 1:
        return 0x83;
    case 2:
        return 0x8F;
    case 3:
        return 0x8F;
    }
    return 0x81;
}

int ov80_02237120(Ov80FrontierWork *work) {
    if (work->unk05 == 0) {
        return 50;
    }
    return 100;
}

void ov80_02237130(Ov80FrontierWork *work) {
    int i;
    void *mon;
    Ov80MonSetup *p;
    ov80_0222A52C(work->unk280, work->unk254, work->unk260, work->unk268, 0, 6, 11, 0xCD);
    SaveArray_Party_Init(work->unk4D4);
    mon = AllocMonZeroed(11);
    for (i = 0, p = work->unk280; i < 6; i++, p++) {
        ov80_0222A140(p, mon, ov80_02237120(work));
        ov80_0222A3BC(work->unk4F8, work->unk4D4, mon);
    }
    Heap_Free(mon);
}

void ov80_022371B0(Ov80FrontierWork *work) {
    int i;
    int count;
    void *mon;
    Ov80MonSetup buf[2];
    count = Party_GetCount(work->unk4D4);
    while (count > 2) {
        Party_RemoveMon(work->unk4D4, count - 1);
        count--;
    }
    ov80_0222A52C(buf, work->unk584, work->unk590, work->unk598, 0, 2, 11, 0xCD);
    mon = AllocMonZeroed(11);
    for (i = 0; i < 2; i++) {
        ov80_0222A140(&buf[i], mon, ov80_02237120(work));
        ov80_0222A3BC(work->unk4F8, work->unk4D4, mon);
        work->unk4EC[i] = work->unk584[i];
    }
    Heap_Free(mon);
}

BOOL ov80_02237254(int a0) {
    switch (a0) {
    case 2:
    case 3:
        return TRUE;
    }
    return FALSE;
}
