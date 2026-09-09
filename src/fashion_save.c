#include "global.h"

#include "pm_string.h"
#include "pokemon.h"

typedef struct SaveFashionMon {
    u32 personality;
    u32 otId;
    u16 species;
    u16 nickname[11];
    u16 secondText[8];
    s8 unk_30;
    u8 unk_31;
    u8 unk_32;
    u8 form;
    u8 unk_34;
} SaveFashionMon;

extern void ov41_02249780(int, int *, int *);
extern int ov41_02249710(int);
BOOL sub_0202B614(u32 value);
void sub_0202B630(int a0, u8 *a1, u8 *a2, u8 *a3);
void sub_0202B684(SaveFashionMon *dst, Pokemon *mon, u8 a2, u8 a3, s8 a4);
void sub_0202B6E8(SaveFashionMon *dst, Pokemon *mon, int a2);
void sub_0202B718(SaveFashionMon *dst, String *str, u8 a2);
void sub_0202B730(SaveFashionMon *src, Pokemon *mon);
void sub_0202B770(u8 *dst, u8 a1, u8 a2, u8 a3, u8 a4);
void sub_0202B784(u32 *data, int value, u8 index);
u8 sub_0202B7C8(u32 *data, u8 index);
void sub_0202B808(u32 *data, u8 value, u8 index);

BOOL sub_0202B614(u32 value) {
    if (value == 0x1234 || value == 0x2345) {
        return TRUE;
    }
    return FALSE;
}

void sub_0202B630(int a0, u8 *a1, u8 *a2, u8 *a3) {
    int x;
    int y;
    int z;
    ov41_02249780(a0, &x, &y);
    z = ov41_02249710(a0);
    GF_ASSERT(x < 256);
    GF_ASSERT(y < 256);
    GF_ASSERT(z > -128);
    *a1 = x;
    *a2 = y;
    *a3 = z;
}

void sub_0202B684(SaveFashionMon *dst, Pokemon *mon, u8 a2, u8 a3, s8 a4) {
    dst->species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    GetMonData(mon, MON_DATA_NICKNAME, dst->nickname);
    dst->personality = GetMonData(mon, MON_DATA_PERSONALITY, NULL);
    dst->otId = GetMonData(mon, MON_DATA_OT_ID, NULL);
    dst->form = GetMonData(mon, MON_DATA_FORM, NULL);
    dst->unk_31 = a2;
    dst->unk_32 = a3;
    dst->unk_30 = a4;
}

void sub_0202B6E8(SaveFashionMon *dst, Pokemon *mon, int a2) {
    u8 x, y, z;
    sub_0202B630(a2, &x, &y, &z);
    sub_0202B684(dst, mon, x, y, (s8)z);
}

void sub_0202B718(SaveFashionMon *dst, String *str, u8 a2) {
    CopyStringToU16Array(str, dst->secondText, 8);
    dst->unk_34 = a2;
}

void sub_0202B730(SaveFashionMon *src, Pokemon *mon) {
    CreateMon(mon, src->species, 0, 0, TRUE, src->personality, TRUE, src->otId);
    SetMonData(mon, MON_DATA_NICKNAME, src->nickname);
    SetMonData(mon, MON_DATA_FORM, &src->form);
}

void sub_0202B770(u8 *dst, u8 a1, u8 a2, u8 a3, u8 a4) {
    dst[0] = a1;
    dst[1] = a2;
    dst[2] = a3;
    dst[3] = a4;
}

void sub_0202B784(u32 *data, int value, u8 index) {
    u8 shift;
    u8 word;
    GF_ASSERT(index < 61);
    shift = index % 8;
    shift *= 4;
    word = index / 8;
    data[word] &= ~(15 << shift);
    data[word] |= value << shift;
}

u8 sub_0202B7C8(u32 *data, u8 index) {
    u8 word;
    u8 shift;
    u8 value;
    GF_ASSERT(index < 61);
    word = index / 8;
    shift = index % 8;
    shift *= 4;
    value = (data[word] >> shift) & 15;
    if (value > 9) {
        value = 9;
    }
    return value;
}

void sub_0202B808(u32 *data, u8 value, u8 index) {
    u8 shift;
    u8 word;
    GF_ASSERT(value < 2);
    shift = index % 32;
    word = index / 32;
    data[word] &= ~(1 << shift);
    data[word] |= value << shift;
}
