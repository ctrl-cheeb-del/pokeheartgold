#ifndef OV70_RESIDUAL_4_PRIVATE_H
#define OV70_RESIDUAL_4_PRIVATE_H

#include "global.h"

#include "bg_window.h"
#include "filesystem.h"
#include "gf_gfx_loader.h"
#include "heap.h"
#include "obj_char_transfer.h"
#include "obj_pltt_transfer.h"
#include "pokemon_icon_idx.h"
#include "sprite.h"
#include "sprite_transfer.h"
#include "touchscreen_list_menu.h"
#include "unk_02005D10.h"
#include "unk_02009D48.h"
#include "unk_0200A090.h"
#include "unk_0200B150.h"
#include "yes_no_prompt.h"

typedef struct Ov70WorkR4 {
    u8 pad0000[4];
    BgConfig *bgConfig;
    u8 pad0008[0xBF4 - 8];
    SpriteList *spriteList;
    G2dRenderer renderer;
    u8 padRendererEnd[0xD20 - 0xBF8 - sizeof(G2dRenderer)];
    GF_2DGfxResMan *resourceManagers[4];
    SpriteResource *resources[8];
    u8 padD50[0xD60 - 0xD50];
    SpriteResourcesHeader headers[2];
    u8 padDA8[0x11AC - 0xDA8];
    ListMenuItem *listItems;
    u8 pad11B0[0x11C8 - 0x11B0];
    YesNoPrompt *yesNoPrompt;
    TouchscreenListMenuSpawner *menuSpawner;
} Ov70WorkR4;

extern const ObjCharTransferTemplate ov70_02245208;
extern const TouchscreenListMenuTemplate _022451EC;

void ov70_02238FB4(int);
void ov70_02238FE0(void);
void ov70_02238880(void);
void ov70_022388D0(void);
void ov70_02238900(Ov70WorkR4 *);
void ov70_02238B54(SpriteTemplate *, Ov70WorkR4 *, const SpriteResourcesHeader *, NNS_G2D_VRAM_TYPE);
void ov70_02238B80(Ov70WorkR4 *);
YesNoPrompt *ov70_02238C14(BgConfig *, u8, int, u32, u8);
YesNoPrompt *ov70_02238C2C(BgConfig *, u8, int, u32, int, u8);
YesNoResponse ov70_02238C8C(Ov70WorkR4 *);
TouchscreenListMenu *ov70_02238CAC(Ov70WorkR4 *, u8, int);
void ov70_02238D38(TouchscreenListMenu *, u8, void *, int);

#endif
