#ifndef OV96_POKEATHLON_COURSE_UI_PRIVATE_H
#define OV96_POKEATHLON_COURSE_UI_PRIVATE_H

#include <nitro/fx/fx_vec.h>
#include <nitro/mi/memory.h>

#include "global.h"

#include "pokeathlon/pokeathlon.h"

#include "bg_window.h"
#include "filesystem.h"
#include "gf_gfx_loader.h"
#include "heap.h"
#include "overlay96_sprite_helpers_private.h"
#include "player_data.h"
#include "sprite.h"
#include "string_util.h"

typedef struct Ov96CourseUiSub {
    void *unk00;
    void *unk04;
} Ov96CourseUiSub;

typedef struct Ov96CourseUiGfx {
    enum HeapID heapId;      // 0x00
    void *unk04;             // 0x04
    BgConfig *bgConfig;      // 0x08
    Window window;           // 0x0C
    void *scrnRaw;           // 0x1C
    NNSG2dScreenData *scrn;  // 0x20
    Ov96CourseUiSub subs[3]; // 0x24
    u8 pad3C[0x74 - 0x3C];
} Ov96CourseUiGfx;

void ov96_02203E30(Ov96R31Work *sprites, void *a, void *b);
void ov96_02203FBC(Ov96CourseUiGfx *gfx);
void ov96_02203FFC(Ov96CourseUiGfx *gfx);

Ov96CourseUiGfx *ov96_02203A00(enum HeapID heapId, BgConfig *bgConfig, void *unk04);
void ov96_02203A30(Ov96CourseUiGfx *gfx);
void ov96_02203A64(Ov96CourseUiGfx *gfx, u32 index);
void ov96_02203B44(Ov96CourseUiGfx *gfx, Ov96R31Work *sprites);
void ov96_02203B8C(void *a, Ov96R31Work *sprites, void *b);

typedef struct Ov96SortEntry {
    u16 group;
    u16 index;
    s32 score;
} Ov96SortEntry;

typedef struct Ov96AnimRec {
    u8 pad00[4];
    s32 unk04;
} Ov96AnimRec;

typedef struct Ov96CourseSlot {
    void *unk00;
    void *unk04;
    void *unk08;
    s32 unk0C;
    VecFx32 pos;
    u8 pad1C[0x41 - 0x1C];
    u8 unk41;
    u8 pad42[2];
    u16 unk44;
    u16 unk46;
} Ov96CourseSlot;

typedef struct Ov96CourseUiWork {
    u8 pad000[0x14];
    Window windows[3];
    enum HeapID heapId;
    u8 pad048[0x50 - 0x48];
    Sprite *unk050;
    Sprite *unk054;
    u8 pad058[0xB8 - 0x58];
    Ov96CourseSlot slots[12];
    u8 pad418[0x598 - 0x418];
    void *unk598;
} Ov96CourseUiWork;

typedef s32 (*Ov96CompareFunc)(const void *, const void *);
void MATH_QSort(void *ptr, u32 nmemb, u32 size, Ov96CompareFunc func, void *work);
void Sprite_SetAnimCtrlSeq(Sprite *sprite, int seq);
void AddTextPrinterParameterizedWithColor(Window *, int, String *, int, int, int, u32, void *);
void String_Delete(String *str);
void ov96_021E8318(void *course, u16 v);
void ov96_0220337C(void *p, u16 v);
Ov96AnimRec *ov96_021EB594(void *p);
void ov96_021EB630(void *p, int v);
extern const u8 ov96_0221C95C[][12];

void ov96_02203754(Ov96CourseUiWork *w);
void ov96_0220382C(Ov96CourseUiWork *w, PokeathlonCourseData *data);
void ov96_022038A0(Ov96CourseUiWork *w, u32 v);
void ov96_022038D4(PokeathlonCourseData *course);
s32 ov96_02203924(const void *aa, const void *bb);
void ov96_02203970(Ov96CourseUiWork *w, u16 group);

#endif
