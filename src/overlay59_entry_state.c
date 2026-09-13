#include "global.h"

extern void BeginNormalPaletteFade(int, int, int, int, int, int, int);
extern BOOL Heap_Create(int, int, u32);
extern void Heap_Destroy(int);
extern BOOL IsPaletteFadeFinished(void);
extern void MenuInputStateMgr_SetState(void *, int);
extern u32 MenuInputStateMgr_GetState(void *);
extern u32 Options_GetFrame(void *);
extern u32 Options_GetTextFrameDelay(void *);
extern void *OverlayManager_CreateAndGetData(void *, u32, int);
extern void OverlayManager_FreeData(void *);
extern void *OverlayManager_GetArgs(void *);
extern void *OverlayManager_GetData(void *);
extern void *Save_ApricornBox_Get(void *);
extern void *Save_PlayerData_GetOptionsAddr(void *);
extern void SpriteSystem_DrawSprites(void *);
extern void ov59_02237E94(void *);
extern BOOL ov59_02237F3C(u8 *);
extern BOOL ov59_02237F74(u8 *);
extern u32 ov59_02237FA4(u8 *);
extern u32 ov59_0223801C(u8 *);
extern u32 ov59_02238068(u8 *);
extern void ov59_022380E4(void *);
extern u32 ov59_022380EC(void *);
extern void ov59_0223811C(void *);
extern u32 ov59_02238124(void *);
extern u32 ov59_02238218(void *);
extern u32 ov59_022382F4(void *);
extern u32 ov59_0223834C(void *);
extern u32 ov59_022383B4(void *);
extern u32 ov59_022384E4(void *);
extern int ov59_02238578(void *);
extern u32 ov59_0223858C(void *);
extern int ov59_022385AC(void *);
extern void ov59_02238624(void *);
extern void ov59_02238674(void *);
extern void ov59_022386A8(void *);
extern void ov59_022386D0(void *);
extern void ov59_02238768(void *);
extern void ov59_02238CFC(void *, int, int);
extern void ov59_02238D74(u8 *);
extern void ov59_02238FF4(void *, int);
extern void sub_020210BC(void);
extern void sub_02021148(int);
extern void sub_02021238(void);
extern void sub_02031BEC(void *, int);
extern u32 sub_02031C00(void *);

BOOL ov59_02237D40(void *, u32 *);
BOOL ov59_02237DA8(void *, u32 *);
BOOL ov59_02237E68(void *);
void ov59_02237E94(void *);
void ov59_02237F28(u8 *);
BOOL ov59_02237F3C(u8 *);
BOOL ov59_02237F74(u8 *);
u32 ov59_02237FA4(u8 *);
u32 ov59_0223801C(u8 *);
u32 ov59_02238068(u8 *);
BOOL ov59_02237D40(void *man, u32 *state) {
    void *work;

    switch (*state) {
    case 0:
        ov59_02238624(man);
        Heap_Create(3, 0x86, 2 << 16);
        work = OverlayManager_CreateAndGetData(man, 0xa7 * 4, 0x86);
        MI_CpuFill8(work, 0, 0xa7 * 4);
        *(u32 *)work = 0x86;
        *(void **)((u8 *)work + 4) = OverlayManager_GetArgs(man);
        ov59_02237E94(work);
        (*state)++;
        break;
    case 1:
        work = OverlayManager_GetData(man);
        if (ov59_02237F3C(work)) {
            return TRUE;
        }
        break;
    }
    return FALSE;
}

BOOL ov59_02237DA8(void *man, u32 *state) {
    void *p = OverlayManager_GetData(man);
    switch (*state) {
    case 0:
        *state = ov59_02237FA4(p);
        break;
    case 1:
        *state = ov59_0223801C(p);
        break;
    case 2:
        *state = ov59_02238068(p);
        break;
    case 3:
        *state = ((u32 (*)(void *))ov59_022380E4)(p);
        break;
    case 4:
        *state = ov59_022380EC(p);
        break;
    case 5:
        *state = ((u32 (*)(void *))ov59_0223811C)(p);
        break;
    case 6:
        *state = ov59_02238124(p);
        break;
    case 7:
        *state = ov59_02238218(p);
        break;
    case 8:
        *state = ov59_022382F4(p);
        break;
    case 9:
        *state = ov59_0223834C(p);
        break;
    case 10:
        *state = ov59_022383B4(p);
        break;
    case 11:
        *state = ov59_022384E4(p);
        break;
    case 14:
        *state = ov59_02238578(p);
        break;
    case 15:
        *state = ov59_0223858C(p);
        break;
    case 16:
        return TRUE;
    }
    SpriteSystem_DrawSprites(*(void **)((u8 *)p + 0x250));
    return FALSE;
}

