#include "communication_player_state_internal.h"

void sub_02034354(void *save, void *rules) {
    void *profile;
    int i;

    profile = Save_PlayerData_GetProfile(save);
    if (_021D4130 == NULL) {
        _021D4130 = Heap_Alloc(15, sizeof(Unk02034354));
        MI_CpuFill8(_021D4130, 0, sizeof(Unk02034354));
        for (i = 0; i < 8; i++) {
            _021D4130->profiles[i] = &_021D4130->entries[i].profile;
            sub_020346E8(i);
        }
        _021D4130->unk3A4 = 0;
        _021D4130->unk3A5 = 0;
        _021D4130->curIdx = 0;
        _021D4130->save = save;
        _021D4130->rules = rules;
        PlayerProfile_Copy(profile, _021D4130->profiles[0]);
    }
}

void sub_020343E4(void) {
    int i;

    if (_021D4130 != NULL) {
        for (i = 0; i < 8; i++) {
            _021D4130->profiles[i] = NULL;
        }
        if (_021D4130 != NULL) {
            Heap_Free(_021D4130);
        }
        _021D4130 = NULL;
    }
}

BOOL sub_02034420(void) {
    if (_021D4130 != NULL) {
        return TRUE;
    }
    return FALSE;
}

void sub_02034434(void) {
    int netId;
    void *friends;
    void *r7;
    void *wifi;
    void *profile;

    netId = sub_0203769C();
    friends = Save_FriendGroup_Get(_021D4130->save);
    r7 = sub_0202C6F4(_021D4130->save);
    wifi = Save_WiFiHistory_Get(_021D4130->save);
    profile = _021D4130->unk00;
    if (profile == NULL) {
        profile = Save_PlayerData_GetProfile(_021D4130->save);
    }
    PlayerProfile_Copy(profile, _021D4130->profiles[netId]);
    OS_GetMacAddress(_021D4130->entries[netId].mac);
    MI_CpuCopy8(sub_0202C7E0(friends, 1, 0), _021D4130->entries[netId].unk4C, 0x10);
    _021D4130->entries[netId].country = WifiHistory_GetPlayerCountry(wifi);
    _021D4130->entries[netId].region = WiFiHistory_GetPlayerRegion(wifi);
    _021D4130->entries[netId].unk65 = 0;
    DWC_CreateExchangeToken(sub_0202C08C(r7), _021D4130->entries[netId].token);
    MI_CpuFill8(&_021D4130->entries[netId], 0, 0x20);
    if (_021D4130->rules != NULL) {
        LinkBattleRuleset_Copy(_021D4130->rules, &_021D4130->entries[netId]);
    }
    sub_02037030(3, &_021D4130->entries[netId], sizeof(Unk02034354_Entry));
}

int sub_02034520(void) {
    return sizeof(Unk02034354_Entry);
}

void sub_02034524(void) {
    if (_021D4130 != NULL) {
        _021D4130->unk3A4 = 1;
    }
}

void sub_0203453C(int netId, int unused, void *packet) {
#pragma unused(unused)
    Unk02034354_Entry *pkt = packet;

    if (_021D4130 == NULL) {
        return;
    }
    if (!sub_020373B4((u16)netId)) {
        return;
    }
    MI_CpuCopy8(pkt, &_021D4130->entries[pkt->index], sizeof(Unk02034354_Entry));
    _021D4130->curIdx = pkt->index;
    if (PlayerProfile_IsNameEmpty(_021D4130->profiles[_021D4130->curIdx]) == TRUE) {
        return;
    }
    if (_021D4130->status[_021D4130->curIdx] >= 2) {
        return;
    }
    _021D4130->status[_021D4130->curIdx] = 1;
    if (_021D4130->curIdx != sub_0203769C()) {
        return;
    }
    _021D4130->status[_021D4130->curIdx] = 3;
}

void sub_020345D0(int netId, int unused, void *src) {
#pragma unused(unused)
    if (_021D4130 == NULL) {
        return;
    }
    MI_CpuCopy8(src, &_021D4130->entries[netId], sizeof(Unk02034354_Entry));
    sub_020357C4(_021D4130->entries[netId].mac, netId);
    _021D4130->status[netId] = 1;
    if (netId == sub_0203769C()) {
        _021D4130->status[netId] = 3;
        return;
    }
    _021D4130->unk3A5 = 1;
}

BOOL sub_02034638(void) {
    int i;

    if (_021D4130->unk3A5 == 0) {
        return FALSE;
    }
    if (sub_0203769C() != 0) {
        return FALSE;
    }
    if (sub_02037824(5) == 0) {
        for (i = 0; i < 8; i++) {
            if (_021D4130->status[i] != 0) {
                _021D4130->entries[i].index = i;
                MI_CpuCopy8(_021D4130->profiles[i], _021D4130->entries[i].profile, PlayerProfile_sizeof());
                sub_0203753C(4, &_021D4130->entries[i], sizeof(Unk02034354_Entry));
            }
        }
        sub_0203753C(5, NULL, 0);
        _021D4130->unk3A5 = 0;
        return TRUE;
    }
    return FALSE;
}

u8 sub_020346D4(void) {
    return _021D4130->unk3A5;
}

