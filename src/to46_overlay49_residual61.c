#include "global.h"

#pragma require_prototypes off

typedef struct Ov49Residual61State {
    u8 data[10];
} Ov49Residual61State;

typedef struct Ov49Residual61Config {
    u8 state;
    u8 index;
    u8 value;
} Ov49Residual61Config;

extern void *ov49_02259FE8(void *);
extern s32 sub_0203988C(void);
extern u32 ov45_0222F314(u32);
extern u32 ov45_0222F3E8(u32);
extern void ov49_0225EF8C(void *, u32);
extern void ov45_0222AC14(void *, u32, u32, void *, u32, u32, u32, u32);
extern void GF_AssertFail(void);
extern void ov49_0225A204(void *, u32, u32, u32, u32);
extern void ov49_0225A22C(void *);
extern const u8 ov49_02269DF8[];

void ov49_02262DD4(Ov49Residual61State *, s32);

BOOL ov49_02262CB4(Ov49Residual61State *work, void *ctx, Ov49Residual61Config *config, void *state, void *arg) {
    void *object = ov49_02259FE8(ctx);
    s32 connection = sub_0203988C();
    u32 index = ov45_0222F314(config->index);

    if (connection == 0) {
        config->state = 4;
        ov49_0225EF8C(state, 0x17);
        return TRUE;
    }
    if (connection == 2) {
        *(u16 *)&work->data[8] = index;
        ov49_0225EF8C(state, 0x15);
        return TRUE;
    }
    if (work->data[7] != index) {
        work->data[7] = index;
        if (index != 4) {
            ov45_0222AC14(object, config->value, index, arg, 0, 0, 0, 0);
        }
    }
    *(s16 *)&work->data[0] = ov45_0222F3E8(config->index);
    if (*(s16 *)&work->data[0] == 0) {
        if (ov45_0222F314(config->index) <= 1) {
            config->state = 3;
            ov49_0225EF8C(state, 0x17);
            return TRUE;
        }
        ov49_0225EF8C(state, 0x16);
        return TRUE;
    }
    if (*(s16 *)&work->data[0] <= 0x14A) {
        ov49_0225EF8C(state, 0x14);
        return TRUE;
    }
    return FALSE;
}

void ov49_02262D70(Ov49Residual61State *work, void *ctx, u32 value, u32 mode, s32 amount) {
    if (mode >= 2) {
        GF_AssertFail();
    }
    work->data[0] = 0;
    work->data[1] = 0;
    work->data[2] = 0;
    work->data[3] = 0;
    work->data[4] = 0;
    work->data[5] = 0;
    work->data[6] = 0;
    work->data[7] = 0;
    work->data[6] = mode;
    work->data[3] = value;
    ov49_02262DD4(work, amount);
    ov49_0225A204(ctx, 0x12, 3, 0xD, ov49_02269DF8[mode]);
}

void ov49_02262DB8(Ov49Residual61State *work, void *ctx) {
    work->data[0] = 0;
    work->data[1] = 0;
    work->data[2] = 0;
    work->data[3] = 0;
    work->data[4] = 0;
    work->data[5] = 0;
    work->data[6] = 0;
    work->data[7] = 0;
    ov49_0225A22C(ctx);
}

void ov49_02262DD4(Ov49Residual61State *work, s32 amount) {
    s16 value = amount / 30;
    if (value != *(s16 *)&work->data[4]) {
        *(s16 *)&work->data[4] = value;
        work->data[7] |= 8;
    }
}
