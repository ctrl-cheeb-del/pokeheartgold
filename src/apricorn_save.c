#include "global.h"

#include "constants/items.h"

#include "apricorn_internal.h"

void sub_02031B5C(void *ptr);
void sub_02031B3C(SaveApricornBox *apricornBox);
void sub_020325CC(void *ptr);
int ApricornBox_TakeApricorn(SaveApricornBox *apricornBox, int apricorn, u32 quantity);
u32 Save_ApricornBox_sizeof(void);
u32 sub_02031B10(void);
SaveApricornBox *Save_ApricornBox_Get(SaveData *saveData);
void InitApricornBox(SaveApricornBox *apricornBox);
void Save_ApricornBox_Init(SaveApricornBox *apricornBox);
int ApricornBox_GiveApricorn(SaveApricornBox *apricornBox, int apricorn, u8 amount);
int ApricornBox_CountApricorn(SaveApricornBox *apricornBox, int apricorn);
void ApricornBox_SetKurtApricorn(SaveApricornBox *apricornBox, u32 apricorn, u32 quantity);
int ApricornBox_GetKurtQuantity(SaveApricornBox *apricornBox);
int ApricornBox_GetKurtBall(SaveApricornBox *apricornBox);
void sub_02031BEC(SaveApricornBox *apricornBox, u32 value);
u32 sub_02031C00(SaveApricornBox *apricornBox);

u32 Save_ApricornBox_sizeof(void) {
    return sizeof(SaveApricornBox);
}

u32 sub_02031B10(void) {
    return 0x20;
}

SaveApricornBox *Save_ApricornBox_Get(SaveData *saveData) {
    return SaveArray_Get(saveData, 0x26);
}

void InitApricornBox(SaveApricornBox *apricornBox) {
    MI_CpuFill8(apricornBox, 0, sizeof(SaveApricornBox));
    sub_02031B5C(apricornBox->unk_0C);
    sub_02031B3C(apricornBox);
}

void sub_02031B3C(SaveApricornBox *apricornBox) {
    int i;
    for (i = 0; i < 3; i++) {
        sub_020325CC(apricornBox->unk_20[i]);
    }
}

void Save_ApricornBox_Init(SaveApricornBox *apricornBox) {
    InitApricornBox(apricornBox);
}

void sub_02031B5C(void *ptr) {
    MI_CpuFill8(ptr, 0, 8);
}

int ApricornBox_GiveApricorn(SaveApricornBox *apricornBox, int apricorn, u8 amount) {
    int quantity = amount;
    if (apricorn >= 7) {
        GF_ASSERT(FALSE);
        return 0;
    }
    quantity += apricornBox->apricorns[apricorn];
    if (quantity > 99) {
        apricornBox->apricorns[apricorn] = 99;
    } else {
        apricornBox->apricorns[apricorn] = quantity;
    }
    return apricornBox->apricorns[apricorn];
}

int ApricornBox_TakeApricorn(SaveApricornBox *apricornBox, int apricorn, u32 quantity) {
    u8 count;
    if (apricorn >= 7) {
        GF_ASSERT(FALSE);
        return 0;
    }
    count = apricornBox->apricorns[apricorn];
    if (count >= quantity) {
        apricornBox->apricorns[apricorn] = count - quantity;
    }
    return apricornBox->apricorns[apricorn];
}

int ApricornBox_CountApricorn(SaveApricornBox *apricornBox, int apricorn) {
    if (apricorn >= 7) {
        GF_ASSERT(FALSE);
        return 0;
    }
    return apricornBox->apricorns[apricorn];
}

void ApricornBox_SetKurtApricorn(SaveApricornBox *apricornBox, u32 apricorn, u32 quantity) {
    if (apricornBox->apricorns[apricorn] < quantity) {
        GF_ASSERT(FALSE);
        return;
    }
    apricornBox->kurtApricorn = apricorn;
    apricornBox->kurtQuantity = quantity;
    ApricornBox_TakeApricorn(apricornBox, apricorn, quantity);
}

int ApricornBox_GetKurtQuantity(SaveApricornBox *apricornBox) {
    return apricornBox->kurtQuantity;
}

extern const u16 _020F68D0[];

int ApricornBox_GetKurtBall(SaveApricornBox *apricornBox) {
    if (apricornBox->kurtApricorn >= 7) {
        return ITEM_POKE_BALL;
    }
    return _020F68D0[apricornBox->kurtApricorn];
}

void sub_02031BEC(SaveApricornBox *apricornBox, u32 value) {
    apricornBox->unk_1C = (apricornBox->unk_1C & 0x3FFFFFFF) | (value << 30);
}

u32 sub_02031C00(SaveApricornBox *apricornBox) {
    return apricornBox->unk_1C >> 30;
}
