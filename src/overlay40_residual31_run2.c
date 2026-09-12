#include "overlay40_residual31_private.h"

#define PTR(p, off) (*(void **)((u8 *)(p) + (off)))

int ov40_02237AA8(void *p);

int ov40_02237AA8(void *p) {
    void *inner = PTR(p, 0x860);
    TouchHitboxController_IsTriggered(PTR(inner, 0x338));
    return 0;
}
