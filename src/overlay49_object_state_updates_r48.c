#include "overlay49_object_state_updates_r48_private.h"

#pragma require_prototypes off

extern BOOL ov49_0225E9D0(void *p, u8 x, u8 y);
extern u32 ov49_0225D1C0(void *p);
extern void ov49_0225EAB4(void *p, void *obj);
extern void ov49_0225EA70(void *p, void *obj);
extern void ov49_0225D4A0(void *ctx, void *obj, u32 v);
extern void ov49_0225D4C8(void *obj, u32 v);
extern void ov49_0225D214(void *ctx, void *obj, u32 index, u32 v);
extern void ov49_0225D328(void *ctx, void *obj, u32 index);
extern void ov49_0225D494(void *obj, u32 v);

void ov49_0225E58C(void *p, u8 a, u8 b) {
    int i;
    for (i = 0; i < U8_AT(p, 0x612); i++) {
        BOOL t1 = ov49_0225E9D0((void *)U32_AT((u32 *)p + i, 8), a - 1, b - 1);
        BOOL t2 = ov49_0225E9D0((void *)U32_AT((u32 *)p + i, 8), a, b - 1);
        if (t1 == 1 || t2 == 1) {
            switch (ov49_0225D1C0((void *)U32_AT((u32 *)p + i, 8))) {
            case 1:
            case 2:
            case 3:
            case 4:
                if (U8_AT(p, 0x611) == 4) {
                    ov49_0225EAB4(p, (void *)U32_AT((u32 *)p + i, 8));
                } else {
                    ov49_0225EA70(p, (void *)U32_AT((u32 *)p + i, 8));
                }
                break;
            }
        }
    }
}

void ov49_0225E624(void *p, int a) {
    int i;
    for (i = 0; i < U8_AT(p, 0x612); i++) {
        switch (ov49_0225D1C0((void *)U32_AT((u32 *)p + i, 8))) {
        case 1:
        case 2:
        case 3:
        case 4:
            if (a == 1) {
                ov49_0225D4A0((void *)U32_AT(p, 4), (void *)U32_AT((u32 *)p + i, 8), 1);
            }
            break;
        case 15:
            if (a == 1) {
                ov49_0225D4C8((void *)U32_AT((u32 *)p + i, 8), 0x800);
                ov49_0225D214((void *)U32_AT(p, 4), (void *)U32_AT((u32 *)p + i, 8), 0, 6);
                ov49_0225D214((void *)U32_AT(p, 4), (void *)U32_AT((u32 *)p + i, 8), 1, 6);
                ov49_0225D214((void *)U32_AT(p, 4), (void *)U32_AT((u32 *)p + i, 8), 2, 6);
                ov49_0225D494((void *)U32_AT((u32 *)p + i, 8), 1);
            } else {
                ov49_0225D328((void *)U32_AT(p, 4), (void *)U32_AT((u32 *)p + i, 8), 0);
                ov49_0225D328((void *)U32_AT(p, 4), (void *)U32_AT((u32 *)p + i, 8), 1);
                ov49_0225D328((void *)U32_AT(p, 4), (void *)U32_AT((u32 *)p + i, 8), 2);
                ov49_0225D494((void *)U32_AT((u32 *)p + i, 8), 0);
            }
            break;
        }
    }
}
