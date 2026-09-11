#include "overlay96_exact_bank_internal.h"
#include "overlay96_exact_bank_prototypes.h"

void ov96_021F893C(u8 *p, u32 *a, u32 *b) {
    *a = *(u32 *)(p + 0x38);
    *b = *(u32 *)(p + 0x3C);
}

void ov96_021F8948(u8 *p, void *a, void *b) {
    *(void **)(p + 0x38) = a;
    *(void **)(p + 0x3c) = b;
    ov96_021F8C88(a, b, p);
}
