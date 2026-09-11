#include "overlay34_remaining_internal.h"

void ov34_0225D5A0(void *task, Ov34State *p) {
    void *fs = *(void **)((u8 *)p + 0xC);
    void *x = *(void **)((u8 *)p + 0x14);
    if (*(void **)((u8 *)fs + 0x84) == NULL) {
        return;
    }
    switch (*(u32 *)p) {
    case 0:
    case 1:
        break;
    case 2:
        if (!FieldSystem_TaskIsRunning(fs)) {
            ov34_0225D558(p, x);
        }
        SpriteList_RenderAndAnimateSprites(*(void **)((u8 *)p + 0x28));
        break;
    case 3:
        ov01_021F6A9C(fs, 0, 0);
        *(u32 *)p = 4;
        break;
    case 4:
    case 5:
        break;
    }
}
