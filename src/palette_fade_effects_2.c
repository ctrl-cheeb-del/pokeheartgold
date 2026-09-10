#include "palette_fade_effects_internal.h"

BOOL FadeFunc_03(FadeWork *work) {
    if (work->state == 0) {
        *(const void **)(_0210F64C + 0x10) = _020F5D5C;
        sub_0200FCDC(work->color);
        sub_0201289C(work, _0210F64C + 0x10);
        work->topScreen = 0;
        work->bottomScreen = 0;
        return 0;
    }
    return sub_020128E0(work);
}

BOOL FadeFunc_04(FadeWork *work) {
    if (work->state == 0) {
        *(const void **)(_0210F64C + 0x20) = _020F5D64;
        sub_0200FCDC(work->color);
        sub_0201289C(work, _0210F64C + 0x20);
        work->topScreen = 1;
        work->bottomScreen = 0;
        return 0;
    }
    return sub_020128E0(work);
}

BOOL FadeFunc_05(FadeWork *work) {
    if (work->state == 0) {
        *(const void **)(_0210F64C + 0x28) = _020F5D58;
        sub_0200FCDC(work->color);
        sub_0201289C(work, _0210F64C + 0x28);
        work->topScreen = 0;
        work->bottomScreen = 0;
        return 0;
    }
    return sub_020128E0(work);
}

BOOL FadeFunc_06(FadeWork *work) {
    if (work->state == 0) {
        sub_0200FCDC(work->color);
        sub_0201164C(work, _020F5E2C);
        work->topScreen = 1;
        work->bottomScreen = 0;
        return 0;
    }
    return sub_0201169C(work);
}

BOOL FadeFunc_07(FadeWork *work) {
    if (work->state == 0) {
        sub_0200FCDC(work->color);
        sub_0201164C(work, _020F5E38);
        work->topScreen = 0;
        work->bottomScreen = 0;
        return 0;
    }
    return sub_0201169C(work);
}

BOOL FadeFunc_08(FadeWork *work) {
    if (work->state == 0) {
        *(const void **)(_0210F64C + 0x08) = _020F5D90;
        sub_0200FCDC(work->color);
        sub_0201289C(work, _0210F64C + 0x08);
        work->topScreen = 1;
        work->bottomScreen = 0;
        return 0;
    }
    return sub_020128E0(work);
}

BOOL FadeFunc_09(FadeWork *work) {
    if (work->state == 0) {
        *(const void **)(_0210F64C + 0x38) = _020F5D68;
        sub_0200FCDC(work->color);
        sub_0201289C(work, _0210F64C + 0x38);
        work->topScreen = 0;
        work->bottomScreen = 0;
        return 0;
    }
    return sub_020128E0(work);
}

BOOL FadeFunc_10(FadeWork *work) {
    if (work->state == 0) {
        *(const void **)(_0210F64C + 0x48) = _020F5D80;
        sub_0200FCDC(work->color);
        sub_0201289C(work, _0210F64C + 0x48);
        work->topScreen = 1;
        work->bottomScreen = 0;
        return 0;
    }
    return sub_020128E0(work);
}

BOOL FadeFunc_11(FadeWork *work) {
    if (work->state == 0) {
        *(const void **)(_0210F64C + 0x40) = _020F5DB8;
        sub_0200FCDC(work->color);
        sub_0201289C(work, _0210F64C + 0x40);
        work->topScreen = 0;
        work->bottomScreen = 0;
        return 0;
    }
    return sub_020128E0(work);
}

BOOL FadeFunc_12(FadeWork *work) {
    if (work->state == 0) {
        sub_0200FCDC(work->color);
        sub_0201164C(work, _020F5E5C);
        work->topScreen = 1;
        work->bottomScreen = 0;
        return 0;
    }
    return sub_0201169C(work);
}

BOOL FadeFunc_13(FadeWork *work) {
    if (work->state == 0) {
        sub_0200FCDC(work->color);
        sub_0201164C(work, _020F5E68);
        work->topScreen = 0;
        work->bottomScreen = 0;
        return 0;
    }
    return sub_0201169C(work);
}

BOOL FadeFunc_14(FadeWork *work) {
    if (work->state == 0) {
        sub_0200FCDC(work->color);
        sub_020116EC(work, _020F5E80, _020F5E8C);
        work->topScreen = 1;
        work->bottomScreen = 0;
        return 0;
    }
    return sub_02011744(work);
}

BOOL FadeFunc_15(FadeWork *work) {
    if (work->state == 0) {
        sub_0200FCDC(work->color);
        sub_020116EC(work, _020F5EA4, _020F5EB0);
        work->topScreen = 0;
        work->bottomScreen = 0;
        return 0;
    }
    return sub_02011744(work);
}

