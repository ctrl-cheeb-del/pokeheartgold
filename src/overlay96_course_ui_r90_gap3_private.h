#ifndef TO45_OV96_R90_GAP3_PRIVATE_H
#define TO45_OV96_R90_GAP3_PRIVATE_H

#include "global.h"

#include "bg_window.h"
#include "sprite.h"

typedef struct Ov96R90Vec {
    fx32 x;
    fx32 y;
    fx32 z;
} Ov96R90Vec;

typedef struct Ov96R90ParticipantSprites {
    Sprite *sprite38;
    Sprite *sprite3C;
    Sprite *sprite40;
    u8 flag44;
    u8 pad0D[0x0f];
} Ov96R90ParticipantSprites;

typedef struct Ov96R90Work {
    u32 heapId;
    u8 pad004[4];
    BgConfig *bgConfig;
    u8 pad00C[0x1c];
    void *tileData;
    u8 pad02C[0x0c];
    Ov96R90ParticipantSprites participant[4];
    void *pad0A8[9];
    struct {
        u8 pad00[0x14];
        void *pixels;
    } *graphics[12];
    u8 palette[12];
    u8 pad108[0x28];
    Sprite *numberSprites[2];
    u8 pad138[4];
    Sprite *actionSprites[4][4];
    Sprite *choiceSprites[4][2];
    u32 state;
    u16 currentParticipant;
    u8 pad1A2[2];
    u8 selectedImage[4];
    u8 pad1A8[0x0c];
    Sprite *digitSprites[2];
    struct {
        u16 x;
        u16 y;
    } counters[3];
} Ov96R90Work;

void ov96_021EB52C(void *, int, int);
void ov96_021EB564(void *, int);
void ov96_021EB588(void *, const Ov96R90Vec *);
const Ov96R90Vec *ov96_021EB594(void *);
Sprite *ov96_021EB5B8(void *);
void ov96_021EB630(void *, int);
void ov96_022082BC(void *, u32, u32);
void ov96_022088AC(void *, u8);
void ov96_02208A80(void **, int);
void ov96_0220831C(Ov96R90Work *, int, int);
void ov96_02208374(Ov96R90Work *, int);
BOOL ov96_02208608(Ov96R90Work *, u32);
void ov96_02208658(Ov96R90Work *, int, u8, BOOL, int);
void ov96_02208740(Ov96R90Work *, int);
void ov96_02208784(Ov96R90Work *, int);

#endif
