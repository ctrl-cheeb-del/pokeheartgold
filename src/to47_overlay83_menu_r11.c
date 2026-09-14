#include "to47_overlay83_menu_r11_private.h"

void ov83_02240528(void *p, int a)
{
    void *profile;
    void *str;
    u32 color;
    int width;

    FillWindowPixelBuffer((u8 *)p + 0x3F0, 0);
    FillWindowPixelBuffer((u8 *)p + 0x400, 0);
    FillWindowPixelBuffer((u8 *)p + 0x410, 0);
    if (a == 6) {
        ov83_022479E4((u8 *)p + 0x3F0, PTR_AT(p, 0x20), 0x6A, 0, 0, 0, 0x10200, 0);
    } else {
        ov83_022479E4((u8 *)p + 0x3F0, PTR_AT(p, 0x20), 0x6B, 0, 0, 0, 0x10200, 0);
    }
    profile = Save_PlayerData_GetProfile(PTR_AT(p, 0x50C));
    str = String_New(8, 0x6B);
    CopyU16ArrayToString(str, PlayerProfile_GetNamePtr(profile));
    if (PlayerProfile_GetTrainerGender(profile) == 0) {
        color = 0x70800;
    } else {
        color = 0x30400;
    }
    ov83_02247998((u8 *)p + 0x400, str, 0, 0, 0, color, 0);
    String_Delete(str);
    ov83_02240C48(p, 0, FrontierSave_GetStat(PTR_AT(p, 4), sub_0205C1F0(U8_AT(p, 9)), sub_0205C268(sub_0205C1F0(U8_AT(p, 9)))), 4, 1);
    width = GetWindowWidth((u8 *)p + 0x410) * 8;
    ov83_02241DD8(p, (u8 *)p + 0x410, PTR_AT(p, 0x20), 2, width, 0, 0, 0x10200, 1);
    ScheduleWindowCopyToVram((u8 *)p + 0x3F0);
    ScheduleWindowCopyToVram((u8 *)p + 0x400);
    ScheduleWindowCopyToVram((u8 *)p + 0x410);
}

void ov83_02240664(void *p)
{
    u16 index;
    u16 i;
    int width;

    index = (u16)(S16_AT(p, 0x862) * 6);
    for (i = 0; i < 6; i++) {
        FillWindowPixelBuffer((u8 *)p + 0x50 + (i + 0x30) * 16, 0);
        if ((int)(index + i) < U8_AT(p, 0x861)) {
            AddTextPrinterParameterizedWithColor((u8 *)p + 0x50 + (i + 0x30) * 16, 0, (void *)U32_AT(ELEM(index * 8, PTR_AT(p, 0x4DC)), i * 8), 4, 4, 0xFF, 0x10200, 0);
            ov83_02240C48(p, 0, ov83_02240EC4(p, (u16)U32_AT(ELEM(i * 8, ELEM(index * 8, PTR_AT(p, 0x4DC))), 4), U8_AT(p, 0x13)), 2, 0);
            width = GetWindowWidth((u8 *)p + 0x50 + (i + 0x30) * 16) * 8 - 4;
            ov83_02241DD8(p, (u8 *)p + 0x50 + (i + 0x30) * 16, PTR_AT(p, 0x20), 0x68, width, 0x14, 0, 0x10200, 1);
        }
        ScheduleWindowCopyToVram((u8 *)p + 0x50 + (i + 0x30) * 16);
    }
}
