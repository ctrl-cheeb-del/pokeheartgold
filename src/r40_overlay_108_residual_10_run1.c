#include "r40_overlay_108_residual_10_private.h"

void ov108_021E733C(Ov108R10 *work) {
    int i = 0;
    u8 *area = (u8 *)work;

    for (; i < 6; i++) {
        work->sprites[i + 6] = ov108_021E8540(work->sub,
            (i % 3) * 0x48 + 0x38,
            (i / 3) * 0x48 + 0x38,
            2,
            0x80,
            i,
            area[0x1C],
            1);
        area += 0x7A;
    }
    for (i = 0; i < 6; i++) {
        work->sprites[i + 12] = ov108_021E8540(work->sub,
            (i % 3) * 0x50 + 0x30,
            (i / 3) * 0x48 + 0x38,
            3,
            0x80,
            i + 6,
            i + 6 * work->page,
            1);
    }
    work->sprites[0] = SpriteSystem_CreateSpriteFromResourceHeader(work->spriteSystem, work->spriteManager, &ov108_021EA7F8);
    work->sprites[1] = SpriteSystem_CreateSpriteFromResourceHeader(work->spriteSystem, work->spriteManager, &ov108_021EA7F8);
    work->sprites[3] = SpriteSystem_CreateSpriteFromResourceHeader(work->spriteSystem, work->spriteManager, &ov108_021EA7F8);
    work->sprites[2] = SpriteSystem_CreateSpriteFromResourceHeader(work->spriteSystem, work->spriteManager, &ov108_021EA820);
    work->sprites[4] = SpriteSystem_CreateSpriteFromResourceHeader(work->spriteSystem, work->spriteManager, &ov108_021EA848);
    work->sprites[5] = SpriteSystem_CreateSpriteFromResourceHeader(work->spriteSystem, work->spriteManager, &ov108_021EA870);
    thunk_Sprite_SetPriority(work->sprites[1], 3);
    thunk_Sprite_SetPriority(work->sprites[4], 3);
    thunk_Sprite_SetPriority(work->sprites[5], 3);
    thunk_Sprite_SetPriority(work->sprites[3], 0);
    thunk_Sprite_SetDrawPriority(work->sprites[3], 5);
    thunk_Sprite_SetDrawFlag(work->sprites[0], 0);
    thunk_Sprite_SetDrawFlag(work->sprites[1], 0);
    thunk_Sprite_SetDrawFlag(work->sprites[3], 0);
    thunk_Sprite_SetDrawFlag(work->sprites[2], 0);
    ov108_021E756C(work);
}
