#ifndef PRIVATE_OVERLAY_01_021EB1E8_H
#define PRIVATE_OVERLAY_01_021EB1E8_H

#include "global.h"

typedef struct WeatherRec {
    /* 0x00 */ u16 unk00;
    /* 0x02 */ s16 unk02;
    /* 0x04 */ u32 unk04;
    /* 0x08 */ void *unk08;
    /* 0x0C */ void *unk0C;
    /* 0x10 */ u16 unk10;
    /* 0x12 */ u16 unk12;
    /* 0x14 */ void *unk14;
    /* 0x18 */ void (*unk18)(int, void *);
} WeatherRec; /* 0x1C */

typedef struct WeatherGfx {
    /* 0x00 */ void *unk00;
    /* 0x04 */ void *unk04;
    /* 0x08 */ void *unk08;
    /* 0x0C */ void *unk0C;
} WeatherGfx;

typedef struct WeatherSys {
    /* 0x000 */ WeatherRec *recs;
    /* 0x004 */ const u32 (*sfx)[3];
    /* 0x008 */ void *unk08;
    /* 0x00C */ void *unk0C;
    /* 0x010 */ void *unk10;
    /* 0x014 */ void *unk14;
    /* 0x018 */ void *unk18;
    /* 0x01C */ u8 unk1C[0xF4 - 0x1C];
    /* 0x0F4 */ void *unkF4;
    /* 0x0F8 */ void *unkF8;
    /* 0x0FC */ void *unkFC;
    /* 0x100 */ void *unk100;
    /* 0x104 */ void *fieldSystem;
    /* 0x108 */ void *narc;
} WeatherSys; /* 0x10C */

typedef struct WeatherManager {
    /* 0x00 */ WeatherSys *sys;
    /* 0x04 */ int unk04;
    /* 0x08 */ int unk08;
    /* 0x0C */ int unk0C;
    /* 0x10 */ int unk10;
    /* 0x14 */ void *task;
} WeatherManager; /* 0x18 */

typedef struct WeatherLerp {
    /* 0x00 */ int cur;
    /* 0x04 */ int start;
    /* 0x08 */ int delta;
    /* 0x0C */ int t;
    /* 0x10 */ int dur;
} WeatherLerp;

typedef struct WeatherSpriteWork {
    /* 0x00 */ u32 unk00;
    /* 0x04 */ void *sprite;
    /* 0x08 */ u8 *unk08;
    /* 0x0C */ u8 unk0C[0x28];
    /* 0x34 */ struct WeatherSpriteWork *next;
    /* 0x38 */ struct WeatherSpriteWork *prev;
} WeatherSpriteWork; /* 0x3C */

typedef struct WeatherSpriteMgr {
    /* 0x00 */ u32 unk00;
    /* 0x04 */ u32 unk04;
    /* 0x08 */ u8 *unk08;
    /* 0x0C */ WeatherSpriteWork head;
    /* 0x48 */ WeatherSpriteWork works[0x40];
} WeatherSpriteMgr;

/* --- externs with no tracked definition reachable from global.h --- */
extern void *Heap_Alloc(int heapId, u32 size);
extern void Heap_Free(void *ptr);
extern void SysTask_Destroy(void *task);
extern void *SysTask_CreateOnMainQueue(void (*fn)(void *, void *), void *arg, u32 prio);
extern void GfGfx_EngineATogglePlanes(int mask, int on);
extern void SpriteList_RenderAndAnimateSprites(void *list);
extern void *GF2DGfxResHeader_GetByIndex(void *a0, int idx);
extern void *GfGfxLoader_LoadFromNarc(int narcId, int memberNo, int compressed, int heapId, int allocEnd);
extern void GF2DGfxResHeader_Init(void *data, void *hdr, int a2);
extern void *NARC_New(int narcId, int heapId);
extern void SpriteTransfer_DeleteCharTransferTask(void *p);
extern void SpriteTransfer_DeletePlttTransferTask(void *p);
extern void DestroySingle2DGfxResObj(void *a0, void *a1);
extern void SpriteTransfer_CreateCharTransferTask_AllocAtEnd(void *p);
extern void SpriteTransfer_CreatePlttTransferTask(void *p);
extern void sub_0200A740(void *p);
extern void *Sprite_CreateAffine(void *tmpl);
extern void Sprite_SetDrawFlag(void *sprite, int flag);
extern void Sprite_Delete(void *sprite);
extern VecFx32 *Sprite_GetMatrixPtr(void *sprite);
extern void GF_AssertFail(void);
extern void *ov01_021EB898(void *a0, int a1, int a2, void *a3, void *a4, int a5);
extern void ov01_021EB4B8(void *p);
extern void ov01_021EB68C(void *p);
extern BOOL ov01_021EBE4C(WeatherSys *sys, WeatherRec *rec);
extern void ov01_021EBD70(void *a0, void *a1);
extern void ov01_021EBFD0(WeatherSys *sys, WeatherRec *rec);

