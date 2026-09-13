#include "to42_overlay_45_thumb_residual_35_private.h"
void ov45_02230108(void);
void ov45_02230130(void);
void ov45_02230144(void *);
void ov45_02230108(void) {
    if (*(u32 *)(_022577C0 + 0x980) != 1) {
        GF_AssertFail();
    }
    *(u32 *)(_022577C0 + 0x980) = 2;
}
void ov45_02230130(void) {
    _022577C0[0x131] = 1;
}
void ov45_02230144(void *work) {
    memset((u8 *)work + 0x5b8, 0, 0xe4);
    *(u16 *)((u8 *)work + 0x69c) = 3;
}
