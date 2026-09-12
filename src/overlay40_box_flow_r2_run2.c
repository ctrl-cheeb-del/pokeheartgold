#include "global.h"

typedef struct TouchHitboxController TouchHitboxController;
typedef void (*TouchCallback)(u32, u32, void *);

void ov40_0222BF94(void *);
void ov40_0222BF64(void *, u32, u32, u32);
void ov40_0222BF80(void *, u32);
void sub_02087A84(void *, u32, u32);
void ov40_0222DD9C(void *, u32);
BOOL ov40_0222DD94(void);
void *Save_FashionData_Get(void *);
void *sub_0202B9B8(void *, u32);
BOOL sub_0202BC10(void *);
void PlaySE(u32);
void ov40_0222C23C(u32, u32, void *);
TouchHitboxController *TouchHitboxController_Create(const void *, u32, TouchCallback, void *, u32);
void ManagedSprite_GetPositionXY(void *, s16 *, s16 *);

#define U32_AT(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))

BOOL ov40_0222BFB0(void *p);
BOOL ov40_0222C018(void *p);
void ov40_0222C03C(void *p);
BOOL ov40_0222C15C(void *p);
void ov40_0222C360(void *p);
void ov40_0222C39C(void *p);
void ov40_0222C434(void *p);

void ov40_0222C360(void *p) {
    s32 i = 0;
    u8 *hitbox = (u8 *)p + 0x30;
    u8 *row = p;

    do {
        i++;
        PTR_AT(row, 0x60C) = hitbox;
        hitbox += 4;
        row += 0x28;
    } while (i < 5);
    PTR_AT(p, 0x2C) = TouchHitboxController_Create((u8 *)p + 0x30, 5, ov40_0222C23C, p, 0x6D);
}

void ov40_0222C39C(void *p) {
    s16 pos[2];
    u32 offset;
    s32 i;
    u32 zero;
    u8 *row;

    if (PTR_AT(p, 0x818) == NULL) {
        return;
    }
    offset = 0;
    row = p;
    i = offset;
    zero = offset;
    do {
        if (*(void **)((u8 *)PTR_AT(p, 0x818) + offset) == NULL) {
            *(u8 *)PTR_AT(row, 0x60C) = zero;
            *((u8 *)PTR_AT(row, 0x60C) + 1) = zero;
            *((u8 *)PTR_AT(row, 0x60C) + 2) = zero;
            *((u8 *)PTR_AT(row, 0x60C) + 3) = zero;
        } else {
            ManagedSprite_GetPositionXY(PTR_AT(row, 0x5FC), &pos[1], &pos[0]);
            *(u8 *)PTR_AT(row, 0x60C) = pos[0] - 16;
            *((u8 *)PTR_AT(row, 0x60C) + 1) = pos[0] + 16;
            *((u8 *)PTR_AT(row, 0x60C) + 2) = pos[1];
            *((u8 *)PTR_AT(row, 0x60C) + 3) = pos[1] + 160;
        }
        offset += 0x24;
        i++;
        row += 0x28;
    } while (i < 5);
}

void ov40_0222C434(void *p) {
    s16 pos[2];
    s32 i = 0;
    u32 zero = i;
    u8 *row = p;

    do {
        ManagedSprite_GetPositionXY(PTR_AT(row, 0x5FC), &pos[1], &pos[0]);
        *(u8 *)PTR_AT(row, 0x60C) = zero;
        *((u8 *)PTR_AT(row, 0x60C) + 1) = zero;
        *((u8 *)PTR_AT(row, 0x60C) + 2) = zero;
        *((u8 *)PTR_AT(row, 0x60C) + 3) = zero;
        i++;
        row += 0x28;
    } while (i < 5);
}
