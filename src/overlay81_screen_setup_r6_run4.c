#include "overlay81_screen_setup_r6_private.h"

void ov81_02240E78(void *work) {
    PTR(work, 0x1c0) = Heap_Alloc(0x64, 0x3c);
    memset(PTR(work, 0x1c0), 0, 0x3c);
    PTR(PTR(work, 0x1c0), 0) = PTR(work, 0x3c0);
    PTR(PTR(work, 0x1c0), 4) = PTR(work, 0x1b8);
    U8(PTR(work, 0x1c0), 0x11) = 1;
    U8(PTR(work, 0x1c0), 0x12) = 1;
    U8(PTR(work, 0x1c0), 0x13) = U8(work, 0x12);
    U8(PTR(work, 0x1c0), 0x14) = U32(work, 0x468);
    U16(PTR(work, 0x1c0), 0x18) = 0;
    U32(PTR(work, 0x1c0), 0x1c) = SaveArray_IsNatDexEnabled(PTR(work, 0x1bc));
    U32(PTR(work, 0x1c0), 0x2c) = 0;
    U32(PTR(work, 0x1c0), 0x34) = 0;
    sub_02089D40(PTR(work, 0x1c0), _02243458);
    sub_0208AD34(PTR(work, 0x1c0), Save_PlayerData_GetProfile(PTR(work, 0x1bc)));
}
