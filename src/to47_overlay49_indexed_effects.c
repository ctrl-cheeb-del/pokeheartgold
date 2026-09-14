#include "to47_overlay49_indexed_effects_private.h"

void ov49_0225EF98(void *p, u32 index, const void *config, u32 value) {
    if (p == NULL) {
        GF_AssertFail();
    }
    if (index >= 20) {
        GF_AssertFail();
    }
    ov49_0225F0D8((u8 *)p + 8 + index * 0x24, config, value);
}

void ov49_0225EFC4(void *p, u32 index, const void *config, u32 value) {
    if (p == NULL) {
        GF_AssertFail();
    }
    if (index >= 20) {
        GF_AssertFail();
    }
    ov49_0225F110((u8 *)p + 8 + index * 0x24, config, value);
}

void ov49_0225EFF0(void *p, u32 index, u8 value) {
    if (p == NULL) {
        GF_AssertFail();
    }
    if (index >= 20) {
        GF_AssertFail();
    }
    ov49_0225F10C((u8 *)p + 8 + index * 0x24, value);
}

void ov49_0225F018(void *p, u32 value) {
    int i;
    u8 *entry;
    u8 *test;
    if (ov49_0225F180((u8 *)p + 0x2D8) == TRUE) {
        ov49_0225F098((u8 *)p + 0x2D8, p, value, 0);
        return;
    }
    entry = (u8 *)p + 8;
    i = 0;
    test = entry;
    for (; i < 20; i++, entry += 0x24, test += 0x24) {
        if (ov49_0225F180(entry) == TRUE) {
            ov49_0225F098(test, p, value, i);
        }
    }
}
