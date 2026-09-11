#include "overlay32_partial_internal.h"

void ov32_0225DCD4(u8 *work) {
    u8 *base = work;
    u32 offset = 0x298;
    u32 i = 0;
    u8 *current = base;
    do {
        Sprite_Delete(*(void **)(current + offset));
        i++;
        current += 4;
    } while (i < 4);
    SpriteTransfer_DeleteCharTransferTask(*(void **)(base + 0x288));
    SpriteTransfer_DeletePlttTransferTask(*(void **)(base + 0x28C));
}

void ov32_0225DD04(u8 *work) {
    u32 step = 0x1000;
    u32 offset = 0x298;
    u32 i = 0;
    do {
        Sprite_UpdateAnim(*(void **)(work + offset), step);
        i++;
        work += 4;
    } while (i < 4);
}
