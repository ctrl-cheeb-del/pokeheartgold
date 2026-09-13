#include "global.h"

int ov40_02230958(void *);
void PokepicManager_HandleLoadImgAndOrPltt(void *);
void SpriteSystem_DrawSprites(void *);
void SpriteSystem_TransferOam(void);
void *SysTask_CreateOnVBlankQueue(void (*)(void *, void *), void *, u32);
u32 ov40_02244AB0(void *, u32, u32, u16 *, void *);

void ov40_0222FBBC(void *, void *);
void ov40_0222FBF8(void *);
BOOL ov40_0222FC14(void *, u32, u32);

void ov40_0222FBBC(void *task, void *work) {
    if (*(void **)((u8 *)work + 0x1C) == NULL) {
        return;
    }
    if (ov40_02230958(work) == 1) {
        return;
    }
    if (*(u32 *)((u8 *)work + 0x524) == 1) {
        return;
    }
    *(u32 *)((u8 *)work + 0x524) = 1;
    PokepicManager_HandleLoadImgAndOrPltt(*(void **)((u8 *)work + 0x64));
    SpriteSystem_DrawSprites(*(void **)((u8 *)work + 0x1C));
    SpriteSystem_TransferOam();
    *(u32 *)((u8 *)work + 0x524) = 0;
}

void ov40_0222FBF8(void *work) {
    *(void **)((u8 *)work + 0x416C) = SysTask_CreateOnVBlankQueue(ov40_0222FBBC, work, 5);
}

BOOL ov40_0222FC14(void *p, u32 a1, u32 a2) {
    u32 result = ov40_02244AB0(*(void **)((u8 *)p + 0x830), a1, a2, (u16 *)((u8 *)p + 0x834), (u8 *)p + 0x836);
    return result > 1;
}
