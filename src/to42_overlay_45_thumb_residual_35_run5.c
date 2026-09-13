#include "to42_overlay_45_thumb_residual_35_private.h"
int ov45_022301E0(void *work, int index, u32 key) {
    if (index >= 3) {
        GF_AssertFail();
    }
    if (ov45_0223021C(work, index) == 1) {
        u8 *entry = (u8 *)work + index * 0x4c;
        if (key == *(u32 *)(entry + 0x600)) {
            *(u16 *)(entry + 0x5fc) = 0;
            return 1;
        }
    }
    return 0;
}
int ov45_0223021C(void *work, int index) {
    if (index >= 3) {
        GF_AssertFail();
    }
    return *(u16 *)((u8 *)work + index * 0x4c + 0x5fc);
}
u16 ov45_0223023C(void *work, int index) {
    Ov45Pair stamp;
    s64 elapsed;
    if (ov45_0223021C(work, index) == 0) {
        return 0;
    }
    ov45_02230384(ov45_022302B0(work, index), (u32 *)&stamp);
    elapsed = *(s64 *)((u8 *)work + 0x19c) - *(s64 *)&stamp;
    if (elapsed > 30) {
        elapsed = 30;
    } else if (elapsed < 0) {
        elapsed = 0;
    }
    return (u16)((60 - elapsed) * 30);
}
void *ov45_022302B0(void *work, int index) {
    int offset;
    if (index >= 3) {
        GF_AssertFail();
    }
    offset = index * 0x4c;
    if (*(u16 *)((u8 *)work + offset + 0x5fc) != 1) {
        GF_AssertFail();
    }
    return (u8 *)work + 0x5b8 + offset;
}
