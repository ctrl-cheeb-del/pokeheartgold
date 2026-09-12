#include "global.h"

#include "bg_window.h"
#include "heap.h"

extern u8 SDK_OVERLAY_OVY_80_ID[];

extern void BeginNormalPaletteFade(int, int, int, int, int, int, int);
extern void GF_DestroyVramTransferManager(void);
extern void HandleLoadOverlay(u32, int);
extern int IsPaletteFadeFinished(void);
extern void *OverlayManager_CreateAndGetData(void *, u32, enum HeapID);
extern void *OverlayManager_GetArgs(void *);
extern void *OverlayManager_GetData(void *);
extern void OverlayManager_FreeData(void *);
extern void UnloadOverlayByID(u32);
extern int ov80_02237D8C(int);
extern void ov80_0222A7CC(void *, int);
extern int Options_GetFrame(void *);
extern void SpriteList_RenderAndAnimateSprites(void *);
extern int ov83_022433F8(u8 *);
extern void ov83_022433B8(u8 *);
extern int ov83_02243C88(u8 *);
extern int ov83_02243D7C(u8 *);
extern int ov83_02243DE8(u8 *);
extern void ov83_02243E30(u8 *);
extern void ov83_02243F9C(void);
extern void ov83_02243FD4(u8 *);
extern int ov83_022450A8(u8 *, int, int);
extern void ov83_02245074(u8 *);
extern int ov83_022448AC(u8 *, int, int);
extern void ov83_02244CD4(u8 *, u32 *, int);
extern void ov83_022459A0(u8 *);
extern void ov83_022459AC(u8 *);
extern int ov83_0224753C(void *);
extern void ov83_02247944(void *, int);
extern void sub_02037AC0(int);
extern int sub_02037B38(int);
extern void sub_02037BEC(void);
extern void *sub_02030CC8(void *);
extern void *sub_02030E08(void *);
extern void *Save_Frontier_GetStatic(void *);
extern void *Save_PlayerData_GetOptionsAddr(void *);
extern void sub_02096910(u8 *);
extern const u8 ov83_02247E64[][4];

BOOL ov83_02242F2C(u8 *);
BOOL ov83_02242FE8(void *);
BOOL ov83_02243108(void *, u32 *);
BOOL ov83_02243268(void *);
BOOL ov83_022432B4(u8 *);

BOOL ov83_02242F2C(u8 *work) {
    const u8 *entry = ov83_02247E64[*(u16 *)(work + 0x864)];

    switch (work[0x866]) {
    case 0:
        BgTilemapRectChangePalette(*(BgConfig **)(work + 0x4C), 2, entry[0], entry[1], entry[2], entry[3], 6);
        ScheduleBgTilemapBufferTransfer(*(BgConfig **)(work + 0x4C), 2);
        work[0x866]++;
        break;
    case 1:
        work[0x867]++;
        if (work[0x867] == 4) {
            BgTilemapRectChangePalette(*(BgConfig **)(work + 0x4C), 2, entry[0], entry[1], entry[2], entry[3], 5);
            ScheduleBgTilemapBufferTransfer(*(BgConfig **)(work + 0x4C), 2);
            work[0x867] = 0;
            work[0x866]++;
        }
        break;
    case 2:
        work[0x867]++;
        if (work[0x867] == 2) {
            return FALSE;
        }
        break;
    }
    return TRUE;
}

BOOL ov83_02242FE8(void *manager) {
    u8 *work;
    u8 *args;
    int i;

    HandleLoadOverlay((u32)SDK_OVERLAY_OVY_80_ID, 2);
    ov83_02243F9C();
    Heap_Create((enum HeapID)3, (enum HeapID)0x6B, 0x30000);
    work = OverlayManager_CreateAndGetData(manager, 0x614, (enum HeapID)0x6B);
    memset(work, 0, 0x614);
    *(void **)(work + 0x4C) = BgConfig_Alloc((enum HeapID)0x6B);
    *(void **)work = manager;
    args = OverlayManager_GetArgs(manager);
    *(void **)(work + 0x2BC) = *(void **)args;
    *(void **)(work + 0x2C0) = sub_02030CC8(*(void **)(work + 0x2BC));
    *(void **)(work + 0x2C4) = sub_02030E08(*(void **)(work + 0x2BC));
    work[9] = args[4];
    *(void **)(work + 0x548) = args + 0x20;
    *(void **)(work + 0x2B8) = Save_PlayerData_GetOptionsAddr(*(void **)(work + 0x2BC));
    *(void **)(work + 0x55C) = *(void **)(args + 0x1C);
    *(void **)(work + 0x54C) = args + 8;
    *(void **)(work + 0x550) = args + 0xC;
    *(void **)(work + 0x554) = args + 0x10;
    *(void **)(work + 0x558) = args + 0x14;
    work[0x11] = 0xFF;
    *(u16 *)(work + 0x5BA) = *(u16 *)(args + 0x28);
    *(void **)(work + 4) = Save_Frontier_GetStatic(*(void **)(work + 0x2BC));
    for (i = 0; i < 3; i++) {
        work[0x5B7 + i] = 1;
    }
    work[0x14] = ov80_02237D8C(work[9]) == 0 ? 3 : 4;
    work[0x15] = 4;
    work[0xC] = work[0x15] - 1;
    work[0x5B4] = 0;
    ov83_02243FD4(work);
    if (ov80_02237D8C(work[9]) == 1) {
        sub_02096910(work);
    }
    return TRUE;
}

