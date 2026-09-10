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

void ov52_021E8B94(void *d) {
    int i = 0;
    u8 *w = (u8 *)d + 0x274;
    for (; i < 5; i++, w += 0x10) {
        RemoveWindow(w);
    }
    RemoveWindow((u8 *)d + 0x2f4);
    RemoveWindow((u8 *)d + 0x2e4);
    RemoveWindow((u8 *)d + 0x2c4);
    RemoveWindow((u8 *)d + 0x2d4);
}

void ov52_021E8BD8(void) {
}
