#ifndef POKEHEARTGOLD_APRICORN_INTERNAL_H
#define POKEHEARTGOLD_APRICORN_INTERNAL_H

#include "global.h"

#include "heap.h"
#include "msgdata.h"
#include "player_data.h"
#include "string_util.h"
#include "unk_02031B0C.h"

struct SaveApricornBox {
    u8 apricorns[7];
    u8 kurtQuantity;
    u8 kurtApricorn;
    u8 unk_09;
    u16 unk_0A;
    u8 unk_0C[8];
    u32 unk_14;
    u32 unk_18;
    union {
        u32 unk_1C;
        struct {
            u32 mixProgress : 30;
            u32 mixState : 2;
        };
    };
    u8 unk_20[3][0x20];
};

typedef struct ApricornRecord {
    u32 trainerId;
    u8 gender;
    u8 language;
    u8 version;
    u8 padding;
    u16 name[8];
    UnkStruct_02031CEC data;
} ApricornRecord;

typedef struct ApricornMix {
    u8 padding[3];
    u8 values[5];
} ApricornMix;

u8 sub_02031C08(SaveApricornBox *);
int ApricornBox_TakeApricorn(SaveApricornBox *, int, u32);
void sub_02031B5C(void *);
BOOL sub_02031CEC(SaveApricornBox *, u16, UnkStruct_02031CEC *);
BOOL sub_02031D6C(UnkStruct_02031CEC *);
int sub_02031D80(UnkStruct_02031CEC *);
void sub_02031DA0(void *, void *);
void sub_02031BEC(SaveApricornBox *, u32);
void sub_02032340(SaveApricornBox *, u8);
void sub_02032354(SaveApricornBox *);
int sub_02032004(void *);
u8 sub_02032504(int, u8);

#endif
