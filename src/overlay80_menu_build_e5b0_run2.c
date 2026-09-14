#include "overlay80_menu_build_e5b0_private.h"

void ov80_0222E88C(void *work) {
    void *owner = PTR_AT(work, 0);
    s32 i;
    u8 *cursor;

    PlaySE(0x5DC);
    Delete2dMenu(PTR_AT(work, 0xB0), 0);
    sub_0200E5D4(PTR_AT(work, 0xA8), 0);
    RemoveWindow(PTR_AT(work, 0xA8));
    i = 0;
    cursor = work;
    do {
        String_Delete(PTR_AT(cursor, 0x1C));
        i++;
        cursor += 4;
    } while (i < 28);
    if (((u32)U8_AT(work, 0x97) << 30) >> 31 == 1) {
        DestroyMsgData(PTR_AT(work, 0x8C));
    }
    SysTask_Destroy(PTR_AT(work, 4));
    Heap_Free(work);
    PTR_AT(owner, 0x60) = NULL;
}
