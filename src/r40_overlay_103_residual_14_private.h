#ifndef SOL_R40_OV103_R14_PRIVATE_H
#define SOL_R40_OV103_R14_PRIVATE_H
#include "global.h"
typedef struct R14Args {
    void *save;
    u32 unk4;
    void *unk8;
} R14Args;
typedef struct R14Work {
    u8 pad0[8];
    R14Args *args;
    u32 unkC;
    void *manager;
    void *mail;
    u8 pad18[9];
    u8 index : 7;
    u8 bit7 : 1;
    u16 item;
    u32 result;
} R14Work;
extern const u32 ov103_021EEC58;
u32 ItemToMailId(u16);
void *sub_02090E68(void *, u32, u32, u32, u32);
void *OverlayManager_New(const void *, void *, u32);
u32 sub_02090F6C(void *);
void *SaveArray_Party_Get(void *);
void *Party_GetMonByIndex(void *, u32);
void sub_02090F70(void *, void *);
void *Save_Bag_Get(void *);
void Bag_TakeItem(void *, u16, u32, u32);
void sub_02090F90(void *);
u32 ov103_021EDD54(R14Work *);
u32 ov103_021EDD98(R14Work *);
#endif
