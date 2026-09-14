#include "global.h"

#include "bg_window.h"

#define U8_AT(p, off)  (*(u8 *)((p) + (off)))
#define S8_AT(p, off)  (*(s8 *)((p) + (off)))
#define PTR_AT(p, off) (*(void **)((p) + (off)))

typedef struct Ov32Control {
    u8 mode : 1;
    u8 bgId : 7;
    u8 low : 4;
    u8 high : 4;
    u8 state;
    u8 counter;
    u8 x;
    u8 y;
    u8 width;
    u8 height;
} Ov32Control;

typedef struct Ov32Work {
    BgConfig *bgConfig;
    u8 padding04[0x18];
    Ov32Control control;
    u8 padding24[0x274];
    void *sprites[4];
    u8 padding2A8;
    u8 result;
    s8 selection;
} Ov32Work;

void ov32_0225DF9C(u8 *work, int delta);
void ov32_0225DFE8(Ov32Work *work, u8 palette);
int ov32_0225E048(u8 *work);
int ov32_0225E0A8(Ov32Work *work, u8 bgId, u8 low, u8 high, u8 result);
int ov32_0225E0FC(Ov32Work *work, u8 x, u8 y, u8 result);
void Sprite_SetAnimCtrlSeq(void *sprite, int sequence);

void ov32_0225DF9C(u8 *work, int delta) {
    int low;
    int high;

    S8_AT(work, 0x2AA) += delta;
    if (S8_AT(work, 0x2AA) < 0) {
        S8_AT(work, 0x2AA) = 3;
    }
    if (S8_AT(work, 0x2AA) > 3) {
        S8_AT(work, 0x2AA) = 0;
    }
    if (delta > 0) {
        low = 3;
        high = 6;
    } else {
        low = 2;
        high = 4;
    }
    ov32_0225E0A8((Ov32Work *)work, low, high + 1, high, 2);
}

void ov32_0225DFE8(Ov32Work *work, u8 palette) {
    if (work->control.mode == 0) {
        Sprite_SetAnimCtrlSeq(work->sprites[work->control.bgId], palette);
    } else {
        BgTilemapRectChangePalette(work->bgConfig, work->control.bgId, work->control.x, work->control.y, work->control.width, work->control.height, palette);
        ScheduleBgTilemapBufferTransfer(work->bgConfig, work->control.bgId);
    }
}

int ov32_0225E048(u8 *work) {
    Ov32Control *state = (Ov32Control *)(work + 0x1C);

    switch (state->state) {
    case 0:
        ov32_0225DFE8((Ov32Work *)work, state->low);
        state->state++;
        break;
    case 1:
        state->counter++;
        if (state->counter == 4) {
            ov32_0225DFE8((Ov32Work *)work, state->high);
            state->counter = 0;
            state->state++;
        }
        break;
    case 2:
        state->counter++;
        if (state->counter == 2) {
            return 0;
        }
        break;
    }
    return 1;
}

int ov32_0225E0A8(Ov32Work *work, u8 bgId, u8 low, u8 high, u8 result) {
    work->control.mode = 0;
    work->control.counter = 0;
    work->control.state = 0;
    work->control.bgId = bgId;
    work->control.low = low;
    work->control.high = high;
    work->result = result;
    return 1;
}

int ov32_0225E0FC(Ov32Work *work, u8 x, u8 y, u8 result) {
    int mode = *(u8 *)&work->control;

    mode &= ~1;
    mode |= 1;
    *(u8 *)&work->control = mode;
    work->control.counter = 0;
    work->control.state = 0;
    work->control.bgId = 5;
    work->control.low = 1;
    work->control.high = 0;
    work->control.x = x;
    work->control.y = y;
    work->control.width = 12;
    work->control.height = 4;
    work->result = result;
    return 1;
}
