#include "overlay70_pokegear_radio_ui_private.h"

int ov70_0223F96C(Ov70Work *work) {
    ov70_0223FC40(work);
    ov70_0223FA08(work->bgConfig);
    ov70_0223FB60(work);
    ov70_0223FBF4(work);
    ov70_02241358(work);
    BeginNormalPaletteFade(3, 1, 1, 0, 6, 1, 0x3d);
    ov70_02245124(work);
    work->state2c = 0;
    return 2;
}

void ov70_0223F9B4(Ov70Work *work) {
    ov70_02238E44(work);
    sub_0203A930();
    ov70_02246658[work->state2c](work);
}

int ov70_0223F9D4(Ov70Work *work) {
    if (GXx_GetMasterBrightness_((volatile u16 *)0x0400106C)) {
        ov70_02241380(work);
    }
    ov70_0223FC58(work);
    ov70_0223FC30(work);
    ov70_0223FB34(work->bgConfig);
    ov70_02238E58(work);
    return 1;
}

void ov70_0223FA08(void *bgConfig) {
    Ov70Gm graphicsModes;
    Ov70Bt template0;
    Ov70Bt template1;
    Ov70Bt template2;
    Ov70Bt template4;
    Ov70Bt template5;

    graphicsModes = ov70_02245C60;
    SetBothScreensModesAndDisable(&graphicsModes);
    template0 = ov70_02245CA8;
    InitBgFromTemplate(bgConfig, 0, &template0, 0);
    BgClearTilemapBufferAndCommit(bgConfig, 0);
    template1 = ov70_02245C8C;
    InitBgFromTemplate(bgConfig, 1, &template1, 0);
    BgClearTilemapBufferAndCommit(bgConfig, 1);
    template2 = ov70_02245CE0;
    InitBgFromTemplate(bgConfig, 2, &template2, 0);
    BgClearTilemapBufferAndCommit(bgConfig, 2);
    template4 = ov70_02245CC4;
    InitBgFromTemplate(bgConfig, 4, &template4, 0);
    BgClearTilemapBufferAndCommit(bgConfig, 4);
    template5 = ov70_02245C70;
    InitBgFromTemplate(bgConfig, 5, &template5, 0);
    BG_ClearCharDataRange(0, 0x20, 0, 0x3d);
    BG_ClearCharDataRange(1, 0x20, 0, 0x3d);
    BG_ClearCharDataRange(4, 0x20, 0, 0x3d);
    GfGfx_EngineATogglePlanes(0x10, 1);
    GfGfx_EngineBTogglePlanes(0x10, 1);
}

void ov70_0223FB34(void *bgConfig) {
    FreeBgTilemapBuffer(bgConfig, 5);
    FreeBgTilemapBuffer(bgConfig, 4);
    FreeBgTilemapBuffer(bgConfig, 2);
    FreeBgTilemapBuffer(bgConfig, 1);
    FreeBgTilemapBuffer(bgConfig, 0);
}

void ov70_0223FB60(Ov70Work *work) {
    void *bgConfig = work->bgConfig;

    GfGfxLoader_GXLoadPal(0x64, 0, 0, 0, 0x60, 0x3d);
    LoadFontPal1(0, 0x1a0, 0x3d);
    LoadUserFrameGfx2(bgConfig, 0, 1, 0xe, (u8)Options_GetFrame(work->unk00->unk24), 0x3d);
    LoadUserFrameGfx1(bgConfig, 0, 0x1f, 0xb, 0, 0x3d);
    if (work->unk11DC == 0) {
        ToggleBgLayer(4, 0);
        ToggleBgLayer(5, 0);
        GfGfx_EngineBTogglePlanes(0x10, 0);
    }
    if (work->unk20 == 9) {
        ov70_02239C6C(work);
        ov70_02239CF8(work);
    }
}

void ov70_0223FBF4(Ov70Work *work) {
    AddWindowParameterized(work->bgConfig, work->windowF18, 0, 2, 0x13, 0x1b, 4, 0xd, 0x28);
    FillWindowPixelBuffer(work->windowF18, 0);
}

