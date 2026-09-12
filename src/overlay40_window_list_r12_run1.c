#include "overlay40_window_list_r12_private.h"

void ov40_0222E7F0(void *windowData, void *owner) {
    void *fmt;
    void *template;
    void *str;
    u32 country = sub_02031620(OV40_PTR(owner, 0x88C));
    u32 city = sub_0203162C(OV40_PTR(owner, 0x88C));
    void *window = (u8 *)windowData + 0x18;

    if (country == 0 && city == 0) {
        str = NewString_ReadMsgData(OV40_PTR(owner, 0x48), 0x7D);
    } else {
        fmt = ov40_0222DAB0(0x6D);
        if (city != 0) {
            str = String_New(0xFF, 0x6D);
            template = NewString_ReadMsgData(OV40_PTR(owner, 0x48), 0x17);
            BufferCityName(fmt, 0, country, city);
            StringExpandPlaceholders(fmt, str, template);
        } else {
            str = String_New(0xFF, 0x6D);
            template = NewString_ReadMsgData(OV40_PTR(owner, 0x48), 0x16);
            BufferCountryName(fmt, 0, country);
            StringExpandPlaceholders(fmt, str, template);
        }
        String_Delete(template);
        MessageFormat_Delete(fmt);
    }

    AddTextPrinterParameterizedWithColor(window, 0, str, 0, 0x10, 0xFF, 0x000F0D00, NULL);
    ScheduleWindowCopyToVram(window);
    String_Delete(str);
}
