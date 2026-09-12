#include "overlay70_resource_state_25_private.h"

void ov70_0223ECCC(Ov70Work25 *work) {
    work->string = String_New(0xB4, HEAP_ID_61);
    work->allocation = Heap_Alloc(HEAP_ID_61, sizeof(Ov70Alloc25));
    MI_CpuClearFast(work->allocation, sizeof(Ov70Alloc25));
    work->allocation->primary = ov70_0223F634(HEAP_ID_61, 0, &work->allocation->count);
    work->allocation->secondary = ov70_0223F684(HEAP_ID_61);
    ov70_0223F948(work->pairs);
}

void ov70_0223ED24(Ov70Work25 *work) {
    Heap_Free(work->allocation->secondary);
    Heap_Free(work->allocation->primary);
    Heap_Free(work->allocation);
    String_Delete(work->string);
}

int ov70_0223ED58(Ov70Work25 *work) {
    if (IsPaletteFadeFinished()) {
        ov70_0223E8E8(work, 9, 1, 0, 0xF0F);
        ov70_02238D84(work, 0x10, 1);
    }
    return 3;
}

int ov70_0223ED8C(Ov70Work25 *work) {
    if (gSystem.newKeys & PAD_BUTTON_B) {
        ov70_02238E50(work, 5, 5);
        work->state = 2;
    }
    work->state = 3;
    return 3;
}

int ov70_0223EDB0(Ov70Work25 *work) {
    ov70_022420C4(work->manager, 0);
    work->state = 6;
    return 3;
}
