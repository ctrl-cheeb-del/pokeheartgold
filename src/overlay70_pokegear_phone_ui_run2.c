#include "overlay70_pokegear_phone_ui_private.h"

int ov70_0223C930(Ov70Work *work);
int ov70_0223C958(Ov70Work *work);
int ov70_0223C978(Ov70Work *work);
int ov70_0223C9AC(Ov70Work *work);
int ov70_0223CA18(Ov70Work *work);
int ov70_0223CA40(Ov70Work *work);
void ov70_0223CAC4(Ov70Work *work, int msgId, int color, int a, int b);
void ov70_0223CB1C(void *a, void *b, void *msgData);
void ov70_0223CC04(void *bgConfig, void *window, void *msgData, int flag);
int ov70_0223CC68(const Ov70Key *a, const Ov70Key *b, int c, int d);
void ov70_0223CCA4(Ov70Work *work);
void ov70_0223CD28(int value);
int ov70_0223CD44(Ov70Work *work);
void ov70_0223CDD8(Ov70Work *work);
int ov70_0223CDF8(Ov70Work *work);
void ov70_0223CE44(void *bgConfig);
void ov70_0223CF48(void *bgConfig);
void ov70_0223CF74(Ov70Work *work);
void ov70_0223D058(Ov70Work *work);

void ov70_0223D208(Ov70Work *work) {
    int i;

    for (i = 0; i < 2; i++) {
        Sprite_Delete(work->spritesF04[i]);
    }
    Sprite_Delete(work->spriteDCC);
    for (i = 0; i < 0x1e; i++) {
        Sprite_Delete(work->spritesDD8[i]);
        Sprite_Delete(work->spritesE50[i]);
    }
    for (i = 0; i < 6; i++) {
        Sprite_Delete(work->spritesEC8[i]);
    }
}

void ov70_0223D26C(Ov70Work *work) {
    AddWindowParameterized(work->bgConfig, work->windowF48, 3, 4, 0, 0xd, 3, 0xd, 0x60);
    FillWindowPixelBuffer(work->windowF48, 0);
    CopyWindowToVram(work->windowF48);
    AddWindowParameterized(work->bgConfig, work->windowF18, 0, 2, 0x15, 0x1b, 2, 0xd, 0x109);
    FillWindowPixelBuffer(work->windowF18, 0);
    AddWindowParameterized(work->bgConfig, work->window1158, 0, 2, 0x13, 0x1b, 4, 0xd, 0x13f);
    FillWindowPixelBuffer(work->window1158, 0);
    AddWindowParameterized(work->bgConfig, work->windowF68, 1, 0x18, 0x10, 6, 2, 0, 0x165);
    FillWindowPixelBuffer(work->windowF68, 6);
    ov70_02245084(work->windowF68, work->strBB8, 0, 1, 1, 0x10306);
    if (work->field24 == 5) {
        ov70_02239D44(work, 3);
    } else {
        ov70_02239D44(work, 1);
    }
}

void ov70_0223D378(Ov70Work *work) {
    RemoveWindow(work->window1198);
    RemoveWindow(work->window1158);
    RemoveWindow(work->windowF68);
    RemoveWindow(work->windowF18);
    RemoveWindow(work->windowF48);
}

void ov70_0223D3BC(Ov70Work *work) {
    work->strBB4 = String_New(0x12, 0x3d);
    work->strBBC = String_New(0xb4, 0x3d);
    work->strBB8 = NewString_ReadMsgData(work->msgDataBA0, 0x6d);
    if (work->field122 == 0x1e) {
        work->field122 = 0;
    }
    work->ptr11F4 = Heap_Alloc(0x3d, 0x78);
}

void ov70_0223D414(Ov70Work *work) {
    Heap_Free(work->ptr11F4);
    String_Delete(work->strBB4);
    String_Delete(work->strBBC);
    String_Delete(work->strBB8);
}

int ov70_0223D44C(Ov70Work *work) {
    int msgId;

    if (IsPaletteFadeFinished()) {
        if (work->field24 == 5) {
            msgId = 0x15;
        } else if (work->field24 == 6) {
            msgId = 0x11;
        }
        ov70_0223E01C(work, msgId, 1, 0, 0xf0f, 0);
        ov70_02238D84(work, 3, 1);
    }
    return 3;
}

void ov70_0223D490(Ov70Work *work) {
    void *mon;

    if (work->field122 == 0x1e) {
        ov70_02238E50(work, 1, 0);
        work->state2c = 2;
        PlaySE(0x5dc);
        return;
    }
    if (work->field122 == 0x1f) {
        return;
    }
    PlaySE(0x5dc);
    switch (ov70_0223E5C8(work->unk00->unk08, work->unk00->unk0C, work->field120, work->field122)) {
    case 1:
        if (ov70_0223E4DC(work->unk00->unk08, work->unk00->unk0C, work->field120, work->field122)) {
            mon = ov70_0223E49C(work->unk00->unk08, work->unk00->unk0C, work->field120, work->field122);
            BufferBoxMonNickname(work->ptrB9C, 0, mon);
            ov70_0223E01C(work, 0x16, 1, 0, 0xf0f, 0);
            ov70_02238D84(work, 3, 7);
        } else {
            ov70_0223E01C(work, 0x1a, 1, 0, 0xf0f, 1);
            ov70_02238D84(work, 4, 1);
        }
        break;
    case 2:
        ov70_0223E01C(work, 0x1b, 1, 0, 0xf0f, 1);
        ov70_02238D84(work, 4, 1);
        break;
    }
}

