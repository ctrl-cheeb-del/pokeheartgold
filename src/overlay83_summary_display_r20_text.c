#include "overlay83_summary_display_r20_private.h"

void ov83_02241DD8(u8 *work, void *window, void *msgData, int msgNo, int x, int y, int color, int a, int b) {
    void *string = NewString_ReadMsgData(msgData, msgNo);

    StringExpandPlaceholders(*(void **)(work + 0x24), *(void **)(work + 0x28), string);
    ov83_02247998(window, *(void **)(work + 0x28), x, y, color, a, b);
    String_Delete(string);
}
