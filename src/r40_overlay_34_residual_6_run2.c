#include "r40_overlay_34_residual_6_private.h"

void *ov34_0225E2BC(void *palPad, u32 trainerId, void *format, void *msgData, void *profile) {
    int status = 0;
    void *result = NULL;

    if (trainerId != PlayerProfile_GetTrainerID(profile)) {
        status = PalPad_PlayerIdIsFriendOrMutual(palPad, trainerId);
    }
    if (status > 0) {
        if (status == 1) {
            BufferPlayersName(format, 0, profile);
        } else if (status >= 2) {
            int index = status - 2;
            void *string = String_New(10, 0x57);
            CopyU16ArrayToString(string, PalPad_GetNthEntry(palPad, index));
            BufferString(format, 0, string, 0, 0, PalPadEntry_GetFromUnk68Array(palPad, index));
            String_Delete(string);
        }
        result = ReadMsgData_ExpandPlaceholders(format, msgData, 0xD0, 0x57);
    }
    return result;
}
