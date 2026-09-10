#include "render_window_internal.h"

void sub_0200E398(void *dest, u32 member, u32 value, BOOL compressed, u32 heapId) {
    if (compressed == 0) {
        GfGfxLoader_LoadCharData(0x26, 0, dest, member, value, 0, 0, heapId);
    } else {
        GfGfxLoader_LoadCharData(0x26, 1, dest, member, value, 0, 0, heapId);
    }
}

u32 sub_0200E3D8(void) {
    return 0x19;
}
