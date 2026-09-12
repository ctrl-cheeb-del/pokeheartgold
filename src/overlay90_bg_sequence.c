#include "overlay90_bg_sequence_internal.h"

void ov90_0225A350(Ov90R18Work *work, void *bg, int heapId) {
    u32 width;
    work->counter2C = 0;
    work->state2E = 0;
    ov90_02258CF0((u8 *)work + 0x18, ov90_0225C258[work->mode10], ov90_0225C228[work->mode10], ov90_0225C21C[work->mode10], 16);
    ov90_0225A5BC(work, bg, work->value18 >> 12);
    FontID_Alloc(2, heapId);
    width = FontID_String_GetWidth(2, work->string14, 0);
    AddTextPrinterParameterizedWithColor(work, 2, work->string14, 0x50 - (width >> 1), 0, 0, ov90_0225C210[work->mode10], NULL);
    FontID_Release(2);
    GfGfx_EngineATogglePlanes(1, 1);
}

void ov90_0225A3E0(Ov90R18Work *work, void *bg) {
    work->counter2C = 0;
    work->state2E = 0;
    ov90_02258CF0((u8 *)work + 0x18, ov90_0225C228[work->mode10], ov90_0225C1F8[work->mode10], ov90_0225C204[work->mode10], 8);
    ov90_0225A60C(work, bg, work->value18 >> 12);
}

BOOL ov90_0225A428(Ov90R18Work *work, void *bg) {
    int done;

    switch (work->state2E) {
    case 0:
        done = ov90_02258D4C((u8 *)work + 0x18, work->counter2C);
        ov90_0225A60C(work, bg, work->value18 >> 12);
        work->counter2C++;
        if (done == 1) {
            PlaySE(0x581);
            ov90_02258CF0((u8 *)work + 0x18, ov90_0225C228[work->mode10], ov90_0225C234[work->mode10], ov90_0225C240[work->mode10], 4);
            work->state2E++;
            work->counter2C = 0;
        }
        break;
    case 1:
        done = ov90_02258D4C((u8 *)work + 0x18, work->counter2C);
        ov90_0225A60C(work, bg, work->value18 >> 12);
        work->counter2C++;
        if (done == 1) {
            ov90_02258CF0((u8 *)work + 0x18, ov90_0225C234[work->mode10], ov90_0225C228[work->mode10], ov90_0225C24C[work->mode10], 4);
            work->state2E++;
            work->counter2C = 0;
        }
        break;
    case 2:
        done = ov90_02258D4C((u8 *)work + 0x18, work->counter2C);
        ov90_0225A60C(work, bg, work->value18 >> 12);
        work->counter2C++;
        if (done == 1) {
            work->state2E++;
        }
        break;
    case 3:
        return TRUE;
    }
    return FALSE;
}

BOOL ov90_0225A544(Ov90R18Work *work, void *bg) {
    int done;
    switch (work->state2E) {
    case 0:
        done = ov90_02258D4C((u8 *)work + 0x18, work->counter2C);
        ov90_0225A60C(work, bg, work->value18 >> 12);
        work->counter2C++;
        if (done == 1) {
            work->state2E++;
        }
        break;
    case 1:
        ClearWindowTilemapAndCopyToVram(work);
        GfGfx_EngineATogglePlanes(1, 0);
        ov90_0225A5BC(work, bg, 0);
        BgClearTilemapBufferAndCommit(*(void **)bg, 0);
        BgClearTilemapBufferAndCommit(*(void **)bg, 1);
        GfGfx_EngineATogglePlanes(1, 1);
        return TRUE;
    }
    return FALSE;
}

void ov90_0225A5BC(Ov90R18Work *work, void *bg, int value) {
    switch (work->mode10) {
    case 0:
    case 1:
        BgSetPosTextAndCommit(*(void **)bg, 0, 0, value);
        BgSetPosTextAndCommit(*(void **)bg, 1, 0, value);
        break;
    case 2:
        BgSetPosTextAndCommit(*(void **)bg, 0, 3, value);
        BgSetPosTextAndCommit(*(void **)bg, 1, 3, value);
        break;
    default:
        GF_AssertFail();
        break;
    }
}

void ov90_0225A60C(Ov90R18Work *work, void *bg, int value) {
    switch (work->mode10) {
    case 0:
    case 1:
        ScheduleSetBgPosText(*(void **)bg, 0, 0, value);
        ScheduleSetBgPosText(*(void **)bg, 1, 0, value);
        break;
    case 2:
        ScheduleSetBgPosText(*(void **)bg, 0, 3, value);
        ScheduleSetBgPosText(*(void **)bg, 1, 3, value);
        break;
    default:
        GF_AssertFail();
        break;
    }
}

void ov90_0225A65C(void *narc, int type, int heapId) {
    int offset;
    int palette;
    switch (type) {
    case 0:
        palette = 1;
        break;
    case 1:
        palette = 2;
        break;
    case 2:
        palette = 0;
        break;
    default:
        palette = 1;
        break;
    }
    offset = palette << 5;
    GfGfxLoader_GXLoadPalWithSrcOffsetFromOpenNarc(narc, 5, 0, offset, 0xA0, 0x20, heapId);
    GfGfxLoader_GXLoadPalWithSrcOffsetFromOpenNarc(narc, 5, 4, offset, 0xA0, 0x20, heapId);
}
