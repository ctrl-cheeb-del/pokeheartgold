#ifndef TO46_OV43_R29_MIDDLE_PRIVATE_H
#define TO46_OV43_R29_MIDDLE_PRIVATE_H

#include "global.h"

typedef struct String String;

typedef struct Ov43Entry {
    u8 pad00[4];
    void *save;
    u8 pad08[3];
    s8 playerIndex;
    u8 pad0C[0x0C];
    u8 playerIds[4];
} Ov43Entry;

typedef struct Ov43Display {
    u8 pad00[0x7C];
    String *raw;
    String *expanded;
} Ov43Display;

void *Save_Frontier_GetStatic(void *save);
u32 FrontierSave_GetStat(void *frontier, u32 stat, u32 player);
String *String_New(u32 length, u32 heapId);
void String_Delete(String *string);
void ov43_0222ABFC(Ov43Display *display, u32 value);
void ov43_0222DEF8(void *windows, u32 window);
void ov43_0222EC58(void *windows, u32 window, u32 mode, Ov43Entry *entry, Ov43Display *display, u32 message, u32 x, u32 y, u32 color, String *raw, String *expanded, u32 flag);
void ov43_0222E0E8(void *windows, Ov43Entry *entry, Ov43Display *display);
void ov43_0222E220(void *windows, Ov43Entry *entry, Ov43Display *display, u32 heapId);

#endif
