#ifndef TO42_SOL_R1_OV40_R27_U16_PRIVATE_H
#define TO42_SOL_R1_OV40_R27_U16_PRIVATE_H

#include "global.h"

#define PTR(p, off)  (*(void **)((u8 *)(p) + (off)))
#define WORD(p, off) (*(u32 *)((u8 *)(p) + (off)))
#define S32(p, off)  (*(s32 *)((u8 *)(p) + (off)))

BOOL TouchscreenHitbox_TouchNewIsIn(const void *hitbox);
void ov40_02230944(void *work);
void ov40_0222BF80(void *work, int state);
void Thunk_G3X_Reset(void);
void ov41_0224B554(void *p);
void RequestSwap3DBuffers(int a, int b);
void BgClearTilemapBufferAndCommit(void *bgConfig, int bgId);
void ov40_02236130(void *work);
void ov40_02230964(void *work, int value);
void ov40_0222E7B8(void *p, void *work);
void ov40_0223584C(void *work);
void ov40_0222DA84(void *p, int value);
BOOL ov40_0222DA00(void *a, void *b, int c, int d);
void ov41_0224B57C(void);
void ov40_0222BC54(void *work);
void SetBgPriority(int bgId, int priority);
void ov40_02235994(void);
void PaletteData_BlendPalettes(void *palette, int mask, int coeff, int color, int selector);
void *ov39_02227080(void *p, void *q);
void *ov41_0224B530(void *p, void *q);
void ov41_0224B5D0(void *p, int value);
void ov40_02235940(void);
void ov40_022307DC(void *work, int a, int b);
void GfGfx_EngineBTogglePlanes(int planes, int enable);
void GfGfx_EngineATogglePlanes(int planes, int enable);
void Main_SetVBlankIntrCB(void (*callback)(void *), void *arg);
void PaletteData_LoadPaletteSlotFromHardware(void *palette, int a, int b, int size);
void ov40_02235C7C(void *work, int selection);
void ov40_022358C0(void *work);
void ov40_02235900(void *arg);

extern const u8 ov40_022451C4[];
extern const u8 ov40_022451D0[];
extern const u8 ov40_022451D4[];
extern const u8 ov40_022451D8[];

int ov40_0223527C(void *work);
int ov40_0223534C(void *work);
int ov40_0223512C(void *work);

#endif
