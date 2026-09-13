#ifndef SOL_R40_OV108_R10_PRIVATE_H
#define SOL_R40_OV108_R10_PRIVATE_H
#include "global.h"

typedef struct Ov108R10 {
    u32 heapId;
    u8 pad004[0x1C - 4];
    u8 areaData[0x324];
    u8 pad340[8];
    void *sub;
    void *spriteSystem;
    void *spriteManager;
    void *sprites[18];
    u8 pad39C[0x184DE - 0x39C];
    u8 page;
} Ov108R10;

typedef struct Ov108Template {
    u32 data[10];
} Ov108Template;
extern const Ov108Template ov108_021EA7F8;
extern const Ov108Template ov108_021EA820;
extern const Ov108Template ov108_021EA848;
extern const Ov108Template ov108_021EA870;

void *ov108_021E8540(void *, u16, u16, int, int, u8, u8, int);
void *SpriteSystem_CreateSpriteFromResourceHeader(void *, void *, const void *);
void thunk_Sprite_SetPriority(void *, int);
void thunk_Sprite_SetDrawPriority(void *, int);
void thunk_Sprite_SetDrawFlag(void *, int);
void ov108_021E756C(Ov108R10 *);
void ov108_021E733C(Ov108R10 *);
#endif
