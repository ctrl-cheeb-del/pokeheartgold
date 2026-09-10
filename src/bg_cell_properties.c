#include "bg_cell_internal.h"

u16 *sub_02019B08(UnkStruct_0201956C *mgr, int index) {
    return mgr->cells[index].data;
}

u8 sub_02019B10(UnkStruct_0201956C *mgr, int index) {
    return mgr->cells[index].bgId;
}

void sub_02019B1C(UnkStruct_0201956C *mgr, int index, s8 *x, s8 *y) {
    if (x != NULL) {
        *x = mgr->cells[index].x;
    }
    if (y != NULL) {
        *y = mgr->cells[index].y;
    }
}

void sub_02019B44(UnkStruct_0201956C *mgr, int index, u16 *width, u16 *height) {
    if (width != NULL) {
        *width = mgr->cells[index].width;
    }
    if (height != NULL) {
        *height = mgr->cells[index].height;
    }
}

void sub_02019B70(UnkStruct_0201956C *mgr, int index, s8 left, s8 top, s8 right, s8 bottom) {
    mgr->cells[index].left = left;
    mgr->cells[index].top = top;
    mgr->cells[index].right = right;
    mgr->cells[index].bottom = bottom;
}

void sub_02019BA0(BgConfig *bgConfig, u8 bgId) {
}
