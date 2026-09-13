#include "r40_overlay_108_residual_15_private.h"

void ov108_021E84F8(R40Ov108Sub15 *s, int index, int file) {
    void *obj = s->lists[0]->objects[index];
    ReplaceCharResObjFromNarc(s->managers[0], obj, 0xA6, file + 0x12, 0, s->heapId);
    SpriteTransfer_ReplaceCharData(obj);
}
