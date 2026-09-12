#include "overlay18_filter_input_internal.h"

#define U8_AT(p, n)  (*(u8 *)((u8 *)(p) + (n)))
#define U16_AT(p, n) (*(u16 *)((u8 *)(p) + (n)))

typedef struct Ov18Flags5 {
    u8 value : 5;
    u8 : 3;
} Ov18Flags5;

int ov18_021F7D30(void *work, int *touched) {
    int ret = ov18_021F7B94(work, touched);
    if (ret != -1) {
        return ret;
    }
    if (System_GetTouchNew() == TRUE) {
        ret = TouchscreenHitbox_FindRectAtTouchNew(ov18_021FB804);
        if (ret == -1) {
            return -1;
        }
        *touched = 1;
        return ov18_021FB760[ret];
    }
    *touched = 0;
    if (gSystem.newAndRepeatedKeys & PAD_KEY_UP) {
        return 5;
    }
    if (gSystem.newAndRepeatedKeys & PAD_KEY_DOWN) {
        return 7;
    }
    if (gSystem.newAndRepeatedKeys & PAD_KEY_LEFT) {
        if (Pokedex_CheckMonCaughtFlag(**(Pokedex ***)work, U16_AT(work, 0x18A2))) {
            return 1;
        }
        return 0;
    }
    if (gSystem.newAndRepeatedKeys & PAD_KEY_RIGHT) {
        return 12;
    }
    if (gSystem.newKeys & PAD_BUTTON_A) {
        return 11;
    }
    return -1;
}

int ov18_021F7DCC(void *work, int *touched) {
    int ret;
    if (System_GetTouchNew() == TRUE) {
        ret = TouchscreenHitbox_FindRectAtTouchNew(ov18_021FB7E0);
        if (ret == -1) {
            return -1;
        }
        *touched = 1;
        return ov18_021FB7C0[ret];
    }
    *touched = 0;
    if (gSystem.newAndRepeatedKeys & PAD_KEY_UP) {
        if (((Ov18Flags5 *)((u8 *)work + 0x18C7))->value == 0) {
            return 0;
        }
        return 2;
    }
    if (gSystem.newAndRepeatedKeys & PAD_KEY_DOWN) {
        if (((Ov18Flags5 *)((u8 *)work + 0x18C7))->value == 0) {
            return 1;
        }
        return 3;
    }
    if (gSystem.newKeys & PAD_KEY_LEFT) {
        return 6;
    }
    if (gSystem.newKeys & PAD_KEY_RIGHT) {
        return 7;
    }
    if (gSystem.newKeys & 0x400) {
        return 4;
    }
    if (gSystem.newKeys & (PAD_BUTTON_A | PAD_BUTTON_B)) {
        return 5;
    }
    return -1;
}

int ov18_021F7E70(void *work, int *touched) {
    int ret = ov18_021F7B94(work, touched);
    if (ret != -1) {
        return ret;
    }
    if (System_GetTouchNew() == TRUE) {
        ret = TouchscreenHitbox_FindHitboxAtTouchNew(ov18_021FB630);
        if (ret == -1) {
            return -1;
        }
        *touched = 1;
        return 4;
    }
    *touched = 0;
    if (gSystem.newAndRepeatedKeys & PAD_KEY_LEFT) {
        return 2;
    }
    if (gSystem.newAndRepeatedKeys & PAD_KEY_RIGHT) {
        return 0;
    }
    if (gSystem.newKeys & PAD_BUTTON_A) {
        return 3;
    }
    return -1;
}
