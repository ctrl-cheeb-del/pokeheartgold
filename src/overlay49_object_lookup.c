#include "global.h"

#include "overlay49_object_lookup_private.h"

Ov49Residual9Entry *ov49_02258F7C(Ov49Residual9Context *ctx, s32 x, s32 y) {
    UnkStruct_ov44_02232914 pos;
    UnkStruct_ov42_02228110 *object;
    u8 *entry;
    int i;

    pos.unk0 = x << 4;
    pos.unk2 = y << 4;
    object = ov42_022284A4(ctx->objects, pos);
    if (object == NULL) {
        return NULL;
    }
    i = 0;
    if (i < ctx->count) {
        entry = ctx->entries;
        do {
            if (*(UnkStruct_ov42_02228110 **)entry == object) {
                return (Ov49Residual9Entry *)(ctx->entries + i * sizeof(Ov49Residual9Entry));
            }
            i++;
            entry += sizeof(Ov49Residual9Entry);
        } while (i < ctx->count);
    }
    GF_ASSERT(FALSE);
    return NULL;
}

BOOL ov49_02258FDC(Ov49Residual9Context *ctx, s32 x, s32 y) {
    UnkStruct_ov44_02232914 a = ov42_022282DC((UnkStruct_ov42_02228110 *)ctx->objects);
    UnkStruct_ov44_02232914 b = ov42_022282E8((UnkStruct_ov42_02228110 *)ctx->objects);

    if (a.unk0 == (x << 4) && a.unk2 == (y << 4)) {
        return TRUE;
    }
    if (b.unk0 == (x << 4) && b.unk2 == (y << 4)) {
        return TRUE;
    }
    return FALSE;
}

BOOL ov49_0225904C(Ov49Residual9Context *ctx, Ov49Residual9Entry *entry, s32 *direction, UnkStruct_ov44_02232914 *position) {
    UnkStruct_ov44_02232914 current = ov42_022282DC(entry->object);
    int i;

    for (i = 0; i < 4; i++) {
        UnkStruct_ov44_02232914 next = ov42_02228270(current, ov49_02269654[i]);
        int y = next.unk2 / 16;
        int x = next.unk0 / 16;

        if (ov49_022589AC(ctx->map, x, y) != 1) {
            int tile = ov49_022589C4(ctx->map, x, y);
            if ((tile == 0 || tile == 0x2A) && ov42_022284A4(ctx->objects, next) == NULL) {
                *direction = ov49_02269654[i];
                *position = next;
                return TRUE;
            }
        }
    }
    return FALSE;
}
