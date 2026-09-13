#include "global.h"

#include "constants/sndseq.h"
extern u8 SDK_OVERLAY_OVY_90_ID[];

typedef struct R27State {
    void *manager;
    u32 slots[13];
    u8 active;
    u8 unk39;
    u16 heapId;
    void *context;
    void *field40;
    void *field44;
} R27State;

typedef struct R27Profiles {
    u32 unk00;
    u8 slotIds[4];
    u8 pad08[0x14];
    u32 unk1C;
    void *profiles[4];
    void *context;
    u8 flag38;
    u8 flag39;
    u8 pad3A[2];
    u32 field3C;
} R27Profiles;

typedef void (*Cb3)(R27State *, void *, void *);
typedef void (*Cb2)(R27State *, void *);
typedef void (*Cb1)(void *);
extern Cb3 ov45_02254E88[];
extern Cb2 ov45_02254E54[];
extern Cb2 ov45_02254EBC[];
extern Cb1 _02254E20[];
extern u8 ov45_02254B04[], ov45_02254B14[], ov45_02254B24[], ov45_02254B34[];
extern u8 ov45_02254B54[], ov45_02254B64[], ov45_02254B74[], ov45_02254B84[];
extern u8 ov45_02254B94[], ov45_02254BA4[];

extern void GF_AssertFail(void);
extern void *OverlayManager_New(const void *, void *, u32);
extern void *Heap_Alloc(u32, u32);
extern void Heap_Free(void *);
extern void *PlayerProfile_New(u32);
extern void *ov45_0222A5C0(void *);
extern void *ov45_0222AAC8(void *);
extern void ov45_0222AB38(void *, void *);
extern void ov45_0222A498(void *, void *);
extern void *ov45_0222A578(void *, u8);
extern void ov45_0222A844(void *, void *, u32);
extern void *ov45_0222AD2C(void *);
extern void *ov45_0222AD3C(void *);
extern void *ov45_0222A214(void *);
extern void **ov45_0222A22C(void *);
extern int ov45_0222A33C(void *);
extern void *ov45_0222A210(void *);
extern void ov45_0222A430(void *, void *);
extern void ov45_0222A72C(void *, void *);
extern void HandleLoadOverlay(u32, u32);
extern void UnloadOverlayByID(u32);

void ov45_0222CDC4(R27State *st, void **arg, const void *templ);
void ov45_0222CDE4(R27State *st, u32 i, void *arg);
void ov45_0222CE0C(R27State *st, u32 i);
void ov45_0222CE2C(R27State *st, u32 i);
void ov45_0222CE54(R27State *st, u32 i);
void ov45_0222CE78(R27Profiles *p, u32 heap);
void ov45_0222CE94(R27Profiles *p);
void ov45_0222CEB0(R27Profiles *p, void *ctx, u32 arg);
void ov45_0222CF00(R27State *st, void **out, u32 heap);
void ov45_0222CF24(void **p);
void ov45_0222CF40(R27State *st, void ***arg);
int ov45_0222CF68(R27State *st, void **arg);
void ov45_0222CFF4(R27State *st, void **out, u32 heap);
void ov45_0222D01C(void **p);
void ov45_0222D028(R27State *st, void ***arg);
int ov45_0222D054(R27State *st);
void ov45_0222D078(R27State *st, void **out, u32 heap);
void ov45_0222D0BC(void **p);
void ov45_0222D0C8(R27State *st, void **arg);
int ov45_0222D0D8(R27State *st);
void ov45_0222D0FC(R27State *st, void **out, u32 heap);
void ov45_0222D130(void **p);
void ov45_0222D13C(R27State *st, void **arg);
int ov45_0222D14C(R27State *st, void **arg);
void ov45_0222D164(R27State *st, void **out, u32 heap);
void ov45_0222D19C(void **out);
void ov45_0222D1B0(R27State *st, void **arg);
int ov45_0222D1DC(R27State *st, void **arg);
void ov45_0222D20C(R27State *st, void **out, u32 heap);
void ov45_0222D23C(void **out);
void ov45_0222D250(R27State *st, void **arg);
int ov45_0222D27C(R27State *st, void **arg);
void ov45_0222D2AC(R27State *st, void **out, u32 heap);
void ov45_0222D2E4(void **out);
void ov45_0222D2F8(R27State *st, void **arg);
int ov45_0222D324(R27State *st, void **arg);
void ov45_0222D354(R27State *st, void **out, u32 heap);
void ov45_0222D380(void **p);
int ov45_0222D38C(R27State *st);
void ov45_0222D3B0(R27State *st, void **arg);
void ov45_0222D3C4(R27State *st, void **arg);
void ov45_0222D3D8(R27State *st, void **out, u32 heap);
void ov45_0222D410(void **p);
void ov45_0222D41C(R27State *st, void **arg);
void ov45_0222D428(R27State *st, void **arg);
void ov45_0222D434(R27State *st, void **arg, u32 v);

