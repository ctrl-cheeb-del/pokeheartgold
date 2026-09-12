#include "overlay57_capsule_controls_r10_private.h"

int ov57_0223B620(void *w) {
    u32 keys;
    ov57_0223B12C(w);
    keys = U32(gSystem, 0x48);
    if (keys & 1) {
        if (U32(w, 0xd4) != 0xff) {
            PlaySE(0x5f2);
            return 4;
        }
        ov57_0223B948(w, 0);
        PlaySE(0x5e2);
        ov57_0223B90C(PTR(w, 0x440), U32(w, 0x260));
        return 6;
    }
    if (keys & 2) {
        if (U32(w, 0xd4) != 0xff) {
            PlaySE(0x5f2);
            return 4;
        }
        ov57_0223B948(w, 0);
        PlaySE(0x5dd);
        ov57_0223B90C(PTR(w, 0x444), U32(w, 0x264));
        return 7;
    }
    if (keys & 0xc00) {
        if (U32(w, 0xd4) != 0xff) {
            PlaySE(0x5f2);
            return 4;
        }
        PlaySE(0x5dd);
        ov57_0223B90C(PTR(w, 0x43c), 0);
        return 5;
    }
    return 4;
}
