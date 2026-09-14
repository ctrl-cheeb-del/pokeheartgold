#ifndef OVERLAY_49_RESIDUAL_56_PRIVATE_H
#define OVERLAY_49_RESIDUAL_56_PRIVATE_H

#include "global.h"

typedef struct Ov49Residual56Block {
    u32 words[4];
} Ov49Residual56Block;

typedef struct Ov49Residual56Data {
    u32 unk00;
    Ov49Residual56Block unk04;
    Ov49Residual56Block unk14;
} Ov49Residual56Data;

void ov49_0225F110(Ov49Residual56Data *data, u32 arg1, u32 arg2);
void ov49_0225F148(Ov49Residual56Data *data);

BOOL ov49_0225F170(Ov49Residual56Data *data);
void ov49_0225F190(Ov49Residual56Block *block, u32 arg1, u32 arg2, u32 arg3, u32 arg4);
void ov49_0225F19C(Ov49Residual56Block *block);

#endif
