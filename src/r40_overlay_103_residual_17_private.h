#ifndef R40_OV103_R17_PRIVATE_H
#define R40_OV103_R17_PRIVATE_H
#include "global.h"
typedef struct R40Ctx17 {
    u8 pad[0x258];
    void *sprites[7];
} R40Ctx17;
extern void Sprite_DeleteAndFreeResources(void *);
void ov103_021EE078(R40Ctx17 *, u32);
#endif
