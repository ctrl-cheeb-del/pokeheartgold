#include "to45_overlay49_message_descriptor_r65_internal.h"

#pragma require_prototypes off

extern u32 ov45_0222A9A4(void *);
extern void *ov45_0222A99C(void *);
extern u32 MTRandom(void);
extern const u8 ov49_02269E1C[8];
extern const Ov49MessageDescriptor ov49_02269E24;

void ov49_02264F78(Ov49TargetDescriptor *out, void *target) {
    u32 selection = ov45_0222A9A4(target);
    out->count = 1;
    out->selection = selection;
    out->target = ov45_0222A99C(target);
}

void ov49_02264F9C(Ov49MessageWork *out, void *ctx, u32 count, u32 first, u32 special) {
    u32 i;

    ov49_0225A10C(ctx, count);
    out->requestedCount = count;
    for (i = 0; i < count; i++) {
        void *message;
        if (special != 0 && i == count - 1) {
            if (special == 1) {
                message = ov49_0225A30C(ctx, 3, 0x205);
            } else {
                message = ov49_0225A30C(ctx, 3, 0xEB);
            }
        } else {
            message = ov49_0225A30C(ctx, 3, first + i);
        }
        ov49_0225A144(ctx, message, i);
    }
    out->descriptor = ov49_02269E24;
    out->descriptor.count = out->requestedCount;
    if (out->descriptor.capacity > out->requestedCount) {
        out->descriptor.capacity = out->requestedCount;
    }
    out->descriptor.message = ov49_0225A154(ctx);
}

void ov49_02265044(Ov49MessageWork *out, void *ctx, u32 range, u32 count, u32 first, u32 special) {
    u32 i;

    ov49_0225A120(ctx, count, range);
    out->requestedCount = count;
    for (i = 0; i < count; i++) {
        void *message;
        u32 choice;
        if (special != 0 && i == count - 1) {
            choice = range;
            if (special == 1) {
                message = ov49_0225A30C(ctx, 3, 0x205);
            } else {
                message = ov49_0225A30C(ctx, 3, 0xEB);
            }
        } else {
            do {
                choice = MTRandom() % range;
            } while (ov49_0225A164(ctx, choice) == 1);
            message = ov49_0225A30C(ctx, 3, first + choice);
        }
        ov49_0225A144(ctx, message, choice);
    }
    out->descriptor = ov49_02269E24;
    out->descriptor.count = out->requestedCount;
    if (out->descriptor.capacity > out->requestedCount) {
        out->descriptor.capacity = out->requestedCount;
    }
    out->descriptor.message = ov49_0225A154(ctx);
}

void ov49_02265110(Ov49MessageWork *out, void *ctx) {
    s32 i;

    ov49_0225A10C(ctx, 8);
    out->requestedCount = 8;
    for (i = 0; i < 8; i++) {
        ov49_0225A144(ctx, ov49_0225A30C(ctx, 1, ov49_02269E1C[i]), i);
    }
    out->descriptor = ov49_02269E24;
    out->descriptor.count = out->requestedCount;
    out->descriptor.capacity = out->requestedCount;
    out->descriptor.message = ov49_0225A154(ctx);
}

void ov49_02265170(Ov49MessageWork *out, void *ctx) {
    s32 i;

    ov49_0225A10C(ctx, 4);
    out->requestedCount = 4;
    for (i = 0; i < 3; i++) {
        ov49_0225A38C(ctx, i, 0);
        ov49_0225A144(ctx, ov49_0225A30C(ctx, 1, 0x27), i);
    }
    ov49_0225A144(ctx, ov49_0225A30C(ctx, 1, 0x25), 3);
    out->descriptor = ov49_02269E24;
    out->descriptor.count = out->requestedCount;
    out->descriptor.capacity = out->requestedCount;
    out->descriptor.message = ov49_0225A154(ctx);
}

void ov49_022651E8(Ov49MessageWork *out, void *ctx) {
    s32 i;

    ov49_0225A10C(ctx, 4);
    out->requestedCount = 4;
    for (i = 0; i < 3; i++) {
        ov49_0225A37C(ctx, i, 0);
        ov49_0225A144(ctx, ov49_0225A30C(ctx, 1, 0x26), i);
    }
    ov49_0225A144(ctx, ov49_0225A30C(ctx, 1, 0x25), 3);
    out->descriptor = ov49_02269E24;
    out->descriptor.count = out->requestedCount;
    out->descriptor.capacity = out->requestedCount;
    out->descriptor.message = ov49_0225A154(ctx);
}

void ov49_02265260(void *unused, void *ctx) {
    ov49_0225A134(ctx);
}
