#ifndef TO47_OPUS_R5_OVERLAY_70_RESIDUAL_21_PRIVATE_H
#define TO47_OPUS_R5_OVERLAY_70_RESIDUAL_21_PRIVATE_H

#include "global.h"

#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))

typedef struct Ov70MonGfx {
    u32 offset;
    void *palette;
    void *sprite;
    u8 buf[0x200];
} Ov70MonGfx;

typedef struct Ov70Work {
    void *sub;
    u8 pad0004[0x24 - 0x04];
    u32 mode;
    u8 pad0028[0x12c - 0x28];
    u32 index;
    u8 pad0130[0xba0 - 0x130];
    void *msgData;
    u8 pad0ba4[0xbb4 - 0xba4];
    void *str;
    u8 pad0bb8[0xdd8 - 0xbb8];
    void *spritesA[30];
    void *spritesB[30];
    void *spritesC[6];
    u8 pad0ee0[0xf48 - 0xee0];
    u8 window[0x11f4 - 0xf48];
    struct Ov70BoxEntry *entries;
    u8 pad11f8[0x1200 - 0x11f8];
    struct Ov70MonGfx *gfx;
    void *callback;
} Ov70Work;

typedef struct Ov70BoxEntry {
    u16 species;
    u8 unk2;
    u8 unk3;
} Ov70BoxEntry;

void DC_FlushRange(const void *ptr, u32 size);
void GX_LoadOBJ(const void *pSrc, u32 offset, u32 szByte);
void Sprite_SetPaletteOverride(void *sprite, void *pltt);
void Sprite_SetDrawFlag(void *sprite, int flag);
void Sprite_SetAnimCtrlSeq(void *sprite, int seq);
void Heap_Free(void *ptr);
void *Heap_AllocAtEnd(int heapId, u32 size);
void *NARC_New(int narcId, int heapId);
void NARC_Delete(void *narc);
int AcquireBoxMonLock(void *boxmon);
void ReleaseBoxMonLock(void *boxmon, int lock);
u32 GetBoxMonData(void *boxmon, int field, void *dest);
u32 GetMonData(void *mon, int field, void *dest);
int ItemIdIsMail(u16 item);
void *PCStorage_GetMonByIndexPair(void *pcStorage, int box, int slot);
void PCStorage_GetBoxName(void *pcStorage, int box, void *dst);
int Party_GetCount(void *party);
void *Party_GetMonByIndex(void *party, int slot);
void *Mon_GetBoxMon(void *mon);
void ReadMsgDataIntoString(void *msgData, u32 msgId, void *dst);
void FillWindowPixelBuffer(void *window, u8 fillValue);

void ov70_0223E0BC(int species, u32 a2, u32 a3, int a4, void *a5, void *a6, Ov70MonGfx *a7);
void ov70_0223E114(void *boxmon, u8 *dest);
void ov70_0223E738(void *a1, void *a2, void *a3, void *a4);
void ov70_02245084(void *window, void *str, int a3, int a4, int a5, u32 a6);

void ov70_0223E120(Ov70Work *w);
void ov70_0223E170(void *boxmon, void *spriteA, void *spriteB, u16 *species, int index, void *narc, Ov70BoxEntry *entry, Ov70MonGfx *gfx);
void ov70_0223E264(Ov70Work *w, int box);

#endif
