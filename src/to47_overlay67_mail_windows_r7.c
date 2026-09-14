#include "to47_overlay67_mail_windows_r7_private.h"

void ov67_021E6490(void *work) {
    u16 entry;
    void *windows;
    u16 i;

    if (U8(work, 0x4a2) == 0) {
        windows = PTR(work, 0x11c);
    } else {
        windows = PTR(work, 0x1dc);
    }
    entry = U16(work, 0x4a0) * 12;
    for (i = 0; i < 12; entry++, i++) {
        FillWindowPixelBuffer(PTR(windows, i * 16), 0);
        if (entry < 30) {
            u8 *record = PTR(work, entry * 16);
            u32 color;
            if (U8(record, 0x2a0) == 0) {
                color = 0x70800;
            } else {
                color = 0x30400;
            }
            ov67_021E6118(PTR(windows, i * 16), (void *)U32(record, 0x29c), 0, 0, 0, color, 0);
        }
        ScheduleWindowCopyToVram(PTR(windows, i * 16));
    }
    U8(work, 0x4a2) ^= 1;
}

void ov67_021E6530(void *work) {
    FillWindowPixelBuffer(PTR(work, 0xac), 0);
    BufferIntegerAsString((void *)U32(work, 0x2c), 0, U16(work, 0x4a0) + 1, 1, 0, 1);
    ov67_021E61A0(work, 4, 0x14, 8, 0, 0, 0x10200, 1);
    ov67_021E6164(work, 4, 0x15, 0x10, 0, 0, 0x10200, 2);
    BufferIntegerAsString((void *)U32(work, 0x2c), 0, 3, 1, 0, 1);
    ov67_021E61A0(work, 4, 0x14, 0x18, 0, 0, 0x10200, 0);
    ScheduleWindowCopyToVram(PTR(work, 0xac));
}

void ov67_021E65C0(void *work) {
    u32 i;
    u8 *window;
    u8 *window2;
    u32 j;
    u8 values[4];

    for (i = 0, window = PTR(work, 0x6c); i <= 3; i++, window += 16) {
        FillWindowPixelBuffer(window, 0);
    }
    ov67_021E61E8(work);
    sub_0202D8D0((void *)U32(work, 0x24), values);
    BufferIntegerAsString((void *)U32(work, 0x2c), 0, values[0], 2, 0, 1);
    ov67_021E61A0(work, 1, 0x11, 0, 0, 0, 0xf0200, 0);
    BufferIntegerAsString((void *)U32(work, 0x2c), 1, values[1], 3, 2, 1);
    ov67_021E61A0(work, 2, 0x12, 0x3c, 0, 0, 0xf0200, 2);
    ov67_021E6164(work, 3, 0x13, 0, 0, 0, 0xf0200, 0);
    for (j = 0, window2 = PTR(work, 0x6c); j <= 3; j++, window2 += 16) {
        ScheduleWindowCopyToVram(window2);
    }
    ov67_021E6490(work);
    ov67_021E6688(work, 0);
    ov67_021E6530(work);
}

void ov67_021E6688(void *work, int entry) {
    u32 windowIndex;
    u8 *windows;
    u16 i;

    if (U8(work, 0x4a3) == 0) {
        windowIndex = 5;
    } else {
        windowIndex = 8;
    }
    windows = PTR(work, 0x6c);
    windows = PTR(windows, windowIndex * 16);
    for (i = 0; i < 3; i++) {
        FillWindowPixelBuffer(PTR(windows, i * 16), 0);
    }
    if ((u32)entry < 30) {
        u32 offset = entry * 16;
        u8 *flags = PTR(work, 0x2a0);
        u8 *countries;
        u8 *mail;
        void *string;

        BufferString((void *)U32(work, 0x2c), 0, (void *)U32(work, 0x29c + offset),
            flags[offset], 1, 2);
        if (flags[offset] == 0) {
            ov67_021E61A0(work, windowIndex, 0x16, 0, 0, 0, 0x10200, 0);
        } else {
            ov67_021E61A0(work, windowIndex, 0x17, 0, 0, 0, 0x10200, 0);
        }
        ov67_021E6164(work, windowIndex + 1, 0x1c, 0, 0, 0, 0x10200, 0);
        countries = PTR(work, 0x2a1);
        if (countries[offset] == 0) {
            ov67_021E6164(work, windowIndex + 1, 0x1f, 0, 0x10, 0, 0x10200, 0);
        } else {
            BufferCountryName((void *)U32(work, 0x2c), 0, countries[offset]);
            ov67_021E61A0(work, windowIndex + 1, 0x1d, 0, 0x10, 0, 0x10200, 0);
        }
        if (U8(work, 0x2a2 + offset) != 0) {
            BufferCityName((void *)U32(work, 0x2c), 0, countries[offset], U8(work, 0x2a2 + offset));
            ov67_021E61A0(work, windowIndex + 1, 0x1e, 0, 0x20, 0, 0x10200, 0);
        }
        ov67_021E6164(work, windowIndex + 2, 0x20, 0, 0, 0, 0x10200, 0);
        mail = PTR(work, 0x2a4);
        string = MailMsg_GetExpandedString(PTR(mail, offset), U32(work, 0));
        ov67_021E6118(PTR(windows, 0x20), string, 0, 0x10, 0, 0x10200, 0);
        String_Delete(string);
    }
    for (i = 0; i < 3; i++) {
        ScheduleWindowCopyToVram(PTR(windows, i * 16));
    }
    U8(work, 0x4a3) ^= 1;
}
