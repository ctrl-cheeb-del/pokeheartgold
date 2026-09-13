#ifndef R40_OV103_R3_PRIVATE_H
#define R40_OV103_R3_PRIVATE_H
#include "global.h"

#include "filesystem.h"
#include "gf_gfx_loader.h"
typedef struct R40Ov103Work3 {
    u8 pad[0xC];
    u8 *ctx;
} R40Ov103Work3;
void ov103_021ECC1C(R40Ov103Work3 *);
#endif
