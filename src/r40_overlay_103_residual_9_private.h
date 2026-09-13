#ifndef R40_OV103_R9_PRIVATE_H
#define R40_OV103_R9_PRIVATE_H
#include "global.h"

#include "yes_no_prompt.h"
typedef struct R40Ov103Work9 {
    u8 pad[0xC];
    u8 *ctx;
} R40Ov103Work9;
typedef u32 (*R40Fn9)(R40Ov103Work9 *);
extern R40Fn9 ov103_021EEC68[][2];
u32 ov103_021ED4D4(R40Ov103Work9 *);
#endif
