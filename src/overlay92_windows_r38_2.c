#include "overlay92_r38_private.h"

extern BOOL WindowIsInUse(const void *window);
extern void sub_0200E5D4(void *window, int mode);
extern void ClearWindowTilemapAndCopyToVram(void *window);
extern void RemoveWindow(void *window);
extern void GfGfxLoader_LoadScrnDataFromOpenNarc(void *narc, int member, void *bgConfig, int layer, int offset, int size, int compressed, int heapId);

ManagedSprite *ov92_0225E7E4(void *work, u16 x, u16 y) {
    ManagedSpriteTemplate template;
    ManagedSprite *sprite;
    void *ctx = PAT(work, 0x14);
    void *system = PAT(ctx, 8);
    void *manager = PAT(ctx, 0xc);

    ov92_0225DDD8(&template, x, y, 1, 0, 0x232b);
    template.bgPriority = 0;
    template.drawPriority = 0;
    sprite = SpriteSystem_NewSprite(system, manager, &template);
    ManagedSprite_TickTwoFrames(sprite);
    return sprite;
}
