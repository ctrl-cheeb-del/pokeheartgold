#include "global.h"

#include "sprite_system.h"
#include "system.h"
#include "touchscreen.h"

#define P(p, o)   (*(void **)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))

extern void ov57_02237EA8(void *);
extern void ov57_02237E90(void *, u8, u8);
extern void ov57_02238260(void *, u8);
extern void ov57_02238044(void *, u8);

void ov57_02237EB8(void *, ManagedSprite *, int);
void ov57_02237F14(void *);
void ov57_02237F3C(void *);

void ov57_02237EB8(void *work, ManagedSprite *sprite, int mode) {
    s16 x;
    s16 y;
    if (sprite == NULL) {
        return;
    }
    if (mode == 1) {
        ManagedSprite_SetPositionXY(sprite, gSystem.touchX, gSystem.touchY);
        ManagedSprite_GetPositionXY(sprite, &x, &y);
        ov57_02237EA8(work);
    } else {
        ManagedSprite_GetPositionXY(sprite, &x, &y);
        ov57_02237E90(work, (u8)x, (u8)y);
    }
}

void ov57_02237F14(void *work) {
    int i;
    u8 *slot = work;
    for (i = 0; i < 8; i++, slot += 0x10) {
        if (P(slot, 0x354) != NULL) {
            ManagedSprite_OffsetPositionXY(P(slot, 0x354), -0x38, 0x10);
        }
    }
}

void ov57_02237F3C(void *work) {
    u8 *entry = (u8 *)work + U32(work, 0x3EC) * 8;
    const u8 *values = P(entry, 8);
    int i = 0;
    u8 *slot = work;
    do {
        if (values[0] != 0) {
            U8(slot, 0x350) = values[0];
            U8(slot, 0x351) = values[1];
            U8(slot, 0x352) = values[2];
            ov57_02238260(work, (u8)i);
            ov57_02237EB8(P(slot, 0x358), P(slot, 0x354), 0);
            U32(slot, 0x34C) = 1;
        } else {
            U32(slot, 0x34C) = 0;
            U8(slot, 0x350) = 0;
        }
        i++;
        values += 3;
        slot += 0x10;
    } while (i < 8);
}
