#include "overlay70_menu_and_icon_helpers_private.h"

#define PTR(base, off) (*(void **)((u8 *)(base) + (off)))
#define U32(base, off) (*(u32 *)((u8 *)(base) + (off)))

int ov70_0223D934(Ov70Work *work) {
    PTR(work, 0x11ac) = ListMenuItems_New(3, 0x3d);
    ListMenuItems_AppendFromMsgData(PTR(work, 0x11ac), work->msgDataBA0, 0x62, 1);
    ListMenuItems_AppendFromMsgData(PTR(work, 0x11ac), work->msgDataBA0, 0x63, 2);
    ListMenuItems_AppendFromMsgData(PTR(work, 0x11ac), work->msgDataBA0, 0x64, 3);
    work->menu11D0 = ov70_02238CAC(work, 3, 0xa);
    work->state2c = 8;
    return 3;
}

int ov70_0223D998(Ov70Work *work) {
    u32 input;
    void *mon;
    int flag;

    input = TouchscreenListMenu_HandleInput(work->menu11D0);
    switch (input) {
    case 1:
        ov70_02238D60(work);
        ListMenuItems_Delete(PTR(work, 0x11ac));
        ClearFrameAndWindow2(work->windowF18, 0);
        work->state2c = 2;
        ov70_02238E50(work, 8, 5);
        break;
    case 2:
        ov70_02238D60(work);
        ListMenuItems_Delete(PTR(work, 0x11ac));
        mon = ov70_0223E49C(work->unk00->unk08, work->unk00->unk0C, work->field120, work->field122);
        if (ov70_0223E4FC(mon)) {
            ov70_0223E01C(work, 0x25, 1, 0, 0xf0f, 1);
            ov70_02238D84(work, 4, 1);
            break;
        }
        {
            int status = ov70_0223E538(mon);
            if (status) {
                if (status == 1) {
                    ov70_0223E01C(work, 0xb1, 1, 0, 0xf0f, 1);
                } else {
                    ov70_0223E01C(work, 0xb2, 1, 0, 0xf0f, 1);
                }
                ov70_02238D84(work, 4, 1);
                break;
            }
        }
        if (ov70_0223E59C(mon)) {
            ov70_0223E01C(work, 0xb3, 1, 0, 0xf0f, 1);
            ov70_02238D84(work, 4, 1);
            break;
        }
        flag = 0;
        if (ov70_0223E490(work->field120)) {
            mon = Party_GetMonByIndex(work->unk00->unk08, work->field122);
            if (GetMonData(mon, 0xa2, 0)) {
                flag = 1;
                work->state2c = 0xe;
            }
        }
        if (!flag) {
            work->field124 = ov70_0223E49C(work->unk00->unk08, work->unk00->unk0C, work->field120, work->field122);
            work->state2c = 2;
            ov70_02238E50(work, 6, 0);
        }
        break;
    case 3:
    case -2:
        ov70_02238D60(work);
        ListMenuItems_Delete(PTR(work, 0x11ac));
        ClearFrameAndWindow2(work->windowF18, 0);
        work->state2c = 0;
        break;
    }
    return 3;
}

int ov70_0223DB30(Ov70Work *work) {
    PTR(work, 0x11ac) = ListMenuItems_New(3, 0x3d);
    ListMenuItems_AppendFromMsgData(PTR(work, 0x11ac), work->msgDataBA0, 0x57, 1);
    ListMenuItems_AppendFromMsgData(PTR(work, 0x11ac), work->msgDataBA0, 0x58, 2);
    ListMenuItems_AppendFromMsgData(PTR(work, 0x11ac), work->msgDataBA0, 0x59, 3);
    work->menu11D0 = ov70_02238CAC(work, 3, 0xa);
    work->state2c = 0xa;
    return 3;
}

