#ifndef POKEHEARTGOLD_OVERLAY40_PARTY_SPRITES_R30_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY40_PARTY_SPRITES_R30_PRIVATE_H

#include "global.h"

typedef struct Ov40PartySpriteWork {
    u8 raw[0x864];
} Ov40PartySpriteWork;

typedef struct Ov40PartySpriteData {
    u8 pad00[0x2c];
    u16 species[30];
    u8 pad68[0x24c];
    void *sprites[30];
} Ov40PartySpriteData;

extern void ManagedSprite_SetDrawFlag(void *, int);
extern void SpriteManager_UnloadPlttObjById(void *, int);
extern void SpriteManager_UnloadCellObjById(void *, int);
extern void SpriteManager_UnloadAnimObjById(void *, int);
extern void SpriteManager_UnloadCharObjById(void *, int);
extern void Sprite_DeleteAndFreeResources(void *);
extern void Pokepic_SetAttr(void *, int, int);

void ov40_022373E4(Ov40PartySpriteWork *work, int draw);
void ov40_02237410(Ov40PartySpriteWork *work);
void ov40_02237548(Ov40PartySpriteWork *work, int value);

#endif
