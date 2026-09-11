#include "overlay72_anim_internal.h"
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
typedef struct Ov72AnimCtl {
    u8 mode;
    u8 state;
    u8 layer;
    u8 timer;
    u8 x;
    u8 y;
    u8 w;
    u8 h;
    u16 first;
    u16 second;
} Ov72AnimCtl;

void ov72_0223AE20(void *p, int pal) {
    Ov72AnimCtl *c = (Ov72AnimCtl *)((u8 *)p + 0x1358);
    if (c->mode == 0) {
        {
            u8 *q = (u8 *)p + c->layer * 4;
            Sprite_SetAnimCtrlSeq(PTR(q, 0xDF4), pal);
        }
    } else {
        BgTilemapRectChangePalette(PTR(p, 4), c->layer, c->w, c->h, c->x, c->y, pal);
        ScheduleBgTilemapBufferTransfer(PTR(p, 4), c->layer);
    }
}

int ov72_0223AE6C(void *p) {
    Ov72AnimCtl *c = (Ov72AnimCtl *)((u8 *)p + 0x1358);
    switch (c->state) {
    case 0:
        ov72_0223AE20(p, (u8)c->first);
        c->state++;
        break;
    case 1:
        c->timer++;
        if (c->timer == 4) {
            ov72_0223AE20(p, (u8)c->second);
            c->timer = 0;
            c->state++;
        }
        break;
    case 2:
        c->timer++;
        if (c->timer == 2) {
            return 0;
        }
        break;
    }
    return 1;
}
