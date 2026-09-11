#include "ov99_wave41_private.h"
typedef struct Ov99Record {
    u16 a, b, c, d;
    u8 rest[36];
} Ov99Record;
typedef struct Ov99Bits {
    u8 pad[8];
    u32 value : 9;
} Ov99Bits;

void ov99_021E64E0(R99 *w, u32 flag) {
    ManagedSprite_SetDrawFlag(P(w, 0x50), flag);
    ManagedSprite_SetDrawFlag(P(w, 0x54), flag);
    ManagedSprite_SetDrawFlag(P(w, 0x58), flag);
    ManagedSprite_SetDrawFlag(P(w, 0x44), flag);
    ManagedSprite_SetDrawFlag(P(w, 0x48), flag);
    ManagedSprite_SetDrawFlag(P(w, 0x4c), flag);
    ManagedSprite_SetDrawFlag(P(w, 0x5c), flag);
    ManagedSprite_SetDrawFlag(P(w, 0x60), flag);
    ManagedSprite_SetDrawFlag(P(w, 0x64), flag);
}
