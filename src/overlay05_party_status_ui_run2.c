#include "overlay05_party_status_ui_private.h"
#define PTR(s, o) (*(void **)((s)->raw + (o)))
#define U8(s, o)  ((s)->raw[(o)])

void ov05_0221D4D0(Ov05R10 *s) {
    u8 *root = PTR(s, 0);
    if (root[0x29] == 0) {
        ov05_0221D414(s, *(void **)(root + 4), 6, 0);
        ov05_0221D414(s, *(void **)(PTR(s, 0) + 8), 6, 6);
    } else {
        ov05_0221D414(s, *(void **)(root + 4), 3, 0);
        ov05_0221D414(s, *(void **)(PTR(s, 0) + 0xC), 3, 3);
        ov05_0221D414(s, *(void **)(PTR(s, 0) + 8), 3, 6);
        ov05_0221D414(s, *(void **)(PTR(s, 0) + 0x10), 3, 9);
    }
}
