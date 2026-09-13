#include "to42_overlay_45_thumb_residual_35_private.h"
extern char *ov45_02254EF0;
void ov45_0222FE84(int, int, int, int, const char *, const void *);
void ov45_0222FE84(int a0, int a1, int a2, int a3, const char *name, const void *src) {
    if (strcmp(name, ov45_02254EF0) == 0) {
        memcpy(_022577C0 + 0x134, src, 0x50);
        if (_022577C0[0x130] != 0) {
            _022577C0[0x130] = 0;
        }
    }
}
