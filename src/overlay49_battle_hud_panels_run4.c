#include "overlay49_battle_hud_panels_private.h"

#pragma require_prototypes off

extern void GF_AssertFail(void);

extern u32 ov49_02259FF0(void *p);
extern u32 ov49_02258DAC(void *p);
extern u32 ov49_02258E60(void *p, u32 a);
extern void ov49_0225A53C(void *p, u32 a);
extern void ov49_02259154(void *p, VecFx32 *v);
extern void ov49_02259148(void *p, const VecFx32 *v);
extern void ov49_0225CC20(void *p, u32 a, u32 b, u32 c);
extern void ov45_0222AE08(void *p, fx32 *a, fx32 *b);
extern void ov49_0225E420(void *p, fx32 a, fx32 b, VecFx32 *v);
extern u32 ov49_0225EF88(void *p);
extern void ov49_0225EF90(void *p);
extern u32 ov49_02259FE8(void *p);
extern u32 ov45_0222A330(void *p);
extern u32 ov45_0222A374(void *p);
extern u32 ov49_0225A30C(void *p, u32 a, u32 b);
extern void ov49_0225A08C(void *p, u32 a);
extern void PlaySE(u32 id);
extern u32 ov49_0225A0AC(void *p);
extern void ov49_0225A0EC(void *p);
extern void ov49_02258EEC(void *p, u32 a, u32 b);
extern u32 ov49_0225A520(void *p, fx32 a);
extern BOOL ov49_0225F438(void *p);
extern void ov49_0225F374(void *p);
extern void ov49_0225F430(void *p);
extern fx32 ov49_0225F394(void *p);
extern void ov49_0225A10C(void *p, u32 n);
extern void ov49_0225A40C(void *p, u32 a, u32 b);
extern void ov49_0225A144(void *p, u32 a, u32 b);
extern u32 ov49_0225A154(void *p);
extern const Ov49Blk ov49_02269C00;

void ov49_02261434(Ov49Hud *p, void *a) {
    VecFx32 v;
    fx32 y;
    fx32 x;
    ov45_0222AE08(p->unk00, &x, &y);
    ov49_0225E420(a, x, y, &v);
    ov49_02259148(p->unk0C, &v);
}

void ov49_02261460(Ov49Hud *p, u32 unused, void *a) {
    VecFx32 v;
    fx32 x;
    fx32 y;
    fx32 d;
    ov45_0222AE08(p->unk00, &x, &y);
    if (ov49_0225A520(a, x) == 1) {
        if (!ov49_0225F438(&p->unk10)) {
            ov49_0225F374(&p->unk10);
        }
    } else {
        if (ov49_0225F438(&p->unk10) == 1) {
            ov49_0225F430(&p->unk10);
        }
    }
    d = ov49_0225F394(&p->unk10);
    ov49_02259154(p->unk0C, &v);
    v.y += d;
    ov49_02259148(p->unk0C, &v);
}

void ov49_022614CC(Ov49Owner *q, void *p) {
    int i;
    ov49_0225A10C(p, 0x12);
    for (i = 1; i < 0x12; i++) {
        ov49_0225A40C(p, 0, i);
        ov49_0225A144(p, ov49_0225A30C(p, 1, 6), i);
    }
    ov49_0225A144(p, ov49_0225A30C(p, 1, 7), 0);
    q->unk08 = ov49_02269C00;
    q->unk08.w[0] = ov49_0225A154(p);
}
