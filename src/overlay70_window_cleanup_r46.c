#include "global.h"

#include "overlay70_window_cleanup_r46_private.h"

#define CLEAN_WINDOWS(count)                                    \
    do {                                                        \
        int i;                                                  \
        for (i = 0; i < (count); i++) {                         \
            FillWindowPixelBuffer(&work->windows[i], 0x22);     \
            CopyWindowPixelsToVram_TextMode(&work->windows[i]); \
            RemoveWindow(&work->windows[i]);                    \
        }                                                       \
    } while (0)

#define CLEAR_BG_IF(expr, width)                                                                     \
    do {                                                                                             \
        if (expr) {                                                                                  \
            FillBgTilemapRect(work->bgConfig, 2, 5, 0x11 + ((width) == 0xe), 1, (width), 0xf, 0x10); \
            BgCommitTilemapBufferToVram(work->bgConfig, 2);                                          \
        }                                                                                            \
    } while (0)

#define REMOVE_WINDOWS(count)                \
    do {                                     \
        int i;                               \
        for (i = 0; i < (count); i++) {      \
            RemoveWindow(&work->windows[i]); \
        }                                    \
    } while (0)

void ov70_02241DB4(Ov70MenuWork *work, int mode) {
    s8 coords[2];

    sub_02019B1C(work->cellManager, 0, &coords[1], &coords[0]);
    switch (mode) {
    case 4:
        CLEAN_WINDOWS(9);
        CLEAR_BG_IF(coords[1] == 0x10, 0xf);
        RemoveWindow(&work->windows[14]);
        break;
    case 5:
        CLEAN_WINDOWS(4);
        CLEAR_BG_IF(coords[1] == 0x10, 0xf);
        RemoveWindow(&work->windows[14]);
        break;
    case 0:
        CLEAN_WINDOWS(5);
        CLEAR_BG_IF(coords[1] == 0x10, 0xf);
        RemoveWindow(&work->windows[14]);
        break;
    case 6:
        CLEAN_WINDOWS(9);
        CLEAR_BG_IF(coords[1] == 0x10, 0xf);
        RemoveWindow(&work->windows[14]);
        RemoveWindow(&work->windows[15]);
        break;
    case 3:
        CLEAN_WINDOWS(6);
        CLEAR_BG_IF(coords[1] == 0x10 || coords[1] == 0x11, 0xe);
        RemoveWindow(&work->windows[14]);
        break;
    case 1:
        REMOVE_WINDOWS(3);
        RemoveWindow(&work->windows[14]);
        break;
    case 2:
        REMOVE_WINDOWS(5);
        RemoveWindow(&work->windows[14]);
        break;
    }
}
