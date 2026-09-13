#ifndef OVERLAY45_BATTLE_REQUESTS_PRIVATE_H
#define OVERLAY45_BATTLE_REQUESTS_PRIVATE_H
#include "global.h"
typedef struct Ov45State {
    u8 pad00[4];
    void *context;
    u8 pad08[0xE0];
    void *selected[4];
    u8 padF8[0x430];
    int heapId;
} Ov45State;
typedef struct Ov45Input {
    int values[4];
    u8 count;
    u8 pad11;
    u8 option;
    u8 mode : 7;
    u8 flag : 1;
} Ov45Input;
int ov45_0222EC68(int);
void *ov45_0222A578(Ov45State *, int);
void ov45_0222A844(void *, void *, int);
void ov45_0222D940(void *, void *);
void ov45_0222D990(void *, void *);
void ov45_0222D9EC(void *, void *);
void ov45_0222DA80(void *, void *);
void ov45_0222DAE0(void *, void *);
void ov45_0222DB3C(void *, void *);
void ov45_0222DC64(void *, void *);
void ov45_0222BE9C(Ov45State *, Ov45Input *);
void ov45_0222BF18(Ov45State *, Ov45Input *);
void ov45_0222BF98(Ov45State *, Ov45Input *);
void ov45_0222C0CC(Ov45State *, Ov45Input *);
void ov45_0222C130(Ov45State *, Ov45Input *);
void ov45_0222C1EC(Ov45State *, Ov45Input *);
void ov45_0222C2A8(Ov45State *, Ov45Input *);
#endif
