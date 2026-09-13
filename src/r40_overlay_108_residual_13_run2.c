#include "r40_overlay_108_residual_13_private.h"

void ov108_021E7B74(SafariAreaCustomizer *work, void *narc, u32 index, int member) {
    Ov108CharData *data;
    void *allocation = GfGfxLoader_GetCharDataFromOpenNarc(narc, member + 0x12, FALSE, &data, work->heapId);
    BG_LoadCharTilesData(work->bgConfig, 5, data->raw, 0x1000, index * 0x40 + 1);
    Heap_Free(allocation);
}

void ov108_021E7BB4(SafariAreaCustomizer *work, u32 index, int member) {
    void *narc = NARC_New(0xA6, work->heapId);

    if (index >= 6) {
        int i;
        u8 *entry;
        for (i = 0, entry = (u8 *)work; i < 6; i++, entry += 0x7A) {
            ov108_021E7B74(work, narc, (u8)i, entry[0x1C]);
        }
    } else {
        ov108_021E7B74(work, narc, index, member);
    }
    NARC_Delete(narc);
}
