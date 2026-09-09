#include "friend_group.h"

#include "global.h"

#include "math_util.h"
#include "string_util.h"
extern SAV_FRIEND_GRP *_021D2AF0;
u32 Save_FriendGroup_sizeof(void);
void sub_0202C738(SAV_FRIEND_GRP *data, int src, int dst);
void Save_FriendGroup_Init(SAV_FRIEND_GRP *data);
void sub_0202C78C(SAV_FRIEND_GRP *data, u32 count);
u32 Save_FriendGroup_GetGroupId(SAV_FRIEND_GRP *data, int index);
void sub_0202C7C0(SAV_FRIEND_GRP *data, int index, u32 id);
u32 sub_0202C7DC(SAV_FRIEND_GRP *data);
u16 *sub_0202C7E0(SAV_FRIEND_GRP *data, int index, int type);
void sub_0202C7F8(SAV_FRIEND_GRP *data, int index, int type, String *str);
void sub_0202C824(SAV_FRIEND_GRP *data, int index, u8 value);
u8 sub_0202C830(SAV_FRIEND_GRP *data, int index);
u8 sub_0202C83C(SAV_FRIEND_GRP *data, int index);
void sub_0202C848(SAV_FRIEND_GRP *data, int index, u8 value);
SAV_FRIEND_GRP *Save_FriendGroup_Get(SaveData *save);
BOOL sub_0202C860(SAV_FRIEND_GRP *data, int index);
BOOL sub_0202C878(SAV_FRIEND_GRP *data, int index);
BOOL sub_0202C88C(SAV_FRIEND_GRP *data, u16 *name);
BOOL sub_0202C8C4(FRIEND_GROUP *group);
BOOL sub_0202C8E4(FRIEND_GROUP *a, FRIEND_GROUP *b);
u32 Save_FriendGroup_sizeof(void) {
    return sizeof(SAV_FRIEND_GRP);
}
void sub_0202C738(SAV_FRIEND_GRP *data, int src, int dst) {
    data->groups[dst] = data->groups[src];
}
void Save_FriendGroup_Init(SAV_FRIEND_GRP *data) {
    int i;
    MI_CpuClearFast(data, sizeof(*data));
    for (i = 0; i < 6; i++) {
        data->groups[i].unk_0[0] = 0xFFFF;
        data->groups[i].unk_10[0] = 0xFFFF;
    }
    _021D2AF0 = data;
}
void sub_0202C78C(SAV_FRIEND_GRP *data, u32 count) {
    u32 i, j;
    for (i = 0; i < 6; i++) {
        for (j = 0; j < count; j++) {
            data->groups[i].unk_28 = PRandom(data->groups[i].unk_28);
        }
    }
}
u32 Save_FriendGroup_GetGroupId(SAV_FRIEND_GRP *data, int index) {
    return data->groups[index].unk_24;
}
void sub_0202C7C0(SAV_FRIEND_GRP *data, int index, u32 id) {
    data->groups[index].unk_24 = id;
    data->groups[index].unk_28 = PRandom(id);
}
u32 sub_0202C7DC(SAV_FRIEND_GRP *data) {
    return data->groups[1].unk_28;
}
u16 *sub_0202C7E0(SAV_FRIEND_GRP *data, int index, int type) {
    if (type == 0) {
        return data->groups[index].unk_0;
    } else {
        return data->groups[index].unk_10;
    }
}
void sub_0202C7F8(SAV_FRIEND_GRP *data, int index, int type, String *str) {
    if (type == 0) {
        CopyStringToU16Array(str, data->groups[index].unk_0, 8);
    } else {
        CopyStringToU16Array(str, data->groups[index].unk_10, 8);
    }
}
void sub_0202C824(SAV_FRIEND_GRP *data, int index, u8 value) {
    data->groups[index].unk_20 = value;
}
u8 sub_0202C830(SAV_FRIEND_GRP *data, int index) {
    return data->groups[index].unk_20;
}
u8 sub_0202C83C(SAV_FRIEND_GRP *data, int index) {
    return data->groups[index].unk_21;
}
void sub_0202C848(SAV_FRIEND_GRP *data, int index, u8 value) {
    data->groups[index].unk_21 = value;
}
SAV_FRIEND_GRP *Save_FriendGroup_Get(SaveData *save) {
    return SaveArray_Get(save, 14);
}
BOOL sub_0202C860(SAV_FRIEND_GRP *data, int index) {
    return !sub_0202C8C4(&data->groups[index]);
}
BOOL sub_0202C878(SAV_FRIEND_GRP *data, int index) {
    return sub_0202C8E4(&data->groups[1], &data->groups[index]);
}
BOOL sub_0202C88C(SAV_FRIEND_GRP *data, u16 *name) {
    int i;
    if (name[0] == 0xFFFF) {
        return FALSE;
    }
    for (i = 0; i < 6; i++) {
        if (!StringNotEqualN(name, data->groups[i].unk_0, 8)) {
            return TRUE;
        }
    }
    return FALSE;
}
BOOL sub_0202C8C4(FRIEND_GROUP *group) {
    if (group->unk_0[0] == 0xFFFF) {
        return TRUE;
    }
    if (group->unk_10[0] == 0xFFFF) {
        return TRUE;
    }
    return FALSE;
}
BOOL sub_0202C8E4(FRIEND_GROUP *a, FRIEND_GROUP *b) {
    if (StringNotEqualN(a->unk_10, b->unk_10, 8)) {
        return FALSE;
    }
    if (StringNotEqualN(a->unk_0, b->unk_0, 8)) {
        return FALSE;
    }
    if (a->unk_20 != b->unk_20) {
        return FALSE;
    }
    if (a->unk_21 != b->unk_21) {
        return FALSE;
    }
    if (a->unk_24 == b->unk_24) {
        return TRUE;
    }
    return FALSE;
}
