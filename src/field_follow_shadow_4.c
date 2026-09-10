#include "field_follow_shadow_internal.h"

void ov01_021FD9CC(u32 direction, VecFx32 *pos) {
    switch (direction) {
    case 0:
        pos->z += 0x2000;
        break;
    case 1:
        pos->z -= 0x2000;
        break;
    case 2:
        pos->x += 0x6000;
        break;
    case 3:
        pos->x -= 0x6000;
        break;
    }
}
