#include "overlay95_sprite_resources_r5_private.h"

void ov95_021E5EF8(Ov95R5Work *work) {
    struct Ov95R5Files {
        u32 file[8];
    } files = *(const struct Ov95R5Files *)ov95_021E7594;
    SpriteSystem *system = work->spriteSystem;
    SpriteManager *manager = work->spriteManager;
    PaletteData *palette = work->paletteData;

    SpriteSystem_LoadCharResObj(system, manager, (NarcId)0x73, files.file[0], TRUE, NNS_G2D_VRAM_TYPE_2DMAIN, 0x4E20);
    SpriteSystem_LoadPaletteBuffer(palette, PLTTBUF_MAIN_OBJ, system, manager, (NarcId)0x73, files.file[1], FALSE, 1, NNS_G2D_VRAM_TYPE_2DMAIN, 0x4E21);
    SpriteSystem_LoadCellResObj(system, manager, (NarcId)0x73, files.file[2], TRUE, 0x4E22);
    SpriteSystem_LoadAnimResObj(system, manager, (NarcId)0x73, files.file[3], TRUE, 0x4E23);
    SpriteSystem_LoadCharResObj(system, manager, (NarcId)0x73, 7, TRUE, NNS_G2D_VRAM_TYPE_2DMAIN, 0x61A8);
    SpriteSystem_LoadPaletteBuffer(palette, PLTTBUF_MAIN_OBJ, system, manager, (NarcId)0x73, 10, FALSE, 1, NNS_G2D_VRAM_TYPE_2DMAIN, 0x61A9);
    SpriteSystem_LoadCellResObj(system, manager, (NarcId)0x73, 6, TRUE, 0x61AA);
    SpriteSystem_LoadAnimResObj(system, manager, (NarcId)0x73, 5, TRUE, 0x61AB);
}
