#include "overlay96_ui_helpers_private.h"

void ov96_021EE808(u8 *p) {
    DestroyMsgData(*(void **)(p + 8));
    DestroyMsgData(*(void **)(p + 0xC));
    MessageFormat_Delete(*(void **)(p + 4));
    if (*(void **)(p + 0x10) != NULL) String_Delete(*(void **)(p + 0x10));
    Heap_Free(p);
}
