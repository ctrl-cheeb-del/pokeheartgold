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
void ov96_021F4E5C(u8 *p, int value);
void ov96_021F4E9C(u8 frame, const s32 *points, void *handle);
void ov96_021F4FD8(int base, u8 *data);

void ov96_021F4A60(u8 *p, void *bg) {
    ov96_021F4724(p);
    if (ov96_0221DC04[U16(p, 0x18)] == 3) {
        ov96_021F48FC(p, bg);
    } else {
        ov96_021F4990(p, bg);
    }
    U16(p, 0x18) = (U16(p, 0x18) + 1) % 3;
}

void ov96_021F4A9C(u8 *outer) {
    if (U8(outer, 0x151) != U8(outer, 0x150)) {
        ov96_021F4EF8(outer + 0x68, PTR(outer, 8));
        BgTilemapRectChangePalette(PTR(outer, 8), 6, 3, 7, 12, 8, 3);
        ScheduleBgTilemapBufferTransfer(PTR(outer, 8), 6);
    }
}

void ov96_021F4AE0(u8 *outer) {
    u8 *p = outer + 0x68;
    U16(p, 0x1a)
    ++;
    if (U16(p, 0x1a) > 0x46) {
        ov96_021F4724(p);
        return;
    }
    ov96_021F4E9C(U16(p, 0x1a), ov96_0221C01C, PTR(p, 0x90));
    U8(p, 0xea) += 0x20;
    *(vu32 *)0x04001018 = (U8(p, 0xea) << 16) & 0x01ff0000;
}
