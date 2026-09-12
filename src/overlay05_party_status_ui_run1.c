#include "overlay05_party_status_ui_private.h"
#define PTR(s, o) (*(void **)((s)->raw + (o)))
#define U8(s, o)  ((s)->raw[(o)])

void ov05_0221D318(Ov05R10 *s) {
    NARC *narc = NARC_New(NARC_a_0_0_8, (enum HeapID) * (u32 *)(PTR(s, 0) + 0x24));
    SpriteSystem_LoadCharResObjFromOpenNarc(PTR(s, 0x190), PTR(s, 0x194), narc, 0xD0, 1, 1, 0xB807);
    SpriteSystem_LoadPlttResObj(PTR(s, 0x190), PTR(s, 0x194), NARC_a_1_0_4, 8, 0, 2, 1, 0xB807);
    SpriteSystem_LoadCellResObjFromOpenNarc(PTR(s, 0x190), PTR(s, 0x194), narc, 0xCF, 1, 0xB807);
    SpriteSystem_LoadAnimResObjFromOpenNarc(PTR(s, 0x190), PTR(s, 0x194), narc, 0xD1, 1, 0xB807);
    NARC_Delete(narc);
}
