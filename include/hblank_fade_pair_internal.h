#ifndef PRIVATE_UNK_0200FEE4_H
#define PRIVATE_UNK_0200FEE4_H

typedef void (*FadeBlankFunc)(u32);
typedef struct FadeBlankPair {
    u32 values[2];
    FadeBlankFunc funcs[2];
    u32 active[2];
} FadeBlankPair;

void GF_AssertFail(void);
BOOL Main_SetHBlankIntrCB(void (*cb)(void *), void *arg);
void sub_0200FECC(FadeBlankPair *data);
void sub_02010014(u32 value);
void sub_0200FEE4(FadeBlankPair *data, u32 value, FadeBlankFunc func, int index);

#endif
