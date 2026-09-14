#ifndef OVERLAY18_SPRITE_RESOURCE_SETUP_R41_PRIVATE_H
#define OVERLAY18_SPRITE_RESOURCE_SETUP_R41_PRIVATE_H

#include "global.h"

#include "sprite.h"
#include "unk_02009D48.h"
#include "unk_0200A090.h"

void SpriteTransfer_CreateCharTransferTask_AllocAtEnd(SpriteResource *resource);
void SpriteTransfer_CreatePlttTransferTask(SpriteResource *resource);
void SpriteTransfer_DeleteCharTransferTask(SpriteResource *resource);
void SpriteTransfer_DeletePlttTransferTask(SpriteResource *resource);
void sub_0200A740(SpriteResource *resource);
int GF2DGfxResObj_GetResID(SpriteResource *resource);
void DestroySingle2DGfxResObj(GF_2DGfxResMan *manager, SpriteResource *resource);
int ov18_021F9688(void *value);

void ov18_021F922C(SpriteResource **resources, GF_2DGfxResMan **managers, enum HeapID heapId, NARC *narc, int charFileId, int plttFileId, int cellFileId, int animFileId, int plttNum, int charId, int plttId, int cellId, int animId);
SpriteResource *ov18_021F92AC(GF_2DGfxResMan *manager, enum HeapID heapId, NARC *narc, int fileId, int plttNum, int id);
void ov18_021F92DC(SpriteResource **resources, GF_2DGfxResMan **managers);
void ov18_021F9310(SpriteResource **resources, GF_2DGfxResMan **managers, SpriteResourcesHeader *header, int priority);
void ov18_021F9370(void *work);

#endif
