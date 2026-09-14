#include "global.h"

#define U32AT(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PAT(p, o)   (*(void **)((u8 *)(p) + (o)))

extern void *OverlayManager_GetData(void *);
extern void *OverlayManager_GetArgs(void *);
extern void OverlayManager_FreeData(void *);
extern void Heap_Free(void *);
extern void Main_SetVBlankIntrCB(void *, void *);
extern void RemoveWindow(void *);
extern void GfGfx_EngineATogglePlanes(u32, u32);
extern void FreeBgTilemapBuffer(void *, u32);
extern void sub_020135AC(void *);
extern void SpriteSystem_FreeResourcesAndManager(void *, void *);
extern void SpriteSystem_Free(void *);
extern void GF_DestroyVramTransferManager(void);
extern void PaletteData_FreeBuffers(void *, u32);
extern void PaletteData_Free(void *);
extern void String_Delete(void *);
extern void MessageFormat_Delete(void *);
extern void DestroyMsgData(void *);
extern void SysTask_Destroy(void *);
extern void sub_02021238(void);
extern void TextFlags_SetCanABSpeedUpPrint(u32);
extern void TextFlags_SetAutoScrollParam(u32);
extern void TextFlags_SetCanTouchSpeedUpPrint(u32);
extern void sub_0203A914(void);
extern void ov90_02258C38(void *);
extern void ov93_022602E4(void *);
extern void ov93_02260608(void *);
extern void ov93_0225D064(void *);
extern void ov93_0225D6E0(void *);
extern void ov93_0225D9E8(void *);
extern void ov93_0225DAF8(void *);
extern void ov93_0225DBC4(void *);
extern void ov93_0225DD28(void *);
extern void ov93_0225DED0(void *);
extern void ov93_0225E860(void *, void *);
extern void ov93_0225CFB8(void *);
extern int IsPaletteFadeFinished(void);
extern void sub_0200FB70(void);
extern void sub_0200FC20(int);
extern int ov90_02258B98(void *);
extern void sub_02037AC0(int);
extern int sub_02037B38(int);
extern int ov93_022627A4(void);
extern void ov93_0225E10C(void *);
extern void ov93_02262250(void *);
extern void BeginNormalPaletteFade(int, int, int, int, int, int, int);
extern void ov93_0225E764(void *);
extern void ov93_02262310(void *);
extern int ov93_02262374(void *, void *);
extern void ov90_02258C8C(void *);
extern int ov90_02258CE0(void *);
extern void ov93_0225D4B8(void *);
extern void ov93_0225D5AC(void *, int);
extern void ov90_02258CB0(void *);
extern void ov93_0225E4B0(void *);
extern void ov93_0225E370(void *);
extern int ov93_0225E300(void *);
extern void ov93_0225E7AC(void *);
extern void GfGfx_DisableEngineAPlanes(void);
extern void GfGfx_DisableEngineBPlanes(void);
extern void G2x_SetBlendAlpha_(u32, int, int, int, int);
extern void *OverlayManager_CreateAndGetData(void *, u32, u32);
extern void HeapExp_FndInitAllocator(void *, u32, u32);
extern void *ov93_0225CF14(u32);
extern void ov93_022626FC(void *);
extern void *PaletteData_Init(u32);
extern void PaletteData_SetAutoTransparent(void *, int);
extern void PaletteData_AllocBuffers(void *, int, u32, u32);
extern void *BgConfig_Alloc(u32);
extern void GF_CreateVramTransferManager(int, u32);
extern void SetKeyRepeatTimers(int, int);
extern void ov93_0225D1D8(void *);
extern void sub_020210BC(void);
extern void sub_02021148(int);
extern void ov93_0225CFC0(void *);
extern void *SpriteSystem_Alloc(u32);
extern void SpriteSystem_Init(void *, const void *, const void *, u32);
extern void G2dRenderer_SetObjCharTransferReservedRegion(int, u32);
extern void G2dRenderer_SetPlttTransferReservedRegion(int);
extern void *SpriteManager_New(void *);
extern void SpriteSystem_InitSprites(void *, void *, int);
extern void SpriteSystem_InitManagerWithCapacities(void *, void *, const void *);
extern void *SpriteSystem_GetRenderer(void *);
extern void G2dRenderer_SetSubSurfaceCoords(void *, int, int);
extern void ov93_0225D674(void *);
extern void *NewMsgDataFromNarc(int, int, int, int);
extern void *MessageFormat_New(int);
extern void *String_New(int, int);
extern void *FontSystem_NewInit(int, int);
extern void ov93_02261310(void *, void *);
extern void *NARC_New(int, int);
extern void NARC_Delete(void *);
extern void ov93_0225DB2C(void *, void *);
extern void ov93_0225DBC8(void *, void *);
extern void ov93_0225D380(void *);
extern void ov93_0225D78C(void *, void *);
extern void ov93_0225DA40(void *, void *);
extern void ov93_0225DD2C(void *, void *);
extern void PaletteData_LoadNarc(void *, int, int, int, int, int, int);
extern void ov93_0225D4EC(void *);
extern void ov93_0225D468(void *);
extern void sub_0203A880(void);
extern void *ov93_0225E7B0(void *);
extern void *SysTask_CreateOnMainQueue(void *, void *, u32);
extern void GfGfx_SwapDisplay(void);
extern void GfGfx_BothDispOn(void);
extern void GfGfx_EngineBTogglePlanes(int, int);
extern void *SpriteManager_GetSpriteList(void *);
extern void *ov90_02258BD4(void *, int);
extern u32 ov90_02258C74(void *);
extern void PaletteData_LoadPaletteSlotFromHardware(void *, int, u32, int);
extern void ov93_0225CEA0(void *);
extern void ov93_0225D07C(void *);
extern void ov00_021E69A8(int);
extern const u8 ov93_02262AA8[];
extern const u8 ov93_02262A7C[];
extern const u8 ov93_02262A90[];
extern u8 gSystem[];

