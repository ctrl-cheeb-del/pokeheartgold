#include "global.h"

#include "bg_window.h"
#include "gf_gfx_planes.h"

extern const GraphicsBanks ov111_021E6BD8;

void Main_SetVBlankIntrCB(void (*callback)(void *), void *arg);
void HBlankInterruptDisable(void);
void GfGfx_DisableEngineAPlanes(void);
void GfGfx_DisableEngineBPlanes(void);
void GF_AssertFail(void);
void SpriteSystem_DrawSprites(void *system);
void SpriteSystem_TransferOam(void);
u32 CalculateHpBarPixelsLength(u32 hp, u32 maxHp, u32 width);
u32 CalculateHpBarColor(u32 hp, u32 maxHp, u32 width);

void ov111_021E5CB4(void);
void ov111_021E5CD4(void);
void ov111_021E5D08(void *work, int which);
void ov111_021E5DF0(void *work);
void ov111_021E5D2C(Window *window, u32 hp, u32 maxHp);

void ov111_021E5CB4(void) {
    GraphicsBanks banks = ov111_021E6BD8;

    GfGfx_SetBanks(&banks);
}

void ov111_021E5CD4(void) {
    Main_SetVBlankIntrCB(NULL, NULL);
    HBlankInterruptDisable();
    GfGfx_DisableEngineAPlanes();
    GfGfx_DisableEngineBPlanes();
    *(u32 *)0x04000000 &= 0xFFFFE0FF;
    *(u32 *)0x04001000 &= 0xFFFFE0FF;
}

void ov111_021E5D08(void *work, int which) {
    switch (which) {
    case 1: {
        u32 *values = *(u32 **)((u8 *)work + 4);
        values[4] = values[0];
        return;
    }
    case 2: {
        u32 *values = *(u32 **)((u8 *)work + 4);
        values[4] = values[1];
        return;
    }
    default:
        GF_AssertFail();
    }
}

void ov111_021E5D2C(Window *window, u32 hp, u32 maxHp) {
    BgConfig *bgConfig = GetWindowBgConfig(window);
    u8 bgId = GetWindowBgId(window);
    u8 x = GetWindowX(window);
    u8 y = GetWindowY(window);
    u32 length = CalculateHpBarPixelsLength(hp, maxHp, 0x30);
    u8 tile;
    u8 i;

    switch (CalculateHpBarColor(hp, maxHp, 0x30)) {
    case 0:
    case 3:
    case 4:
        tile = 1;
        break;
    case 2:
        tile = 10;
        break;
    case 1:
        tile = 19;
        break;
    default:
        GF_AssertFail();
        break;
    }
    for (i = 0; i < 6; i++) {
        u16 fill;
        if (length >= 8) {
            fill = tile + 8;
        } else {
            fill = tile + length;
        }
        FillBgTilemapRect(bgConfig, bgId, fill, x + i, y, 1, 1, 0x11);
        if (length < 8) {
            length = 0;
        } else {
            length = (u8)(length - 8);
        }
    }
    ScheduleBgTilemapBufferTransfer(bgConfig, bgId);
}

void ov111_021E5DF0(void *work) {
    u8 *bytes = work;
    vu32 *base = (vu32 *)0x027E0000;

    if (bytes == NULL) {
        GF_AssertFail();
    }
    if (*(void **)(bytes + 0x10) == NULL) {
        GF_AssertFail();
    }
    if (*(void **)(bytes + 8) == NULL) {
        GF_AssertFail();
    }
    SpriteSystem_DrawSprites(*(void **)(bytes + 0x10));
    SpriteSystem_TransferOam();
    DoScheduledBgGpuUpdates(*(void **)(bytes + 8));
    base[0x3FF8 / sizeof(u32)] |= 1;
}
