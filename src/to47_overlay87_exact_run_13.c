#include "to47_overlay87_private.h"

void ov87_021E7990(u8 *p) {
    p[14]++;
}
void ov87_021E7998(u8 *p) {
    p[14]++;
}
void ov87_021E79A0(State *p) {
    ov87_021E7FD4(*(SpriteWrap **)((u8 *)p + 0x340), 0);
    FillWindowPixelBuffer((u8 *)p + 0xfc, 0);
    ScheduleWindowCopyToVram((u8 *)p + 0xfc);
}
void ov87_021E79C4(State *p) {
    void *d;
    *(void **)((u8 *)p + 0x384) = GfGfxLoader_GetCharData(0xcf, 7, 0, (void **)((u8 *)p + 0x388), 0x7a);
    d = *(void **)((u8 *)p + 0x388);
    BG_LoadCharTilesData(*(void **)((u8 *)p + 0x58), 0, *((u32 *)d + 5), *((void **)d + 4), 0);
    BgCommitTilemapBufferToVram(*(void **)((u8 *)p + 0x58), 0);
}
void ov87_021E7A04(State *p) {
    void *d = *(void **)((u8 *)p + 0x388);
    *(void **)((u8 *)p + 0x38c) = Heap_Alloc(0x7a, *((u32 *)d + 4));
    if (*(void **)((u8 *)p + 0x38c) == 0) {
        if (*(void **)((u8 *)p + 0x38c) == 0) {
            GF_AssertFail();
        }
    }
}
void ov87_021E7A2C(State *p) {
    void *q = *(void **)((u8 *)p + 0x388);
    memcpy(*(void **)((u8 *)p + 0x38c), *((void **)q + 5), *((u32 *)q + 4));
}