u32 ov93_0225C768(void *);

u32 ov93_0225C768(void *man) {
    void *p;
    void *narc;

    Main_SetVBlankIntrCB(NULL, NULL);
    GfGfx_DisableEngineAPlanes();
    GfGfx_DisableEngineBPlanes();
    *(vu32 *)0x04000000 &= 0xffffe0ff;
    *(vu32 *)0x04001000 &= 0xffffe0ff;
    *(vu32 *)0x04000000 &= 0xffff1fff;
    *(vu32 *)0x04001000 &= 0xffff1fff;
    G2x_SetBlendAlpha_(0x04000050, 1, 0x3f, 0x10, 0x10);
    G2x_SetBlendAlpha_(0x04001050, 8, 0x1f, 0xd, 3);
    p = OverlayManager_CreateAndGetData(man, 0x3850, 0x75);
    MI_CpuFill8(p, 0, 0x3850);
    HeapExp_FndInitAllocator((u8 *)p + 0xa8, 0x75, 0x20);
    PAT(p, 0x98) = ov93_0225CF14(0x75);
    PAT(p, 0) = OverlayManager_GetArgs(man);
    ov93_022626FC(p);
    PAT(p, 0x8c) = PaletteData_Init(0x75);
    PaletteData_SetAutoTransparent(PAT(p, 0x8c), 1);
    PaletteData_AllocBuffers(PAT(p, 0x8c), 0, 0x200, 0x75);
    PaletteData_AllocBuffers(PAT(p, 0x8c), 1, 0x200, 0x75);
    PaletteData_AllocBuffers(PAT(p, 0x8c), 2, 0x1c0, 0x75);
    PaletteData_AllocBuffers(PAT(p, 0x8c), 3, 0x200, 0x75);
    PAT(p, 0x2c) = BgConfig_Alloc(0x75);
    GF_CreateVramTransferManager(0x40, 0x75);
    SetKeyRepeatTimers(4, 8);
    ov93_0225D1D8(PAT(p, 0x2c));
    sub_020210BC();
    sub_02021148(4);
    ov93_0225CFC0(p);
    PAT(p, 0x24) = SpriteSystem_Alloc(0x75);
    SpriteSystem_Init(PAT(p, 0x24), ov93_02262AA8, ov93_02262A7C, 0x20);
    G2dRenderer_SetObjCharTransferReservedRegion(1, 0x00100010);
    G2dRenderer_SetPlttTransferReservedRegion(1);
    PAT(p, 0x28) = SpriteManager_New(PAT(p, 0x24));
    SpriteSystem_InitSprites(PAT(p, 0x24), PAT(p, 0x28), 0xe0);
    SpriteSystem_InitManagerWithCapacities(PAT(p, 0x24), PAT(p, 0x28), ov93_02262A90);
    G2dRenderer_SetSubSurfaceCoords(SpriteSystem_GetRenderer(PAT(p, 0x24)), 0, 0x160000);
    ov93_0225D674(p);
    PAT(p, 0x80) = NewMsgDataFromNarc(0, 0x1b, 0xc, 0x75);
    PAT(p, 0x84) = MessageFormat_New(0x75);
    PAT(p, 0x88) = String_New(0x140, 0x75);
    PAT(p, 0x90) = FontSystem_NewInit(0x13, 0x75);
    ov93_02261310(p, (u8 *)p + 0x1468);
    narc = NARC_New(0xc9, 0x75);
    ov93_0225DB2C(p, narc);
    ov93_0225DBC8(p, narc);
    ov93_0225D380(p);
    ov93_0225D78C(p, narc);
    ov93_0225DA40(p, narc);
    ov93_0225DD2C(p, narc);
    NARC_Delete(narc);
    PaletteData_LoadNarc(PAT(p, 0x8c), 0x10, 7, 0x75, 0, 0x20, 0xe0);
    PaletteData_LoadNarc(PAT(p, 0x8c), 0x10, 7, 0x75, 1, 0x20, 0x50);
    ov93_0225D4EC(p);
    ov93_0225D5AC(p, 0);
    ov93_0225D468(p);
    sub_0203A880();
    PAT(p, 0xd4) = ov93_0225E7B0(p);
    BeginNormalPaletteFade(0, 0x1b, 0x1b, 0, 6, 1, 0x75);
    PAT(p, 0x94) = SysTask_CreateOnMainQueue(ov93_0225D07C, p, 0xea60);
    gSystem[0x69] = 1;
    GfGfx_SwapDisplay();
    GfGfx_BothDispOn();
    GfGfx_EngineATogglePlanes(0x10, 1);
    GfGfx_EngineBTogglePlanes(0x10, 1);
    TextFlags_SetAutoScrollParam(1);
    TextFlags_SetCanABSpeedUpPrint(0);
    TextFlags_SetCanTouchSpeedUpPrint(0);
    PAT(p, 0x1c) = ov90_02258BD4(SpriteManager_GetSpriteList(PAT(p, 0x28)), 0x75);
    PaletteData_LoadPaletteSlotFromHardware(PAT(p, 0x8c), 2, (ov90_02258C74(PAT(p, 0x1c)) << 20) >> 16, 0x60);
    Main_SetVBlankIntrCB(ov93_0225CEA0, p);
    if (*(u8 *)((u8 *)PAT(p, 0) + 0x3c) != 0) {
        ov00_021E69A8(0x75);
    }
    return 1;
}

