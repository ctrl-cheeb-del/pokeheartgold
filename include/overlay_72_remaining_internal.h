#ifndef TO40_OVERLAY_72_PRIVATE_H
#define TO40_OVERLAY_72_PRIVATE_H
#include "global.h"

typedef struct Ov72GlobalState {
    s32 state;
    s32 result;
} Ov72GlobalState;
typedef struct Ov72NetState {
    u8 pad00[3];
    u8 mode;
    u8 pad04[4];
    u8 *response;
} Ov72NetState;

extern s32 _0223B820[];
extern u8 ov72_0223B920[];
int ov38_0221BF48(void);
void ov38_0221C014(void);
s32 ov38_0221C020(void);
void ov38_0221BFEC(void);
s32 ov72_02237D88(void);
void ov72_022378DC(void);
BOOL ov72_02237B54(void);

#endif
