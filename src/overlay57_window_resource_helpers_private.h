#ifndef OV57_R7_PRIVATE_H
#define OV57_R7_PRIVATE_H
#include "global.h"

#include "bg_window.h"
#include "gf_gfx_loader.h"
#include "msgdata.h"
#include "palette.h"
#include "render_window.h"
#include "seal_case.h"
#include "sprite_system.h"
#include "text.h"
typedef struct Ov57R7Work {
    u8 pad00[0x64];
    SEALBAG *seals;
    u8 pad68[0x7C];
    BgConfig *bgConfig;
    u8 padE8[4];
    Window windows[32];
    u8 pad2EC[0x164];
    u8 sealIds[8];
} Ov57R7Work;
typedef struct Ov57R7LoopWork {
    u8 pad00[0x64];
    SEALBAG *seals;
    u8 pad68[0x3E3];
    u8 sealIds[13];
} Ov57R7LoopWork;
typedef struct Ov57R7SpriteSlot {
    u32 unk0;
    ManagedSprite *sprite;
    u32 unk8;
} Ov57R7SpriteSlot;
typedef struct Ov57R7SpriteWork {
    u8 pad[0x290];
    Ov57R7SpriteSlot slots[12];
} Ov57R7SpriteWork;
extern const u32 ov57_0223BDF4[];
u32 sub_0200E640(u32);
void ov57_02239558(Ov57R7SpriteWork *);
void ov57_02239588(Ov57R7SpriteWork *);
void ov57_022395B8(BgConfig *, PaletteData *);
void ov57_02239670(BgConfig *, PaletteData *, int);
void ov57_02239728(Window *, int, u32, BOOL);
void ov57_022397B0(BgConfig *, Window *, int, int, int, int, int, int);
void ov57_02239814(BgConfig *, Window *, int, int, int, int, int, int);
void ov57_02239868(BgConfig *, Window *, int, int, int, int, int, int, int);
void ov57_022398C4(Ov57R7Work *work);
void ov57_022399F8(Ov57R7LoopWork *work);
void ov57_02239A8C(Ov57R7Work *work, int index);
void ov57_02239B0C(void *work);
void ov57_02239B2C(Window *window, u32 message);
#endif
