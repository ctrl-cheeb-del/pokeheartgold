#ifndef TO47_SOL_R3_OVERLAY49_RESIDUAL58_PRIVATE_H
#define TO47_SOL_R3_OVERLAY49_RESIDUAL58_PRIVATE_H

#include "global.h"

typedef void (*Ov49R58Callback)(void *, void *, u32, u8);

typedef struct Ov49R58Entry {
    u8 values[8];
    u32 type;
    u8 config[8];
    Ov49R58Callback callback;
} Ov49R58Entry;

void *ov49_0225EF84(void *);
void *ov49_0225A010(void *);
void ov49_0225EF68(void *);
void ov49_0225EF98(void *, u32, const void *, u32);
void ov49_0225EFC4(void *, u32, const void *, u32);
void ov49_0225F260(void *, void *, u32, const Ov49R58Entry *, u32);

#endif
