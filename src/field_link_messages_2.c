#include "field_link_messages_internal.h"

int sub_0205A6AC(struct MessageFormat *msgFmt) {
    u8 myCountry = sub_020348A8(sub_0203769C());
    u8 theirCountry = sub_020348A8(sub_0203769C() ^ 1);
    u8 myCity = sub_020348CC(sub_0203769C());
    u8 theirCity = sub_020348CC(sub_0203769C() ^ 1);

    if (theirCountry == 0) {
        return 15;
    }
    if (theirCountry != 0) {
        BufferCountryName(msgFmt, 3, theirCountry);
        if (theirCity != 0) {
            BufferCityName(msgFmt, 4, theirCountry, theirCity);
        }
    }
    if (myCountry != theirCountry) {
        if (theirCity == 0) {
            return 13;
        }
        if (myCity == theirCity) {
            return 13;
        }
        return 12;
    }
    if (myCity != theirCity) {
        return 14;
    }
    return 15;
}

int sub_0205A730(int a0, int a1, struct MessageFormat *msgFmt) {
    if (a0 != 0) {
        return _020FC99C[a0][a1];
    }
    return sub_0205A6AC(msgFmt);
}

int sub_0205A750(struct UnkStruct_02059E1C *p, int objId, int a2, struct MessageFormat *msgFmt) {
    PlayerProfile *profile;
    int gender;

    if (a2 == 0) {
        return sub_0205A544(p, objId - 1);
    }
    profile = sub_02035798(objId - 1);
    if (profile == NULL) {
        sub_020398D4(1, 1);
        sub_02039AD8(1);
        return 0;
    }
    gender = PlayerProfile_GetTrainerGender(profile);
    switch (a2) {
    case 1:
        return sub_0205A730(p->unk34 - 1, gender, msgFmt);
    case 2:
        return _020FC7D4[gender];
    case 9:
        if (p->unk34 == 0) {
            return 0;
        }
        return _020FC95C[p->unk34][gender];
    case 19:
    case 20:
    case 21:
        a2 -= 19;
        return _020FC880[a2][gender];
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
        return _020FC934[a2 - 3][gender];
    case 10:
    case 11:
    case 12:
        a2 -= 10;
        return _020FC838[a2][gender];
    case 13:
    case 14:
    case 15:
        a2 -= 13;
        return _020FC850[a2][gender];
    case 16:
    case 17:
    case 18:
        a2 -= 16;
        return _020FC868[a2][gender];
    case 22:
        return _020FC7E4[gender];
    case 23:
        return _020FC7DC[gender];
    case 24:
        return _020FC7EC[gender];
    case 25:
        return 0xda;
    case 26:
        return _020FC7F4[gender];
    }
    GF_AssertFail();
    return 0x28;
}

u8 sub_0205A894(void) {
    PlayerProfile *profile = sub_02034818(sub_0203769C() ^ 1);
    GF_ASSERT(profile);
    return PlayerProfile_GetVersion(profile);
}

void sub_0205A8B4(struct UnkSub_0205AA4C *p) {
    PlayerProfile *profile;
    int netId;
    int i;
    for (netId = 1; netId < 5; netId++) {
        i = netId - 1;
        profile = sub_02034818(netId);
        if (profile != NULL) {
            if (sub_0203769C() == 0) {
                p->unk00[i] = PlayerProfile_GetTrainerID(profile);
                p->unk18[i] = PlayerProfile_GetAvatar(profile) | (PlayerProfile_GetTrainerGender(profile) << 7);
            }
        } else {
            p->unk00[i] = 0;
            p->unk18[i] = 0;
        }
    }
}
