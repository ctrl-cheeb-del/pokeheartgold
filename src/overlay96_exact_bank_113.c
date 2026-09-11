#include "overlay96_exact_bank_internal.h"
#include "overlay96_exact_bank_prototypes.h"

void ov96_02215944(u8 *p, int a, int b) {
    ov96_02215914(p, a);
    ov96_02215914(p + 4, b);
}
