#ifndef POKEHEARTGOLD_SOL_R39_OVERLAY83_RESIDUAL38_PRIVATE_H
#define POKEHEARTGOLD_SOL_R39_OVERLAY83_RESIDUAL38_PRIVATE_H

#include "global.h"

#define PTR_AT(p, off) (*(void **)((u8 *)(p) + (off)))
#define U32_AT(p, off) (*(u32 *)((u8 *)(p) + (off)))
#define U16_AT(p, off) (*(u16 *)((u8 *)(p) + (off)))
#define U8_AT(p, off)  (*(u8 *)((u8 *)(p) + (off)))

typedef struct Ov83R39Flags {
    u8 gender : 7;
    u8 flag : 1;
} Ov83R39Flags;

void *NewString_ReadMsgData(void *msgData, int msgNo);
void StringExpandPlaceholders(void *format, void *dest, void *source);
void String_Delete(void *string);
void ov83_02247998(void *window, void *string, int x, int y, int color, int a, int b);
void FillWindowPixelBuffer(void *window, int fill);
void ov83_022479E4(void *window, void *msgData, int msgNo, int x, int y, int a, u32 color, int b);
void CopyWindowPixelsToVram_TextMode(void *window);
u32 ov83_02247768(u32 first, u32 second);
void *Party_GetMonByIndex(void *party, int index);
BOOL AcquireMonLock(void *mon);
BOOL ReleaseMonLock(void *mon, BOOL lock);
void *Mon_GetBoxMon(void *mon);
u32 GetMonData(void *mon, int field, void *dest);
u32 GetMonNature(void *mon);
u8 GetMonGender(void *mon);
u32 GetMoveMaxPP(u16 move, u8 ppUps);

void ov83_02245D08(u8 *work, void *window, void *msgData, int msgNo, int x, int y, int color, int a, int b);
void ov83_02245F24(u8 *work);
void ov83_02245D48(u8 *work);

#endif
