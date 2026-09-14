#ifndef TO45_OVERLAY41_R35_PRIVATE_H
#define TO45_OVERLAY41_R35_PRIVATE_H

#include "global.h"

#include "touchscreen.h"

typedef struct Ov41R35Node {
    u32 field00;
    u32 field04;
    struct Ov41R35Node *next;
} Ov41R35Node;

typedef struct Ov41R35Config {
    void *resource;
    u32 field04;
    u32 field08;
    u32 field0C;
    u32 field10;
    u32 field14;
    u32 field18;
    u32 field1C;
    u32 field20;
    u32 field24;
    u32 field28;
    u32 field2C;
} Ov41R35Config;

extern Ov41R35Node *ov41_02248A94(void *);
extern BOOL ov41_02249AA8(Ov41R35Node *, int, int, int);
extern void ov41_02249C7C(void *, const Ov41R35Config *);
extern void ov41_02249DB4(void *, const Ov41R35Config *, int, int, int, int);

BOOL ov41_0224883C(void *, u32, u32);
Ov41R35Node *ov41_02248858(void *, int, int, int);
void ov41_0224888C(u8 *, int);

#endif
