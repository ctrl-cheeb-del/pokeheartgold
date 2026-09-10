#include "apricorn_internal.h"

BOOL sub_02031C30(SaveApricornBox *box, int apricorn, u32 value);
int sub_02031CA0(SaveApricornBox *box);
void sub_02031CCC(SaveApricornBox *box, int amount);
u8 sub_02031CE8(SaveApricornBox *box);

BOOL sub_02031C30(SaveApricornBox *box, int apricorn, u32 value) {
    u16 slots = box->unk_0A;
    u16 encoded;
    int i;
    if (apricorn >= 7) {
        GF_ASSERT(FALSE);
        return FALSE;
    }
    for (i = 0; i < 5; i++) {
        if (slots & 7) {
            slots >>= 3;
            continue;
        }
        encoded = ((apricorn + 1) & 7) << (i * 3);
        box->unk_0A |= encoded;
        box->unk_0A |= 2 << 14;
        box->unk_14 = value;
        if (box->unk_09 == 0) {
            box->unk_18 = value;
        }
        *(u32 *)((u8 *)box + 0x1C) &= 0xC0000000;
        ApricornBox_TakeApricorn(box, apricorn, 1);
        return TRUE;
    }
    return FALSE;
}

int sub_02031CA0(SaveApricornBox *box) {
    u32 value;
    if (sub_02031C08(box) == 0) {
        return 0;
    }
    value = box->mixProgress;
    if (value < 50) {
        return 1;
    }
    if (value < 80) {
        return 2;
    }
    return 3;
}

void sub_02031CCC(SaveApricornBox *box, int amount) {
    int increment = amount * 10;
    int value;
    if (box->unk_09 != 0) {
        value = box->unk_0C[2];
        value += increment;
        if (value > 255) {
            box->unk_0C[2] = 255;
        } else {
            box->unk_0C[2] = value;
        }
    }
}

u8 sub_02031CE8(SaveApricornBox *box) {
    return box->unk_09;
}
