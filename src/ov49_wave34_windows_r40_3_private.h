#ifndef OV49_R40_RESIDUAL_34_3_PRIVATE_H
#define OV49_R40_RESIDUAL_34_3_PRIVATE_H

#include "global.h"

extern const u8 ov49_0226970C[];
extern const u8 ov49_022696F4[];
void ov49_0225CB50(void);

typedef struct Ov49WindowWorkR40 {
    u8 padding00[6];
    u16 flag;
    u8 padding08[4];
    u8 window[0x10];
    void *touchController;
    void *screenData[3];
    u32 destinations[3];
} Ov49WindowWorkR40;

void AddWindow(void *bgConfig, void *window, const void *template);
void *GfGfxLoader_GetScrnDataFromOpenNarc(void *narc, u32 member, u32 compressed, void *destination, u32 heapId);
void *TouchHitboxController_Create(const void *hitboxes, u32 count, void (*callback)(void), void *context, u32 heapId);
void ov49_0225C844(Ov49WindowWorkR40 *work, void *bgConfigHolder, void *narc, u32 heapId);

#endif
