#include "r40_overlay_71_residual_32_private.h"
#include "sprite.h"

extern void ov71_0224A278(void *work);
extern void ov71_0224A3F0(void *work);
extern void ov71_0224A510(void *work);
extern BOOL Sprite_IsAnimated(Sprite *sprite);
extern void ov71_0224A5C4(void *work, void *sub);
extern void ov71_02247704(void *camera, int value);
extern BOOL ov71_0224A684(void *sub);
extern void PlaySE(int seqNo);
extern void BeginNormalPaletteFade(int, int, int, int, int, int, int);
extern BOOL IsPaletteFadeFinished(void);

BOOL ov71_0224A18C(void *work) {
    ov71_0224A278(work);
    ov71_0224A3F0(work);
    ov71_0224A510(work);
    BeginNormalPaletteFade(0, 1, 1, 0x7FFF, 8, 1, 0x39);
    return TRUE;
}

BOOL ov71_0224A1C4(void *work, u32 *state) {
    u8 *p = work;

    switch (*state) {
    case 0:
        if (IsPaletteFadeFinished()) {
            Sprite_SetAnimCtrlSeq(*(Sprite **)(p + 0x20), 3);
            Sprite_SetDrawFlag(*(Sprite **)(p + 0x20), TRUE);
            (*state)++;
        }
        break;
    case 1:
        if (!Sprite_IsAnimated(*(Sprite **)(p + 0x20))) {
            PlaySE(0x6AA);
            ov71_0224A5C4(work, p + 0x34);
            ov71_02247704(*(void **)(p + 0x2C), 1);
            (*state)++;
        }
        break;
    case 2:
        if (ov71_0224A684(p + 0x34)) {
            BeginNormalPaletteFade(0, 0, 0, 0x7FFF, 0x10, 1, 0x39);
            (*state)++;
        }
        break;
    case 3:
        if (IsPaletteFadeFinished()) {
            return TRUE;
        }
        break;
    }
    return FALSE;
}
