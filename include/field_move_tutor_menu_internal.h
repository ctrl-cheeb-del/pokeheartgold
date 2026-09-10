#ifndef PRIVATE_OV01_021EDAFC_H
#define PRIVATE_OV01_021EDAFC_H

#include "global.h"

#include "constants/heap.h"
#include "constants/sndseq.h"

#include "bg_window.h"
#include "field_system.h"
#include "font.h"
#include "gf_gfx_planes.h"
#include "heap.h"
#include "list_menu.h"
#include "list_menu_2d.h"
#include "message_format.h"
#include "msgdata.h"
#include "overlay_01.h"
#include "overlay_01_021EDAFC.h"
#include "overlay_03.h"
#include "pm_string.h"
#include "screen_fade.h"
#include "string_util.h"
#include "sys_task.h"
#include "sys_task_api.h"

typedef struct MoveTutorMenuEntry {
    String *text;
    u32 value;
} MoveTutorMenuEntry;

struct UnkStruct_ov01_021EDC28 {
    /* 0x000 */ FieldSystem *fieldSystem;
    /* 0x004 */ SysTask *task;
    /* 0x008 */ Window window;
    /* 0x018 */ Window *printWindow;
    /* 0x01C */ String *strbufs[28];
    /* 0x08C */ MsgData *msgData;
    /* 0x090 */ MessageFormat *msgFmt;
    /* 0x094 */ u8 delay;
    /* 0x095 */ u8 unk_95;
    /* 0x096 */ u8 initCursorPos;
    /* 0x097 */ u8 cancellable : 1;
    u8 ownMsgData : 1;
    u8 unk_97_2 : 4;
    u8 unk_97_6 : 1;
    u8 unk_97_7 : 1;
    /* 0x098 */ u8 x;
    /* 0x099 */ u8 y;
    /* 0x09A */ u8 unk_9A;
    /* 0x09B */ u8 count;
    /* 0x09C */ u8 unk_9C[4];
    /* 0x0A0 */ u16 *ret_p;
    /* 0x0A4 */ u16 *scroll_p;
    /* 0x0A8 */ u16 *row_p;
    /* 0x0AC */ struct ListMenu2DTemplate menu2d;
    /* 0x0B8 */ struct ListMenu2D *menu2dPtr;
    /* 0x0BC */ MoveTutorMenuEntry entries[28];
    /* 0x19C */ ListMenuTemplate listTemplate;
    /* 0x1BC */ ListMenu *listMenu;
    /* 0x1C0 */ u16 unk_1C0;
    /* 0x1C2 */ u16 cursorPos;
    /* 0x1C4 */ ListMenuItem items[28];
    /* 0x2A4 */ u16 msgIds[28];
    /* 0x2DC */ u16 lastRow;
    /* 0x2DE */ u16 unk_2DE;
};

typedef struct UnkStruct_ov01_021EDC28 MoveTutorMenu;

void sub_0200E5D4(Window *window, int a1);
void PlaySE(u16 seq);
void AddTextPrinterParameterized(Window *window, u32 fontId, String *str, u32 x, u32 y, u32 speed, u32 colors);
ListMenuItem *ov01_021EEF58(MoveTutorMenu *menu);
u8 ov01_021EEF60(MoveTutorMenu *menu);
Window *ov01_021EEF68(FieldSystem *fieldSystem, u16 a1);
void ov01_021EEF88(Window *window);
void ov01_021EEF9C(MoveTutorMenu *menu, int idx);
u8 ov01_021EF00C(MoveTutorMenu *menu);
int ov01_021EE934(u32 mapId, int a1, u8 *width_p);

#endif
