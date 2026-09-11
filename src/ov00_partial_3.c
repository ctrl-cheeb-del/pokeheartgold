#include "ov00_partial_internal.h"

extern Ov00Sys *_0221A680;
extern u32 _0221A684;
#define sOv00Sys  _0221A680
#define sVctBlock (*(Ov00VctBlock *)((u8 *)&_0221A684 + 4))

void ov00_021E6274(u32 a0) {
    if (a0 == 0) {
        sOv00Sys->unk_1070 = 4;
    } else {
        sOv00Sys->unk_1070 = 12;
    }
}

void ov00_021E6298(void) {
}
