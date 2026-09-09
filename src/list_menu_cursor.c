#include "list_menu_cursor.h"

#include "global.h"

#include "bg_window.h"
#include "heap.h"
#include "pm_string.h"
#include "text.h"

typedef struct ListMenuCursor {
    u32 color;
    String *string;
} ListMenuCursor;
extern const u16 _020F60DC[];

struct ListMenuCursor *ListMenuCursorNew(enum HeapID heapID) {
    ListMenuCursor *cursor = Heap_Alloc(heapID, sizeof(ListMenuCursor));
    if (cursor != NULL) {
        cursor->color = 0x1020F;
        cursor->string = String_New(4, heapID);
        CopyU16ArrayToString(cursor->string, _020F60DC);
    }
    return cursor;
}

void DestroyListMenuCursorObj(struct ListMenuCursor *cursor_) {
    ListMenuCursor *cursor = cursor_;
    GF_ASSERT(cursor != NULL);
    if (cursor != NULL) {
        if (cursor->string != NULL) {
            String_Delete(cursor->string);
        }
        Heap_Free(cursor);
    }
}

void ListMenuCursorSetColor(struct ListMenuCursor *cursor_, u32 color) {
    ListMenuCursor *cursor = cursor_;
    GF_ASSERT(cursor != NULL);
    if (cursor != NULL) {
        cursor->color = color;
    }
}

void ListMenuUpdateCursorObj(struct ListMenuCursor *cursor_, Window *window, u8 x, u8 y) {
    ListMenuCursor *cursor = cursor_;
    AddTextPrinterParameterizedWithColor(window, 0, cursor->string, x, y, 0xFF, cursor->color, NULL);
    CopyWindowPixelsToVram_TextMode(window);
}
