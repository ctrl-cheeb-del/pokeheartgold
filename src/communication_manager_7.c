#include "communication_manager_internal.h"

void sub_02036AA0(void *ptr) {
    if (ptr != NULL) {
        _0210F900[1]++;
    } else {
        GF_AssertFail();
    }
}

void sub_02036ABC(void *ptr) {
    if (ptr != NULL) {
        _0210F900[0]++;
    } else {
        GF_AssertFail();
    }
}