void ov70_0223FC30(Ov70Work *work) {
    RemoveWindow(work->windowF18);
}

void ov70_0223FC40(Ov70Work *work) {
    work->strBBC = String_New(0xb4, 0x3d);
}

void ov70_0223FC58(Ov70Work *work) {
    String_Delete(work->strBBC);
}

int ov70_0223FC68(Ov70Work *work) {
    switch (work->unk24) {
    case 7:
        ov70_02244FA4(work, work->ptrBA0, 0x18, 1, 0xf0f);
        ov70_02238D84(work, 0x25, 2);
        break;
    case 8:
        ov70_02244FA4(work, work->ptrBA0, 0x18, 1, 0xf0f);
        ov70_02238D84(work, 0x25, 7);
        break;
    case 9:
        ov70_02244FA4(work, work->ptrBA0, 0x18, 1, 0xf0f);
        ov70_02238D84(work, 0x25, 0xc);
        break;
    case 10:
        ov70_02244FA4(work, work->ptrBA0, 0x18, 1, 0xf0f);
        ov70_02238D84(work, 0x25, 0x12);
        work->unk11FC = 1;
        break;
    case 11:
        ov70_02244FA4(work, work->ptrBA0, 0x18, 0, 0xf0f);
        work->state2c = 0x18;
        break;
    case 12:
        ov70_02244FA4(work, work->ptrBA0, 0x94, 1, 0xf0f);
        work->unk18 = 1;
        work->state2c = 0x1d;
        break;
    default:
        GF_AssertFail();
        break;
    }
    ov70_02238F64(work);
    return 3;
}

int ov70_0223FD64(Ov70Work *work) {
    Pokemon_RemoveCapsule(work->unk13c);
    ov70_02237F64(work->unk13c);
    work->state2c = 3;
    work->timer1604 = 0;
    ov70_02240D44(work, 4, 6);
    return 3;
}

int ov70_0223FD98(Ov70Work *work) {
    if (ov70_02237F38()) {
        int result = ov70_02237F58();
        work->timer1604 = 0;
        switch (result + 15) {
        case 15:
            ov70_022409C0(work, 1);
            GameStats_Inc(work->unk00->unk28, 0x2d);
            work->state2c = 0x1e;
            break;
        case 14:
            work->value3c = result;
            work->state2c = 0x26;
            break;
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
            work->value3c = result;
            work->state2c = 0x27;
            break;
        case 3:
        case 11:
            work->value3c = result;
            work->state2c = 0x27;
            break;
        case 0:
        case 1:
        case 13:
            work->value3c = result;
            work->state2c = 0x26;
            break;
        case 2:
            sub_020399EC();
            break;
        }
    } else {
        work->timer1604++;
        if (work->timer1604 == 0xe10) {
            sub_020399EC();
        }
    }
    return 3;
}

int ov70_0223FE40(Ov70Work *work) {
    ov70_02237FB4(work);
    work->state2c = 5;
    work->timer1604 = 0;
    work->value36 = 1;
    return 3;
}

int ov70_0223FE60(Ov70Work *work) {
    if (ov70_02237F38()) {
        int result = ov70_02237F58();
        work->timer1604 = 0;
        switch (result + 15) {
        case 15:
            work->state2c = 0x21;
            break;
        case 3:
        case 11:
            work->value3c = result;
            work->state2c = 0x27;
            break;
        case 0:
        case 1:
        case 10:
        case 12:
        case 13:
        case 14:
            sub_02039AD8(4);
            break;
        case 2:
            sub_020399EC();
            break;
        }
    } else {
        work->timer1604++;
        if (work->timer1604 == 0xe10) {
            sub_020399EC();
        }
    }
    return 3;
}

int ov70_0223FEE4(Ov70Work *work) {
    ov70_02238008(work->unk13c);
    work->state2c = 8;
    work->timer1604 = 0;
    ov70_02240D44(work, 9, 0xb);
    return 3;
}

