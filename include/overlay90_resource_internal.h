#ifndef LOCAL_OV90_R10_H
#define LOCAL_OV90_R10_H
#include "global.h"

#include "bg_window.h"
#include "sprite.h"
#include "sprite_transfer.h"
#include "system.h"
typedef struct Ov90ResRec {
    u32 active;
    SpriteResource *obj[4];
    u8 header[0x24];
} Ov90ResRec;
typedef struct Ov90ResWork {
    GF_2DGfxResMan *man[4];
    Ov90ResRec *records;
    u32 count;
} Ov90ResWork;
void ov90_02258DD0(Ov90ResWork *, int, enum HeapID);
void ov90_02258E10(Ov90ResWork *);
typedef struct Ov90BgTemplate {
    u32 bgId;
    BgTemplate template;
} Ov90BgTemplate;
typedef struct Ov90BgWork {
    BgConfig *bg;
    Ov90BgTemplate *templates;
    u32 count;
} Ov90BgWork;
void ov90_02258EE0(Ov90ResWork *, Ov90ResRec *, int, int, int, int, int, int, int, int);
Ov90ResRec *ov90_02258E54(Ov90ResWork *, int, int, int, int, int, int, int, int);
Sprite *ov90_02258EB4(void *, SpriteList *, int, int, u16, enum HeapID);
void ov90_02258FF0(Ov90BgWork *, const GraphicsModes *, Ov90BgTemplate *, u32, enum HeapID);
void ov90_02259084(Ov90BgWork *);
void ov90_02258FB8(Ov90ResWork *, Ov90ResRec *);
#endif
