#include "overlay89_r23_object_pool.h"

BOOL ov89_0225AEA8(const Ov89Rect *a, const Ov89Rect *b) {
    if (a->left <= b->right && b->left <= a->right && a->bottom >= b->top && b->bottom >= a->top) {
        return TRUE;
    }
    return FALSE;
}

void ov89_0225AED0(u8 *work, u8 *arg) {
    int i;
    u8 *entry = work + 0x53C;
    for (i = 0; i < 128; i++, entry += 4) {
        if (entry[1] == 0) {
            *(u32 *)(arg + 0x240) = (*(u32 *)(arg + 0x240) & 0xFFFFFF) | (i << 24);
            entry[0] = 0;
            entry[1]++;
            return;
        }
    }
    GF_AssertFail();
}
