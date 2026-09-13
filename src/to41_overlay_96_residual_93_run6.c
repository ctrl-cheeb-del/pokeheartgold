#include "to41_overlay_96_residual_93_private.h"

void ov96_0220A254(void *course, u32 idx, u32 arg) {
    u32 local[4];
    u8 *p;
    u8 *b;
    p = PokeathlonCourse_GetHeapAllocPtr4(course);
    b = p + 0x50;
    ov96_021E6168(course, idx, arg, local);
    ov96_021EECB8(PTR(b + 0x70 * idx, 8), local, *(u16 *)(b + 0x1c4), PTR(p, 0x50), idx << 9, PTR(p, 0));
}
