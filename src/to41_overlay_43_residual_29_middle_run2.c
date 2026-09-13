#include "to41_overlay_43_residual_29_middle_private.h"

#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define S8(p, o)  (*(s8 *)((u8 *)(p) + (o)))
#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))

typedef struct Ov43Entry {
    u8 pad_00[0xb];
    s8 playerIndex;
    u8 pad_0c[0xc];
    u8 playerIds[4];
} Ov43Entry;

#define GET_PLAYER_INDEX(entry) (((Ov43Entry *)(entry))->playerIds[((Ov43Entry *)(entry))->playerIndex])

void ov43_0222E5B4(void *windows, void *entry, void *display, u32 heapId) {
    void *frontier = Save_Frontier_GetStatic(PTR(entry, 4));
    String *raw = String_New(0x80, heapId);
    String *expanded = String_New(0x80, heapId);
    u32 value;

    ov43_0222EC58(windows, 4, 0, entry, display, 0x1f, 0, 0, 0x10200, raw, expanded, 0);
    ov43_0222EC58(windows, 4, 0, entry, display, 0x29, 0x68, 0x14, 0x10200, raw, expanded, 0);
    value = FrontierSave_GetStat(frontier, 0x6c, GET_PLAYER_INDEX(entry));
    ov43_0222EC58(windows, 4, 0, entry, display, value == 0 ? 0x22 : 0x23, 0, 0x30, 0x10200, raw, expanded, 0);
    ov43_0222ABFC(display, FrontierSave_GetStat(frontier, 0x87, GET_PLAYER_INDEX(entry)));
    ov43_0222EC58(windows, 4, 0, entry, display, 0x2d, 0x70, 0x30, 0x10200, raw, expanded, 1);
    ov43_0222ABFC(display, FrontierSave_GetStat(frontier, 0x88, GET_PLAYER_INDEX(entry)));
    ov43_0222EC58(windows, 4, 0, entry, display, 0x2c, 0xa8, 0x30, 0x10200, raw, expanded, 0);
    ov43_0222EC58(windows, 4, 0, entry, display, 0x24, 0, 0x48, 0x10200, raw, expanded, 0);
    ov43_0222ABFC(display, FrontierSave_GetStat(frontier, 0x86, GET_PLAYER_INDEX(entry)));
    ov43_0222EC58(windows, 4, 0, entry, display, 0x2d, 0x70, 0x48, 0x10200, raw, expanded, 1);
    ov43_0222ABFC(display, FrontierSave_GetStat(frontier, 0x8a, GET_PLAYER_INDEX(entry)));
    ov43_0222EC58(windows, 4, 0, entry, display, 0x2c, 0xa8, 0x48, 0x10200, raw, expanded, 0);
    ov43_0222DEF8(windows, 4);
    String_Delete(raw);
    String_Delete(expanded);
}

void ov43_0222E78C(void *windows, void *entry, void *display, u32 heapId) {
    void *frontier = Save_Frontier_GetStatic(PTR(entry, 4));
    String *raw = String_New(0x80, heapId);
    String *expanded = String_New(0x80, heapId);
    String *species;
    u32 value;

    ov43_0222EC58(windows, 5, 0, entry, display, 0x20, 0, 0, 0x10200, raw, expanded, 0);
    value = FrontierSave_GetStat(frontier, 0x7c, GET_PLAYER_INDEX(entry));
    species = GetSpeciesName(value, heapId);
    AddTextPrinterParameterizedWithColor((Window *)PTR((u8 *)windows + 0x20, 0),
        0,
        species,
        0,
        0x18,
        0xff,
        0x10200,
        NULL);
    String_Delete(species);
    value = FrontierSave_GetStat(frontier, 0x6a, GET_PLAYER_INDEX(entry));
    ov43_0222EC58(windows, 5, 0, entry, display, value == 0 ? 0x22 : 0x23, 0, 0x30, 0x10200, raw, expanded, 0);
    ov43_0222ABFC(display, FrontierSave_GetStat(frontier, 0x7b, GET_PLAYER_INDEX(entry)));
    ov43_0222EC58(windows, 5, 0, entry, display, 0x25, 0x70, 0x30, 0x10200, raw, expanded, 1);
    ov43_0222EC58(windows, 5, 0, entry, display, 0x24, 0, 0x48, 0x10200, raw, expanded, 0);
    ov43_0222ABFC(display, FrontierSave_GetStat(frontier, 0x7a, GET_PLAYER_INDEX(entry)));
    ov43_0222EC58(windows, 5, 0, entry, display, 0x25, 0x70, 0x48, 0x10200, raw, expanded, 1);
    ov43_0222DEF8(windows, 5);
    String_Delete(raw);
    String_Delete(expanded);
}

