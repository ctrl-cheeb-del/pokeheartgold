#include "overlay96_course_ui_r101_private.h"

void ov96_0220EE4C(void *work) {
    int i;

    RemoveWindow((u8 *)work + 0x24);
    MessageFormat_Delete(PTR(work, 0x14));
    DestroyMsgData(PTR(work, 0x18));
    for (i = 0; i < 7; i++) {
        FreeBgTilemapBuffer(PTR(work, 8), (u8)ov96_0221CF58[i]);
    }
    FontID_Release(4);
    Heap_Free(PTR(work, 8));
}
