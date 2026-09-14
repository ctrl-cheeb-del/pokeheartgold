#include "math_util.h"
#include "overlay49_spawn_argument_helpers_r10_private.h"

void ov49_0225927C(void *ctx, u16 value, u8 kind, u8 direction) {
    UnkStruct_ov42_02228CDC data;

    data.unk0 = value;
    data.unk2 = kind;
    data.unk3 = direction;
    ov49_02258C1C(ctx, &data);
}

u8 ov49_02259294(const u8 *values, u32 count) {
    return values[MTRandom() % count];
}

BOOL ov49_022592A8(Ov49R10Context *ctx, UnkStruct_ov42_02228110 **object, s32 direction, u16 value) {
    UnkStruct_ov44_02232914 position = ov42_022282DC(*object);
    u32 result;

    position = ov42_02228270(position, direction);
    result = ov49_022589B8(ctx->unk14, position.unk0 / 16, position.unk2 / 16);
    if (result == value) {
        return TRUE;
    }
    return FALSE;
}
