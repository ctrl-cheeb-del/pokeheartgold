#include "ov00_partial_internal.h"

extern Ov00Sys *_0221A680;
extern u32 _0221A684;
#define sOv00Sys  _0221A680
#define sVctBlock (*(Ov00VctBlock *)((u8 *)&_0221A684 + 4))

s32 ov00_021E6EBC(void) {
    if (sOv00Sys != NULL) {
        return (s32)sOv00Sys->unk_1094;
    }
    return -1;
}
