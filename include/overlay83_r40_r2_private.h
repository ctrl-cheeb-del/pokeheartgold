#ifndef TO45_OV83_R40_R2_PRIVATE_H
#define TO45_OV83_R40_R2_PRIVATE_H

#include "global.h"

#include "sprite.h"

#pragma require_prototypes off

#define U8_AT(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U32_AT(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))

typedef struct Ov83MenuEntry {
    u32 value;
    u32 message;
} Ov83MenuEntry;

extern const u16 ov83_02248024[];
extern const u16 ov83_02248028[];
extern const u16 ov83_0224802C[];
extern const u16 ov83_02248030[];

void ov83_022447E0(void *, void *, int, int, int, int, int, int, int, int);
u8 ov83_0224777C(void *, int, int);
void SpriteTransfer_DeleteCharTransferTask(void *);
void SpriteTransfer_DeletePlttTransferTask(void *);

#endif
