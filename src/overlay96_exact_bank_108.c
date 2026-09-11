#include "overlay96_exact_bank_internal.h"
#include "overlay96_exact_bank_prototypes.h"

void ov96_02213354(int x, int y, int *out) {
    out[0] = x << 12;
    out[1] = y << 12;
    out[2] = 0;
}
