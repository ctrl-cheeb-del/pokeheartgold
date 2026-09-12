#include "overlay57_capsule_main_r9_private.h"

void ov57_0223A05C(void *w) {
    int i;
    u8 *p = w;
    u32 off = 0x414;
    i = 8;
    p += 0x20;
    for (; i < 13; i++, p += 4) {
        Sprite_DeleteAndFreeResources(*(void **)(p + off));
    }
}

BOOL ov57_0223A07C(void *capsule) {
    BOOL ret = FALSE;
    int i;
    int count;
    count = ret;
    i = ret;
    for (; i < 8; i++) {
        if (SealOnCapsuleGetID(CapsuleGetSealI(capsule, i)) != 0) {
            count++;
        }
    }
    if (count != 0) {
        ret = TRUE;
    }
    return ret;
}

int ov57_0223A0A8(void *w, int i) {
    u8 *p = (u8 *)w + i * 12;
    u32 a = U32(p, 0x28c);
    u32 b = U32(p, 0x290);
    if (a == 0xff && b == 0) {
        return 0;
    }
    if (a == 0xff && b == 1) {
        return 1;
    }
    if (a != 0xff && b == 1) {
        return 2;
    }
    return 3;
}

void *ov57_0223A0E0(void *w) {
    void *ret = ov57_0223BEB8[U32(w, 0x3f4)](w);
    SpriteSystem_DrawSprites(PTR(w, 0xe0));
    return ret;
}
