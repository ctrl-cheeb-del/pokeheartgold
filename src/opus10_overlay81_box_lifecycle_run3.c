#include "opus10_overlay81_box_lifecycle_private.h"

BOOL ov81_0223DD60(void *man, u32 *state);
BOOL ov81_0223DEA8(void *man, u32 *state);
BOOL ov81_0223E234(void *man, u32 *state);
BOOL ov81_0223E318(u8 *p);
BOOL ov81_0223E520(u8 *p);
void ov81_0223E5B4(u8 *p);

void ov81_0223E87C(u8 *p) {
    int i;
    u8 *q;

    i = 0;
    if (i < p[0x12]) {
        q = p;
        do {
            PTR(q, 0x360) = ov81_022412C4(p, i);
            ov81_02242EB8(PTR(q, 0x360), 1);
            i++;
            q += 4;
        } while (i < p[0x12]);
    }
}
