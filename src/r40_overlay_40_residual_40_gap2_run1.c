#include "r40_overlay_40_residual_40_gap2_private.h"

void ov40_0224355C(void *p) {
    u32 num;
    void *str;
    int i;
    SolGapEntry *entry;
    str = String_New(0x64, 0x6D);
    U32(p, 0x2C8) = 1;
    U32(p, 0x2CC) = 0;
    U32(p, 0x2D0) = 0;
    if (S32(p, 0x204) > 0) {
        i = 0;
        entry = p;
        do {
            if (entry->a == 0) {
                entry->a = 1;
                ManagedSprite_SetAnim(entry->sprite, ov40_02244054(entry->a, entry->code));
            }
            num = entry->a - 1;
            if (i != 0) {
                S64(p, 0x2CC) *= 10;
            }
            S64(p, 0x2CC) += num;
            String16_FormatInteger(str, num, 1, 1, 1);
            String_Cat(PTR(p, 0x2C0), str);
            i++;
            entry++;
        } while (i < S32(p, 0x204));
    }
    String_Delete(str);
    ov40_0224320C(p, 3);
}
