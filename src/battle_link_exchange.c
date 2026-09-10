#include "battle_link_internal.h"

void sub_02075028(int sender, int size, u8 *data, BattleSystem *battle) {
    int i;
    u8 *buffer = BattleSystem_GetRecvBufferPtr(battle);
    u16 *write = ov12_0223A984(battle);
    u16 *end = ov12_0223A990(battle);
    if (*write + size + 1 > 4096) {
        *end = *write;
        *write = 0;
    }
    for (i = 0; i < size; i++) {
        buffer[*write] = data[i];
        (*write)++;
    }
}
BOOL sub_02075074(LinkWork *work, u32 value, ...) {
    if (sub_02037190() != 264) {
        return FALSE;
    }
    if (sub_02037B38(51) == 0) {
        return FALSE;
    }
    return sub_02037030(24, &value, 4);
}
void sub_020750B4(int sender, int unused, u32 *data, LinkWork *work) {
    work->setup->aiFlags[sender] = *data;
    sub_0203049C(sender, work->setup->aiFlags[sender]);
    work->received++;
}
BOOL sub_020750E0(LinkWork *work) {
    if (sub_02037190() != 264) {
        return FALSE;
    }
    PlayerProfile_Copy(work->setup->profile[0], (PlayerProfile *)&work->buffer);
    return TRUE;
}
BOOL sub_02075108(LinkWork *work) {
    if (sub_02037190() != 264) {
        return FALSE;
    }
    if (sub_02037B38(52) == 0) {
        return FALSE;
    }
    return sub_02036FD8(25, &work->buffer, PlayerProfile_sizeof());
}
void sub_0207513C(int sender, int unused, void *data, LinkWork *work) {
    work->received++;
}
BOOL sub_0207514C(LinkWork *work) {
    if (sub_02037190() != 264) {
        return FALSE;
    }
    work->buffer.trainer = work->setup->trainer[0];
    return TRUE;
}
BOOL sub_02075178(LinkWork *work) {
    if (sub_02037190() != 264) {
        return FALSE;
    }
    if (sub_02037B38(53) == 0) {
        return FALSE;
    }
    return sub_02036FD8(26, &work->buffer, 52);
}
void sub_020751A8(int sender, int unused, void *data, LinkWork *work) {
    work->received++;
}
BOOL sub_020751B8(LinkWork *work) {
    if (sub_02037190() != 264) {
        return FALSE;
    }
    Party_Copy(work->setup->party[0], (Party *)&work->buffer);
    return TRUE;
}
BOOL sub_020751DC(LinkWork *work) {
    if (sub_02037190() != 264) {
        return FALSE;
    }
    if (sub_02037B38(54) == 0) {
        return FALSE;
    }
    return sub_02036FD8(27, &work->buffer, PartyCore_sizeof());
}
void sub_02075210(int sender, int unused, void *data, LinkWork *work) {
    work->received++;
}
BOOL sub_02075220(LinkWork *work) {
    if (sub_02037190() != 264) {
        return FALSE;
    }
    Chatot_Copy(&work->buffer.chatot, work->setup->chatot[0]);
    return TRUE;
}
BOOL sub_02075248(LinkWork *work) {
    if (sub_02037190() != 264) {
        return FALSE;
    }
    if (sub_02037B38(55) == 0) {
        return FALSE;
    }
    return sub_02036FD8(28, &work->buffer, 1000);
}
