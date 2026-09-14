#include "overlay96_course_ui_r90_gap3_private.h"

#ifndef RUN2_ONLY
void ov96_0220831C(Ov96R90Work *work, int participant, int image) {
    Sprite *sprite;
    int slot;

    sprite = ov96_021EB5B8(work->participant[participant].sprite38);
    slot = image + participant * 3;
    DC_FlushRange(work->graphics[slot]->pixels, 0x200);
    GXS_LoadOBJ(work->graphics[slot]->pixels, 0x1800 + participant * 0x200, 0x200);
    Sprite_SetPaletteOverride(sprite, work->palette[slot]);
}

void ov96_02208374(Ov96R90Work *work, int value) {
    u8 x[3];
    u8 y[3];
    u8 digit;
    u8 i;

    digit = value / 100;
    x[0] = (digit % 5) * 4;
    y[0] = (digit / 5) * 8;
    digit = (value - digit * 100) / 10;
    x[1] = (digit % 5) * 4;
    y[1] = (digit / 5) * 8;
    digit = value % 10;
    x[2] = (digit % 5) * 4;
    y[2] = (digit / 5) * 8;

    for (i = 0; i < 3; i++) {
        CopyRectToBgTilemapRect(work->bgConfig, 5, 14 + i * 4, 3, 4, 8, (u8 *)work->tileData + 0xC, x[i], y[i], 20, 16);
    }
    ScheduleBgTilemapBufferTransfer(work->bgConfig, 5);
}
#endif

#ifndef RUN1_ONLY
BOOL ov96_02208608(Ov96R90Work *work, u32 counter) {
    if (counter == 0 || counter >= 4) {
        GF_AssertFail();
    }
    counter--;
    work->counters[counter].x += 0x20;
    if (work->counters[counter].x >= 0x58) {
        work->counters[counter].x = 0;
        work->counters[counter].y++;
    }
    if (work->counters[counter].y >= 3) {
        work->counters[counter].y = 0;
        return TRUE;
    }
    return FALSE;
}

void ov96_02208658(Ov96R90Work *work, int participant, u8 image, BOOL visible, int mode) {
    if (work->selectedImage[participant] != image) {
        work->selectedImage[participant] = image;
        ov96_0220831C(work, participant, image);
    }
    if (visible) {
        Ov96R90Vec vec;
        vec.z = 0;
        vec.x = (participant * 0x28 + 0x70) << 12;
        vec.y = 0x350004;
        ov96_021EB588(work->participant[participant].sprite38, &vec);
        ov96_021EB588(work->participant[participant].sprite40, &vec);
        ov96_02208A80((void **)&work->actionSprites[participant][0], 0);
    } else {
        Ov96R90Vec vec;
        vec.z = 0;
        vec.x = (participant * 0x28 + 0x70) << 12;
        vec.y = 0x350000;
        ov96_021EB588(work->participant[participant].sprite38, &vec);
        ov96_021EB588(work->participant[participant].sprite40, &vec);
        ov96_02208A80((void **)&work->actionSprites[participant][0], 1);
        if (mode == 1) {
            if (work->participant[participant].flag44 != mode) {
                ov96_021EB52C(work->participant[participant].sprite3C, 1, 1);
                ov96_021EB564(work->participant[participant].sprite3C, 1);
            }
        } else {
            ov96_021EB52C(work->participant[participant].sprite3C, 1, 0);
        }
    }
    work->participant[participant].flag44 = mode;
}

void ov96_02208740(Ov96R90Work *work, int value) {
    u8 digit = value / 30;
    u8 anim = digit / 10;
    Sprite_SetAnimCtrlSeq(work->digitSprites[0], anim + 1);
    anim = digit % 10;
    Sprite_SetAnimCtrlSeq(work->digitSprites[1], anim + 1);
}

void ov96_02208784(Ov96R90Work *work, int chosen) {
    u8 order[4];
    int i;
    u8 next;

    for (i = 0; i < 2; i++) {
        Sprite_SetDrawPriority(work->digitSprites[i], 2);
    }
    for (i = 0; i < 2; i++) {
        Sprite_SetDrawPriority(ov96_021EB5B8(work->numberSprites[i]), 2);
    }
    next = 1;
    for (i = 0; i < 4; i++) {
        if (i == chosen) {
            order[0] = i;
        }
    }
    for (i = 0; i < 4; i++) {
        if (order[0] != i) {
            order[next++] = i;
        }
    }
    for (i = 0; i < 4; i++) {
        ov96_021EB630(work->participant[order[i]].sprite3C, 3 + i * 2);
        ov96_021EB630(work->participant[order[i]].sprite38, 4 + i * 2);
        ov96_021EB630(work->participant[order[i]].sprite40, 11 + i);
    }
}
#endif
