#include "to47_overlay49_r60_state_pair.h"

#include "global.h"

#pragma require_prototypes off

typedef struct Ov49R60Input {
    u8 x;
    u8 y;
    u8 expected;
    u8 mode;
    u8 enabled;
} Ov49R60Input;

typedef struct Ov49R60Coord {
    u16 x;
    u16 y;
} Ov49R60Coord;

extern void *ov49_0225EF3C(void *);
extern void ov49_0225EF8C(void *, u32);
extern u32 ov49_0225EF88(void *);
extern void ov49_0225EF90(void *);
extern void *ov49_02259FE8(void *);
extern void *ov49_02259FF0(void *);
extern void *ov49_02258D70(void *, u32);
extern void *ov49_02258DAC(void *);
extern u32 ov49_02258E34(void *);
extern void ov49_0225913C(void *, Ov49R60Coord *);
extern u32 ov49_022591CC(void *);
extern void ov49_022591C0(void *, u32);
extern u32 ov49_02258F38(void *);
extern void ov49_02258EEC(void *, void *, u32);
extern void ov49_0225A04C(void *, u8, u32);
extern void ov49_0225A06C(void *, u8, u32);
extern u32 ov45_0222B0B0(void *);
extern void *ov45_0222A5C0(void *);
extern u8 ov45_0222A920(void *);
extern void ov45_0222B0A4(void *);
extern void ov49_02258E60(void *, u32);
extern u32 ov42_022282A4(void);
extern void ov49_02258EAC(void *, void *, u32, u32);
extern void *ov45_0222A578(void *, u32);
extern u32 ov45_0222AFF8(void *);
extern u32 ov45_0222A2A0(void *, u32);
extern u32 ov49_02258FDC(void *, u8, u8);
extern void ov49_02258DB4(void *, Ov49R60Coord);

extern void *ov49_0225EF84(void *);
extern void *ov49_0225EF40(void *, u32);
extern void ov49_0225EF68(void *);
extern void ov49_0225EF98(void *, u32, const void *, u32);
extern void *ov49_02259FF8(void *);
extern int ov45_0222ADA8(void *, u32);
extern void ov45_0222AE08(int, int *, int *);
extern void ov49_0225E420(void *, int, int, VecFx32 *);
extern void ov49_02259154(void *, VecFx32 *);
extern void ov49_02259148(void *, VecFx32 *);
extern void ov49_02259184(void *, u32);
extern void ov49_022591B4(void *, u32);
extern void ov49_02259160(void *, u32);
extern void ov49_02258D54(void *);
extern u32 ov49_0225A520(void *, int);
extern BOOL ov49_0225F438(void *);
extern void ov49_0225F374(void *);
extern void ov49_0225F430(void *);
extern fx32 ov49_0225F394(void *);
extern int ov45_0222AD80(void *, int);
extern void *ov49_0225A010(void *);
extern void PlaySE(u16);
extern u8 ov49_02269B78[];

typedef struct Ov49R60Work {
    void *unk00;
    int unk04;
    int unk08;
    fx32 unk0C;
    fx32 unk10;
    int unk14;
    u8 unk18[8];
} Ov49R60Work;

BOOL ov49_02261930(void *state, void *ctx, u32 index) {
    void *map;
    void *third;
    void *field;
    VecFx32 vecD;
    VecFx32 vecC;
    VecFx32 vecB;
    VecFx32 vecA;
    Ov49R60Work *work;
    BOOL done;
    fx32 delta;
    fx32 offset;

    field = ov49_02259FE8(ctx);
    map = ov49_02259FF0(ctx);
    third = ov49_02259FF8(ctx);
    work = (Ov49R60Work *)ov49_0225EF84(state);

    switch (ov49_0225EF88(state)) {
    case 0:
        work = (Ov49R60Work *)ov49_0225EF40(state, 0x20);
        work->unk00 = ov49_02258D70(map, index);
        work->unk04 = ov45_0222ADA8(field, index);
        GF_ASSERT(work->unk04 != -1);
        ov45_0222AE08(work->unk04, &work->unk04, &work->unk08);
        ov49_02258EEC(map, work->unk00, 3);
        ov49_0225EF8C(state, 1);
        break;
    case 1:
        if (ov49_02258F38(work->unk00) != 0) {
            ov49_0225E420(third, work->unk04, work->unk08, &vecD);
            work->unk10 = vecD.x - 0x10000;
            ov49_02259154(work->unk00, &vecD);
            work->unk0C = vecD.y;
            work->unk14 = 0;
            {
                Ov49R60Coord coord = { 0 };
                ov49_02258DB4(work->unk00, coord);
            }
            PlaySE(0x64E);
            ov49_02259184(work->unk00, 1);
            ov49_0225EF8C(state, 2);
        }
        break;
    case 2:
        done = FALSE;
        work->unk14++;
        if (work->unk14 >= 0x18) {
            work->unk14 = 0x18;
            done = TRUE;
        }
        ov49_0225E420(third, work->unk04, work->unk08, &vecC);
        vecB.z = vecC.z;
        vecB.x = work->unk10;
        delta = vecC.y - work->unk0C;
        vecB.y = FX_Div(FX_Mul(FX_F32_TO_FX32(work->unk14), delta), 0x18000);
        vecB.y += work->unk0C;
        ov49_02259148(work->unk00, &vecB);
        if (done == TRUE) {
            ov49_02259184(work->unk00, 0);
            ov49_022591B4(work->unk00, 8);
            ov49_02259160(work->unk00, 2);
            ov49_0225EF8C(state, 3);
        }
        break;
    case 3:
        if (ov49_0225A520(ctx, work->unk04) == 1) {
            if (ov49_0225F438(work->unk18) == 0) {
                ov49_0225F374(work->unk18);
            }
        } else if (ov49_0225F438(work->unk18) == 1) {
            ov49_0225F430(work->unk18);
        }
        offset = ov49_0225F394(work->unk18);
        ov49_0225E420(third, work->unk04, work->unk08, &vecA);
        vecA.y += offset;
        ov49_02259148(work->unk00, &vecA);
        if (ov45_0222AD80(field, work->unk04) == 2) {
            ov49_0225EF8C(state, 4);
        }
        break;
    case 4:
        ov49_02258D54(work->unk00);
        ov49_0225EF68(state);
        ov49_0225EF98(ov49_0225A010(ctx), index, ov49_02269B78, 0);
        break;
    }
    return FALSE;
}

