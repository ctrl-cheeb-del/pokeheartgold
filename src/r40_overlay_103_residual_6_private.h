#ifndef SOL_R40_OV103_R6_PRIVATE_H
#define SOL_R40_OV103_R6_PRIVATE_H
#include "global.h"

typedef struct Ov103Context6 {
    u8 pad000[0x27C];
    void *mail[20];
    u8 pad2CC[0x2CC - 0x2CC];
    u8 order[20];
    u16 count;
    u16 page;
} Ov103Context6;

typedef struct Ov103Work6 {
    u32 unk00;
    void *mailbox;
    u32 unk08;
    Ov103Context6 *context;
} Ov103Work6;

void *Mailbox_AllocAndFetchMailI(void *, u32, u32, u32);
u32 Mail_TypeIsValid(void *);
void ov103_021ED00C(Ov103Work6 *);
#endif