extern void ov01_021EC114(WeatherSys *sys, u16 idx);
extern void ov01_021EC8F8(int a0, void *a1);
extern void ov01_021EC94C(int a0, void *a1);
extern void ov01_021ECD08(int a0, void *a1);
extern void ov01_021ED0F0(int a0, void *a1);
extern void ov01_021ED584(int a0, void *a1);
extern void ov01_021ED710(int a0, void *a1);
extern void ov01_021ED924(int a0, void *a1);
extern void ov01_021EDA50(int a0, void *a1);

typedef struct WeatherEmit {
    /* 0x00 */ u32 unk00;
    /* 0x04 */ u16 unk04;
    /* 0x06 */ u16 unk06;
    /* 0x08 */ u16 unk08;
    /* 0x0A */ u16 unk0A;
    /* 0x0C */ u16 unk0C;
    /* 0x0E */ u16 unk0E;
    /* 0x10 */ u16 unk10;
    /* 0x12 */ u16 unk12;
    /* 0x14 */ u32 unk14;
    /* 0x18 */ u32 unk18;
} WeatherEmit;

typedef struct WeatherAnim {
    /* 0x00 */ void *unk00;
    /* 0x04 */ u8 unk04[0x20];
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s16 unk2C;
    /* 0x2E */ s16 unk2E;
} WeatherAnim;

extern BOOL ov01_021EB700(WeatherSys *sys, int a1, int a2);
extern void ov01_021EB320(void *a0, void *a1);
extern void ov01_021EB3F0(void *a0, void *a1);
extern void ov01_021EC4A8(void *a0, fx32 *px, fx32 *py);
typedef struct WeatherFade {
    /* 0x00 */ void *unk00;
    /* 0x04 */ WeatherLerp l1;
    /* 0x18 */ WeatherLerp l2;
    /* 0x2C */ WeatherLerp l3;
    /* 0x40 */ WeatherLerp l4;
    /* 0x54 */ WeatherLerp l5;
} WeatherFade; /* 0x68 */

extern BOOL ov01_021EC728(WeatherFade *p);
extern void ov01_021EA864(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void ov01_021EA89C(void *a0, int a1, int a2, int a3);
extern void ov01_021EA8C4(void *a0, void *a1);
extern BOOL ov01_021EC7E8(WeatherAnim *p);
extern void ov01_021EC828(WeatherAnim *p);
extern void PlaySE(u16 seqNo);
extern void StopSE(u16 seqNo, int a1);

typedef struct WeatherGfxMgr { /* lives at WeatherSys+8 */
    /* 0x00 */ void *objMan[4];
    /* 0x10 */ void *resHdr;
    /* 0x14 */ u8 pad14[0xF4 - 0x14];
    /* 0xF4 */ void *spriteList;
    /* 0xF8 */ void *task;
} WeatherGfxMgr;

extern void ov01_021ED474(void *p, u32 a1, int a2, int a3, int a4, int a5, int a6);
extern void GF2DGfxResHeader_Reset(void *hdr);
extern void Destroy2DGfxResObjMan(void *man);
extern void SpriteList_Delete(void *list);
extern void ov01_021EC240(void *a0, WeatherSys *sys, void *a2, int a3, int a4);

typedef struct WeatherSlow {
    /* 0x000 */ u8 _pad000[4];
    /* 0x004 */ void *unk04;
    /* 0x008 */ u8 _pad008[0xF62 - 8];
    /* 0xF62 */ u16 state;
    /* 0xF64 */ u16 unkF64;
    /* 0xF66 */ u16 sub;
} WeatherSlow;

extern void ov01_021EBCA4(void *p);

typedef struct WeatherFsys {
    /* 0x00 */ u8 _pad00[8];
    /* 0x08 */ void *bgConfig;
} WeatherFsys;

extern void *NARC_AllocAndReadWholeMember(void *narc, u32 member, u32 heap);
extern void BG_LoadPlttData(int bg, void *data, u32 size, u32 offset);
extern void BG_LoadCharTilesData(void *cfg, int bg, void *data, u32 size, u32 offset);
extern void ov01_021EC078(WeatherSys *sys, u16 idx);
extern void ov01_021EC0C0(WeatherSys *sys, u16 idx);

#endif
