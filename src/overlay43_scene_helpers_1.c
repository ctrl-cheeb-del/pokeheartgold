#include "overlay43_scene_helpers_private.h"

void ov43_0222B1FC(u8 *state, u8 *unused, u8 *work) {
    u16 *dims;
    ov43_0222A9F4(work, work + 0x64, 0);
    ScheduleWindowCopyToVram((Window *)(state + 8));
    dims = *(u16 **)(state + 0x1C);
    LoadRectToBgTilemapRect(*(void **)work, 2, dims + 6, 0, 0, (dims[0] >> 3) & 0xFF, (dims[1] >> 3) & 0xFF);
    ScheduleSetBgPosText(*(BgConfig **)work, 2, BG_POS_OP_SET_X, 0);
    ScheduleSetBgPosText(*(BgConfig **)work, 2, BG_POS_OP_SET_Y, 0);
    ov43_0222AD74(work, 1, 0);
    ov43_0222AD98(work, 1, 0);
    ov43_0222B3A4((u32 *)state, work);
    ScheduleBgTilemapBufferTransfer(*(void **)work, 2);
}

BOOL ov43_0222B278(u32 *selection, u32 *state, u8 *work) {
    BOOL moved = FALSE;
    if (gSystem.newKeys & 0xCF3) {
        *state = 0;
    }
    if (gSystem.newKeys & PAD_BUTTON_A) {
        ov43_0222B3C4(selection, work);
        PlaySE(0x5DD);
        return TRUE;
    }
    if (gSystem.newKeys & PAD_BUTTON_B) {
        PlaySE(0x5DD);
        *selection = 3;
        return TRUE;
    }
    if (gSystem.newAndRepeatedKeys & PAD_KEY_UP) {
        if (*selection != 0) {
            (*selection)--;
            moved = TRUE;
        } else {
            *selection = 3;
            moved = TRUE;
        }
    } else if (gSystem.newAndRepeatedKeys & PAD_KEY_DOWN) {
        if (*selection < 3) {
            (*selection)++;
            moved = TRUE;
        } else {
            *selection = 0;
            moved = TRUE;
        }
    }
    if (moved == TRUE) {
        PlaySE(0x5E5);
        ov43_0222B3A4(selection, work);
        ScheduleBgTilemapBufferTransfer(*(void **)work, 2);
    }
    return FALSE;
}

BOOL ov43_0222B324(u32 *selection, u32 *state, u8 *work, int *usedTouch) {
    int hit = TouchscreenHitbox_FindHitboxAtTouchNew(ov43_0222EE1A);
    if (hit == -1) return FALSE;
    *usedTouch = TRUE;
    *state = TRUE;
    *selection = hit;
    PlaySE(0x5DD);
    ov43_0222B3C4(selection, work);
    ov43_0222B3A4(selection, work);
    ScheduleBgTilemapBufferTransfer(*(void **)work, 2);
    return TRUE;
}

BOOL ov43_0222B374(u32 *selection, u32 *state, u8 *work) {
    int usedTouch = FALSE;
    BOOL ret = ov43_0222B324(selection, state, work, &usedTouch);
    if (usedTouch != FALSE) {
        *state = TRUE;
        return ret;
    }
    return ov43_0222B278(selection, state, work);
}

void ov43_0222B3A4(u32 *selection, u8 *work) {
    Sprite_SetPositionXY(*(Sprite **)(work + 0x1FC), 0x80, (s16)(*selection * 40 + 48));
}

void ov43_0222B3C4(u32 *selection, u8 *work) {
    int i = 0;
    int y = 4;
    while (i < 4) {
        int palette = (*selection == i) ? 9 : 2;
        ((void (*)(void *, int, int, int, int, int, int))BgTilemapRectChangePalette)(*(void **)work, 2, 2, (u8)y, 0x1C, 4, palette);
        i++;
        y += 5;
    }
    ScheduleBgTilemapBufferTransfer(*(void **)work, 2);
}
