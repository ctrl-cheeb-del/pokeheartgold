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

u32 ov86_021E6DD8(Work *w, u32 which) {
    void *frontier = Save_FrontierData_Get(w->saveData);
    u32 index;
    switch (which) {
    case 0:
        index = 8;
        break;
    case 1:
        index = 9;
        break;
    case 2:
        index = 10;
        break;
    case 3:
        index = 11;
        break;
    case 4:
        index = 12;
        break;
    case 6:
        index = 15;
        break;
    default:
        index = 8;
        break;
    }
    return sub_0202D5DC(frontier, index, 0) == 1 ? 0x1e : 0x1d;
}

void ov86_021E6E30(Work *w) {
    String *s = NewString_ReadMsgData(w->msgData, 0x27);
    FillWindowPixelBuffer(&w->titleWindow, 0);
    ov86_021E5FD8(&w->titleWindow, s, GetWindowWidth(&w->titleWindow) * 8 / 2, 0, 4, 0x000F0100, 2);
    ScheduleWindowCopyToVram(&w->titleWindow);
    String_Delete(s);
}
