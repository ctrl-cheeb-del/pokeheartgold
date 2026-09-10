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

void ov52_021E8568(void *d) {
    int i;
    u8 *p;
    YesNoPrompt_Destroy(PTR(d, 0x5c9c));
    i = 0;
    p = d;
    for (; i < 5; i++, p += 4) {
        String_Delete(PTR(p, 0x18));
    }
    String_Delete(PTR(d, 0x34));
    String_Delete(PTR(d, 0x30));
    String_Delete(PTR(d, 0x2c));
}

void ov52_021E85A0(void *bg) {
    FreeBgTilemapBuffer(bg, 5);
    FreeBgTilemapBuffer(bg, 4);
    FreeBgTilemapBuffer(bg, 3);
    FreeBgTilemapBuffer(bg, 2);
    FreeBgTilemapBuffer(bg, 1);
    FreeBgTilemapBuffer(bg, 0);
    Heap_Free(bg);
}