BOOL FadeFunc_16(FadeWork *work) {
    if (work->state == 0) {
        sub_0200FCDC(work->color);
        sub_02011884(work, _020F5EC8);
        work->topScreen = 1;
        work->bottomScreen = 0;
        return 0;
    }
    return sub_020118BC(work);
}

BOOL FadeFunc_17(FadeWork *work) {
    if (work->state == 0) {
        sub_0200FCDC(work->color);
        sub_02011884(work, _020F5ED4);
        work->topScreen = 0;
        work->bottomScreen = 0;
        return 0;
    }
    return sub_020118BC(work);
}

BOOL FadeFunc_18(FadeWork *work) {
    if (work->state == 0) {
        sub_0200FCDC(work->color);
        sub_02011884(work, _020F5DD8);
        work->topScreen = 1;
        work->bottomScreen = 0;
        return 0;
    }
    return sub_020118BC(work);
}

BOOL FadeFunc_19(FadeWork *work) {
    if (work->state == 0) {
        sub_0200FCDC(work->color);
        sub_02011884(work, _020F5DE4);
        work->topScreen = 0;
        work->bottomScreen = 0;
        return 0;
    }
    return sub_020118BC(work);
}

BOOL FadeFunc_20(FadeWork *work) {
    if (work->state == 0) {
        sub_0200FCDC(work->color);
        sub_02011B5C(work, _020F5DD0);
        work->topScreen = 1;
        work->bottomScreen = 0;
        return 0;
    }
    return sub_02011B94(work);
}

BOOL FadeFunc_21(FadeWork *work) {
    if (work->state == 0) {
        sub_0200FCDC(work->color);
        sub_02011B5C(work, _020F5DC8);
        work->topScreen = 0;
        work->bottomScreen = 0;
        return 0;
    }
    return sub_02011B94(work);
}

BOOL FadeFunc_22(FadeWork *work) {
    if (work->state == 0) {
        sub_0200FCDC(work->color);
        sub_0201164C(work, _020F5E08);
        work->topScreen = 1;
        work->bottomScreen = 0;
        return 0;
    }
    return sub_0201169C(work);
}

BOOL FadeFunc_23(FadeWork *work) {
    if (work->state == 0) {
        sub_0200FCDC(work->color);
        sub_0201164C(work, _020F5E14);
        work->topScreen = 0;
        work->bottomScreen = 0;
        return 0;
    }
    return sub_0201169C(work);
}

BOOL FadeFunc_24(FadeWork *work) {
    if (work->state == 0) {
        sub_0200FCDC(work->color);
        sub_0201164C(work, _020F5E20);
        work->topScreen = 1;
        work->bottomScreen = 0;
        return 0;
    }
    return sub_0201169C(work);
}

BOOL FadeFunc_25(FadeWork *work) {
    if (work->state == 0) {
        sub_0200FCDC(work->color);
        sub_0201164C(work, _020F5E44);
        work->topScreen = 0;
        work->bottomScreen = 0;
        return 0;
    }
    return sub_0201169C(work);
}

BOOL FadeFunc_26(FadeWork *work) {
    if (work->state == 0) {
        sub_0200FCDC(work->color);
        sub_02011D60(work, _020F5DA8);
        work->topScreen = 1;
        work->bottomScreen = 0;
        return 0;
    }
    return sub_02011D98(work);
}

BOOL FadeFunc_27(FadeWork *work) {
    if (work->state == 0) {
        sub_0200FCDC(work->color);
        sub_02011D60(work, _020F5DA0);
        work->topScreen = 0;
        work->bottomScreen = 0;
        return 0;
    }
    return sub_02011D98(work);
}

BOOL FadeFunc_28(FadeWork *work) {
    Fade16Param param;
    if (work->state == 0) {
        param.first = _020F5EEC;
        param.second = _020F5EFC;
        param.value08 = 4;
        param.value0A = 0;
        param.value0C = 0x3F;
        param.value0D = 0x20;
        param.value0E = 1;
        sub_0200FCDC(work->color);
        sub_02011FF8(work, &param);
        work->topScreen = 1;
        work->bottomScreen = 0;
        return 0;
    }
    return sub_02012030(work);
}

BOOL FadeFunc_29(FadeWork *work) {
    Fade16Param param;
    if (work->state == 0) {
        param.first = _020F5F0C;
        param.second = _020F5F1C;
        param.value08 = 4;
        param.value0A = 0;
        param.value0C = 0x3F;
        param.value0D = 0x20;
        param.value0E = 0;
        sub_0200FCDC(work->color);
        sub_02011FF8(work, &param);
        work->topScreen = 0;
        work->bottomScreen = 0;
        return 0;
    }
    return sub_02012030(work);
}

