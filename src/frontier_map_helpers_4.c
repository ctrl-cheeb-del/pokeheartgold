#include "frontier_map_helpers_internal.h"

void ov80_0223937C(void *vramMan) {
    GF_3DVramMan_Delete(vramMan);
}

void ov80_02239384(FrontierMap *m) {
    m->unk34 = SpriteSystem_Alloc(0x65);
    SpriteSystem_Init(m->unk34, ov80_0223D5B8, ov80_0223D570, 0x20);
    G2dRenderer_SetObjCharTransferReservedRegion(1, 0x00200010);
    G2dRenderer_SetPlttTransferReservedRegion(1);
    m->unk38 = SpriteManager_New(m->unk34);
    SpriteSystem_InitSprites(m->unk34, m->unk38, 0x80);
    SpriteSystem_InitManagerWithCapacities(m->unk34, m->unk38, ov80_0223D584);
    G2dRenderer_SetSubSurfaceCoords(SpriteSystem_GetRenderer(m->unk34), 0, 2 << 20);
}
