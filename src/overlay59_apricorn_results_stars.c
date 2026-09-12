#include "overlay59_apricorn_results_internal.h"

void ov59_0223BE18(void *work, void *entry) {
    s32 i;

    CalcMonPokeathlonStars((u8 *)entry + 0x16, OV59_RESULT_PTR(entry, 0), (u8 *)entry + 0x10, OV59_RESULT_PTR(work, 0));
    for (i = 0; i < 5; i++) {
        ov59_0223BD4C(work, entry, (u8)i);
    }
}
