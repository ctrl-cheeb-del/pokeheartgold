#include "to47_overlay87_private.h"

void ov87_021E6AE0(State *p) {
    *(void **)((u8 *)p + 0x390) = YesNoPrompt_Create(0x7a);
}
void ov87_021E6AF4(State *p) {
    PromptTemplate t;
    t.bg = *(void **)((u8 *)p + 0x58);
    t.bgId = 2;
    t.tileStart = 0x380;
    t.plttSlot = 9;
    t.x = 24;
    t.y = 8;
    t.shape = 0;
    YesNoPrompt_InitFromTemplate(*(void **)((u8 *)p + 0x390), &t);
}
void ov87_021E6B28(State *p) {
    YesNoPrompt_Destroy(*(void **)((u8 *)p + 0x390));
}
void ov87_021E6B38(State *p) {
    ov87_021E6C40();
    ov87_021E6C60(*(void **)((u8 *)p + 0x58));
    *(void **)((u8 *)p + 0x15c) = PaletteData_Init(0x7a);
    PaletteData_AllocBuffers(*(void **)((u8 *)p + 0x15c), 2, 0x200, 0x7a);
    PaletteData_AllocBuffers(*(void **)((u8 *)p + 0x15c), 0, 0x200, 0x7a);
    ov87_021E6DBC(p, 7);
    ov87_021E6E44();
    ov87_021E6E00(p, 6);
    ov87_021E6EB0(p, 1);
    ov87_021E6E78();
    ov87_021E6EF4(p, 0);
    GfGfx_EngineATogglePlanes(4, 0);
    GfGfx_EngineBTogglePlanes(1, 0);
}
void ov87_021E6BA8(State *p) {
    ov87_021E7AF8((u8 *)p + 0x16c);
}
void ov87_021E6BB8(void *p) {
    GfGfx_EngineATogglePlanes(0x1f, 0);
    GfGfx_EngineBTogglePlanes(0x1f, 0);
    FreeBgTilemapBuffer(p, 7);
    FreeBgTilemapBuffer(p, 6);
    FreeBgTilemapBuffer(p, 4);
    FreeBgTilemapBuffer(p, 1);
    FreeBgTilemapBuffer(p, 0);
    FreeBgTilemapBuffer(p, 2);
    Heap_Free(p);
}
void ov87_021E6C04(State *p) {
    volatile SharedIrqState *s;
    if (*(u32 *)((u8 *)p + 4) == 0) {
        void *q = *(void **)((u8 *)p + 0x15c);
        if (q != 0) {
            PaletteData_PushTransparentBuffers(q);
        }
        DoScheduledBgGpuUpdates(*(void **)((u8 *)p + 0x58));
        GF_RunVramTransferTasks();
        OamManager_ApplyAndResetBuffers();
        s = (volatile SharedIrqState *)0x027E0000;
        s->irqCheck |= 1;
    }
}
void ov87_021E6C40(void) {
    Banks b = ov87_021E8330;
    GfGfx_SetBanks(&b);
}