void sub_020346E8(int netId) {
    PlayerProfile_Init(_021D4130->profiles[netId]);
    _021D4130->status[netId] = 0;
}

BOOL sub_02034714(int netId) {
    if (_021D4130->status[netId] == 1) {
        return TRUE;
    }
    return FALSE;
}

BOOL sub_02034730(int netId) {
    return _021D4130->status[netId] == 2 || _021D4130->status[netId] == 1;
}

BOOL sub_02034750(int netId) {
    if (_021D4130->status[netId] == 2) {
        return TRUE;
    }
    return FALSE;
}

void sub_0203476C(int netId) {
    _021D4130->status[netId] = 2;
}

int sub_02034780(void) {
    int i;

    for (i = 0; i < 8; i++) {
        if (_021D4130->status[i] == 1) {
            return i;
        }
    }
    return 0xFF;
}

int sub_020347A0(void) {
    int count;
    int i;

    count = 0;
    for (i = 0; i < 8; i++) {
        switch (_021D4130->status[i]) {
        case 2:
        case 3:
            count++;
        }
    }
    return count;
}

BOOL sub_020347CC(void) {
    int i;
    BOOL ret;

    ret = FALSE;
    if (_021D4130 != NULL) {
        if (sub_02037454() == 0) {
            return ret;
        }
        for (i = 0; i < 8; i++) {
            if (!sub_020373B4((u16)i) && _021D4130->status[i] != 0) {
                sub_020346E8(i);
                ret = TRUE;
            }
        }
    }
    return ret;
}

void *sub_02034818(int netId) {
    if (_021D4130 == NULL) {
        return NULL;
    }
    switch (_021D4130->status[netId]) {
    case 1:
    case 2:
    case 3:
        return _021D4130->profiles[netId];
    }
    return NULL;
}

void *sub_0203484C(int netId) {
    if (_021D4130->status[netId] != 0) {
        return _021D4130->entries[netId].token;
    }
    return NULL;
}

u8 sub_02034870(int a) {
    return sub_0203A378(_021D4130->save, a);
}

void *sub_02034884(int netId) {
    if (_021D4130->status[netId] != 0) {
        return _021D4130->entries[netId].unk4C;
    }
    return NULL;
}

u8 sub_020348A8(int netId) {
    if (_021D4130->status[netId] != 0) {
        return _021D4130->entries[netId].country;
    }
    return 0;
}

u8 sub_020348CC(int netId) {
    if (_021D4130->status[netId] != 0) {
        return _021D4130->entries[netId].region;
    }
    return 0;
}

BOOL sub_020348F0(void) {
    int i;
    int j;

    for (i = 0; i < 7; i++) {
        if (!sub_020373B4((u16)i)) {
            continue;
        }
        if (_021D4130->status[i] == 0) {
            continue;
        }
        if (!sub_020373B4((u16)(i + 1))) {
            continue;
        }
        if (_021D4130->status[i + 1] == 0) {
            continue;
        }
        for (j = 0; j < 0x20; j++) {
            if (_021D4130->entries[i].rules[j] != _021D4130->entries[i + 1].rules[j]) {
                return FALSE;
            }
        }
    }
    return TRUE;
}

void sub_02034960(int mode, int delta) {
    int i;
    int parity;

    if (_021D4130 == NULL) {
        return;
    }
    if (mode != 2) {
        parity = sub_020378AC(sub_0203769C()) & 1;
    }
    for (i = 0; i < sub_02037454(); i++) {
        if (!sub_020373B4((u16)i)) {
            continue;
        }
        if (_021D4130->status[i] == 0) {
            continue;
        }
        if (mode == 0) {
            if (parity == (sub_020378AC(i) & 1)) {
                continue;
            }
            _021D4130->scores[i].a += delta;
        } else if (mode == 1) {
            if (parity == (sub_020378AC(i) & 1)) {
                continue;
            }
            _021D4130->scores[i].b += delta;
        } else {
            _021D4130->scores[i].c += delta;
        }
    }
}

void sub_02034A20(void *save) {
    void *r;
    int val;
    int i;
    void *tok;

    r = sub_0202C6F4(save);
    for (i = 0; i < sub_02037454(); i++) {
        tok = sub_0203484C(i);
        if (tok != NULL) {
            int res = sub_0203A084(save, tok, &val);
            switch (res) {
            case 0:
            case 1:
                if (val < 0) {
                    GF_AssertFail();
                }
                sub_0202C4F0(r, val, _021D4130->scores[i].a, _021D4130->scores[i].b, _021D4130->scores[i].c);
            }
        }
    }
    for (i = 0; i < 8; i++) {
        _021D4130->scores[i].a = 0;
        _021D4130->scores[i].b = 0;
        _021D4130->scores[i].c = 0;
    }
}

void sub_02034AC0(void *save, int b) {
    if (b == 1) {
        sub_02034960(0, 1);
    } else if (b == -1) {
        sub_02034960(1, 1);
    }
    sub_02034A20(save);
}

void sub_02034AEC(void *save, int b) {
    sub_02034960(2, b);
    sub_02034A20(save);
}

void sub_02034B00(void *a) {
    _021D4130->unk00 = a;
}
