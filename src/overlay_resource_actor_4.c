#include "overlay_resource_actor_internal.h"

void sub_020772F8(Work *work) {
    void *str = NewString_ReadMsgData(work->msgData);
    StringExpandPlaceholders(work->msgFmt, work->string, str);
    Heap_Free(str);
    FillWindowPixelBuffer(work->windows, 0xff);
    AddTextPrinterParameterized(work->windows, 1, work->string, 0, 0, Options_GetTextFrameDelay(work->options), (void *)sub_02077340);
}

int sub_02077340(void *unused, int event) {
    int result = 0;
    switch (event) {
    case 1:
        result = GF_IsAnySEPlaying();
        break;
    case 2:
        result = IsFanfarePlaying();
        break;
    case 3:
        PlayFanfare(0x4a4);
        break;
    case 4:
        PlaySE(0x5e6);
        break;
    case 5:
        PlayFanfare(0x4a0);
        break;
    }
    return result;
}

void sub_02077394(Work *work) {
    work->overlayMan = OverlayManager_New((void *)gOverlayTemplate_PokemonSummary, work->summaryArgs, work->heapId);
}
