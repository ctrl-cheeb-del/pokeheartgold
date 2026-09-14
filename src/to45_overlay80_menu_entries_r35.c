#include "to45_overlay80_menu_entries_r35_private.h"

void ov80_0222EA74(void *work, u32 messageNo, u16 value, void *callback) {
    Ov80MenuWorkPrefix *state = work;
    String *string;
    u8 count;

    string = String_New(0x50, (enum HeapID) * (u32 *)((u8 *)PTR_AT(work, 0) + 0x34));
    ReadMsgDataIntoString(state->msgData, messageNo, string);
    StringExpandPlaceholders(state->messageFormat, state->strings[state->count], string);
    count = state->count;
    *(String **)((u8 *)work + 0x1BC + count * 8) = state->strings[count];
    String_Delete(string);
    if (callback == (void *)0xFA) {
        u8 *slot = (u8 *)work + U8_AT(work, 0x9B) * 8;
        S32_AT(slot, 0x1C0) = -3;
    } else {
        u8 *slot = (u8 *)work + U8_AT(work, 0x9B) * 8;
        PTR_AT(slot, 0x1C0) = callback;
    }
    {
        u8 *slot = (u8 *)work + U8_AT(work, 0x9B) * 2;
        U16_AT(slot, 0x29C) = value;
    }
    U8_AT(work, 0x9B)
    ++;
}

u32 ov80_0222EB14(void *work) {
    u32 width = 0;
    s32 i = 0;
    s32 count = U8_AT(work, 0x9B);

    if (count > 0) {
        u8 *slot = work;
        do {
            String *string = *(String **)(slot + 0x1BC);
            u32 next;
            if (string == NULL) {
                break;
            }
            next = FontID_String_GetWidth(0, string, 0);
            if (width < next) {
                width = next;
            }
            i++;
            slot += 8;
        } while (i < U8_AT(work, 0x9B));
    }
    return width + 12;
}
