#include "overlay49_camera_lookat_private.h"

void ov49_0225CBF4(void *p) {
    if (PTR(p, 4) != NULL) {
        ov49_02259154(PTR(p, 4), (u8 *)p + 8);
        S32_AT(p, 8) += 0x8000;
        S32_AT(p, 0x10) -= 0x20000;
    }
    Camera_PushLookAtToNNSGlb();
}
