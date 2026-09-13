#include "r40_overlay_80_0222BDF4_residual_32_private.h"

void ov80_0222E400(String *dest, u16 bank, u16 number, u16 field0, u16 field1) {
    MailMessage message;
    String *expanded;
    MailMsg_Init(&message);
    MailMsg_SetMsgBankAndNum(&message, bank, number);
    MailMsg_SetFieldI(&message, 0, field0);
    MailMsg_SetFieldI(&message, 1, field1);
    expanded = MailMsg_GetExpandedString(&message, (enum HeapID)0x20);
    String_Copy(dest, expanded);
    String_Delete(expanded);
}
