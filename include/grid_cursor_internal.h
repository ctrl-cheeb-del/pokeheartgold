#ifndef POKEHEARTGOLD_GRID_CURSOR_INTERNAL_H
#define POKEHEARTGOLD_GRID_CURSOR_INTERNAL_H

#include "global.h"

#include "heap.h"

typedef struct GridCursor GridCursor;

typedef struct GridPosition {
    s8 x;
    s8 y;
    u8 index;
    u8 padding;
} GridPosition;

typedef void (*GridMoveCallback)(GridCursor *, GridPosition *, const u8 *, int, int);
typedef void (*GridSelectCallback)(GridCursor *, GridPosition *, const u8 *, int);

typedef struct GridEntry {
    const u8 *dimensions;
    GridMoveCallback move;
    GridSelectCallback select;
} GridEntry;

struct GridCursor {
    u8 current;
    u8 count;
    u8 unk_02;
    u8 padding;
    void *userData;
    const GridEntry *entries;
    GridPosition *positions;
};

typedef struct GridMove {
    u32 type;
    u8 value;
} GridMove;

extern const GridEntry _02108434[6];

void sub_020957B0(GridCursor *cursor, GridPosition *position, const u8 *dimensions, s8 dx, s8 dy);
void sub_02095838(GridCursor *cursor, GridPosition *position, const u8 *dimensions, const GridMove *move);
void sub_020958C0(GridCursor *cursor, GridPosition *position, const u8 *dimensions, s8 dx, s8 dy);
void sub_02095920(void *unused, GridPosition *position);
void sub_0209592C(GridCursor *cursor, GridPosition *position, const u8 *dimensions, s8 dx, s8 dy);
void sub_020959D8(GridCursor *cursor, GridPosition *position, const u8 *dimensions, const GridMove *move);
void sub_02095A34(GridCursor *cursor, GridPosition *position, const u8 *dimensions, s8 dx, s8 dy);
void sub_02095A78(void);
void sub_02095A7C(GridCursor *cursor, GridPosition *position, const u8 *dimensions, s8 dx, s8 dy);
void sub_02095AF8(void *unused, GridPosition *position);
void sub_02095B04(GridCursor *cursor, GridPosition *position, const u8 *dimensions, s8 dx, s8 dy);
void sub_02095B88(GridCursor *cursor, GridPosition *position, const u8 *dimensions, const GridMove *move);
int sub_02095BF0(GridCursor *cursor, GridPosition *position, const u8 *dimensions, s8 dx, s8 dy);
void sub_02095C90(GridCursor *cursor, u8 type);
void sub_02095CB8(GridCursor *cursor, u8 type, int arg);
GridCursor *sub_02095CE0(enum HeapID heapId, void *userData);
void sub_02095D1C(GridCursor *cursor, u8 value);
void sub_02095D2C(GridCursor *cursor);
void sub_02095D40(GridCursor *cursor, u8 type, u8 index);
BOOL sub_02095D88(GridCursor *cursor, int arg1, int arg2);
u8 sub_02095DD8(GridCursor *cursor);
u8 sub_02095DE8(GridCursor *cursor);

#endif
