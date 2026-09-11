#include "overlay96_exact_bank_internal.h"
#include "overlay96_exact_bank_prototypes.h"

void ov96_021EB564(void **p, int v) {
    Sprite_SetAnimCtrlSeq(p[1], v);
}

BOOL ov96_021EB570(void **p, int v) {
    return Sprite_TryChangeAnimSeq(p[1], v);
}

BOOL ov96_021EB57C(void **p) {
    return Sprite_IsAnimated(p[1]);
}

void ov96_021EB588(void **p, const void *v) {
    Sprite_SetMatrix(p[1], v);
}

void *ov96_021EB594(void **p) {
    return Sprite_GetMatrixPtr(p[1]);
}

void ov96_021EB5A0(void **p, const void *v, int type) {
    Sprite_SetScaleAndAffineType(p[1], v, type);
}

void ov96_021EB5AC(void **p, u16 v, int type) {
    Sprite_SetRotationAndAffineType(p[1], v, type);
}

void *ov96_021EB5B8(void **p) {
    return p[1];
}

void ov96_021EB5BC(u8 *p) {
    SpriteList_RenderAndAnimateSprites(*(void **)(p + 0x14));
}
