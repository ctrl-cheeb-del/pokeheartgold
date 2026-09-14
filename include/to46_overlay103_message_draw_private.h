#ifndef TO46_OVERLAY103_MESSAGE_DRAW_PRIVATE_H
#define TO46_OVERLAY103_MESSAGE_DRAW_PRIVATE_H

#include "global.h"

#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))

typedef struct Ov103MsgOwner {
    u8 pad[0x228];
    void *msgData;
    u8 gap[4];
    void *string;
} Ov103MsgOwner;

typedef struct Ov103Work {
    u8 pad[0xC];
    Ov103MsgOwner *owner;
} Ov103Work;

void ReadMsgDataIntoString(void *, u32, void *);
void ov103_021EE7DC(Ov103Work *);
void ov103_021EE8A8(Ov103Work *, u32);
void *Mail_GetUnk20Array(void *, u8);
BOOL MailMsg_IsInit(void *);
void *MailMsg_GetExpandedString(void *, u32);
void String_Delete(void *);
void ov103_021EE3E4(void *, void *, u32, u32, u32, u32, u32);
void ov103_021EE9C8(Ov103Work *, u32, u32);
void FillWindowPixelBuffer(void *, u8);
void ScheduleWindowCopyToVram(void *);
void *Mail_GetAuthorNamePtr(void *);
void CopyU16ArrayToString(void *, const u16 *);
void ov103_021EE930(Ov103Work *);

#endif
