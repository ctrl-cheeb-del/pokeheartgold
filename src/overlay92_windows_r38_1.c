#include "overlay92_r38_private.h"

extern BOOL WindowIsInUse(const void *window);
extern void sub_0200E5D4(void *window, int mode);
extern void ClearWindowTilemapAndCopyToVram(void *window);
extern void RemoveWindow(void *window);
extern void GfGfxLoader_LoadScrnDataFromOpenNarc(void *narc, int member, void *bgConfig, int layer, int offset, int size, int compressed, int heapId);

void ov92_0225E360(void *work) {
    int i;
    u8 *window;

    i = 0;
    if ((int)U32AT(work, 4) > 0) {
        window = (u8 *)work + 0x1ff0;
        do {
            if (i != (int)U32AT(work, 0)) {
                if (WindowIsInUse(window) == TRUE) {
                    sub_0200E5D4(window, 1);
                    ClearWindowTilemapAndCopyToVram(window);
                    RemoveWindow(window);
                }
                window += 0x10;
            }
            i++;
        } while (i < (int)U32AT(work, 4));
    }
    GfGfxLoader_LoadScrnDataFromOpenNarc(PAT(PAT(work, 0x14), 0), 0x4e, PAT(PAT(work, 0x14), 0x10), 7, 0, 0, 0, 0x71);
}
