#ifndef OV39_RESIDUAL5_PRIVATE_H
#define OV39_RESIDUAL5_PRIVATE_H

#include "global.h"

typedef struct {
    u32 first;
    u32 second;
} Ov39Pair;

typedef struct {
    void *saveData;
    u8 pad004[0x140 - 4];
    u8 sourcePayload[0x50];
    union {
        void *ptr190;
        u16 value;
    } field190;
    u8 byte194;
    u8 pad195[3];
    u32 payloadOffset;
    Ov39Pair pairs[3];
    u8 pad1B4[0x3E8 - 0x1B4];
    u32 command;
    u8 pad3EC[4];
    u32 unk3F0;
    u8 pad3F4[0x411 - 0x3F4];
    u8 byte411;
} Ov39WorkResidual5;

BOOL ov39_022274D4(Ov39WorkResidual5 *work, void *src, const Ov39Pair *pairs);
BOOL ov39_02227534(Ov39WorkResidual5 *work, void *dst);
BOOL ov39_02227590(Ov39WorkResidual5 *work, u16 value, u8 a2, u8 a3, u8 a4);
BOOL ov39_022275E8(Ov39WorkResidual5 *work);
BOOL ov39_02227648(Ov39WorkResidual5 *work);

#endif
