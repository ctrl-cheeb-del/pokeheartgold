#include "global.h"

#include "overlay18_pokedex_index_helpers_private.h"

typedef struct CandidateEntry {
    u16 unk_0;
    u16 unk_2;
} CandidateEntry;

typedef struct CandidateApp {
    u8 filler_0000[0x878];
    CandidateEntry source[493];
    u16 count;
    u16 filler_102E;
    CandidateEntry entries[518];
    u8 filler_1848[0x10];
    u8 national;
} CandidateApp;

u16 ov18_021F8838(void *p) {
    int index = ov18_021F8824(p);
    return *(u16 *)((u8 *)p + 0x1030 + index * 4);
}

u32 ov18_021F8850(void *entry, u16 target) {
    u32 i;
    u16 first = 0;
    u16 count = *(u16 *)((u8 *)entry + 0x7B4);
    for (i = 0; i < count; i++, entry = (u8 *)entry + 4) {
        if (first == 0) {
            first = *(u16 *)entry;
        }
        if (target == *(u16 *)entry) {
            return target;
        }
    }
    return first;
}

void ov18_021F8884(void *p, int mode) {
    CandidateApp *app = p;
    u32 i;
    MI_CpuClear32(app->entries, sizeof(app->entries));
    if (mode == 1) {
        for (i = 0; i < app->count; i++) {
            u32 no = Pokedex_ConvertToCurrentDexNo(app->national, app->source[i].unk_0);
            CandidateApp *indexed;
            no--;
            indexed = (CandidateApp *)((u8 *)app + no * sizeof(CandidateEntry));
            indexed->entries[0].unk_0 = app->source[i].unk_0;
            indexed->entries[0].unk_2 = app->source[i].unk_2;
        }
    } else {
        for (i = 0; i < app->count; i++) {
            app->entries[i + 1].unk_0 = app->source[i].unk_0;
            app->entries[i + 1].unk_2 = app->source[i].unk_2;
        }
    }
}

u32 ov18_021F891C(void *p, int mode) {
    if (mode == 0) {
        return *(u16 *)((u8 *)p + 0x102C);
    }
    return Pokedex_ConvertToCurrentDexNo(*((u8 *)p + 0x1858), *(u16 *)((u8 *)p + 0x878 + (*(u16 *)((u8 *)p + 0x102C) - 1) * 4));
}

u32 ov18_021F8950(void *p, int mode) {
    if (mode == 0) {
        return ov18_021F891C(p, mode) / 15;
    }
    return (ov18_021F891C(p, mode) - 1) / 15;
}
