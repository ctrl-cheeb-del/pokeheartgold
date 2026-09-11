#ifndef TO40_OPUS_R4_OVERLAY14_RESIDUAL57_PRIVATE_H
#define TO40_OPUS_R4_OVERLAY14_RESIDUAL57_PRIVATE_H

#include "global.h"

/* House style borrowed verbatim from include/overlay_14_sol_partial_internal.h */
#define U8_AT(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U16_AT(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32_AT(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))

typedef struct {
    u32 pid;      /* 0x00 */
    u16 species;  /* 0x04 */
    u16 item;     /* 0x06 */
    u32 unk08;    /* 0x08 */
    u16 unk0c;    /* 0x0c */
    u8 ability;   /* 0x0e */
    u8 nature;    /* 0x0f */
    u16 unk10;    /* 0x10 */
    u8 level : 7; /* 0x12 */
    u8 empty : 1;
    u8 markKind : 7; /* 0x13 */
    u8 marked : 1;
    u16 moves[4]; /* 0x14 */
} BoxMonView;

typedef struct {
    u8 page : 4;
    u8 loaded : 3;
    u8 unk7 : 1;
} BoxFlags;

#define FLAGS44E(q) (*(BoxFlags *)((u8 *)(q) + 0x44e))

typedef struct {
    u16 msgId;
    u16 kind;
} BoxMenuEntry;

extern const u8 ov14_021F8080[];
extern const u8 ov14_021F84B4[];

/* ---- heap / string / message ---- */
extern void Heap_Free(void *);
extern void *Heap_AllocAtEnd(u32, u32);
extern void *String_New(u32, u32);
extern void String_Delete(void *);
extern void *NewString_ReadMsgData(void *, u32);
extern void StringExpandPlaceholders(void *, void *, void *);
extern void DestroyMsgData(void *);
extern void *NewMsgDataFromNarc(u32, u32, u32, u32);
extern void BufferIntegerAsString(void *, u32, s32, u32, u32, u32);
extern void BufferBoxMonSpeciesName(void *, u32, u32);
extern void BufferBoxMonNickname(void *, u32, u32);
extern void BufferNatureName(void *, u32, u32);
extern void BufferAbilityName(void *, u32, u32);
extern void BufferItemName(void *, u32, u32);
extern void GetItemNameIntoString(void *, u32, u32);
extern void GetItemDescIntoString(void *, u32, u32);

/* ---- window / bg ---- */
extern void InitWindow(void *);
extern void RemoveWindow(void *);
extern void AddWindow(void *, void *, const void *);
extern void AddWindowParameterized(void *, void *, u32, u32, u32, u32, u32, u32, u32);
extern void AddTextWindowTopLeftCorner(void *, void *, u32, u32, u32, u32);
extern void FillWindowPixelBuffer(void *, u32);
extern void ScheduleWindowCopyToVram(void *);
extern void CopyWindowToVram(void *);
extern void CopyWindowPixelsToVram_TextMode(void *);
extern void ClearWindowTilemapAndScheduleTransfer(void *);
extern u32 GetWindowBgId(void *);
extern u32 GetWindowX(void *);
extern u32 GetWindowY(void *);
extern s32 GetWindowWidth(void *);
extern s32 GetWindowHeight(void *);
extern void BlitBitmapRect(void *, void *, u16, u16, u16, u16, u16, u16, u16, u16, u16);

/* ---- font / text ---- */
extern void *FontSystem_NewInit(u32, u32);
extern void FontID_Alloc(u32, u32);
extern void FontID_Release(u32);
extern u32 FontID_String_GetWidth(u32, void *, u32);
extern u32 FontID_String_GetWidthMultiline(u32, void *, u32);
extern void AddTextPrinterParameterizedWithColor(void *, u32, void *, s32, s32, u32, u32, void *);
extern void TextOBJ_SetSpritesDrawFlag(void *, u32);
extern void TextOBJ_CopyFromBGWindow(void *, void *, void *, u32);
extern void FontOAM_Delete(void *);
extern void *SpriteManager_GetSpriteList(void *);
extern void *SpriteManager_FindPlttResourceProxy(void *, u32);
extern void *sub_02013910(void *, u32);
extern void sub_02013938(void *);
extern void *sub_02013688(void *, u32, u32);
extern void sub_02021AC8(void *, u32, u32, void *);
extern void sub_02021B5C(void *);
extern void *sub_020135D8(void *);
extern void sub_020135AC(void *);
extern void sub_020138B0(void *, u32);
extern void sub_020138E0(void *, u32);
extern void sub_020137F0(void *, u32);
extern void sub_0200CDAC(void *, u32, void *, u32, u32);

/* ---- graphics loader ---- */
extern void *GfGfxLoader_GetCharData(u32, s32, u32, void *, u32);

/* ---- storage / pokemon ---- */
extern void *PCStorage_GetMonByIndexPair(void *, u32, u32);
extern u32 AcquireBoxMonLock(void *);
extern u32 ReleaseBoxMonLock(void *, u32);
extern u32 GetBoxMonData(void *, u32, void *);
extern s32 GetMonBaseStatEx_HandleAlternateForm(void *, s32, s32, s32);
extern void PCStorage_GetBoxName(void *, u32, void *);
extern s32 PCStorage_CountMonsAndEggsInBox(void *, u32);
extern u32 PCStorage_IsBonusWallpaperUnlocked(void *, u32);
extern u32 SaveArray_IsNatDexEnabled(void *);
extern u32 Pokedex_ConvertToCurrentDexNo(u32, u32);

/* ---- sprites / overlay 14 neighbours ---- */
extern void ManagedSprite_SetPositionXY(void *, s32, s32);
extern void ManagedSprite_GetPositionXY(void *, s16 *, s16 *);
extern void ov14_021F2C1C(void *, u32, void *, u32);
extern void ov14_021F2A18(void *, u32, u32);
extern void ov14_021F2A60(void *, u32, u32);
extern void ov14_021F29E4(void *, u32, u32);
extern void ov14_021F46F4(void *);
extern void *ov14_021F6628(void);
extern void sub_02019B44(void *, u32, u16 *, u16 *);
extern void sub_020199F4(void *, u32, u32, u32, u32, u32, u32);

#endif
