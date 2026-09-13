#ifndef POKEHEARTGOLD_SOL_R40_OVERLAY108_RESIDUAL13_PRIVATE_H
#define POKEHEARTGOLD_SOL_R40_OVERLAY108_RESIDUAL13_PRIVATE_H

#include "global.h"

#include "overlay_108_helpers_internal.h"

typedef struct Ov108CharData {
    u8 pad[0x14];
    void *raw;
} Ov108CharData;

void Sprite_SetPositionXY(void *sprite, s16 x, s16 y);
void ov108_021E78C0(SafariAreaCustomizer *work, int index, int animation, int draw);
void FillBgTilemapRect(void *bgConfig, int bgId, u16 value, int x, int y, int width, int height, int palette);
void ScheduleBgTilemapBufferTransfer(void *bgConfig, int bgId);
void *GfGfxLoader_GetCharDataFromOpenNarc(void *narc, int member, BOOL compressed, Ov108CharData **data, int heapId);
void BG_LoadCharTilesData(void *bgConfig, int bgId, const void *data, u32 size, u32 tileStart);
void Heap_Free(void *ptr);
void *NARC_New(int narcId, int heapId);
void NARC_Delete(void *narc);

void ov108_021E78F4(SafariAreaCustomizer *work, u32 index, u32 animation);
void ov108_021E7ADC(SafariAreaCustomizer *work);
void ov108_021E7B74(SafariAreaCustomizer *work, void *narc, u32 index, int member);
void ov108_021E7BB4(SafariAreaCustomizer *work, u32 index, int member);

#endif
