#include "ov00_partial_internal.h"

extern Ov00Sys *_0221A680;
extern u32 _0221A684;
#define sOv00Sys  _0221A680
#define sVctBlock (*(Ov00VctBlock *)((u8 *)&_0221A684 + 4))

void ov00_021E6CA4(u32 a0) {
    if (sOv00Sys != NULL) {
        sOv00Sys->unk_0FC0 = a0;
    }
}

void ov00_021E6CB8(void) {
    ov00_021ED9B4();
    ov00_021EC8D8();
    ov00_021E6A4C();
    ov00_021E5AE8();
}

void ov00_021E6CCC(u32 a0, u32 a1) {
    sOv00Sys->unk_1064 = a0;
    sOv00Sys->unk_1068 = a1;
}
