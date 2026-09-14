#include "global.h"

#define U8_AT(p, n)  (*(u8 *)((u8 *)(p) + (n)))
#define U16_AT(p, n) (*(u16 *)((u8 *)(p) + (n)))
#define U32_AT(p, n) (*(u32 *)((u8 *)(p) + (n)))
#define PTR_AT(p, n) ((void *)((u8 *)(p) + (n)))

extern const u8 ov86_021E81DC[];
extern u32 GridInputHandler_HandleInput_NoHold(void *handler);
extern void PlaySE(u32 seqNo);
extern void ov86_021E71C0(void *work);
extern void ov86_021E723C(void *work);
extern void BgTilemapRectChangePalette(void *bgConfig, u32 bgId, u32 x, u32 y, u32 width, u32 height, u32 palette);
extern void ScheduleBgTilemapBufferTransfer(void *bgConfig, u32 bgId);

void ov86_021E7688(void *work, int index);
u8 ov86_021E7710(void *work);
void ov86_021E77BC(void *work);
