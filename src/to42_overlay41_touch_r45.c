#include "to42_overlay41_touch_r45_private.h"

/* ---- prototypes, source order ---- */
void ov41_022490B0(Ov41Work *self);
void ov41_022490F0(Ov41Work *self);
void ov41_02249280(Ov41Work *self);
void ov41_022492B0(Ov41Work *self);
void ov41_022492E0(Ov41Work *self);
void ov41_02249390(Ov41Work *self);
void ov41_022493BC(Ov41Work *w, void *object, int a2, int a3, int a4, int a5);
void ov41_02249418(Ov41Work *w);
void ov41_0224942C(Ov41Work *self, int *a, int *b, int *c, int *d);

/* ---- bodies ---- */

void ov41_022490B0(Ov41Work *self) {
    Ov41Work *w = (Ov41Work *)W(self, 0);

    if (W(w, 0x10) != 0) {
        GF_ASSERT(W((Ov41Work *)W(w, 0x10), 4) == 1);
        ov41_02249480(w, 4, S16(w, 0x1C), S16(w, 0x1E), (void *)W((Ov41Work *)W(w, 0x10), 4), U8F(w, 0x21));
        ov41_02249418(w);
    }
}

void ov41_022490F0(Ov41Work *self) {
    Ov41Work *w = (Ov41Work *)W(self, 0);
    int top;
    int bottom;
    int left;
    int right;
    int vw;
    int vh;
    int x;
    int y;
    int n;

    if (W(w, 0x10) != 0) {
        ov41_0224946C(self, &top, &bottom, &left, &right);
        n = ov41_022481D8((void *)W(w, 4), left, top);
        n += ov41_022481D8((void *)W(w, 4), right, top);
        n += ov41_022481D8((void *)W(w, 4), left, bottom);
        if (n + ov41_022481D8((void *)W(w, 4), right, bottom) >= 4) {
            if (!ov41_022480A4((void *)W(w, 4), (void *)W(w, 0x10), (void *)W((Ov41Work *)W(w, 0), 0x38))) {
                x = S16(w, 0x1C);
                y = S16(w, 0x1E);
                PlaySE(0x682);
                ov41_0224AC08((void *)W(w, 0xC), 0x1B, 0xD7, 3);
                ov41_02249480(w, 4, x, y, (void *)W((Ov41Work *)W(w, 0x10), 4), U8F(w, 0x21));
            } else {
                ov41_02248158((void *)W(w, 4));
                ov41_022463FC();
                W(w, 0x30) = 0;
                PlaySE(0x5EA);
            }
        } else {
            void *object = (void *)W((Ov41Work *)W(w, 0x10), 0);

            ov41_0224942C(self, &top, &bottom, &left, &right);
            n = ov41_0224883C((void *)W(w, 8), left, top);
            if (n + ov41_0224883C((void *)W(w, 8), right, bottom) < 2) {
                if (U8F(w, 0x20) == 1) {
                    ov41_02249B94((void *)W(w, 0x10), &vw, &vh);
                    x = MTRandom() % (108 - vw) + 10;
                    y = MTRandom() % (125 - vh) + 18;
                } else {
                    x = S16(w, 0x1C);
                    y = S16(w, 0x1E);
                }
                PlaySE(0x682);
            } else {
                ov41_02249B44((void *)W(w, 0x10), &x, &y);
                PlaySE(0x5EB);
            }
            if (U8F(w, 0x20) == 1) {
                U8F(w, 0x21) = (u8)ov41_022484E8(W((Ov41Work *)W(w, 0x10), 4), W((Ov41Work *)object, 0), (void *)W((Ov41Work *)W(w, 8), 4));
            }
            ov41_02249480(w, 4, x, y, (void *)W((Ov41Work *)W(w, 0x10), 4), U8F(w, 0x21));
        }
        ov41_02249418(w);
    }
}

void ov41_02249280(Ov41Work *self) {
    Ov41Work *w = (Ov41Work *)W(self, 0);

    if (W(w, 0x10) != 0 && *(u16 *)(gSystem + 0x60) != 0xFFFF && *(u16 *)(gSystem + 0x60) != 0xFFFF) {
        ov41_02249AF4((void *)W(w, 0x10), (int)*(u16 *)(gSystem + 0x60) - (int)W(w, 0x14), (int)*(u16 *)(gSystem + 0x62) - (int)W(w, 0x18));
    }
}

