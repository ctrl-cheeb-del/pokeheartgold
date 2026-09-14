#include "bg_window.h"
#include "heap.h"
#include "overlay_65_residual_8_internal.h"
#include "sound_02004A44.h"

int ov65_0221E600(void *p) {
    int result = ov65_0221FC54(PTR(p, 0x180), (u8 *)p + 0x664, (u8 *)p + 0x670, (u8 *)p + 0x36c0, 1);

    switch (result) {
    case 1:
    case 3:
        PTR(p, 0x2220) = ov65_0221E558;
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

int ov65_0221E684(void *p) {
    Ov65CallbacksR8 *callbacks = p;
    int result = ov65_0221FC54(PTR(p, 0x180), (u8 *)p + 0x664, (u8 *)p + 0x670, (u8 *)p + 0x36c0, 1);

    switch (result) {
    case 1:
    case 3: {
        int i;
        callbacks->callback = ov65_0221E740;
        for (i = 0; i < 0x20; i++) {
            if (!sub_0202C2DC(PTR(p, 0x36a0), i)) {
                sub_0203A280(PTR(p, 4), U32(p, 0x3678), i, HEAP_ID_26, 0);
                break;
            }
        }
        if (i == 0x20) {
            ov65_0221E330(p, 0x3f);
            callbacks->callback = ov65_0221E600;
            return 0;
        }
        break;
    }
    case 2:
    case 4:
        callbacks->callback = ov65_0221E740;
        break;
    }
    return 0;
}
