#ifndef TO46_OV80_A00C_R2_PRIVATE_H
#define TO46_OV80_A00C_R2_PRIVATE_H

#include "global.h"

#include "bg_window.h"
#include "obj_char_transfer.h"
#include "pm_string.h"
#include "sprite_system.h"
#include "text.h"
#include "unk_02013534.h"

typedef struct Ov80TextContext {
    u8 padding00[0x10];
    BgConfig *bgConfig;
    u8 padding14[4];
    SpriteManager *spriteManager;
    u8 padding1C[0x14];
    UnkStruct_02013534 *fontSystem;
} Ov80TextContext;

typedef struct Ov80TextObject {
    TextOBJ *textObj;
    UnkStruct_02021AC8 charTransfer;
    u16 fontLength;
} Ov80TextObject;

typedef struct Ov80TextCache {
    Window window;
    u16 charLength;
    u16 fontLength;
} Ov80TextCache;

void ov80_0223A62C(Ov80TextContext *, Ov80TextObject *, String *, u32, int, int, int, int, int, int, Ov80TextCache *);
void ov80_0223A75C(String *, u32, int *, int *);

#endif
