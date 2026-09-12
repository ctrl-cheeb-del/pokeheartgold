#include "overlay14_box_sprite_setup_private.h"

void ov14_021F396C(void *p, u32 index, u32 mode) {
    s16 pos[2];
    ov14_021F2F88(index, &pos[1], &pos[0], mode);
    ov14_021F395C(p, (s16)(pos[1] + 8), (s16)(pos[0] + 8));
}

void ov14_021F39A0(void *p, u32 index, u32 mode) {
    s16 pos[2];
    ov14_021F2F88(index, &pos[1], &pos[0], mode);
    ov14_021F395C(p, pos[1], (s16)(pos[0] + 4));
}
