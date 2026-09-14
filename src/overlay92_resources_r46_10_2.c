#include "overlay92_resources_r46_10_2_private.h"

#define LOAD_GROUP(narc, sys, mgr, pal, rid, cf, cv, cellf, animf, pf, pbuf, pnum, pvram)                                                      \
    do {                                                                                                                                       \
        SpriteSystem_LoadCharResObjFromOpenNarc((sys), (mgr), (narc), (cf), FALSE, (cv), (rid));                                               \
        SpriteSystem_LoadCellResObjFromOpenNarc((sys), (mgr), (narc), (cellf), FALSE, (rid));                                                  \
        SpriteSystem_LoadAnimResObjFromOpenNarc((sys), (mgr), (narc), (animf), FALSE, (rid));                                                  \
        SpriteSystem_LoadPaletteBufferFromOpenNarc((pal), (PaletteBufferId)(pbuf), (sys), (mgr), (narc), (pf), FALSE, (pnum), (pvram), (rid)); \
    } while (0)

void ov92_0225E3C4(void *work) {
    NARC *narc = PTR(work, 0x48);
    SpriteSystem *system = PTR(work, 0x50);
    SpriteManager *manager = PTR(work, 0x54);
    PaletteData *palette = PTR(work, 0x5c);

    LOAD_GROUP(narc, system, manager, palette, 0x2328, 0x54, 2, 0x53, 0x52, 0x55, 3, 0xd, 2);
    LOAD_GROUP(narc, system, manager, palette, 0x232b, 0x1d, 1, 0x1c, 0x1b, 0x1e, 2, 1, 1);
    LOAD_GROUP(narc, system, manager, palette, 0x232c, 0x0d, 1, 0x0c, 0x0b, 0x0e, 2, 1, 1);
    LOAD_GROUP(narc, system, manager, palette, 0x232d, 0x15, 1, 0x14, 0x13, 0x16, 2, 1, 1);
    LOAD_GROUP(narc, system, manager, palette, 0x232e, 0x11, 1, 0x10, 0x0f, 0x12, 2, 1, 1);
    LOAD_GROUP(narc, system, manager, palette, 0x232a, 0x19, 1, 0x18, 0x17, 0x1a, 2, 3, 1);
    narc = NARC_New(NARC_a_1_9_8, HEAP_ID_113);
    LOAD_GROUP(narc, system, manager, palette, 0x232f, 0x15, 1, 0x16, 0x17, 0x14, 2, 2, 1);
    NARC_Delete(narc);
}
