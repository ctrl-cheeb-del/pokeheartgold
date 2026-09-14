#include "global.h"

#pragma require_prototypes off

extern const u16 ov83_02247EE0[];
extern const u16 ov83_02247F16[];
extern const u16 ov83_02247F88[];
extern const u16 ov83_02247FC8[];

void PlaySE(int);
int ov80_02237D8C(int);
void ov83_02241368(void *, int, int);
void ov83_022475D4(void *, int);
void ov83_02247568(void *, int, int);
void ov83_02242844(void *, int);
void ov83_02242814(void *, int);
int ov83_0224777C(void *, int, int);
void GF_AssertFail(void);

void ov83_02240E70(void *work, int *x, int *y, u32 index);
void ov83_02240DE0(void *work, u32 index, int update);

void ov83_02240DB0(void *work) {
    u8 *p = work;

    PlaySE(0x5DC);
    if (ov80_02237D8C(p[9]) == 1) {
        ov83_02241368(work, 12, p[13]);
    }
    ov83_02240DE0(work, p[13], 0);
}

void ov83_02240DE0(void *work, u32 index, int update) {
    u8 *p = work;
    void *sprite;
    int x;
    int y;
    int seq;
    int idleSeq;

    if (update == 0) {
        sprite = *(void **)(p + 0x760);
        seq = 1;
        idleSeq = 0;
    } else {
        sprite = *(void **)(p + 0x764);
        seq = 2;
        idleSeq = 0x11;
    }

    if (index >= p[0x15]) {
        ov83_022475D4(sprite, idleSeq);
        ov83_02247568(sprite, 0xE0, 0xA0);
        if (update == 0) {
            ov83_02242844(work, 0);
        }
        return;
    }

    ov83_022475D4(sprite, seq);
    ov83_02240E70(work, &x, &y, index);
    ov83_02247568(sprite, (u16)x, (u16)y);
    if (update == 0) {
        if (p[0xC] >= p[0x15]) {
            ov83_02242844(work, 1);
        }
        ov83_02242814(work, 0);
    }
}

void ov83_02240E70(void *work, int *x, int *y, u32 index) {
    u8 *p = work;

    if (ov80_02237D8C(p[9]) == 1) {
        if (index == 0) {
            *x = 0x28;
        } else if (index == 1) {
            *x = 0x68;
        } else if (index == 2) {
            *x = 0xA8;
        } else {
            *x = 0xE8;
        }
    } else {
        if (index == 0) {
            *x = 0x48;
        } else if (index == 1) {
            *x = 0x88;
        } else {
            *x = 0xC8;
        }
    }
    *y = 0x58;
}

u16 ov83_02240EC4(void *work, int index, int mode) {
    u8 *p = work;

    ov83_0224777C(*(void **)(p + 0x50C), p[9], 1);
    if (mode == 6) {
        return ov83_02247FC8[index];
    }
    return ov83_02247F16[index];
}

u16 ov83_02240EF8(u16 value) {
    u32 i;

    for (i = 0; i < 27; i++) {
        if (value == ov83_02247EE0[i]) {
            return ov83_02247F16[i];
        }
    }
    for (i = 0; i < 32; i++) {
        if (value == ov83_02247F88[i]) {
            return ov83_02247FC8[i];
        }
    }
    GF_AssertFail();
    return 0;
}

u16 ov83_02240F48(void *work, int index, int mode) {
    u8 *p = work;

    ov83_0224777C(*(void **)(p + 0x50C), p[9], 1);
    if (mode == 6) {
        return ov83_02247F88[index];
    }
    return ov83_02247EE0[index];
}
