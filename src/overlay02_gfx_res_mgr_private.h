#ifndef OVERLAY_02_02248728_PRIVATE_H
#define OVERLAY_02_02248728_PRIVATE_H

#include "global.h"

#include "filesystem.h"
#include "sprite.h"
#include "unk_02009D48.h"
#include "unk_0200A090.h"

typedef struct ResSlot {
    s16 id;
    s16 unk2;
    SpriteResource *res;
} ResSlot;

typedef struct GfxWork {
    u8 charCount;            // 000
    u8 plttCount;            // 001
    u8 cellCount;            // 002
    u8 animCount;            // 003
    s8 charNone;             // 004
    s8 plttNone;             // 005
    s8 cellNone;             // 006
    s8 animNone;             // 007
    SpriteList *list;        // 008
    u8 renderer[0x128];      // 00C
    GF_2DGfxResMan *charMan; // 134
    GF_2DGfxResMan *plttMan; // 138
    GF_2DGfxResMan *cellMan; // 13C
    GF_2DGfxResMan *animMan; // 140
    ResSlot *charRes;        // 144
    ResSlot *plttRes;        // 148
    ResSlot *cellRes;        // 14C
    ResSlot *animRes;        // 150
} GfxWork;

extern void *ov02_0224B690(u32 heapId, u32 size);
extern void Heap_Free(void *ptr);
extern void GF_AssertFail(void);
extern void SpriteTransfer_DeleteCharTransferTask(SpriteResource *res);
extern void SpriteTransfer_DeletePlttTransferTask(SpriteResource *res);
extern void SpriteTransfer_CreateCharTransferTask_AllocAtEnd(SpriteResource *res);
extern void SpriteTransfer_CreatePlttTransferTask(SpriteResource *res);

void ov02_02248728(GfxWork *work, int numSprites, int numChar, int numPltt, int numCell, int numAnim, int charNone, int plttNone, int cellNone, int animNone);
void ov02_0224886C(GfxWork *work);
void ov02_02248980(GfxWork *work, NARC *narc, int fileId, int id);
void ov02_022489F0(GfxWork *work, int id);
void ov02_02248A24(GfxWork *work, int id);
void ov02_02248A58(GfxWork *work, NARC *narc, int fileId, int id);
void ov02_02248AC8(GfxWork *work, int id);
void ov02_02248AFC(GfxWork *work, int id);
void ov02_02248B30(GfxWork *work, NARC *narc, int fileId, int id);
void ov02_02248BA0(GfxWork *work, NARC *narc, int fileId, int id);
Sprite *ov02_02248C10(GfxWork *work, const VecFx32 *pos, int charId, int plttId, int cellId, int animId, int priority, u32 drawPriority);

#endif // OVERLAY_02_02248728_PRIVATE_H
