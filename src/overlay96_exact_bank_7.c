#include "overlay96_exact_bank_internal.h"
#include "overlay96_exact_bank_prototypes.h"

void ov96_021E7F98(u32 add, u32 limit, u32 *value) {
    if (*value + add > limit) {
        *value = limit;
    } else {
        *value += add;
    }
}