int ov70_0223FF10(Ov70Work *work) {
    if (ov70_02237F38()) {
        int result = ov70_02237F58();
        work->timer1604 = 0;
        switch (result + 15) {
        case 15: {
            s8 value = work->unk25d;
            if (value != 0) {
                work->state2c = 0x18;
            } else {
                ov70_02240A7C(work, work->unk13c, sub_0202DBA0(work->unk00->unk00), value);
                work->state2c = 0x1e;
            }
            break;
        }
        case 12:
            work->state2c = 0x26;
            break;
        case 11:
            work->state2c = 0x26;
            break;
        case 3:
            work->value3c = result;
            work->state2c = 0x27;
            break;
        case 0:
        case 1:
        case 13:
            work->value3c = result;
            work->state2c = 0x26;
            break;
        case 2:
            sub_020399EC();
            break;
        }
    } else {
        work->timer1604++;
        if (work->timer1604 == 0xe10) {
            sub_020399EC();
        }
    }
    return 3;
}

int ov70_0223FFCC(Ov70Work *work) {
    ov70_022380EC(work);
    work->state2c = 0xa;
    work->timer1604 = 0;
    return 3;
}

int ov70_0223FFE8(Ov70Work *work) {
    if (ov70_02237F38()) {
        int result = ov70_02237F58() + 15;
        work->timer1604 = 0;
        switch (result) {
        case 15:
            work->state2c = 0x21;
            break;
        case 10:
        case 11:
        case 12:
            sub_02039AD8(3);
            break;
        case 0:
        case 1:
        case 3:
        case 13:
            sub_02039AD8(4);
            break;
        case 2:
            sub_020399EC();
            break;
        }
    } else {
        work->timer1604++;
        if (work->timer1604 == 0xe10) {
            sub_020399EC();
        }
    }
    return 3;
}

int ov70_0224006C(Ov70Work *work) {
    u32 *entry;

    Pokemon_RemoveCapsule(work->unk13c);
    entry = (u32 *)((u8 *)work + 0x124 * work->unk12c);
    ov70_02238208(entry[0xda], work->unk13c, work->unkA5C);
    ov70_02240D44(work, 0xe, 0x10);
    work->state2c = 0xd;
    work->timer1604 = 0;
    return 3;
}

int ov70_022400BC(Ov70Work *work) {
    if (ov70_02237F38()) {
        int result = ov70_02237F58();
        work->timer1604 = 0;
        switch (result + 15) {
        case 15:
            work->state2c = 0x1e;
            ov70_022409C0(work, 0);
            ov70_02240B9C(work, work->unkA5C, work->unk120);
            ov70_02240CE4(work->unk00->unk18, work->unkA5C);
            ov70_02240500(work, work->unkA5C);
            break;
        case 10:
            work->value3c = result;
            work->state2c = 0x11;
            break;
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            work->value3c = result;
            work->state2c = 0x27;
            break;
        case 3:
            work->value3c = result;
            work->state2c = 0x27;
            break;
        case 0:
        case 1:
        case 13:
            work->value3c = result;
            work->state2c = 0x26;
            break;
        case 2:
            sub_020399EC();
            break;
        }
    } else {
        work->timer1604++;
        if (work->timer1604 == 0xe10) {
            sub_020399EC();
        }
    }
    return 3;
}

int ov70_02240180(Ov70Work *work) {
    ov70_0223826C(work);
    work->state2c = 0xf;
    work->timer1604 = 0;
    return 3;
}

int ov70_0224019C(Ov70Work *work) {
    if (ov70_02237F38()) {
        int result = ov70_02237F58() + 15;
        work->timer1604 = 0;
        switch (result) {
        case 15:
            work->state2c = 0x21;
            break;
        case 10:
            sub_02039AD8(3);
            break;
        case 0:
        case 1:
        case 3:
        case 13:
            sub_02039AD8(4);
            break;
        case 2:
            sub_020399EC();
            break;
        }
    } else {
        work->timer1604++;
        if (work->timer1604 == 0xe10) {
            sub_020399EC();
        }
    }
    return 3;
}

int ov70_02240220(Ov70Work *work) {
    ov70_02238058(work->unk13c);
    work->state2c = 0x19;
    work->timer1604 = 0;
    return 3;
}
