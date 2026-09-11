#include "overlay96_exact_bank_internal.h"
#include "overlay96_exact_bank_prototypes.h"

void ov96_021EEF98(void **p) {
    FreeBgTilemapBuffer(p[1], 0);
    Heap_Free(p[1]);
}
