#include "overlay96_course_ui_r90_private.h"

void ov96_02208A4C(void *work) {
    AddWindow(OV96_R90_PTR(work, 8), (u8 *)work + 0xC, ov96_0221CBEC);
    BG_FillCharDataRange(OV96_R90_PTR(work, 8), 4, 0, 1, 0);
    LoadFontPal0(4, 0x1E0, OV96_R90_WORD(work, 0));
}

void ov96_02208A80(void **sprites, int value) {
    ov96_021EB52C(sprites[0], 1, value);
    ov96_021EB52C(sprites[2], 1, value);
    ov96_021EB52C(sprites[1], 1, value);
}

void *ov96_02208AA8(u32 heapId, int value) {
    void *work = Heap_Alloc(heapId, 0x55C);
    MI_CpuFill8(work, 0, 0x55C);
    OV96_R90_BYTE(work, 0x554) = value;
    OV96_R90_BYTE(work, 0x559) = 4 - value;
    OV96_R90_BYTE(work, 0x558) = OV96_R90_BYTE(work, 0x559);
    OV96_R90_BYTE(work, 0x557) = 6;
    OV96_R90_BYTE(work, 0x556) = OV96_R90_BYTE(work, 0x557);
    return work;
}