typedef struct Ov93LifecycleWork {
    u8 pad[0x2fb4];
    u32 counter;
    u32 enabled;
} Ov93LifecycleWork;

u32 ov93_0225CA8C(void *, int *);

u32 ov93_0225CA8C(void *man, int *state) {
    void *p = OverlayManager_GetData(man);

    if (*(u8 *)((u8 *)PAT(p, 0) + 0x3d) == 1) {
        switch (*(u8 *)((u8 *)PAT(p, 0) + 0x3e)) {
        case 0:
            if (IsPaletteFadeFinished() == 1) {
                sub_0200FB70();
            }
            sub_0200FC20(0);
            *(volatile u32 *)0x04000000 &= 0xffff1fff;
            (*(u8 *)((u8 *)PAT(p, 0) + 0x3e))++;
            break;
        case 1:
        default:
            if (ov90_02258B98(PAT(p, 0)) == 1) {
                return 1;
            }
            break;
        }
        return 0;
    }

    switch (*state) {
    case 0:
        if (IsPaletteFadeFinished() == 1) {
            (*state)++;
        }
        break;
    case 1:
        sub_02037AC0(0xd3);
        (*state)++;
        break;
    case 2:
        if (sub_02037B38(0xd3) == 1) {
            (*state)++;
        }
        break;
    case 3:
        if (ov93_022627A4() == 1) {
            (*state)++;
        }
        break;
    case 4:
        if (U32AT(p, 8) >= *(u8 *)((u8 *)PAT(p, 0) + 0x30)) {
            ov93_0225E10C(p);
            (*state)++;
        }
        break;
    case 5:
        if (U32AT(p, 0x2fc0) == 1) {
            ov93_02262250(p);
            BeginNormalPaletteFade(0, 0x1a, 0x1a, 0, 6, 1, 0x75);
            (*state)++;
        }
        ov93_0225E764(p);
        switch (U32AT(p, 0x20)) {
        case 1:
            u32 blend;
            *(volatile u32 *)0x04000000 = (*(volatile u32 *)0x04000000 & 0xffff1fff) | ((u32)0x04000000 >> 12);
            *(volatile u16 *)0x04000042 = 0x44c;
            *(volatile u16 *)0x04000046 = 0xa8b8;
            *(volatile u16 *)0x04000048 = (*(volatile u16 *)0x04000048 & 0xffffc0ff) | ((u32)0x04000000 >> 14);
            blend = *(volatile u16 *)0x0400004a;
            blend = (blend & ~0x3f) | 0x1f;
            blend |= 0x20;
            *(volatile u16 *)0x0400004a = blend;
            ov93_02262310(p);
            U32AT(p, 0x20) = 2;
        case 2:
            if (ov93_02262374(p, (u8 *)p + 0x174c) == 1) {
                U32AT(p, 0x1768) = 1;
                U32AT(p, 0x20) = 0;
            }
            break;
        case 3:
            ov90_02258C8C(PAT(p, 0x1c));
            U32AT(p, 0x20) = 4;
            break;
        case 4:
            if (ov90_02258CE0(PAT(p, 0x1c)) == 1) {
                U32AT(p, 0x2fb8) = 1;
                *(u8 *)((u8 *)p + 0x1559) = 0;
                U32AT(p, 0x20) = 5;
                ov93_0225D4B8(p);
                ov93_0225D5AC(p, 1);
            }
            break;
        case 6:
            ov90_02258CB0(PAT(p, 0x1c));
            U32AT(p, 0x20) = 7;
            break;
        case 7:
            if (ov90_02258CE0(PAT(p, 0x1c)) == 1) {
                U32AT(p, 0x20) = 8;
            }
            break;
        }
        ov93_0225E4B0(p);
        ov93_0225E370(p);
        if (U32AT(p, 0x2fbc) != 1) {
            if (ov93_0225E300(p) == 1) {
                U32AT(p, 0x2fc4) = 13;
            }
            if (((Ov93LifecycleWork *)p)->enabled == 1 && ((Ov93LifecycleWork *)p)->counter <= 0x516) {
                ((Ov93LifecycleWork *)p)->counter++;
            }
        }
        break;
    case 6:
        if (IsPaletteFadeFinished() == 1) {
            return 1;
        }
        break;
    }

    ov93_0225E7AC(PAT(p, 0x9c));
    U32AT(p, 0x384c)
    ++;
    return 0;
}

