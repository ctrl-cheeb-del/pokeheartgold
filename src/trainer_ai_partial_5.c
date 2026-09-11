#include "global.h"

typedef struct AIState {
    u8 data[0x3200];
} AIState;
void ov10_0221EF24(AIState *, int);
u32 ov10_0221EEF0(AIState *);
u32 ov10_0221EF10(AIState *, int);

void ov10_0221EE28(void *, AIState *, u32);
void ov10_0221EC08(void *, AIState *);
void ov10_0221EC28(void *, AIState *);
void ov10_0221EB8C(void *, AIState *);
void ov10_0221D60C(void *, AIState *);
void ov10_0221D644(void *, AIState *);
void ov10_0221E0EC(void *, AIState *);
u32 ov10_0221EF34(AIState *, u8);
void ov10_0221DDF0(void *, AIState *);
void ov10_0221EB18(void *, AIState *);
void ov10_0221EA44(void *, AIState *);
void ov10_0221EAC8(void *, AIState *);
void ov10_0221CB64(void *, AIState *);
void ov10_0221D068(void *, AIState *);
void ov10_0221DDCC(void *, AIState *);
void ov10_0221DDE8(void);
void ov10_0221DDEC(void);
void ov10_0221EB00(u8 *, AIState *);
void ov10_0221EEF0_proto(void);
void ov10_0221EF24_proto(void);
void ov10_0221C878(void *, AIState *);
void ov10_0221C8A8(void *, AIState *);
void ov10_0221C8D8(void *, AIState *);
void ov10_0221C908(void *, AIState *);
void ov10_0221C938(void *, AIState *);
void ov10_0221C968(void *, AIState *);
void ov10_0221C998(void *, AIState *);
void ov10_0221C9C8(void *, AIState *);
void ov10_0221CEA4(void *, AIState *);
void ov10_0221CED4(void *, AIState *);
void ov10_0221DEF0(void *, AIState *);
void ov10_0221CD10(void *, AIState *);
void ov10_0221D084(void *, AIState *);
void ov10_0221E178(void *, AIState *);
void ov10_0221EB4C(void *, AIState *);
void ov10_0221EB6C(void *, AIState *);

void ov10_0221D60C(void *x, AIState *p) {
    u32 a, b, i;
    (void)x;
    ov10_0221EF24(p, 1);
    a = ov10_0221EEF0(p);
    b = ov10_0221EEF0(p);
    i = *(u16 *)&p->data[0x356];
    if (a == *(u16 *)&p->data[0x3de + i * 16]) {
        ov10_0221EF24(p, b);
    }
}

void ov10_0221D644(void *x, AIState *p) {
    u32 a, b, i;
    (void)x;
    ov10_0221EF24(p, 1);
    a = ov10_0221EEF0(p);
    b = ov10_0221EEF0(p);
    i = *(u16 *)&p->data[0x356];
    if (a != *(u16 *)&p->data[0x3de + i * 16]) {
        ov10_0221EF24(p, b);
    }
}
