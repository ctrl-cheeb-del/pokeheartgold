#include "wireless_connection_actions_internal.h"

BOOL sub_020351AC(int index) {
    u8 *work;
    u16 value;

    work = _021D4134.work;
    value = *(u16 *)(work + 0xD44 + index * 2);
    if (value != 0) {
        u8 flag = ((Unk020351Entry *)(work + 0xC0))[index].flag;
        if (flag == 0) {
            return TRUE;
        }
        return flag;
    }
    return FALSE;
}

void sub_020351DC(int ordinal, void *profile) {
    int i;
    int current = 0;
    u8 *ptr = _021D4134.work;

    for (i = 0; i < 16; i++, ptr += 2) {
        if (*(u16 *)(ptr + 0xD44) != 0) {
            if (ordinal == current) {
                PlayerProfile_Copy(sub_02035798(i), profile);
                return;
            }
            current++;
        }
    }
}

BOOL sub_02035218(int index) {
    int state = sub_02033298();

    if (state == 2) {
        sub_02032E24();
        return FALSE;
    }
    if (sub_02033298() == 1) {
        int mode = sub_0203993C();
        u32 offset = index * 0xC0;
        _021D4134.work[0xD90] = *(u16 *)(_021D4134.work + offset + 0x14A);
        if (sub_0203401C(mode)) {
            sub_02032B84(1, _021D4134.work + 0x118 + offset, 0);
        } else {
            sub_0203373C(1, _021D4134.work + 0x114 + offset);
        }
        return TRUE;
    }
    return FALSE;
}

void sub_0203528C(void) {
    int i;
    int offset;

    sub_02034C94();
    for (i = 0, offset = 0; i < 16; i++, offset += 2) {
        if (*(u16 *)(_021D4134.work + offset + 0xD44) != 0) {
            if (*(u16 *)(_021D4134.work + offset + 0xD44) != 0) {
                --*(u16 *)(_021D4134.work + offset + 0xD44);
                if (*(u16 *)(_021D4134.work + offset + 0xD44) == 0) {
                    _021D4134.work[0xD74] = 1;
                }
            }
        }
    }
}

void sub_020352D8(void) {
    int mode = sub_0203993C();
    void *profile = sub_02035784();

    if (mode != 15) {
        u8 *packet = *(u8 **)(_021D4134.work + 0xD88);
        if ((int)LinkBattleRuleset_sizeof() > 0x20) {
            GF_AssertFail();
        }
        if (PlayerProfile_sizeof() != 0x20) {
            GF_AssertFail();
        }
        MI_CpuCopy8(profile, packet + 0x10, PlayerProfile_sizeof());
        MI_CpuCopy8(*(void **)(_021D4134.work + 0xD7C), packet + 0x30, LinkBattleRuleset_sizeof());
        *(u32 *)packet = PlayerProfile_GetTrainerID(profile);
        packet[4] = sub_0203993C();
        packet[5] = sub_02039954();
        MI_CpuCopy8(_021D4134.work + 0xD68, packet + 8, 8);
        packet += 0x54;
        *packet = sub_02033AB8();
    } else {
        u8 *packet = *(u8 **)(_021D4134.work + 0xD88);
        *(u32 *)packet = PlayerProfile_GetTrainerID(profile);
        packet[4] = sub_0203993C();
        packet[5] = sub_02039954();
        MI_CpuCopy8(_021D4134.work, packet + 8, 0x54);
    }
    DC_FlushRange(*(void **)(_021D4134.work + 0xD88), 0x5C);
    sub_02033240(*(void **)(_021D4134.work + 0xD88), 0x5C);
}
