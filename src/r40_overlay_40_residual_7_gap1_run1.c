#include "r40_overlay_40_residual_7_gap1_private.h"

u32 ov40_0222DB30(u8 *work, u32 kind) {
    Ov40ValueTable7 a = *(const Ov40ValueTable7 *)ov40_02244EB0;
    Ov40ValueTable7 b = *(const Ov40ValueTable7 *)ov40_02244E40;
    Ov40ValueTable7 c = *(const Ov40ValueTable7 *)ov40_02244ECC;
    Ov40ValueTable7 d = *(const Ov40ValueTable7 *)ov40_02244E78;
    u32 index = work[0x5C];

    switch (kind) {
    case 0:
        return a.values[index];
    case 1:
        return b.values[index];
    case 2:
        return c.values[index];
    case 3:
        return d.values[index];
    default:
        GF_AssertFail();
        return a.values[0];
    }
}

void ov40_0222DBEC(u8 *work) {
    void *paletteData = *(void **)(work + 0x28);
    void *spriteManager = *(void **)(work + 0x1C);
    void *openNarc = *(void **)(work + 0x14);
    u32 resource = *(u32 *)(work + 0x18);

    PaletteData_LoadNarc(paletteData, 0xBF, ov40_0222DB30(work, 3), 0x6D, 0, 0x120, 0);
    PaletteData_LoadNarc(paletteData, 0xBF, ov40_0222DB30(work, 3), 0x6D, 1, 0x120, 0);
    PaletteData_LoadNarc(paletteData, 0xBF, ov40_0222DB30(work, 0), 0x6D, 0, 0x20, 0xE0);
    PaletteData_LoadNarc(paletteData, 0xBF, ov40_0222DB30(work, 0), 0x6D, 1, 0x20, 0xE0);

    sub_0208763C(*(void **)(work + 0x6F0), work[0x5C]);
    sub_0208763C(*(void **)(work + 0x6F0), work[0x5C]);
    SpriteManager_UnloadPlttObjById(spriteManager, 0x270F);
    SpriteManager_UnloadPlttObjById(spriteManager, 0x2710);

    SpriteSystem_LoadPaletteBufferFromOpenNarc(paletteData, 2, resource, spriteManager, openNarc, ov40_0222DB30(work, 2), 0, 3, 1, 0x270F);
    SpriteSystem_LoadPaletteBufferFromOpenNarc(paletteData, 3, resource, spriteManager, openNarc, ov40_0222DB30(work, 2), 0, 3, 2, 0x2710);
}
