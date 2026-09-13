#include "r40_overlay_49_residual_62_gap_1_private.h"

typedef struct Ov49R62Status {
    u8 value0;
    u8 value1;
    u8 value2;
    u8 selection;
    s16 value4;
    u8 enabled;
    u8 flags;
} Ov49R62Status;

void ov49_02262E10(Ov49R62Status *status, void *ctx, u32 force, u32 mode) {
    u32 kind;
    u32 value;
    u32 value0;
    volatile u32 savedMode = mode;
    void *message;
    u8 x;

    if (force != 0) {
        status->flags = 0xFF;
    }
    switch (status->selection) {
    case 0:
        kind = 0;
        break;
    case 1:
        kind = 1;
        break;
    case 2:
        kind = 2;
        break;
    default:
        GF_AssertFail();
        kind = 2;
        break;
    }

    value0 = ov45_0222F274(kind);
    if (status->value0 != value0) {
        status->flags |= 4;
    }
    status->value0 = value0;

    value = ov45_0222F294(kind);
    if (status->value2 != value) {
        status->flags |= 4;
    }
    status->value2 = value;

    if (value0 == 1) {
        value = ov45_0222F2D4(kind);
    } else {
        value = 4;
    }
    if (status->value1 != value) {
        status->flags |= 2;
    }
    status->value1 = value;

    if (status->flags & 1) {
        ov49_0225A24C(ctx, 0, 0, 0x68, 0x10);
        ov49_0225A37C(ctx, status->selection, 0);
        message = ov49_0225A30C(ctx, 1, 0x36);
        ov49_0225A23C(ctx, message, 0, 0);
    }
    if (status->flags & 4) {
        ov49_0225A24C(ctx, 0, 0x10, 0x68, 0x10);
        if (savedMode == 1 && status->value2 == 0 && status->value0 == 1) {
            message = ov49_0225A30C(ctx, 1, 0x45);
            x = 0x68 - FontID_String_GetWidth(0, message, 0);
            ov49_0225A23C(ctx, message, x, 0x10);
        }
    }
    if (status->flags & 2) {
        ov49_0225A24C(ctx, 0, 0x20, 0x68, 0x20);
        ov49_0225A31C(ctx, status->value1, 1, 1, 2);
        ov49_0225A31C(ctx, 4 - status->value1, 1, 0, 2);
        message = ov49_0225A30C(ctx, 1, 0x44);
        ov49_0225A23C(ctx, message, 0, 0x20);
    }
    if (status->enabled == 1 && (status->flags & 8)) {
        ov49_0225A24C(ctx, 0, 0x40, 0x68, 0x10);
        ov49_0225A31C(ctx, status->value4, 2, 0, 2);
        message = ov49_0225A30C(ctx, 0, 0xF);
        ov49_0225A23C(ctx, message, 0, 0x40);
    }
    status->flags = 0;
}
