#include "overlay40_pc_box_transition_r40_private.h"

int ov40_02243284(u8 *work) {
    if (OV40_R40_S32(work, 0x1FC) == 0) {
        OV40_R40_S32(work, 0x1FC)
        ++;
    } else {
        ov40_0224395C(work);
        TouchHitboxController_IsTriggered(OV40_R40_PTR(work, 0x234));
    }
    return 0;
}
