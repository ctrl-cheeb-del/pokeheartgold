#include "overlay40_window_list_middle_e9b8_private.h"

void ov40_0222E9B8(void *p, void *owner, void *msgData, void *cfg) {
    void *window = (u8 *)p + 0x18;
    int i;
    int count;

    WORD(p, 4) = WORD(cfg, 4);
    WORD(p, 0) = 0;
    WORD(p, 0xc) = 0;
    WORD(p, 0x10) = WORD(cfg, 0x24);
    PTR(p, 0x28) = cfg;
    if (msgData != NULL) {
        PTR(p, 0x34) = msgData;
    } else {
        PTR(p, 0x34) = PTR(owner, 0x48);
    }
    WORD(p, 0x14) = SWORD(p, 4) / SWORD(p, 0x10) + 1;
    SWORD(p, 0x40) = SWORD(p, 0x10) / 2;
    SWORD(p, 0x44) = SWORD(p, 0x10) / 2;
    count = SWORD(p, 4);
    if (count < SWORD(p, 0x10)) {
        SWORD(p, 0x10) = count;
        SWORD(p, 0x40) = count - 1;
        SWORD(p, 0x44) = SWORD(p, 0x10) - 1;
    }

    InitWindow(window);
    AddWindowParameterized(PTR(owner, 0x24), window, (u8)WORD(cfg, 0x20), (u8)WORD(cfg, 0x0c), (u8)WORD(cfg, 0x10), (u8)WORD(cfg, 0x14), (u8)WORD(cfg, 0x18), 14, (u16)WORD(cfg, 0x1c));
    FillWindowPixelBuffer(window, 0);

    if (PTR(cfg, 0) != NULL) {
        for (i = 0; i < SWORD(p, 0x10); i++) {
            void *str = NewString_ReadMsgData(PTR(p, 0x34), WORD(PTR(cfg, 0) + i * 0x10, 0));
            AddTextPrinterParameterizedWithColor(window, 0, str, 0, WORD(cfg, 8) * 16 * i, 0xff, 0x000f0d00, NULL);
            String_Delete(str);
        }
    } else {
        i = 0;
        if (SWORD(p, 0x10) > 0) {
            void *cursor = owner;
            int y = 4;
            do {
                void *name = String_New(0xff, 0x6d);
                void *number = String_New(0xff, 0x6d);
                void *template = NewString_ReadMsgData(PTR(owner, 0x48), 0x63);
                u32 width;

                String16_FormatInteger(number, i + 1, 2, 1, 1);
                CopyU16ArrayToString(name, PTR(cursor, 0x2608));
                ov40_02230DCC(owner, name);
                width = FontID_String_GetWidth(0, number, 0);
                AddTextPrinterParameterizedWithColor(window, 0, number, 16 - width, y, 0xff, 0x000f0d00, NULL);
                AddTextPrinterParameterizedWithColor(window, 0, template, 16, y, 0xff, 0x000f0d00, NULL);
                AddTextPrinterParameterizedWithColor(window, 0, name, 22, y, 0xff, 0x000f0d00, NULL);
                String_Delete(name);
                String_Delete(number);
                String_Delete(template);
                cursor = (u8 *)cursor + 4;
                y += 0x18;
                i++;
            } while (i < SWORD(p, 0x10));
        }
    }
    ScheduleWindowCopyToVram(window);
}
