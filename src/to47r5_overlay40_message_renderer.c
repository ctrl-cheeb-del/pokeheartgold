#include "to47r5_overlay40_message_renderer_private.h"



void ov40_0222E09C(void *windowData, void *owner) {
    Ov40WinCoordsTable coords = ov40_02244F40;
    Ov40MsgIdTable msgIds = ov40_02244F10;
    Ov40MailBuf mail;
    void *cityTemplate;
    void *countryTemplate;
    void *countryStr;
    u32 city;
    void *dateStr;
    void *monthTemplate;
    u32 month;
    void *nameTemplate;
    void *nameStr;
    int i;
    int baseTile;
    void *save;
    const u32 *idp;
    void *window2;
    void *window;
    const Ov40WinCoords *cp;
    void *fmt;
    void *str;
    u32 country;

    baseTile = 1;
    i = 0;
    window = (u8 *)windowData + 0x0C;
    idp = msgIds.ids;
    cp = coords.coords;
    for (; i < 8; i++) {
        str = NewString_ReadMsgData(OV40_PTR(owner, 0x48), *idp);
        InitWindow(window);
        AddWindowParameterized(OV40_PTR(owner, 0x24), window, 2, cp->x, cp->y, cp->width, cp->height, 0x0E, baseTile);
        FillWindowPixelBuffer(window, 0);
        AddTextPrinterParameterizedWithColor(window, 0, str, ov40_022306C0(window, str), 0, 0xFF, 0x000F0D00, NULL);
        ScheduleWindowCopyToVram(window);
        baseTile += cp->width * cp->height;
        String_Delete(str);
        window = (u8 *)window + 0x10;
        idp++;
        cp++;
    }

    save = OV40_PTR(windowData, 0);
    fmt = ov40_0222DAB0(0x6D);
    window = (u8 *)windowData + 0x0C;
    nameStr = sub_020315B8(save, 0x6D);
    ov40_02230DCC(owner, nameStr);
    nameTemplate = NewString_ReadMsgData(OV40_PTR(owner, 0x48), 13);
    str = String_New(0xFF, 0x6D);
    BufferString(fmt, 0, nameStr, 0, 1, 2);
    StringExpandPlaceholders(fmt, str, nameTemplate);
    FillWindowPixelBuffer(window, 0);
    AddTextPrinterParameterizedWithColor(window, 0, str, ov40_022306C0(window, str), 0, 0xFF, 0x000F0D00, NULL);
    ScheduleWindowCopyToVram(window);
    String_Delete(nameStr);
    String_Delete(nameTemplate);
    String_Delete(str);
    MessageFormat_ResetBuffers(fmt);

    month = sub_020316F0(save);
    window = (u8 *)windowData + 0x2C;
    monthTemplate = NewString_ReadMsgData(OV40_PTR(owner, 0x48), 15);
    dateStr = sub_020315B8(save, 0x6D);
    ov40_02230DCC(owner, dateStr);
    str = String_New(0xFF, 0x6D);
    BufferMonthNameAbbr(fmt, 0, month);
    StringExpandPlaceholders(fmt, str, monthTemplate);
    FillWindowPixelBuffer(window, 0);
    AddTextPrinterParameterizedWithColor(window, 0, str, ov40_022306C0(window, str), 0, 0xFF, 0x000F0D00, NULL);
    ScheduleWindowCopyToVram(window);
    String_Delete(monthTemplate);
    String_Delete(dateStr);
    String_Delete(str);
    MessageFormat_ResetBuffers(fmt);

    window = (u8 *)windowData + 0x3C;
    str = NewString_ReadMsgData(OV40_PTR(owner, 0x48), 16);
    FillWindowPixelBuffer(window, 0);
    AddTextPrinterParameterizedWithColor(window, 0, str, ov40_022306C0(window, str), 0, 0xFF, 0x000F0D00, NULL);
    ScheduleWindowCopyToVram(window);
    String_Delete(str);

    country = sub_02031620(save);
    city = sub_0203162C(save);
    window = (u8 *)windowData + 0x4C;
    FillWindowPixelBuffer(window, 0);
    if (country == 0) {
        str = NewString_ReadMsgData(OV40_PTR(owner, 0x48), 21);
        AddTextPrinterParameterizedWithColor(window, 0, str, 0, 0, 0xFF, 0x000F0D00, NULL);
        ScheduleWindowCopyToVram(window);
        String_Delete(str);
    } else {
        countryStr = String_New(0xFF, 0x6D);
        countryTemplate = NewString_ReadMsgData(OV40_PTR(owner, 0x48), 22);
        BufferCountryName(fmt, 0, country);
        StringExpandPlaceholders(fmt, countryStr, countryTemplate);
        AddTextPrinterParameterizedWithColor(window, 0, countryStr, 0, 0, 0xFF, 0x000F0D00, NULL);
        ScheduleWindowCopyToVram(window);
        String_Delete(countryStr);
        String_Delete(countryTemplate);
        if (city != 0) {
            window2 = (u8 *)windowData + 0x5C;
            FillWindowPixelBuffer(window2, 0);
            str = String_New(0xFF, 0x6D);
            cityTemplate = NewString_ReadMsgData(OV40_PTR(owner, 0x48), 23);
            BufferCityName(fmt, 0, country, city);
            StringExpandPlaceholders(fmt, str, cityTemplate);
            AddTextPrinterParameterizedWithColor(window2, 0, str, 4, 0, 0xFF, 0x000F0D00, NULL);
            ScheduleWindowCopyToVram(window2);
            String_Delete(str);
            String_Delete(cityTemplate);
        }
    }

    MessageFormat_ResetBuffers(fmt);
    window = (u8 *)windowData + 0x6C;
    str = NewString_ReadMsgData(OV40_PTR(owner, 0x48), 17);
    FillWindowPixelBuffer(window, 0);
    AddTextPrinterParameterizedWithColor(window, 0, str, ov40_022306C0(window, str), 0, 0xFF, 0x000F0D00, NULL);
    ScheduleWindowCopyToVram(window);
    String_Delete(str);

    window = (u8 *)windowData + 0x7C;
    str = sub_0203164C(save, &mail, 0x6D);
    if (str == NULL) {
        str = MailMsg_GetExpandedString(&mail, 0x6D);
    }
    FillWindowPixelBuffer(window, 0);
    AddTextPrinterParameterizedWithColor(window, 0, str, 0, 0, 0xFF, 0x000F0D00, NULL);
    ScheduleWindowCopyToVram(window);
    String_Delete(str);
    MessageFormat_Delete(fmt);
}
