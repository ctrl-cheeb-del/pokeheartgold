#include "global.h"

#include "gf_gfx_loader.h"
#include "heap.h"
#include "location_gmm_dat.h"
#include "save_wifi_history.h"

#define ADD(p, n)   ((void *)((u8 *)(p) + (n)))
#define U32AT(p, n) (*(u32 *)((u8 *)(p) + (n)))
#define S16AT(p, n) (*(s16 *)((u8 *)(p) + (n)))

typedef struct Ov69Rec6 {
    u16 kind;
    s16 x;
    s16 y;
} Ov69Rec6;
typedef struct Ov69Rec4 {
    s16 x;
    s16 y;
} Ov69Rec4;
typedef struct Ov69Entry {
    s16 x;
    s16 y;
    MtxFx33 mtx;
    s16 state;
    s16 country;
    s16 city;
} Ov69Entry;
typedef struct Ov69List {
    u32 heap;
    SaveWiFiHistory *history;
    u32 unused;
    u32 count;
    Ov69Entry entries[1];
} Ov69List;
typedef struct Ov69Late {
    u8 pad[0xC2C4];
    s32 selectedX;
    s32 selectedY;
    u8 pad2[0x58];
    u32 country;
    u32 city;
} Ov69Late;

extern const MtxFx33 ov69_021E7770;
void ov69_021E7120(MtxFx33 *, VecFx32 *);
void ov69_021E6138(void *);
void ov69_021E623C(void *, u32, s32, s32, u16, u16);
void ov69_021E62B0(void *);

void ov69_021E6138(void *p) {
    u32 size1;
    u32 size2;
    NARC *narc;
    void *buf1;
    void *buf2;
    const Ov69Rec6 *rec6;
    const Ov69Rec4 *rec4;
    s32 nCountry;
    s32 nCity;
    s32 i;
    s32 j;
    Ov69List *list;

    list = p;
    narc = NARC_New((NarcId)0x62, (enum HeapID)list->heap);
    list->count = 0;
    buf1 = GfGfxLoader_LoadFromOpenNarc_GetSizeOut(narc, 0x12, FALSE, (enum HeapID)list->heap, FALSE, &size1);
    nCity = size1 / 6;
    rec6 = ADD(buf1, 6);
    i = 1;
    for (; i < nCity; i++) {
        if (rec6->kind != 2) {
            ov69_021E623C(list, list->count, rec6->x, rec6->y, (u16)i, 0);
            list->count++;
        }
        rec6++;
    }
    Heap_Free(buf1);
    i = 1;
    nCountry = LocationGmmDatCountGet();
    for (; i < nCountry; i++) {
        buf2 = GfGfxLoader_LoadFromOpenNarc_GetSizeOut(narc, LocationGmmDatGetEarthPlaceDatId(i), FALSE, (enum HeapID)list->heap, FALSE, &size2);
        nCity = size2 / 4;
        rec4 = ADD(buf2, 4);
        j = 1;
        for (; j < nCity; j++) {
            ov69_021E623C(list, list->count, rec4->x, rec4->y, (u16)LocationGmmDatGetCountryMsgNo(i), (u16)j);
            list->count++;
            rec4++;
        }
        Heap_Free(buf2);
    }
    NARC_Delete(narc);
}

void ov69_021E623C(void *p, u32 idx, s32 x, s32 y, u16 country, u16 city) {
    Ov69List *list;
    MtxFx33 mtx;
    VecFx32 rot;

    list = p;
    mtx = ov69_021E7770;
    list->entries[idx].x = (s16)x;
    list->entries[idx].y = (s16)y;
    rot.x = x;
    rot.y = y;
    rot.z = 0;
    ov69_021E7120(&mtx, &rot);
    list->entries[idx].mtx = mtx;
    list->entries[idx].state = (s16)WiFiHistory_GetLocationSeenState(list->history, country, city);
    list->entries[idx].country = (s16)country;
    list->entries[idx].city = (s16)city;
}

void ov69_021E62B0(void *p) {
    u32 i;
    u8 *entry;
    Ov69Late *work;

    work = p;
    for (i = 0; i < U32AT(p, 0xC); i++) {
        entry = ADD(p, i * 0x30);
        if (work->country == *(u16 *)(entry + 0x3A) && work->city == *(u16 *)(entry + 0x3C)) {
            *(u16 *)(entry + 0x38) = 3;
            work->selectedX = S16AT(entry, 0x10);
            work->selectedY = S16AT(entry, 0x12);
        }
    }
}
