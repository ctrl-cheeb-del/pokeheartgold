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

void ov52_021E8CBC(void *p, int on) {
    const volatile u16 *a = _021E94AC;
    if (on == 0) {
        Sprite_SetAnimCtrlSeq(PTR(p, 0), a[2] + 1);
    } else {
        Sprite_SetAnimCtrlSeq(PTR(p, 0), a[2]);
    }
}

void ov52_021E8CDC(void *p, int on) {
    if (on == 1) {
        Sprite_SetAnimCtrlSeq(PTR(p, 0), 1);
    } else {
        Sprite_SetAnimCtrlSeq(PTR(p, 0), 0);
    }
}

int ov52_021E8CF4(void *d, int ret) {
    ov52_021E8BDC(d);
    ov52_021E925C((u8 *)d + 0x274, 0, 0x000e0c0f, d);
    ov52_021E9260(d);
    ov52_021E9218(d);
    ov52_021E9158((u8 *)d + 0x2c4, (u8 *)d + 0x432d, (u8 *)d + 0x4382, 1);
    return ret;
}

void ov52_021E8D3C(void *d) {
    ov52_021E8BD8();
    ov52_021E9218(d);
    ov52_021E9158((u8 *)d + 0x2c4, (u8 *)d + 0x432d, (u8 *)d + 0x4382, 0);
}

void ov52_021E8D64(void *bg, void *prompt) {
    PromptTemplate t;
    t.bg = bg;
    t.a = 0;
    t.b = 0xb4;
    t.c = 8;
    t.d = 0x19;
    t.e = 6;
    YesNoPrompt_InitFromTemplate(prompt, &t);
}

int ov52_021E8D8C(void *d, int ret) {
    if (ov52_021E92E8(U32(d, 0x38))) {
        ov52_021E8D64(PTR(d, 0), PTR(d, 0x5c9c));
        ov52_021E9488(d, 1);
        U32(d, 0x30c) = 3;
    }
    ov52_021E8D3C(d);
    return ret;
}
