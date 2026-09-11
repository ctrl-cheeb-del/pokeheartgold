#include "overlay96_exact_bank_internal.h"
#include "overlay96_exact_bank_prototypes.h"

int ov96_021ED47C(void *course) {
    void *p = PokeathlonCourse_GetHeapAllocPtr4(course);
    SpriteSystem_DrawSprites(*(void **)((u8 *)p + 0x1C));
    return 1;
}
