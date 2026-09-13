#include "r40_overlay_72_residual_5_private.h"

void ov72_02238688(Sprite *sprite, int x, int y) {
    VecFx32 v;
    float f;
    if (x > 0) {
        f = (float)(x << 12) + 0.5f;
    } else {
        f = (float)(x << 12) - 0.5f;
    }
    v.x = (fx32)f;
    if (y > 0) {
        f = (float)(y << 12) + 0.5f;
    } else {
        f = (float)(y << 12) - 0.5f;
    }
    v.y = (fx32)f;
    v.z = 0;
    Sprite_SetMatrix(sprite, &v);
}

void ov72_022386F4(Sprite *sprite, int index) {
    ov72_02238688(sprite, ov72_0223B3A4[index * 2], ov72_0223B3A6[index * 2] + 0x100);
    if (index < 10) {
        Sprite_SetAnimCtrlSeq(sprite, 1);
    } else {
        Sprite_SetAnimCtrlSeq(sprite, 2);
    }
}

void ov72_02238730(Sprite *sprite, int index, int row) {
    ov72_02238688(sprite, *(u16 *)((u8 *)ov72_0223B364 + row * 12 + index * 4), 0x129);
}

void ov72_02238750(Sprite *sprite, int index, int row) {
    ov72_02238688(sprite,
        *(u16 *)((u8 *)ov72_0223B364 + row * 12 + index * 4),
        *(u16 *)((u8 *)ov72_0223B366 + row * 12 + index * 4) + 0x100);
}

void *ov72_02238778(void *unused, u32 size, int alignment) {
    OSIntrMode enabled = OS_DisableInterrupts();
    void *result = NNS_FndAllocFromExpHeapEx(ov72_0223B92C, size, alignment);
    OS_RestoreInterrupts(enabled);
    return result;
}
