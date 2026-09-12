#include "network_state_handshake_private.h"

void sub_02038B9C(int unused0, int unused1, const u8 *data) {
    u32 i;
    int matches = TRUE;
    const u8 *expected = _0210F904 + 1;

    for (i = 1; i < 6; i++) {
        if (*expected != data[i]) {
            matches = FALSE;
            break;
        }
        expected++;
    }

    if (matches) {
        int value = data[0];
        if (value == sub_0203769C()) {
            _021D4150->field4C = 1;
        }
        return;
    }

    {
        const u8 *expected2;
        int matches2;
        u32 i2;

        expected2 = _0210F914 + 1;
        matches2 = TRUE;
        i2 = matches2;

        for (; i2 < 6; i2++) {
            if (*expected2 != data[i2]) {
                matches2 = FALSE;
                break;
            }
            expected2++;
        }

        if (matches2) {
            u8 value = data[0];
            if (value == (u8)sub_0203769C()) {
                _021D4150->field4C = 2;
            }
        }
    }
}
