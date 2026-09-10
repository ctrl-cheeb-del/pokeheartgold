#include "summary_screen_helpers_internal.h"

void sub_0208AD34(void *args, PlayerProfile *profile) {
    *(const u16 **)((u8 *)args + 8) = PlayerProfile_GetNamePtr(profile);
    *(u32 *)((u8 *)args + 0xC) = PlayerProfile_GetTrainerID(profile);
    *((u8 *)args + 0x10) = PlayerProfile_GetTrainerGender(profile);
}

int sub_0208AD54(void) {
    return 0x40;
}

int sub_0208AD58(void) {
    return 0x41;
}

int sub_0208AD5C(void) {
    return 0x3F;
}

int sub_0208AD60(void) {
    return 0x3E;
}

int Pokemon_GetStatusIconId(Pokemon *mon) {
    u32 status = GetMonData(mon, 160, 0);
    if (GetMonData(mon, 163, 0) == 0) {
        return 6;
    }
    if (status & 0x88) {
        return 4;
    }
    if (status & 7) {
        return 3;
    }
    if (status & 0x10) {
        return 5;
    }
    if (status & 0x20) {
        return 2;
    }
    if (status & 0x40) {
        return 1;
    }
    return 7;
}

void sub_0208ADB8(void *data, int state) {
    void *p = *(void **)((u8 *)data + 0x22C);
    void *mgr = *(void **)((u8 *)p + 0x30);
    if (mgr != 0) {
        MenuInputStateMgr_SetState(mgr, state);
    }
}

int sub_0208ADCC(void) {
    return TouchscreenHitbox_FindRectAtTouchNew(_021038D4);
}

int sub_0208ADDC(void) {
    int ret = TouchscreenHitbox_FindRectAtTouchNew(_021038D4);
    if (ret != -1) {
        return ret;
    }
    if (TouchscreenHitbox_TouchNewIsIn(_021038AC) == 1) {
        return 4;
    }
    return -1;
}

int sub_0208AE08(void) {
    int ret = TouchscreenHitbox_FindRectAtTouchNew(_021038D4);
    if (ret != -1) {
        return ret;
    }
    if (TouchscreenHitbox_TouchNewIsIn(_021038B0) == 1) {
        return 4;
    }
    if (TouchscreenHitbox_TouchNewIsIn(_021038AC) == 1) {
        return 5;
    }
    return -1;
}

int sub_0208AE48(void) {
    int ret = TouchscreenHitbox_FindRectAtTouchNew(_021038D4);
    if (ret != -1) {
        return ret;
    }
    if (TouchscreenHitbox_TouchNewIsIn(_021038B4) == 1) {
        return 4;
    }
    if (TouchscreenHitbox_TouchNewIsIn(_021038AC) == 1) {
        return 5;
    }
    return -1;
}

int sub_0208AE88(void) {
    if (TouchscreenHitbox_TouchNewIsIn(_021038B4) == 1) {
        return 0;
    }
    if (TouchscreenHitbox_TouchNewIsIn(_021038AC) == 1) {
        return 1;
    }
    return -1;
}

int sub_0208AEB4(void) {
    return TouchscreenHitbox_FindRectAtTouchNew(_021038B8);
}

int sub_0208AEC4(void) {
    return TouchscreenHitbox_FindRectAtTouchNew(_021039E8);
}
