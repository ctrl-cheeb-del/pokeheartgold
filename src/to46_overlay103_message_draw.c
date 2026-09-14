#include "global.h"

#include "to46_overlay103_message_draw_private.h"

void ov103_021EE8A8(Ov103Work *work, u32 which) {
    switch (which) {
    case 0:
        ReadMsgDataIntoString(work->owner->msgData, 10, work->owner->string);
        break;
    case 1:
        ReadMsgDataIntoString(work->owner->msgData, 11, work->owner->string);
        break;
    case 2:
        ReadMsgDataIntoString(work->owner->msgData, 12, work->owner->string);
        break;
    case 3:
        ReadMsgDataIntoString(work->owner->msgData, 13, work->owner->string);
        break;
    case 4:
        ReadMsgDataIntoString(work->owner->msgData, 14, work->owner->string);
        break;
    }
    ov103_021EE7DC(work);
}

void ov103_021EE930(Ov103Work *work) {
    u32 i;

    for (i = 0; i < 3; i++) {
        FillWindowPixelBuffer((u8 *)work->owner + 0x48 + (i + 0x1A) * 16, 0);
        ov103_021EE9C8(work, i + 0x1A, i);
        ScheduleWindowCopyToVram((u8 *)work->owner + 0x48 + (i + 0x1A) * 16);
    }
    FillWindowPixelBuffer((u8 *)work->owner + 0x218, 0);
    CopyU16ArrayToString(work->owner->string,
        Mail_GetAuthorNamePtr(PTR_AT((u8 *)work->owner + *((u8 *)work + 0x1F) * 4, 0x27C)));
    ov103_021EE3E4((u8 *)work->owner + 0x218, work->owner->string, 0, 1, 1, 0x10200, 0);
    ScheduleWindowCopyToVram((u8 *)work->owner + 0x218);
}

void ov103_021EE9C8(Ov103Work *work, u32 windowIndex, u32 messageIndex) {
    void *message;
    void *string;
    u8 selected = *((u8 *)work + 0x1F);
    void *mail = PTR_AT((u8 *)work->owner + selected * 4, 0x27C);

    message = Mail_GetUnk20Array(mail, (u8)messageIndex);
    if (MailMsg_IsInit(message)) {
        string = MailMsg_GetExpandedString(message, 0x9D);
        ov103_021EE3E4((u8 *)work->owner + 0x48 + windowIndex * 16,
            string,
            0,
            0,
            1,
            0x10200,
            0);
        String_Delete(string);
    }
}
