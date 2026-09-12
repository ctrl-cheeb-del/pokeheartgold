#ifndef OV70_RESIDUAL24_PRIVATE_H
#define OV70_RESIDUAL24_PRIVATE_H

#include "global.h"

typedef struct Ov70Root24 {
    u8 pad00[0x10];
    void *profile;
    u8 pad14[0x24 - 0x14];
    void *options;
} Ov70Root24;

typedef struct Ov70Work24 {
    Ov70Root24 *root;
    void *bgConfig;
    u8 pad08[0x2C - 8];
    u32 state;
    u8 pad30[0x124 - 0x30];
    void *field124;
    u8 pad128[0xB80 - 0x128];
    u8 recordB80[0x1C];
    void *msgFmt;
    void *msgData;
    void *stringBA4;
    u8 padBA8[0xBBC - 0xBA8];
    void *stringBBC;
    u8 padBC0[0xBF0 - 0xBC0];
    u32 printer;
    u8 padBF4[0xDD0 - 0xBF4];
    void *spriteDD0;
    u8 padDD4[0xF04 - 0xDD4];
    void *spriteF04;
    void *spriteF08;
    u8 padF0C[4];
    void *spriteF10;
    u8 padF14[4];
    u8 windowF18[0x40];
    u8 windowF58[0x100];
    u8 windows1058[6][0x10];
    u8 pad10B8[0x1168 - 0x10B8];
    void *ptr1168;
    u8 pad116C[0x11A8 - 0x116C];
    void *manager11A8;
    u8 pad11AC[0x11C4 - 0x11AC];
    void *ptr11C4;
} Ov70Work24;

typedef struct Ov70SpriteTemplate24 {
    u8 pad00[8];
    s32 x;
    s32 y;
    u8 pad10[0x30 - 0x10];
} Ov70SpriteTemplate24;

typedef struct Ov70BgTemplate24 {
    u32 words[7];
} Ov70BgTemplate24;

typedef int (*Ov70StateFunc24)(Ov70Work24 *);

typedef struct Ov70ManagerArgs24 {
    void *values[12];
} Ov70ManagerArgs24;

extern const Ov70BgTemplate24 ov70_02245938;
extern const Ov70BgTemplate24 ov70_02245954;
extern const Ov70BgTemplate24 ov70_02245970;
extern const Ov70BgTemplate24 ov70_0224598C;
extern const u16 ov70_02245920[][2];
extern Ov70StateFunc24 ov70_02246614[];

void ov70_0223ECCC(Ov70Work24 *);
void ov70_02245124(Ov70Work24 *);
void ov70_0223F3D8(void *, void *, void *, void *, int, int, int);
void ov70_0223F508(void *, void *, void *, void *, void *);
void *ov70_02242014(void *, int);
void ov70_02238E44(void);
void sub_0203A930(void);
void sub_0203A914(void);
void ov70_0223ECA4(Ov70Work24 *);
void ov70_0224212C(void *);
void ov70_0223ED24(Ov70Work24 *);
void ov70_02238E58(Ov70Work24 *);
void ov70_022392BC(void *);
void ov70_022391F0(void *, int, int);
void ov70_02239CF8(Ov70Work24 *);
void ov70_02239D44(Ov70Work24 *, int);
void ov70_02238B54(Ov70SpriteTemplate24 *, Ov70Work24 *, void *, int);

void *NARC_New(int, int);
void NARC_Delete(void *);
void BeginNormalPaletteFade(int, int, int, int, int, int, int);
void *NewString_ReadMsgData(void *, int);
void StringExpandPlaceholders(void *, void *, void *);
void FillWindowPixelBuffer(void *, int);
void DrawFrameAndWindow2(void *, int, int, int);
u32 AddTextPrinterParameterized(void *, int, void *, int, int, int, int);
void String_Delete(void *);
void InitBgFromTemplate(void *, int, const void *, int);
void BgClearTilemapBufferAndCommit(void *, int);
void FillBgTilemapRect(void *, int, int, int, int, int, int, int);
void BgCommitTilemapBufferToVram(void *, int);
void BG_ClearCharDataRange(int, int, int, int);
void FreeBgTilemapBuffer(void *, int);
void Sprite_SetDrawFlag(void *, int);
void GfGfxLoader_GXLoadPal(int, int, int, int, int, int);
void LoadFontPal1(int, int, int);
int Options_GetFrame(void *);
void LoadUserFrameGfx2(void *, int, int, int, int, int);
void LoadUserFrameGfx1(void *, int, int, int, int, int);
void GfGfxLoader_LoadCharData(int, int, void *, int, int, int, int, int);
void GfGfxLoader_LoadScrnData(int, int, void *, int, int, int, int, int);
void GfGfxLoader_LoadCharDataFromOpenNarc(void *, int, void *, int, int, int, int, int);
void AddWindowParameterized(void *, void *, int, int, int, int, int, int, int);
void CopyWindowToVram(void *);
void RemoveWindow(void *);
void *Sprite_CreateAffine(Ov70SpriteTemplate24 *);
void Sprite_SetAnimCtrlSeq(void *, int);

int ov70_0223E8E8(Ov70Work24 *, int, int, int, int);
int ov70_0223E884(Ov70Work24 *);
int ov70_0223E8A4(Ov70Work24 *);
int ov70_0223E78C(Ov70Work24 *);
void ov70_0223E954(void *);
void ov70_0223EA6C(Ov70Work24 *);
void ov70_0223EB34(Ov70Work24 *);
void ov70_0223EC0C(Ov70Work24 *);
void ov70_0223EA40(void *);
void ov70_0223EBD4(Ov70Work24 *);
void ov70_0223AB3C(void *, int);

#endif
