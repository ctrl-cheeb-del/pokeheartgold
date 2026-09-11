#include "overlay96_exact_bank_internal.h"
#include "overlay96_exact_bank_prototypes.h"

void ov96_022043AC(u8 *p, int i, u32 v, u32 w) {
    i *= 4;
    *(u32 *)(p + i) = v;
    p += i;
    *(u32 *)(p + 0x30) = w;
}

void ov96_022043B8(void *p) {
    Heap_Free(p);
}
