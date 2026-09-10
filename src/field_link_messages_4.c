#include "field_link_messages_internal.h"

void sub_0205AB88(MailMessage *mailMessage) {
    struct UnkSub_0205AA4C sp0;
    sub_0205AA4C(&sp0);
    sp0.unk1C = 0;
    sub_02035838(mailMessage);
    sub_02035854(&sp0);
    sub_0203588C();
}

void sub_0205ABB0(struct UnkStruct_02059E1C *p) {
    p->unk30 = 0;
    p->unk40 = 0;
    p->unk44 = 0;
}

void sub_0205ABBC(struct UnkStruct_02059E1C *p) {
    p->unk20 = 0;
    p->unk24 = 0;
    p->unk2C = 0;
    p->unk30 = 0;
    p->unk40 = 0;
    p->unk174 = 0;
    p->unk180 = 0;
    p->unk44 = 0;
}