void ov41_022492B0(Ov41Work *self) {
    Ov41Work *w = (Ov41Work *)W(self, 0);

    if (W(w, 0x10) != 0) {
        ov41_02248020((void *)W(w, 4), (void *)W(w, 0x10));
        ov41_02248158((void *)W(w, 4));
        ov41_022463FC();
        W(w, 0x30) = 0;
        PlaySE(0x5EB);
        ov41_02249418(w);
    }
}

void ov41_022492E0(Ov41Work *self) {
    Ov41Work *w = (Ov41Work *)W(self, 0);
    int dx;
    int dy;
    int a;
    int b;
    int e;
    int g;
    int f;
    int h;
    int ey;

    if (W(w, 0x10) != 0 && *(u16 *)(gSystem + 0x60) != 0xFFFF && *(u16 *)(gSystem + 0x60) != 0xFFFF) {
        ov41_02249BAC((void *)W(w, 0x10), &e, &f, &g, &h);
        ov41_02249B94((void *)W(w, 0x10), &a, &b);
        dx = (int)*(u16 *)(gSystem + 0x60) - (int)W(w, 0x14);
        dy = (int)*(u16 *)(gSystem + 0x62) - (int)W(w, 0x18);
        ey = dy + g;
        a = a - f;
        b = b - h;
        if (dx + e <= 0x8A) {
            dx = 0x8A - e;
        } else if (dx + a >= 0xF6) {
            dx = 0xF6 - a;
        }
        if (ey <= 0x12) {
            dy = 0x12 - g;
        } else if (dy + b >= 0x8F) {
            dy = 0x8F - b;
        }
        ov41_022495A4(self, dx, dy);
        ov41_022482B8((void *)W(w, 4), &e, &g);
        ov41_022495A4(self, dx + e, dy + g);
    }
}

void ov41_02249390(Ov41Work *self) {
    Ov41Work *w = (Ov41Work *)W(self, 0);

    if (W(w, 0x10) != 0) {
        void *object;

        GF_ASSERT(W((Ov41Work *)W(w, 0x10), 4) == 1);
        object = (void *)W((Ov41Work *)W(w, 0x10), 0);
        ov41_022482A8((void *)W(w, 4));
        ov41_0224825C((void *)W(w, 4), (void *)W((Ov41Work *)object, 0), 0xE);
    }
}

void ov41_022493BC(Ov41Work *w, void *object, int a2, int a3, int a4, int a5) {
    int x;
    int y;

    ov41_02249B44(object, &x, &y);
    W(w, 0x10) = (u32)object;
    S16(w, 0x1C) = (s16)x;
    S16(w, 0x1E) = (s16)y;
    U8F(w, 0x20) = (u8)a2;
    W(w, 0x14) = (u32)a3;
    W(w, 0x18) = (u32)a4;
    if (a2 == 0) {
        U8F(w, 0x21) = (u8)ov41_0224895C((void *)W(w, 8), (void *)W((Ov41Work *)W(w, 0x10), 4));
    } else {
        U8F(w, 0x21) = 0;
    }
    W(w, 0x30) = 1;
    ov41_02249A90(object, a5);
}

void ov41_02249418(Ov41Work *w) {
    W(w, 0x10) = 0;
    S16(w, 0x1C) = 0;
    S16(w, 0x1E) = 0;
    U8F(w, 0x20) = 0;
    U8F(w, 0x21) = 0;
}

void ov41_0224942C(Ov41Work *self, int *a, int *b, int *c, int *d) {
    Ov41Work *w = (Ov41Work *)W(self, 0);
    int vw;
    int vh;
    int x;
    int y;

    ov41_02249B94((void *)W(w, 0x10), &vw, &vh);
    ov41_02249B44((void *)W(w, 0x10), &x, &y);
    *a = y;
    *b = y + vh;
    *c = x;
    *d = x + vw;
}
