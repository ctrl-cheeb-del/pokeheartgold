#include "overlay96_exact_bank_internal.h"
#include "overlay96_exact_bank_prototypes.h"

u8 ov96_02214904(u8 *p) {
    return *(u32 *)(p + 0x44);
}
