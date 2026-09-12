#include "overlay59_apricorn_ui_r8_private.h"

#define U8(w, off)  (*(u8 *)((u8 *)(w) + (off)))
#define U16(w, off) (*(u16 *)((u8 *)(w) + (off)))
#define U32(w, off) (*(u32 *)((u8 *)(w) + (off)))
#define PTR(w, off) (*(void **)((u8 *)(w) + (off)))

void ov59_02239C70(Ov59R8Work *work) {
    int i;
    for (i = 0; i < 15; i++) {
        if (work->sprites[i] != NULL) {
            Sprite_Delete(work->sprites[i]);
        }
    }
}
