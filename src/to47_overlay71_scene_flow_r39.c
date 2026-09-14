#include "global.h"

#include <nitro/code16.h>

typedef struct Ov71SceneWorkR39 {
    void *unk_00;
    u8 pad_04[0x08 - 0x04];
    s32 unk_08;
    void *unk_0C;
    void *unk_10;
    u32 unk_14;
    void *unk_18;
    u32 unk_1C;
    u8 pad_20[0x24 - 0x20];
    void *unk_24;
    u8 pad_28[0x30 - 0x28];
    u32 unk_30;
    u32 unk_34;
    u32 unk_38;
} Ov71SceneWorkR39;

extern const u16 ov71_0224BEE8[];
extern const u8 ov71_0224BEFC[];
extern const u8 ov71_0224BF1C[];
extern const u8 ov71_0224BF38[];
extern const u8 ov71_0224BF54[];

extern BOOL IsPaletteFadeFinished(void);
extern void BeginNormalPaletteFade(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern void ov71_0224AFD4(Ov71SceneWorkR39 *work, u32 *arg);
extern void ov71_0224AF08(Ov71SceneWorkR39 *work, u32 *arg);
extern void *ov71_02246C6C(u32 *arg, s32 a1);
extern void ov71_02246D40(void *arg);
extern void ov71_0224B084(void *a0, s32 a1, s32 a2, s32 a3, u32 *a4);
extern void *ov71_02247000(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 *a6);
extern u32 ov71_022473A0(void *ctx);

extern void GfGfx_SetBanks(const void *banks);
extern void SetBothScreensModesAndDisable(const void *modes);
extern void InitBgFromTemplate(void *bgConfig, u32 layer, const void *template, u32 bgType);
extern u32 GfGfxLoader_LoadCharData(u32 narcId, s32 memberNo, void *bgConfig, u32 layer, u32 tileStart, u32 szByte, u32 isCompressed, u32 heapId);
extern void GfGfxLoader_LoadScrnData(u32 narcId, s32 memberNo, void *bgConfig, u32 layer, u32 tileStart, u32 szByte, u32 isCompressed, u32 heapId);
extern void GfGfxLoader_GXLoadPal(u32 narcId, s32 memberNo, u32 location, u32 palSlotOffset, u32 szByte, u32 heapId);
extern void GfGfxLoader_GXLoadPalWithSrcOffset(u32 narcId, s32 memberNo, u32 location, u32 srcOffset, u32 palSlotOffset, u32 szByte, u32 heapId);
extern void *Heap_Alloc(u32 heapId, u32 size);
extern void Heap_Free(void *ptr);
extern void DC_FlushRange(const void *addr, u32 size);
extern void GX_BeginLoadBGExtPltt(void);
extern void GXS_BeginLoadBGExtPltt(void);
extern void GX_LoadBGExtPltt(const void *src, u32 offset, u32 size);
extern void GXS_LoadBGExtPltt(const void *src, u32 offset, u32 size);
extern void GX_EndLoadBGExtPltt(void);
extern void GXS_EndLoadBGExtPltt(void);
extern void BgSetPosTextAndCommit(void *bgConfig, u32 layer, u32 op, int val);
extern void ToggleBgLayer(u32 layer, u32 toggle);
extern void GfGfx_EngineATogglePlanes(u32 planeMask, u32 enable);
extern void GfGfx_EngineBTogglePlanes(u32 planeMask, u32 enable);

BOOL ov71_0224AA28(Ov71SceneWorkR39 *work, u32 *state);
BOOL ov71_0224AAF8(Ov71SceneWorkR39 *work, u32 *state);
void ov71_0224AB7C(Ov71SceneWorkR39 *work);



BOOL ov71_0224AA28(Ov71SceneWorkR39 *work, u32 *state) {
    switch (*state) {
    case 0:
        if (IsPaletteFadeFinished()) {
            work->unk_08 = 0;
            ov71_0224AFD4(work, &work->unk_30);
            (*state)++;
        }
        break;
    case 1:
        work->unk_08++;
        if (work->unk_08 > 8) {
            ov71_0224AF08(work, &work->unk_34);
            (*state)++;
        }
        break;
    case 2:
        if (work->unk_34 == 0 && work->unk_30 == 0) {
            (*state)++;
        }
        break;
    case 3:
        work->unk_10 = ov71_02246C6C(&work->unk_14, -1);
        work->unk_08 = 0;
        (*state)++;
        break;
    case 4:
        work->unk_08++;
        if (work->unk_08 > 30) {
            ov71_0224B084(work->unk_24, 31, 0, 40, &work->unk_38);
            (*state)++;
        }
        break;
    case 5:
        if (work->unk_38 == 0) {
            ov71_02246D40(work->unk_10);
            (*state)++;
        }
        break;
    case 6:
        if (work->unk_14 == 0) {
            return TRUE;
        }
        break;
    }
    return FALSE;
}

BOOL ov71_0224AAF8(Ov71SceneWorkR39 *work, u32 *state) {
    switch (*state) {
    case 0:
        work->unk_18 = ov71_02247000(work->unk_0C, 0x1000, 0x400, 1, 0x128, 1, &work->unk_1C);
        work->unk_08 = 0;
        (*state)++;
        break;
    case 1:
        work->unk_08++;
        if (work->unk_08 > 13) {
            BeginNormalPaletteFade(0, 0, 0, 0, 8, 1, 0x39);
            (*state)++;
        }
        break;
    case 2:
        if (IsPaletteFadeFinished() && work->unk_1C) {
            return TRUE;
        }
        break;
    default:
        break;
    }
    return FALSE;
}

void ov71_0224AB7C(Ov71SceneWorkR39 *work) {
    OSIntrMode intr;
    void *buf;
    u32 idx;
    u16 srcOffset;

    GfGfx_SetBanks(ov71_0224BF54);
    reg_GX_POWCNT |= 0x8000;
    SetBothScreensModesAndDisable(ov71_0224BEFC);
    InitBgFromTemplate(work->unk_0C, 2, ov71_0224BF1C, 1);
    InitBgFromTemplate(work->unk_0C, 6, ov71_0224BF1C, 1);
    intr = OS_DisableInterrupts();
    InitBgFromTemplate(work->unk_0C, 3, ov71_0224BF38, 2);
    InitBgFromTemplate(work->unk_0C, 7, ov71_0224BF38, 2);
    OS_RestoreInterrupts(intr);
    GfGfxLoader_LoadCharData(0x59, 2, work->unk_0C, 2, 0, 0, 1, 0x39);
    GfGfxLoader_LoadCharData(0x59, 2, work->unk_0C, 6, 0, 0, 1, 0x39);
    GfGfxLoader_LoadScrnData(0x59, 1, work->unk_0C, 2, 0, 0, 1, 0x39);
    GfGfxLoader_LoadScrnData(0x59, 1, work->unk_0C, 6, 0, 0, 1, 0x39);
    idx = ov71_022473A0(work->unk_00);
    GfGfxLoader_GXLoadPal(0x59, 3, 0, 0, 0x20, 0x39);
    GfGfxLoader_GXLoadPal(0x59, 3, 4, 0, 0x20, 0x39);
    srcOffset = ov71_0224BEE8[idx];
    GfGfxLoader_GXLoadPalWithSrcOffset(0x59, 3, 0, srcOffset, 0x20, 0x40, 0x39);
    GfGfxLoader_GXLoadPalWithSrcOffset(0x59, 3, 4, srcOffset, 0x20, 0x40, 0x39);
    GfGfxLoader_LoadCharData(0x59, 5, work->unk_0C, 3, 0, 0, 1, 0x39);
    GfGfxLoader_LoadCharData(0x59, 5, work->unk_0C, 7, 0, 0, 1, 0x39);
    GfGfxLoader_LoadScrnData(0x59, 4, work->unk_0C, 3, 0, 0, 1, 0x39);
    GfGfxLoader_LoadScrnData(0x59, 4, work->unk_0C, 7, 0, 0, 1, 0x39);
    buf = Heap_Alloc(0x39, 0x60);
    if (buf != NULL) {
        MIi_CpuClear32(0, (u32 *)buf, 0x60);
        DC_FlushRange(buf, 0x60);
        GX_BeginLoadBGExtPltt();
        GXS_BeginLoadBGExtPltt();
        GX_LoadBGExtPltt(buf, 6 * 0x1000, 0x60);
        GXS_LoadBGExtPltt(buf, 6 * 0x1000, 0x60);
        GX_EndLoadBGExtPltt();
        GXS_EndLoadBGExtPltt();
        Heap_Free(buf);
    }
    BgSetPosTextAndCommit(work->unk_0C, 2, 3, -384);
    BgSetPosTextAndCommit(work->unk_0C, 6, 3, -192);
    BgSetPosTextAndCommit(work->unk_0C, 3, 3, 67);
    ToggleBgLayer(7, 0);
    GfGfx_EngineATogglePlanes(0x10, 1);
    GfGfx_EngineBTogglePlanes(0x10, 1);
}
