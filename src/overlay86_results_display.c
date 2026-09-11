#include "global.h"

#include "font.h"
#include "frontier_data.h"
#include "msgdata.h"
#include "pm_string.h"
#include "sprite_system.h"
#include "unk_02030A98.h"

typedef struct Work {
    void *man;
    u8 state, unk5, mode, kind;
    u16 unk8, unkA;
    void *bgConfig;
    Window windows[32];
    MsgData *msgData;
    void *msgFmt;
    String *str;
    void *plttData;
    void *options;
    SaveData *saveData;
    void *frontier;
    SpriteSystem *spriteSystem;
    SpriteManager *spriteManager;
    ManagedSprite *sprites[2];
    Window titleWindow;
} Work;

extern void ov86_021E5FD8(Window *, String *, u32, u32, u32, u32, u32);
extern u32 sub_0205C268(u32);
extern u32 sub_0202D5DC(void *, u32, u32);
extern void ov86_021E6024(Work *, u32, u32, u32, u32, u32, u32, u32);
extern void ov86_021E6064(Work *, u32, u32, u32, u32, u32, u32, u32);
extern void ov86_021E5FBC(Work *, u32, u32);
extern u32 sub_0205C2C0(u32);
extern u32 sub_0205C2E8(u32);
extern u32 sub_0205C310(u32);
extern u32 sub_0205C350(u32);

extern u32 sub_0205C1A0(u32);
extern u32 sub_0205C1C8(u32);
extern u32 sub_0205C1F0(u32);
extern u32 sub_0205C240(u32);
void ov86_021E66D0(Work *);
void ov86_021E6BA8(Work *);
void ov86_021E690C(Work *);
void ov86_021E6A88(Work *);

u32 ov86_021E68B8(Work *);
u32 ov86_021E6A34(Work *);
u32 ov86_021E6DD8(Work *, u32);

void ov86_021E6E30(Work *);
void ov86_021E6FF4(Work *);

void ov86_021E66D0(Work *w) {
    u32 msg, stat;
    void *frontier;
    FillWindowPixelBuffer(&w->windows[0], 0);
    FillWindowPixelBuffer(&w->windows[1], 0);
    FillWindowPixelBuffer(&w->windows[2], 0);
    FillWindowPixelBuffer(&w->windows[3], 0);
    ov86_021E6024(w, 0, 0x17, 0, 0, 0, 0x000F0200, 0);
    if (w->mode == 0) {
        msg = 0x1a;
    } else if (w->mode == 1) {
        msg = 0x1b;
    } else {
        msg = 0x1c;
    }
    ov86_021E6024(w, 0, msg, 0xe0, 0, 0, 0x000F0200, 1);
    ov86_021E6024(w, 1, 0x31, 0x70, 0, 0, 0x00010200, 1);
    ov86_021E6024(w, 2, ov86_021E68B8(w), 0, 0, 0, 0x00010200, 0);
    ov86_021E5FBC(w, 0, FrontierSave_GetStat(w->frontier, sub_0205C1A0(w->mode), 0xff));
    ov86_021E6064(w, 2, 0x36, 0x70, 0, 0, 0x00010200, 2);
    frontier = Save_Frontier_GetStatic(w->saveData);
    stat = sub_0205C1F0(w->mode);
    ov86_021E5FBC(w, 0, FrontierSave_GetStat(frontier, stat, sub_0205C268(sub_0205C1F0(w->mode))));
    ov86_021E6064(w, 2, 0x35, 0xe0, 0, 0, 0x00010200, 1);
    ov86_021E6024(w, 3, 0x2b, 0, 0, 0, 0x00010200, 0);
    ov86_021E5FBC(w, 0, FrontierSave_GetStat(w->frontier, sub_0205C1C8(w->mode), 0xff));
    ov86_021E6064(w, 3, 0x36, 0x70, 0, 0, 0x00010200, 2);
    frontier = Save_Frontier_GetStatic(w->saveData);
    stat = sub_0205C240(w->mode);
    ov86_021E5FBC(w, 0, FrontierSave_GetStat(frontier, stat, sub_0205C268(sub_0205C240(w->mode))));
    ov86_021E6064(w, 3, 0x35, 0xe0, 0, 0, 0x00010200, 1);
    ScheduleWindowCopyToVram(&w->windows[0]);
    ScheduleWindowCopyToVram(&w->windows[1]);
    ScheduleWindowCopyToVram(&w->windows[2]);
    ScheduleWindowCopyToVram(&w->windows[3]);
}

