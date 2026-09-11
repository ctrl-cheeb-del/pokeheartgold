#ifndef SOL40_OV49_R72_PRIVATE_H
#define SOL40_OV49_R72_PRIVATE_H
#include "global.h"
extern const u8 ov49_0226A7A8[],ov49_0226A7B8[],ov49_0226A7C8[];
extern const u32 ov49_0226A70C[];
extern const u8 ov49_0226A454[],ov49_0226A46C[],ov49_0226A4B4[],ov49_0226A464[],ov49_0226A49C[],ov49_0226A4C0[],ov49_0226A47C[],ov49_0226A45C[],ov49_0226A474[];
void ov49_02265980(void *, void *, int, const u32 *);
void ov49_02267D98(void *, const void *, int, int, int, void *);
void ov49_02267C8C(void *, void *);
typedef struct Ov49R72Entry { u8 raw[0x78]; } Ov49R72Entry;
typedef struct Ov49R72State {
    u8 pad0[2];
    s16 progress;
    u8 pad4[8];
    Ov49R72Entry entries[19];
    u8 pad8f4[0x60];
    s8 count;
    s8 phase;
} Ov49R72State;
int sub_020182A4(void *);
void sub_020182A0(void *, int);
int ov49_02265B28(void *, Ov49R72State *, int, int);
void ov49_02265BE8(void *, Ov49R72State *, int, int, int);
#define DECL(n) void n(void *, u8 *)
DECL(ov49_0226639C);DECL(ov49_022663EC);DECL(ov49_0226643C);DECL(ov49_0226648C);DECL(ov49_022664DC);DECL(ov49_0226652C);DECL(ov49_0226657C);DECL(ov49_022665D0);DECL(ov49_02266624);
int ov49_02266678(void *, Ov49R72State *);
#endif