int ov70_0223DB94(Ov70Work *work) {
    u32 input;
    void *mon;
    int flag;

    input = TouchscreenListMenu_HandleInput(work->menu11D0);
    switch (input) {
    case 1:
        ov70_02238D60(work);
        ListMenuItems_Delete(PTR(work, 0x11ac));
        work->state2c = 2;
        ov70_02238E50(work, 8, 6);
        break;
    case 2:
        ov70_02238D60(work);
        ListMenuItems_Delete(PTR(work, 0x11ac));
        ClearFrameAndWindow2(work->windowF18, 0);
        mon = ov70_0223E49C(work->unk00->unk08, work->unk00->unk0C, work->field120, work->field122);
        if (ov70_0223E4FC(mon)) {
            ov70_0223E01C(work, 0x25, 1, 0, 0xf0f, 1);
            ov70_02238D84(work, 4, 1);
            break;
        }
        {
            int status = ov70_0223E538(mon);
            if (status) {
                if (status == 1) {
                    ov70_0223E01C(work, 0xb1, 1, 0, 0xf0f, 1);
                } else {
                    ov70_0223E01C(work, 0xb2, 1, 0, 0xf0f, 1);
                }
                ov70_02238D84(work, 4, 1);
                break;
            }
        }
        if (ov70_0223E59C(mon)) {
            ov70_0223E01C(work, 0xb3, 1, 0, 0xf0f, 1);
            ov70_02238D84(work, 4, 1);
            break;
        }
        flag = 0;
        if (ov70_0223E490(work->field120)) {
            mon = Party_GetMonByIndex(work->unk00->unk08, work->field122);
            if (GetMonData(mon, 0xa2, 0)) {
                flag = 1;
                work->state2c = 0xb;
            }
        }
        if (!flag) {
            ov70_0223DE6C(work);
        }
        break;
    case 3:
    case -2:
        ov70_02238D60(work);
        ListMenuItems_Delete(PTR(work, 0x11ac));
        ClearFrameAndWindow2(work->windowF18, 0);
        work->state2c = 0;
        break;
    }
    return 3;
}

int ov70_0223DD0C(Ov70Work *work) {
    if (U32(work, 0x18) == 0 || U32(work, 0x18) == 8 || U32(work, 0x18) == 3) {
        BeginNormalPaletteFade(0, 0, 0, 0, 6, 1, 0x3d);
        work->field11FC = 1;
    } else {
        BeginNormalPaletteFade(3, 0, 0, 0, 6, 1, 0x3d);
    }
    work->state2c = 0;
    return 4;
}

int ov70_0223DD68(Ov70Work *work) {
    work->prompt11C8 = ov70_02238C14(work->bgConfig, 0xc, 0x1ad, 8, 1);
    work->state2c = 6;
    return 3;
}

int ov70_0223DD94(Ov70Work *work) {
    int result = ov70_02238C8C(work);
    if (result == 1) {
        YesNoPrompt_Destroy(work->prompt11C8);
        work->state2c = 2;
        ov70_02238E50(work, 0, 0);
    } else if (result == 2) {
        YesNoPrompt_Destroy(work->prompt11C8);
        work->state2c = 0;
    }
    return 3;
}

int ov70_0223DDD0(Ov70Work *work) {
    ov70_0223E01C(work, 0x19, 1, 0, 0xf0f, 1);
    ov70_02238D84(work, 3, 0xc);
    return 3;
}

int ov70_0223DDFC(Ov70Work *work) {
    work->prompt11C8 = ov70_02238C14(work->bgConfig, 0xa, 0x1ad, 8, 1);
    work->state2c = 0xd;
    return 3;
}

int ov70_0223DE28(Ov70Work *work) {
    int result = ov70_02238C8C(work);
    if (result == 1) {
        YesNoPrompt_Destroy(work->prompt11C8);
        ov70_0223DE6C(work);
    } else if (result == 2) {
        YesNoPrompt_Destroy(work->prompt11C8);
        ClearFrameAndWindow2(work->window1158, 0);
        work->state2c = 1;
    }
    return 3;
}

