#include "overlay80_tile_blink_internal.h"

void ov80_022385B0(TileBlinkManager *manager) {
    ov80_022385C4(manager->task);
    Heap_Free(manager);
}

void ov80_022385C4(TileBlinkTask *task) {
    SysTask_Destroy(task->task);
    Heap_Free(task);
}

u32 ov80_022385D8(u32 value) {
    switch (value) {
    case 2:
        return 0x73;
    case 3:
        return 0x77;
    case 4:
        return 0x87;
    case 5:
        return 0x7B;
    case 6:
        return 0x8F;
    case 1:
        return 0x71;
    default:
        return value;
    }
}

u32 ov80_02238610(u32 value) {
    switch (value) {
    case 2:
        return 0x66;
    case 3:
        return 0x68;
    case 4:
        return 0x6C;
    case 5:
        return 0x6A;
    case 6:
        return 0x6E;
    case 1:
        return 0x64;
    default:
        return value;
    }
}
