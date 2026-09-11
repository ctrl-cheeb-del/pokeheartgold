#include "overlay96_exact_bank_internal.h"
#include "overlay96_exact_bank_prototypes.h"

int ov96_021E6F18(void *course) {
    PokeathlonCourse_ResetDataCopyArea(course);
    PokeathlonCourse_SetStateField07(course, 0x14);
    return 0;
}
