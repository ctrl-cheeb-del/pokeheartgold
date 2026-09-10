#include "field_link_messages_internal.h"

void sub_0205AA4C(struct UnkSub_0205AA4C *p) {
    int i;
    p->unk1C = 0;
    for (i = 0; i < 4; i++) {
        p->unk00[i] = 0;
        p->unk18[i] = 0;
        p->unk10[i] = 0;
        p->unk14[i] = 0;
    }
}

void sub_0205AA6C(struct UnkStruct_02059E1C *p, MailMessage *mailMessage) {
    MailMsg_Copy((MailMessage *)p->unk178, mailMessage);
    p->unk180 = 1;
}

MailMessage *sub_0205AA84(struct UnkStruct_02059E1C *p) {
    if (p->unk180 == 0) {
        return NULL;
    }
    p->unk180 = 0;
    return (MailMessage *)p->unk178;
}
