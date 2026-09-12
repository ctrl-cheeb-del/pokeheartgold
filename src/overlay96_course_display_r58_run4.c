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

int ov96_021F46BC(u8 *state, const u8 *input);
BOOL ov96_021F4700(u8 *p, int next);
void ov96_021F4724(u8 *p);
void ov96_021F4790(u8 *p);
BOOL ov96_021F47F0(u8 *p, int next);
void ov96_021F4A60(u8 *p, void *bg);
void ov96_021F4A9C(u8 *outer);
void ov96_021F4AE0(u8 *outer);
void ov96_021F4E9C(u8 frame, const s32 *points, void *handle);
void ov96_021F4FD8(int base, u8 *data);

void ov96_021F4E5C(u8 *p, int value) {
    s32 matrix[3];
    void *sprite;
    ov96_021F4504(p, 0, value);
    sprite = ov96_021EB5B8(PTR(p, 0x90));
    matrix[0] = 0x80000;
    matrix[1] = 0x1d8000;
    matrix[2] = 0;
    Sprite_SetMatrix(sprite, matrix);
    ov96_021EB52C(PTR(p, 0x90), 1, 1);
}
