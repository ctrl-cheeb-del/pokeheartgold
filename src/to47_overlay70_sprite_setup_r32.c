#include "to47_overlay70_sprite_setup_r32_private.h"

void ov70_02240D74(u8 *work, int which) {
    Ov70R32SpriteTemplate template;
    int i;
    const u16 *coords;
    u8 *spriteSlot;
    int anim;

    ov70_0224127C(work);
    ov70_02238B54(&template, work, work + 0xd84, 2);
    template.whichScreen = 2;
    template.position.x = 0x80000;
    template.position.y = 0x182000;
    *(Sprite **)(work + 0xee4) = Sprite_CreateAffine(&template);
    Sprite_SetAnimActiveFlag(*(Sprite **)(work + 0xee4), 1);
    Sprite_SetPriority(*(Sprite **)(work + 0xee4), 2);
    Sprite_SetAnimCtrlSeq(*(Sprite **)(work + 0xee4), which * 7 + 3);
    Sprite_SetDrawFlag(*(Sprite **)(work + 0xee4), 1);

    i = 0;
    coords = ov70_02245D0A;
    spriteSlot = work;
    anim = 14;
    for (; i < 7; i++) {
        *(Sprite **)(spriteSlot + 0xee8) = Sprite_CreateAffine(&template);
        Sprite_SetAnimActiveFlag(*(Sprite **)(spriteSlot + 0xee8), 1);
        Sprite_SetAnimCtrlSeq(*(Sprite **)(spriteSlot + 0xee8), anim);
        Sprite_SetDrawFlag(*(Sprite **)(spriteSlot + 0xee8), 0);
        ov70_022410F0(*(Sprite **)(spriteSlot + 0xee8), coords[0], coords[1]);
        Sprite_SetPriority(*(Sprite **)(spriteSlot + 0xee8), 2);
        spriteSlot += 4;
        anim += 4;
        coords += 2;
    }

    *(Sprite **)(work + 0xf0c) = Sprite_CreateAffine(&template);
    Sprite_SetAnimActiveFlag(*(Sprite **)(work + 0xf0c), 1);
    Sprite_SetAnimCtrlSeq(*(Sprite **)(work + 0xf0c), 43);
    Sprite_SetDrawFlag(*(Sprite **)(work + 0xf0c), 0);
    ov70_022410F0(*(Sprite **)(work + 0xf0c), 128, 86);
    Sprite_SetPriority(*(Sprite **)(work + 0xf0c), 1);

    *(Sprite **)(work + 0xf10) = Sprite_CreateAffine(&template);
    Sprite_SetAnimActiveFlag(*(Sprite **)(work + 0xf10), 1);
    Sprite_SetAnimCtrlSeq(*(Sprite **)(work + 0xf10), 42);
    ov70_02238F9C(*(Sprite **)(work + 0xf10), 55, *(u8 **)(work + 0xf14) + 0x1a8);
    Sprite_SetDrawFlag(*(Sprite **)(work + 0xf10), 0);

    spriteSlot = work;
    for (i = 0; i < 8; i++) {
        Ov70R32Vec *matrix = Sprite_GetMatrixPtr(*(Sprite **)(spriteSlot + 0xee4));
        *(s16 *)(spriteSlot + 0x120c) = matrix->x / 0x1000;
        *(s16 *)(spriteSlot + 0x120e) = matrix->y / 0x1000;
        spriteSlot += 4;
    }
}
