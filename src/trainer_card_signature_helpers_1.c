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

void ov52_021E837C(void *bg) {
    GF_RunVramTransferTasks();
    OamManager_ApplyAndResetBuffers();
    DoScheduledBgGpuUpdates(bg);
    *(u32 *)((u8 *)OS_IRQTable + 0x3ff8) |= 1;
}

void ov52_021E83A4(void) {
    Words40 b = ov52_021E9578;
    GfGfx_SetBanks(&b);
}
