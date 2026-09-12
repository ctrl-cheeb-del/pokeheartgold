#include "overlay05_party_status_ui_private.h"
#define PTR(s, o) (*(void **)((s)->raw + (o)))
#define U8(s, o)  ((s)->raw[(o)])

void ov05_0221D890(Ov05R10 *s) {
    NARC *narc = NARC_New(NARC_a_1_0_4, (enum HeapID) * (u32 *)(PTR(s, 0) + 0x24));
    SpriteSystem_LoadCharResObjFromOpenNarc(PTR(s, 0x190), PTR(s, 0x194), narc, 5, 0, 1, 0xB808);
    SpriteSystem_LoadCellResObjFromOpenNarc(PTR(s, 0x190), PTR(s, 0x194), narc, 6, 0, 0xB808);
    SpriteSystem_LoadAnimResObjFromOpenNarc(PTR(s, 0x190), PTR(s, 0x194), narc, 7, 0, 0xB808);
    NARC_Delete(narc);
}

void ov05_0221D904(Ov05R10 *s) {
    ManagedSprite_SetDrawFlag(PTR(s, 0x1C8), 0);
    ManagedSprite_SetDrawFlag(PTR(s, 0x1CC), 0);
    if (*((u8 *)PTR(s, 0) + 0x2A) == 3) {
        ManagedSprite_SetPositionXY(PTR(s, 0x1C8), 0x80, 0x48);
        ManagedSprite_SetAnim(PTR(s, 0x1C8), 2);
        return;
    }
    if (ov05_0221CCF4() == 1) {
        if (*((u8 *)PTR(s, 0) + 0x2A) == 1) {
            ManagedSprite_SetPositionXY(PTR(s, 0x1C8), 0x30, 0x48);
            ManagedSprite_SetPositionXY(PTR(s, 0x1CC), 0xD0, 0x48);
        } else {
            ManagedSprite_SetPositionXY(PTR(s, 0x1C8), 0xD0, 0x48);
            ManagedSprite_SetPositionXY(PTR(s, 0x1CC), 0x30, 0x48);
        }
    } else {
        if (*((u8 *)PTR(s, 0) + 0x2A) == 1) {
            ManagedSprite_SetPositionXY(PTR(s, 0x1C8), 0xD0, 0x48);
            ManagedSprite_SetPositionXY(PTR(s, 0x1CC), 0x30, 0x48);
        } else {
            ManagedSprite_SetPositionXY(PTR(s, 0x1C8), 0x30, 0x48);
            ManagedSprite_SetPositionXY(PTR(s, 0x1CC), 0xD0, 0x48);
        }
    }
    ManagedSprite_SetAnim(PTR(s, 0x1C8), 0);
    ManagedSprite_SetAnim(PTR(s, 0x1CC), 1);
}