BOOL ov59_02237E68(void *man) {
    void *p;
    p = OverlayManager_GetData(man);
    if (ov59_02237F74(p) == FALSE) {
        return FALSE;
    }
    ov59_02237F28(p);
    OverlayManager_FreeData(man);
    Heap_Destroy(0x86);
    return TRUE;
}

void ov59_02237E94(void *raw) {
    u8 *p = raw;
    void *options;

    *(u32 *)(p + 0x40) = MenuInputStateMgr_GetState(*(void **)((u8 *)*(void **)((u8 *)*(void **)(p + 4) + 4) + 0x14));
    options = Save_PlayerData_GetOptionsAddr(*(void **)((u8 *)*(void **)((u8 *)*(void **)(p + 4) + 4) + 0x18));
    p[0x45] = (u8)Options_GetTextFrameDelay(options);
    p[0x46] = (u8)Options_GetFrame(options);
    p[0x44] = ((u8 *)*(void **)(p + 4))[0x18];
    *(void **)(p + 0x38) = *(void **)((u8 *)*(void **)((u8 *)*(void **)(p + 4) + 4) + 0x10);
    *(void **)(p + 0x10) = Save_ApricornBox_Get(*(void **)((u8 *)*(void **)((u8 *)*(void **)(p + 4) + 4) + 0x18));
    ov59_02238768(p);
    if (p[0x44] == 3) {
        p[0x49] = 2;
        p[0x4a] = 0;
        p[0x4b] = ((u8 *)*(void **)(p + 4))[0x1a];
        p[0x4c] = ((u8 *)*(void **)(p + 4))[0x1b];
        p[0x44] = 1;
        ((u8 *)*(void **)(p + 4))[0x18] = 1;
    }
}

void ov59_02237F28(u8 *p) {
    void *a = *(void **)(p + 4);
    void *b = *(void **)((u8 *)a + 4);
    MenuInputStateMgr_SetState(*(void **)((u8 *)b + 0x14), *(int *)(p + 0x40));
}

BOOL ov59_02237F3C(u8 *p) {
    switch (*(u16 *)(p + 0x3c)) {
    case 0:
        ov59_02238674(p);
        (*(u16 *)(p + 0x3c))++;
        break;
    case 1:
        ov59_022386D0(p);
        sub_020210BC();
        sub_02021148(1);
        *(u16 *)(p + 0x3c) = 0;
        return TRUE;
    }
    return FALSE;
}

BOOL ov59_02237F74(u8 *p) {
    switch (*(u16 *)(p + 0x3c)) {
    case 0:
        sub_02021238();
        ov59_022386A8(p);
        (*(u16 *)(p + 0x3c))++;
        break;
    case 1:
    default:
        ((void (*)(void))ov59_02238624)();
        *(u16 *)(p + 0x3c) = 0;
        return TRUE;
    }
    return FALSE;
}

u32 ov59_02237FA4(u8 *p) {
    switch (*(u16 *)(p + 0x3c)) {
    case 0:
        BeginNormalPaletteFade(0, 1, 1, 0, 6, 1, *(u32 *)p);
        (*(u16 *)(p + 0x3c))++;
        break;
    case 1:
        if (IsPaletteFadeFinished()) {
            *(u16 *)(p + 0x3c) = 0;
            switch (p[0x44]) {
            case 0:
                break;
            case 1:
                if (sub_02031C00(*(void **)(p + 0x10)) != 1) {
                    return 2;
                }
                return 4;
            case 2:
                return 5;
            default:
                break;
            }
            return 3;
        }
        break;
    }
    return 0;
}

u32 ov59_0223801C(u8 *p) {
    switch (*(u16 *)(p + 0x3c)) {
    case 0:
        BeginNormalPaletteFade(0, 0, 0, 0, 6, 1, *(u32 *)p);
        (*(u16 *)(p + 0x3c))++;
        break;
    case 1:
        if (IsPaletteFadeFinished()) {
            *(u16 *)(p + 0x3c) = 0;
            return 0x10;
        }
        break;
    }
    return 1;
}

u32 ov59_02238068(u8 *p) {
    if (*(u16 *)(p + 0x3c) == 0) {
        u32 kind;
        ov59_02238FF4(p, 1);
        kind = sub_02031C00(*(void **)(p + 0x10));
        switch (kind) {
        case 0:
            ov59_02238CFC(p, 0x16, p[0x45]);
            break;
        case 2:
            ov59_02238CFC(p, 0x17, 0xff);
            break;
        case 3:
            ov59_02238CFC(p, 0x18, 0xff);
            break;
        }
        sub_02031BEC(*(void **)(p + 0x10), 1);
        (*(u16 *)(p + 0x3c))++;
    } else if (ov59_022385AC(p)) {
        ov59_02238FF4(p, 0);
        ov59_02238D74(p);
        *(u16 *)(p + 0x3c) = 0;
        return 4;
    }
    return 2;
}
