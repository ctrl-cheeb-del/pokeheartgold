#include "overlay83_summary_display_r20_private.h"

void ov83_02242814(u8 *work, int value) {
    ov83_02241E18(work);
    ov83_022421E0(work, value);
    ov83_02247668(*(void **)(work + 0x780), *(void **)(work + 0x808), *(u16 *)(work + 0x80C), *(void **)(work + 0x814));
}
