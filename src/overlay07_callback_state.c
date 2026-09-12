#include "global.h"

#include "sprite_system.h"

typedef struct Ov07CallbackWork {
    u8 pad00[8];
    u32 state;
    u8 pad0C[0x1C - 0x0C];
    void *active;
    u8 pad20[4];
    u32 tickSprite;
    u8 pad28[4];
    SpriteManager *spriteSystem;
    ManagedSprite *sprite;
    u8 pad34[0x98 - 0x34];
    u32 callbackId;
    u8 pad9C[0xB8 - 0x9C];
    s16 spriteX;
    s16 spriteY;
    u8 padBC[0xDC - 0xBC];
    s32 delay;
} Ov07CallbackWork;

typedef BOOL (*Ov07StateCallback)(Ov07CallbackWork *);

BOOL ov07_022335B4(Ov07CallbackWork *);
BOOL ov07_02233874(Ov07CallbackWork *);
BOOL ov07_02233C98(Ov07CallbackWork *);
BOOL ov07_022335A0(Ov07CallbackWork *);
BOOL ov07_02233D24(Ov07CallbackWork *);
BOOL ov07_02233B04(Ov07CallbackWork *);
void ov07_02233D60(void *, Ov07CallbackWork *);

extern const Ov07StateCallback ov07_022371A0[];

BOOL ov07_02233D24(Ov07CallbackWork *work) {
    s16 x;
    s16 y;

    if (work->state == 0xFF) {
        return FALSE;
    }
    if (work->sprite != NULL) {
        ManagedSprite_GetPositionXY(work->sprite, &x, &y);
        work->spriteX = x;
        work->spriteY = y;
    }
    return TRUE;
}

void ov07_02233D60(void *task, Ov07CallbackWork *work) {
    if (work->active != NULL) {
        if (work->delay > 0) {
            work->delay--;
            SpriteSystem_DrawSprites(work->spriteSystem);
            return;
        }
        if (!ov07_022371A0[work->callbackId](work)) {
            work->active = NULL;
        }
        if (work->tickSprite == TRUE) {
            ManagedSprite_TickFrame(work->sprite);
        }
        SpriteSystem_DrawSprites(work->spriteSystem);
    }
}
