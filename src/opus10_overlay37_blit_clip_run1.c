#include "opus10_overlay37_blit_clip_private.h"

u32 ov37_021E6F5C(Ov37Work *work, u32 arg1) {
    if (work->unk_93B0 != 0) {
        if (work->unk_93B0 != sub_02037454()) {
            work->unk_93B0 = 0;
        }
    }
    work->counter++;
    if ((s32)work->counter > 60 && work->unk_93B0 == 0) {
        ov37_021E76C0(work);
        ov37_021E7844(work, 4);
        if (!sub_0203769C()) {
            work->unk_93F4 = 1;
            ov37_021E76D0(work, 1);
        }
    }
    ov37_021E68AC(work);
    return arg1;
}

void ov37_021E6FC8(Ov37Work *work, int arg1, u32 arg2) {
    switch (arg1) {
    case 1:
        if (work->prevState == 6 || work->prevState == 0xE) {
            ov37_021E78A4(work);
        }
        ov37_021E6848(&work->holder, 0);
        BufferPlayersName(work->msgFormat, 0, sub_02034818(arg2));
        work->unk_0320 = arg2;
        work->unk_93B4 = 0;
        break;
    case 3:
        ov37_021E76C0(work);
        break;
    case 8:
    case 9:
    case 0xF:
        break;
    case 0x15:
        if (work->unk_93BC == 1) {
            return;
        }
        BufferPlayersName(work->msgFormat, 0, sub_02034818(arg2));
        if (arg2 == sub_0203769C()) {
            return;
        }
        if (sub_0203769C() == 0) {
            work->unk_93B4 &= 0xFFFF ^ arg2;
        }
        if (work->prevState == 6 || work->prevState == 0xE) {
            ov37_021E78A4(work);
            CopyWindowToVram(&work->winB2);
        }
        ov37_021E6848(&work->holder, 0);
        break;
    default:
        return;
    }
    ov37_021E7844(work, arg1);
}

void ov37_021E70BC(Ov37Window *window, const void *src, s32 srcX, s32 srcY, s32 srcWidth, s32 srcHeight, s32 destX, s32 destY, s32 destWidth, s32 destHeight) {
    if (destX < 0) {
        s32 clip = -destX;
        if (clip > destWidth) {
            clip = destWidth;
        }
        destX = 0;
        srcX += clip;
        srcWidth -= clip;
        destWidth -= clip;
    }
    if (destY < 0) {
        s32 clip = -destY;
        if (clip > destHeight) {
            clip = destHeight;
        }
        destY = 0;
        srcY += clip;
        srcHeight -= clip;
        destHeight -= clip;
    }
    BlitBitmapRectToWindow(window, src, srcX, srcY, srcWidth, srcHeight, destX, destY, destWidth, destHeight);
}

void ov37_021E713C(Ov37Window *window, const void *src, s32 x1, s32 y1, s32 *px, s32 *py, s32 arg6, s32 arg7) {
    s32 ex;
    s32 dx;
    s32 ey;
    s32 sy;
    s32 sx;
    s32 x;
    s32 y;
    s32 err;
    s32 dy;

    x = *px;
    y = *py;
    ex = x1;
    ey = y1;
    if (arg6 == 0 && arg7 == 0) {
        *px = x1;
        *py = y1;
        return;
    }
    dx = x1 - x;
    if (dx < 0) {
        dx = -dx;
    }
    dy = y1 - y;
    if (dy < 0) {
        dy = -dy;
    }
    if (dx > dy) {
        if (x > x1) {
            if (y > y1) {
                sy = 1;
            } else {
                sy = -1;
            }
            ex = x;
            x = x1;
            y = y1;
        } else {
            if (y < y1) {
                sy = 1;
            } else {
                sy = -1;
            }
        }
        ov37_021E70BC(window, src, 0, 0, 6, 6, x, y, 6, 6);
        err = dx >> 1;
        for (x++; x <= ex; x++) {
            err -= dy;
            if (err < 0) {
                err += dx;
                y += sy;
            }
            ov37_021E70BC(window, src, 0, 0, 6, 6, x, y, 6, 6);
        }
    } else {
        if (y > y1) {
            if (x > x1) {
                sx = 1;
            } else {
                sx = -1;
            }
            ey = y;
            y = y1;
            x = x1;
        } else {
            if (x < x1) {
                sx = 1;
            } else {
                sx = -1;
            }
        }
        ov37_021E70BC(window, src, 0, 0, 6, 6, x, y, 6, 6);
        err = dy >> 1;
        for (y++; y <= ey; y++) {
            err -= dx;
            if (err < 0) {
                err += dy;
                x += sx;
            }
            ov37_021E70BC(window, src, 0, 0, 6, 6, x, y, 6, 6);
        }
    }
    *px = x1;
    *py = y1;
}

void ov37_021E72B4(const Ov37Entry *entries, Ov37Point *points) {
    int i;

    for (i = 0; i < 5; i++, entries++, points++) {
        points->count = entries->count;
        if (entries->count != 0) {
            points->x = entries->xs[entries->count - 1];
            points->y = entries->ys[entries->count - 1];
        }
    }
}

void ov37_021E72E8(Ov37Window *window, Ov37Entry *entries, Ov37Point *points, u32 arg3) {
    s32 lastX;
    s32 lastY;
    int i;
    u32 drew;
    int j;
    Ov37Entry *e;
    Ov37Point *p;

    drew = 0;
    for (i = 0, e = entries, p = points; i < 5; i++, e++, p++) {
        if (e->count != 0) {
            if (p->count != 0) {
                lastX = p->x - 9;
                lastY = p->y - 0x11;
            }
            for (j = 0; j < e->count; j++) {
                drew = 1;
                ov37_021E713C(window, &ov37_021E7AC8[e->unk_08_6][e->unk_08_0], e->xs[j] - 9, e->ys[j] - 0x11, &lastX, &lastY, j, p->count);
            }
        }
    }
    if (drew != 0 && arg3 != 0) {
        CopyWindowToVram(window);
    }
    ov37_021E72B4(entries, points);
    for (j = 0; j < 5; j++) {
        entries->count = 0;
        entries++;
    }
}

void ov37_021E73B4(Ov37Work *work) {
    int i;
    Ov37Entry *e;

    for (i = 0, e = work->entries; i < 5; i++) {
        if (i != sub_0203769C()) {
            if (e->count != 0 && sub_02034818(i)) {
                Sprite_SetDrawFlag(work->sprites[i], 1);
                ov37_021E657C(work->sprites[i], e->xs[e->count - 1], e->ys[e->count - 1]);
            } else {
                Sprite_SetDrawFlag(work->sprites[i], 0);
            }
        }
        e++;
    }
}

void ov37_021E741C(u16 *deg) {
    u16 color;

    *deg += 0x14;
    if (*deg > 360) {
        *deg = 0;
    }
    color = (u16)(((GF_SinDeg(*deg) * 10 / FX32_ONE + 15) << 5) | 0x1D);
    GX_LoadOBJPltt(&color, 0x18, 2);
}
