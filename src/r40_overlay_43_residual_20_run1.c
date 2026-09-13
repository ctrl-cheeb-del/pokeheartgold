#include "r40_overlay_43_residual_20_private.h"
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))

static inline int Abs16(s16 x) {
    return x < 0 ? -x : x;
}

void ov43_0222C7F8(s16 *pos, void *ctx, void *res) {
    int y = pos[1];
    if (y < 0) {
        y = -y;
    }
    int x = pos[0];
    if (x < 0) {
        x = -x;
    }
    u16 *data = *(u16 **)((u8 *)res + 8);
    LoadRectToBgTilemapRect(PTR(ctx, 0), 2, (u8 *)data + 12, (u8)x, (u8)y, (u8)(data[0] >> 3), (u8)(data[1] >> 3));
    ScheduleBgTilemapBufferTransfer(PTR(ctx, 0), 2);
}

void ov43_0222C844(void *unused, void *p, int index) {
    if (index == 10) {
        ov43_0222AD74(p, 0, 0xFF);
        return;
    }
    const Ov43Rect *r = &ov43_0222EFA0[index];
    Sprite_SetPositionXY(PTR(p, 0x1FC), ((r->x + 7) << 19) >> 16, ((r->y + 2) << 19) >> 16);
    ov43_0222AD74(p, 1, 0xFF);
}

void ov43_0222C890(s16 *pos, void *ctx, int selected, int mode) {
    int i;
    for (i = 0; i < 9; i++) {
        const Ov43Rect *r = &ov43_0222EFA0[i];
        int pal = (mode == 1 && selected == i) ? r->a8 : r->a7;
        BgTilemapRectChangePalette(PTR(ctx, 0), r->palette, (u8)(r->x + Abs16(pos[0])), (u8)(r->y + Abs16(pos[1])), r->w, r->h, (u8)pal);
    }
    ScheduleBgTilemapBufferTransfer(PTR(ctx, 0), 2);
    ScheduleBgTilemapBufferTransfer(PTR(ctx, 0), 0);
}

void ov43_0222C918(void *rect, void *args, void *ctx, int a3, int a4, u8 *list, int page, int a7) {
    int offset, i;
    int heap;
    heap = sub_0202C6F4(PTR(args, 4));
    FillWindowPixelBuffer((u8 *)rect + 8, 0);
    ov43_0222CA30(rect, ctx);
    offset = page * 8;
    i = 0;
    u8 *entry = list + offset;
    do {
        if (*(u32 *)list > (u32)(offset + i)) {
            ov43_0222CA50(rect, (void *)a3, ctx, a4, i, heap, entry[8], a7);
        } else {
            ov43_0222CB34(rect, ctx, a4, i);
        }
        i++;
        entry++;
    } while (i < 8);
    ScheduleBgTilemapBufferTransfer(PTR(ctx, 0), 2);
    ScheduleWindowCopyToVram((u8 *)rect + 8);
}

void ov43_0222C9A4(s16 *rect, void *ctx) {
    ov43_0222CA30(rect, ctx);
    ClearWindowTilemapAndScheduleTransfer((u8 *)rect + 8);
    FillBgTilemapRect(PTR(ctx, 0), 2, 0, (u8)Abs16(rect[0]), (u8)Abs16(rect[1]), *(u8 *)((u8 *)rect + 4), *(u8 *)((u8 *)rect + 5), 0);
    ScheduleBgTilemapBufferTransfer(PTR(ctx, 0), 2);
    FillBgTilemapRect(PTR(ctx, 0), 3, 0, (u8)Abs16(rect[0]), (u8)Abs16(rect[1]), *(u8 *)((u8 *)rect + 4), *(u8 *)((u8 *)rect + 5), 0);
    ScheduleBgTilemapBufferTransfer(PTR(ctx, 0), 3);
}
