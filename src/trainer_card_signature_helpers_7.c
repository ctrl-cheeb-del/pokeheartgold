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

void ov52_021E9218(void *d) {
    (void)d;
}

void ov52_021E921C(u16 *angle) {
    u16 color;
    s32 v;
    *angle += 20;
    if (*angle > 360) {
        *angle = 0;
    }
    v = GF_SinDeg(*angle) * 10 / 4096;
    color = ((v + 15) << 5) | 29;
    GX_LoadOBJPltt(&color, 0x18, 2);
}

void ov52_021E925C(void *a, int b, u32 c, void *d) {
    (void)a;
    (void)b;
    (void)c;
    (void)d;
}
