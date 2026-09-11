#include "global.h"

#include "unk_02012A90_opus_partial_internal.h"

void sub_02012A90(UnkStruct_02012A90 *param0) {
    s32 i;

    for (i = 0; i < param0->unk310; i++) {
        sub_02012ACC(&param0->unk30C[i], param0->unk0, param0->unk318, param0->unk314);
    }
}

void sub_02012ACC(const UnkStruct_02012ACC *param0, u8 *param1, s32 param2, s32 param3) {
    u32 lo = param0->unk0;
    u32 hi = param0->unk1;
    s32 mid;
    s32 start;
    s32 end;
    u32 val;
    s32 i;

    mid = (s32)(hi - lo) * param2 / param3;
    mid += lo;

    if (lo <= hi) {
        start = lo;
        end = hi;
        val = param0->unk2;
    } else {
        start = hi;
        end = lo;
        val = !param0->unk2;
    }

    for (i = start; i < end; i++) {
        if (i == mid) {
            val = !val;
        }
        param1[i] = val;
    }
}

void sub_02012B1C(UnkStruct_02012B1C_0 *param0, UnkStruct_02012B1C_1 *param1) {
    UnkStruct_02012BE8 *v0;

    param0->unk14 = Heap_Alloc(param0->unk20, sizeof(UnkStruct_02012BE8));
    memset(param0->unk14, 0, sizeof(UnkStruct_02012BE8));

    v0 = param0->unk14;

    if (param1->unkB == 0) {
        sub_02012BE8(v0, param1, param0->unk4, param0->unk8, param0->unk10, param0->unk18, param0->unk1C, param0->unk20);
    } else {
        sub_02012CDC(v0, param1, param0->unk4, param0->unk8, param0->unk10, param0->unk18, param0->unk1C, param0->unk20);
    }

    param0->unkC++;
}

BOOL sub_02012B80(UnkStruct_02012B1C_0 *param0) {
    BOOL ret = FALSE;
    UnkStruct_02012BE8 *v0 = param0->unk14;
    BOOL v1;

    switch (param0->unkC) {
    case 1:
        if (v0->unk386 == 0) {
            v1 = sub_02012C68(v0, param0);
        } else {
            v1 = sub_02012D4C(v0, param0);
        }

        if (v1 == 1) {
            sub_02010F34(param0->unk28, param0->unk18, param0->unk10);
            param0->unkC++;
        }
        break;
    case 2:
        Heap_Free(v0);
        param0->unk14 = NULL;
        param0->unkC++;
        ret = TRUE;
        break;
    case 3:
        ret = TRUE;
        break;
    default:
        GF_AssertFail();
        break;
    }

    return ret;
}

void sub_02012BE8(UnkStruct_02012BE8 *param0, UnkStruct_02012B1C_1 *param1, s32 param2, s32 param3, u32 param4, u32 param5, u32 param6, u32 param7) {
    s32 v0 = FX_Mul(param2 << FX32_SHIFT, param1->unk14) >> FX32_SHIFT;

    param0->unk384 = param2 - v0;
    param0->unk380 = param1;
    param0->unk386 = param1->unkB;

    sub_020117A0(param0, param1, v0, param3, param4, param5);

    if (param1->unk8 == 0) {
        sub_02011068(param5, 1, param4, param1->unkB);
    } else {
        sub_02011068(param5, 2, param4, param1->unkB);
    }

    param0->unk385 = 0;
}

BOOL sub_02012C68(UnkStruct_02012BE8 *param0, UnkStruct_02012B1C_0 *param1) {
    BOOL ret = FALSE;

    switch (param0->unk385) {
    case 0:
        if (sub_020117FC(param0) == 1) {
            param0->unk385++;
            sub_02012940(param0->unk4C, param0->unk380->unkC, param0->unk384, param1->unk8, param1->unk10, param1->unk18, param1->unk1C, param1->unk20);
        }
        break;
    case 1:
        if (sub_02012A2C(param0->unk4C) == 1) {
            ret = TRUE;
            param0->unk385++;
        }
        break;
    case 2:
        ret = TRUE;
        break;
    }

    return ret;
}

void sub_02012CDC(UnkStruct_02012BE8 *param0, UnkStruct_02012B1C_1 *param1, s32 param2, s32 param3, u32 param4, u32 param5, u32 param6, u32 param7) {
    s32 v0 = FX_Mul(param2 << FX32_SHIFT, param1->unk14) >> FX32_SHIFT;
    s32 v1;

    param0->unk384 = v0;
    v1 = param2 - param0->unk384;
    param0->unk380 = param1;
    param0->unk386 = param1->unkB;

    sub_02012940(param0->unk4C, param0->unk380->unkC, v1, param3, param4, param5, param6, param7);

    param0->unk385 = 0;
}

BOOL sub_02012D4C(UnkStruct_02012BE8 *param0, UnkStruct_02012B1C_0 *param1) {
    BOOL ret = FALSE;

    switch (param0->unk385) {
    case 0:
        if (sub_02012A2C(param0->unk4C) == 1) {
            param0->unk385++;
            sub_020117A0(param0, param0->unk380, param0->unk384, param1->unk8, param1->unk10, param1->unk18);

            if (param0->unk380->unk8 == 0) {
                sub_02011068(param1->unk18, 1, param1->unk10, param0->unk380->unkB);
            } else {
                sub_02011068(param1->unk18, 2, param1->unk10, param0->unk380->unkB);
            }
        }
        break;
    case 1:
        if (sub_020117FC(param0) == 1) {
            ret = TRUE;
            param0->unk385++;
        }
        break;
    case 2:
        ret = TRUE;
        break;
    }

    return ret;
}
