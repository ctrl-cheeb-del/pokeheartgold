#include "global.h"

typedef struct FWork {
    u8 data[0x700];
} FWork;
#define U8(p, o)  (*(u8 *)((p)->data + (o)))
#define U16(p, o) (*(u16 *)((p)->data + (o)))
#define U32(p, o) (*(u32 *)((p)->data + (o)))

extern FWork *_022577C0;
extern const u8 ov45_02254C30[];
extern u32 ov45_02254EF0;
extern void GF_AssertFail(void);
extern u32 ov45_0222F7B0(u32);
extern s32 ov45_0222FB5C(FWork *, s32, s32);
extern void ov45_02232170(void *, void *);
extern FWork *ov45_0222F74C(void);
extern void ov45_02232304(s32, s32, u32, s32);
extern u32 ov45_0222F7A8(u32);
extern void ov45_0222FB84(FWork *, u32);
extern u32 ov45_02232580(void);
extern void ov45_0222FA74(FWork *, s32, u32);
extern void ov45_0222EB94(void);
extern void ov45_022320C4(void *);
extern void ov45_0222F898(FWork *, s32, const void *, u32);
extern void ov45_0222F928(FWork *, s32, const void *);
extern void *ov45_0222F8D8(FWork *, s32);
extern s32 ov45_0222FB24(FWork *, s32, s32);
extern void ov45_02230008(s32, void *);
extern void ov45_0222F978(FWork *, s32);
extern void ov45_0222F8FC(FWork *, s32);
extern void ov45_0222FAF8(FWork *, s32, u32);

BOOL ov45_0222FBD8(FWork *work, s32 mode);
void ov45_0222FC44(int selected, u32 state);
void ov45_0222FCE0(s32 key, const void *record, const void *data, u32 size);
void ov45_0222FD50(s32 key);

BOOL ov45_0222FBD8(FWork *work, s32 mode) {
    u32 wanted;
    s32 count;
    s32 i;
    FWork *entry;

    GF_ASSERT(mode < 4);
    count = ov45_0222F7B0(mode);
    wanted = count;
    count = 0;
    i = count;
    if (i < U16(work, 0x11e)) {
        entry = work;
        do {
            s32 key = ov45_0222FB5C(work, i, 0);
            if (key != -1 && wanted == U32(entry, 0x34)) {
                count++;
            }
            i++;
            entry = (FWork *)(entry->data + 12);
        } while (i < U16(work, 0x11e));
    }
    return ov45_02254C30[mode] > count;
}

void ov45_0222FC44(int selected, u32 state) {
    FWork *work;

    if (state == 0) {
        U32(_022577C0, 0x5b4) = 0x400;
        ov45_02232170(_022577C0->data + 0x1b4, _022577C0->data + 0x5b4);
        work = ov45_0222F74C();
        if (work == NULL) {
            GF_AssertFail();
        }
        ov45_02232304(-1, 0, ov45_02254EF0, 0);
        return;
    }
    work = _022577C0;
    if (U8(work, 0x12d) == ov45_0222F7A8(state)) {
        if (selected == 1) {
            U8(work, 0x12f) = 1;
            ov45_0222FB84(_022577C0, U8(_022577C0, 0x12d));
            ov45_0222FA74(_022577C0, ov45_02232580(), 1);
        } else {
            U8(work, 0x12f) = 2;
        }
    } else {
        GF_AssertFail();
        ov45_0222EB94();
    }
}

void ov45_0222FCE0(s32 key, const void *record, const void *data, u32 size) {
    BOOL current;
    FWork *work;
    void *stored;
    void (*callback)(s32, void *, void *, BOOL);

    if (key == ov45_02232580()) {
        ov45_022320C4(_022577C0->data + 0x19c);
        current = TRUE;
    } else {
        current = FALSE;
    }
    ov45_0222FA74(_022577C0, key, 0);
    ov45_0222F898(_022577C0, key, data, size);
    ov45_0222F928(_022577C0, key, record);
    work = _022577C0;
    stored = ov45_0222F8D8(work, key);
    callback = (void (*)(s32, void *, void *, BOOL))U32(_022577C0, 0xc);
    callback(key, stored, (void *)U32(work, 0x20), current);
}

void ov45_0222FD50(s32 key) {
    s32 i;
    u32 offset;
    void (*callback)(s32, void *);

    if (ov45_0222FB24(_022577C0, key, 0) == -1) {
        return;
    }
    for (i = 0, offset = 0; i < 3; i++, offset += 0x4c) {
        if (key == *(s32 *)(_022577C0->data + 0x600 + offset)) {
            ov45_02230008(key, _022577C0->data + 0x5b8 + offset);
        }
    }
    callback = (void (*)(s32, void *))U32(_022577C0, 0x10);
    callback(key, (void *)U32(_022577C0, 0x20));
    ov45_0222F978(_022577C0, key);
    ov45_0222F8FC(_022577C0, key);
    ov45_0222FAF8(_022577C0, key, 0);
    ov45_0222FAF8(_022577C0, key, 1);
}
