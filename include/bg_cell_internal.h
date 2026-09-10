#ifndef POKEHEARTGOLD_BG_CELL_INTERNAL_H
#define POKEHEARTGOLD_BG_CELL_INTERNAL_H
#include "global.h"

#include "bg_window.h"
#include "filesystem.h"
#include "gf_gfx_loader.h"
#include "heap.h"

typedef struct BgCell {
    u16 *data;
    u16 width : 6;
    u16 height : 6;
    u16 active : 1;
    u16 state : 3;
    s8 x;
    s8 y;
    s8 dx;
    s8 dy;
    u8 bgId;
    u8 timer;
    s8 left;
    s8 top;
    s8 right;
    s8 bottom;
} BgCell;

struct UnkStruct_0201956C {
    BgConfig *bgConfig;
    BgCell *cells;
    u16 count;
    u16 value : 15;
    u16 flag : 1;
    enum HeapID heapId;
};

#include "unk_0201956C.h"

UnkStruct_0201956C *sub_0201956C(BgConfig *, int, int, enum HeapID);
void sub_020195C0(UnkStruct_0201956C *);
void sub_020195F4(UnkStruct_0201956C *, int, int, int, int);
void sub_02019668(UnkStruct_0201956C *, int, u16 *);
void sub_020196B8(UnkStruct_0201956C *, int, NARC *, int, int);
void sub_020196E8(UnkStruct_0201956C *, int, int, int);
void sub_0201980C(UnkStruct_0201956C *, int);
void sub_020198FC(UnkStruct_0201956C *, int, int, int, u8);
void sub_02019934(UnkStruct_0201956C *);
BOOL sub_020199E4(UnkStruct_0201956C *, int);
void sub_020199F4(UnkStruct_0201956C *, int, u8, u8, u8, u8, u8);
u16 *sub_02019B08(UnkStruct_0201956C *, int);
void sub_02019B44(UnkStruct_0201956C *, int, u16 *, u16 *);
void sub_02019B70(UnkStruct_0201956C *, int, s8, s8, s8, s8);

void sub_02019688(UnkStruct_0201956C *mgr, int index, int narcId, int fileId, int compressed);

BOOL sub_02019978(UnkStruct_0201956C *, int);
void sub_020197F4(UnkStruct_0201956C *, int);
u8 sub_02019B10(UnkStruct_0201956C *, int);
void sub_02019B1C(UnkStruct_0201956C *, int, s8 *, s8 *);
void sub_02019BA0(BgConfig *, u8);

#endif
