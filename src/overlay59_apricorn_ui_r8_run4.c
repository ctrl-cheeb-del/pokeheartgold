#include "overlay59_apricorn_ui_r8_private.h"

#define U8(w, off)  (*(u8 *)((u8 *)(w) + (off)))
#define U16(w, off) (*(u16 *)((u8 *)(w) + (off)))
#define U32(w, off) (*(u32 *)((u8 *)(w) + (off)))
#define PTR(w, off) (*(void **)((u8 *)(w) + (off)))

int ov59_0223A3B0(Ov59R8Work *work) {
    u32 keys = gSystem.newKeys;
    if (keys & 0xCF3) {
        U32(work, 0x40) = 0;
    }
    keys = gSystem.newKeys;
    if (keys & 2) {
        return ov59_0223A350(work, 8);
    }
    if (keys & 1) {
        return ov59_0223A350(work, ov59_02239EA8(work));
    }
    if (ov59_0223A678(work)) {
        PlaySE(0x5DC);
        ov59_022388C4(work);
        return 5;
    }
    return 5;
}

int ov59_0223A418(Ov59R8Work *work, int *hit) {
    int input = TouchscreenHitbox_FindHitboxAtTouchNew((const TouchscreenHitbox *)ov59_0223C924);
    if (input == -1 || input == 7) {
        return 5;
    }
    *hit = 1;
    U32(work, 0x40) = 1;
    U8(work, 0x4C) = 0;
    U8(work, 0x4B) = U8(work, 0x4C);
    U8(work, 0x4A) = 0;
    if (input == 8) {
        U8(work, 0x49) = 2;
    } else {
        U8(work, 0x49) = input % 2;
        U8(work, 0x4A) = input / 2;
    }
    return ov59_0223A350(work, input);
}