int ov70_0223DE6C(Ov70Work *work) {
    if (ov70_0223E76C((u8 *)work + 0x260 + work->field12C * 0x124) && work->field120 != 0x12 && Party_GetCount(work->unk00->unk08) == 6) {
        ov70_0223E01C(work, 0x1c, 1, 0, 0xf0f, 1);
        ov70_02238D84(work, 4, 1);
        return 0;
    }
    work->field124 = ov70_0223E49C(work->unk00->unk08, work->unk00->unk0C, work->field120, work->field122);
    work->state2c = 2;
    work->field11FC = 1;
    ov70_02238E50(work, 7, 9);
    ov70_0223E690((u8 *)work + 0x13c, work);
    U32(work, 0x128) = 0;
    return 1;
}

int ov70_0223DF14(Ov70Work *work) {
    ov70_0223E01C(work, 0x19, 1, 0, 0xf0f, 1);
    ov70_02238D84(work, 3, 0xf);
    return 3;
}

int ov70_0223DF40(Ov70Work *work) {
    work->prompt11C8 = ov70_02238C14(work->bgConfig, 0xa, 0x1ad, 8, 1);
    work->state2c = 0x10;
    return 3;
}

int ov70_0223DF6C(Ov70Work *work) {
    int result = ov70_02238C8C(work);
    if (result == 1) {
        YesNoPrompt_Destroy(work->prompt11C8);
        work->field124 = ov70_0223E49C(work->unk00->unk08, work->unk00->unk0C, work->field120, work->field122);
        work->state2c = 2;
        ov70_02238E50(work, 6, 0);
    } else if (result == 2) {
        YesNoPrompt_Destroy(work->prompt11C8);
        ClearFrameAndWindow2(work->window1158, 0);
        work->state2c = 1;
    }
    return 3;
}

int ov70_0223DFD0(Ov70Work *work) {
    if (!TextPrinterCheckActive((u8)work->printerBF0)) {
        work->state2c = work->field30;
    }
    return 3;
}

int ov70_0223DFF0(Ov70Work *work) {
    if (!TextPrinterCheckActive((u8)work->printerBF0)) {
        ClearFrameAndWindow2(work->window1158, 0);
        work->state2c = work->field30;
    }
    return 3;
}

void ov70_0223E01C(Ov70Work *work, int msgId, int color, int unused, int unused2, int window) {
    void *tmp = NewString_ReadMsgData(work->msgDataBA0, msgId);
    void *win;
    StringExpandPlaceholders(work->ptrB9C, work->strBBC, tmp);
    win = window == 0 ? (void *)work->windowF18 : (void *)work->window1158;
    FillWindowPixelBuffer(win, 0xf);
    DrawFrameAndWindow2(win, 0, 1, 0xe);
    work->printerBF0 = AddTextPrinterParameterized(win, 1, work->strBBC, 0, 0, color, 0);
    String_Delete(tmp);
}

void *ov70_0223E094(void *narc, int member, void **unpacked, int heap) {
    void *raw = NARC_AllocAndReadWholeMember(narc, member, heap);
    if (raw != 0 && !NNS_G2dGetUnpackedBGCharacterData(raw, (NNSG2dCharacterData **)unpacked)) {
        Heap_Free(raw);
        return 0;
    }
    return raw;
}

void ov70_0223E0BC(int species, int form, int gender, int slot, int field08, void *narc, Ov70IconData *dst) {
    NNSG2dCharacterData *unpacked;
    void *raw;
    int member = GetMonIconNaixEx(species, gender, form);
    raw = ov70_0223E094(narc, member, (void **)&unpacked, 0x3d);
    MIi_CpuCopyFast(unpacked->pRawData, (u32 *)dst->pixels, 0x200);
    dst->tile = (slot * 0x10 + 0xc) * 0x20;
    dst->field08 = field08;
    dst->palette = GetMonIconPaletteEx(species, form, gender) + 3;
    Heap_Free(raw);
}