BOOL ov49_02261B74(void *state, void *ctx, u32 index) {
    void *map;
    void *field;
    BOOL shouldAdvance;
    Ov49R60Coord current;
    Ov49R60Coord coord;
    Ov49R60Coord packedCoord;
    void *work;
    void *object;
    void *manager;

    work = ov49_0225EF3C(state);
    field = ov49_02259FE8(ctx);
    map = ov49_02259FF0(ctx);
    object = ov49_02258D70(map, index);
    manager = ov49_02258DAC(map);

    switch (ov49_0225EF88(state)) {
    case 0:
        if (((Ov49R60Input *)work)->enabled == 0) {
            ov49_0225EF90(state);
        } else {
            ov49_0225EF8C(state, 3);
        }
        break;
    case 1:
        ov49_02258EEC(map, object, 3);
        ov49_0225EF90(state);
        break;
    case 2:
    case 7:
    case 9:
        if (ov49_02258F38(object) == TRUE) {
            ov49_0225EF90(state);
        }
        break;
    case 3: {
        u32 packed = ov49_02258E34(object);
        packedCoord.x = packed;
        packedCoord.y = packed >> 16;
        current = packedCoord;
        ov49_0225913C(object, &current);
        if (ov49_022591CC(object) == 0) {
            ov49_022591C0(object, 1);
        }
        ov49_02258EEC(map, object, 4);
        ov49_0225EF90(state);
        break;
    }
    case 4:
        if (ov49_02258F38(object) == TRUE) {
            ov49_0225EF90(state);
            ov49_02258EEC(map, object, 0);
            ov49_0225A04C(ctx, index, 0);
            ov49_0225A06C(ctx, index, 0);
        }
        break;
    case 5:
        shouldAdvance = FALSE;
        if (((Ov49R60Input *)work)->mode == 1 && ov45_0222B0B0(field) == 0 && ov45_0222A920(ov45_0222A5C0(field)) == 9) {
            ov45_0222B0A4(field);
            ov49_02258E60(object, 6);
            ov49_02258EAC(map, manager, 0, ov42_022282A4());
        }
        object = ov45_0222A578(field, index);
        if (object == NULL) {
            shouldAdvance = TRUE;
        } else if (((Ov49R60Input *)work)->mode == 1 && ov45_0222AFF8(field) == 0) {
            shouldAdvance = TRUE;
        } else if (ov45_0222A2A0(field, index) != 0) {
            u8 kind = ov45_0222A920(object);
            if (kind != ((Ov49R60Input *)work)->expected) {
                shouldAdvance = TRUE;
            }
        }
        if (shouldAdvance == TRUE) {
            ov49_0225EF90(state);
            ov49_0225A04C(ctx, index, 1);
            ov49_0225A06C(ctx, index, 1);
        }
        break;
    case 6:
        ov49_02258EEC(map, object, 3);
        ov49_0225EF90(state);
        break;
    case 8:
        if (ov49_02258FDC(ov49_02258DAC(map), ((Ov49R60Input *)work)->x, ((Ov49R60Input *)work)->y) == 0) {
            coord.x = ((Ov49R60Input *)work)->x << 4;
            coord.y = ((Ov49R60Input *)work)->y << 4;
            ov49_02258DB4(object, coord);
            ov49_0225913C(object, &coord);
            ov49_02258EEC(map, object, 4);
            ov49_0225EF90(state);
        }
        break;
    case 10:
        ov49_02258EEC(map, object, 2);
        ov49_0225A04C(ctx, index, 0);
        ov49_0225A06C(ctx, index, 0);
        return TRUE;
    }
    return FALSE;
}
