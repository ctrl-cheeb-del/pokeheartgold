#include "overlay108_area_page_private.h"

void ov108_021E7C5C(Ov108AreaPageWork *work) {
    int i;

    if (work->active != 0) {
        for (i = 0; i < 5; i++) {
            Ov108AreaWindow *window = &work->windows[5 + i * 2];
            ReadMsgDataIntoString(work->msgData, i + 10, work->string);
            AddTextPrinterParameterizedWithColor(window, 0, work->string, 0, 0, 0, ov108_021EA724[i % 2], 0);
            CopyWindowToVram(window);
        }
    }
}
