#include "to47_overlay87_private.h"

int ov87_021E7FC0(SpriteWrap *p) {
    Sprite_Delete(p->sprite);
    Heap_Free(p);
    return 0;
}
void ov87_021E7FD4(SpriteWrap *p, int v) {
    Sprite_SetDrawFlag(p->sprite, v);
}
void ov87_021E7FE0(SpriteWrap *p, int v) {
    Sprite_SetDrawPriority(p->sprite, v);
}
void ov87_021E7FEC(SpriteWrap *p, int x, int y) {
    s32 xy[3];
    xy[1] = y << 12;
    xy[0] = x << 12;
    if (p->raw[2] == 1) {
        xy[1] += 0x200000;
    }
    Sprite_SetMatrix(p->sprite, xy);
}
void ov87_021E8014(SpriteWrap *p, int *x, int *y) {
    s32 *m = Sprite_GetMatrixPtr(p->sprite);
    *x = (s32)(m[0] + ((u32)(m[0] >> 11) >> 20)) >> 12;
    *y = (s32)(m[1] + ((u32)(m[1] >> 11) >> 20)) >> 12;
}
void ov87_021E803C(SpriteWrap *p, int a) {
    Sprite_SetAnimSpeed(p->sprite, 0x1000);
    Sprite_TryChangeAnimSeq(p->sprite, a);
}
void ov87_021E8058(SpriteWrap *p) {
    Sprite_SetScaleAndAffineType(p->sprite, ov87_021E83A8, 1);
}
void ov87_021E806C(SpriteWrap *p, const void *v) {
    Sprite_SetScaleAndAffineType(p->sprite, v, 2);
}
void ov87_021E8078(SpriteWrap *p, int n) {
    Sprite_SetPalIndexRespectVramOffset(p->sprite, n);
}
void ov87_021E8084(SpriteWrap *p, int active) {
    int n;
    Sprite_SetAnimActiveFlag(p->sprite, active);
    Sprite_SetAnimSpeed(p->sprite, 0x1000);
    n = Sprite_GetAnimationNumber(p->sprite);
    Sprite_SetAnimCtrlSeq(p->sprite, n);
}
void ov87_021E80A8(SpriteWrap *p, int v) {
    Sprite_SetMosaic(p->sprite, v);
}
int ov87_021E80B4(SpriteWrap *p) {
    return Sprite_IsAnimated(p->sprite);
}
void ov87_021E80C0(void *bg, void *w) {
    u8 i = 0;
    do {
        AddWindow(bg, (u8 *)w + i * 16, ov87_021E842C + i * 8);
        FillWindowPixelBuffer((u8 *)w + i * 16, 0);
        i++;
    } while (i < 16);
}
void ov87_021E80F0(void *w) {
    u16 i = 0;
    do {
        RemoveWindow((u8 *)w + i * 16);
        i++;
    } while (i < 16);
}
void ov87_021E810C(void *bg, void *w) {
    sub_0200E398(bg, 2, 0x3f7, 0, 0x7a);
    DrawFrameAndWindow1(w, 1, 0x3f7, 0xb);
}
void ov87_021E8134(void *w, int frame) {
    int bg = GetWindowBgId(w);
    LoadUserFrameGfx2(*(void **)w, bg, 0x3d9, 0xa, (u8)frame, 0x7a);
    FillWindowPixelBuffer(w, 0xf);
    DrawFrameAndWindow2(w, 0, 0x3d9, 0xa);
}
