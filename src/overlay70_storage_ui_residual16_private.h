#ifndef OV70_RESIDUAL_16_PRIVATE_H
#define OV70_RESIDUAL_16_PRIVATE_H

#include "global.h"

typedef struct Ov70Root {
    u8 pad00[8];
    void *party;
    u8 pad0C[0x24 - 0x0C];
    void *options;
} Ov70Root;

typedef struct Ov70KeyInfo {
    s16 msgId;
    s8 kind;
    s8 value;
} Ov70KeyInfo;

typedef struct Ov70DisplayRecord {
    s16 msgId;
    s8 kind;
    s8 value;
} Ov70DisplayRecord;

typedef struct Ov70Work {
    Ov70Root *root;
    void *bgConfig;
    u8 pad08[0x24 - 0x08];
    u32 mode;
    u8 pad28[4];
    u32 state;
    u32 nextState;
    u8 pad34[0x12C - 0x34];
    s32 selected;
    u8 pad130[0x13C - 0x130];
    u8 field13C[0x22C - 0x13C];
    s16 field22C;
    s8 field22E;
    s8 field22F;
    s8 field230;
    u8 pad231[0x260 - 0x231];
    u8 records260[0x124 * 8];
    u8 recordsB80[0x1C];
    void *msgFmtB9C;
    void *msgDataBA0;
    void *stringBA4;
    u8 padBA8[0xBBC - 0xBA8];
    void *stringBBC;
    u8 padBC0[0xBF0 - 0xBC0];
    u32 printerBF0;
    u8 padBF4[0xEE0 - 0xBF4];
    void *spriteEE0;
    void *spritesEE4[8];
    u8 padF04[0xF10 - 0xF04];
    void *spriteF10;
    s32 offsetF14;
    u8 windowF18[0x30];
    u8 windowF48[0x10];
    u8 windowF58[0x10];
    u8 windowF68[0x1080 - 0xF68];
    u8 window1080[0x68];
    u8 window10E8[0x30];
    u8 window1118[0x20];
    u8 window1138[0x74];
    void *listItems11AC;
    u8 pad11B0[0x11C0 - 0x11B0];
    s32 timer11C0;
    u8 pad11C4[4];
    void *yesNo11C8;
    u8 pad11CC[4];
    void *touchMenu11D0;
    u8 pad11D4[0x11FC - 0x11D4];
    u32 flag11FC;
    u8 pad1200[8];
    void *callback1208;
    s16 spriteY120C[8];
} Ov70Work;

typedef struct Ov70BgTemplate {
    u32 words[7];
} Ov70BgTemplate;

typedef struct Ov70System {
    u8 pad00[0x48];
    u32 newKeys;
    u8 pad4C[0x64 - 0x4C];
    u16 touchNew;
} Ov70System;

extern Ov70System gSystem;
extern const Ov70BgTemplate ov70_022454B4;
extern const Ov70BgTemplate ov70_022454D0;
extern int (*const ov70_022464CC[])(Ov70Work *);
extern const u32 ov70_02245910[];
extern const u32 ov70_0224649C[];

void BeginNormalPaletteFade(int, int, int, int, int, int, int);
void PlaySE(u16);
void *ListMenuItems_New(int, int);
void ListMenuItems_AppendFromMsgData(void *, void *, int, int);
void ListMenuItems_Delete(void *);
int TouchscreenListMenu_HandleInput(void *);
void YesNoPrompt_Destroy(void *);
void ClearFrameAndWindow2(void *, int);
BOOL TextPrinterCheckActive(u8);
void *Mon_GetBoxMon(void *);
void BufferBoxMonSpeciesName(void *, int, void *);
void *NewString_ReadMsgData(void *, int);
void StringExpandPlaceholders(void *, void *, void *);
void FillWindowPixelBuffer(void *, int);
void DrawFrameAndWindow2(void *, int, int, int);
u32 AddTextPrinterParameterized(void *, int, void *, int, int, int, int);
void String_Delete(void *);
int Party_GetCount(void *);
void Sprite_SetDrawFlag(void *, int);
void InitBgFromTemplate(void *, int, const void *, int);
void BgClearTilemapBufferAndCommit(void *, int);
void BG_ClearCharDataRange(int, int, int, int);
int GXx_GetMasterBrightness_(volatile u16 *);
void GfGfx_EngineATogglePlanes(int, int);
void *Heap_Alloc(int, u32);
void Heap_Free(void *);
void GetPokemonSpriteCharAndPlttNarcIds(u16 *, void *, int);
u32 GetMonData(void *, int, void *);
void sub_02014494(u16, u16, int, int, int, int, int, void *, int, int, int, int);
void DC_FlushRange(const void *, u32);
void GX_LoadOBJ(const void *, u32, u32);
void GfGfxLoader_GXLoadPal(int, int, int, int, int, int);
void *String_New(int, int);
void CopyU16ArrayToString(void *, const u16 *);
void ov70_02245084(void *, void *, int, int, int, u32);
u32 GetBoxMonData(void *, int, void *);
void BufferIntegerAsString(void *, int, int, int, int, int);
void *ReadMsgData_ExpandPlaceholders(void *, void *, int, int);
void GetItemNameIntoString(void *, u16, int);

void *ov70_02238C14(void *, int, int, int, int);
int ov70_02238C8C(void);
void *ov70_02238CAC(Ov70Work *, int, int);
void ov70_02238D60(Ov70Work *);
void ov70_02238D84(Ov70Work *, int, int);
void ov70_02238E50(Ov70Work *, int, int);
void ov70_02238E58(Ov70Work *);
void ov70_02238F9C(void *, int, int);
void ov70_02238FB4(int);
BOOL ov70_0223E76C(void *);
int ov70_0223F864(int, int, int);
void ov70_0223F470(void *, void *, void *, void *, int, int, int);
void ov70_0223AE98(Ov70Work *);
void ov70_0223ABF4(Ov70Work *);
void ov70_0223ACF4(Ov70Work *);
void ov70_0223AC98(Ov70Work *);
void ov70_0223B3BC(void *, void *, int);
void ov70_0223B3EC(void *, void *, int);
void ov70_0223B258(Ov70Work *);
void ov70_02241330(Ov70Work *, int, int);
void ov70_0223B4D4(void);
void ov70_0223ACE4(Ov70Work *);
void ov70_0223AF30(Ov70Work *);
void ov70_0223AE40(Ov70Work *);
void ov70_0223ABD8(void *);
void ov70_022391F0(void *, int, int);

int ov70_0223A260(Ov70Work *);
int ov70_0223A2D0(Ov70Work *);
int ov70_0223A2F8(Ov70Work *);
int ov70_0223A324(Ov70Work *);
int ov70_0223A384(Ov70Work *);
int ov70_0223A3DC(Ov70Work *);
int ov70_0223A4A0(Ov70Work *);
int ov70_0223A4C0(Ov70Work *);
void ov70_0223A4F4(Ov70Work *, int, int, int, u32, void *);
void ov70_0223A578(void *, void *, void *, void *, void *, const Ov70DisplayRecord *);
void ov70_0223A72C(void *, void *, const u16 *, void *, void *);
void ov70_0223A7E4(void *);
void ov70_0223A874(Ov70Work *);
int ov70_0223A8BC(Ov70Work *);
int ov70_0223AA90(Ov70Work *);
int ov70_0223AB00(Ov70Work *);
void ov70_0223AB3C(void *, int);

#endif
