#include "overlay49_window_setup_teardown_internal.h"

void ov49_0225BB14(void *owner, NARC *narc, int member, int bgId, int tileOffset, enum HeapID heapId) {
    NNSG2dScreenData *screen;
    void *allocation;
    int i;
    int count;
    u16 *rawData;

    allocation = GfGfxLoader_GetScrnDataFromOpenNarc(narc, member, FALSE, &screen, heapId);
    count = screen->szByte >> 1;
    rawData = (u16 *)screen->rawData;
    for (i = 0; i < count; i++) {
        rawData[i] += tileOffset;
    }
    LoadRectToBgTilemapRect(*(BgConfig **)owner, bgId, screen->rawData, 0, 0, (u8)(screen->screenWidth >> 3), (u8)(screen->screenHeight >> 3));
    ScheduleBgTilemapBufferTransfer(*(BgConfig **)owner, bgId);
    Heap_Free(allocation);
}

void ov49_0225BB84(Ov49WindowGroup *windows, void *display) {
    int i;
    const WindowTemplate *template = ov49_022697F4;
    Window *window;

    i = 0;
    window = windows->windows;
    do {
        AddWindow(*(BgConfig **)display, window, template);
        i++;
        template++;
        window++;
    } while (i < 5);
}

void ov49_0225BBA8(Ov49WindowGroup *windows, void *unused, void *context) {
    int i;

    if (windows->handler != NULL) {
        ov49_0225BF80(windows, unused, context);
    }
    for (i = 0; i < 5; i++) {
        RemoveWindow(&windows->windows[i]);
    }
}
