#include "overlay18_profile_animation_internal.h"

void ov18_021F5000(void *p, u16 angle) {
    ov18_021F4F98(p, 8, (u16)(-0x4000 - angle), 0x80, 0x68);
    ov18_021F4F98(p, 9, (u16)(0x4000 - angle), 0x80, 0x68);
    ov18_021F4FC8(p, 2, 8);
    ov18_021F4FC8(p, 4, 9);
}
