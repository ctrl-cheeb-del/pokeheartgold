#ifndef OV89_R2_U1_PRIVATE_H
#define OV89_R2_U1_PRIVATE_H

#define PaletteData_FillPaletteInBuffer PaletteData_FillPaletteInBuffer_typed
#include "global.h"

#include "bg_window.h"
#include "filesystem.h"
#include "gf_gfx_loader.h"
#include "msgdata.h"
#include "options.h"
#include "palette.h"
#include "render_window.h"
#include "sprite_system.h"
#include "unk_02013534.h"
#undef PaletteData_FillPaletteInBuffer

void PaletteData_FillPaletteInBuffer(PaletteData *, int, int, int, int, int);

typedef struct Ov89WorkHead {
    void *args;
    SaveData *save;
    BgConfig *bg;
    PaletteData *palette;
    u8 pad10[0x0c];
    SpriteSystem *spriteSystem;
    SpriteManager *spriteManager;
    u8 pad24[0x0c];
    MsgData *msgData;
    u8 pad34[0x8f0];
    ManagedSprite *spritesA[6];
    ManagedSprite *spritesB[6];
    ManagedSprite *spritesC[6];
    ManagedSprite *spriteMain;
    ManagedSprite *spritesD[8];
} Ov89WorkHead;

extern const ManagedSpriteTemplate ov89_0225CAA0;
extern const s16 ov89_0225CA38[][2];
extern const ManagedSpriteTemplate ov89_0225CAD4;
extern const ManagedSpriteTemplate ov89_0225CB08;
extern const ManagedSpriteTemplate ov89_0225CB3C;
extern const ManagedSpriteTemplate ov89_0225CB70;

void ov89_0225A260(void *, void *, String *, int, u32, u32, u32, u32, u32, u32);
void ov89_0225A354(void *);
int sub_0200E640(int);
void ov89_02259264(Ov89WorkHead *, NARC *);
void ov89_02259408(Ov89WorkHead *, NARC *);
void ov89_02259588(Ov89WorkHead *);
void ov89_022596DC(void *);
void ov89_02259734(Ov89WorkHead *, NARC *);
void ov89_022597FC(Ov89WorkHead *);

#endif
