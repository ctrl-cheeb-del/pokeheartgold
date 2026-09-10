#include "network_communication_state_internal.h"

BOOL sub_02039AA4(void) {
    if (sub_02035630() != 0 || sub_02037D78() == 0) {
        return TRUE;
    }
    if (sub_02034BE4() == 0) {
        return TRUE;
    }
    if (sub_02033974() != 0) {
        return TRUE;
    }
    return FALSE;
}

BOOL sub_02039AD8(int country) {
    if (_021D4150 != NULL) {
        _021D4150->country5D = country;
        sub_02037988(country);
        return TRUE;
    }
    return FALSE;
}

void sub_02039AF8(void) {
    _021D4150->activity4E = 0x1D;
    ov00_021E5C84(sub_020369CC, sub_020369CC);
}

void sub_02039B18(void) {
    _021D4150->activity4E = 0x23;
    ov00_021E5C84(sub_020369CC, sub_020369CC);
}

void sub_02039B38(void) {
    _021D4150->activity4E = 0x21;
    ov00_021E5C84(sub_020369CC, sub_020369CC);
}

void sub_02039B58(void) {
    _021D4150->activity4E = 0x17;
    ov00_021E5C84(sub_02036904, sub_020367A8);
}

void sub_02039B7C(void) {
    _021D4150->activity4E = 0x13;
    ov00_021E5C84(sub_02036904, sub_020367A8);
}
