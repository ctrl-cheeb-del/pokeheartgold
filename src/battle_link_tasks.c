#include "battle_link_internal.h"

BOOL sub_020752D8(LinkWork *work) {
    if (sub_02037190() != 264) {
        return FALSE;
    }
    if (sub_02037B38(56) == 0) {
        return FALSE;
    }
    return sub_02036FD8(33, &work->buffer, 1000);
}
void sub_0207530C(int sender, int unused, void *data, LinkWork *work) {
    work->received++;
}
BOOL sub_0207531C(LinkWork *work, int index) {
    if (sub_02037190() != 264) {
        return FALSE;
    }
    work->buffer.trainer = work->setup->trainer[index];
    return TRUE;
}
BOOL sub_02075350(LinkWork *work, int index, int command) {
    if (sub_02037190() != 264) {
        return FALSE;
    }
    if (!sub_02037B38((u8)command)) {
        return FALSE;
    }
    if (index == 1) {
        return sub_02036FD8(29, &work->buffer, 52);
    }
    return sub_02036FD8(30, &work->buffer, 52);
}
void sub_02075398(int sender, int unused, void *data, LinkWork *work) {
    work->received++;
}
BOOL sub_020753A8(LinkWork *work, int index) {
    if (sub_02037190() != 264) {
        return FALSE;
    }
    Party_Copy(work->setup->party[index], (Party *)&work->buffer);
    return TRUE;
}
BOOL sub_020753D4(LinkWork *work, int index, int command) {
    if (sub_02037190() != 264) {
        return FALSE;
    }
    if (!sub_02037B38((u8)command)) {
        return FALSE;
    }
    if (index == 1) {
        return sub_02036FD8(31, &work->buffer, PartyCore_sizeof());
    }
    return sub_02036FD8(32, &work->buffer, PartyCore_sizeof());
}
void sub_02075424(int sender, int unused, void *data, LinkWork *work) {
    work->received++;
}
void sub_02075434(SysTask *task, void *ptr) {
    LinkTask *work = ptr;
    u8 *buffer = BattleSystem_GetSendBufferPtr(work->battle);
    u16 *read = ov12_0223A954(work->battle);
    u16 *write = ov12_0223A960(work->battle);
    u16 *end = ov12_0223A96C(work->battle);
    switch (work->state) {
    case 0: {
        int size;
        if (sub_02037190() != 264) {
            break;
        }
        if (*read == *write) {
            break;
        }
        if (*read == *end) {
            *read = 0;
            *end = 0;
        }
        size = (buffer[*read + 2] | (buffer[*read + 3] << 8)) + 4;
        if (sub_02037030(23, &buffer[*read], size) == TRUE) {
            *read += size;
        }
        break;
    }
    case 255:
    default:
        Heap_Free(work);
        SysTask_Destroy(task);
        break;
    }
}
void sub_020754C0(SysTask *task, void *ptr) {
    LinkTask *work = ptr;
    u8 *buffer = BattleSystem_GetRecvBufferPtr(work->battle);
    u16 *read = ov12_0223A978(work->battle);
    u16 *write = ov12_0223A984(work->battle);
    u16 *end = ov12_0223A990(work->battle);
    switch (work->state) {
    case 0:
        if (*read == *write) {
            break;
        }
        if (*read == *end) {
            *read = 0;
            *end = 0;
        }
        if (ov12_02264334(work->battle, &buffer[*read]) == TRUE) {
            *read += (buffer[*read + 2] | (buffer[*read + 3] << 8)) + 4;
        }
        break;
    case 255:
    default:
        Heap_Free(work);
        SysTask_Destroy(task);
        break;
    }
}
void sub_02075534(int sender, int unused, void *data, BattleSystem *battle) {
    ov12_0223BC14(battle, 255);
    ov12_0223BC20(battle, 255);
    ov12_0223BC2C(battle, 1);
}
void sub_02075554(PlayerProfile *profile, SavePalPad *friends, SavePalPad *out) {
    int i;
    CopyU16StringArray(out->name, PlayerProfile_GetNamePtr(profile));
    out->otid = PlayerProfile_GetTrainerID(profile);
    out->filler_14[0] = PlayerProfile_GetLanguage(profile);
    out->filler_14[1] = PlayerProfile_GetVersion(profile);
    out->filler_14[2] = PlayerProfile_GetTrainerGender(profile);
    for (i = 0; i < 16; i++) {
        out->unk_18[i] = friends[i].otid;
        out->unk_58[i] = friends[i].filler_14[1];
        out->unk_68[i] = friends[i].filler_14[0];
        out->filler_78[i] = friends[i].filler_14[2];
    }
}
void sub_020755B4(int sender, int unused, SavePalPad *data, LinkWork *work) {
    if (sender != sub_0203769C()) {
        SavePalPad_Merge(work->setup->palPad, data, 1, (enum HeapID)5);
    }
    work->received++;
}
u32 sub_020755E4(void) {
    return 0x88;
}
