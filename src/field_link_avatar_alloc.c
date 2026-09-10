#include "field_link_avatar_alloc_internal.h"

void *sub_0205ABD8(struct UnkStruct_02059E1C *p) {
    int gender;
    int attr;
    p->unk184 = sub_020691A8(0);
    p->unk188[0] = sub_020691A8(0);
    p->unk188[1] = sub_020691A8(0);
    gender = PlayerProfile_GetTrainerGender(p->unk08);
    attr = GetUnionRoomAvatarAttrBySprite(gender, PlayerProfile_GetAvatar(p->unk08), 0);
    sub_02068FC8(0, 0, 0, attr, p->unk00, p->unk184);
    return p->unk188[sub_0203769C() ^ 1];
}
