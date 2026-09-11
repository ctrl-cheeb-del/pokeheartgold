#include "overlay49_task_internal.h"
#pragma require_prototypes off
#define P(p, o) ((void *)((u8 *)(p) + (o)))
#define W(p, o) (*(void **)((u8 *)(p) + (o)))

void ov49_0225A08C(void *p, u32 a) {
    ov49_0225AB44(P(p, 0x2f8), a);
}

void ov49_0225A09C(void *p, u32 a) {
    ov49_0225ABA4(P(p, 0x2f8), a);
}

void ov49_0225A0AC(void *p) {
    ov49_0225AC5C(P(p, 0x2f8));
}

void ov49_0225A0BC(void *p) {
    ov49_0225AC08(P(p, 0x2f8));
}

void ov49_0225A0CC(void *p) {
    ov49_0225AC24(P(p, 0x2f8));
}

void ov49_0225A0DC(void *p) {
    ov49_0225AC4C(P(p, 0x2f8));
}

void ov49_0225A0EC(void *p) {
    ov49_0225AC74(P(p, 0x2f8));
}

void ov49_0225A0FC(void *p, u32 a) {
    ov49_0225ACC4(P(p, 0x318), a);
}

void ov49_0225A10C(void *p, u32 a) {
    ov49_0225AEA8(P(p, 0x338), a, 0x78, 0);
}

void ov49_0225A120(void *p, u32 a, u32 b) {
    ov49_0225AEA8(P(p, 0x338), a, 0x78, b);
}

void ov49_0225A134(void *p) {
    ov49_0225AEE0(P(p, 0x338));
}

void ov49_0225A144(void *p, u32 a, u32 b) {
    ov49_0225AEF8(P(p, 0x338), a, b);
}

void ov49_0225A154(void *p) {
    ov49_0225AF04(P(p, 0x338));
}

void ov49_0225A164(void *p, u32 a) {
    ov49_0225AF08(P(p, 0x338), a);
}

void ov49_0225A174(void *p, u32 a, u32 b, u32 c) {
    ov49_0225AF30(P(p, 0x338), a, P(p, 0x3c), b, c, 0x77, 0x10, 3, 0xf);
}

void ov49_0225A1A4(void *p, u32 a, u32 b, u32 c, u8 d, u8 e, u8 f) {
    ov49_0225AF30(P(p, 0x338), a, P(p, 0x3c), b, c, 0x77, d, e, f);
}

void ov49_0225A1D4(void *p) {
    ov49_0225AFD8(P(p, 0x338));
}

void ov49_0225A1E4(void *p, u32 a, u32 b) {
    ov49_0225B014(P(p, 0x338), a, b);
}

void ov49_0225A1F4(void *p, u32 a) {
    ov49_0225B06C(P(p, 0x338), a);
}

void ov49_0225A204(void *p, u32 a, u32 b, u32 c, u8 d) {
    ov49_0225B0E0(P(p, 0x3c4), P(p, 0x3c), 0x77, a, b, c, d);
}

void ov49_0225A22C(void *p) {
    ov49_0225B124(P(p, 0x3c4));
}

u32 ov49_0225A23C(void *p, u32 a, u32 b, u32 c) {
    return ov49_0225B148(&((Ov49WorkView *)p)->sub3C4, a, b, c);
}

void ov49_0225A24C(void *p, u32 a, u32 b, u32 c, u16 d) {
    ov49_0225B178(P(p, 0x3c4), a, b, c, d);
}

void ov49_0225A264(void *p) {
    ov49_0225AF30(P(p, 0x338), P(p, 0x3a4), P(p, 0x3c), 0, 0, 0x77, 0x19, 0xd, 6);
}

void ov49_0225A294(void *p) {
    ov49_0225AF30(P(p, 0x338), P(p, 0x3a4), P(p, 0x3c), 0, 1, 0x77, 0x19, 0xd, 6);
}

u32 ov49_0225A2C4(void *p) {
    s32 r = ov49_0225AFD8(P(p, 0x338));
    if (r == 0) {
        goto zero;
    }
    if (r == 1) {
        goto one;
    }
    if (r != -2) {
        goto two;
    }
    PlaySE(0x5dc);
one:
    return 1;
zero:
    return 0;
two:
    return 2;
}

