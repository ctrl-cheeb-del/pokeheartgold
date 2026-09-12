#include "overlay70_storage_ui_residual16_private.h"

int ov70_0223A260(Ov70Work *work) {
    if ((gSystem.newKeys & 1) || gSystem.touchNew) {
        ov70_0223A4F4(work, 5, 1, 0, 0xF0F, work->field13C);
        ov70_02238D84(work, 3, 7);
        PlaySE(0x5DC);
    } else if (gSystem.newKeys & 2) {
        work->state = 2;
        ov70_02238E50(work, 1, 0);
        PlaySE(0x5DC);
    }
    return 3;
}

int ov70_0223A2D0(Ov70Work *work) {
    BeginNormalPaletteFade(3, 0, 0, 0, 6, 1, 0x3D);
    work->state = 0;
    return 4;
}

int ov70_0223A2F8(Ov70Work *work) {
    work->yesNo11C8 = ov70_02238C14(work->bgConfig, 12, 0x16A, 8, 1);
    work->state = 6;
    return 3;
}

int ov70_0223A324(Ov70Work *work) {
    int result = ov70_02238C8C();
    if (result == 1) {
        YesNoPrompt_Destroy(work->yesNo11C8);
        work->state = 2;
        work->flag11FC = 1;
        ov70_02238E50(work, 7, 8);
        ov70_0223A874(work);
    } else if (result == 2) {
        YesNoPrompt_Destroy(work->yesNo11C8);
        work->state = 0;
        ClearFrameAndWindow2(work->windowF18, 0);
        ov70_0223A874(work);
    }
    return 3;
}

int ov70_0223A384(Ov70Work *work) {
    work->listItems11AC = ListMenuItems_New(2, 0x3D);
    ListMenuItems_AppendFromMsgData(work->listItems11AC, work->msgDataBA0, 0x37, 1);
    ListMenuItems_AppendFromMsgData(work->listItems11AC, work->msgDataBA0, 0x38, 2);
    work->touchMenu11D0 = ov70_02238CAC(work, 2, 0xD);
    ov70_02238FB4(1);
    work->state = 8;
    return 3;
}

int ov70_0223A3DC(Ov70Work *work) {
    int result = TouchscreenListMenu_HandleInput(work->touchMenu11D0);
    if (result == 1) {
        ov70_02238D60(work);
        ListMenuItems_Delete(work->listItems11AC);
        void *mon = work->field13C;
        if (ov70_0223E76C(mon) && Party_GetCount(work->root->party) == 6) {
            ov70_0223A4F4(work, 0x24, 1, 0, 0xF0F, mon);
            ov70_02238D84(work, 3, 1);
            return 3;
        }
        ov70_0223A4F4(work, 6, 1, 0, 0xF0F, mon);
        ov70_02238D84(work, 3, 5);
        ov70_0223A874(work);
    } else if (result == 2 || result == -2) {
        ov70_02238D60(work);
        ListMenuItems_Delete(work->listItems11AC);
        work->state = 2;
        ov70_02238E50(work, 1, 0);
        ov70_0223A874(work);
    }
    return 3;
}

int ov70_0223A4A0(Ov70Work *work) {
    if (!TextPrinterCheckActive((u8)work->printerBF0)) {
        work->state = work->nextState;
    }
    return 3;
}

int ov70_0223A4C0(Ov70Work *work) {
    if (!TextPrinterCheckActive((u8)work->printerBF0)) {
        work->timer11C0++;
        if (work->timer11C0 > 45) {
            work->timer11C0 = 0;
            work->state = work->nextState;
        }
    }
    return 3;
}

void ov70_0223A4F4(Ov70Work *work, int msgId, int speed, int unused, u32 color, void *mon) {
    void *boxMon = Mon_GetBoxMon(mon);
    void *str;
    BufferBoxMonSpeciesName(work->msgFmtB9C, 0, boxMon);
    str = NewString_ReadMsgData(work->msgDataBA0, msgId);
    StringExpandPlaceholders(work->msgFmtB9C, work->stringBBC, str);
    FillWindowPixelBuffer(work->windowF18, 0xF);
    DrawFrameAndWindow2(work->windowF18, 0, 1, 0xE);
    work->printerBF0 = AddTextPrinterParameterized(work->windowF18, 1, work->stringBBC, 0, 0, speed, 0);
    String_Delete(str);
}
