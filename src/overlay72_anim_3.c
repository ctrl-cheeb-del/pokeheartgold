#include "overlay72_anim_internal.h"
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
typedef struct Ov72AnimCtl {
    u8 mode;
    u8 state;
    u8 layer;
    u8 timer;
    u8 x;
    u8 y;
    u8 w;
    u8 h;
    u16 first;
    u16 second;
} Ov72AnimCtl;

void ov72_0223AF1C(void *p) {
    u8 *q = p;
    q[0x2D] = 0;
    q[0x33] = q[0x2C];
    ov72_0223B0C4(p);
    ov72_0223B1C8(p);
    ov72_0223B2E4(p);
}

int ov72_0223AF48(void *p) {
    int r = ov72_0223B7FC[((u8 *)p)[0x2D]](p);
    if (r == 1) {
        return ((u8 *)p)[0x33] + 1;
    }
    return 0;
}
