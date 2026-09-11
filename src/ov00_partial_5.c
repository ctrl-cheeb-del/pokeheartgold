#include "ov00_partial_internal.h"

extern Ov00Sys *_0221A680;
extern u32 _0221A684;
#define sOv00Sys  _0221A680
#define sVctBlock (*(Ov00VctBlock *)((u8 *)&_0221A684 + 4))

u32 ov00_021E6424(void) {
    return 1;
}

void ov00_021E6428(u32 a0, s32 a1) {
    sOv00Sys->unk_1078 = 0;
    sOv00Sys->unk_10AC[a1] = 0;
}
