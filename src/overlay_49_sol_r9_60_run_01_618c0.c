#include "overlay49_sol_r9_60_private.h"

BOOL ov49_022618C0(void *state, void *ctx, u32 index) {
    void *object = ov49_02259FF0(ctx);
    void *target = ov49_02258D70(object, index);

    switch (ov49_0225EF88(state)) {
    case 0:
        ov49_02258EEC(object, (u32)target, 3);
        ov49_0225EF90(state);
        break;
    case 1:
        if (ov49_02258F38(target) != 0) {
            ov49_0225EF90(state);
        }
        break;
    case 2:
        ov49_02258D54(target);
        ov49_0225EF98(ov49_0225A010(ctx), index, ov49_02269B78, 0);
        break;
    }
    return FALSE;
}
