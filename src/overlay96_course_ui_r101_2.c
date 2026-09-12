#include "overlay96_course_ui_r101_private.h"

void ov96_0220EAA4(void *work) {
    ov96_021EA894(PTR(work, 0x20));
    ov96_021E9C0C(PTR(work, 0x1c));
    SpriteSystem_FreeResourcesAndManager(PTR(work, 0xc), PTR(work, 0x10));
    SpriteSystem_Free(PTR(work, 0xc));
}
