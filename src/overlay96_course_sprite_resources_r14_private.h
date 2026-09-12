#ifndef OVERLAY96_COURSE_SPRITE_RESOURCES_R14_PRIVATE_H
#define OVERLAY96_COURSE_SPRITE_RESOURCES_R14_PRIVATE_H

#include <nitro/fx/fx_mtx43.h>
#include <nitro/fx/fx_trig.h>
#include <nitro/fx/fx_vec.h>

#include "global.h"

#include "bg_window.h"
#include "heap.h"
#include "overlay96_pokeathlon_course_ui_private.h"
#include "pokemon.h"
#include "sprite.h"
#include "unk_02013FDC.h"

#define U8_AT(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U16_AT(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32_AT(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define S32_AT(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))

typedef struct R14Participant {
    u16 species;
    u16 form;
    u16 unk04;
    u8 shiny;
    u8 gender;
    u32 unk08;
    u32 personality;
} R14Participant;

typedef struct R14Pos {
    s16 x;
    s16 y;
} R14Pos;

typedef struct R14WorldPos {
    fx32 x;
    fx32 y;
} R14WorldPos;

extern const WindowTemplate ov96_0221CA28;
extern void LoadFontPal0(int, int, enum HeapID);
extern u16 LCRandom(void);
extern void MTX_MultVec43(const VecFx32 *, const MtxFx43 *, VecFx32 *);
extern void ov96_021EB588(void *, const VecFx32 *);
extern void ov96_021EB564(void *, int);
extern void ov96_021E634C(void *, int, int, void *, u32, u8, u32);

void ov96_02203CE4(void *);
void ov96_02203D74(void *, void *, int);
void ov96_02203DCC(void *, R14Participant *);
void ov96_02203F0C(void *);
void ov96_02203F50(Ov96R31Work *, void *);
void ov96_02204320(int, VecFx32 *);
void *ov96_02204364(enum HeapID, u8);

#endif