void ov45_0222CDC4(R27State *st, void **arg, const void *templ) {
    if (st->manager != NULL) {
        GF_AssertFail();
    }
    st->manager = OverlayManager_New(templ, *arg, st->heapId);
}
void ov45_0222CDE4(R27State *st, u32 i, void *arg) {
    if (i >= 13) {
        GF_AssertFail();
    }
    ov45_02254E88[i](st, &st->slots[i], arg);
}
void ov45_0222CE0C(R27State *st, u32 i) {
    if (i >= 13) {
        GF_AssertFail();
    }
    _02254E20[i](&st->slots[i]);
}
void ov45_0222CE2C(R27State *st, u32 i) {
    if (i >= 13) {
        GF_AssertFail();
    }
    ov45_02254E54[i](st, &st->slots[i]);
    st->active = i;
}
void ov45_0222CE54(R27State *st, u32 i) {
    if (i >= 13) {
        GF_AssertFail();
    }
    ov45_02254EBC[i](st, &st->slots[i]);
}
void ov45_0222CE78(R27Profiles *p, u32 heap) {
    int i;
    for (i = 0; i < 4; i++) {
        p->profiles[i] = PlayerProfile_New(heap);
    }
}
void ov45_0222CE94(R27Profiles *p) {
    int i;
    void *nullp = NULL;
    for (i = 0; i < 4; i++) {
        Heap_Free(p->profiles[i]);
        p->profiles[i] = nullp;
    }
}
void ov45_0222CEB0(R27Profiles *p, void *ctx, u32 arg) {
    int i;
    void *v = ov45_0222AAC8(ov45_0222A5C0(ctx));
    p->unk00 = (u32)v;
    ov45_0222AB38(ctx, &p->slotIds[4]);
    ov45_0222A498(ctx, p->slotIds);
    p->context = ctx;
    p->unk1C = 0;
    for (i = 0; i < 4; i++) {
        void *x = ov45_0222A578(ctx, p->slotIds[i]);
        if (x) {
            ov45_0222A844(x, p->profiles[i], arg);
        }
    }
}
void ov45_0222CF00(R27State *st, void **out, u32 heap) {
    R27State *state = st;
    void **dest = out;
    u32 *p;
    *dest = Heap_Alloc(heap, 0x20);
    memset(*dest, 0, 0x20);
    p = *dest;
    p[0] = (u32)state->field40;
    p[7] = (u32)state->context;
}
void ov45_0222CF24(void **p) {
    if (*p == NULL) {
        GF_AssertFail();
    }
    Heap_Free(*p);
    *p = NULL;
}
void ov45_0222CF40(R27State *st, void ***arg) {
    void **p = *arg;
    p[1] = ov45_0222AD2C(st->context);
    p[2] = ov45_0222AD3C(st->context);
    ov45_0222CDC4(st, (void **)arg, ov45_02254B94);
}
int ov45_0222CF68(R27State *st, void **arg) {
    switch (((u32 *)*arg)[6]) {
    case 0:
        ov45_0222CE2C(st, 9);
        break;
    case 1:
        ov45_0222CE2C(st, 1);
        break;
    case 2:
        ov45_0222CE2C(st, 2);
        break;
    case 6:
        ov45_0222CE2C(st, 3);
        break;
    case 7:
        ov45_0222CE2C(st, 4);
        break;
    case 3:
        ov45_0222CE2C(st, 6);
        break;
    case 4:
        ov45_0222CE2C(st, 7);
        break;
    case 5:
        ov45_0222CE2C(st, 8);
        break;
    case 8:
        ov45_0222CE2C(st, 10);
        break;
    case 9:
        ov45_0222CE2C(st, 11);
        break;
    case 10:
        ov45_0222CE2C(st, 12);
        break;
    default:
        GF_AssertFail();
    }
    return 0;
}
void ov45_0222CFF4(R27State *st, void **out, u32 heap) {
    u8 *p;
    u32 count;
    p = Heap_Alloc(heap, 0x10);
    *out = p;
    count = 0x10;
    do {
        *p = 0;
        p++;
        count--;
    } while (count);
    p = *out;
    *(u32 *)(p + 4) = (u32)st->field40;
    *(u32 *)(p + 0xc) = (u32)st->context;
}
void ov45_0222D01C(void **p) {
    Heap_Free(*p);
}
void ov45_0222D028(R27State *st, void ***arg) {
    void **p = *arg;
    p[0] = ov45_0222A214(st->context);
    p[2] = *ov45_0222A22C(st->context);
    ov45_0222CDC4(st, (void **)arg, ov45_02254B84);
}
int ov45_0222D054(R27State *st) {
    if (ov45_0222A33C(st->context)) {
        ov45_0222CE2C(st, 10);
    } else {
        ov45_0222CE2C(st, 0);
    }
    return 0;
}
void ov45_0222D078(R27State *st, void **out, u32 heap) {
    u8 *p = Heap_Alloc(heap, 12);
    *out = p;
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
    p = *out;
    *(void **)p = ov45_0222A210(st->context);
    *(void **)(p + 4) = ov45_0222A22C(st->context);
    *(void **)(p + 8) = st->context;
}
void ov45_0222D0BC(void **p) {
    Heap_Free(*p);
}
void ov45_0222D0C8(R27State *st, void **arg) {
    ov45_0222CDC4(st, (void **)arg, ov45_02254B74);
}
int ov45_0222D0D8(R27State *st) {
    if (ov45_0222A33C(st->context)) {
        ov45_0222CE2C(st, 10);
    } else {
        ov45_0222CE2C(st, 0);
    }
    return 0;
}
void ov45_0222D0FC(R27State *st, void **out, u32 heap) {
    u8 *p;
    u32 count;
    p = Heap_Alloc(heap, 0x14);
    *out = p;
    count = 0x14;
    do {
        *p = 0;
        p++;
        count--;
    } while (count);
    p = *out;
    *(void **)p = st->field40;
    *(void **)(p + 4) = st->context;
    *(u32 *)(p + 8) = st->unk39;
    *(void **)(p + 0xc) = st->field44;
}
void ov45_0222D130(void **p) {
    Heap_Free(*p);
}
void ov45_0222D13C(R27State *st, void **arg) {
    ov45_0222CDC4(st, (void **)arg, ov45_02254B64);
}
int ov45_0222D14C(R27State *st, void **arg) {
    if (((u32 *)*arg)[4] == 0) {
        return 1;
    }
    ov45_0222CE2C(st, 0);
    return 0;
}
void ov45_0222D164(R27State *st, void **out, u32 heap) {
    u8 *p;
    *out = Heap_Alloc(heap, 0x3c);
    memset(*out, 0, 0x3c);
    p = *out;
    p[0x38] = 0;
    p[0x39] = 1;
    *(void **)(p + 0x34) = st->field40;
    ov45_0222CE78((R27Profiles *)p, heap);
}
void ov45_0222D19C(void **out) {
    ov45_0222CE94(*out);
    Heap_Free(*out);
}
void ov45_0222D1B0(R27State *st, void **arg) {
    HandleLoadOverlay((u32)SDK_OVERLAY_OVY_90_ID, 2);
    ov45_0222CEB0(*arg, st->context, st->heapId);
    ov45_0222CDC4(st, (void **)arg, ov45_02254B54);
}
int ov45_0222D1DC(R27State *st, void **arg) {
    R27Profiles *p;
    UnloadOverlayByID((u32)SDK_OVERLAY_OVY_90_ID);
    p = *arg;
    ov45_0222A430(st->context, (void *)p->unk1C);
    ov45_0222A72C(st->context, (void *)p->unk00);
    ov45_0222CE2C(st, 0);
    return 0;
}
void ov45_0222D20C(R27State *st, void **out, u32 heap) {
    u8 *p;
    *out = Heap_Alloc(heap, 0x40);
    memset(*out, 0, 0x40);
    p = *out;
    *(u32 *)(p + 0x3c) = 0;
    *(u32 *)(p + 0x38) = 1;
    *(void **)(p + 0x34) = st->field40;
    ov45_0222CE78((R27Profiles *)p, heap);
}
void ov45_0222D23C(void **out) {
    ov45_0222CE94(*out);
    Heap_Free(*out);
}
void ov45_0222D250(R27State *st, void **arg) {
    HandleLoadOverlay((u32)SDK_OVERLAY_OVY_90_ID, 2);
    ov45_0222CEB0(*arg, st->context, st->heapId);
    ov45_0222CDC4(st, (void **)arg, ov45_02254BA4);
}
int ov45_0222D27C(R27State *st, void **arg) {
    R27Profiles *p;
    UnloadOverlayByID((u32)SDK_OVERLAY_OVY_90_ID);
    p = *arg;
    ov45_0222A430(st->context, (void *)p->unk1C);
    ov45_0222A72C(st->context, (void *)p->unk00);
    ov45_0222CE2C(st, 0);
    return 0;
}
void ov45_0222D2AC(R27State *st, void **out, u32 heap) {
    u8 *p;
    *out = Heap_Alloc(heap, 0x3c);
    memset(*out, 0, 0x3c);
    p = *out;
    p[0x38] = 0;
    p[0x39] = 1;
    *(void **)(p + 0x34) = st->field40;
    ov45_0222CE78((R27Profiles *)p, heap);
}
void ov45_0222D2E4(void **out) {
    ov45_0222CE94(*out);
    Heap_Free(*out);
}
void ov45_0222D2F8(R27State *st, void **arg) {
    HandleLoadOverlay((u32)SDK_OVERLAY_OVY_90_ID, 2);
    ov45_0222CEB0(*arg, st->context, st->heapId);
    ov45_0222CDC4(st, (void **)arg, ov45_02254B34);
}
int ov45_0222D324(R27State *st, void **arg) {
    R27Profiles *p;
    UnloadOverlayByID((u32)SDK_OVERLAY_OVY_90_ID);
    p = *arg;
    ov45_0222A430(st->context, (void *)p->unk1C);
    ov45_0222A72C(st->context, (void *)p->unk00);
    ov45_0222CE2C(st, 0);
    return 0;
}
void ov45_0222D354(R27State *st, void **out, u32 heap) {
    u8 *p = Heap_Alloc(heap, 8);
    *out = p;
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;
    *(void **)*out = st->context;
}
void ov45_0222D380(void **p) {
    Heap_Free(*p);
}
int ov45_0222D38C(R27State *st) {
    if (ov45_0222A33C(st->context)) {
        ov45_0222CE2C(st, 10);
    } else {
        ov45_0222CE2C(st, 0);
    }
    return 0;
}
void ov45_0222D3B0(R27State *st, void **arg) {
    ((u8 *)*arg)[4] = 0;
    ov45_0222CDC4(st, (void **)arg, ov45_02254B24);
}
void ov45_0222D3C4(R27State *st, void **arg) {
    ((u8 *)*arg)[4] = 1;
    ov45_0222CDC4(st, (void **)arg, ov45_02254B14);
}
void ov45_0222D3D8(R27State *st, void **out, u32 heap) {
    u8 *p = Heap_Alloc(heap, 12);
    *out = p;
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
    p = *out;
    *(void **)p = st->field40;
    *(void **)(p + 4) = st->context;
}
void ov45_0222D410(void **p) {
    Heap_Free(*p);
}
void ov45_0222D41C(R27State *st, void **arg) {
    ov45_0222D434(st, arg, 0);
}
void ov45_0222D428(R27State *st, void **arg) {
    ov45_0222D434(st, arg, 1);
}
void ov45_0222D434(R27State *st, void **arg, u32 v) {
    ((u32 *)*arg)[2] = v;
    ov45_0222CDC4(st, (void **)arg, ov45_02254B04);
}
