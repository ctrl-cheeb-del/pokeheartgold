#ifndef TO40_SOL_R18_TRAINER_AI_PRIVATE_H
#define TO40_SOL_R18_TRAINER_AI_PRIVATE_H

#include "global.h"

typedef struct {
    u8 pad[0x2134];
    int *script;
    int index;
} AiState;

typedef struct {
    u32 pad : 8;
    u32 flag : 3;
    u32 rest : 21;
} AiBits;

extern void GF_AssertFail(void);
extern void ov10_0221EF24(void *, int);
extern int ov10_0221EEF0(void *);
extern int ov10_0221EE60(void *, void *);
extern int ov10_0221EF34(void *, u8);
extern int GetBattlerAbility(void *, int);

void ov10_0221EC44(void *, void *);
void ov10_0221EC6C(void *, void *);
void ov10_0221ED10(void *, void *);
void ov10_0221ED48(void *, void *);
void ov10_0221ED80(void *, void *);
void ov10_0221EDB4(void *, void *);
void ov10_0221EDF8(void *, void *);
void ov10_0221EE28(void *, void *, int);
int ov10_0221EE60(void *, void *);
void ov10_0221EE88(void *, void *);
int ov10_0221EEF0(void *);

#endif
