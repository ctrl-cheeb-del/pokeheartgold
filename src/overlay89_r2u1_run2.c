#include "overlay89_r2u1_private.h"

#define SLOT(w, off) (*(void **)((u8 *)(w) + (off)))

void ov89_022596DC(void *work) {
    {
        int i = 0;
        u8 *p = work;
        for (; i < 6; i++, p += 4) {
            Sprite_DeleteAndFreeResources(SLOT(p, 0x924));
        }
    }
    {
        u8 *p;
        int i;
        i = 0;
        p = work;
        for (; i < 6; i++, p += 4) {
            Sprite_DeleteAndFreeResources(SLOT(p, 0x93c));
        }
    }
    {
        u8 *p;
        int i;
        i = 0;
        p = work;
        for (; i < 6; i++, p += 4) {
            Sprite_DeleteAndFreeResources(SLOT(p, 0x954));
        }
    }
    ov89_0225A354((u8 *)work + 0x19c0);
}

void ov89_02259734(Ov89WorkHead *work, NARC *narc) {
    int i;
    SpriteSystem_LoadPaletteBufferFromOpenNarc(work->palette, (PaletteBufferId)3, work->spriteSystem, work->spriteManager, narc, 10, FALSE, 1, 2, 0x2714);
    SpriteSystem_LoadCharResObjFromOpenNarc(work->spriteSystem, work->spriteManager, narc, 9, FALSE, 2, 0x2719);
    SpriteSystem_LoadCellResObjFromOpenNarc(work->spriteSystem, work->spriteManager, narc, 8, FALSE, 0x2714);
    SpriteSystem_LoadAnimResObjFromOpenNarc(work->spriteSystem, work->spriteManager, narc, 7, FALSE, 0x2714);
    for (i = 0; i < 8; i++) {
        SpriteSystem_LoadCharResObjFromOpenNarc(work->spriteSystem, work->spriteManager, narc, 13, FALSE, 2, 0x271a + i);
    }
    SpriteSystem_LoadCellResObjFromOpenNarc(work->spriteSystem, work->spriteManager, narc, 12, FALSE, 0x2715);
    SpriteSystem_LoadAnimResObjFromOpenNarc(work->spriteSystem, work->spriteManager, narc, 11, FALSE, 0x2715);
}