u32 ov86_021E68B8(Work *w) {
    u32 result;
    u8 mode = w->mode;
    if (mode == 3) {
        void *p = Save_Frontier_GetStatic(w->saveData);
        result = FrontierSave_GetStat(p, 0x6c, sub_0205C268(0x6c));
    } else {
        result = sub_02030E58(sub_02030E08(w->saveData), 9, mode, 0, 0);
    }
    return (u8)result == 1 ? 0x1e : 0x1d;
}

void ov86_021E690C(Work *w) {
    u32 msg;
    FillWindowPixelBuffer(&w->windows[0], 0);
    FillWindowPixelBuffer(&w->windows[1], 0);
    FillWindowPixelBuffer(&w->windows[2], 0);
    ov86_021E6024(w, 0, 0x19, 0, 0, 0, 0x000F0200, 0);
    if (w->mode == 0) {
        msg = 0x1a;
    } else if (w->mode == 1) {
        msg = 0x1b;
    } else {
        msg = 0x1c;
    }
    ov86_021E6024(w, 0, msg, 0xe0, 0, 0, 0x000F0200, 1);
    ov86_021E6024(w, 1, ov86_021E6A34(w), 0, 0, 0, 0x00010200, 0);
    ov86_021E5FBC(w, 0, FrontierSave_GetStat(w->frontier, sub_0205C2C0(w->mode), 0xff));
    ov86_021E6064(w, 1, 0x37, 0x70, 0, 0, 0x00010200, 2);
    ov86_021E6024(w, 2, 0x2b, 0, 0, 0, 0x00010200, 0);
    ov86_021E5FBC(w, 0, FrontierSave_GetStat(w->frontier, sub_0205C2E8(w->mode), 0xff));
    ov86_021E6064(w, 2, 0x37, 0x70, 0, 0, 0x00010200, 2);
    ScheduleWindowCopyToVram(&w->windows[0]);
    ScheduleWindowCopyToVram(&w->windows[1]);
    ScheduleWindowCopyToVram(&w->windows[2]);
}

u32 ov86_021E6A34(Work *w) {
    u32 result;
    u8 mode = w->mode;
    if (mode == 3) {
        void *p = Save_Frontier_GetStatic(w->saveData);
        result = FrontierSave_GetStat(p, 0x6e, sub_0205C268(0x6e));
    } else {
        result = sub_02030FE4(sub_02030FA0(w->saveData), 8, mode, 0, 0);
    }
    return (u8)result == 1 ? 0x1e : 0x1d;
}

void ov86_021E6A88(Work *w) {
    u32 msg;
    FillWindowPixelBuffer(&w->windows[0], 0);
    FillWindowPixelBuffer(&w->windows[2], 0);
    FillWindowPixelBuffer(&w->windows[3], 0);
    ov86_021E6024(w, 0, 0x15, 0, 0, 0, 0x000F0200, 0);
    msg = w->mode == 0 ? 0x1a : 0x1b;
    ov86_021E6024(w, 0, msg, 0xe0, 0, 0, 0x000F0200, 1);
    ov86_021E6024(w, 2, ov86_021E6DD8(w, w->mode), 0, 0, 0, 0x00010200, 0);
    ov86_021E5FBC(w, 0, FrontierSave_GetStat(w->frontier, sub_0205C310(w->mode), 0xff));
    ov86_021E6064(w, 2, 0x32, 0x70, 0, 0, 0x00010200, 2);
    ov86_021E6024(w, 3, 0x2b, 0, 0, 0, 0x00010200, 0);
    ov86_021E5FBC(w, 0, FrontierSave_GetStat(w->frontier, sub_0205C350(w->mode), 0xff));
    ov86_021E6064(w, 3, 0x32, 0x70, 0, 0, 0x00010200, 2);
    ScheduleWindowCopyToVram(&w->windows[0]);
    ScheduleWindowCopyToVram(&w->windows[2]);
    ScheduleWindowCopyToVram(&w->windows[3]);
}
