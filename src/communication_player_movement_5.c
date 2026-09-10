#include "communication_player_movement_internal.h"

void sub_020572AC(void *fieldSystem) {
    int mode = 2;
    if (gSystem.heldKeys & 2) {
        mode = 1;
    } else if (fieldSystem != NULL && PlayerAvatar_CheckRunningShoesLock(FieldSystem_GetPlayerAvatar(fieldSystem))) {
        mode = 1;
    }
    sub_02037498(mode);
}

void sub_020572DC(int unused, void *fieldSystem) {
    if (sub_02037474()) {
        sub_020572AC(fieldSystem);
        if (sub_0203769C() == 0) {
            sub_0205712C(fieldSystem);
            sub_020570C8(fieldSystem);
        } else {
            sub_020570C8(fieldSystem);
        }
        sub_02057314(fieldSystem);
    }
}

void sub_02057314(void *unused) {
    int i;
    u8 slot;
    for (i = 0; i < 8; i++) {
        if (sub_020373B4((u16)i)) {
            sub_02057818(i);
        } else if (_021D41C4->raw[0x24 + i] != 0) {
            slot = i;
            sub_0205776C(0, 1, &slot, *(void **)&_021D41C4->raw[0x30]);
        }
    }
}

void sub_02057358(int value) {
    if (_021D41C4 != NULL) {
        if (_021D41C4->raw[0xED] != value) {
            _021D41C4->raw[0xED] = value;
        }
        sub_020376E0(0x3E, &_021D41C4->raw[0xED]);
    }
}

void sub_02057384(int value) {
    if (_021D41C4 != NULL && _021D41C4->raw[0xED] != value) {
        _021D41C4->raw[0xED] = value;
        sub_020376E0(0x3E, &_021D41C4->raw[0xED]);
    }
}

void sub_020573AC(int slot, int size, const u8 *data) {
    int valid;
    if (_021D41C4 == NULL) {
        return;
    }
    if (size != 1) {
        GF_AssertFail();
    }
    if (slot >= 8) {
        GF_AssertFail();
    }
    valid = 1;
    if (*data != 1 && *data != 0) {
        valid = 0;
    }
    if (!valid) {
        GF_AssertFail();
    }
    sub_02057C5C(slot, *data);
}

void sub_020573F0(void *fieldSystem, int value) {
    void *avatar;
    if (_021D41C4 == NULL) {
        return;
    }
    sub_02057384(value);
    _021D41C4->raw[0xF1] = value;
    avatar = *(void **)((u8 *)fieldSystem + 0x40);
    if (avatar != NULL) {
        ((CommPlayerManagerLayout *)_021D41C4)->avatars[sub_0203769C()] = avatar;
    }
    if (sub_02037474() && sub_0203769C() == 0) {
        sub_02057550(0, _021D41C4);
    }
    if (sub_02037474() && sub_0203769C() == 0) {
        sub_02057D74();
    }
}

int sub_02057454(int unused, int keys) {
    if (keys & 0x20) {
        return 2;
    }
    if (keys & 0x10) {
        return 3;
    }
    if (keys & 0x40) {
        return 0;
    }
    if (keys & 0x80) {
        return 1;
    }
    return -1;
}
