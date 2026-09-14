#include "to47_overlay102_input_dispatch_r7_private.h"

int ov102_021E87B4(Ov102R7Work *work, u32 *state)
{
    switch (*state) {
    case 0:
        ov102_021E8B18(work, state);
        break;
    case 1:
        if (ov102_021E947C(work->ui, 0x13)) {
            *state = 0;
        }
        break;
    case 2:
        if (ov102_021E947C(work->ui, 0x13)) {
            ov102_021E940C(work->ui, 0x12);
            *state = 0;
        }
        break;
    case 3:
        if (ov102_021E9464(work->ui)) {
            ov102_021E7A4C(work, work->handler);
            *state = 0;
        }
        break;
    }
    return 0;
}

void ov102_021E8820(Ov102R7Work *work, u32 *state)
{
    int input;
    if ((work->mode == 0 && work->side6b != 0) ||
        (work->mode == 1 && work->side6b != 1) ||
        (work->keys & 4)) {
        PlaySE(0x5e4);
        work->mode = 4;
        work->cursor50 = 0;
        work->side6b ^= 1;
        ov102_021E940C(work->ui, 0xc);
        work->handler = ov102_021E8240;
        *state = 3;
        return;
    }
    if (work->mode == 2) {
        input = ov102_021E8C3C(&work->page54);
    } else if (work->mode == 3) {
        input = ov102_021E8C64(&work->page54);
    } else {
        input = ov102_021E8B40(&work->page54, work->repeatKeys);
    }
    switch (input) {
    case 1:
        PlaySE(0x5dc);
        ov102_021E940C(work->ui, 0x12);
        return;
    case 2:
        PlaySE(0x5dc);
        ov102_021E940C(work->ui, 0x13);
        *state = 1;
        return;
    case 3:
        PlaySE(0x5dc);
        ov102_021E940C(work->ui, 0x13);
        *state = 2;
        return;
    }
    if (work->keys & 2) {
        PlaySE(0x5dc);
        ov102_021E940C(work->ui, 0xc);
        work->handler = ov102_021E8240;
        *state = 3;
        return;
    }
    if (work->keys & 1) {
        if (work->flag60 != 0) {
            PlaySE(0x5dc);
            ov102_021E940C(work->ui, 0xc);
            work->handler = ov102_021E8240;
            *state = 3;
            return;
        }
        PlaySE(0x5dc);
        work->selected62 = 0xffff;
        ov102_021E8CA4(work);
        work->handler = ov102_021E7AA4;
        ov102_021E940C(work->ui, 0xd);
        *state = 3;
    }
}

int ov102_021E896C(Ov102R7Work *work)
{
    int hit;
    u16 selection;
    int y;
    int done;
    int top;
    Ov102R7Hitbox box;

    if (!System_GetTouchNew()) {
        return 0;
    }
    hit = TouchscreenHitbox_FindRectAtTouchNew(ov102_021EC5F4);
    switch (hit) {
    case 0:
        return ov102_021E8C3C(&work->page54);
    case 1:
        return ov102_021E8C64(&work->page54);
    }
    selection = work->page54 * 2;
    done = 0;
    y = 0;
    top = 0x30;
    while (y < 5) {
        int x;
        int left;

        box.top = top;
        box.bottom = box.top + 0x10;
        x = 0;
        left = 0x20;
        while (x < 2) {
            box.left = left;
            box.right = box.left + 0x48;
            if (TouchscreenHitbox_PointIsIn(&box, *(u16 *)(gSystem + 0x60), *(u16 *)(gSystem + 0x62))) {
                work->selected62 = selection;
                return 5;
            }
            selection++;
            if (selection >= work->count58) {
                done = 1;
                break;
            }
            x++;
            left += 0x68;
        }
        if (done) {
            break;
        }
        top += 0x18;
        y++;
    }
    return 0;
}

void ov102_021E8A34(Ov102R7Work *work, u32 *state)
{
    int input = ov102_021E839C(work);
    switch (input) {
    case 1:
        PlaySE(0x5dc);
        ov102_021E940C(work->ui, 0xc);
        work->handler = ov102_021E8240;
        *state = 3;
        return;
    case 2:
        PlaySE(0x5e4);
        work->cursor50 = 0;
        work->side6b ^= 1;
        ov102_021E940C(work->ui, 0xc);
        work->handler = ov102_021E8240;
        *state = 3;
        return;
    }
    input = ov102_021E896C(work);
    switch (input) {
    case 5:
        PlaySE(0x5dc);
        ov102_021E8CA4(work);
        work->handler = ov102_021E7AA4;
        ov102_021E940C(work->ui, 0xd);
        *state = 3;
        return;
    case 1:
        PlaySE(0x5dc);
        ov102_021E940C(work->ui, 0x12);
        return;
    case 2:
        PlaySE(0x5dc);
        ov102_021E940C(work->ui, 0x13);
        *state = 1;
        return;
    case 3:
        PlaySE(0x5dc);
        ov102_021E940C(work->ui, 0x13);
        *state = 2;
        return;
    }
}
