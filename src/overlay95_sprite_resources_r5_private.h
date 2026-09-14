#ifndef TO46_OVERLAY95_SPRITE_RESOURCES_R5_PRIVATE_H
#define TO46_OVERLAY95_SPRITE_RESOURCES_R5_PRIVATE_H

#include "global.h"

#include "sprite_system.h"

typedef struct Ov95R5Work {
    u8 pad00[8];
    PaletteData *paletteData;
    u8 pad0C[0x44];
    SpriteManager *spriteManager;
    SpriteSystem *spriteSystem;
    u8 pad58[0x1C];
    ManagedSprite *sprite74;
    ManagedSprite *sprite78;
    ManagedSprite *sprite7C;
    u32 state80;
    u32 timer84;
} Ov95R5Work;

extern const u32 ov95_021E7594[8];
extern const s16 ov95_021E75DC[][10];
extern const s16 ov95_021E762C[][10];
extern const f32 ov95_021E76D0[][10];
extern const f32 ov95_021E7770[][10];

void ov95_021E5EF8(Ov95R5Work *work);
BOOL ov95_021E60A4(Ov95R5Work *work, int index);

#endif
