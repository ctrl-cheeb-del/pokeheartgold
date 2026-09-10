#ifndef PRIVATE_OVERLAY_80_02239AF8_H
#define PRIVATE_OVERLAY_80_02239AF8_H

#include "global.h"

typedef struct Overlay80SpriteResource {
    u8 padding_00[0x14];
    u32 charId;
    u32 paletteId;
    u32 cellId;
    u32 animId;
    u8 padding_24[0x10];
} Overlay80SpriteResource;

extern const Overlay80SpriteResource ov80_0223DA54[4];

void GF_AssertFail(void);
void SpriteManager_UnloadCharObjById(void *manager, u32 id);
void SpriteManager_UnloadPlttObjById(void *manager, u32 id);
void SpriteManager_UnloadCellObjById(void *manager, u32 id);
void SpriteManager_UnloadAnimObjById(void *manager, u32 id);
void *SpriteSystem_NewSprite(void *system, void *manager, const void *template);
void Sprite_TickFrame(void *sprite);
void Sprite_DeleteAndFreeResources(void *sprite);
void SpriteSystem_LoadCharResObjFromOpenNarc(void *system, void *manager, void *narc, u32 member, u32 compressed, u32 vramType, u32 resourceId);
void SpriteSystem_LoadPaletteBufferFromOpenNarc(void *paletteData, u32 bufferId, void *system, void *manager, void *narc, u32 member, u32 compressed, u32 count, u32 vramType, u32 resourceId);
void SpriteSystem_LoadCellResObjFromOpenNarc(void *system, void *manager, void *narc, u32 member, u32 compressed, u32 resourceId);
void SpriteSystem_LoadAnimResObjFromOpenNarc(void *system, void *manager, void *narc, u32 member, u32 compressed, u32 resourceId);

void ov80_02239AF8(void *narc, void *system, void *manager, void *paletteData, u16 index);
void ov80_02239B7C(void *manager, u32 index);
void *ov80_02239BB8(void *system, void *manager, u32 index);
void ov80_02239BE8(void *sprite);

#endif
