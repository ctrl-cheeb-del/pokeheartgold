#include "overlay96_exact_bank_internal.h"
#include "overlay96_exact_bank_prototypes.h"

void ov96_021FBE3C(void *p) {
    Heap_Free(p);
}

void *ov96_021FBE44(u8 *p, int i) {
    return p + i * 0x10;
}

void ov96_021FBE4C(void **p, void *a, void *b) {
    p[1] = a;
    p[2] = b;
}
