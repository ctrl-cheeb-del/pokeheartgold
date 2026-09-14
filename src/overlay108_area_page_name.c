#include "overlay108_area_page_name_internal.h"

void ov108_021E7EB0(SafariAreaCustomizer *s) {
    u8 x;
    u8 *record;
    void *window = &s->windows[4];

    FillWindowPixelBuffer(window, 12);
    record = &s->entries[s->selected * 0x7A];
    ReadMsgDataIntoString(s->msgData, record[0] + 16, s->string);
    x = (0x60 - FontID_String_GetWidth(0, s->string, 0)) / 2;
    AddTextPrinterParameterizedWithColor(window, 0, s->string, x, 4, 0xFF, 0x00080B0C, 0);
    if (s->otherPage < 6) {
        ReadMsgDataIntoString(s->msgData, s->otherPage + 16 + s->index * 6, s->string);
        x = (0x60 - FontID_String_GetWidth(0, s->string, 0)) / 2;
        AddTextPrinterParameterizedWithColor(window, 0, s->string, x + 0x90, 4, 0xFF, 0x00080B0C, 0);
    }
    ScheduleWindowCopyToVram(window);
}

void ov108_021E7F7C(SafariAreaCustomizer *s) {
    int i;
    int base;
    u8 *entry;
    u32 tmp;

    if (s->mode == 0) {
        FillBgTilemapRect(s->bgConfig, 1, 0, 0, 21, 32, 3, 17);
        ScheduleBgTilemapBufferTransfer(s->bgConfig, 1);
        s->y = -192;
        s->flag0 = 1;
        s->otherPage = 0;
        ov108_021E78F4(s, 1, s->otherPage);
        ov108_021E78F4(s, 2, s->selected);
        ov108_021E77D4(s);
    } else {
        ov108_021E79A8(s, 1, 0xFF, 0);
        ov108_021E78C0(s, 1, 0, 0);
        i = 0;
        base = s->flagB * 6;
        entry = (u8 *)s;
        do {
            ManagedSprite_SetPositionXY(s->sprites[6 + base + i], 56 + 72 * (i % 3), -136 + 72 * (i / 3));
            ManagedSprite_SetPriority(s->sprites[6 + base + i], 2);
            ov108_021E84F8(s->sub, i + base, entry[0x1C]);
            i++;
            entry += 0x7A;
        } while (i < 6);
    }
    s->frame = 0;
    FillWindowPixelBuffer(&s->windows[4], 12);
    ScheduleWindowCopyToVram(&s->windows[4]);
    *(volatile u16 *)0x04001040 = 0xF0;
    *(volatile u16 *)0x04001044 = 0x10;
    tmp = (*(volatile u16 *)0x04001048 & ~0x3F) | 0xF;
    tmp |= 0x20;
    *(volatile u16 *)0x04001048 = tmp;
    tmp = (*(volatile u16 *)0x0400104A & ~0x3F) | 0x1F;
    tmp |= 0x20;
    *(volatile u16 *)0x0400104A = tmp;
    *(volatile u32 *)0x04001000 = (*(volatile u32 *)0x04001000 & 0xFFFF1FFF) | 0x2000;
}
