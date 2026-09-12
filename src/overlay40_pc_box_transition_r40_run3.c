#include "overlay40_pc_box_transition_r40_private.h"

void ov40_0224395C(u8 *work) {
    switch (OV40_R40_S32(work, 0x29C)) {
    case 1:
        ov40_0224301C(work, OV40_R40_S32(work, 0x2A0));
        ov40_02244060(work);
        ov40_022440A0(work, 1);
        ov40_0224320C(work, 2);
        OV40_R40_S32(work, 0x29C) = 0xFF;
        break;
    case 2:
        ov40_02243EB0(work, OV40_R40_S32(work, 0x2A0));
        ov40_022439B8(work);
        break;
    case 0:
    case 0xFF:
        break;
    }
}
