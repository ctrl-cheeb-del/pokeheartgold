#include "r40_overlay_49_residual_59_unmatched_1_private.h"

BOOL ov49_0225F448(void *controller, void *work, u32 index) {
    struct {
        void *entry;
        void *selection;
    } volatile temp;
    void *object;

    object = ov49_02259FF0(work);
    temp.entry = ov49_02258D70(object, index);
    temp.selection = ov49_02259FE8(work);

    switch (ov49_0225EF88(controller)) {
    case 0:
        ov49_0225A56C(work, index);
        ov49_0225EF8C(controller, 1);
        if (index == ov45_0222A53C(temp.selection)) {
            ov49_0225A53C(work, 0);
        }
        break;
    case 1:
        if (ov49_0225A5AC(work, index) == 1) {
            ov49_0225EF8C(controller, 2);
        }
        break;
    case 2:
        if (index == ov45_0222A53C(temp.selection)) {
            ov49_02258EEC(object, temp.entry, 1);
        } else {
            if (ov49_0225A4F0(work) == 1) {
                if (index != ov49_0225A4E0(work)) {
                    ov49_02258EEC(object, temp.entry, 2);
                }
            } else {
                ov49_02258EEC(object, temp.entry, 2);
            }
            ov49_0225A04C(work, (u8)index, 0);
        }
        ov49_0225A54C(work);
        return TRUE;
    default:
        break;
    }

    return FALSE;
}
