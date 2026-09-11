#include "overlay96_exact_bank_internal.h"
#include "overlay96_exact_bank_prototypes.h"

int ov96_02209738(void *course) {
    void *p = PokeathlonCourse_GetHeapAllocPtr4(course);
    SpriteSystem_DrawSprites(*(void **)((u8 *)p + 0xc));
    return 1;
}
