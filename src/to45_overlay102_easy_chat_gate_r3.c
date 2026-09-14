#include "global.h"

#include "system.h"

BOOL System_GetTouchHeld(void);
void PlaySE(u16 se);
void ov102_021E940C(void *p, u32 mode);
BOOL ov102_021E7A58(u8 *p);
void ov102_021E7AA4(u8 *p, int arg);
int ov102_021E7AB8(u8 *p, u32 action);
int ov102_021E7B18(u8 *p);

extern void (*const ov102_021EC5E8[])(u8 *p, int arg);

BOOL ov102_021E7A58(u8 *p) {
    if (*(u32 *)(p + 0x74) == 1) {
        if (System_GetTouchHeld()) {
            return FALSE;
        }
        if (gSystem.heldKeys != 0) {
            *(u32 *)(p + 0x38) = 4;
            *(u32 *)(p + 0x74) = 0;
            return FALSE;
        }
    } else {
        if (gSystem.heldKeys != 0) {
            return FALSE;
        }
        if (System_GetTouchHeld()) {
            *(u32 *)(p + 0x74) = 1;
            return FALSE;
        }
    }
    return FALSE;
}

void ov102_021E7AA4(u8 *p, int arg) {
    ov102_021EC5E8[*(u32 *)(p + 4)](p, arg);
}

int ov102_021E7AB8(u8 *p, u32 action) {
    switch (action) {
    case 2:
        PlaySE(0x5dc);
        return 2;
    case 1:
        PlaySE(0x5dc);
        return 1;
    case 0:
        PlaySE(0x5dc);
        *(u16 *)(p + 0x50) = 0;
        ov102_021E940C(*(void **)(p + 0x14), 9);
        return 4;
    case 3:
        PlaySE(0x5dc);
        ov102_021E940C(*(void **)(p + 0x14), 0xf);
        break;
    }
    return 0;
}

int ov102_021E7B18(u8 *p) {
    u16 keys = *(u16 *)(p + 0x30);

    if (keys & 2) {
        *(u16 *)(p + 0x4c) = 2;
        ov102_021E940C(*(void **)(p + 0x14), 0xf);
        return ov102_021E7AB8(p, 2);
    }
    if (keys & 1) {
        return ov102_021E7AB8(p, *(u16 *)(p + 0x4c));
    }
    if (keys & 8) {
        *(u16 *)(p + 0x4c) = 1;
        return ov102_021E7AB8(p, 3);
    }
    if (keys & 0x80) {
        if (*(u16 *)(p + 0x4c) == 2) {
            return 0;
        }
        (*(u16 *)(p + 0x4c))++;
        return ov102_021E7AB8(p, 3);
    }
    if (keys & 0x40) {
        if (*(u16 *)(p + 0x4c) == 0) {
            return 0;
        }
        (*(u16 *)(p + 0x4c))--;
        return ov102_021E7AB8(p, 3);
    }
    if (*(u32 *)(p + 4) == 0) {
        return 0;
    }
    if (keys & 0x30) {
        *(u16 *)(p + 0x4e) ^= 1;
        return ov102_021E7AB8(p, 3);
    }
    return 0;
}
