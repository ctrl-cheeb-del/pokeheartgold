#include "sol_r12_ov01_windowfx6_private.h"

Ov01WindowEffect *ov01_021F0250(void) {
    Ov01WindowEffect *effect = Heap_Alloc(4, sizeof(Ov01WindowEffect));

    memset(effect, 0, sizeof(Ov01WindowEffect));
    G2_SetWnd0InsidePlane(0x1f, TRUE);
    G2_SetWnd1InsidePlane(0x1f, TRUE);
    G2_SetWndOutsidePlane(0, FALSE);
    return effect;
}
