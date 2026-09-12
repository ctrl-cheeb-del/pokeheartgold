#include "overlay40_pc_box_wallpaper_private.h"

void ov40_02244494(void *w) {
    u8 *p = PTR(w, 0x860);
    ClearWindowTilemapAndCopyToVram(p + 0x10);
    RemoveWindow(p + 0x10);
    ClearWindowTilemapAndCopyToVram(p + 0x20);
    RemoveWindow(p + 0x20);
}

int ov40_022444C0(void *w) {
    void *p = Heap_Alloc(0x6D, 0x30);
    memset(p, 0, 0x30);
    PTR(w, 0x860) = p;
    BgClearTilemapBufferAndCommit(PTR(w, 0x24), 2);
    BgClearTilemapBufferAndCommit(PTR(w, 0x24), 3);
    BgClearTilemapBufferAndCommit(PTR(w, 0x24), 6);
    BgClearTilemapBufferAndCommit(PTR(w, 0x24), 7);
    ov40_0222D9E8(p, (u8 *)p + 4, 0);
    ov40_0222BF80(w, 1);
    return 0;
}
