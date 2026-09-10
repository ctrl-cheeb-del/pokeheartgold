#include "brightness_transition_internal.h"

void sub_02010E64(ScanlineBufferController *ctl, int mode, int screen, u32 heapId) {
    int i;
    switch (mode) {
    case 0:
    case 1:
        ctl->buffer = Heap_Alloc(heapId, 0x604);
        ctl->count = 1;
        ctl->screen = screen;
        *(s32 *)((u8 *)ctl->buffer + 0x600) = mode;
        break;
    case 2:
        ctl->buffer = Heap_Alloc(heapId, 0xc08);
        ctl->count = 2;
        ctl->screen = screen;
        for (i = 0; i < 2; i++) {
            *(s32 *)((u8 *)ctl->buffer + i * 0x604 + 0x600) = i;
        }
        break;
    }
}
