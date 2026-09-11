#include "overlay96_exact_bank_internal.h"
#include "overlay96_exact_bank_prototypes.h"

void ov96_02214B74(u8 *p, u32 v) {
    *(u32 *)(p + 0x90) = v;
}

void ov96_02214B7C(void *p) {
    Heap_Free(p);
}
