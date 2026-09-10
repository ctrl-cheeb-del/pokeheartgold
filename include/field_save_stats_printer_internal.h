#ifndef POKEHEARTGOLD_FIELD_SAVE_STATS_PRINTER_INTERNAL_H
#define POKEHEARTGOLD_FIELD_SAVE_STATS_PRINTER_INTERNAL_H

// THUMB comes from the SOURCE: global.h -> nitro/code16.h -> #pragma thumb on
#include "global.h"

#include "constants/maps.h"

#include "bg_window.h"
#include "field_system.h"
#include "filesystem.h"
#include "font.h"
#include "heap.h"
#include "igt.h"
#include "map_header.h"
#include "message_format.h"
#include "msgdata.h"
#include "overlay_01.h"
#include "player_avatar.h"
#include "player_data.h"
#include "pm_string.h"
#include "pokedex.h"
#include "render_text.h"
#include "render_window.h"
#include "save.h"
#include "save_local_field_data.h"
#include "string_util.h"
#include "text.h"

// struct SaveStatsPrinter is only FORWARD-DECLARED in include/overlay_01.h
// (line 99), so the full layout has no tracked definition and is private here.
// Offsets are read straight off the assembly; total size 0x34 (Heap_Alloc 0x34).
struct SaveStatsPrinterStats {
    int dexOwned;           // 0x00 (printer +0x1c)
    int mapSec;             // 0x04 (printer +0x20)
    PlayerProfile *profile; // 0x08 (printer +0x24)
    IGT *igt;               // 0x0c (printer +0x28)
};

struct SaveStatsPrinter {
    FieldSystem *fieldSystem;           // 0x00
    enum HeapID heapId;                 // 0x04
    u8 bgId;                            // 0x08  (strb / ldrb)
    BgConfig *bgConfig;                 // 0x0c
    Window *window;                     // 0x10
    MessageFormat *msgFmt;              // 0x14
    MsgData *msgData;                   // 0x18
    struct SaveStatsPrinterStats stats; // 0x1c
    int width;                          // 0x2c
    int height;                         // 0x30
};

struct SaveStatsRow {
    u32 msgId; // 0x0
    u32 align; // 0x4
    u32 row;   // 0x8
    u32 color; // 0xc
};

void ov01_021F6830(FieldSystem *fieldSystem, int a1, int a2);
void GF_AssertFail(void);

extern const u32 sTextColors[2];
extern const u32 sMsgIdsMain[4];
extern const u32 sMsgIdsSub[5];
extern const struct SaveStatsRow sStatRows[9];

void ov01_021F3F50(struct SaveStatsPrinterStats *stats, FieldSystem *fieldSystem);
void ov01_021F3F9C(MessageFormat *msgFmt, struct SaveStatsPrinterStats *stats);
int ov01_021F4044(struct SaveStatsPrinterStats *stats);
void ov01_021F4048(struct SaveStatsPrinter *printer);
int ov01_021F4234(Window *window, String *str, int align, int fontId);
void ov01_021F426C(struct SaveStatsPrinter *printer);
void ov01_021F42F8(UnkStruct_field_021F4360 *a0);
void ov01_021F434C(UnkStruct_field_021F4360 *a0);
UnkStruct_field_021F4360 *ov01_021F4360(FieldSystem *fieldSystem, enum HeapID heapID, u8 a2);
void ov01_021F43D0(UnkStruct_field_021F4360 *a0);
void ov01_021F4404(FieldSystem *fieldSystem);
void ov01_021F4440(FieldSystem *fieldSystem);

#endif // POKEHEARTGOLD_FIELD_SAVE_STATS_PRINTER_INTERNAL_H
