#ifndef R40_OV103_R16_PRIVATE_H
#define R40_OV103_R16_PRIVATE_H
#include "global.h"

#include "sprite_system.h"
#include "unk_02009D48.h"
typedef struct R40Ov103Ctx16 {
    u8 pad[0x250];
    SpriteSystem *spriteSystem;
    SpriteManager *spriteManager;
} R40Ov103Ctx16;
extern const OamManagerParam ov103_021EED38;
extern const OamCharTransferParam ov103_021EED0C;
extern const SpriteResourceCountsListUnion ov103_021EED20;
void ov103_021EDF88(R40Ov103Ctx16 *);
#endif
