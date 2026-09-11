#include "network_communication_state_internal.h"

int sub_02039FFC(int arg) {
    int result;
    LoadDwcOverlay();
    LoadOVY38();
    result = sub_02039FD8(arg);
    UnloadDwcOverlay();
    UnloadOVY38();
    return result;
}

void sub_0203A01C(void) {
    void *profile = sub_0202C08C();
    if (!DWC_CheckUserData(profile)) {
        DWC_CreateUserData(profile, 0x4144414A);
        DWC_ClearDirtyFlag(profile);
    }
}

int sub_0203A040(void) {
    u8 token[12];
    void *profile = sub_0202C08C();
    DWC_CreateExchangeToken(profile, token);
    return DWC_GetGsProfileId(profile, token);
}

BOOL sub_0203A05C(void) {
    void *profile;
    sub_0202C6F4();
    profile = sub_0202C08C();
    if (DWC_CheckHasProfile(profile) && DWC_CheckValidConsole(profile)) {
        return TRUE;
    }
    return FALSE;
}
