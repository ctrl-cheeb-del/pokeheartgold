#include "overlay40_pc_box_transition_r40_private.h"

int ov40_02243538(u8 *work) {
    int result = ov40_02245C18[OV40_R40_S32(work, 0x1F4)](work);

    if (result == 0) {
        ov40_02243F88(work);
    }
    return result;
}
