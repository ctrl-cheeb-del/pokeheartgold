#include "overlay96_ui_resources_57_private.h"

#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))

void ov96_021F3E60(void *w) {
    u32 ids[2];
    u32 *p = ids;
    int i;
    ids[0] = ov96_0221BFF4[2];
    ids[1] = ov96_0221BFF4[3];
    for (i = 0; i < 2; i++) {
        ov96_021EB2BC(w, 0x5d, 9, *p, 2);
        ov96_021EB2F4(w, 0x5d, 6, *p, 2, 1);
        ov96_021EB334(w, 0x5d, 0xa, *p);
        ov96_021EB36C(w, 0x5d, 0xa, *p);
        p++;
    }
}
