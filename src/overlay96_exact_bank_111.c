#include "overlay96_exact_bank_internal.h"
#include "overlay96_exact_bank_prototypes.h"

BOOL ov96_02215864(u8 *p) {
    if (p == NULL) {
        GF_AssertFail();
    }
    return *(u32 *)(p + 8) == 0;
}

void ov96_0221587C(void **p, void *a, void *b) {
    p[1] = a;
    p[0] = b;
}
