#include "overlay18_filter_input_internal.h"

#define U8_AT(p, n)  (*(u8 *)((u8 *)(p) + (n)))
#define U16_AT(p, n) (*(u16 *)((u8 *)(p) + (n)))

typedef struct Ov18Flags5 {
    u8 value : 5;
    u8 : 3;
} Ov18Flags5;

int ov18_021F7B94(void *work, int *touched) {
    int hit;
    u32 coords[2];

    if (System_GetTouchNew() == TRUE) {
        hit = TouchscreenHitbox_FindRectAtTouchNew(ov18_021FB704);
        if (hit == -1) {
            return -1;
        }
        System_GetTouchNewCoords(&coords[1], &coords[0]);
        hit = ov18_021FB698[hit];
        if (hit == 1 && !Pokedex_CheckMonCaughtFlag(**(Pokedex ***)work, U16_AT(work, 0x18A2))) {
            return -1;
        }
        *touched = 1;
        return hit;
    }
    if (gSystem.newKeys & PAD_BUTTON_B) {
        *touched = 0;
        return 3;
    }
    return -1;
}

int ov18_021F7C14(void *work, int *touched) {
    int ret = ov18_021F7B94(work, touched);
    if (ret != -1) {
        return ret;
    }
    if (System_GetTouchNew() == TRUE) {
        ret = TouchscreenHitbox_FindHitboxAtTouchNew(ov18_021FB934);
        if (ret == -1) {
            return -1;
        }
        *touched = 1;
        return ov18_021FB904[ret];
    }
    *touched = 0;
    if (gSystem.newAndRepeatedKeys & PAD_KEY_UP) {
        return 5;
    }
    if (gSystem.newAndRepeatedKeys & PAD_KEY_DOWN) {
        return 7;
    }
    if (gSystem.newKeys & PAD_BUTTON_A) {
        if ((s8)U8_AT(work, 0x18C9) == 0) {
            return 14;
        }
        if ((s8)U8_AT(work, 0x18C9) == 1) {
            return 15;
        }
        return 13;
    }
    if (gSystem.newKeys & PAD_BUTTON_SELECT) {
        if ((s8)U8_AT(work, 0x18C8) == 0) {
            return 12;
        }
        return 11;
    }
    if ((s8)U8_AT(work, 0x18C8) == 0) {
        if (gSystem.newKeys & PAD_BUTTON_R) {
            return 12;
        }
    } else if (gSystem.newKeys & PAD_BUTTON_L) {
        return 11;
    }
    if (gSystem.newAndRepeatedKeys & PAD_KEY_LEFT) {
        return 16;
    }
    if (gSystem.newAndRepeatedKeys & PAD_KEY_RIGHT) {
        if (Pokedex_CheckMonCaughtFlag(**(Pokedex ***)work, U16_AT(work, 0x18A2))) {
            return 1;
        }
        return 2;
    }
    return -1;
}
