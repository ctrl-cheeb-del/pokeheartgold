#include "overlay96_exact_bank_internal.h"
#include "overlay96_exact_bank_prototypes.h"

void ov96_021EABDC(u8 *p, u32 v) {
    *(u32 *)(p + 0x3C) = v;
}

void ov96_021EABE0(void **p, int value) {
    Sprite_SetAffineOverwriteMode(ov96_021E8BAC(p[0]), value);
}

void ov96_021EABF4(void **p, const void *value) {
    Sprite_SetAffineMatrix(ov96_021E8BAC(p[0]), value);
}

void ov96_021EAC08(u8 *p, u32 v) {
    *(u32 *)(p + 0x34) = v;
}
