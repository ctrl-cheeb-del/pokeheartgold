#ifndef TO47_OV40_RESIDUAL_31_PRIVATE_H
#define TO47_OV40_RESIDUAL_31_PRIVATE_H

#include "global.h"

#define PTR_AT(p, off)  (*(void **)((u8 *)(p) + (off)))
#define WORD_AT(p, off) (*(u32 *)((u8 *)(p) + (off)))
#define BYTE_AT(p, off) (*(u8 *)((u8 *)(p) + (off)))

void *SaveArray_PCStorage_Get(void *saveData);
BOOL PCStorage_IsBonusWallpaperUnlocked(void *pcStorage, u32 wallpaper);

void GfGfxLoader_LoadCharDataFromOpenNarc(void *narc, int memberNo, void *bgConfig, int layer, int tileStart, int size, int compressed, int heapId);
void GfGfxLoader_LoadScrnDataFromOpenNarc(void *narc, int memberNo, void *bgConfig, int layer, int tileStart, int size, int compressed, int heapId);
void PaletteData_LoadFromNarc(void *palette, int narcId, int memberNo, int heapId, int bufferId, int size, int pos, int readPos);
void PaletteData_BlendPalettes(void *palette, int bufferId, int selectedBuffer, u8 cur, u16 target);
void GfGfx_EngineATogglePlanes(int plane, int enable);
void GfGfx_EngineBTogglePlanes(int plane, int enable);

void ov40_0222BF80(void *work, int state);
void ov40_0222C710(void *work, int layer);
BOOL ov40_0222DA00(void *a, void *b, int c, int d);
BOOL ov40_0222DA84(void *transition, int direction);
void ov40_02230964(void *work, int value);
void ov40_02236EB4(void *work);
void ov40_02237030(void *work, int messageId);
void ov40_02237144(void *work);
void ov40_022371E4(void *work, int box);
void ov40_02237284(void *work);
void ov40_022373E4(void *work, int draw);
void ov40_02237474(void *work);
void ov40_02237548(void *work, int value);

void ov40_0223757C(void *work);
void ov40_02237644(void *work);
int ov40_022376FC(void *work);

#endif
