#include "overlay96_course_collision_r87_private.h"

void ov96_02206F1C(u8 *p, fx32 worldX, fx32 worldY, void **out, u8 *count) {
    int i;
    int x;
    int y;
    void **obj;
    for (i = 0; i < 20; i++) {
        out[i] = NULL;
    }
    x = worldX / FX32_ONE;
    y = worldY / FX32_ONE;
    *count = 0;
    obj = (void **)&p[0x61c];
    for (i = 0; i < 20; i++, p += 12, obj++) {
        int dx;
        int dy;
        if (*(void **)&p[0x37c] == NULL) {
            break;
        }
        dx = *(u16 *)&p[0x384] - x + 0x80;
        dy = *(u16 *)&p[0x386] - y + 0x60;
        if (dx >= -32 && dx <= 288 && dy >= -32 && dy <= 224) {
            out[(*count)++] = obj;
        }
    }
}
