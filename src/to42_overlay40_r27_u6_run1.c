#include "to42_overlay40_r27_u6_private.h"

int ov40_022319A4(void *p);
int ov40_02231C78(void *p);
int ov40_02231EA4(void *p);
int ov40_02232094(void *p);
int ov40_02232288(void *p);
int ov40_022322E0(void *p);
int ov40_02232470(void *p);

void ov40_022318C8(void *task, void *arg) {
    s16 x;
    s16 y;
    void *w = arg;

    switch (BYTE(w, 0x1D)) {
    case 0:
        HALF(w, 8) = (SHALF(w, 4) - SHALF(w, 0)) / BYTE(w, 0x1C);
        HALF(w, 0xA) = (SHALF(w, 6) - SHALF(w, 2)) / BYTE(w, 0x1C);
        BYTE(w, 0x1D)
        ++;
    case 1:
        ov40_0222D294(PTR(w, 0x20), &x, &y);
        BYTE(w, 0x1C)
        --;
        if (BYTE(w, 0x1C) == 0) {
            x = SHALF(w, 4);
            y = SHALF(w, 6);
            BYTE(w, 0x1D)
            ++;
        } else {
            x = x + SHALF(w, 8);
            y = y + SHALF(w, 0xA);
        }
        if (PTR(w, 0x28) != NULL) {
            sub_020878B8(PTR(w, 0x28), x + 0x10, y);
            if (BYTE(w, 0x1C) == 2) {
                WORD(PTR(w, 0x30), 0) = 1;
            }
        }
        ov40_0222D288(PTR(w, 0x20), x, y);
        sub_020136B4(PTR(w, 0x24), 0x24, 0x24 - 0x2C);
        WORD(PTR(w, 0x2C), 0) = 1;
        break;
    default:
        Heap_Free(w);
        SysTask_Destroy(task);
        break;
    }
}
