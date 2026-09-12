#include "overlay59_apricorn_ui_r8_private.h"

#define U8(w, off)  (*(u8 *)((u8 *)(w) + (off)))
#define U16(w, off) (*(u16 *)((u8 *)(w) + (off)))
#define U32(w, off) (*(u32 *)((u8 *)(w) + (off)))
#define PTR(w, off) (*(void **)((u8 *)(w) + (off)))

int ov59_02239EF8(Ov59R8Work *work) {
    int hit = 0;
    int result = ov59_0223A120(work, &hit);
    if (hit == 0) {
        result = ov59_0223A0B8(work);
    }
    return result;
}

int ov59_02239F18(Ov59R8Work *work) {
    int hit = 0;
    int result = ov59_0223A2D0(work, &hit);
    if (hit == 0) {
        result = ov59_0223A268(work);
    }
    return result;
}
