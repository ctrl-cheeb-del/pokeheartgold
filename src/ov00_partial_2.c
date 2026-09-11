#include "ov00_partial_internal.h"

extern Ov00Sys *_0221A680;
extern u32 _0221A684;
#define sOv00Sys  _0221A680
#define sVctBlock (*(Ov00VctBlock *)((u8 *)&_0221A684 + 4))

void ov00_021E5E34(void) {
    if (sOv00Sys->unk_1070 == 10) {
        sOv00Sys->unk_1070 = 11;
    } else {
        sOv00Sys->unk_1070 = 9;
    }
}
