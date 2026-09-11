#include "overlay49_table_helpers_private.h"

void ov49_02264CFC(Config49 *cfg, u8 timer, u8 action, void *object, u8 value) {
    cfg->timer6 = timer;
    cfg->action7 = action;
    ov49_0225EF8C(object, value);
}

void ov49_02264D14(Config49 *cfg, void *object) {
    if (cfg->timer6 != 0) cfg->timer6--;
    else ov49_0225EF8C(object, cfg->action7);
}

void ov49_02264D30(Config49 *cfg, void *object, void *check) {
    if (ov49_0225A0AC(check)) ov49_0225EF8C(object, cfg->action7);
}

void ov49_02264D4C(void *unused0, void *unused1, void *ctx, void *arg, void *a, void *b) {
    u32 ai;
    u32 bi;
    u32 value;
    ov49_02264D9C(ctx, 0, arg, a);
    ov49_02264D9C(ctx, 1, arg, b);
    ai = ov45_0222AA10(a);
    bi = ov45_0222AA10(b);
    value = ov49_02269E44[ai][bi];
    ov49_0225A08C(ctx, ov49_0225A30C(ctx, 3, value));
}

void ov49_02264D9C(void *ctx, u32 index, void *arg, void *value) {
    switch (ov45_0222AA10(value)) {
    case 1: ov49_0225A3AC(ctx, index, arg); return;
    case 2: ov49_0225A3BC(ctx, index, arg); return;
    case 3: ov49_0225A3CC(ctx, index, arg); return;
    case 4: ov49_0225A3DC(ctx, index, arg); return;
    case 5: ov49_0225A3EC(ctx, index, arg); return;
    case 7: ov49_0225A3FC(ctx, index, arg); return;
    default: ov49_0225A3BC(ctx, index, arg); return;
    }
}

BOOL ov49_02264E20(Config49 *cfg, void *object, void *ctx) {
    void *a = ov45_0222A5C0(object);
    void *b = ov45_0222A578(object, cfg->index3);
    u32 action;
    if (ov45_0222AA28(a) == 0) return FALSE;
    if (ov45_0222AA28(b) == 0) return FALSE;
    if (cfg->value4 != cfg->value5) {
        switch (cfg->value5) {
        case 0: action = 0x27; break;
        case 1: action = 0x25; break;
        case 2: action = 0x26; break;
        }
        ov49_0225A08C(ctx, ov49_0225A30C(ctx, 3, action));
        return TRUE;
    }
    return FALSE;
}

void ov49_02264E90(Config49 *cfg, void *object, void *ctx, void *arg, u32 which) {
    void *a = ov45_0222A5C0(object);
    void *b = ov45_0222A578(object, cfg->index3);
    void *selected;
    if (which == 0) selected = ov45_0222AAC8(b);
    else selected = ov45_0222AAC8(a);
    ov49_0225A39C(ctx, selected, arg);
}

void ov49_02264EC8(Config49 *cfg, void *object) {
    ov49_02259FE8(object);
    if (ov45_0222B094() == 0x1c2) {
        ov49_0225A0CC(object);
        ov49_0225A334(object, cfg->index3, 0);
        ov49_0225A08C(object, ov49_02264C04(object, cfg->index3, 0x2ac));
        ov49_0225A0BC(object);
    }
}
