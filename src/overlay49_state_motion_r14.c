#include "overlay49_state_motion_r14_private.h"

void ov49_02259764(Ov49R14Anim *work, u32 arg1, u32 arg2) {
    VecFx32 sp1C;
    VecFx32 sp10;
    UnkStruct_ov44_02232914 spC;
    UnkStruct_ov44_02232914 sp8;
    UnkStruct_ov44_02232914 sp4;
    UnkStruct_ov44_02232914 sp0;
    u32 done;
    u8 dir;

    switch (work->unk08) {
    case 0:
        ov45_0223089C(work->unk04, 0);
        ov45_0223093C(work->unk04, 0);
        ov45_02230974(work->unk04, 2);
        ov49_02259320(work->unk0C, 0, 0x10000, 4);
        ov45_02230908(work->unk04, &sp1C);
        switch (arg2) {
        case 0:
        case 1:
            work->unk20 = sp1C.z;
            break;
        case 2:
        case 3:
            work->unk20 = sp1C.x;
            break;
        }
        work->unk1C = 0;
        work->unk08++;
    case 1:
        done = ov49_0225932C(work->unk0C, work->unk1C);
        work->unk1C = work->unk1C + 1;
        ov45_02230908(work->unk04, &sp10);
        switch (arg2) {
        case 0:
            sp10.z = work->unk20 - ov49_022593BC(work->unk0C);
            break;
        case 1:
            sp10.z = work->unk20 + ov49_022593BC(work->unk0C);
            break;
        case 2:
            sp10.x = work->unk20 - ov49_022593BC(work->unk0C);
            break;
        case 3:
            sp10.x = work->unk20 + ov49_022593BC(work->unk0C);
            break;
        }
        ov45_022308E4(work->unk04, &sp10);
        if (done == 1) {
            dir = ov42_022282A4(arg2);
            work->unk1C = 4;
            switch (dir) {
            case 3:
                work->unk1C += 2;
            case 0:
                work->unk1C += 2;
            case 2:
                work->unk1C += 2;
            case 1:
                break;
            }
            work->unk08++;
        }
        break;
    case 2:
        work->unk1C--;
        if (work->unk1C == 0) {
            work->unk08++;
            sp4 = ov42_022282DC(work->unk00);
            spC = sp4;
            sp0 = ov42_02228270(spC, arg2);
            sp8 = sp0;
            ov49_02258E04(work, sp8, ov42_022282A4(arg2));
            ov45_02230968(work->unk04);
            ov45_0223089C(work->unk04, 1);
            work->unk0A = 1;
        }
        break;
    case 3:
        break;
    }
}

void ov49_0225991C(Ov49R14Spin *work) {
    VecFx32 pos;
    s16 angle;
    s32 deg;

    switch (work->unk08) {
    case 0:
        ov45_0223089C(work->unk04, 0);
        ov45_02230908(work->unk04, &work->unk10);
        work->unk0C = 0x1C;
        work->unk08++;
        break;
    case 1:
        work->unk0C--;
        if (work->unk0C < 0) {
            work->unk0C = 0x1C;
        }
        pos = work->unk10;
        angle = work->unk0C - 0x10;
        if (angle > 0) {
            angle = angle % 6;
            deg = angle * 0xB4 / 6;
            pos.z += FX_Mul(GF_SinDegNoWrap(deg), FX32_CONST(-2.0));
            pos.y += FX_Mul(GF_SinDegNoWrap(deg), FX32_CONST(10.0));
        }
        ov45_022308E4(work->unk04, &pos);
        ov45_02230920(work->unk04, 1);
        break;
    }
}
