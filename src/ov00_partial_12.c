#include "ov00_partial_internal.h"

extern Ov00Sys *_0221A680;
extern u32 _0221A684;
#define sOv00Sys  _0221A680
#define sVctBlock (*(Ov00VctBlock *)((u8 *)&_0221A684 + 4))

u32 ov00_021E7080(void) {
    if (sOv00Sys != NULL) {
        return sOv00Sys->unk_109C;
    }
    return 0;
}

u32 ov00_021E709C(void) {
    if (sOv00Sys != NULL) {
        return sOv00Sys->unk_1098;
    }
    return 0;
}

void ov00_021E70B8(u32 a0) {
    sOv00Sys->unk_109C = a0;
}

void ov00_021E70CC(u16 a0) {
    sOv00Sys->unk_10D6 = a0;
}

void ov00_021E70E0(void) {
    sOv00Sys->unk_10E0 = 2;
}