u32 ov93_0225CD10(void *);

u32 ov93_0225CD10(void *man) {
    void *p;
    u8 *window;
    s32 i;

    p = OverlayManager_GetData(man);
    U32AT(PAT(p, 0), 0x24) = U32AT(p, 0x2fd0);
    ov90_02258C38(PAT(p, 0x1c));
    ov93_022602E4(p);
    ov93_02260608(p);
    Main_SetVBlankIntrCB(NULL, NULL);
    ov93_0225D6E0(p);
    ov93_0225D9E8(p);
    ov93_0225DAF8(p);
    ov93_0225DBC4(p);
    ov93_0225DD28(p);
    ov93_0225DED0(p);
    ov93_0225E860(p, PAT(p, 0xd4));

    i = 0;
    window = (u8 *)p + 0x30;
    for (; i < 5; i++, window += 0x10) {
        RemoveWindow(window);
    }
    GfGfx_EngineATogglePlanes(1, 0);
    GfGfx_EngineATogglePlanes(2, 0);
    FreeBgTilemapBuffer(PAT(p, 0x2c), 1);
    FreeBgTilemapBuffer(PAT(p, 0x2c), 2);
    FreeBgTilemapBuffer(PAT(p, 0x2c), 3);
    FreeBgTilemapBuffer(PAT(p, 0x2c), 4);
    FreeBgTilemapBuffer(PAT(p, 0x2c), 5);
    FreeBgTilemapBuffer(PAT(p, 0x2c), 6);
    FreeBgTilemapBuffer(PAT(p, 0x2c), 7);
    sub_020135AC(PAT(p, 0x90));
    SpriteSystem_FreeResourcesAndManager(PAT(p, 0x24), PAT(p, 0x28));
    SpriteSystem_Free(PAT(p, 0x24));
    GF_DestroyVramTransferManager();
    PaletteData_FreeBuffers(PAT(p, 0x8c), 0);
    PaletteData_FreeBuffers(PAT(p, 0x8c), 1);
    PaletteData_FreeBuffers(PAT(p, 0x8c), 2);
    PaletteData_FreeBuffers(PAT(p, 0x8c), 3);
    PaletteData_Free(PAT(p, 0x8c));
    String_Delete(PAT(p, 0x88));
    MessageFormat_Delete(PAT(p, 0x84));
    DestroyMsgData(PAT(p, 0x80));
    Heap_Free(PAT(p, 0x2c));
    ov93_0225D064(p);
    SysTask_Destroy(PAT(p, 0x94));
    *(volatile u32 *)0x04000000 &= 0xffff1fff;
    *(volatile u32 *)0x04001000 &= 0xffff1fff;
    ov93_0225CFB8(PAT(p, 0x98));
    sub_02021238();
    OverlayManager_FreeData(man);
    TextFlags_SetCanABSpeedUpPrint(0);
    TextFlags_SetAutoScrollParam(0);
    TextFlags_SetCanTouchSpeedUpPrint(0);
    sub_0203A914();
    return 1;
}
