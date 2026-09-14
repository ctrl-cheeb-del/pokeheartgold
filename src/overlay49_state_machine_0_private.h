#ifndef OVERLAY49_STATE_MACHINE_0_PRIVATE_H
#define OVERLAY49_STATE_MACHINE_0_PRIVATE_H

#include "global.h"

typedef struct Overlay49StateMachine0 {
    void *object;
    u16 state;
    u16 padding_06;
    u32 value;
} Overlay49StateMachine0;

void ov49_0225EC28(Overlay49StateMachine0 *work);
u32 ov49_0225EC30(Overlay49StateMachine0 *work);
void ov49_0225D4C8(void *object, u32 value);
void ov49_0225D214(void *ctx, void *object, u32 index, u32 value);
void ov49_0225D494(void *object, u32 value);
void ov49_0225D328(void *ctx, void *object, u32 index);
void ov49_0225D4E8(void *object);
void ov49_0225D4F0(void *object, u32 x, u32 y, u32 z);

void ov49_0225EB08(Overlay49StateMachine0 *work, void *ctx);
void ov49_0225EB54(Overlay49StateMachine0 *work, void *ctx, u32 value);
void ov49_0225EB84(Overlay49StateMachine0 *work);
void ov49_0225EBA8(Overlay49StateMachine0 *work, void *ctx);
void ov49_0225EBE4(Overlay49StateMachine0 *work, void *ctx);

#endif
