#include "overlay80_menu_build_e5b0_private.h"

void ov80_0222E690(void *work, u32 messageNo, u16 value, void *callback) {
    String *string;

    string = String_New(0x50, *(u32 *)((u8 *)PTR_AT(work, 0) + 0x34));
    ReadMsgDataIntoString(PTR_AT(work, 0x8C), messageNo, string);
    StringExpandPlaceholders(PTR_AT(work, 0x90), PTR_AT((u8 *)work + U8_AT(work, 0x9B) * 4, 0x1C), string);
    PTR_AT((u8 *)work + U8_AT(work, 0x9B) * 8, 0xB4) = PTR_AT((u8 *)work + U8_AT(work, 0x9B) * 4, 0x1C);
    String_Delete(string);
    U16_AT((u8 *)work + U8_AT(work, 0x9B) * 2, 0x29C) = value;
    PTR_AT((u8 *)work + U8_AT(work, 0x9B) * 8, 0xB8) = callback;
    U8_AT(work, 0x9B)
    ++;
}

u32 ov80_0222E714(void *work) {
    u32 width = 0;
    s32 i = 0;
    s32 count = U8_AT(work, 0x9B);
    u8 *cursor;

    if (count > 0) {
        cursor = work;
        do {
            String *string = PTR_AT(cursor, 0xB4);
            u32 next;
            if (string == NULL) {
                break;
            }
            next = FontID_String_GetWidth(0, string, 0);
            if (width < next) {
                width = next;
            }
            i++;
            cursor += 8;
        } while (i < U8_AT(work, 0x9B));
    }
    return width + 12;
}
