#include "overlay05_party_status_ui_private.h"
#define PTR(s, o) (*(void **)((s)->raw + (o)))
#define U8(s, o)  ((s)->raw[(o)])

void ov05_0221D5DC(Ov05R10 *s) {
    PTR(s, 0xB44) = FontSystem_NewInit(8, *(u32 *)(PTR(s, 0) + 0x24));
    ov05_0221D530(s, 0, *(void **)(PTR(s, 0) + 0x14));
    ov05_0221D530(s, 2, *(void **)(PTR(s, 0) + 0x18));
    if (*((u8 *)PTR(s, 0) + 0x29) == 1) {
        ov05_0221D530(s, 1, *(void **)(PTR(s, 0) + 0x1C));
        ov05_0221D530(s, 3, *(void **)(PTR(s, 0) + 0x20));
    } else {
        ov05_0221D530(s, 1, *(void **)(PTR(s, 0) + 0x14));
        ov05_0221D530(s, 3, *(void **)(PTR(s, 0) + 0x18));
        TextOBJ_SetSpritesDrawFlag(PTR(s, 0xB4C), 0);
        TextOBJ_SetSpritesDrawFlag(PTR(s, 0xB54), 0);
    }
}

void ov05_0221D664(Ov05R10 *s, int index, int x, int y) {
    Ov05R10Layout *work = (Ov05R10Layout *)s;
    sub_020136B4(work->text[index], x + work->x[index], y + work->y[index]);
}

void ov05_0221D690(Ov05R10 *s) {
    u32 i;
    u8 *walker;
    if (*((u8 *)PTR(s, 0) + 0x28) != 0) {
        i = 0;
        walker = (u8 *)s;
        for (; i < 4; i++) {
            FontOAM_Delete(*(void **)(walker + 0xB48));
            walker += 4;
        }
        sub_020135AC(PTR(s, 0xB44));
    }
}
