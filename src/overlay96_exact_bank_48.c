#include "overlay96_exact_bank_internal.h"
#include "overlay96_exact_bank_prototypes.h"

u8 ov96_021EF2A0(void *p) {
    return PokeathlonCourse_GetField3D8_ForCurrentParticipant(p);
}

BOOL ov96_021EF2AC(void *course) {
    void *save = PokeathlonCourse_GetSaveData(course);
    void *flags = Save_VarsFlags_Get(save);
    return Save_VarsFlags_CheckFlagInArray(flags, 0xEF);
}
