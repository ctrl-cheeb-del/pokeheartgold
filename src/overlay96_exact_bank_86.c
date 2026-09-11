#include "overlay96_exact_bank_internal.h"
#include "overlay96_exact_bank_prototypes.h"

void ov96_02206368(int a, int b, u8 *p) {
    if (p[0xA4] != 0) {
        p[0xA4]--;
    }
}
