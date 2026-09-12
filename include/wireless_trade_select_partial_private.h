#ifndef WIRELESS_TRADE_SELECT_PARTIAL_PRIVATE_H
#define WIRELESS_TRADE_SELECT_PARTIAL_PRIVATE_H

#include "global.h"

#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))

typedef struct Ov65Banks {
    u32 words[10];
} Ov65Banks;

typedef struct Ov65WorkPartial {
    u8 pad_0000[0x79c];
    void *first[6];
    void *second[6];
    u8 pad_07cc[0x1a58];
    void *party1;
    void *party2;
} Ov65WorkPartial;

extern const Ov65Banks ov65_0221FE44;
extern int Party_GetCount(void *);
extern void *Party_GetMonByIndex(void *, u32);
extern void *Mon_GetBoxMon(void *);
extern void BufferBoxMonNickname(void *, u32, void *);
extern u32 GetMonIconPaletteEx(u32, u32, u32);
extern void Sprite_SetPalOffset(void *, u32);
extern void *ReadMsgData_ExpandPlaceholders(void *, void *, int, u32);
extern void ov65_0221FB4C(void *, void *, u32, u32, u32, u32);
extern void String_Delete(void *);
extern void SpriteTransfer_DeleteCharTransferTask(void *);
extern void SpriteTransfer_DeletePlttTransferTask(void *);
extern void Destroy2DGfxResObjMan(void *);
extern void SpriteList_Delete(void *);
extern void OamManager_Free(void);
extern void ObjCharTransfer_Destroy(void);
extern void ObjPlttTransfer_Destroy(void);
extern void Heap_Free(void *);
extern void GfGfx_SetBanks(const Ov65Banks *);
extern void FreeBgTilemapBuffer(void *, u32);

void ov65_0221BFBC(void *, u32, u32, u32, u32, void *);
void ov65_0221C3DC(void *, void *, u32);
void ov65_0221C414(void *, void *, void *, void *, int);
void ov65_0221CCB0(void *);
void ov65_0221CD0C(Ov65WorkPartial *);
void ov65_0221CE98(void);
void ov65_0221D1C8(void *);

#endif
