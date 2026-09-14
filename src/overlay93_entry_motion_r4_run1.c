#include "global.h"

#include "sprite_system.h"

typedef struct Ov93Entry {
    u32 active;
    u16 value4;
    u16 value6;
    u32 value8;
    s16 delay;
    u8 kind;
    u8 padF;
    ManagedSprite *sprite;
    const u8 *config;
} Ov93Entry;

typedef struct Ov93Request {
    u8 id;
    u8 side;
    u16 value;
    u32 payload4;
    u32 payload8;
} Ov93Request;

typedef struct Ov93Position {
    s16 x;
    s16 y;
    u16 animation;
    u8 priority;
} Ov93Position;

typedef struct Ov93System {
    u8 pad00[0x2fbc];
    u32 field2fbc;
    u8 pad2fc0[0xc];
    u32 field2fcc;
    u8 pad2fd0[0xc];
    Ov93Entry entries[40];
} Ov93System;

extern void GF_AssertFail(void);
extern u32 sub_0203769C(void);
extern u32 ov93_0225E3C4(void *sys, u32 id);
extern void ov93_0225DF38(void *sys, u32 payload);
extern void ov93_02261C58(void *sys, void *arg1, u32 arg2, u32 arg3, u32 arg4);
extern BOOL ov93_02260080(void *sys, Ov93Entry *entry);
extern void ov93_0225FE08(void *sys, void *arg1, u32 arg2, s16 arg3, u32 arg4);
extern const u8 ov93_02263010[];
extern const s32 ov93_02262CA4[];
extern const ManagedSpriteTemplate ov93_02262DCC;
extern BOOL ov93_022614F4(void *sys, void **out);
extern void ov93_02260FB8(void *sys, u32 kind);
extern void *ov93_02260F84(void *sys);
extern void ov93_02261528(void *entry, u8 state);
extern void ov93_022627E8(void *sys, const void *body);

u32 ov93_0225FF1C(void *sys, const Ov93Request *request, Ov93Entry *entry);
BOOL ov93_0225FEC4(void *sys, const Ov93Request *request);
void ov93_0225FFF8(void *sys);
ManagedSprite *ov93_0226027C(void *sys, const Ov93Position *position);

BOOL ov93_0225FEC4(void *sys, const Ov93Request *request) {
    int i;
    u8 *scan;

    for (i = 0, scan = sys; i < 40; i++, scan += sizeof(Ov93Entry)) {
        if (*(u32 *)(scan + 0x2fdc) == 0) {
            ov93_02261C58(sys, (u8 *)sys + 0x1560, request->side, request->id, ov93_0225FF1C(sys, request, &((Ov93System *)sys)->entries[i]));
            return TRUE;
        }
    }
    GF_AssertFail();
    return FALSE;
}

u32 ov93_0225FF1C(void *sys, const Ov93Request *request, Ov93Entry *entry) {
    void *work = sys;
    s16 x;
    s16 y;
    const u8 *config;
    s32 delta;

    if (entry->active != 0) {
        GF_AssertFail();
    }
    MI_CpuFill8(entry, 0, sizeof(*entry));
    config = ov93_02263010 + (*(u8 *)((u8 *)*(void **)work + 0x30) * 40) + ov93_0225E3C4(work, request->id) * 10;
    entry->value4 = request->id;
    entry->value6 = request->value;
    entry->value8 = request->payload8;
    entry->config = config;
    entry->kind = request->side;
    entry->sprite = ov93_0226027C(work, (const Ov93Position *)config);
    if (request->id == sub_0203769C()) {
        ov93_0225DF38(work, request->payload4);
        entry->delay = 25;
        ManagedSprite_SetDrawFlag(entry->sprite, FALSE);
    }
    entry->active = 1;
    delta = 0;
    ManagedSprite_GetPositionXYWithSubscreenOffset(entry->sprite, &x, &y, 0x160000);
    switch (config[7]) {
    case 0:
        delta = 28 - y;
        break;
    case 1:
        delta = x - 204;
        break;
    case 2:
        delta = y - 164;
        break;
    case 3:
        delta = 52 - x;
        break;
    }
    return (delta << 12) / (5 << 12);
}

void ov93_0225FFF8(void *sys) {
    Ov93Entry *entry = (Ov93Entry *)((u8 *)sys + 0x2fdc);
    int i;

    for (i = 0; i < 40; i++, entry++) {
        if (entry->active == 1) {
            if (entry->delay > 0) {
                entry->delay--;
                if (entry->delay == 0) {
                    ManagedSprite_SetDrawFlag(entry->sprite, TRUE);
                }
            } else if (ov93_02260080(sys, entry) == TRUE) {
                if (((Ov93System *)sys)->field2fcc == 1 && ((Ov93System *)sys)->field2fbc == 0) {
                    ov93_0225FE08(sys, (u8 *)sys + 0x1428, entry->value8, entry->value4, entry->kind);
                }
                Sprite_DeleteAndFreeResources(entry->sprite);
                entry->active = 0;
            }
        }
    }
}
