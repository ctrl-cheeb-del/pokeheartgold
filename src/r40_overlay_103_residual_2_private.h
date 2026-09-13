#ifndef R40_OV103_R2_PRIVATE_H
#define R40_OV103_R2_PRIVATE_H
#include "global.h"

#include "bg_window.h"
typedef struct R40Ov103Work2 {
    u8 pad[0xC];
    u8 *ctx;
} R40Ov103Work2;
extern const GraphicsModes ov103_021EEB40;
extern const BgTemplate ov103_021EEBC0, ov103_021EEBA4, ov103_021EEB88, ov103_021EEC14;
extern const BgTemplate ov103_021EEBDC, ov103_021EEB50, ov103_021EEB6C, ov103_021EEBF8;
void ov103_021EC9E8(R40Ov103Work2 *);
#endif
