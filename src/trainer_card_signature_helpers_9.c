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

void ov52_021E9424(void *p) {
    s8 *v = p;
    if (v[0] == 0 && v[1] == 0) {
        if (!IsSEPlaying(0x699)) {
            PlaySE(0x699);
        }
    }
    if (v[0] * v[2] < 0) {
        goto sound;
    }
    if (v[1] * v[3] >= 0) {
        goto done;
    }
sound:
    if (!IsSEPlaying(0x699)) {
        PlaySE(0x699);
    }
done:
    v[0] = v[2];
    v[1] = v[3];
    v[2] = 0;
    v[3] = 0;
}

void ov52_021E9488(void *d, int show) {
    if (show == 1) {
        Sprite_SetDrawFlag(PTR(d, 0x250), 0);
        return;
    }
    Sprite_SetDrawFlag(PTR(d, 0x250), 1);
}
