#ifndef R40_OV103_R5_PRIVATE_H
#define R40_OV103_R5_PRIVATE_H
#include "global.h"

#include "touchscreen_list_menu.h"
typedef struct R40Ov103Work5 {
    u8 pad[0xC];
    u8 *ctx;
} R40Ov103Work5;
extern const TouchscreenListMenuTemplate _021EEB34;
extern u32 ov103_021ED2B8(void *);
void ov103_021ECF68(R40Ov103Work5 *);
#endif
