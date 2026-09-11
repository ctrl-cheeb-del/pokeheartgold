#ifndef SOL40_R35_PRIVATE_H
#define SOL40_R35_PRIVATE_H
#include "global.h"
#pragma require_prototypes off
#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
void *ListMenuItems_New(int, int);
void ListMenuItems_AppendFromMsgData(void *, void *, int, int);
void ListMenuItems_Delete(void *);
void *SpriteResourceCollection_Find(void *, int);
int GetItemIndexMapping(int, int);
void ReplaceCharResObjFromNarc(void *, void *, int, int, int, int);
void ReplacePlttResObjFromNarc(void *, void *, int, int, int, int);
void SpriteTransfer_ReplaceCharData(void *);
void SpriteTransfer_ReplacePlttData(void *);
void SpriteTransfer_DeleteCharTransferTask(void *);
void SpriteTransfer_DeletePlttTransferTask(void *);
void Destroy2DGfxResObjMan(void *);
void SpriteList_Delete(void *);
typedef struct {
    u32 v[4];
} SolXferTemplate;
extern SolXferTemplate ov83_0224817C;
void ObjCharTransfer_InitEx(void *, int, u32);
void *NARC_New(int, int);
void NARC_Delete(void *);
void *AddCharResObjFromOpenNarc(void *, void *, int, int, int, int, int);
void *AddPlttResObjFromNarc(void *, int, int, int, int, int, int, int);
void *AddCellOrAnimResObjFromOpenNarc(void *, void *, int, int, int, int, int);
#endif
