#include "summary_ui_stats_internal.h"

int sub_02089E98(SummaryWork *arg) {
    SummaryWork *work = arg;
    typedef struct PackedFlags {
        u32 low : 28;
        u32 flag : 1;
        u32 high : 3;
    } PackedFlags;
    u8 selection = sub_0208E544(work);
    if (selection == 0xff) {
        return 2;
    }
    switch (selection) {
    case 0:
        if (sub_02089E80(work, selection)) {
            sub_02089E14(work, (s8)selection);
        }
        break;
    case 1:
    case 2:
        if (!((PackedFlags *)((u8 *)work + 0x280))->flag && sub_02089E80(work, selection)) {
            sub_02089E14(work, (s8)selection);
        }
        break;
    case 3:
        sub_0208ADB8(work, 1);
        PlaySE(0x940);
        return sub_0208B044(work, 0x15);
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9: {
        int index = selection - 4;
        if (((u8 *)work->monData)[0x14] != index && sub_0208A310(work, index)) {
            sub_0208A234(work, (u8)index);
            return 0x13;
        }
    } break;
    }
    return 2;
}

void sub_02089F50(SummaryWork *work, void *bgConfig, int member, int bgId) {
    NNSG2dScreenData *screen;
    void *raw = AllocAndReadWholeNarcMemberByIdPair(0xa2, member, 0x13);
    NNS_G2dGetUnpackedScreenData(raw, &screen);
    LoadRectToBgTilemapRect(work->bgConfig, (u8)bgId, screen->rawData, 0, 0, 0x20, 0x20);
    ScheduleBgTilemapBufferTransfer(bgConfig, (u8)bgId);
    Heap_Free(raw);
}

void sub_02089F98(SummaryWork *work) {
    typedef struct PackedFlags {
        u32 low : 28;
        u32 flag : 1;
        u32 high : 3;
    } PackedFlags;
    if (*(u32 *)((u8 *)work->monData + 0x34) == 0 && work->selection == 2) {
        sub_02089F50(work, work->bgConfig, 11, 3);
    } else {
        sub_02089F50(work, work->bgConfig, _021039B8[work->selection][0], 3);
    }
    if (((u8 *)work->monData)[0x12] == 2) {
        sub_02089F50(work, work->bgConfig, _021039B8[work->selection][2], 6);
        ScheduleSetBgPosText(work->bgConfig, 5, 0, 0x80);
        ScheduleSetBgPosText(work->bgConfig, 5, 3, 0);
        if (*(u16 *)((u8 *)work->monData + 0x18) == 0) {
            sub_0208AF70(work);
        }
    } else if (((PackedFlags *)((u8 *)work + 0x280))->flag) {
        sub_02089F50(work, work->bgConfig, _021039B8[work->selection][2], 6);
    } else if (sub_02089E80(work, 2)) {
        sub_02089F50(work, work->bgConfig, _021039B8[work->selection][1], 6);
    } else if (work->selection == 0) {
        sub_02089F50(work, work->bgConfig, 0x4d, 6);
    } else {
        sub_02089F50(work, work->bgConfig, 0x4e, 6);
    }
    if (((u8 *)work->monData)[0x11] == 2) {
        sub_020196E8(*(void **)((u8 *)work + 0x7d0), 4, 0x14, 4);
        sub_0208B118(work);
    }
    if (!((PackedFlags *)((u8 *)work + 0x280))->flag) {
        if (work->selection == 0) {
            sub_0208A1A0(work);
        } else if (work->selection == 1) {
            sub_0208A0EC(work);
        }
    }
}

void sub_0208A0EC(SummaryWork *work) {
    u16 tileBase;
    u32 pixels;
    u8 i;
    u16 fullTile;
    switch (CalculateHpBarColor(*(u16 *)((u8 *)work + 0x254), *(u16 *)((u8 *)work + 0x256), 0x30)) {
    case 0:
    case 3:
    case 4:
        tileBase = 0xf097;
        break;
    case 2:
        tileBase = 0xf0b7;
        break;
    case 1:
        tileBase = 0xf0d7;
        break;
    }
    pixels = CalculateHpBarPixelsLength(*(u16 *)((u8 *)work + 0x254), *(u16 *)((u8 *)work + 0x256), 0x30);
    i = 0;
    fullTile = (u16)(tileBase + 8);
    do {
        u16 tile = pixels >= 8 ? fullTile : (u16)(tileBase + pixels);
        FillBgTilemapRect(work->bgConfig, 3, tile, (u8)(i + 10), 5, 1, 1, 0x11);
        if (pixels < 8) {
            pixels = 0;
        } else {
            pixels = (u8)(pixels - 8);
        }
        i = (u8)(i + 1);
    } while (i < 6);
    ScheduleBgTilemapBufferTransfer(work->bgConfig, 3);
}

void sub_0208A1A0(SummaryWork *work) {
    typedef struct PackedSelection {
        u8 value : 7;
        u8 flag : 1;
    } PackedSelection;
    u32 current;
    u32 maximum;
    u32 pixels;
    u8 i;
    if (((PackedSelection *)((u8 *)work + 0x242))->value < 100) {
        u32 start = *(u32 *)((u8 *)work + 0x24c);
        maximum = *(u32 *)((u8 *)work + 0x250) - start;
        current = *(u32 *)((u8 *)work + 0x248) - start;
    } else {
        maximum = 0;
        current = 0;
    }
    pixels = CalculateHpBarPixelsLength(current, maximum, 0x38);
    i = 0;
    do {
        u32 tile = pixels >= 8 ? 0xe03f : (u16)(0xe037 + pixels);
        FillBgTilemapRect(work->bgConfig, 6, tile, (u8)(i + 9), 0x13, 1, 1, 0x11);
        if (pixels < 8) {
            pixels = 0;
        } else {
            pixels = (u8)(pixels - 8);
        }
        i = (u8)(i + 1);
    } while (i < 7);
    ScheduleBgTilemapBufferTransfer(work->bgConfig, 6);
}

void sub_0208A234(SummaryWork *work, u8 selection) {
    ((u8 *)work->monData)[0x14] = selection;
    sub_020897C0(work);
    sub_02089C50(work);
    sub_0208C57C(work);
    sub_0208C614(work);
    sub_0208C6B4(work);
    sub_02089F98(work);
    sub_0208E4B4(work);
    sub_0208B448(work);
    sub_0208BA60(work);
    sub_0208B5A8(work);
    sub_0208B89C(work);
    sub_0208B9C8(work);
    sub_0208C2A0(work);
    sub_0208BE70(work);
    sub_0208B48C(work);
    sub_0208B4EC(work);
    sub_0208BCD4(work);
    sub_0208BD38(work);
    sub_0208CBD4(work);
    sub_0208B400(work);
    sub_0208BFD0(work);
}
