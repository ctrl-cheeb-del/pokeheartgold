#include "overlay_27_helpers_internal.h"

extern int PlayerAvatar_GetPlayerMoveState(PlayerAvatar *avatar);
extern u32 sub_0203769C(void);
extern BOOL sub_02037958(void);
extern BOOL sub_02058740(void);
extern BOOL sub_02058258(void);
extern BOOL sub_02056EE0(void);
extern BOOL sub_02057A0C(void);
extern BOOL sub_02057F18(u32 value);
extern BOOL IsPaletteFadeFinished(void);
extern int TouchscreenHitbox_FindRectAtTouchNew(const void *hitboxes);
extern void *Save_Bag_Get(SaveData *saveData);
extern u16 Bag_GetRegisteredItem1(void *bag);
extern u16 Bag_GetRegisteredItem2(void *bag);
extern u8 gSystem[];
extern const u8 ov27_0225CF68[];
extern int ov27_0225C170(u8 *work, int index);
extern u8 GetWindowX(Ov27Window *window);
extern u8 GetWindowY(Ov27Window *window);
extern u8 GetWindowWidth(Ov27Window *window);
extern u8 GetWindowHeight(Ov27Window *window);
extern void FillBgTilemapRect(BgConfig *bgConfig, u8 bgId, u16 fillValue, u8 x, u8 y, u8 width, u8 height, u8 palette);
extern void ScheduleBgTilemapBufferTransfer(BgConfig *bgConfig, u8 bgId);

typedef struct Ov27RawEntry {
    u8 state;
    u8 pad[7];
} Ov27RawEntry;

typedef struct Ov27RawWork {
    u8 pad000[0x390];
    void *items[10];
    u8 pad3B8[0x470 - 0x3B8];
    Ov27RawEntry entries[7];
} Ov27RawWork;

BOOL ov27_0225B4D8(Ov27Work *work);
void ov27_0225B630(Ov27Window *window, u32 mode);

BOOL ov27_0225B4D8(Ov27Work *work) {
    s32 hit;
    void *bag;

    if (PlayerAvatar_GetPlayerMoveState(*(PlayerAvatar **)((u8 *)work->unk10 + 0x40)) != 0 || (*(u32 *)(gSystem + 0x48) & 0xF0) != 0) {
        return TRUE;
    }

    if (((work->unk51C.raw << 27) >> 28) == 5) {
        u32 player = sub_0203769C();
        if (!sub_02058740() || !sub_02058258() || !sub_02056EE0() || !sub_02057A0C() || sub_02057F18(player) || sub_02037958()) {
            return TRUE;
        }
    }

    if (!IsPaletteFadeFinished()) {
        return TRUE;
    }
    if (((work->unk51C.raw << 26) >> 31) == 1) {
        return TRUE;
    }

    hit = TouchscreenHitbox_FindRectAtTouchNew(ov27_0225CF68);
    if (hit > 0 && hit < 8) {
        u8 *entry = (u8 *)work + (hit - 1) * 8;
        if (entry[0x470] == 0) {
            return FALSE;
        }
    }

    bag = Save_Bag_Get(work->unk10->saveData);
    if ((u32)(hit - 8) <= 1) {
        if (!work->unk51C.b.bit0) {
            return TRUE;
        }
        if (!ov27_0225BDAC(work)) {
            return TRUE;
        }
    }
    if (hit == 8) {
        if (Bag_GetRegisteredItem1(bag) == 0) {
            return TRUE;
        }
    } else if (hit == 9 && Bag_GetRegisteredItem2(bag) == 0) {
        return TRUE;
    }

    if (hit != -1) {
        if (hit == 0) {
            *(u16 *)work->unk0C = 1;
        } else {
            u8 *entry = (u8 *)work + (hit - 1) * 4;
            if (*(void **)(entry + 0x390) != NULL) {
                if (hit < 8) {
                    work->unk14 = hit - 1;
                    ((u8 *)work->unk10)[0xD3] = ov27_0225C170((u8 *)work, work->unk14);
                    ov27_0225B398(work, work->unk14);
                }
                *(u16 *)work->unk0C = ov27_0225C170((u8 *)work, hit - 1) + 2;
            }
        }
        return FALSE;
    }
    return TRUE;
}

#define F(bg, tile, xx, yy, ww, pal) FillBgTilemapRect(bgConfig, bg, tile, xx, yy, ww, 1, pal)

void ov27_0225B630(Ov27Window *window, u32 mode) {
    BgConfig *bgConfig = window->bgConfig;
    u32 x = GetWindowX(window);
    u32 y = GetWindowY(window);
    u32 width = GetWindowWidth(window);
    u32 height = GetWindowHeight(window);

    switch (mode) {
    case 1:
        F(4, 0xA9, x - 3, y - 1, 1, 2);
        F(4, 0xAA, x - 2, y - 1, 1, 2);
        F(4, 0xAB, x - 1, y - 1, 1, 2);
        F(5, 0xAC, x, y - 1, width, 2);
        F(5, 0xAD, x + width, y - 1, 1, 2);
        F(4, 0x64, x - 3, y, 1, 2);
        F(4, 0x65, x - 2, y, 1, 2);
        F(4, 0x66, x - 1, y, 1, 2);
        F(5, 0x68, x + width, y, 1, 2);
        F(4, 0x84, x - 3, y + 1, 1, 2);
        F(4, 0x85, x - 2, y + 1, 1, 2);
        F(4, 0x86, x - 1, y + 1, 1, 2);
        F(5, 0x88, x + width, y + 1, 1, 2);
        F(4, 0xA4, x - 3, y + height, 1, 2);
        F(4, 0xA5, x - 2, y + height, 1, 2);
        F(4, 0xA6, x - 1, y + height, 1, 2);
        F(5, 0xA7, x, y + height, width, 2);
        F(5, 0xA8, x + width, y + height, 1, 2);
        break;
    case 2:
        F(4, 7, x - 3, y - 1, 1, 0);
        F(4, 7, x - 2, y - 1, 1, 0);
        F(4, 7, x - 1, y - 1, 1, 0);
        F(5, 0, x, y - 1, width, 2);
        F(5, 0, x + width, y - 1, 1, 2);
        F(4, 7, x - 3, y, 1, 0);
        F(4, 7, x - 2, y, 1, 0);
        F(4, 7, x - 1, y, 1, 0);
        F(5, 0, x + width, y, 1, 2);
        F(4, 7, x - 3, y + 1, 1, 0);
        F(4, 7, x - 2, y + 1, 1, 0);
        F(4, 7, x - 1, y + 1, 1, 0);
        F(5, 0, x + width, y + 1, 1, 2);
        F(4, 7, x - 3, y + height, 1, 0);
        F(4, 7, x - 2, y + height, 1, 0);
        F(4, 7, x - 1, y + height, 1, 0);
        F(5, 0, x, y + height, width, 2);
        F(5, 0, x + width, y + height, 1, 2);
        break;
    default:
        GF_ASSERT(FALSE);
        break;
    }
    ScheduleBgTilemapBufferTransfer(bgConfig, 4);
    ScheduleBgTilemapBufferTransfer(bgConfig, 5);
}
