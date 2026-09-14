#ifndef TO45_OV96_R90_GAP2_PRIVATE_H
#define TO45_OV96_R90_GAP2_PRIVATE_H

#include "global.h"

#include "bg_window.h"
#include "filesystem.h"
#include "gf_gfx_loader.h"
#include "heap.h"
#include "pokemon_icon_idx.h"
#include "sprite.h"

typedef struct Ov96R90ParticipantSprites {
    Sprite *sprite38;
    Sprite *sprite3C;
    Sprite *sprite40;
    u8 flag44;
    u8 pad0D[0x0F];
} Ov96R90ParticipantSprites;

typedef struct Ov96R90Graphic {
    u8 pad00[0x14];
    void *pixels;
} Ov96R90Graphic;

typedef struct Ov96R90Work {
    enum HeapID heapId;
    u8 pad004[4];
    BgConfig *bgConfig;
    u8 pad00C[0x18];
    void *tileData;
    NNSG2dScreenData *screenData;
    u8 pad02C[0x0C];
    Ov96R90ParticipantSprites participant[4];
    void *pad0A8[9];
    Ov96R90Graphic *graphics[12];
    u8 palette[12];
    u8 pad108[0x28];
    Sprite *numberSprites[2];
    Sprite *specialSprite;
    Sprite *actionSprites[4][4];
    Sprite *choiceSprites[4][2];
    u32 state;
    u16 currentParticipant;
    u8 pad1A2[2];
    u8 selectedImage[4];
    u8 pad1A8[0x0C];
    Sprite *digitSprites[2];
} Ov96R90Work;

typedef struct Ov96R90Mon {
    u16 species;
    u16 form;
} Ov96R90Mon;

void ov96_021EB2BC(void *, int, int, int, int);
void ov96_021EB2F4(void *, int, int, int, int, int);
void ov96_021EB334(void *, int, int, int);
void ov96_021EB36C(void *, int, int, int);
void *ov96_021EB3E4(void *, int, int, int, int);
void ov96_021EB52C(void *, int, int);
void ov96_021EB564(void *, int);
void ov96_021EB588(void *, const VecFx32 *);
void *ov96_021EB5E8(void *);
Sprite *ov96_021EA2C4(void *, void *, int, enum HeapID);
void ov96_0220831C(Ov96R90Work *, int, int);
void ov96_02208374(Ov96R90Work *, int);
void ov96_02208914(void *, Ov96R90Work *);

u32 sub_02074490(void);

extern const u8 ov96_0221CBC4[];
extern const u8 ov96_0221CBC8[];
extern const u32 ov96_0221CBCC[];
extern const VecFx32 ov96_0221CBF4;

void ov96_02207DDC(Ov96R90Work *);
void ov96_02207E7C(void *, void *);
void ov96_02207F18(Ov96R90Work *, void *, void *);
void ov96_022080F4(Ov96R90Work *, const Ov96R90Mon *);

#endif
