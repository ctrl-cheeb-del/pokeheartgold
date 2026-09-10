#include "overlay80_palette_effect_internal.h"

Overlay80Effect *ov80_02239F48(void *owner) {
    Overlay80Effect *effect = Heap_Alloc(0x65, sizeof(Overlay80Effect));
    void *palette;
    MI_CpuFill8(effect, 0, sizeof(Overlay80Effect));
    effect->owner = owner;
    effect->paletteIndex = 2;
    palette = PaletteData_GetUnfadedBuf(owner, 0);
    MIi_CpuCopy16((u16 *)((u8 *)palette + 0xA0), (u16 *)effect->palettes, 0x60);
    effect->task = SysTask_CreateOnMainQueue(ov80_02239FA8, effect, 0x1368D);
    return effect;
}

void ov80_02239F94(Overlay80Effect *effect) {
    SysTask_Destroy(effect->task);
    Heap_Free(effect);
}

void ov80_02239FA8(void *task, void *data) {
    Overlay80Effect *effect = data;
    if (effect->timer < 8) {
        effect->timer++;
        return;
    }
    effect->timer = 0;
    PaletteData_LoadPalette(effect->owner,
        effect->palettes + effect->paletteIndex * 0x20,
        0,
        0x60,
        0x20);
    effect->paletteIndex++;
    if (effect->paletteIndex >= 3) {
        effect->paletteIndex = 0;
    }
}
