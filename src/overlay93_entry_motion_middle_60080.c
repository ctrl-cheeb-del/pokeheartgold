#include "global.h"

#include "sprite_system.h"

typedef struct Ov93Entry {
    u32 active;
    s16 value4;
    u16 value6;
    s32 value8;
    s16 delay;
    u8 kind;
    u8 padF;
    ManagedSprite *sprite;
    const u8 *config;
} Ov93Entry;

extern u32 sub_0203769C(void);
extern const s32 ov93_02262CA4[];
extern u32 ov93_022614F4(void *sys, void **out);
extern void ov93_02260FB8(void *sys, u32 kind);
extern void *ov93_02260F84(void *sys);
extern void ov93_02261528(void *entry, u8 state);
extern void ov93_022627E8(void *sys, const void *body);

BOOL ov93_02260080(void *sys, Ov93Entry *entry);

BOOL ov93_02260080(void *sys, Ov93Entry *entry) {
    s16 nextX;
    s16 nextY;
    s16 x;
    s16 y;
    void *target;
    void *nextTarget;
    int remaining;
    int previous;
    BOOL done = FALSE;
    s32 value;
    float scale;

    ManagedSprite_GetPositionXYWithSubscreenOffset(entry->sprite, &x, &y, 0x160000);
    switch (entry->config[7]) {
    case 0:
        previous = 28 - y;
        ManagedSprite_AddSpritePrecisePositionXY(entry->sprite, 0, 5 << 12);
        ManagedSprite_GetPositionXYWithSubscreenOffset(entry->sprite, &nextX, &nextY, 0x160000);
        remaining = 28 - nextY;
        if (nextY > 74) {
            done = TRUE;
        }
        break;
    case 1:
        previous = x - 204;
        ManagedSprite_AddSpritePrecisePositionXY(entry->sprite, -5 << 12, 0);
        ManagedSprite_GetPositionXYWithSubscreenOffset(entry->sprite, &nextX, &nextY, 0x160000);
        remaining = nextX - 204;
        if (nextX < 152) {
            done = TRUE;
        }
        break;
    case 2:
        previous = y - 164;
        ManagedSprite_AddSpritePrecisePositionXY(entry->sprite, 0, -5 << 12);
        ManagedSprite_GetPositionXYWithSubscreenOffset(entry->sprite, &nextX, &nextY, 0x160000);
        remaining = nextY - 164;
        if (nextY < 114) {
            done = TRUE;
        }
        break;
    case 3:
        previous = 52 - x;
        ManagedSprite_AddSpritePrecisePositionXY(entry->sprite, 5 << 12, 0);
        ManagedSprite_GetPositionXYWithSubscreenOffset(entry->sprite, &nextX, &nextY, 0x160000);
        remaining = 52 - nextX;
        if (nextX > 104) {
            done = TRUE;
        }
        break;
    }

    if (remaining >= 0) {
        if (remaining < 14) {
            value = (remaining << 12) / 14;
            if (value < (1 << 10)) {
                value = 1 << 10;
            }
            scale = (float)value / 4096.0f;
            ManagedSprite_SetAffineScale(entry->sprite, scale, scale);
        }
    } else if (remaining > -14) {
        value = (-remaining * ov93_02262CA4[entry->kind]) / 14;
        if (value < (1 << 10)) {
            value = 1 << 10;
        }
        scale = (float)value / 4096.0f;
        ManagedSprite_SetAffineScale(entry->sprite, scale, scale);
    }

    if (entry->value4 == sub_0203769C() && previous >= 0 && remaining <= 0) {
        entry->kind = ov93_022614F4(sys, &target);
        switch (entry->kind) {
        case 1:
            entry->value8 *= 2;
            break;
        case 2:
            entry->value8 /= 2;
            break;
        case 3:
            entry->value8 *= 3;
            break;
        }
        ov93_02260FB8(sys, entry->kind);
        if (entry->kind != 0) {
            ov93_02261528(target, 3);
        }
        nextTarget = ov93_02260F84(sys);
        if (nextTarget != NULL) {
            ov93_022627E8(sys, nextTarget);
        }
    }
    if (done == TRUE) {
        return TRUE;
    }
    return FALSE;
}
