#include "overlay49_battle_config_internal.h"

int ov49_02264B94(void *state) {
    struct {
        void *a;
        void *b;
    } pair;

    pair.a = ov45_0222A9C8(state);
    pair.b = pair.a;
    switch (*(u8 *)&pair.b) {
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
        return 0;
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
        return 1;
    case 0:
    case 1:
    case 2:
    case 3:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
        return 2;
    default:
        GF_AssertFail();
        return 1;
    }
}

void ov49_02264C04(void *ctx, void *object, u32 value) {
    u32 i;

    if (ov45_0222AB28(ov49_02259FE8(ctx), object) == 1) {
        for (i = 0; i < 0x163; i++) {
            if (value == ov49_02269EC4[i * 2]) {
                value = ov49_02269EC6[i * 2];
                break;
            }
        }
    }
    ov49_0225A30C(ctx, 3, value);
}

void ov49_02264C50(void *ctx, void *left, void *right) {
    void *object = ov49_02259FE8(ctx);
    int a = ov45_0222AB28(object, left);
    int b = ov45_0222AB28(object, right);
    u32 value = 0x29;

    if (a == 1 && b == 1) {
        value = 0x2AA;
    } else if (a == 1 && b == 0) {
        value = 0x226;
    } else if (a == 0 && b == 1) {
        value = 0x2A9;
    }
    ov49_0225A30C(ctx, 3, value);
}

BOOL ov49_02264CA8(Ov49BattleConfig *config, void *object, s32 index) {
    void *a;
    void *b;

    if (index == -1) {
        GF_AssertFail();
    }
    config->index = index;
    config->unk8 = ov45_0222A53C(object);
    config->unkA = 1;
    a = ov45_0222A5C0(object);
    b = ov45_0222A578(object, config->index);
    if (b == NULL) {
        return FALSE;
    }
    config->valueA = ov49_02264B94(a);
    config->valueB = ov49_02264B94(b);
    return TRUE;
}
