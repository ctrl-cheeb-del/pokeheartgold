#include "overlay49_state_machine_0_private.h"

void ov49_0225EB08(Overlay49StateMachine0 *work, void *ctx) {
    switch (work->state) {
    case 0:
        break;
    case 1:
        ov49_0225EBA8(work, ctx);
        work->state = 2;
        break;
    case 2:
        break;
    case 3:
        ov49_0225EC28(work);
        work->state = 4;
        break;
    case 4:
        if (ov49_0225EC30(work) == 1) {
            ov49_0225EBE4(work, ctx);
            work->state = 0;
        }
        break;
    }
}

void ov49_0225EB54(Overlay49StateMachine0 *work, void *ctx, u32 value) {
    if ((u16)(work->state + 0xffff) <= 1) {
        return;
    }
    if ((u16)(work->state + 0xfffd) <= 1) {
        ov49_0225EBE4(work, ctx);
    }
    work->state = 1;
    work->value = value;
}

void ov49_0225EB84(Overlay49StateMachine0 *work) {
    if ((u16)(work->state + 0xfffd) <= 1) {
        return;
    }
    if (work->state <= 1) {
        work->state = 0;
    } else {
        work->state = 3;
    }
}

void ov49_0225EBA8(Overlay49StateMachine0 *work, void *ctx) {
    ov49_0225D4C8(work->object, work->value);
    ov49_0225D214(ctx, work->object, 0, 0);
    ov49_0225D214(ctx, work->object, 1, 0);
    ov49_0225D214(ctx, work->object, 2, 0);
    ov49_0225D494(work->object, 1);
}

void ov49_0225EBE4(Overlay49StateMachine0 *work, void *ctx) {
    ov49_0225D328(ctx, work->object, 0);
    ov49_0225D328(ctx, work->object, 1);
    ov49_0225D328(ctx, work->object, 2);
    ov49_0225D494(work->object, 0);
    ov49_0225D4E8(work->object);
    ov49_0225D4F0(work->object, 0x1000, 0x1000, 0x1000);
}
