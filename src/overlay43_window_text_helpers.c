#include "overlay43_window_display_private.h"

void ov43_0222ECD4(void *window, int unused, void *ctx, int msgId, int x, int color, int y) {
    Ov43WindowMessageWork *work = ctx;

    ReadMsgDataIntoString(work->msgData, msgId, work->raw);
    StringExpandPlaceholders(work->formatted, work->expanded, work->raw);
    AddTextPrinterParameterizedWithColor(window, 1, work->expanded, x, color, 0xff, y, 0);
}

void ov43_0222ED18(void *ptr, int delta) {
    Ov43WrappedCursor *cursor = ptr;
    int divisor = cursor->mode == 1 ? 8 : 3;

    if (delta > 0) {
        cursor->previous = cursor->current;
        cursor->current = (cursor->current + delta) % divisor;
    } else if (delta < 0) {
        cursor->previous = cursor->current;
        cursor->current += delta;
        if (cursor->current < 0) {
            cursor->current += divisor;
        }
    }
}
