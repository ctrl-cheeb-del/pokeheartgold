#include "overlay59_apricorn_ui_r8_private.h"

#define U8(w, off)  (*(u8 *)((u8 *)(w) + (off)))
#define U16(w, off) (*(u16 *)((u8 *)(w) + (off)))
#define U32(w, off) (*(u32 *)((u8 *)(w) + (off)))
#define PTR(w, off) (*(void **)((u8 *)(w) + (off)))

BOOL ov59_0223A678(Ov59R8Work *work) {
    u32 keys;
    switch (U8(work, 0x49)) {
    case 0:
        keys = gSystem.newKeys;
        if (keys & 0x10) {
            ov59_0223A7FC(work, 0);
            return TRUE;
        }
        if ((keys & 0x40) && U8(work, 0x4A) != 0) {
            U8(work, 0x4C) = 0;
            U8(work, 0x4A)
            --;
            return TRUE;
        }
        if ((keys & 0x80) && U8(work, 0x4A) < 3) {
            U8(work, 0x4C) = 0;
            U8(work, 0x4A)
            ++;
            return TRUE;
        }
        break;
    case 1:
        keys = gSystem.newKeys;
        if (keys & 0x20) {
            ov59_0223A7FC(work, 1);
            return TRUE;
        }
        if (keys & 0x10) {
            U8(work, 0x4C) = U8(work, 0x4A);
            U8(work, 0x4A) = 0;
            U8(work, 0x49)
            ++;
            return TRUE;
        }
        if ((keys & 0x40) && U8(work, 0x4A) != 0) {
            U8(work, 0x4B) = 0;
            U8(work, 0x4A)
            --;
            return TRUE;
        }
        if ((keys & 0x80) && U8(work, 0x4A) < 2) {
            U8(work, 0x4B) = 0;
            U8(work, 0x4A)
            ++;
            return TRUE;
        }
        break;
    case 2:
        keys = gSystem.newKeys;
        if (keys & 0x20) {
            U8(work, 0x4A) = U8(work, 0x4C);
            U8(work, 0x49)
            --;
            return TRUE;
        }
        if (U8(work, 0x44) == 2) {
            return FALSE;
        }
        if ((keys & 0x90) && U8(work, 0x44) != 0) {
            U8(work, 0x49)
            ++;
            return TRUE;
        }
        break;
    case 3:
        keys = gSystem.newKeys;
        if (keys & 0x60) {
            U8(work, 0x49)
            --;
            return TRUE;
        }
        break;
    }
    return FALSE;
}