BOOL FadeFunc_30(FadeWork *work) {
    if (work->state == 0) {
        *(const void **)(_0210F64C + 0x30) = _020F5EBC;
        sub_0200FCDC(work->color);
        sub_0201289C(work, _0210F64C + 0x30);
        work->topScreen = 1;
        work->bottomScreen = 0;
        return 0;
    }
    return sub_020128E0(work);
}

BOOL FadeFunc_31(FadeWork *work) {
    if (work->state == 0) {
        *(const void **)(_0210F64C + 0x18) = _020F5DF0;
        sub_0200FCDC(work->color);
        sub_0201289C(work, _0210F64C + 0x18);
        work->topScreen = 0;
        work->bottomScreen = 0;
        return 0;
    }
    return sub_020128E0(work);
}

BOOL FadeFunc_32(FadeWork *work) {
    ShortVector4 param;
    if (work->state == 0) {
        param = *(const ShortVector4 *)(_020F5D58 + 0x30);
        sub_0200FCDC(work->color);
        sub_020122B8(work, &param);
        work->topScreen = 1;
        work->bottomScreen = 0;
        return 0;
    }
    return sub_020122F8(work);
}

BOOL FadeFunc_33(FadeWork *work) {
    ShortVector4 param;
    if (work->state == 0) {
        param = *(const ShortVector4 *)(_020F5D98 + 0x28);
        sub_0200FCDC(work->color);
        sub_020122B8(work, &param);
        work->topScreen = 0;
        work->bottomScreen = 0;
        return 0;
    }
    return sub_020122F8(work);
}

BOOL FadeFunc_34(FadeWork *work) {
    ShortVector4 param;
    if (work->state == 0) {
        param = *(const ShortVector4 *)(_020F5D58 + 0x20);
        sub_0200FCDC(work->color);
        sub_020125EC(work, &param);
        work->topScreen = 1;
        work->bottomScreen = 0;
        return 0;
    }
    return sub_0201262C(work);
}

BOOL FadeFunc_35(FadeWork *work) {
    ShortVector4 param;
    if (work->state == 0) {
        param = *(const ShortVector4 *)(_020F5D58 + 0x18);
        sub_0200FCDC(work->color);
        sub_020125EC(work, &param);
        work->topScreen = 0;
        work->bottomScreen = 0;
        return 0;
    }
    return sub_0201262C(work);
}

BOOL FadeFunc_36(FadeWork *work) {
    if (work->state == 0) {
        sub_0200FCDC(work->color);
        sub_02011884(work, _020F5E98);
        work->topScreen = 1;
        work->bottomScreen = 0;
        return 0;
    }
    return sub_020118BC(work);
}

BOOL FadeFunc_37(FadeWork *work) {
    if (work->state == 0) {
        sub_0200FCDC(work->color);
        sub_02011884(work, _020F5EE0);
        work->topScreen = 0;
        work->bottomScreen = 0;
        return 0;
    }
    return sub_020118BC(work);
}

BOOL FadeFunc_38(FadeWork *work) {
    if (work->state == 0) {
        sub_0200FCDC(work->color);
        sub_0201164C(work, _020F5DFC);
        work->topScreen = 1;
        work->bottomScreen = 0;
        return 0;
    }
    return sub_0201169C(work);
}

BOOL FadeFunc_39(FadeWork *work) {
    if (work->state == 0) {
        sub_0200FCDC(work->color);
        sub_0201164C(work, _020F5E50);
        work->topScreen = 0;
        work->bottomScreen = 0;
        return 0;
    }
    return sub_0201169C(work);
}

BOOL FadeFunc_40(FadeWork *work) {
    if (work->state == 0) {
        *(const void **)(_0210F64C + 0x5C) = _020F5D98;
        sub_0200FCDC(work->color);
        sub_02012B1C(work, _0210F64C + 0x50);
        work->topScreen = 1;
        work->bottomScreen = 0;
        return 0;
    }
    return sub_02012B80(work);
}

BOOL FadeFunc_41(FadeWork *work) {
    if (work->state == 0) {
        *(const void **)(_0210F64C + 0x74) = _020F5DB0;
        sub_0200FCDC(work->color);
        sub_02012B1C(work, _0210F64C + 0x68);
        work->topScreen = 0;
        work->bottomScreen = 0;
        return 0;
    }
    return sub_02012B80(work);
}

BOOL FadeFunc_42(FadeWork *work) {
    if (work->state == 0) {
        sub_0200FCDC(work->color);
        sub_02012DD8(work, _020F5E74);
        work->topScreen = 1;
        work->bottomScreen = 0;
        return 0;
    }
    return sub_02012E10(work);
}

int sub_020109BC(int angle) {
    int index = angle >> 4;
    return FX_Div(FX_SinCosTable_[index * 2], FX_SinCosTable_[index * 2 + 1]);
}
