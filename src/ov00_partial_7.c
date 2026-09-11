#include "ov00_partial_internal.h"

extern Ov00Sys *_0221A680;
extern u32 _0221A684;
#define sOv00Sys  _0221A680
#define sVctBlock (*(Ov00VctBlock *)((u8 *)&_0221A684 + 4))

void ov00_021E6A4C(void) {
    ov00_021E7A30();
    if (sOv00Sys != NULL) {
        sOv00Sys->unk_1090 = 0;
        sOv00Sys->unk_1080 = 0;
    }
}
