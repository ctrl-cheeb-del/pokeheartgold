#include "ov80_2237a70_partial_internal.h"

int ov80_02237B24(int mode, int flag) {
    switch (mode) {
    case 0:
    case 1:
        return 3;
    case 2:
    case 3:
        if (flag == 0) {
            return 2;
        }
        return 4;
    default:
        GF_AssertFail();
        return 3;
    }
}

int ov80_02237B58(int mode, int flag) {
    switch (mode) {
    case 0:
    case 1:
        return 3;
    case 2:
    case 3:
        if (flag == 0) {
            return 2;
        }
        return 4;
    default:
        GF_AssertFail();
        return 3;
    }
}
