#include "overlay96_exact_bank_internal.h"
#include "overlay96_exact_bank_prototypes.h"

int ov96_021FCD74(void *course) {
    void *p = PokeathlonCourse_GetHeapAllocPtr4(course);
    ov96_021EB5BC(*(u8 **)((u8 *)p + 0x18));
    return 1;
}
