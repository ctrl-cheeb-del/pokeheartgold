#include "network_communication_state_internal.h"

BOOL sub_02039080(int flag) {
    if (_021D4150->callback != sub_02038F9C) {
        return FALSE;
    }
    ov00_021E5C84(sub_02036904, sub_020367A8);
    _021D4150->pad51 = flag;
    sub_020381C0(sub_0203900C, 0);
    return TRUE;
}
