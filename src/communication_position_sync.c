#include "communication_position_sync_private.h"

void sub_02057D74(void) {
    int count;
    const u16 *table;
    u8 i;

    sub_0203993C();
    count = sub_0203774C();
    table = count == 2 ? _0210FAB4 : _0210FABC;
    i = 0;
    while (i < count) {
        if (_021D41C4->raw[0xE6 + i] != 0) {
            int j;
            const u16 *pair;
            j = 0;
            if (j < count) {
                pair = table;
                do {
                    if (sub_02057B4C(i) == pair[0] && sub_02057B9C(i) == pair[1]) {
                        _021D41C4->raw[0xBC + i] = 1;
                        sub_02037184(0x5F, &i);
                    }
                    j++;
                    pair += 2;
                } while (j < count);
            }
        }
        i++;
    }
}

void sub_02057E08(void) {
    int slot = sub_0203769C();
    int value;

    if (sub_02057A34() > 8) {
        sub_02057F28(2);
        value = sub_0206234C(2, 0x24);
    } else {
        sub_02057F28(3);
        value = sub_0206234C(3, 0x24);
    }
    sub_0205DFD4(*(void **)(_021D41C4->raw + slot * 4 + 4), value);
    sub_02058024();
}

BOOL sub_02057E50(void) {
    int count;
    int offset;
    int i;

    sub_0203993C();
    count = sub_0203774C();
    for (i = 0; i < count; i++) {
        if (_021D41C4->raw[0x24 + i] == 0 || _021D41C4->raw[0xCC + i] == 1) {
            return FALSE;
        }
    }
    i = 0;
    if (i < count) {
        offset = i;
        do {
            u8 *base = _021D41C4->raw + 0x34;
            u8 *entry = base + offset;
            int facing = sub_02057EEC(*(s8 *)(entry + 4));

            *(u16 *)entry += GetDeltaXByFacingDirection(facing);
            *(u16 *)(entry + 2) += GetDeltaYByFacingDirection(facing);
            entry[5] = 2;
            _021D41C4->raw[0xCC + i] = 1;
            sub_02057C5C(i, 1);
            i++;
            offset += 8;
        } while (i < count);
    }
    return TRUE;
}
