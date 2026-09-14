#ifndef TO45_OVERLAY102_MESSAGE_CURSOR_R2_PRIVATE_H
#define TO45_OVERLAY102_MESSAGE_CURSOR_R2_PRIVATE_H

#include "global.h"

typedef struct Ov102MessageCursor {
    s16 bank;
    s8 number;
    s8 count;
    s8 fields[5];
} Ov102MessageCursor;

void MailMsg_SetMsgBankAndNum(void *message, s16 bank, s8 number);

void ov102_021E7968(Ov102MessageCursor *cursor, void *message);
void ov102_021E79A0(Ov102MessageCursor *cursor, void *message);
void ov102_021E79DC(Ov102MessageCursor *cursor, void *message, int value);

#endif
