#include "overlay81_screen_setup_r6_private.h"

void ov81_022408B8(void *work, void *boxMon) {
    BufferBoxMonSpeciesName(PTR(work, 0x20), boxMon);
}

void ov81_022408C4(void *save, void *window, int x, int y, u8 font) {
    void *profile = Save_PlayerData_GetProfile(PTR(save, 0x1bc));
    void *string = String_New(8, 0x64);
    u32 color;
    FillWindowPixelBuffer(window, 0);
    CopyU16ArrayToString(string, PlayerProfile_GetNamePtr(profile));
    if (PlayerProfile_GetTrainerGender(profile) == 0) {
        color = 0x70800;
    } else {
        color = 0x30400;
    }
    AddTextPrinterParameterizedWithColor(window, font, string, x, y, 0xff, color, 0);
    String_Delete(string);
    ScheduleWindowCopyToVram(window);
}

void ov81_0224093C(void *unused, void *window, int x, int y, u8 font) {
    void *profile = sub_02034818(1 - sub_0203769C());
    void *string = String_New(8, 0x64);
    u32 color;
    FillWindowPixelBuffer(window, 0);
    PlayerName_FlatToString(profile, string);
    if (PlayerProfile_GetTrainerGender(profile) == 0) {
        color = 0x70800;
    } else {
        color = 0x30400;
    }
    AddTextPrinterParameterizedWithColor(window, font, string, x, y, 0xff, color, 0);
    String_Delete(string);
    ScheduleWindowCopyToVram(window);
}
