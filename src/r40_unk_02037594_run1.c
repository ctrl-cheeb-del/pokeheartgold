#include "r40_unk_02037594_private.h"

void sub_02037594(void) {
    s32 result;

    if (_021D4140.work == NULL) {
        return;
    }
    switch (_021D4140.work[0x6AB]) {
    case 1:
        if (sub_02035FF0() == 1) {
            result = sub_020376E0(11, _021D4140.work + 0x6AC);
        } else {
            result = sub_02037108(11, _021D4140.work + 0x6AC, 1);
        }
        if (result != 0) {
            _021D4140.work[0x6AB] = 2;
        }
        break;
    case 3:
        if (sub_020376E0(12, _021D4140.work + 0x6AC) != 0) {
            sub_02035FA8(_021D4140.work[0x6AC]);
            _021D4140.work[0x6AB] = 0;
        }
        break;
    }
}
