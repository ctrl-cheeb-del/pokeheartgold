#include "overlay92_lifecycle_r5_private.h"

extern void *OverlayManager_GetData(void *manager);
extern void OverlayManager_FreeData(void *manager);
extern void Heap_Destroy(int heapId);
extern void sub_020398D4(int, int);
extern void sub_02037AC0(int);
extern int sub_02037B38(int);
extern int sub_02037454(void);
extern int sub_020347A0(void);
extern int ov92_0225D8E4(void *work);

extern void *NARC_New(int narcId, int heapId);
extern void NARC_Delete(void *narc);
extern void *BgConfig_Alloc(int heapId);
extern void BgClearTilemapBufferAndCommit(void *, int);
extern void FreeBgTilemapBuffer(void *, int);
extern void *PaletteData_Init(int heapId);
extern void PaletteData_SetAutoTransparent(void *, int);
extern void PaletteData_AllocBuffers(void *, int, int, int);
extern void PaletteData_FreeBuffers(void *, int);
extern void PaletteData_Free(void *);
extern void *GF_3DVramMan_Create(int, int, int, int, int, int);
extern void GF_3DVramMan_Delete(void *);
extern void *Camera_New(int);
extern void Camera_Delete(void *);
extern void ov92_0225DD88(void *);
extern void ov92_0225D594(void *);
extern void ov92_0225D7CC(void *);
extern void HeapExp_FndInitAllocator(void *, int, int);
extern void G3X_SetEdgeColorTable(const u16 *);
extern const u16 ov92_022638B0[];

extern void GfGfx_EngineATogglePlanes(int, int);
extern void GfGfx_EngineBTogglePlanes(int, int);
extern void Heap_Free(void *);
extern void SpriteSystem_FreeResourcesAndManager(void *, void *);
extern void SpriteSystem_Free(void *);
extern void GfGfx_SwapDisplay(void);
extern u8 gSystem[];

int ov92_0225D36C(void *manager, int *state);
void ov92_0225D3CC(void *work);
void ov92_0225D49C(void *work);

int ov92_0225D36C(void *manager, int *state) {
    int result;
    if (*state == 0) {
        result = ov92_0225D8E4(OverlayManager_GetData(manager));
        OverlayManager_FreeData(manager);
        Heap_Destroy(0x71);
        sub_020398D4(0, 1);
        if (result != 0) {
            return 1;
        }
        sub_02037AC0(0xe7);
        (*state)++;
        goto return_false;
    } else {
        if (sub_02037B38(0xe7) == 1) {
            goto return_true;
        }
        result = sub_02037454();
        if (result >= sub_020347A0()) {
            goto return_false;
        }
        goto return_true;
    }
return_true:
    return 1;
return_false:
    return 0;
}

void ov92_0225D3CC(void *work) {
    PTR_AT(work, 0x48) = NARC_New(0xc1, 0x71);
    PTR_AT(work, 0x4c) = NARC_New(0xbd, 0x71);
    PTR_AT(work, 0x58) = BgConfig_Alloc(0x71);
    PTR_AT(work, 0x5c) = PaletteData_Init(0x71);
    PTR_AT(work, 0x60) = GF_3DVramMan_Create(0x71, 0, 1, 0, 4, 0);
    PTR_AT(work, 0x64) = Camera_New(0x71);
    ov92_0225DD88(work);
    PaletteData_SetAutoTransparent(PTR_AT(work, 0x5c), 1);
    PaletteData_AllocBuffers(PTR_AT(work, 0x5c), 0, 0x200, 0x71);
    PaletteData_AllocBuffers(PTR_AT(work, 0x5c), 1, 0x200, 0x71);
    PaletteData_AllocBuffers(PTR_AT(work, 0x5c), 2, 0x200, 0x71);
    PaletteData_AllocBuffers(PTR_AT(work, 0x5c), 3, 0x200, 0x71);
    ov92_0225D594(PTR_AT(work, 0x58));
    ov92_0225D7CC(work);
    *(vu16 *)0x04000060 = (*(vu16 *)0x04000060 & 0xffffcfff) | 8;
    *(vu16 *)0x04000060 = (*(vu16 *)0x04000060 & 0xffffcfff) | 0x20;
    G3X_SetEdgeColorTable(ov92_022638B0);
    HeapExp_FndInitAllocator((u8 *)work + 0x6c, 0x71, 0x20);
}

void ov92_0225D49C(void *work) {
    GfGfx_EngineATogglePlanes(1, 0);
    GfGfx_EngineATogglePlanes(2, 0);
    GfGfx_EngineATogglePlanes(4, 0);
    GfGfx_EngineATogglePlanes(8, 0);
    GfGfx_EngineBTogglePlanes(1, 0);
    GfGfx_EngineBTogglePlanes(2, 0);
    GfGfx_EngineBTogglePlanes(4, 0);
    GfGfx_EngineBTogglePlanes(8, 0);
    FreeBgTilemapBuffer(PTR_AT(work, 0x58), 0);
    FreeBgTilemapBuffer(PTR_AT(work, 0x58), 1);
    FreeBgTilemapBuffer(PTR_AT(work, 0x58), 2);
    FreeBgTilemapBuffer(PTR_AT(work, 0x58), 3);
    FreeBgTilemapBuffer(PTR_AT(work, 0x58), 4);
    FreeBgTilemapBuffer(PTR_AT(work, 0x58), 5);
    FreeBgTilemapBuffer(PTR_AT(work, 0x58), 6);
    FreeBgTilemapBuffer(PTR_AT(work, 0x58), 7);
    Heap_Free(PTR_AT(work, 0x58));
    PaletteData_FreeBuffers(PTR_AT(work, 0x5c), 0);
    PaletteData_FreeBuffers(PTR_AT(work, 0x5c), 1);
    PaletteData_FreeBuffers(PTR_AT(work, 0x5c), 2);
    PaletteData_FreeBuffers(PTR_AT(work, 0x5c), 3);
    PaletteData_Free(PTR_AT(work, 0x5c));
    NARC_Delete(PTR_AT(work, 0x48));
    NARC_Delete(PTR_AT(work, 0x4c));
    GF_3DVramMan_Delete(PTR_AT(work, 0x60));
    Camera_Delete(PTR_AT(work, 0x64));
    SpriteSystem_FreeResourcesAndManager(PTR_AT(work, 0x50), PTR_AT(work, 0x54));
    SpriteSystem_Free(PTR_AT(work, 0x50));
    gSystem[0x69] = 0;
    GfGfx_SwapDisplay();
    *(vu16 *)0x04000060 &= 0xcff7;
}
