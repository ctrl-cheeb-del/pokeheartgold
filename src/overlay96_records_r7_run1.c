#include "overlay96_records_r7_private.h"

BOOL ov96_021E75E4(Ov96R7Work *w);

BOOL ov96_021E75E4(Ov96R7Work *w) {
    void *copy = PokeathlonCourse_GetDataCopyArea(w);
    int i;
    u8 *src;
    u32 size;
    void *desc;
    void *system;

    if (ov96_021E5F24(w) != 0) {
        GF_AssertFail();
        return FALSE;
    }
    src = w->d + 0x5e0;
    for (i = 0; i < 4; i++, src += 4) {
        size = PokeathlonCourse_GetUnkConstant4(w);
        memcpy((u8 *)ov96_021E8A20((u8 *)copy + 0x28) + i * size, src, size);
    }
    desc = ov96_021E9A14();
    system = PokeathlonCourse_GetSystem(w);
    return ov96_021E87B4(0x1e, (u8 *)copy + 0x28, desc, system);
}
