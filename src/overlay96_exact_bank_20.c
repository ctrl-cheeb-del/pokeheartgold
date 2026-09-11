#include "overlay96_exact_bank_internal.h"
#include "overlay96_exact_bank_prototypes.h"

void ov96_021EA894(u8 *p) {
    ov96_021E8AAC(*(void **)(p + 0x14));
    Heap_Free(p);
}
