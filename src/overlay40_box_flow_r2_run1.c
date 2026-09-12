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

BOOL ov40_0222BFB0(void *p) {
    PTR_AT(p, 0x81C + U32_AT(p, 0x6D8) * 4) = PTR_AT(p, 0x818);
    PTR_AT(p, 0x6C4 + U32_AT(p, 0x6D8) * 4) = (u8 *)PTR_AT(p, 0x818) + U32_AT(p, 0x6E4) * 0x24;
    PTR_AT(p, 0x818) = *(void **)((u8 *)PTR_AT(p, 0x818) + U32_AT(p, 0x6E4) * 0x24 + 0x20);
    U32_AT(p, 0x6D8)
    ++;
    U32_AT(p, 0x6E4) = 0;
    if (PTR_AT(p, 0x818) == NULL) {
        return FALSE;
    }
    ov40_0222BF94(p);
    return TRUE;
}

BOOL ov40_0222C018(void *p) {
    u32 idx = U32_AT(p, 0x6D8);
    PTR_AT(p, 0x818) = PTR_AT(p, 0x81C + idx * 4);
    ov40_0222BF94(p);
    return TRUE;
}

void ov40_0222C03C(void *p) {
    u32 index = U32_AT(p, 0x6E4);
    u8 *record = (u8 *)PTR_AT(p, 0x818) + index * 0x24;

    switch (U32_AT(record, 0x10)) {
    case 2:
        sub_02087A84(PTR_AT(p, 0x868), 0, 0);
        ov40_0222BF80(p, 2);
        break;
    case 4:
        ov40_0222BF64(p, 2, 1, U32_AT(p, 0x10));
        break;
    case 5:
        ov40_0222BF64(p, 3, 1, U32_AT(p, 0x10));
        break;
    case 8:
        ov40_0222BF64(p, 4, 1, U32_AT(p, 0x10));
        break;
    case 9:
        ov40_0222BF64(p, 5, 1, U32_AT(p, 0x10));
        break;
    case 10:
        ov40_0222BF64(p, 6, 1, U32_AT(p, 0x10));
        break;
    case 11:
        ov40_0222BF64(p, 7, 1, U32_AT(p, 0x10));
        break;
    case 12:
        ov40_0222BF64(p, 8, 1, U32_AT(p, 0x10));
        break;
    case 13:
        ov40_0222BF64(p, 9, 1, U32_AT(p, 0x10));
        break;
    case 14:
        ov40_0222BF64(p, 10, 1, U32_AT(p, 0x10));
        break;
    case 15:
        ov40_0222BF64(p, 11, 1, U32_AT(p, 0x10));
        break;
    case 16:
        ov40_0222BF64(p, 12, 1, U32_AT(p, 0x10));
        break;
    case 17:
        ov40_0222BF64(p, 13, 1, U32_AT(p, 0x10));
        break;
    case 18:
        ov40_0222BF64(p, 14, 1, U32_AT(p, 0x10));
        break;
    case 19:
        ov40_0222BF64(p, 15, 1, U32_AT(p, 0x10));
        break;
    case 7:
        ov40_0222BF64(p, 17, 1, U32_AT(p, 0x10));
        break;
    }
}

BOOL ov40_0222C15C(void *p) {
    u32 index = U32_AT(p, 0x6E4);
    u8 *record = (u8 *)PTR_AT(p, 0x818) + index * 0x24;
    u32 value = U32_AT(record, 0x18);
    BOOL result = TRUE;

    switch (U32_AT(p, 0)) {
    default:
        if (value <= 3 && PTR_AT(p, 0x87C + value * 4) == NULL) {
            ov40_0222DD9C(p, 0x10D);
            result = FALSE;
        }
        break;
    case 5:
        if (value == 0) {
            void *fashion = Save_FashionData_Get(PTR_AT(p, 0x830));
            result = sub_0202BC10(sub_0202B9B8(fashion, value));
            if (!result) {
                ov40_0222DD9C(p, 0x122);
            }
        }
        break;
    case 6:
        if (value == 100 && ov40_0222DD94()) {
            ov40_0222DD9C(p, 0x111);
            result = FALSE;
        }
        break;
    case 2:
        if (value == 9999 && PTR_AT(p, 0x87C) == NULL) {
            ov40_0222DD9C(p, 0x81);
            result = FALSE;
        }
        break;
    case 3:
    case 4:
        break;
    }
    if (!result) {
        PlaySE(0x57C);
    } else {
        PlaySE(0x57B);
    }
    return result;
}
