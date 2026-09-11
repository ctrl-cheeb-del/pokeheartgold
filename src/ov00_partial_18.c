#include "ov00_partial_internal.h"

extern Ov00Sys *_0221A680;
extern u32 _0221A684;
#define sOv00Sys  _0221A680
#define sVctBlock (*(Ov00VctBlock *)((u8 *)&_0221A684 + 4))

void ov00_021E7ACC(void) {
    sVctBlock.unk_00->unk_19F0 = 1;
}

void ov00_021E7AE0(void) {
    sVctBlock.unk_00->unk_19F0 = 0;
}
