#include "global.h"

#include "party.h"
#include "player_avatar.h"
#include "pokemon.h"
#include "unk_02030A98.h"
#include "unk_02033AE0.h"
#include "unk_02035900.h"

extern const u32 _02108594[];
typedef struct CommDataBits {
    u8 pad[0x10];
    u8 low : 3;
    u8 flag : 1;
    u8 mid : 1;
    u8 high : 3;
} CommDataBits;
void sub_02096910(void *data);
void sub_02096924(int sender, int unused, const u16 *src, u8 *data);
BOOL sub_02096998(u8 *data);
void sub_020969C4(int sender, int unused, const void *src, u8 *data);
void sub_020969F8(int sender, int unused, const u16 *src, u8 *data);
BOOL sub_02096A34(u8 *data);
void sub_02096A7C(int sender, int unused, const u16 *src, u8 *data);
BOOL sub_02096AAC(u8 *data, u16 value);
void sub_02096ACC(int sender, int unused, const u16 *src, u8 *data);
BOOL sub_02096AF4(u8 *data, u8 first, u8 second);
void sub_02096BB8(int sender, int unused, const u16 *src, u8 *data);
BOOL sub_02096BF8(u8 *data, u16 value);
void sub_02096C18(int sender, int unused, const u16 *src, u8 *data);
BOOL sub_02096C40(u8 *data, u16 value);
void sub_02096C60(int sender, int unused, const u16 *src, u8 *data);
int ov80_022385D8(int value);

void sub_02096910(void *data) {
    sub_0203410C(_02108594, 52, data);
}

void sub_02096924(int sender, int unused, const u16 *src, u8 *data) {
    u16 result = 0;
    data[0x8D4]++;
    if (sender != sub_0203769C()) {
        data[0x12] = src[0];
        *(u16 *)(data + 0x16) = src[1];
        *(u16 *)(data + 0x18) = src[2];
        *(u16 *)(data + 0x14) = src[3];
        ((CommDataBits *)data)->high = data[0x12] + 5;
        if (*(u16 *)(data + 0x2E) == *(u16 *)(data + 0x16) || *(u16 *)(data + 0x2E) == *(u16 *)(data + 0x18)) {
            result += 1;
        }
        if (*(u16 *)(data + 0x30) == *(u16 *)(data + 0x16) || *(u16 *)(data + 0x30) == *(u16 *)(data + 0x18)) {
            result += 2;
        }
        *(u16 *)(data + 0x8D8) = result;
    }
}

BOOL sub_02096998(u8 *data) {
    MI_CpuCopy8(data + 0x3E, data + 0x83E, 0x1C);
    if (sub_02037030(0x3F, data + 0x83E, 0x1C) == 1) {
        return TRUE;
    }
    return FALSE;
}

void sub_020969C4(int sender, int unused, const void *src, u8 *data) {
    data[0x8D4]++;
    if (sender != sub_0203769C() && sub_0203769C() != 0) {
        MI_CpuCopy8(src, data + 0x3E, 0x1C);
    }
}

void sub_020969F8(int sender, int unused, const u16 *src, u8 *data) {
    *(u16 *)(data + 0x8D8) = 0;
    data[0x8D4]++;
    if (sender != sub_0203769C()) {
        if (((CommDataBits *)data)->flag != 0 || src[0] != 0) {
            *(u16 *)(data + 0x8D8) = 1;
        }
    }
}

BOOL sub_02096A34(u8 *data) {
    int stat;
    FrontierSave *frontier;
    *(u16 *)(data + 8) = data[0xA0];
    stat = ov80_022385D8(data[0xA0]);
    frontier = Save_Frontier_GetStatic(*(SaveData **)data);
    *(u16 *)(data + 0xA) = FrontierSave_GetStat(frontier, stat, sub_0205C268(stat));
    if (sub_02037030(0x39, data + 8, 0x28) == 1) {
        return TRUE;
    }
    return FALSE;
}

void sub_02096A7C(int sender, int unused, const u16 *src, u8 *data) {
    data[0x6F]++;
    if (sender != sub_0203769C()) {
        data[0x6E] = src[0];
        *(u16 *)(data + 0x72) = src[1];
    }
}

BOOL sub_02096AAC(u8 *data, u16 value) {
    *(u16 *)(data + 8) = value;
    if (sub_02037030(0x3A, data + 8, 0x28) == 1) {
        return TRUE;
    }
    return FALSE;
}

void sub_02096ACC(int sender, int unused, const u16 *src, u8 *data) {
    data[0x6F]++;
    if (sender != sub_0203769C()) {
        data[0x59] = src[0];
    }
}

BOOL sub_02096AF4(u8 *data, u8 first, u8 second) {
    Party *party = SaveArray_Party_Get(*(SaveData **)data);
    Pokemon *mon;
    data[0x6A] = first;
    data[0x6B] = second;
    if (first == 0xFF) {
        *(u16 *)(data + 0x76) = 0;
        *(u16 *)(data + 0x7E) = 0;
        *(u16 *)(data + 0x78) = 0;
        *(u16 *)(data + 0x80) = 0;
    } else {
        mon = Party_GetMonByIndex(party, first);
        *(u16 *)(data + 0x76) = GetMonData(mon, MON_DATA_SPECIES, NULL);
        *(u16 *)(data + 0x7E) = GetMonData(mon, MON_DATA_HELD_ITEM, NULL);
        mon = Party_GetMonByIndex(party, second);
        *(u16 *)(data + 0x78) = GetMonData(mon, MON_DATA_SPECIES, NULL);
        *(u16 *)(data + 0x80) = GetMonData(mon, MON_DATA_HELD_ITEM, NULL);
    }
    *(u16 *)(data + 8) = *(u16 *)(data + 0x76);
    *(u16 *)(data + 0xA) = *(u16 *)(data + 0x7E);
    *(u16 *)(data + 0xC) = *(u16 *)(data + 0x78);
    *(u16 *)(data + 0xE) = *(u16 *)(data + 0x80);
    if (sub_02037030(0x3B, data + 8, 0x28) == 1) {
        return TRUE;
    }
    return FALSE;
}

void sub_02096BB8(int sender, int unused, const u16 *src, u8 *data) {
    data[0x6F]++;
    if (sender != sub_0203769C()) {
        *(u16 *)(data + 0x86) = src[0];
        *(u16 *)(data + 0x8E) = src[1];
        *(u16 *)(data + 0x88) = src[2];
        *(u16 *)(data + 0x90) = src[3];
    }
}

BOOL sub_02096BF8(u8 *data, u16 value) {
    *(u16 *)(data + 8) = value;
    if (sub_02037030(0x3C, data + 8, 0x28) == 1) {
        return TRUE;
    }
    return FALSE;
}

void sub_02096C18(int sender, int unused, const u16 *src, u8 *data) {
    data[0x6F]++;
    if (sender != sub_0203769C()) {
        *(u16 *)(data + 0x74) = src[0];
    }
}

BOOL sub_02096C40(u8 *data, u16 value) {
    *(u16 *)(data + 8) = value;
    if (sub_02037030(0x3D, data + 8, 0x28) == 1) {
        return TRUE;
    }
    return FALSE;
}

void sub_02096C60(int sender, int unused, const u16 *src, u8 *data) {
    data[0x6F]++;
    if (sender != sub_0203769C()) {
        data[0x71] = src[0];
    }
}
