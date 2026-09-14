#ifndef TO45_OV96_R58_GAP2_PRIVATE_H
#define TO45_OV96_R58_GAP2_PRIVATE_H

#include "global.h"

#include "bg_window.h"
#include "gf_gfx_planes.h"
#include "sprite.h"

typedef struct Ov96R58Resource {
    u8 pad00[8];
    u32 size;
    u8 data[];
} Ov96R58Resource;

typedef struct Ov96R58Work {
    u32 state;
    u8 pad04[0x10];
    void (*callback)(void);
    u8 pad18[4];
    u32 phase;
    u8 pad20[0x78];
    Ov96R58Resource *resource98;
    Ov96R58Resource *resource9C;
    Ov96R58Resource *resourceA0;
    Ov96R58Resource *resourceA4;
    Ov96R58Resource *resourceA8;
    Ov96R58Resource *resourceAC;
    u8 padB0[0x0C];
    void *spritesBC[2];
    void *spriteC4;
    void *spritesC8[4];
} Ov96R58Work;

void ov96_021EB52C(void *, int, int);
void ov96_021F4A9C(void);
void ov96_021F4AE0(void);
void ov96_021F4B34(void);
void ov96_021F4CAC(Ov96R58Work *);
void ov96_021F4E5C(Ov96R58Work *, int);
void ov96_021F4EF8(Ov96R58Work *, BgConfig *);
void ov96_021F480C(Ov96R58Work *, BgConfig *);
void ov96_021F48A8(Ov96R58Work *, BgConfig *, int);
void ov96_021F48FC(Ov96R58Work *, BgConfig *);

#endif
