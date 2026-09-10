#ifndef POKEHEARTGOLD_MOTION_STATE_UPDATE_INTERNAL_H
#define POKEHEARTGOLD_MOTION_STATE_UPDATE_INTERNAL_H

#include "global.h"

typedef struct MotionState {
    int active;
    int kind;
    int value8;
    int valueC;
    int value10;
    int value14;
    int value18;
    int value1C;
    u8 pad20[4];
    int *valuePtr;
    void *object;
    u8 type;
    u8 counter;
    u8 pad2E[2];
    int initial;
} MotionState;

typedef struct MotionConfig {
    u8 raw[0x80];
} MotionConfig;
typedef struct MotionEntry {
    void (*func)(MotionState *);
    int count;
    int selector;
} MotionEntry;

extern const s16 FX_SinCosTable_[];
extern const MotionEntry _020F61BC[];
extern const int _020F61C0[];
extern const int _020F61C4[];
void GF_AssertFail(void);
int _s32_div_f(int, int);
void sub_02017BC8(u8, int *, int *, void *);
MotionState *sub_02017220(void *, u8);
void sub_02017280(void *, u8 *);
void sub_0201726C(void *, void *);

void sub_02017BF8(u8, MotionState *, MotionConfig *);
void sub_02017C78(void *, int, void *, void *);
void sub_02017D20(MotionState *);
void sub_02017DD8(MotionState *);
void sub_02017E98(MotionState *);
void sub_02017ED4(MotionState *);
void sub_02017F10(MotionState *);

#endif
