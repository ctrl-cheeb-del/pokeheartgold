#include "communication_manager_internal.h"

void sub_0203622C(void) {
    u8 lock = _021D4140.updateLock;
    _021D4140.updateLock = 0;
    if (_021D4140.work != NULL) {
        sub_02035DA4();
    }
    _021D4140.updateLock = lock;
}

void sub_0203624C(void) {
    u8 lock = _021D4140.updateLock;
    _021D4140.updateLock = 0;
    if (_021D4140.work != NULL) {
        _021D4140.work[0x6AD] = 1;
        sub_02035DA4();
    }
    _021D4140.updateLock = lock;
}

void sub_02036274(void) {
    u8 lock = _021D4140.updateLock;
    _021D4140.updateLock = 0;
    if (_021D4140.work != NULL) {
        sub_02035DA4();
        sub_02034E2C();
    }
    _021D4140.updateLock = lock;
}
