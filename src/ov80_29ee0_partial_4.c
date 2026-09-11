#include "ov80_29ee0_partial_internal.h"

void ov80_0222A7CC(void *message, int field) {
    int player = sub_0203769C() ^ 1;
    BufferPlayersName(message, field, sub_02034818(player));
}

int ov80_0222A7EC(void *profile) {
    int gender = PlayerProfile_GetTrainerGender(profile);
    switch (PlayerProfile_GetVersion(profile)) {
    default:
    case 7:
    case 8:
        return gender == 0 ? 0 : 0x61;
    case 0:
        return gender == 0 ? 0xEE : 0xEF;
    case 12:
        return gender == 0 ? 0x127 : 0x128;
    }
}

void ov80_0222A840(void *save) {
    sub_02039F68(Save_WiFiHistory_Get(save));
}
