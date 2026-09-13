#include "r40_overlay_34_residual_6_private.h"

void ov34_0225E164(void *work) {
    int first;
    int second = -1;

    if (!FieldSystem_TaskIsRunning(PTR_AT(work, 0xC))) {
        first = ov34_0225DE94(work);
        second = ov34_0225E020(work);
        if (first == -1 && second == -1) {
            ov34_0225E0E4(work);
        }
    }
    ov34_0225E1C4(PTR_AT(work, 0x14), PTR_AT(work, 0x24), (u8 *)work + 0x1C8, second - 1, U32_AT(PTR_AT(work, 0x270), 0x348), (u8 *)work + 0x290);
}
