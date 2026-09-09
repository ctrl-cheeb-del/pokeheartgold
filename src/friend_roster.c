#include "global.h"

#include "gf_rtc.h"
#include "pm_string.h"
#include "unk_0202C034.h"
typedef struct FriendEntry {
    u16 name[8], name2[8];
    u32 id;
    u16 value24, value26, value28, value2A;
    u8 value2C, value2D, value2E, value2F;
    u16 value30, value32, value34, value36;
} FriendEntry;
typedef struct FriendEntryArray {
    FriendEntry entries[32];
} FriendEntryArray;
struct UnkStruct_021D2230 {
    u8 header[0x40];
    u32 friendData[32][3];
    FriendEntryArray roster;
};
extern UnkStruct_021D2230 _021D2230;
void sub_0203A01C(UnkStruct_021D2230 *data);
BOOL DWC_IsValidFriendData(void *data);
u32 sub_0202C034(void);
void sub_0202C03C(UnkStruct_021D2230 *data);
void *sub_0202C08C(UnkStruct_021D2230 *data);
s32 sub_0202C090(UnkStruct_021D2230 *data, s32 index, s32 field);
void sub_0202C190(UnkStruct_021D2230 *data, int index, int field, u8 value);
void *sub_0202C23C(UnkStruct_021D2230 *data, int index);
u16 *sub_0202C254(UnkStruct_021D2230 *data, s32 index);
void sub_0202C270(UnkStruct_021D2230 *data, int index, String *name);
u16 *sub_0202C298(UnkStruct_021D2230 *data, s32 index);
void sub_0202C2B4(UnkStruct_021D2230 *data, int index, String *name);
BOOL sub_0202C2DC(UnkStruct_021D2230 *data, int index);
int sub_0202C2F8(UnkStruct_021D2230 *data);
int sub_0202C318(UnkStruct_021D2230 *data);
void sub_0202C338(UnkStruct_021D2230 *data, int index);
void sub_0202C3E8(UnkStruct_021D2230 *data, int dest, int src);
void sub_0202C46C(UnkStruct_021D2230 *data);
void sub_0202C4B0(UnkStruct_021D2230 *data, s32 index);
u32 sub_0202C034(void) {
    return sizeof(UnkStruct_021D2230);
}
void sub_0202C03C(UnkStruct_021D2230 *data) {
    int i;
    MI_CpuClearFast(data, sizeof(*data));
    for (i = 0; i < 32; i++) {
        data->roster.entries[i].name2[0] = 0xFFFF;
        data->roster.entries[i].name[0] = 0xFFFF;
        data->roster.entries[i].value2E = 2;
    }
    sub_0203A01C(data);
    MI_CpuCopy8(data, &_021D2230, sizeof(*data));
}
void *sub_0202C08C(UnkStruct_021D2230 *data) {
    return data;
}
s32 sub_0202C090(UnkStruct_021D2230 *data, s32 index, s32 field) {
    int value;
    GF_ASSERT(index < 32);
    switch (field) {
    case 0:
        value = data->roster.entries[index].id;
        break;
    case 1:
        value = data->roster.entries[index].value24;
        break;
    case 2:
        value = data->roster.entries[index].value26;
        break;
    case 3:
        value = data->roster.entries[index].value28;
        break;
    case 4:
        value = data->roster.entries[index].value2A;
        break;
    case 5:
        value = data->roster.entries[index].value2C;
        break;
    case 6:
        value = data->roster.entries[index].value2D;
        break;
    case 8:
        value = data->roster.entries[index].value2E;
        break;
    case 7:
        value = data->roster.entries[index].value2F;
        break;
    case 9:
        value = data->roster.entries[index].value30;
        break;
    case 10:
        value = data->roster.entries[index].value32;
        break;
    case 11:
        value = data->roster.entries[index].value34;
        break;
    case 12:
        value = data->roster.entries[index].value36;
        break;
    }
    return value;
}
void sub_0202C190(UnkStruct_021D2230 *data, int index, int field, u8 value) {
    GF_ASSERT(index < 32);
    switch (field) {
    case 0:
        data->roster.entries[index].id = value;
        break;
    case 1:
        GF_ASSERT(FALSE);
        break;
    case 2:
        GF_ASSERT(FALSE);
        break;
    case 3:
        GF_ASSERT(FALSE);
        break;
    case 4:
        data->roster.entries[index].value2A = value;
        break;
    case 5:
        data->roster.entries[index].value2C = value;
        break;
    case 6:
        data->roster.entries[index].value2D = value;
        break;
    case 8:
        data->roster.entries[index].value2E = value;
        break;
    case 7:
        data->roster.entries[index].value2F = value;
        break;
    case 9:
        GF_ASSERT(FALSE);
        break;
    }
}
void *sub_0202C23C(UnkStruct_021D2230 *data, int index) {
    GF_ASSERT(index < 32);
    return data->friendData[index];
}
u16 *sub_0202C254(UnkStruct_021D2230 *data, s32 index) {
    GF_ASSERT(index < 32);
    return data->roster.entries[index].name2;
}
void sub_0202C270(UnkStruct_021D2230 *data, int index, String *name) {
    GF_ASSERT(index < 32);
    CopyStringToU16Array(name, data->roster.entries[index].name2, 16);
}
u16 *sub_0202C298(UnkStruct_021D2230 *data, s32 index) {
    GF_ASSERT(index < 32);
    return data->roster.entries[index].name;
}
void sub_0202C2B4(UnkStruct_021D2230 *data, int index, String *name) {
    GF_ASSERT(index < 32);
    CopyStringToU16Array(name, data->roster.entries[index].name, 16);
}
BOOL sub_0202C2DC(UnkStruct_021D2230 *data, int index) {
    GF_ASSERT(index < 32);
    return DWC_IsValidFriendData(data->friendData[index]);
}
int sub_0202C2F8(UnkStruct_021D2230 *data) {
    int i, count = 0;
    for (i = 0; i < 32; i++) {
        if (sub_0202C2DC(data, i)) {
            count++;
        }
    }
    return count;
}
int sub_0202C318(UnkStruct_021D2230 *data) {
    int end = 0, i;
    for (i = 0; i < 32; i++) {
        if (sub_0202C2DC(data, i)) {
            end = i + 1;
        }
    }
    return end;
}
void sub_0202C338(UnkStruct_021D2230 *data, int index) {
    int i;
    if (index >= 0 && index < 32) {
        for (i = index; i < 31; i++) {
            MI_CpuCopy8(&data->roster.entries[i + 1], &data->roster.entries[i], sizeof(FriendEntry));
            MI_CpuCopy8(data->friendData[i + 1], data->friendData[i], sizeof(data->friendData[i]));
        }
        MI_CpuClearFast((u8 *)&data->roster + 0x6C8, sizeof(FriendEntry));
        MI_CpuClearFast((u8 *)&data->friendData + 0x174, sizeof(data->friendData[31]));
        ((FriendEntry *)((u8 *)&data->roster + 0x6C8))->name2[0] = 0xFFFF;
        ((FriendEntry *)((u8 *)&data->roster + 0x6C8))->name[0] = 0xFFFF;
        ((FriendEntry *)((u8 *)&data->roster + 0x6C8))->value2E = 2;
    }
}
void sub_0202C3E8(UnkStruct_021D2230 *data, int dest, int src) {
    if (dest >= 0 && dest < 32 && src >= 0 && src < 32) {
        MI_CpuCopy8(&data->roster.entries[src], &data->roster.entries[dest], sizeof(FriendEntry));
        MI_CpuCopy8(data->friendData[src], data->friendData[dest], sizeof(data->friendData[src]));
        MI_CpuClearFast(&data->roster.entries[src], sizeof(FriendEntry));
        MI_CpuClearFast(data->friendData[src], sizeof(data->friendData[src]));
        data->roster.entries[src].name2[0] = 0xFFFF;
        data->roster.entries[src].name[0] = 0xFFFF;
        data->roster.entries[src].value2E = 2;
    }
}
void sub_0202C46C(UnkStruct_021D2230 *data) {
    int i, empty = -1;
    for (i = 0; i < 32; i++) {
        if (sub_0202C2DC(data, i)) {
            if (empty != -1) {
                sub_0202C3E8(data, empty, i);
                i = -1;
                empty = -1;
            }
        } else if (empty == -1) {
            empty = i;
        }
    }
}
void sub_0202C4B0(UnkStruct_021D2230 *data, s32 index) {
    RTCDate date;
    GF_RTC_CopyDate(&date);
    if (index >= 0 && index < 32) {
        data->roster.entries[index].value2A = date.year + 2000;
        data->roster.entries[index].value2C = date.month;
        data->roster.entries[index].value2D = date.day;
    }
}
