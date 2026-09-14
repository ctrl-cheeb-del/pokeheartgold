#ifndef TO45_OV40_R31_R4_PRIVATE_H
#define TO45_OV40_R31_R4_PRIVATE_H

#include "global.h"

#define PTR(p, off)  (*(void **)((u8 *)(p) + (off)))
#define WORD(p, off) (*(u32 *)((u8 *)(p) + (off)))

void InitWindow(void *);
void AddWindowParameterized(void *, void *, int, int, int, int, int, int, u16);
void FillWindowPixelBuffer(void *, int);
void *NewString_ReadMsgData(void *, int);
int ov40_022306C0(void *, void *);
void AddTextPrinterParameterizedWithColor(void *, int, void *, int, int, int, u32, void *);
void String_Delete(void *);
void ScheduleWindowCopyToVram(void *);
void ClearWindowTilemapAndCopyToVram(void *);
void RemoveWindow(void *);
BOOL ov40_0223D5CC(void *);
void sub_020879E0(void *, int);
void sub_020878B0(void *, int);
void sub_02087A08(void *, int, int);
void ov40_02237008(void *);
void ov40_02236FE0(void *);
void BgClearTilemapBufferAndCommit(void *, int);
void ov40_0222D980(void *, void *, int, int, int, int, int);
void ov40_0222DA84(void *, int);
BOOL ov40_0222DA00(void *, void *, int, int);
void GfGfx_EngineATogglePlanes(int, int);
void GfGfx_EngineBTogglePlanes(int, int);
void GfGfxLoader_LoadCharDataFromOpenNarc(void *, int, void *, int, int, int, int, int);
void GfGfxLoader_LoadScrnDataFromOpenNarc(void *, int, void *, int, int, int, int, int);
void PaletteData_BlendPalettes(void *, int, int, u8, u16);
void ov40_0223077C(void *, void *, int, s16);
void ov40_0222DED0(void *, int);
void PlaySE(int);
void StopSE(int, int);
void *ov40_0223D540(void *);
int ov39_0222748C(void *, void *);
BOOL ov39_02227D44(void *, void **);
void ov40_0222DFB0(void *);
void ov40_02230CDC(void *, int, u32, u32);
void ov40_02230964(void *, int);
void ov40_02236EB4(void *);
BOOL System_GetTouchNew(void);
void ov40_0222C710(void *, int);
void ov40_02237030(void *, int);
void ov40_02236F38(void *);
void ov40_0222BF80(void *, int);
void ov40_02237C9C(void *);
void ov40_02238290(void *);
void ov40_0222F9E0(void *, void *, int);
void ov40_0222F734(void *);
void ov40_0222EED0(void *, void *, void *, void *);
void ov40_0222FA5C(void *, void *);
void ov40_0222F740(void *, void *, int);
void ov40_0222F858(void *, int, int);
void ov40_02237AC0(void *);

typedef struct Copy44 {
    u32 words[11];
} Copy44;

typedef struct Ov40Inner {
    u8 pad_0000[0x1A4];
    u8 transA[4];
    u8 transB[4];
    u32 blend;
    u8 pad_01B0[0x1D8];
    u32 count;
    u8 pad_038C[0x2A80];
    u8 strings[0xA0];
    Copy44 copied;
} Ov40Inner;

extern const Copy44 ov40_02245310;
extern const u8 ov40_02245268[][4];

void ov40_02237C9C(void *);
void ov40_02237D6C(void *);
int ov40_02237D94(void *);

#endif
