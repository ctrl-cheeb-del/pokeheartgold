#include "overlay96_course_display_r58_private.h"

extern const u32 ov96_0221DC04[];
extern const s32 ov96_0221C01C[];
extern void ov96_021EB52C(void *, int, int);
extern void *ov96_021EB5B8(void *);
extern void ov96_021F4724(u8 *);
extern int ov96_021F4700(u8 *, int);
extern void ov96_021F48FC(void *, void *);
extern void ov96_021F4990(void *, void *);
extern void ov96_021F4EF8(void *, void *);
extern void ov96_021F4E9C(u8, const s32 *, void *);
extern void ov96_021F4504(void *, int, int);
extern void Sprite_SetMatrix(void *, const void *);
extern void GfGfx_EngineBTogglePlanes(int, BOOL);
extern void ScheduleBgTilemapBufferTransfer(void *, int);
extern void BgTilemapRectChangePalette(void *, int, int, int, int, int, int);
extern int _s32_div_f(int, int);

int ov96_021F46BC(u8 *, const u8 *);
BOOL ov96_021F4700(u8 *, int);
void ov96_021F4724(u8 *);
void ov96_021F4790(u8 *);
BOOL ov96_021F47F0(u8 *, int);
void ov96_021F4A60(u8 *, void *);
void ov96_021F4A9C(u8 *);
void ov96_021F4AE0(u8 *);
void ov96_021F4E5C(u8 *, int);
void ov96_021F4E9C(u8, const s32 *, void *);
void ov96_021F4FD8(int, u8 *);

void ov96_021F4724(u8 *p);
void ov96_021F4790(u8 *p);
BOOL ov96_021F47F0(u8 *p, int next);
void ov96_021F4A60(u8 *p, void *bg);
void ov96_021F4A9C(u8 *outer);
void ov96_021F4AE0(u8 *outer);
void ov96_021F4E5C(u8 *p, int value);
void ov96_021F4E9C(u8 frame, const s32 *points, void *handle);
void ov96_021F4FD8(int base, u8 *data);

int ov96_021F46BC(u8 *state, const u8 *input) {
    u8 changed[12];
    int i;

    for (i = 0; i < 12; i++) {
        if (input[i] != 0 && state[i + 8] == 0) {
            state[i + 8] = 1;
            changed[i] = 1;
        } else {
            changed[i] = 0;
        }
    }
    for (i = 0; i < 12; i++) {
        if (changed[i] != 0) {
            return i;
        }
    }
    return 12;
}

BOOL ov96_021F4700(u8 *p, int next) {
    if (U32(p, 0x1c) == next) {
        return FALSE;
    }
    if (next == 1) {
        return TRUE;
    }
    if (next == 2 && U32(p, 0x1c) != 1) {
        return TRUE;
    }
    return FALSE;
}
