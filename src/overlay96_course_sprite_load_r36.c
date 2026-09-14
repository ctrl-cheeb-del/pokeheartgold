#include "overlay96_course_sprite_load_r36_private.h"

void ov96_021ECA18(void *work) {
    void *spriteSystem = PTR(work, 0x18);
    int i;
    void *spriteManager = PTR(work, 0x1c);
    NNS_G2D_VRAM_TYPE vram = NNS_G2D_VRAM_TYPE_2DMAIN;

    for (i = 0; i < 3; i++) {
        SpriteSystem_LoadCharResObj(spriteSystem, spriteManager, NARC_a_1_5_4, 0x14, TRUE, vram, 0x6d + i);
    }
    SpriteSystem_LoadCellResObj(spriteSystem, spriteManager, 0x9a, 0x15, 1, 0x68);
    SpriteSystem_LoadAnimResObj(spriteSystem, spriteManager, 0x9a, 0x16, 1, 0x68);
}
