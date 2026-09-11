#include "ov00_partial_internal.h"

extern Ov00Sys *_0221A680;
extern u32 _0221A684;
#define sOv00Sys  _0221A680
#define sVctBlock (*(Ov00VctBlock *)((u8 *)&_0221A684 + 4))

void ov00_021E5C84(u32 a0, u32 a1) {
    sOv00Sys->unk_0FA4 = a0;
    sOv00Sys->unk_0FA8 = a1;
}

void ov00_021E5CA0(u32 a0, u32 a1) {
    sOv00Sys->unk_0FAC = a0;
    sOv00Sys->unk_0FB0 = a1;
}

void ov00_021E5CBC(u32 a0) {
    sOv00Sys->unk_0FBC = a0;
}

void ov00_021E5CD0(u32 a0, u32 a1) {
    sOv00Sys->unk_0FB4 = a0;
    sOv00Sys->unk_0FB8 = a1;
}
