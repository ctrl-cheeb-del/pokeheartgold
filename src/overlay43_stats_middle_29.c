#include "overlay43_stats_middle_29_private.h"

#define PLAYER_ID(entry) ((entry)->playerIds[(entry)->playerIndex])

void ov43_0222E0E8(void *windows, Ov43Entry *entry, Ov43Display *display) {
    void *frontier = Save_Frontier_GetStatic(entry->save);

    ov43_0222EC58(windows, 2, 0, entry, display, 0x1D, 0, 0, 0x10200, display->raw, display->expanded, 0);
    ov43_0222EC58(windows, 2, 1, entry, display, FrontierSave_GetStat(frontier, 0x64, PLAYER_ID(entry)) + 0x22, 0, 0, 0x10200, display->raw, display->expanded, 0);
    ov43_0222ABFC(display, FrontierSave_GetStat(frontier, 0x71, PLAYER_ID(entry)));
    ov43_0222EC58(windows, 2, 1, entry, display, 0x25, 0x70, 0, 0x10200, display->raw, display->expanded, 1);
    ov43_0222EC58(windows, 2, 1, entry, display, 0x24, 0, 0x18, 0x10200, display->raw, display->expanded, 0);
    ov43_0222ABFC(display, FrontierSave_GetStat(frontier, 0x70, PLAYER_ID(entry)));
    ov43_0222EC58(windows, 2, 1, entry, display, 0x25, 0x70, 0x18, 0x10200, display->raw, display->expanded, 1);
    ov43_0222DEF8(windows, 2);
}

void ov43_0222E220(void *windows, Ov43Entry *entry, Ov43Display *display, u32 heapId) {
    void *frontier = Save_Frontier_GetStatic(entry->save);
    String *raw = String_New(0x80, heapId);
    String *expanded = String_New(0x80, heapId);
    u32 message;

    ov43_0222EC58(windows, 3, 0, entry, display, 0x1E, 0, 0, 0x10200, raw, expanded, 0);
    ov43_0222EC58(windows, 3, 1, entry, display, 0x26, 0, 0, 0x10200, raw, expanded, 0);
    ov43_0222EC58(windows, 3, 1, entry, display, 0x28, 0xD0, 0, 0x10200, raw, expanded, 2);

    message = FrontierSave_GetStat(frontier, 0x66, PLAYER_ID(entry)) == 0 ? 0x22 : 0x23;
    ov43_0222EC58(windows, 3, 2, entry, display, message, 0, 0, 0x10200, raw, expanded, 0);
    ov43_0222ABFC(display, FrontierSave_GetStat(frontier, 0x73, PLAYER_ID(entry)));
    ov43_0222EC58(windows, 3, 2, entry, display, 0x25, 0x70, 0, 0x10200, raw, expanded, 1);
    ov43_0222ABFC(display, FrontierSave_GetStat(frontier, 0x75, PLAYER_ID(entry)));
    ov43_0222EC58(windows, 3, 2, entry, display, 0x2B, 0, 0, 0x10200, raw, expanded, 0);
    ov43_0222EC58(windows, 3, 2, entry, display, 0x24, 0, 0x10, 0x10200, raw, expanded, 0);
    ov43_0222ABFC(display, FrontierSave_GetStat(frontier, 0x72, PLAYER_ID(entry)));
    ov43_0222EC58(windows, 3, 2, entry, display, 0x25, 0x70, 0x10, 0x10200, raw, expanded, 1);
    ov43_0222ABFC(display, FrontierSave_GetStat(frontier, 0x74, PLAYER_ID(entry)));
    ov43_0222EC58(windows, 3, 2, entry, display, 0x2B, 0, 0x10, 0x10200, raw, expanded, 0);

    ov43_0222EC58(windows, 3, 3, entry, display, 0x27, 0, 0, 0x10200, raw, expanded, 0);
    ov43_0222EC58(windows, 3, 3, entry, display, 0x28, 0xD0, 0, 0x10200, raw, expanded, 2);

    message = FrontierSave_GetStat(frontier, 0x68, PLAYER_ID(entry)) == 0 ? 0x22 : 0x23;
    ov43_0222EC58(windows, 3, 4, entry, display, message, 0, 0, 0x10200, raw, expanded, 0);
    ov43_0222ABFC(display, FrontierSave_GetStat(frontier, 0x77, PLAYER_ID(entry)));
    ov43_0222EC58(windows, 3, 4, entry, display, 0x25, 0x70, 0, 0x10200, raw, expanded, 1);
    ov43_0222ABFC(display, FrontierSave_GetStat(frontier, 0x79, PLAYER_ID(entry)));
    ov43_0222EC58(windows, 3, 4, entry, display, 0x2B, 0, 0, 0x10200, raw, expanded, 0);
    ov43_0222EC58(windows, 3, 4, entry, display, 0x24, 0, 0x10, 0x10200, raw, expanded, 0);
    ov43_0222ABFC(display, FrontierSave_GetStat(frontier, 0x76, PLAYER_ID(entry)));
    ov43_0222EC58(windows, 3, 4, entry, display, 0x25, 0x70, 0x10, 0x10200, raw, expanded, 1);
    ov43_0222ABFC(display, FrontierSave_GetStat(frontier, 0x78, PLAYER_ID(entry)));
    ov43_0222EC58(windows, 3, 4, entry, display, 0x2B, 0, 0x10, 0x10200, raw, expanded, 0);

    ov43_0222DEF8(windows, 3);
    String_Delete(raw);
    String_Delete(expanded);
}
