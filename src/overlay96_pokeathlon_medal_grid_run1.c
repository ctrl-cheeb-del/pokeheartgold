#include "overlay96_pokeathlon_medal_grid_private.h"

void ov96_021FA7BC(void *sys, u32 unused, u32 idx, void *s) {
    if (U32AT(s, 4) == 0) {
        if (U8AT(s, 0x34) != 0) {
            sub_0200606C(0x60A, ov96_0221DC2C[idx]);
            ov96_021E8228(sys, (u8)ov96_021E5F24(sys), idx, 2, 1);
        } else {
            sub_0200606C(0x8AA, ov96_0221DC2C[idx]);
        }
        sub_020061D0(ov96_0221DC2C[idx], ov96_0221DC28[idx]);
        U32AT(s, 4) = 1;
        U8AT(s, 0xC) = 0;
        U32AT(s, 8) = 1;
        ov96_021EAE9C(PAT(s, 0), (u8 *)s + 0x10, (u8 *)s + 0x14);
    }
}
