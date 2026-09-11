#include "ov00_partial_internal.h"

extern Ov00Sys *_0221A680;
extern u32 _0221A684;
#define sOv00Sys  _0221A680
#define sVctBlock (*(Ov00VctBlock *)((u8 *)&_0221A684 + 4))

void ov00_021E7300(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        ov00_021E7234((u32)i);
    }
}

u8 ov00_021E7314(void) {
    return sOv00Sys->unk_10E6;
}

void ov00_021E7328(void) {
    sOv00Sys->unk_10E6 = 0;
}
