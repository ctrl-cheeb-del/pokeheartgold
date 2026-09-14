#ifndef TO45_OV102_R6_PRIVATE_H
#define TO45_OV102_R6_PRIVATE_H

#include "global.h"

typedef struct Ov102InputState {
    u8 pad00[0x34];
    u16 keys;
    u8 pad36[0x1A];
    u16 current;
    u16 previous;
} Ov102InputState;

typedef struct Ov102CursorState {
    u16 unk00;
    u16 unk02;
    u16 converted;
    u8 unk06;
    u8 unk07;
    void *unk08;
    u16 unk0C;
    u16 unk0E;
} Ov102CursorState;

extern const u8 ov102_021EC65C[];
extern const u8 ov102_021EC65D[];
extern const u8 ov102_021EC65E[];
extern const u8 ov102_021EC65F[];

u16 ov102_021EC4F8(u16);
u16 ov102_021EC514(u16);
u16 ov102_021EC530(u16);
u16 ov102_021EC54C(u16);
u16 ov102_021EC568(u16);
u16 ov102_021EC584(u16);
u16 ov102_021E8FD8(u32);

BOOL ov102_021E8600(Ov102InputState *);
BOOL ov102_021E86B8(Ov102InputState *);
void ov102_021E874C(Ov102CursorState *, u32);

#endif
