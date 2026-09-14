#include "global.h"

#include "overlay_42.h"

#pragma require_prototypes off

typedef struct Ov49R60Result {
    s8 x;
    s8 y;
    u8 kind;
    u8 valid;
    u8 value;
} Ov49R60Result;

extern void *ov49_02269B90[];
extern void *ov49_02269BA0[];
extern void *ov49_02269BB0[];
extern void *ov49_02269BC0[];
extern void *ov49_02269BD0[];
extern void *ov49_02269C20[];
extern void *ov49_02269C40[];

extern void *ov49_02259FF0(void *);
extern s32 ov49_02258DAC(void *);
extern void *ov49_0225A000(void *);
extern s32 ov49_02258E60(void *, s32);
extern BOOL ov49_02261FC0(void *, void *, void **, u32, u16 *);
extern BOOL ov45_0222AFF8(void *);
extern BOOL ov45_0222B00C(void *);
extern u16 ov45_0222B020(void *);
extern BOOL ov49_0225904C(void *, s32, s32 *, u16 *);
extern u32 ov49_02258E34(void *);
extern void ov49_02258E04(void *, UnkStruct_ov44_02232914, s32);

BOOL ov49_02261DBC(Ov49R60Result *result, void *state, void *ctx, void *object, u8 kind, u32 value) {
    s32 movement;
    u16 output[2];
    UnkStruct_ov44_02232914 position;
    UnkStruct_ov44_02232914 current;
    s32 direction;
    void *map;
    void *sub;
    s32 expected;
    u32 packed;
    s32 valid = FALSE;

    map = ov49_02259FF0(ctx);
    direction = ov49_02258DAC(map);
    sub = ov49_0225A000(ctx);
    expected = ov49_02258E60(object, 4);
    movement = 1;

    switch (kind) {
    case 2:
        if (!ov49_02261FC0(sub, map, ov49_02269B90, 4, output)) {
            return valid;
        }
        goto success;
    case 3:
        if (!ov49_02261FC0(sub, map, ov49_02269BC0, 4, output)) {
            return valid;
        }
        goto success;
    case 4:
        if (!ov49_02261FC0(sub, map, ov49_02269BA0, 4, output)) {
            return valid;
        }
        goto success;
    case 5:
        movement = 0;
        if (!ov49_02261FC0(sub, map, ov49_02269C20, 8, output)) {
            return valid;
        }
        goto success;
    case 6:
        movement = 0;
        if (!ov49_02261FC0(sub, map, ov49_02269C40, 8, output)) {
            return valid;
        }
        goto success;
    case 7:
        movement = 3;
        if (!ov49_02261FC0(sub, map, ov49_02269BB0, 4, output)) {
            return valid;
        }
        goto success;
    case 8:
        movement = 0;
        if (!ov49_02261FC0(sub, map, ov49_02269BD0, 4, output)) {
            return valid;
        }
        goto success;
    case 10:
        return valid;
    case 9:
        if (!ov45_0222AFF8(state)) {
            return valid;
        }
        if (!ov45_0222B00C(state)) {
            return valid;
        }
        if (expected != ov45_0222B020(state)) {
            return valid;
        }
        if (ov49_0225904C(map, direction, &movement, output) != TRUE) {
            GF_AssertFail();
        }
        movement = ov42_022282A4(movement);
        valid = TRUE;
        goto success;
    case 0:
    case 1:
    case 11:
    case 12:
    case 13:
    case 14:
        break;
    }

    return FALSE;

success:
    packed = ov49_02258E34(object);
    current.unk0 = packed;
    current.unk2 = packed >> 16;
    position = current;
    ov49_02258E04(object, *(UnkStruct_ov44_02232914 *)output, movement);
    result->x = position.unk0 / 16;
    result->y = position.unk2 / 16;
    result->kind = kind;
    result->valid = valid;
    result->value = value;
    return TRUE;
}
