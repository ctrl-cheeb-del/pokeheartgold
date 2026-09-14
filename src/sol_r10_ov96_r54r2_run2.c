#include "sol_r10_ov96_r54r2_private.h"

BOOL ov96_021F2A84(Ov96R54Object (*objects)[3], int group) {
    int i;

    for (i = 0; i < 3; i++) {
        if (objects[group][i].completion != 0) {
            return FALSE;
        }
    }
    return TRUE;
}
