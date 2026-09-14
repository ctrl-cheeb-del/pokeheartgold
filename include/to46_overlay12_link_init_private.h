#ifndef R46_OV12_LINK_PRIVATE_H
#define R46_OV12_LINK_PRIVATE_H
#include "global.h"

#include "battle/battle_022378C0.h"
#include "battle/battle_022378C0_tail_private.h"

#include "bg_window.h"
#include "gf_gfx_planes.h"
#include "msgdata.h"
#include "overlay_manager.h"
#include "palette.h"
#include "pm_string.h"
#include "render_window.h"
#include "system.h"
#include "text.h"

typedef struct LinkInitWork {
    BattleSetup *setup;
    BgConfig *bg;
    Window *window;
    PaletteData *palette;
    u8 pad10[0x1010];
    u8 state0;
    u8 state1;
    u16 field1022;
    WaitingIcon *waiting;
} LinkInitWork;
extern const GraphicsBanks ov12_0226C080;
extern const GraphicsModes ov12_0226BFF8;
extern const BgTemplate ov12_0226C044;
void sub_02074EC4(void *);
void ov12_022397E4(void *);
#endif
