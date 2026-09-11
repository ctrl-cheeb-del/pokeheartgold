#include "overlay57_vram_helpers_private.h"

void ov57_022390F4(void *work) {
    TouchscreenListMenuSpawner_Destroy(R20_PTR(work, 0x174));
    SpriteSystem_FreeResourcesAndManager(R20_PTR(work, 8), R20_PTR(work, 0xc));
    SpriteSystem_Free(R20_PTR(work, 8));
}
