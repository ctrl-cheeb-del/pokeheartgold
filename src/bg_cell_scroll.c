#include "bg_cell_internal.h"

void sub_020198FC(UnkStruct_0201956C *mgr, int index, int dx, int dy, u8 timer) {
    BgCell *cell = &mgr->cells[index];
    cell->dx = dx;
    cell->dy = dy;
    cell->timer = timer;
    cell->state = 1;
    mgr->flag = 1;
}

void sub_02019934(UnkStruct_0201956C *mgr) {
    u32 i;
    if (mgr->flag) {
        mgr->flag = 0;
        for (i = 0; i < mgr->count; i++) {
            if (sub_02019978(mgr, i) == TRUE) {
                mgr->flag = 1;
            }
        }
    }
}

BOOL sub_02019978(UnkStruct_0201956C *mgr, int index) {
    if (mgr->cells[index].state == 0) {
        return FALSE;
    }
    sub_0201980C(mgr, index);
    mgr->cells[index].x += mgr->cells[index].dx;
    mgr->cells[index].y += mgr->cells[index].dy;
    sub_020197F4(mgr, index);
    mgr->cells[index].timer--;
    if (mgr->cells[index].timer == 0) {
        mgr->cells[index].state = 0;
        return FALSE;
    }
    return TRUE;
}

BOOL sub_020199E4(UnkStruct_0201956C *mgr, int index) {
    return mgr->cells[index].state;
}
