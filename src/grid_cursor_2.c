#include "grid_cursor_internal.h"
#include "heap.h"

extern void GF_AssertFail(void);

void sub_02095C90(GridCursor *cursor, u8 type) {
    int i;

    for (i = 0; i < cursor->count; i++) {
        if (cursor->entries[i].dimensions[3] == type) {
            cursor->current = i;
            return;
        }
    }
}

void sub_02095CB8(GridCursor *cursor, u8 type, int arg) {
    sub_02095C90(cursor, type);
    cursor->entries[cursor->current].select(cursor, &cursor->positions[cursor->current], cursor->entries[cursor->current].dimensions, arg);
}

GridCursor *sub_02095CE0(enum HeapID heapId, void *userData) {
    GridCursor *cursor = Heap_Alloc(heapId, sizeof(GridCursor));
    u32 i;

    {
        u8 *p = (u8 *)cursor;
        for (i = sizeof(GridCursor); i != 0; i--) {
            *p++ = 0;
        }
    }
    cursor->count = 6;
    cursor->positions = Heap_Alloc(heapId, cursor->count * sizeof(GridPosition));
    memset(cursor->positions, 0, cursor->count * sizeof(GridPosition));
    cursor->userData = userData;
    return cursor;
}

void sub_02095D1C(GridCursor *cursor, u8 value) {
    cursor->current = 0;
    cursor->entries = _02108434;
    cursor->unk_02 = value;
}

void sub_02095D2C(GridCursor *cursor) {
    Heap_Free(cursor->positions);
    Heap_Free(cursor);
}

void sub_02095D40(GridCursor *cursor, u8 type, u8 index) {
    GridPosition *position;
    const u8 *dimensions;

    sub_02095C90(cursor, type);
    position = &cursor->positions[cursor->current];
    dimensions = cursor->entries[cursor->current].dimensions;
    if (index >= dimensions[2]) {
        GF_AssertFail();
    }
    position->index = index;
    if (position->index >= dimensions[2]) {
        position->index = 0;
    }
    position->x = position->index % dimensions[0];
    position->y = position->index / dimensions[0];
}

BOOL sub_02095D88(GridCursor *cursor, int arg1, int arg2) {
    volatile int savedArg2 = arg2;
    u8 oldCurrent = ((volatile GridCursor *)cursor)->current;
    GridPosition *position = &cursor->positions[oldCurrent];
    const GridEntry *entry = &cursor->entries[oldCurrent];
    u8 oldIndex = position->index;

    entry->move(cursor, position, entry->dimensions, arg1, savedArg2);
    if (oldCurrent != cursor->current) {
        return TRUE;
    }
    if (oldIndex != position->index) {
        return TRUE;
    }
    return FALSE;
}

u8 sub_02095DD8(GridCursor *cursor) {
    return cursor->entries[cursor->current].dimensions[3];
}

u8 sub_02095DE8(GridCursor *cursor) {
    return cursor->positions[cursor->current].index;
}
