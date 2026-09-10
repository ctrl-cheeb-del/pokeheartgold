#include "communication_player_movement_internal.h"

void sub_0205776C(int a, int b, const u8 *data, void *fieldSystem) {
    int slot = *data;
    if (_021D41C4 != NULL && slot != sub_0203769C()) {
        sub_0205724C(slot, 0, 0);
        sub_020346E8(slot);
    }
}

int sub_02057798(void) {
    return 5;
}
