#ifndef POKEHEARTGOLD_OVERLAY96_R97_ITEM_UPDATE_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY96_R97_ITEM_UPDATE_PRIVATE_H

#include "global.h"

typedef struct R97Item {
    u32 values[5];
    union {
        u32 raw;
        struct {
            u32 low : 8;
            u32 field8 : 8;
            u32 count : 8;
            u32 middle : 6;
            u32 index : 2;
        } bits;
    } state;
    union {
        u32 raw;
        struct {
            u32 low : 11;
            u32 counter : 11;
            u32 high : 10;
        } bits;
    } timer;
    u32 flags;
    u32 field20;
} R97Item;

void GF_AssertFail(void);
void ov96_0220D014(R97Item *item, int add, u32 unused);
void ov96_0220D07C(R97Item *item);
void ov96_0220D0F8(R97Item *item);

#endif
