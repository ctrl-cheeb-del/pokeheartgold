#ifndef TO45_OVERLAY96_R97_HEAD_PRIVATE_H
#define TO45_OVERLAY96_R97_HEAD_PRIVATE_H
#include <nitro/mi/memory.h>

#include "global.h"

typedef struct R97ItemR11 {
    u32 w[5];
    union {
        u32 raw;
        struct {
            u32 low : 8;
            u32 count : 8;
            u32 middle : 8;
            u32 state : 6;
            u32 kind : 2;
        } bits;
    } state;
    union {
        u32 raw;
        struct {
            u32 counter : 11;
            u32 middle : 11;
            u32 duration : 8;
            u32 kind : 2;
        } bits;
    } timer;
    union {
        u32 raw;
        struct {
            u32 count : 8;
            u32 active : 1;
            u32 rest : 23;
        } bits;
    } flags;
    u32 extra;
} R97ItemR11;

typedef struct R97ListR11 {
    u32 unused;
    void *context;
    R97ItemR11 item[3];
    u32 count : 32;
} R97ListR11;

void GF_AssertFail(void);
u32 ov96_0220CA28(R97ItemR11 *item);
u32 ov96_0220CAC4(R97ItemR11 *item);
u32 ov96_0220CBC0(R97ItemR11 *item);
u32 ov96_0220CBEC(R97ItemR11 *item);
u32 ov96_0220CC18(R97ItemR11 *item);
void ov96_0220CF50(R97ItemR11 *item, u32 value, void *context);
void ov96_0220D200(void *state, u32 index, void *context);
void ov96_0220D07C(R97ItemR11 *item);
void ov96_0220D2AC(void *state, u32 counter, u8 kind);
u32 ov96_0220CD00(R97ItemR11 *item);
void ov96_0220D0F8(R97ItemR11 *item);
void ov96_021E8228(void *course, u8 kind, u8 state, u8 event, u32 value);
void ov96_0220CD84(R97ItemR11 *item, u32 value);
u32 ov96_0220CCBC(R97ItemR11 *item);
u32 ov96_0220CC38(R97ItemR11 *item);
void ov96_0220CE04(R97ItemR11 *item, u32 value);
u32 MTRandom(void);

void ov96_0220C9A0(R97ListR11 *list);
void ov96_0220C9CC(R97ListR11 *list);
void ov96_0220C9F4(R97ItemR11 *item, u32 index, void *context);

#endif
