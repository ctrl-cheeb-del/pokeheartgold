#include "overlay96_exact_bank_internal.h"
#include "overlay96_exact_bank_prototypes.h"

void ov96_021E8A20(void) {
}

void *ov96_021E8A24(void) {
    return ov96_0221AEC4;
}

int ov96_021E8A2C(void) {
    return 0xC;
}

void *ov96_021E8A30(u32 heapId) {
    void **p = Heap_Alloc(heapId, 0x958);
    p[0] = (void *)heapId;
    return p;
}
