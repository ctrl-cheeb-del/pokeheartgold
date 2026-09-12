#include "friend_roster_update_internal.h"

int sub_0203A084(void *saveData, void *friendData, int *indexOut) {
    int i;
    void *account = sub_0202C08C(sub_0202C6F4(saveData));
    void *entry = sub_0202C23C(sub_0202C6F4(saveData), 0);
    *indexOut = -1;
    if (!DWC_IsValidFriendData(friendData)) {
        return 3;
    }
    for (i = 0; i < 32; i++, entry = (u8 *)entry + 12) {
        if (DWC_IsEqualFriendData(friendData, entry)) {
            *indexOut = i;
            return 0;
        }
        if (DWC_GetGsProfileId(account, friendData) > 0 && DWC_GetGsProfileId(account, friendData) == DWC_GetGsProfileId(account, entry)) {
            *indexOut = i;
            return 1;
        }
        if (*indexOut < 0 && !DWC_IsValidFriendData(entry)) {
            *indexOut = i;
        }
    }
    return 2;
}

int sub_0203A128(void *saveData, u64 key, int *indexOut) {
    FriendToken token;
    int i;
    void *account = sub_0202C08C(sub_0202C6F4(saveData));
    void *entry = sub_0202C23C(sub_0202C6F4(saveData), 0);
    if (!DWC_CheckFriendKey(account, key)) {
        return 3;
    }
    DWC_CreateFriendKeyToken(&token, key);
    if (DWC_GetGsProfileId(account, &token) <= 0) {
        return 3;
    }
    *indexOut = -1;
    for (i = 0; i < 32; i++, entry = (u8 *)entry + 12) {
        if (DWC_GetGsProfileId(account, &token) == DWC_GetGsProfileId(account, entry)) {
            *indexOut = i;
            return 0;
        }
        if (*indexOut < 0 && !DWC_IsValidFriendData(entry)) {
            *indexOut = i;
        }
    }
    return 2;
}

BOOL sub_0203A1C4(void *saveData, int *results, int heapId) {
    BOOL needsUpdate = FALSE;
    void *roster = sub_0202C6F4(saveData);
    void *friends = sub_0202C23C(roster, 0);
    int i = 0;

    if (sub_02037454() > 0) {
        do {
            if (i != sub_0203769C()) {
                void *friendData = sub_0203484C(i);
                if (friendData != NULL) {
                    int index;
                    *results = sub_0203A084(saveData, friendData, &index);
                    if (*results == 3) {
                        GF_AssertFail();
                    }
                    if (*results == 0) {
                        sub_0203A280(saveData, i, index, heapId, 2);
                        sub_02034A20(saveData);
                    } else if (*results == 1) {
                        if (sub_02039998() == 0) {
                            sub_0203A280(saveData, i, index, heapId, 1);
                            MI_CpuCopy8(friendData, (u8 *)friends + index * 12, 12);
                            sub_02034A20(saveData);
                        }
                    } else if (*results == 2) {
                        needsUpdate = TRUE;
                    }
                }
            }
            results++;
            i++;
        } while (i < sub_02037454());
    }
    return needsUpdate;
}

void sub_0203A280(void *saveData, int netId, int index, int heapId, int type) {
    struct {
        void *friendData;
        String *profileName;
        String *networkName;
    } local;
    void *roster = sub_0202C6F4(saveData);
    local.friendData = sub_0202C23C(roster, index);
    void *profile = sub_02034818(netId);

    if (type != 2) {
        MI_CpuCopy8(sub_0203484C(netId), local.friendData, 12);
    }
    if (type == 0) {
        local.profileName = PlayerProfile_GetPlayerName_NewString(profile, heapId);
        sub_0202C270(roster, index, local.profileName);
        String_Delete(local.profileName);
        sub_0202C190(roster, index, 8, PlayerProfile_GetTrainerGender(profile));
        sub_0202C190(roster, index, 0, PlayerProfile_GetTrainerID(profile));
    } else if ((u32)(type - 1) <= 1) {
        if (sub_0202C090(roster, index, 8) == 2) {
            sub_0202C190(roster, index, 8, PlayerProfile_GetTrainerGender(profile));
            sub_0202C190(roster, index, 0, PlayerProfile_GetTrainerID(profile));
        }
    }
    local.networkName = String_New(0x78, heapId);
    CopyU16ArrayToString(local.networkName, sub_02034884(netId));
    sub_0202C2B4(roster, index, local.networkName);
    String_Delete(local.networkName);
    sub_0202C190(roster, index, 7, PlayerProfile_GetAvatar(profile));
    sub_02034A20(saveData);
}
