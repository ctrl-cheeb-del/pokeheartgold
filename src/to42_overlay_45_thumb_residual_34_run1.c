#include "global.h"

typedef struct FWork {
    u8 data[0x600];
} FWork;
typedef struct FRec {
    u32 a, b, c;
} FRec;

extern void GF_AssertFail(void);
extern void *Heap_Alloc(u32, u32);
extern void Heap_Free(void *);
extern FWork *_022577C0;
extern s32 ov45_0222FB24(FWork *, s32, s32);
extern void ov45_0222FA40(FWork *, u32);
void ov45_0222F848(void *, u32, u32);
void ov45_0222F878(void);
void ov45_0222F88C(FWork *, s32, void *);
void ov45_0222F898(FWork *, s32, const void *, u32);
void *ov45_0222F8D8(FWork *, s32);
void ov45_0222F8FC(FWork *, s32);
void ov45_0222F928(FWork *, s32, const void *);
void *ov45_0222F954(FWork *, s32);
void ov45_0222F978(FWork *, s32);
void ov45_0222F9B8(FWork *, u32, u32, u32);
void ov45_0222FA10(FWork *);

#define U32(p, o) (*(u32 *)((p)->data + (o)))

void ov45_0222F848(void *unused, u32 size, u32 heap) {
    u32 bytes = size * 20;
    U32(_022577C0, 0x24) = (u32)Heap_Alloc(heap, bytes);
    memset((void *)U32(_022577C0, 0x24), 0, bytes);
    U32(_022577C0, 0x28) = size;
}

void ov45_0222F878(void) {
    Heap_Free((void *)U32(_022577C0, 0x24));
}

void ov45_0222F88C(FWork *work, s32 key, void *source) {
    ov45_0222F898(work, key, source, U32(work, 0x28));
}

void ov45_0222F898(FWork *work, s32 key, const void *source, u32 size) {
    s32 index;
    u32 stride, offset;
    u8 *base;
    index = ov45_0222FB24(work, key, 0);
    if (index == -1) {
        GF_AssertFail();
    }
    stride = U32(work, 0x28);
    base = (u8 *)U32(work, 0x24);
    offset = stride * index;
    if (stride > size) {
        memset(base + offset, 0, stride);
    } else {
        size = stride;
    }
    memcpy(base + offset, source, size);
}

void *ov45_0222F8D8(FWork *work, s32 key) {
    s32 index = ov45_0222FB24(work, key, 0);
    if (index == -1) {
        GF_AssertFail();
    }
    return (u8 *)U32(work, 0x24) + U32(work, 0x28) * index;
}

void ov45_0222F8FC(FWork *work, s32 key) {
    s32 index = ov45_0222FB24(work, key, 0);
    if (index == -1) {
        GF_AssertFail();
    }
    memset((u8 *)U32(work, 0x24) + U32(work, 0x28) * index, 0, U32(work, 0x28));
}

void ov45_0222F928(FWork *work, s32 key, const void *source) {
    s32 index = ov45_0222FB24(work, key, 0);
    FRec *destination;
    if (index == -1) {
        GF_AssertFail();
    }
    destination = (FRec *)(work->data + 0x2c + 12 * index);
    *destination = *(const FRec *)source;
}

void *ov45_0222F954(FWork *work, s32 key) {
    s32 index = ov45_0222FB24(work, key, 0);
    if (index == -1) {
        GF_AssertFail();
    }
    return work->data + 0x2c + 12 * index;
}

void ov45_0222F978(FWork *work, s32 key) {
    s32 index = ov45_0222FB24(work, key, 0);
    u8 *p;
    if (index == -1) {
        GF_AssertFail();
    }
    p = work->data + 0x2c + 12 * index;
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;
    p[8] = 0;
    p[9] = 0;
    p[10] = 0;
    p[11] = 0;
}

void ov45_0222F9B8(FWork *work, u32 count0, u32 count1, u32 heap) {
    s32 i;
    u32 count;
    FWork *p;
    for (i = 0; i < 2; i++) {
        p = (FWork *)(work->data + i * 8);
        if (U32(p, 0x120) != 0) {
            GF_AssertFail();
        }
        if (i == 0) {
            count = count0;
        } else {
            count = count1;
        }
        *(s16 *)(p->data + 0x11c) = 0;
        U32(p, 0x120) = (u32)Heap_Alloc(heap, count * 4);
        *(u16 *)(p->data + 0x11e) = count;
        ov45_0222FA40(work, i);
    }
}

void ov45_0222FA10(FWork *work) {
    s32 i;
    for (i = 0; i < 2; i++) {
        FWork *p = (FWork *)(work->data + 8 * i);
        if (U32(p, 0x120) == 0) {
            GF_AssertFail();
        }
        Heap_Free((void *)U32(p, 0x120));
        U32(p, 0x120) = 0;
    }
}
