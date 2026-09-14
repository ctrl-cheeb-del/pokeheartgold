#include "to45_overlay102_message_cursor_r2_private.h"

void ov102_021E7968(Ov102MessageCursor *cursor, void *message) {
    cursor->number++;
    if (cursor->number >= cursor->count) {
        cursor->number = 0;
        cursor->bank++;
        if (cursor->bank >= 5) {
            cursor->bank = 0;
        }
    }
    MailMsg_SetMsgBankAndNum(message, cursor->bank, cursor->number);
}

void ov102_021E79A0(Ov102MessageCursor *cursor, void *message) {
    cursor->number--;
    if (cursor->number < 0) {
        cursor->bank--;
        if (cursor->bank < 0) {
            cursor->bank = 4;
        }
        cursor->number = cursor->count - 1;
    }
    MailMsg_SetMsgBankAndNum(message, cursor->bank, cursor->number);
}

void ov102_021E79DC(Ov102MessageCursor *cursor, void *message, int value) {
    cursor->number = value % cursor->count;
    cursor->bank = value / cursor->count;
    MailMsg_SetMsgBankAndNum(message, cursor->bank, cursor->number);
}
