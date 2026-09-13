#include "overlay108_safari_decor_r2_private.h"

void ov108_021E9CD0(void *p) {
    int i = 0;
    u8 *q = p;
    u32 off = 0x31c;
    do {
        String_Delete(PTR(q, off));
        i++;
        q += 4;
    } while (i < 4);
    String_Delete(PTR(p, 0x330));
    String_Delete(PTR(p, 0x32c));
    String_Delete(PTR(p, 0x318));
    String_Delete(PTR(p, 0x314));
    MessageFormat_Delete(PTR(p, 0x310));
    DestroyMsgData(PTR(p, 0x30c));
    FontID_Release(4);
}
