#include "to47_overlay15_windows_r23_private.h"

void ov15_021FE17C(Ov15BagWorkR23 *work)
{
    int i;

    if (work->windows[0].bgConfig != NULL) {
        return;
    }

    for (i = 0; i < 12; i++) {
        AddWindowParameterized(work->bgConfig, &work->windows[i], 4,
            ov15_02200908[i].x, ov15_02200908[i].y, 11, 4, 11,
            ov15_02200908[i].baseTile);
    }
}

void ov15_021FE1D0(Ov15BagWorkR23 *work)
{
    int i;

    if (work->windows[0].bgConfig == NULL) {
        return;
    }

    for (i = 0; i < 12; i++) {
        ClearWindowTilemapAndScheduleTransfer(&work->windows[i]);
        RemoveWindow(&work->windows[i]);
        work->windows[i].bgConfig = NULL;
    }
}

void ov15_021FE204(Ov15BagWorkR23 *work)
{
    int i;
    int baseTile;
    const Ov15PositionR23 *position;

    if (work->windows[12].bgConfig != NULL) {
        return;
    }

    AddWindowParameterized(work->bgConfig, &work->windows[12], 4, 12, 7, 11, 4, 11, 0x2CF);
    FillWindowPixelBuffer(&work->windows[12], 0);

    baseTile = 0x31B;
    position = ov15_022008E8;
    for (i = 0; i < 4; i++) {
        AddWindowParameterized(work->bgConfig, &work->windows[i + 13], 4,
            position->x, position->y, 10, 2, 11, baseTile);
        FillWindowPixelBuffer(&work->windows[i + 13], 0);
        baseTile += 20;
        position++;
    }

    baseTile = 0x2FB;
    position = ov15_022008D0;
    for (i = 0; i < 3; i++) {
        AddWindowParameterized(work->bgConfig, &work->windows[i + 17], 4,
            position->x, position->y, 2, 3, 11, baseTile);
        FillWindowPixelBuffer(&work->windows[i + 17], 0);
        baseTile += 6;
        position++;
    }

    AddWindowParameterized(work->bgConfig, &work->windows[20], 4, 14, 21, 7, 2, 11, 0x30D);
    FillWindowPixelBuffer(&work->windows[20], 0);
    AddWindowParameterized(work->bgConfig, &work->windows[21], 4, 11, 1, 18, 4, 11, 0x31B);
    FillWindowPixelBuffer(&work->windows[21], 0);
    AddWindowParameterized(work->bgConfig, &work->windows[22], 4, 0, 0, 9, 4, 11, 0x363);
    FillWindowPixelBuffer(&work->windows[22], 0);
    AddWindowParameterized(work->bgConfig, &work->windows[23], 4, 24, 14, 8, 3, 11, 0x387);
    FillWindowPixelBuffer(&work->windows[23], 0);
}

void ov15_021FE3E0(Ov15BagWorkR23 *work)
{
    int i;

    if (work->windows[12].bgConfig == NULL) {
        return;
    }

    for (i = 0; i < 3; i++) {
        ClearWindowTilemapAndScheduleTransfer(&work->windows[i + 17]);
        RemoveWindow(&work->windows[i + 17]);
        work->windows[i + 17].bgConfig = NULL;
    }
    ClearWindowTilemapAndScheduleTransfer(&work->windows[23]);
    RemoveWindow(&work->windows[23]);
    work->windows[23].bgConfig = NULL;
    RemoveWindow(&work->windows[22]);
    work->windows[22].bgConfig = NULL;
    RemoveWindow(&work->windows[21]);
    work->windows[21].bgConfig = NULL;
    ClearWindowTilemapAndScheduleTransfer(&work->windows[20]);
    RemoveWindow(&work->windows[20]);
    work->windows[20].bgConfig = NULL;
    for (i = 0; i < 4; i++) {
        ClearWindowTilemapAndScheduleTransfer(&work->windows[i + 13]);
        RemoveWindow(&work->windows[i + 13]);
        work->windows[i + 13].bgConfig = NULL;
    }
    ClearWindowTilemapAndScheduleTransfer(&work->windows[12]);
    RemoveWindow(&work->windows[12]);
    work->windows[12].bgConfig = NULL;
}

void ov15_021FE4C8(Ov15BagWorkR23 *work)
{
    MsgData *msgData;
    u16 i;

    msgData = NewMsgDataFromNarc(MSGDATA_LOAD_LAZY, (NarcId)0x1B, 0xE1, (enum HeapID)6);
    for (i = 0; i < 8; i++) {
        work->strings[i] = NewString_ReadMsgData(msgData, i);
    }
    DestroyMsgData(msgData);
}