void ov43_0222E904(void *windows, void *entry, void *display, u32 heapId) {
    void *frontier = Save_Frontier_GetStatic(PTR(entry, 4));
    String *raw = String_New(0x80, heapId);
    String *expanded = String_New(0x80, heapId);
    u8 *player;
    u32 value;

    ov43_0222EC58(windows, 6, 0, entry, display, 0x21, 0, 0, 0x10200, raw, expanded, 0);
    player = (u8 *)entry + S8(entry, 0xb);
    value = FrontierSave_GetStat(frontier, 0x6e, player[0x18]);
    ov43_0222EC58(windows, 6, 0, entry, display, value == 0 ? 0x22 : 0x23, 0, 0x18, 0x10200, raw, expanded, 0);
    ov43_0222ABFC(display, FrontierSave_GetStat(frontier, 0x8f, GET_PLAYER_INDEX(entry)));
    ov43_0222EC58(windows, 6, 0, entry, display, 0x2e, 0x70, 0x18, 0x10200, raw, expanded, 1);
    ov43_0222EC58(windows, 6, 0, entry, display, 0x24, 0, 0x30, 0x10200, raw, expanded, 0);
    ov43_0222ABFC(display, FrontierSave_GetStat(frontier, 0x8e, GET_PLAYER_INDEX(entry)));
    ov43_0222EC58(windows, 6, 0, entry, display, 0x2e, 0x70, 0x30, 0x10200, raw, expanded, 1);
    ov43_0222DEF8(windows, 6);
    String_Delete(raw);
    String_Delete(expanded);
}

void ov43_0222EA40(void *windows, void *entry, void *display, u32 heapId) {
    void *records;
    String *raw;
    String *expanded;

    Save_Frontier_GetStatic(PTR(entry, 4));
    records = sub_0202C6F4(PTR(entry, 4));
    raw = String_New(0x80, heapId);
    expanded = String_New(0x80, heapId);
    ov43_0222EC58(windows, 1, 0, entry, display, 0x2f, 0, 0, 0x10200, raw, expanded, 0);
    ov43_0222AC18(display, 0);
    ov43_0222EC58(windows, 1, 0, entry, display, 0x30, 0, 0x18, 0x10200, raw, expanded, 0);
    ov43_0222ABFC(display, sub_0202C090(records, GET_PLAYER_INDEX(entry), 10));
    ov43_0222EC58(windows, 1, 0, entry, display, 0x31, 0x78, 0x18, 0x10200, raw, expanded, 0);
    ov43_0222AC18(display, 1);
    ov43_0222EC58(windows, 1, 0, entry, display, 0x30, 0, 0x30, 0x10200, raw, expanded, 0);
    ov43_0222ABFC(display, sub_0202C090(records, GET_PLAYER_INDEX(entry), 11));
    ov43_0222EC58(windows, 1, 0, entry, display, 0x31, 0x78, 0x30, 0x10200, raw, expanded, 0);
    ov43_0222AC18(display, 2);
    ov43_0222EC58(windows, 1, 0, entry, display, 0x30, 0, 0x48, 0x10200, raw, expanded, 0);
    ov43_0222ABFC(display, sub_0202C090(records, GET_PLAYER_INDEX(entry), 12));
    ov43_0222EC58(windows, 1, 0, entry, display, 0x31, 0x78, 0x48, 0x10200, raw, expanded, 0);
    ov43_0222DEF8(windows, 1);
    String_Delete(raw);
    String_Delete(expanded);
}

void ov43_0222EBD8(void *windows, void *entry, void *display) {
    ov43_0222EC58(windows, 7, 0, entry, display, 0xe, 0, 0, 0x10200, PTR(display, 0x7c), PTR(display, 0x80), 0);
    ov43_0222DEF8(windows, 7);
}
