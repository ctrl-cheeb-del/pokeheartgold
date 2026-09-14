#include "global.h"

#include "unk_02005D10.h"
#include "unk_020379A0.h"

typedef struct Ov85Entry {
    void *unk_00;
    u8 pad_04[8];
    u32 unk_0C;
    u32 unk_10;
    u8 pad_14[8];
    fx32 unk_1C;
    u8 pad_20[0x90];
} Ov85Entry;

typedef struct Ov85Result {
    u8 pad_00[0x0C];
    u32 unk_0C;
    u32 unk_10;
} Ov85Result;

typedef struct Ov85Work {
    u32 state;
    u8 pad_004[8];
    s32 timer;
    u8 pad_010[0x10];
    u32 flags;
    u8 pad_024[4];
    Ov85Result *result;
    u8 pad_02C[4];
    s32 count;
    u8 pad_034[0x0C];
    u32 ready;
    u8 pad_044[0x1C];
    u16 position;
    u16 received_flags;
    u16 entry_positions[8];
    u8 pad_074[0x10];
    void *messages[5];
    void *names[5];
    u8 pad_0AC[0x24];
    void *menu;
    u8 pad_0D4[0x3C];
    fx32 position_fx;
    u8 pad_114[0x1BC];
    Ov85Entry entries[5];
} Ov85Work;

void GF_AssertFail(void);
BOOL sub_0203769C(void);
BOOL sub_02096D4C(void *menu, int command, void *data, int size);
BOOL ov85_021E8764(Ov85Work *work, fx32 value, s32 count);
void ov85_021E75C8(Ov85Work *work);
void ov85_021E7798(Ov85Work *work);
Ov85Result *ov85_021E7958(Ov85Work *work);
void ov85_021E73D4(Ov85Work *work, void *name, s32 index, u32 player);
void ov85_021E7400(Ov85Work *work, s32 index);
void ov85_021E71EC(Ov85Work *work, int message, void *player);
BOOL ov85_021E62B4(Ov85Work *work);
BOOL ov85_021E62D8(Ov85Work *work);
BOOL ov85_021E636C(Ov85Work *work);
BOOL ov85_021E63D8(Ov85Work *work);
BOOL ov85_021E6420(Ov85Work *work);

BOOL ov85_021E62B4(Ov85Work *work) {
    if (sub_02037B38(0xCA)) {
        if (sub_0203769C() == 0) {
            work->state = 0x22;
        } else {
            work->state = 0x23;
        }
    }
    return FALSE;
}

BOOL ov85_021E62D8(Ov85Work *work) {
    s32 i;
    u16 data[8];
    Ov85Entry *entry;

    data[0] = work->position_fx / (1 << FX32_SHIFT);
    work->flags = 0;
    i = 0;
    if (work->count > 0) {
        entry = work->entries;
        do {
            GF_ASSERT(entry->unk_00 != NULL);
            data[entry->unk_10 + 2] = entry->unk_1C / (1 << FX32_SHIFT);
            if (ov85_021E8764(work, entry->unk_1C, work->count) == 1) {
                work->flags |= 1 << entry->unk_0C;
            }
            i++;
            entry++;
        } while (i < work->count);
    }
    data[1] = work->flags;
    if (sub_02096D4C(work->menu, 15, data, 16) == 1) {
        work->state = 0x24;
    }
    return FALSE;
}

BOOL ov85_021E636C(Ov85Work *work) {
    s32 i;
    Ov85Entry *entry;
    u16 *received;

    if (work->ready == 1) {
        work->position_fx = work->position << FX32_SHIFT;
        received = &work->position;
        i = 0;
        if (work->count > 0) {
            entry = work->entries;
            do {
                GF_ASSERT(entry->unk_00 != NULL);
                entry->unk_1C = received[entry->unk_10 + 2] << FX32_SHIFT;
                i++;
                entry++;
            } while (i < work->count);
        }
        work->flags = received[1];
        ov85_021E75C8(work);
        ov85_021E7798(work);
        work->result = ov85_021E7958(work);
        work->state = 0x24;
    }
    return FALSE;
}

BOOL ov85_021E63D8(Ov85Work *work) {
    s32 i;
    s32 current = work->result->unk_10;

    for (i = 0; i < work->count; i++) {
        u32 name = work->entries[current].unk_0C;
        ov85_021E73D4(work, work->names[name], i, name);
        current = (current + 1) % work->count;
    }
    work->timer = 0;
    work->state = 0x25;
    return FALSE;
}

BOOL ov85_021E6420(Ov85Work *work) {
    s32 i;

    work->timer++;
    if (work->timer < 120) {
        return FALSE;
    }
    work->timer = 0;
    for (i = 0; i < work->count; i++) {
        ov85_021E7400(work, i);
    }
    ov85_021E71EC(work, 2, work->messages[work->result->unk_0C]);
    PlayFanfare(0x4A1);
    work->state = 0x26;
    return FALSE;
}
