#include "network_communication_state_internal.h"

int sub_0203993C(void) {
    if (_021D4150 != NULL) {
        return _021D4150->activity4E;
    }
    return 1;
}

int sub_02039954(void) {
    if (_021D4150 != NULL) {
        return _021D4150->parameter4F;
    }
    return 0;
}

void sub_0203996C(const void *src) {
    MI_CpuCopy8(src, _021D4150->trainerData, 6);
}

void sub_02039980(void *dst) {
    MI_CpuCopy8(_021D4150->trainerData, dst, 6);
}

int sub_02039998(void) {
    return sub_02034044(sub_0203993C());
}

void sub_020399A4(int status) {
    if (_021D4150 != NULL) {
        _021D4150->status56 = status;
    }
}

int sub_020399B8(void) {
    if (sub_0201A79C()) {
        return 0;
    }
    if (_021D4150 != NULL) {
        return _021D4150->status56;
    }
    return 0;
}

void sub_020399DC(int error) {
    ShowCommunicationError(0, 1, error);
    for (;;) {}
}

void sub_020399EC(void) {
    ShowCommunicationError(0, 4, 0);
    for (;;) {}
}

void sub_020399FC(void) {
}
