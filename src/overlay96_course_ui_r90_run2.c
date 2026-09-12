#include "overlay96_course_ui_r90_private.h"

void ov96_02207D64(void *work) {
    int i;
    u8 *p;

    i = 0;
    p = work;
    for (; i < 3; i++, p += 8) {
        Heap_Free(OV96_R90_PTR(p, 0x108));
        Heap_Free(OV96_R90_PTR(p, 0x10C));
    }
    {
        u8 *q = work;
        int j = 0;
        for (; j < 12; j++, q += 4) {
            Heap_Free(OV96_R90_PTR(q, 0x9C));
        }
    }
    Heap_Free(OV96_R90_PTR(work, 0x24));
    {
        u8 *q = work;
        int j = 0;
        for (; j < 3; j++, q += 4) {
            String_Delete(OV96_R90_PTR(q, 0x1A8));
        }
    }
    MessageFormat_Delete(OV96_R90_PTR(work, 0x20));
    DestroyMsgData(OV96_R90_PTR(work, 0x1C));
    RemoveWindow((u8 *)work + 0xC);
    Heap_Free(work);
}
