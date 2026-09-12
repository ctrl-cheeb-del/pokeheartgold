#ifndef OV70_RESIDUAL_19_PRIVATE_H
#define OV70_RESIDUAL_19_PRIVATE_H

#include "global.h"

typedef struct Ov70Sub {
    u8 pad00[8];
    void *unk08;
    void *unk0C;
    u8 pad10[0x24 - 0x10];
    void *unk24;
} Ov70Sub;

typedef struct Ov70Work {
    Ov70Sub *unk00;
    void *bgConfig;
    u8 pad08[0x24 - 0x08];
    u32 field24;
    u8 pad28[0x2c - 0x28];
    u32 state2c;
    u32 field30;
    u8 pad34[0x120 - 0x34];
    u16 field120;
    u16 field122;
    u8 pad124[0x128 - 0x124];
    u32 field128;
    s32 field12C;
    u8 pad130[0x350 - 0x130];
    u8 array350[0xb9c - 0x350];
    void *ptrB9C;
    void *msgDataBA0;
    u8 padBA4[0xbb4 - 0xba4];
    void *strBB4;
    void *strBB8;
    void *strBBC;
    u8 padBC0[0xbf0 - 0xbc0];
    u32 printerBF0;
    u8 padBF4[0xd60 - 0xbf4];
    u8 fieldD60[0xdcc - 0xd60];
    void *spriteDCC;
    u8 padDD0[0xdd8 - 0xdd0];
    void *spritesDD8[30];
    void *spritesE50[30];
    void *spritesEC8[6];
    u8 padEE0[4];
    void *spritesEE4[8];
    void *spritesF04[2];
    u8 padF0C[4];
    void *spriteF10;
    s32 valueF14;
    u8 windowF18[0xf48 - 0xf18];
    u8 windowF48[0xf68 - 0xf48];
    u8 windowF68[0x1158 - 0xf68];
    u8 window1158[0x1198 - 0x1158];
    u8 window1198[0x11c0 - 0x1198];
    s32 field11C0;
    u8 pad11C4[0x11de - 0x11c4];
    u16 field11DE;
    u8 pad11E0[0x11f4 - 0x11e0];
    void *ptr11F4;
} Ov70Work;

typedef struct Ov70Gm {
    u32 gm[4];
} Ov70Gm;

typedef struct Ov70Bt {
    u32 bt[7];
} Ov70Bt;

typedef struct Ov70SprTmpl {
    u8 pad00[8];
    u32 x;
    u32 y;
    u8 pad10[0x24 - 0x10];
    u32 field24;
    u8 pad28[0x30 - 0x28];
} Ov70SprTmpl;

typedef struct Ov70Key {
    s16 field00;
    s8 field02;
    s8 field03;
    s8 field04;
} Ov70Key;

typedef struct Ov70Sys {
    u8 pad00[0x48];
    u32 newKeys;
} Ov70Sys;

extern Ov70Sys gSystem;

extern int (*const ov70_022465A8[])(Ov70Work *);
extern const Ov70Gm ov70_022456F0;
extern const Ov70Bt ov70_02245714;
extern const Ov70Bt ov70_02245730;
extern const Ov70Bt ov70_0224574C;
extern const Ov70Bt ov70_02245768;
extern const u16 ov70_02245784[];
extern const u16 ov70_02245786[];
extern const u16 ov70_022456E8[];
extern const u8 ov70_02245804[][4];
extern const u8 ov70_02245884[];

