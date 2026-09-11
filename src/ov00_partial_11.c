#include "ov00_partial_internal.h"

extern Ov00Sys *_0221A680;
extern u32 _0221A684;
#define sOv00Sys  _0221A680
#define sVctBlock (*(Ov00VctBlock *)((u8 *)&_0221A684 + 4))

void ov00_021E6FBC(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
    sOv00Sys->unk_10A0 = 0;
    if (a0 == 0 && a1 == 0) {
        ov00_021E6388(a4);
    }
}
