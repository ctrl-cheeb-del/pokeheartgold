#include "unk020932e0_residual_4_tail_private.h"

void sub_02094150(SpriteTemplate *template, UnkStruct_020932E0_R4 *ptr, NNS_G2D_VRAM_TYPE vram);
Sprite *sub_0209417C(UnkStruct_020932E0_R4 *ptr, int x, int y, int animSeq, BOOL drawFlag);
void sub_0209428C(TouchscreenHitbox *rect, int x, int y, int width, int height);
void sub_02094004(UnkStruct_020932E0_R4 *ptr);

void sub_02094004(UnkStruct_020932E0_R4 *ptr) {
    int i;

    sub_0209428C(&ptr->hitboxes[30], 0xE0, 0xB0, 0x32, 0x20);
    ptr->spriteA = sub_0209417C(ptr, 0xE0, 0xB0, 4, TRUE);
    Sprite_SetPriority(ptr->spriteA, 3);
    if (ptr->unk_13 == 0) {
        Sprite_SetDrawFlag(ptr->spriteA, FALSE);
    }

    sub_0209428C(&ptr->hitboxes[32], 0x90, 0x10, 0x20, 0x20);
    ptr->spriteC = sub_0209417C(ptr, 0x90, 0x10, 2, TRUE);
    sub_0209428C(&ptr->hitboxes[31], 0x10, 0x10, 0x20, 0x20);
    ptr->spriteD = sub_0209417C(ptr, 0x10, 0x10, 0, TRUE);
    ptr->spriteE = sub_0209417C(ptr, 0, 0, 0x32, FALSE);
    ((u8 *)&ptr->hitboxes[ptr->count + 33])[0] = 0xFF;

    for (i = 0; i < ptr->count; i++) {
        ptr->list[i].sprite = sub_0209417C(ptr, i * 36, 0x40, 6, FALSE);
        ptr->list[i].unk_04 = -1;
        ptr->list[i].unk_08 = ptr->unk_10;
        Sprite_SetDrawPriority(ptr->list[i].sprite, 4);
    }

    ptr->unk_0E = 0;
    ptr->spriteB = sub_0209417C(ptr, 0x14, 0x28, 0x2D, TRUE);
    Sprite_SetPriority(ptr->spriteB, 1);
    Sprite_SetDrawPriority(ptr->spriteB, 1);
}
