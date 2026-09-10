#include "wireless_connection_state_internal.h"

void *sub_02035754(int index) {
    if (_021D4134.work != NULL) {
        if (*(u16 *)(_021D4134.work + 0xD44 + index * 2) != 0) {
            return _021D4134.work + 0x114 + index * 0xC0;
        }
    }
    return NULL;
}

void *sub_02035784(void) {
    return *(void **)(_021D4134.work + 0xD78);
}

void *sub_02035798(int index) {
    u8 *result;
    if (*(u16 *)(_021D4134.work + 0xD44 + index * 2) == 0) {
        return NULL;
    }
    result = _021D4134.work + 0x164 + index * 0xC0;
    return result + 0x10;
}

void sub_020357C4(void *dst, int index) {
    if (_021D4134.work != NULL) {
        if (index >= 8) {
            GF_AssertFail();
        }
        MI_CpuCopy8(dst, _021D4134.work + 0xD14 + index * 6, 6);
    }
}

BOOL sub_020357FC(void) {
    if (_021D4134.work != NULL) {
        return ((u32)_021D4134.work[0xD95] << 27) >> 31;
    }
    return 0;
}

void sub_0203581C(void) {
    if (_021D4134.work != NULL) {
        _021D4134.work[0xD95] |= 0x10;
    }
}

void sub_02035838(void *dst) {
    MI_CpuCopy8(dst, _021D4134.work + 0xD68, 8);
}

void sub_02035854(void *dst) {
    MI_CpuCopy8(dst, *(void **)(_021D4134.work + 0xD7C), LinkBattleRuleset_sizeof());
}

void *sub_02035878(void) {
    return *(void **)(_021D4134.work + 0xD7C);
}

void sub_0203588C(void) {
    sub_020352D8();
    sub_020339B4(*(void **)(_021D4134.work + 0xD88), 0x5C, *(void **)(_021D4134.work + 0xD80), _021D4134.localId);
}

void sub_020358B0(void) {
    sub_02033A44();
}

void sub_020358B8(const void *src) {
    MI_CpuCopy8(src, _021D4134.work, 0x54);
    sub_0203588C();
}

void *sub_020358D0(int index) {
    if (_021D4134.work != NULL) {
        if (*(u16 *)(_021D4134.work + 0xD44 + index * 2) != 0) {
            u8 *result = _021D4134.work + 0x164 + index * 0xC0;
            return result + 8;
        }
    }
    return NULL;
}
