#include "overlay57_picture_anim_internal.h"
#define PTR(w, o) (*(void **)((u8 *)(w) + (o)))

void ov57_0223BA1C(void *w) {
    Pokepic_SetAttr(PTR(w, 0x1c8), 12, 0);
    Pokepic_SetAttr(PTR(w, 0x1c8), 13, 0);
}

BOOL ov57_0223BA40(void *w) {
    if (Pokepic_GetAttr(PTR(w, 0x1c8), 12) == 0x100) {
        return FALSE;
    }
    if (Pokepic_GetAttr(PTR(w, 0x1c8), 12) >= 0x100) {
        Pokepic_SetAttr(PTR(w, 0x1c8), 12, 0x100);
        Pokepic_SetAttr(PTR(w, 0x1c8), 13, 0x100);
        return FALSE;
    }
    Pokepic_AddAttr(PTR(w, 0x1c8), 12, 0x20);
    Pokepic_AddAttr(PTR(w, 0x1c8), 13, 0x20);
    sub_0200914C(PTR(w, 0x1c8), PTR(w, 0x1cc));
    return TRUE;
}

BOOL ov57_0223BABC(void *w) {
    if (Pokepic_GetAttr(PTR(w, 0x1c8), 12) == 0) {
        return FALSE;
    }
    if (Pokepic_GetAttr(PTR(w, 0x1c8), 12) <= 0) {
        Pokepic_SetAttr(PTR(w, 0x1c8), 12, 0);
        Pokepic_SetAttr(PTR(w, 0x1c8), 13, 0);
        return FALSE;
    }
    Pokepic_AddAttr(PTR(w, 0x1c8), 12, -0x20);
    Pokepic_AddAttr(PTR(w, 0x1c8), 13, -0x20);
    sub_0200914C(PTR(w, 0x1c8), PTR(w, 0x1cc));
    return TRUE;
}
