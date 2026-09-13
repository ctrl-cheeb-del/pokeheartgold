#ifndef OVERLAY_75_RESIDUAL_10_PRIVATE_H
#define OVERLAY_75_RESIDUAL_10_PRIVATE_H

#include "global.h"

typedef struct Ov75Residual10State {
    void *work;
    void *context;
    u32 next;
    u8 padding0C[0x20];
    void *message2C;
    void *message30;
    void *message34;
    u8 padding38[0x0C];
    u32 printer;
    u8 padding48[0x40];
    void *prompt;
    u8 padding8C[8];
    u32 state;
} Ov75Residual10State;

typedef struct Ov75Residual10Work {
    u32 unused;
    void *saveData;
} Ov75Residual10Work;

BOOL ov75_02248584(Ov75Residual10State *state);
BOOL ov75_02248684(Ov75Residual10State *state);
BOOL ov75_022486EC(Ov75Residual10State *state);

extern int ov75_02249534(u32 printer);
extern void ov75_022494CC(Ov75Residual10State *state, void *message, u32 messageId, u32 speed, u32 fill);
extern void *ov75_02247890(void *context, u32 heapId, u32 initialChoice);
extern int YesNoPrompt_HandleInput(void *prompt);
extern void YesNoPrompt_Destroy(void *prompt);
extern void ov75_02247854(Ov75Residual10State *state, u32 value, u32 amount);
extern int sub_0203A05C(void *saveData);
extern void ov75_02246BCC(void *work, u32 value, u32 unused);
extern void ov75_02246BE0(void *work, u32 value);
extern void ov75_0224785C(Ov75Residual10State *state);
extern void sub_0203957C(void);

#endif
