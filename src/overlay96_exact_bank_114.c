#include "overlay96_exact_bank_internal.h"
#include "overlay96_exact_bank_prototypes.h"

void *ov96_02215DBC(void *course, int i) {
    u8 *p = PokeathlonCourse_GetHeapAllocPtr4(course);
    return *(void **)(p + i * 0xA8 + 0x1B8);
}
