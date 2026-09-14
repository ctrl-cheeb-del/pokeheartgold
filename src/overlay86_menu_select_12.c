#include "overlay86_menu_select_12_private.h"

u8 ov86_021E7710(void *work) {
    u32 input;
    u8 *entries;
    u32 offset;

    input = GridInputHandler_HandleInput_NoHold((void *)U32_AT(work, 0x254));
    switch (input) {
    case 0x1a:
    case -2:
        PlaySE(0x5dd);
        ov86_021E71C0(work);
        ov86_021E723C(work);
        U8_AT(work, 5) = 10;
        return 9;
    case -3:
        PlaySE(0x5dc);
        goto exit;
    case -4:
    case -1:
        goto exit;
    default:
        entries = PTR_AT(work, 0x264);
        offset = input << 3;
        if (*(u32 *)(entries + offset) == 0) {
            PlaySE(0x5f2);
            goto exit;
        }
        PlaySE(0x5dd);
        U16_AT(work, 0x258) = input;
        U16_AT(work, 0x25a) = 0;
        U8_AT(work, 0x25c) = 0;
        U8_AT(work, 0x25d) = (*(u32 *)(entries + offset) - 1) >> 3;
        ov86_021E7688(work, U16_AT(work, 0x258));
        U8_AT(work, 5) = 4;
        return 9;
    }
exit:
    return 3;
}

void ov86_021E77BC(void *work) {
    u32 i;
    u8 *entry;

    for (i = 0, entry = work; i < 0x1a; i++, entry += 8) {
        if (U32_AT(entry, 0x264) == 0) {
            ov86_021E7688(work, i);
            BgTilemapRectChangePalette((void *)U32_AT(work, 0xc), 2, U8_AT(work, 0x250), U8_AT(work, 0x251), U8_AT(work, 0x252), U8_AT(work, 0x253), 1);
        }
    }
    ScheduleBgTilemapBufferTransfer((void *)U32_AT(work, 0xc), 2);
}
