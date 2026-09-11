#include "overlay96_exact_bank_internal.h"
#include "overlay96_exact_bank_prototypes.h"

u32 ov96_021EEA80(u8 *p) {
    return (*(u32 *)(p + 0x34) << 3) >> 31;
}
