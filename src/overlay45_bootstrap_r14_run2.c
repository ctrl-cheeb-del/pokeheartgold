#include "config.h"
#include "overlay45_bootstrap_r14_internal.h"

void ov45_0222A0F0(void *w) {
    u32 vals[2];
    int i;
    u8 *walker;
    void *x;
    ov45_0222AB0C((u8 *)w + 0x128, vals);
    x = sub_020318E8(PTR(w, 0));
    sub_020318FC(x, vals[0]);
    sub_02031900(x, vals[1]);
    ov45_0222BCD8((u8 *)w + 0x508);
    ov45_0222C994((u8 *)w + 0x3e4);
    ov45_0222EE80();
    ov45_0222D890(PTR(w, 4));
    i = 0;
    walker = w;
    do {
        Heap_Free(PTR(walker, 0xe8));
        i++;
        walker += 4;
    } while (i < 4);
    ov45_0222E688();
    Heap_Free(w);
}
