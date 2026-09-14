#include "bg_window.h"
#include "heap.h"
#include "overlay_65_residual_8_internal.h"
#include "sound_02004A44.h"

int ov65_0221E354(void *p) {
    int result = ov65_0221FC54(PTR(p, 0x180), (u8 *)p + 0x664, (u8 *)p + 0x670, (u8 *)p + 0x36c0, 1);

    switch (result) {
    case 1:
    case 3:
        PTR(p, 0x2220) = ov65_0221E740;
        break;
    case 2:
    case 4:
        ov65_0221E330(p, 0x3f);
        PTR(p, 0x2220) = ov65_0221E600;
        break;
    }
    return 0;
}

int ov65_0221E3BC(void *p) {
    int result = ov65_0221FC54(PTR(p, 0x180), (u8 *)p + 0x664, (u8 *)p + 0x670, (u8 *)p + 0x36c0, 1);

    switch (result) {
    case 1:
    case 3:
        sub_020311AC(Save_Frontier_GetStatic(PTR(p, 4)), U32(p, 0x367c));
        sub_0202C338(PTR(p, 0x36a0), U32(p, 0x367c));
        sub_0203A280(PTR(p, 4), U32(p, 0x3678), 0x1f, 0x1a, 0);
        PTR(p, 0x2220) = ov65_0221E740;
        break;
    case 2:
    case 4:
        BufferPlayersName(PTR(p, 0x3680), 0, sub_02034818(U32(p, 0x3678)));
        ov65_0221E330(p, 0x40);
        PTR(p, 0x2220) = ov65_0221E354;
        break;
    }
    return 0;
}