/* engine / library */
int IsPaletteFadeFinished(void);
void BeginNormalPaletteFade(int, int, int, int, int, int, int);
void SetBothScreensModesAndDisable(const void *);
void InitBgFromTemplate(void *, int, const void *, int);
void BgClearTilemapBufferAndCommit(void *, int);
void FreeBgTilemapBuffer(void *, int);
void BG_ClearCharDataRange(int, int, int, int);
void GfGfx_EngineATogglePlanes(int, int);
void GfGfx_EngineBTogglePlanes(int, int);
void BgSetPosTextAndCommit(void *, int, int, int);
void BgTilemapRectChangePalette(void *, int, int, int, int, int, int);
void BgCommitTilemapBufferToVram(void *, int);
void LoadFontPal1(int, int, int);
int Options_GetFrame(void *);
void LoadUserFrameGfx2(void *, int, int, int, u8, int);
void LoadUserFrameGfx1(void *, int, int, int, int, int);
void AddWindowParameterized(void *, void *, int, int, int, int, int, int, int);
void FillWindowPixelBuffer(void *, int);
void CopyWindowToVram(void *);
void RemoveWindow(void *);
void DrawFrameAndWindow2(void *, int, int, int);
u32 AddTextPrinterParameterized(void *, int, void *, int, int, int, int);
BOOL TextPrinterCheckActive(u8);
void *String_New(int, int);
void String_Delete(void *);
void *NewString_ReadMsgData(void *, int);
void ReadMsgDataIntoString(void *, int, void *);
void BufferBoxMonNickname(void *, int, void *);
void *NARC_New(int, int);
void NARC_Delete(void *);
void GfGfxLoader_GXLoadPalFromOpenNarc(void *, int, int, int, int, int);
void GfGfxLoader_LoadCharDataFromOpenNarc(void *, int, void *, int, int, int, int, int);
void GfGfxLoader_LoadScrnDataFromOpenNarc(void *, int, void *, int, int, int, int, int);
void *Heap_Alloc(int, int);
void Heap_Free(void *);
void PlaySE(u16);
void *Sprite_CreateAffine(void *);
void Sprite_Delete(void *);
void Sprite_SetAnimActiveFlag(void *, int);
void Sprite_SetAnimCtrlSeq(void *, int);
void Sprite_SetPriority(void *, int);
void Sprite_SetDrawFlag(void *, int);
int TouchscreenHitbox_FindRectAtTouchNew(const void *);
void sub_0203A930(void);
void sub_0203A914(void);

/* overlay 70 */
void ov70_02238B54(void *, Ov70Work *, void *, int);
void ov70_02238D84(Ov70Work *, int, int);
void ov70_02238D8C(void *, int, int);
void ov70_02238E44(Ov70Work *);
void ov70_02238E50(Ov70Work *, int, int);
void ov70_02238E58(Ov70Work *);
void ov70_02238F9C(void *, int, int);
void ov70_022391F0(void *, int, int);
void ov70_022392BC(void *);
void ov70_02239C6C(Ov70Work *);
void ov70_02239CF8(Ov70Work *);
void ov70_02239D44(Ov70Work *, int);
int ov70_02241164(u32);
void ov70_02241358(Ov70Work *);
void ov70_02241380(Ov70Work *);
void ov70_02245084(void *, void *, int, int, int, int);
void ov70_022450B8(void *, void *, int, int, int, int);
void ov70_02245124(Ov70Work *);
void ov70_0223E01C(Ov70Work *, int, int, int, int, int);
void ov70_0223E264(Ov70Work *, int);
void *ov70_0223E49C(void *, void *, int, int);
int ov70_0223E4DC(void *, void *, int, int);
int ov70_0223E5C8(void *, void *, int, int);
int ov70_0223E658(void *, void *);
int ov70_0223D924(int, int, int);

int ov70_0223C930(Ov70Work *work);
int ov70_0223C958(Ov70Work *work);
int ov70_0223C978(Ov70Work *work);
int ov70_0223C9AC(Ov70Work *work);
int ov70_0223CA18(Ov70Work *work);
int ov70_0223CA40(Ov70Work *work);
void ov70_0223CAC4(Ov70Work *work, int msgId, int color, int a, int b);
void ov70_0223CB1C(void *a, void *b, void *msgData);
void ov70_0223CC04(void *bgConfig, void *window, void *msgData, int flag);
int ov70_0223CC68(const Ov70Key *a, const Ov70Key *b, int c, int d);
void ov70_0223CCA4(Ov70Work *work);
void ov70_0223CD28(int value);
int ov70_0223CD44(Ov70Work *work);
void ov70_0223CDD8(Ov70Work *work);
int ov70_0223CDF8(Ov70Work *work);
void ov70_0223CE44(void *bgConfig);
void ov70_0223CF48(void *bgConfig);
void ov70_0223CF74(Ov70Work *work);
void ov70_0223D058(Ov70Work *work);
void ov70_0223D208(Ov70Work *work);
void ov70_0223D26C(Ov70Work *work);
void ov70_0223D378(Ov70Work *work);
void ov70_0223D3BC(Ov70Work *work);
void ov70_0223D414(Ov70Work *work);
int ov70_0223D44C(Ov70Work *work);
void ov70_0223D490(Ov70Work *work);
void ov70_0223D588(Ov70Work *work);
int ov70_0223D680(void);
void ov70_0223D690(Ov70Work *work, int code);
int ov70_0223D6C8(Ov70Work *work);
void ov70_0223D808(Ov70Work *work);
void ov70_0223D8E8(void *sprite, int index);

#endif
