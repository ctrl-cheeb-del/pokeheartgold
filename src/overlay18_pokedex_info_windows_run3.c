#include "overlay18_pokedex_info_windows_internal.h"

u32 ov18_021F04C0(void *p, int idx) {
    int value = ((int *)PTR(p, 0x18FC))[idx];
    if (value == -2) {
        return *((s8 *)p + 0x18C8) == 0 ? 0x86 : 0x87;
    }
    BufferLandmarkName(PTR(p, 0x660), 0, MapHeader_GetMapSec(ov18_021E8AE0(p, idx)));
    return 0x85;
}
