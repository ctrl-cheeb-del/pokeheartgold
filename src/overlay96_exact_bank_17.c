#include "overlay96_exact_bank_internal.h"
#include "overlay96_exact_bank_prototypes.h"

void ov96_021E9510(u32 *p) {
    ov96_021E9394(p);
    p[0] = 4;
    p[1] = 0;
}

void *ov96_021E9524(void **p) {
    return p[0];
}

void *ov96_021E9528(void **p) {
    return p[1];
}
