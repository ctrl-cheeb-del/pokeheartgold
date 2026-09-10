#include "trainer_card_signature_internal.h"
typedef struct {
    u32 v[4];
} Words16;
typedef struct {
    u32 v[10];
} Words40;
typedef struct {
    void *bg;
    u32 a, b, c;
    u8 d, e;
    u8 pad[2];
} PromptTemplate;
extern const Words16 ov52_021E94DC;
extern const Words40 ov52_021E9578;
extern int (*const ov52_021E96C0[])(void *);
extern const volatile u16 _021E94AC[];
extern const volatile u16 _021E94AC[];

int ov52_021E8EDC(void *d, int ret) {
    ov52_021E927C(d, 11);
    U32(d, 0x30c) = 5;
    ov52_021E8D3C(d);
    return ret;
}

int ov52_021E8EFC(void *d, int ret) {
    if (ov52_021E92E8(U32(d, 0x38))) {
        U32(d, 0x30c) = 6;
        ov52_021E8D64(PTR(d, 0), PTR(d, 0x5c9c));
    }
    ov52_021E8D3C(d);
    return ret;
}