void ov70_0223D588(Ov70Work *work) {
    void *mon;

    if (work->field122 == 0x1e) {
        ov70_0223D690(work, 6);
        return;
    }
    if (work->field122 == 0x1f) {
        return;
    }
    switch (ov70_0223E5C8(work->unk00->unk08, work->unk00->unk0C, work->field120, work->field122)) {
    case 1:
        mon = ov70_0223E49C(work->unk00->unk08, work->unk00->unk0C, work->field120, work->field122);
        if (ov70_0223E658(mon, &work->array350[0x124 * work->field12C])) {
            if (ov70_0223E4DC(work->unk00->unk08, work->unk00->unk0C, work->field120, work->field122)) {
                BufferBoxMonNickname(work->ptrB9C, 0, mon);
                ov70_0223E01C(work, 0x12, 1, 0, 0xf0f, 0);
                ov70_02238D84(work, 3, 9);
                PlaySE(0x5dc);
            } else {
                ov70_0223E01C(work, 0x1a, 1, 0, 0xf0f, 1);
                ov70_02238D84(work, 4, 1);
            }
        } else {
            PlaySE(0x5dc);
        }
        break;
    case 0:
    case 2:
        PlaySE(0x5dc);
        break;
    }
}

int ov70_0223D680(void) {
    return TouchscreenHitbox_FindRectAtTouchNew(ov70_02245884);
}

void ov70_0223D690(Ov70Work *work, int code) {
    if (code == 5) {
        ov70_02238E50(work, 1, 0);
        work->state2c = 2;
        PlaySE(0x5dc);
    } else if (code == 6) {
        ov70_02238E50(work, 3, 0x11);
        work->state2c = 2;
        PlaySE(0x5dc);
    }
}

int ov70_0223D6C8(Ov70Work *work) {
    int hit = ov70_0223D680();

    if (hit != -1) {
        switch (hit) {
        case 0x1f:
            Sprite_SetAnimActiveFlag(work->spritesF04[0], 1);
            Sprite_SetAnimCtrlSeq(work->spritesF04[0], 0x26);
            work->field120 = ov70_0223D924(work->field120, 0x13, 1);
            ov70_0223E264(work, work->field120);
            PlaySE(0x5dc);
            break;
        case 0x20:
            Sprite_SetAnimActiveFlag(work->spritesF04[1], 1);
            Sprite_SetAnimCtrlSeq(work->spritesF04[1], 0x27);
            work->field120 = ov70_0223D924(work->field120, 0x13, -1);
            ov70_0223E264(work, work->field120);
            PlaySE(0x5dc);
            break;
        case 0x1e:
            ov70_0223D690(work, work->field24);
            work->field122 = hit;
            ov70_0223D8E8(work->spriteDCC, work->field122);
            break;
        default:
            work->field122 = hit;
            ov70_0223D8E8(work->spriteDCC, work->field122);
            if (work->field24 == 5) {
                ov70_0223D490(work);
            } else if (work->field24 == 6) {
                ov70_0223D588(work);
            }
            break;
        }
    } else {
        ov70_0223D808(work);
        if (work->field24 == 5) {
            if (gSystem.newKeys & 2) {
                ov70_0223D690(work, 5);
            } else if (gSystem.newKeys & 1) {
                ov70_0223D490(work);
            }
        } else if (work->field24 == 6) {
            if (gSystem.newKeys & 2) {
                ov70_0223D690(work, 6);
            } else if (gSystem.newKeys & 1) {
                ov70_0223D588(work);
            }
        }
    }
    return 3;
}

void ov70_0223D808(Ov70Work *work) {
    int played;
    int dir;
    u32 keys;
    u8 next;
    u8 idx;

    played = 0;
    dir = 0;
    keys = gSystem.newKeys;
    if (keys & 0x40) {
        dir = 1;
    } else if (keys & 0x80) {
        dir = 2;
    } else if (keys & 0x20) {
        dir = 3;
    } else if (keys & 0x10) {
        dir = 4;
    }
    if (dir != 0) {
        next = ov70_02245804[work->field122][dir - 1];
        if (next != work->field122) {
            if (next == 0x63 || next == 0x65) {
                idx = (u8)(next != 0x65);
                Sprite_SetAnimActiveFlag(work->spritesF04[idx], 1);
                Sprite_SetAnimCtrlSeq(work->spritesF04[idx], idx + 0x26);
                work->field120 = ov70_0223D924(work->field120, 0x13, next - 0x64);
                ov70_0223E264(work, work->field120);
                PlaySE(0x5dc);
            } else {
                played = 1;
                work->field122 = next;
            }
        }
    }
    if (played) {
        PlaySE(0x5dc);
    }
    ov70_0223D8E8(work->spriteDCC, work->field122);
}

void ov70_0223D8E8(void *sprite, int index) {
    ov70_02238D8C(sprite, ov70_02245784[index * 2], ov70_02245786[index * 2]);
    if (index == 0x1f || (index >= 0 && index <= 5)) {
        Sprite_SetPriority(sprite, 0);
    } else {
        Sprite_SetPriority(sprite, 1);
    }
}
