#include "ov99_wave41_private.h"
typedef struct Ov99Record {
    u16 a, b, c, d;
    u8 rest[36];
} Ov99Record;
typedef struct Ov99Bits {
    u8 pad[8];
    u32 value : 9;
} Ov99Bits;

u32 ov99_021E6840(void *mgr) {
    R99 *w = OverlayManager_GetData(mgr);
    ov99_021E7060(P(w, 0));
    ov98_0221E684(P(w, 0x14), w + 0x18, 0x43);
    ov98_0221EB84(P(w, 0x10), 15);
    ov99_021E6A70(w);
    ov98_0221F0EC();
    OverlayManager_FreeData(mgr);
    Heap_Destroy(0x84);
    UnloadOverlayByID((u32)&SDK_OVERLAY_OVY_98_ID);
    return 1;
}
