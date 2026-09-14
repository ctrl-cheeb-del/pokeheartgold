#include "to45_overlay59_apricorn_results_gap1_private.h"

void ov59_0223BBD4(void *work, int which) {
    u32 speed;

    switch (which) {
    case 0: {
        which = ((To45Nibble *)((u8 *)work + 0x20))->value;
        if (which == 6) {
            which = 12;
        } else if (which == 5) {
            which = U8_AT(work, 0x26) + 13;
        } else {
            which += 13;
        }
        speed = 0;
        break;
    }
    case 1:
        which = 18;
        speed = U8_AT(work, 0x4B);
        break;
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
        which += 17;
        speed = U8_AT(work, 0x4B);
        break;
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
        which += 17;
        speed = U8_AT(work, 0x4B);
        break;
    default:
        speed = U8_AT(work, 0x4B);
        break;
    }
    ReadMsgDataIntoString(PTR_AT(work, 0x5C), which, PTR_AT(work, 0x68));
    U8_AT(work, 0x4D) = AddTextPrinterParameterizedWithColor((u8 *)work + 0x1B4, 1, PTR_AT(work, 0x68), 0, 0, speed, 0x1020F, NULL);
    if (speed == 0) {
        ScheduleWindowCopyToVram((u8 *)work + 0x1B4);
    }
}

void ov59_0223BC88(void *work, int index) {
    u8 *entry = (u8 *)work + 0x7C + index * 0x34;

    FillWindowPixelBuffer((u8 *)work + 0x1F4, 0);
    AddTextPrinterParameterizedWithColor((u8 *)work + 0x1F4, 0, PTR_AT(entry, 0xC), 0, 0, 0xFF, 0xF0200, NULL);
    if (U8_AT(entry, 7) != 2) {
        int value = U8_AT(entry, 7);
        AddTextPrinterParameterizedWithColor((u8 *)work + 0x1F4, 0, PTR_AT((u8 *)work + value * 4, 0x70), 0x40, 0, 0xFF, ov59_0223C94C[value], NULL);
    }
    BufferIntegerAsString(PTR_AT(work, 0x60), 0, U8_AT(entry, 6), 3, 0, 1);
    StringExpandPlaceholders(PTR_AT(work, 0x60), PTR_AT(work, 0x68), PTR_AT(work, 0x6C));
    AddTextPrinterParameterizedWithColor((u8 *)work + 0x1F4, 0, PTR_AT(work, 0x68), 0x10, 0x10, 0xFF, 0x10200, NULL);
    ScheduleWindowCopyToVram((u8 *)work + 0x1F4);
    ov59_0223C3AC(PTR_AT(work, 0x78));
    ov59_0223C380(PTR_AT(work, 0x78), entry);
    ov59_0223BE18(work, entry);
}
