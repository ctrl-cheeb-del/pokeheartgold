#include "global.h"

#include "overlay68_helpers_internal.h"

typedef struct OverlayManager OverlayManager;
typedef struct NARC NARC;

extern void Heap_Create(int, int, u32);
extern void Heap_Destroy(int);
extern void *OverlayManager_CreateAndGetData(OverlayManager *, u32, int);
extern void *OverlayManager_GetData(OverlayManager *);
extern void *OverlayManager_GetArgs(OverlayManager *);
extern void OverlayManager_FreeData(OverlayManager *);
extern BgConfig *BgConfig_Alloc(int);
extern NARC *NARC_New(int, int);
extern void NARC_Delete(NARC *);
extern void SpriteSystem_DrawSprites(void *);
extern void HBlankInterruptDisable(void);

extern void GfGfx_DisableEngineAPlanes(void);
extern void GfGfx_DisableEngineBPlanes(void);
extern int MenuInputStateMgr_GetState(void *);

extern u32 ov68_021E5F50(MoveRelearner *);
extern u32 ov68_021E5F68(MoveRelearner *);
extern u32 ov68_021E6058(MoveRelearner *);
extern u32 ov68_021E6078(MoveRelearner *);
extern u32 ov68_021E60D8(MoveRelearner *);
extern u32 ov68_021E614C(MoveRelearner *);
extern u32 ov68_021E61B8(MoveRelearner *);
extern u32 ov68_021E74D8(MoveRelearner *);
extern u32 ov68_021E7568(MoveRelearner *);
extern u32 ov68_021E7AD8(MoveRelearner *);
extern void ov68_021E73A4(MoveRelearner *, u8, int);
extern void ov68_021E7424(MoveRelearner *, int, int);
extern void ov68_021E734C(void *);
extern void ov68_021E5BA0(NARC *);
extern void ov68_021E5BC0(BgConfig *);
extern void ov68_021E5D24(MoveRelearner *, NARC *);
extern void ov68_021E7178(MoveRelearner *, NARC *);
extern void ov68_021E7288(MoveRelearner *);
extern void ov68_021E5E48(MoveRelearner *);
extern void ov68_021E6820(MoveRelearner *);
extern void ov68_021E6320(MoveRelearner *);
extern void ov68_021E75C0(MoveRelearner *);

BOOL MoveRelearner_Init(OverlayManager *, int *);
BOOL MoveRelearner_Main(OverlayManager *, int *);
BOOL MoveRelearner_Exit(OverlayManager *, int *);
void ov68_021E5A58(MoveRelearner *);

BOOL MoveRelearner_Init(OverlayManager *manager, int *state) {
    MoveRelearner *work;
    Heap_Create(HEAP_ID_3, HEAP_ID_66, 9 << 14);
    work = OverlayManager_CreateAndGetData(manager, 0x1DC, HEAP_ID_66);
    memset(work, 0, 0x1DC);
    work->args = OverlayManager_GetArgs(manager);
    ov68_021E5A58(work);
    ov68_021E73A4(work, (u8)work->args->unk_14, 3);
    *(u32 *)((u8 *)work + 0x1B0) = 1;
    ov68_021E7424(work, 0, 0);
    Main_SetVBlankIntrCB(ov68_021E5B6C, work);
    return TRUE;
}

BOOL MoveRelearner_Main(OverlayManager *manager, int *state) {
    MoveRelearner *work = OverlayManager_GetData(manager);
    switch (*state) {
    case 0:
        *state = ov68_021E5F50(work);
        break;
    case 1:
        *state = ov68_021E5F68(work);
        break;
    case 2:
        *state = ov68_021E6058(work);
        break;
    case 3:
        *state = ov68_021E6078(work);
        break;
    case 4:
        *state = ov68_021E60D8(work);
        break;
    case 5:
        *state = ov68_021E614C(work);
        break;
    case 6:
        *state = ov68_021E61A0(work);
        break;
    case 7:
        *state = ov68_021E61B8(work);
        break;
    case 8:
        *state = ov68_021E61EC(work);
        break;
    case 9:
        return TRUE;
    case 10:
        *state = ov68_021E74C0(work);
        break;
    case 11:
        *state = ov68_021E74D8(work);
        return FALSE;
    case 12:
        *state = ov68_021E7568(work);
        return FALSE;
    case 13:
        *state = ov68_021E7AD8(work);
        break;
    case 14:
        *state = ov68_021E7B6C(work);
        break;
    case 15:
        *state = ov68_021E7B8C(work);
        break;
    }
    ov68_021E734C((u8 *)work + 0x154);
    SpriteSystem_DrawSprites(*(void **)((u8 *)work + 0x120));
    return FALSE;
}

BOOL MoveRelearner_Exit(OverlayManager *manager, int *state) {
    MoveRelearner *work = OverlayManager_GetData(manager);
    ov68_021E5B14(work);
    OverlayManager_FreeData(manager);
    Heap_Destroy(HEAP_ID_66);
    return TRUE;
}

void ov68_021E5A58(MoveRelearner *work) {
    NARC *narc;
    Main_SetVBlankIntrCB(NULL, NULL);
    HBlankInterruptDisable();
    GfGfx_DisableEngineAPlanes();
    GfGfx_DisableEngineBPlanes();
    *(vu32 *)0x04000000 &= 0xFFFFE0FF;
    *(vu32 *)0x04001000 &= 0xFFFFE0FF;
    TextFlags_SetCanTouchSpeedUpPrint(TRUE);
    work->unk_1B4 = (void *)MenuInputStateMgr_GetState(work->args->unk_0C);
    work->bgConfig = BgConfig_Alloc(HEAP_ID_66);
    narc = NARC_New(0x6E, HEAP_ID_66);
    ov68_021E5BA0(narc);
    ov68_021E5BC0(work->bgConfig);
    ov68_021E5D24(work, narc);
    ov68_021E7178(work, narc);
    ov68_021E7288(work);
    ov68_021E5EBC(work);
    ov68_021E5E48(work);
    ov68_021E6820(work);
    ov68_021E6204(work);
    ov68_021E6320(work);
    ov68_021E75C0(work);
    sub_020880CC(0, HEAP_ID_66);
    Main_SetVBlankIntrCB(ov68_021E5B6C, work);
    NARC_Delete(narc);
}
