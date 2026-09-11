#include "global.h"

typedef struct Ov45Context {
    u8 filler_00[8];
    u8 inner[0x54];
    u8 effects[1];
} Ov45Context;

typedef struct Ov45Point {
    u32 x;
    u32 y;
    u16 width;
    u16 height;
} Ov45Point;

typedef struct Ov45EffectArgsA {
    Ov45Point point;
    u32 kind;
} Ov45EffectArgsA;

typedef struct Ov45EffectArgsB {
    u32 type;
    u32 value;
    u32 x;
    u32 y;
    u32 x2;
    u32 y2;
    u16 width;
    u16 height;
    u16 width2;
    u16 height2;
    u32 enabled;
} Ov45EffectArgsB;

typedef struct Ov45EffectArgsC {
    u32 kind;
    u32 id;
    u32 x;
    u16 width;
} Ov45EffectArgsC;

typedef struct Ov45EffectArgsD {
    u32 id;
    u32 value;
    u32 x;
    u32 y;
    u32 x2;
    u16 width;
    u16 height;
    u16 width2;
    u16 height2;
} Ov45EffectArgsD;

extern const u8 ov45_02254BC8[];
extern const u32 ov45_02254BDC[];

u32 ov45_0222DE58(void *, ...);
u32 ov45_0222DF14(void *);
u32 ov45_0222DF38(void *, int);
void ov45_0222DE74(void *, int);
void ov45_0222DE8C(void *, int, u32);
void *ov45_0222E04C(void *, u16);
void ov45_0222E0A4(void *, void *);
void ov45_0222E0E0(void *, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32);
BOOL ov45_0222E5B4(u32, u32);

void ov45_0222D8C8(Ov45Context *);
u32 ov45_0222D8D4(Ov45Context *, int);
void ov45_0222D8F0(Ov45Context *, int);
void ov45_0222D940(Ov45Context *, Ov45Point *);
void ov45_0222D990(Ov45Context *, Ov45EffectArgsA *);
void ov45_0222D9EC(Ov45Context *, Ov45EffectArgsB *);
void ov45_0222DA80(Ov45Context *, Ov45EffectArgsC *);
void ov45_0222DAE0(Ov45Context *, Ov45EffectArgsD *);
void ov45_0222DB3C(Ov45Context *, Ov45EffectArgsD *);
void ov45_0222DB98(Ov45Context *, Ov45EffectArgsC *);
void ov45_0222DC08(Ov45Context *, Ov45EffectArgsC *, const u8 *);
void ov45_0222DC64(Ov45Context *, Ov45EffectArgsB *);

u32 ov45_0222D8D4(Ov45Context *ctx, int arg) {
    u32 result = ov45_0222DF14(ctx->inner);
    ov45_0222DE74(ctx->inner, arg);
    return result;
}

void ov45_0222D8F0(Ov45Context *ctx, int index) {
    int i;
    for (i = 0; i < 20; i++) {
        u32 value = ov45_0222DF38(ctx->inner, i);
        if (value & 2) {
            ov45_0222DE8C(ctx->inner, i, value & ~2);
        }
    }
    ov45_0222DE8C(ctx->inner, index, ov45_0222DF38(ctx->inner, index) | 2);
}

void ov45_0222D940(Ov45Context *ctx, Ov45Point *args) {
    void *effect = ov45_0222E04C(ctx->effects, 8);
    if (effect != NULL) {
        ov45_0222E0E0(effect, 0, 0, 0, args->x, args->y, 0, 0, args->width, args->height, 0, 0, 600, 8, 0);
        ov45_0222E0A4(ctx->effects, effect);
    }
}

void ov45_0222D990(Ov45Context *ctx, Ov45EffectArgsA *args) {
    void *effect;
    if (args->kind >= 27) {
        return;
    }
    effect = ov45_0222E04C(ctx->effects, 7);
    if (effect != NULL) {
        ov45_0222E0E0(effect, args->kind, 0, 0, args->point.x, args->point.y, 0, 0, args->point.width, args->point.height, 0, 0, 600, 7, 1);
        ov45_0222E0A4(ctx->effects, effect);
    }
}