BOOL ov83_02243108(void *manager, u32 *state) {
    u8 *work = OverlayManager_GetData(manager);

    if (work[0x5B6] == 1) {
        if (*state == 1) {
            work[0x5B6] = 0;
            ov83_02245074(work);
            ov83_022459A0(work);
            if (*(void **)(work + 0x504) != NULL) {
                ov83_0224753C(*(void **)(work + 0x504));
                work[0xF] &= ~1;
            }
            ov83_02247944(work + 0xC0, Options_GetFrame(*(void **)(work + 0x2B8)));
            ov80_0222A7CC(*(void **)(work + 0x24), 0);
            work[0xA] = ov83_022448AC(work, 7, 1);
            ov83_02244CD4(work, state, 3);
        }
    } else if (work[0x11] != 0xFF && (*state == 1 || *state == 3)) {
        work[0x5B6] = 0;
        ov83_02245074(work);
        ov83_022459A0(work);
        ov83_02244CD4(work, state, 2);
    }

    switch (*state) {
    case 0:
        if (ov83_022432B4(work) == 1) {
            ov83_02244CD4(work, state, 1);
        }
        break;
    case 1:
        if (ov83_022433F8(work) == 1) {
            if (work[0x10] == 1) {
                ov83_02244CD4(work, state, 2);
            } else if (ov80_02237D8C(work[9]) == 1) {
                ov83_02244CD4(work, state, 3);
            } else {
                ov83_02244CD4(work, state, 4);
            }
        }
        break;
    case 2:
        if (ov83_02243C88(work) == 1) {
            ov83_02244CD4(work, state, 1);
        }
        break;
    case 3:
        if (ov83_02243D7C(work) == 1) {
            ov83_02244CD4(work, state, 4);
        }
        break;
    case 4:
        if (ov83_02243DE8(work) == 1) {
            return TRUE;
        }
        break;
    }

    ov83_022459AC(work);
    SpriteList_RenderAndAnimateSprites(*(void **)(work + 0x2C8));
    return FALSE;
}

BOOL ov83_02243268(void *manager) {
    u8 *work = OverlayManager_GetData(manager);

    **(u16 **)(work + 0x548) = work[0xD];
    *(vu16 *)0x04000050 = 0;
    GF_DestroyVramTransferManager();
    ov83_02243E30(work);
    OverlayManager_FreeData(manager);
    Main_SetVBlankIntrCB(NULL, NULL);
    Heap_Destroy((enum HeapID)0x6B);
    UnloadOverlayByID((u32)SDK_OVERLAY_OVY_80_ID);
    return TRUE;
}

BOOL ov83_022432B4(u8 *work) {
    switch (work[8]) {
    case 0:
        if (ov80_02237D8C(work[9]) == 1) {
            sub_02037BEC();
            sub_02037AC0(0xD8);
        }
        work[8]++;
        break;
    case 1:
        if (ov80_02237D8C(work[9]) == 1) {
            if (sub_02037B38(0xD8) == 1) {
                sub_02037BEC();
                work[8]++;
            }
        } else {
            work[8]++;
        }
        break;
    case 2:
        if (ov80_02237D8C(work[9]) == 1) {
            if (ov83_022450A8(work, 0x14, 0) == 1) {
                work[8]++;
            }
        } else {
            ov83_022433B8(work);
            BeginNormalPaletteFade(0, 1, 1, 0, 6, 3, 0x6B);
            work[8]++;
        }
        break;
    case 3:
        if (ov80_02237D8C(work[9]) == 1) {
            if (work[0x17] < 2) {
                break;
            }
            work[0x17] = 0;
            ov83_022433B8(work);
            BeginNormalPaletteFade(0, 1, 1, 0, 6, 3, 0x6B);
            work[8]++;
        } else {
            work[8]++;
        }
        break;
    case 4:
        if (IsPaletteFadeFinished() == 1) {
            return TRUE;
        }
        break;
    }
    return FALSE;
}
