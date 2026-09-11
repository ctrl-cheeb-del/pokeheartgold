#include "ov00_partial_internal.h"

extern Ov00Sys *_0221A680;
extern u32 _0221A684;
#define sOv00Sys  _0221A680
#define sVctBlock (*(Ov00VctBlock *)((u8 *)&_0221A684 + 4))

void ov00_021E62D4(void) {
}

void ov00_021E62D8(void) {
    MI_CpuFill8(sOv00Sys->unk_10AC, 0, 0x20);
}