void ov45_0222D9EC(Ov45Context *ctx, Ov45EffectArgsB *args) {
    u32 type = args->type;
    u32 resource;
    void *effect;
    if (type != 0 && type != 1 && type != 2) {
        return;
    }
    if (args->enabled == 1) {
        if (args->value < 2 || args->value > 4) {
            return;
        }
    } else if (args->value < 1 || args->value > 4) {
        return;
    }
    resource = ov45_02254BDC[type];
    effect = ov45_0222E04C(ctx->effects, (u16)resource);
    if (effect != NULL) {
        ov45_0222E0E0(effect, type, args->value, args->enabled, args->x, args->y, args->x2, args->y2, args->width, args->height, args->width2, args->height2, 900, resource, 2);
        ov45_0222E0A4(ctx->effects, effect);
    }
}

void ov45_0222DA80(Ov45Context *ctx, Ov45EffectArgsC *args) {
    void *effect;
    if (args->kind != 3 && args->kind != 4) {
        return;
    }
    effect = ov45_0222E04C(ctx->effects, (u16)(args->kind + 5));
    if (effect != NULL) {
        ov45_0222E0E0(effect, args->kind, args->id, 0, args->x, 0, 0, 0, args->width, 0, 0, 0, 900, args->kind + 5, 3);
        ov45_0222E0A4(ctx->effects, effect);
    }
}

void ov45_0222DAE0(Ov45Context *ctx, Ov45EffectArgsD *args) {
    void *effect = ov45_0222E04C(ctx->effects, 12);
    if (effect != NULL) {
        ov45_0222E0E0(effect, args->id, 0, 0, args->value, args->x, args->y, args->x2, args->width, args->height, args->width2, args->height2, 450, 12, 4);
        ov45_0222E0A4(ctx->effects, effect);
    }
}

void ov45_0222DB3C(Ov45Context *ctx, Ov45EffectArgsD *args) {
    void *effect = ov45_0222E04C(ctx->effects, 13);
    if (effect != NULL) {
        ov45_0222E0E0(effect, args->id, 0, 0, args->value, args->x, args->y, args->x2, args->width, args->height, args->width2, args->height2, 450, 13, 5);
        ov45_0222E0A4(ctx->effects, effect);
    }
}

void ov45_0222DB98(Ov45Context *ctx, Ov45EffectArgsC *args) {
    void *effect;
    switch (args->id) {
    case 3:
        return;
    case 0:
    case 1:
    case 2:
    case 4:
        break;
    default:
        return;
    }
    effect = ov45_0222E04C(ctx->effects, 14);
    if (effect != NULL) {
        ov45_0222E0E0(effect, *(u32 *)args->kind, args->id, 0, 0, 0, 0, 0, 0, 0, 0, 0, 900, 14, 6);
        ov45_0222E0A4(ctx->effects, effect);
    }
}

void ov45_0222DC08(Ov45Context *ctx, Ov45EffectArgsC *args, const u8 *enabled) {
    void *effect;
    if (args->kind >= 20 || enabled[args->kind] == 0) {
        return;
    }
    effect = ov45_0222E04C(ctx->effects, 1);
    if (effect != NULL) {
        ov45_0222E0E0(effect, args->kind, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x708, 1, 7);
        ov45_0222E0A4(ctx->effects, effect);
    }
}

void ov45_0222DC64(Ov45Context *ctx, Ov45EffectArgsB *args) {
    u32 type;
    u32 resource;
    void *effect;
    if ((args->type != 0 && args->type != 1 && args->type != 2)
        || !ov45_0222E5B4(*(volatile u32 *)&args->type, args->value)) {
        return;
    }
    type = args->type;
    resource = ov45_02254BC8[type];
    effect = ov45_0222E04C(ctx->effects, resource);
    if (effect != NULL) {
        ov45_0222E0E0(effect, type, args->value, 0, args->x, args->y, args->x2, args->y2, args->width, args->height, args->width2, args->height2, 450, resource, 8);
        ov45_0222E0A4(ctx->effects, effect);
    }
}
