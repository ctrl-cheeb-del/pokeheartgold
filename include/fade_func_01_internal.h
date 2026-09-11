#ifndef PRIVATE_H
#define PRIVATE_H
#include "global.h"
typedef struct FadeWork {
    u8 pad00[0xc];
    u32 state;
    u8 pad10[0x14];
    u16 color;
    u16 pad26;
    u32 topScreen;
    u32 bottomScreen;
} FadeWork;
void sub_02010B14(FadeWork *, u32, u32);
BOOL sub_02010BB4(FadeWork *);
void sub_0200FCDC(u16);
void sub_0201289C(FadeWork *, const void *);
BOOL sub_020128E0(FadeWork *);
extern const u8 _020F5D60[];
typedef struct FadeParam {
    const void *first;
    u8 rest[0x7c];
} FadeParam;
extern volatile FadeParam _0210F64C;
BOOL FadeFunc_01(FadeWork *);
BOOL FadeFunc_02(FadeWork *);
#endif