void ov49_0225A2F8(void *p) {
    ov49_0225B014(P(p, 0x338), 0, 0);
}

void ov49_0225A30C(void *p, u32 a, u32 b) {
    ov49_0225B388(P(p, 0x2dc), a, b);
}

void ov49_0225A31C(void *p, u32 a, u32 b, u32 c, u32 d) {
    ov49_0225B3A8(P(p, 0x2dc), a, b, c, d);
}

void ov49_0225A334(void *p, u32 i, u32 a) {
    PlayerProfile *q = PlayerProfile_New(0x77);
    PlayerProfile *src;
    if (i == ov45_0222A53C(W(p, 0x34))) {
        src = ov45_0222A5C0(W(p, 0x34));
    } else {
        src = ov45_0222A578(W(p, 0x34), i);
    }
    ov45_0222A844(src, q, 0x77);
    ov49_0225B3C8(P(p, 0x2dc), q, a);
    Heap_Free(q);
}

void ov49_0225A37C(void *p, u32 a, u32 b) {
    ov49_0225B3D8(P(p, 0x2dc), a, b);
}

void ov49_0225A38C(void *p, u32 a, u32 b) {
    ov49_0225B3E8(P(p, 0x2dc), a, b);
}

void ov49_0225A39C(void *p, u32 a, u32 b) {
    ov49_0225B3F8(P(p, 0x2dc), a, b);
}

void ov49_0225A3AC(void *p, u32 a, u32 b) {
    BufferJPGreeting(((Ov49WorkView *)p)->unk2DC, a, b);
}

void ov49_0225A3BC(void *p, u32 a, u32 b) {
    BufferENGreeting(((Ov49WorkView *)p)->unk2DC, a, b);
}

void ov49_0225A3CC(void *p, u32 a, u32 b) {
    BufferFRGreeting(((Ov49WorkView *)p)->unk2DC, a, b);
}

void ov49_0225A3DC(void *p, u32 a, u32 b) {
    BufferITGreeting(((Ov49WorkView *)p)->unk2DC, a, b);
}

void ov49_0225A3EC(void *p, u32 a, u32 b) {
    BufferDEGreeting(((Ov49WorkView *)p)->unk2DC, a, b);
}

void ov49_0225A3FC(void *p, u32 a, u32 b) {
    BufferSPGreeting(((Ov49WorkView *)p)->unk2DC, a, b);
}

void ov49_0225A40C(void *p, u32 a, u32 b) {
    BufferTypeName(W(p, 0x2dc), a, ov45_0222D7C0(b));
}

void ov49_0225A428(void *p, u32 a, u32 b) {
    Ov49WorkView *w = p;
    if (a != ov49_0225B8F8(&w->sub184) || ov49_0225B8FC(&w->sub184) != 1 || ov49_0225B934(&w->sub184) != 0 || b != ov49_0225B928(&w->sub184)) {
        ov49_0225B89C(&w->sub184, a, b);
    }
}

void ov49_0225A478(void *p, u32 a) {
    ov49_0225B8A8(P(p, 0x184), P(p, 0x3c), a, 0x77);
}

void ov49_0225A490(void *p) {
    Ov49WorkView *w = p;
    if (ov49_0225B8FC(&w->sub184) != 0) {
        ov49_0225BEA0(&w->sub184, &w->pad18C, &w->sub3C, 0x77, ov45_0222A578(w->unk34, ov49_0225B8F8(&w->sub184)));
    }
}

void ov49_0225A4D0(void *p) {
    ov49_0225B8E0(P(p, 0x184));
}

void ov49_0225A4E0(void *p) {
    ov49_0225B8F8(P(p, 0x184));
}

void ov49_0225A4F0(void *p) {
    ov49_0225B8FC(P(p, 0x184));
}

void ov49_0225A500(void *p) {
    ov49_0225B914(P(p, 0x184));
}

void ov49_0225A510(void *p) {
    ov49_0225B8EC(P(p, 0x184));
}

void ov49_0225A520(void *p, u32 a) {
    ov49_02268968(W(p, 0x3dc), a, 1);
}
