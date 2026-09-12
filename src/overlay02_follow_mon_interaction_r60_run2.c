#include "overlay02_follow_mon_interaction_r60_private.h"
void FollowMon_PlaceholdersSet(void *fieldSystem, void *fmt) {
    void *mon = GetFirstAliveMonInParty_CrashIfNone(SaveArray_Party_Get(PTR(fieldSystem, 0xc)));
    void *boxMon = Mon_GetBoxMon(mon);
    BufferBoxMonNickname(fmt, 0, boxMon);
    BufferBoxMonSpeciesName(fmt, 1, boxMon);
    BufferPlayersName(fmt, 2, Save_PlayerData_GetProfile(PTR(fieldSystem, 0xc)));
    BufferLocationName(fmt, 3, MapHeader_GetMapSec(U32(PTR(fieldSystem, 0x20), 0)));
    BufferItemName(fmt, 4, GetMonData(mon, 6, NULL));
}

void ov02_02250504(void *fieldSystem) {
    void *mon = GetFirstAliveMonInParty_CrashIfNone(SaveArray_Party_Get(PTR(fieldSystem, 0xc)));
    int mood = FieldSystem_UnkSub108_GetMonMood(PTR(fieldSystem, 0x108));
    int value = mood;
    value += S8(PTR(fieldSystem, 0x120), 0x815);
    if (value > 127) {
        value = 127;
    } else if (value < -127) {
        value = -127;
    }
    FieldSystem_UnkSub108_SetMonMood(PTR(fieldSystem, 0x108), (s8)value);
    value = GetMonData(mon, 9, NULL);
    value += S8(PTR(fieldSystem, 0x120), 0x814);
    if (value > 255) {
        value = 255;
    } else if (value < 0) {
        value = 0;
    }
    SetMonData(mon, 9, &value);
}

int ov02_02250594(int kind, int value) {
    switch (kind) {
    case 1:
        if (value != 255) {
            break;
        }
        return TRUE;
    case 2:
        if (value < 200) {
            break;
        }
        if (value >= 255) {
            break;
        }
        return TRUE;
    case 3:
        if (value < 150) {
            break;
        }
        if (value >= 200) {
            break;
        }
        return TRUE;
    case 4:
        if (value < 90) {
            break;
        }
        if (value >= 150) {
            break;
        }
        return TRUE;
    case 5:
        if (value < 60) {
            break;
        }
        if (value >= 90) {
            break;
        }
        return TRUE;
    case 6:
        if (value < 30) {
            break;
        }
        if (value >= 60) {
            break;
        }
        return TRUE;
    case 7:
        if (value < 1) {
            break;
        }
        if (value >= 30) {
            break;
        }
        return TRUE;
    case 8:
        if (value != 0) {
            break;
        }
        return TRUE;
    case 9:
        if (value < 90) {
            break;
        }
        return TRUE;
    case 10:
        if (value >= 60) {
            break;
        }
        return TRUE;
    }
    return FALSE;
}

int ov02_02250628(int kind, int value) {
    switch (kind) {
    case 1:
        if (value != 127) {
            break;
        }
        return TRUE;
    case 2:
        if (value < 100) {
            break;
        }
        if (value >= 127) {
            break;
        }
        return TRUE;
    case 3:
        if (value < 50) {
            break;
        }
        if (value >= 100) {
            break;
        }
        return TRUE;
    case 4:
        if (value < 30) {
            break;
        }
        if (value >= 50) {
            break;
        }
        return TRUE;
    case 5:
        if (value <= -30) {
            break;
        }
        if (value >= 30) {
            break;
        }
        return TRUE;
    case 6:
        if (value <= -50) {
            break;
        }
        if (value > -30) {
            break;
        }
        return TRUE;
    case 7:
        if (value <= -127) {
            break;
        }
        if (value > -50) {
            break;
        }
        return TRUE;
    case 8:
        if (value != -127) {
            break;
        }
        return TRUE;
    case 9:
        if (value < 0) {
            break;
        }
        return TRUE;
    case 10:
        if (value > -1) {
            break;
        }
        return TRUE;
    }
    return FALSE;
}

int ov02_022506D4(u32 kind, u32 value) {
    if (kind <= 249) {
        if (kind == value) {
            return TRUE;
        }
    } else {
        switch (kind) {
        case 250:
            if (value > 19) {
                break;
            }
            return TRUE;
        case 251:
            if (value > 130) {
                break;
            }
            return TRUE;
        case 252:
            if (value < 140) {
                break;
            }
            if (value > 149) {
                break;
            }
            return TRUE;
        case 253:
            if (value < 160) {
                break;
            }
            return TRUE;
        case 254:
            if (value < 220) {
                break;
            }
            return TRUE;
        default:
            GF_AssertFail();
            return FALSE;
        }
    }
    return FALSE;
}
