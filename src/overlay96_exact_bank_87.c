#include "overlay96_exact_bank_internal.h"
#include "overlay96_exact_bank_prototypes.h"

void ov96_02207400(const int *a, const int *b, int *out) {
    out[0] = a[0] + b[0];
    out[1] = a[1] + b[1];
}
