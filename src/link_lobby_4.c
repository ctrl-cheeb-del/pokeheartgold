#include "link_lobby_internal.h"

void sub_02058608(void) {
    if (sub_02057C94() == 0) {
        u8 flag;
        _021D41C8->ready = 0;
        flag = 1;
        sub_020376E0(94, &flag);
        sub_020582F4(sub_020586EC, 0);
    }
    sub_0205857C();
}

void sub_02058640(int start, Party *party) {
    if (party) {
        _021D41C8->party = SaveArray_Party_Alloc((enum HeapID)11);
        Party_Copy(party, _021D41C8->party);
    }
    if (start) {
        sub_020582F4(sub_02058870, 3);
        return;
    }
    {
        u8 flag = 3;
        sub_020376E0(94, &flag);
        sub_020582F4(sub_02058608, 0);
    }
}

void sub_02058690(void) {
    sub_020582F4(sub_02058608, 0);
}

void sub_020586A0(void) {
    if (sub_02037958() == 0 && sub_02057F18(sub_0203769C()) == 0) {
        if (_021D41C8->timer) {
            _021D41C8->timer--;
            return;
        }
        sub_02057F58();
        sub_02059538(_021D41C8->fieldSystem, sub_02058640);
        sub_020582F4(sub_02058690, 0);
    }
}

void sub_020586EC(void) {
    if (_021D41C8->ready) {
        u8 flag;
        sub_020582F4(sub_020586A0, 5);
        flag = 0;
        sub_020376E0(94, &flag);
    }
    sub_0205857C();
}

void sub_02058720(int sender, int unused, u8 *data) {
    if (*data == sub_0203769C()) {
        _021D41C8->ready = 1;
    }
}

BOOL sub_02058740(void) {
    if (_021D41C8 && (_021D41C8->state == sub_020586EC || _021D41C8->state == sub_02058608)) {
        return TRUE;
    }
    return FALSE;
}

void sub_0205876C(void) {
    int battleType;
    u8 data[8];
    if (_021D41C8->timer) {
        _021D41C8->timer--;
        return;
    }
    battleType = 5;
    switch (sub_0203993C()) {
    case 4:
    case 5:
        battleType = 15;
        break;
    case 2:
    case 38:
        battleType = 7;
        break;
    }
    sub_02039980(data);
    if (_021D41C8->party == NULL) {
        sub_02051598(_021D41C8->fieldSystem, data, battleType);
    } else {
        sub_020515FC(_021D41C8->fieldSystem, _021D41C8->party, battleType);
        Heap_Free(_021D41C8->party);
        _021D41C8->party = NULL;
    }
    sub_02058098();
}

void sub_020587E8(void) {
    if (sub_02036010()) {
        if (_021D41C8->timer) {
            _021D41C8->timer--;
        }
        if (_021D41C8->timer == 90) {
            sub_02037AC0(4);
        }
        if (sub_02037B38(4)) {
            sub_020582F4(sub_0205876C, 0);
        }
    }
}

void sub_0205882C(void) {
    if (_021D41C8->timer) {
        _021D41C8->timer--;
        return;
    }
    sub_02035FD8();
    sub_020582F4(sub_020587E8, 120);
}

void sub_02058854(void) {
    if (sub_02037B38(3)) {
        sub_020582F4(sub_0205882C, 2);
    }
}

void sub_02058870(void) {
    if (_021D41C8->timer) {
        _021D41C8->timer--;
        return;
    }
    sub_02056EA0(0);
    sub_02037AC0(3);
    sub_020582F4(sub_02058854, 0);
}

void sub_020588A0(void) {
    sub_02037E38();
    sub_020582F4(sub_020588B4, 2);
}

void sub_020588B4(void) {
    if (sub_02035664()) {
        sub_020582F4(sub_0205836C, 10);
    }
}

void sub_020588CC(int index) {
    _021D41C8->received[index] = 1;
}

void *sub_020588DC(int index) {
    GF_ASSERT(index < 4);
    return _021D41C8->packets[index];
}

void sub_020588F8(void) {
    int id = sub_0203769C();
    if (sub_02037B38(95)) {
        sub_02036FD8(88, _021D41C8->packets[id], 0x66c);
        sub_020582F4(sub_02058930, 0);
    }
}

void sub_02058930(void) {
    int i;
    for (i = 0; i < sub_02037454(); i++) {
        if (_021D41C8->received[i] == 0) {
            return;
        }
    }
    sub_02037AC0(97);
    sub_020582F4(sub_020589D8, 0);
}

void sub_0205896C(void) {
    if (sub_02036010() == 0) {
        if (_021D41C8->timer) {
            _021D41C8->timer--;
        }
        if (_021D41C8->timer == 90) {
            sub_02037AC0(5);
        }
        if (sub_02037B38(5)) {
            sub_020582F4(sub_020589F4, 0);
        }
    }
}

void sub_020589B0(void) {
    if (_021D41C8->timer) {
        _021D41C8->timer--;
        return;
    }
    sub_02035FE4();
    sub_020582F4(sub_0205896C, 120);
}

void sub_020589D8(void) {
    if (sub_02037B38(97)) {
        sub_020582F4(sub_020589B0, 2);
    }
}

void sub_020589F4(void) {
    if (_021D41C8->timer) {
        _021D41C8->timer--;
        return;
    }
    sub_02037AC0(98);
    if (_021D41C8->host) {
        sub_020582F4(sub_0205838C, 30);
        return;
    }
    sub_020582F4(sub_020584BC, 30);
}

void sub_02058A38(void) {
    if (sub_02037B38(91)) {
        sub_020398D4(0, 0);
        sub_02056EA0(1);
        sub_020582F4(sub_02058A78, 5);
    }
}

void sub_02058A60(void) {
    sub_02056EA0(1);
    sub_020582F4(sub_02058A78, 5);
}

void sub_02058A78(void) {
    if (_021D41C8->timer) {
        _021D41C8->timer--;
        return;
    }
    sub_02037E9C();
    sub_020582F4(sub_02058098, 0);
}

BOOL sub_02058AA0(void) {
    if (_021D41C8 == NULL) {
        return FALSE;
    }
    if (_021D41C8->state == sub_02058870 || _021D41C8->state == sub_02058854 || _021D41C8->state == sub_0205882C || _021D41C8->state == sub_020587E8 || _021D41C8->state == sub_0205876C) {
        return TRUE;
    }
    return FALSE;
}
