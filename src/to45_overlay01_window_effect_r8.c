#include "global.h"

#include "bg_window.h"
#include "gf_gfx_loader.h"
#include "heap.h"
#include "sys_task.h"

typedef struct Ov01R8Work {
    s32 first;
    u8 padding_04[0x14];
    s32 second;
    u8 padding_1C[0x14];
    u32 scanline;
    u32 state;
    u8 padding_38[4];
    void *hblankTask;
    SysTask *vblankTask;
    u32 *finished;
} Ov01R8Work;

void ov01_021F03C8(void *unused, Ov01R8Work *work);
void ov01_021F03F8(Ov01R8Work *work);
void ov01_021F0360(void *unused, Ov01R8Work *work);
void ov01_021F0454(NARC *narc, int screenMember, int characterMember, int paletteMember, int palette, int paletteSize, BgConfig *bgConfig, int bgId);
void SysTask_Destroy(SysTask *task);
BOOL ov01_021EFF28(void *interp);
void ov01_021FB554(void *task);

void ov01_021F0360(void *unused, Ov01R8Work *work) {
    s32 first;
    s32 second;

    switch (work->state) {
    case 0:
        ov01_021EFF28(&work->second);
        if (ov01_021EFF28(&work->first)) {
            work->state++;
        }
        first = work->first >> 12;
        second = work->second >> 12;
        *(vu16 *)0x04000040 = 0xFF - first;
        *(vu16 *)0x04000044 = (u8)(0x60 - second);
        *(vu16 *)0x04000042 = 0xFF | ((first << 8) & 0xFF00);
        *(vu16 *)0x04000046 = 0xC0 | (((second + 0x60) << 8) & 0xFF00);
        break;
    case 1:
        ov01_021F03F8(work);
        break;
    }
}

void ov01_021F03C8(void *unused, Ov01R8Work *work) {
    vu32 *displayControl = (vu32 *)0x04000000;

    if (*(vu16 *)0x04000006 <= *(u32 *)((u8 *)work + 0x30)) {
        *displayControl = (*displayControl & 0xFFFF1FFF) | 0x2000;
    } else {
        *displayControl = (*displayControl & 0xFFFF1FFF) | 0x4000;
    }
}

void ov01_021F03F8(Ov01R8Work *work) {
    vu16 *windowControl = (vu16 *)0x04000048;
    u32 value;

    value = (windowControl[0] & ~0x3F) | 0x1F;
    value |= 0x20;
    windowControl[0] = value;
    windowControl[1] &= ~0x3F;
    *(vu16 *)0x04000040 = 0;
    *(vu16 *)0x04000044 = 0;
    *(vu32 *)0x04000000 = (*(vu32 *)0x04000000 & 0xFFFF1FFF) | 0x2000;
    *work->finished = 1;
    ov01_021FB554(work->hblankTask);
    work->hblankTask = NULL;
    SysTask_Destroy(work->vblankTask);
    work->vblankTask = NULL;
}

void ov01_021F0454(NARC *narc, int screenMember, int characterMember, int paletteMember, int palette, int paletteSize, BgConfig *bgConfig, int bgId) {
    NNSG2dScreenData *screen;
    void *screenFile;

    GfGfxLoader_GXLoadPalFromOpenNarc(narc, paletteMember, GF_PAL_LOCATION_MAIN_BG, (enum GFPalSlotOffset)(palette << 5), paletteSize << 5, (enum HeapID)4);
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, characterMember, bgConfig, (GFBgLayer)bgId, 0, 0, FALSE, (enum HeapID)4);
    screenFile = GfGfxLoader_GetScrnDataFromOpenNarc(narc, screenMember, FALSE, &screen, (enum HeapID)4);
    LoadRectToBgTilemapRect(bgConfig, (u8)bgId, screen->rawData, 0, 0, (u8)(screen->screenWidth >> 3), (u8)(screen->screenHeight >> 3));
    BgTilemapRectChangePalette(bgConfig, (u8)bgId, 0, 0, (u8)(screen->screenWidth >> 3), (u8)(screen->screenHeight >> 3), (u8)palette);
    Heap_Free(screenFile);
    ScheduleBgTilemapBufferTransfer(bgConfig, (u8)bgId);
}
