#ifndef POKEHEARTGOLD_OVERLAY81_SPRITE_GRAPHICS_R16_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY81_SPRITE_GRAPHICS_R16_PRIVATE_H

#include "global.h"

#include "obj_char_transfer.h"
#include "pokemon.h"
#include "pokepic.h"
#include "sprite.h"
#include "sprite_transfer.h"
#include "unk_0200A090.h"

typedef struct Ov81SpriteWorkR16 {
    SpriteList *spriteList;
    u8 rendererAndPadding[0x128];
    GF_2DGfxResMan *resourceManagers[4];
    SpriteResource *resourceObjects[6][4];
} Ov81SpriteWorkR16;

void OamManager_Free(void);
void ObjPlttTransfer_Destroy(void);
void ObjPlttTransfer_Init(int, enum HeapID);
void ObjPlttTransfer_Reset(void);
void Thunk_G3X_Reset(void);
void NNS_G3dGlbFlushP(void);
void NNS_G2dSetupSoftwareSpriteCamera(void);
void GfGfx_EngineATogglePlanes(int, int);
void GfGfx_EngineBTogglePlanes(int, int);
void NNS_G2dInitOamManagerModule(void);
void OamManager_Create(int, int, int, int, int, int, int, int, enum HeapID);
extern const ObjCharTransferTemplate ov81_02243598;
extern const u8 ov81_02243594[4];
int sub_02074490(void);

void ov81_0224276C(Ov81SpriteWorkR16 *work);
Sprite *ov81_02242A8C(Ov81SpriteWorkR16 *work, int resourceId, int animSeq, int drawPriority, int priority, u8 screen);
void ov81_02242B38(Ov81SpriteWorkR16 *work);
void ov81_02242B90(void);
void ov81_02242BC8(void);
void ov81_02242C48(PokepicManager *manager);
Pokepic *ov81_02242C80(PokepicManager *manager, int polygonId, Pokemon *mon, int x, int y, int z);

#endif
