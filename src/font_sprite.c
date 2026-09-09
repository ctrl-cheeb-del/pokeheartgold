#include "gf_gfx_loader.h"
#include "obj_char_transfer.h"
#include "unk_02013534.h"

typedef struct FontSpriteEntry {
    Sprite *sprite;
    int x, y;
} FontSpriteEntry;
void sub_02013728(TextOBJ *object);
void sub_020137F0(TextOBJ *object, u8 priority);
void sub_02013880(TextOBJ *object, int palette);
void sub_020138B0(TextOBJ *object, u8 palette);

struct UnkStruct_02013534 {
    void *cellFiles[12];
    NNSG2dCellDataBank *cellBanks[12];
    TextOBJ *objects;
    int capacity;
};
typedef struct FontGlyphNode {
    int x, y, index;
    struct FontGlyphNode *prev, *next;
} FontGlyphNode;
typedef NNSG2dImageProxy FontSpriteData;
TextOBJ *sub_02013AD0(UnkStruct_02013534 *system);
int sub_02013BD4(int width, int height, enum HeapID heapId, FontGlyphNode *list);
void sub_02013C5C(Window *window, FontGlyphNode *list, FontSpriteData *sprites, u32 offset, int vram, enum HeapID heapId);
void sub_02013E78(const TextOBJTemplate *template, FontGlyphNode *list, FontSpriteData *sprites, TextOBJ *object);
void sub_02013FA8(FontGlyphNode *list);
void sub_02013ECC(TextOBJ *object);
void sub_02013AC0(TextOBJ *object);
int sub_02013E24(FontGlyphNode *list, NNS_G2D_VRAM_TYPE vram);

struct UnkStruct_02013910 {
    FontGlyphNode list;
    int count;
};
void sub_02013D88(Window *window, void *buffer, FontGlyphNode *list, NNS_G2D_VRAM_TYPE vram, enum HeapID heapId);

extern const u8 _020F5F2C[12][2];
int sub_02013AF8(int width, int height);

typedef struct FontRect {
    int y, x, width, height;
} FontRect;
typedef struct FontSplit {
    FontRect current, remainder;
    u8 hasRemainder;
} FontSplit;
FontGlyphNode *sub_02013F78(enum HeapID heapId);
void sub_02013FC0(FontGlyphNode *node, FontGlyphNode *previous);
BOOL sub_02013B24(FontSplit *split, FontGlyphNode *list, enum HeapID heapId);

u32 sub_02013CD0(Window *window, FontGlyphNode *node, FontSpriteData *proxy, int blockSize, GXOBJVRamModeChar mode, volatile u32 offset, int vram, enum HeapID heapId);
u32 sub_02013DE0(Window *window, FontGlyphNode *node, void *buffer, u32 offset, int blockSize, GXOBJVRamModeChar mode, enum HeapID heapId);

UnkStruct_02013534 *FontSystem_NewInit(int count, enum HeapID heapId) {
    UnkStruct_02013534 *system = Heap_Alloc(heapId, sizeof(UnkStruct_02013534));
    GF_ASSERT(system != NULL);
    for (int i = 0; i < 12; i++) {
        system->cellFiles[i] = GfGfxLoader_GetCellBank((NarcId)35, i, FALSE, &system->cellBanks[i], heapId);
        GF_ASSERT(system->cellFiles[i] != NULL);
    }
    system->objects = Heap_Alloc(heapId, sizeof(TextOBJ) * count);
    GF_ASSERT(system->objects != NULL);
    system->capacity = count;
    memset(system->objects, 0, sizeof(TextOBJ) * count);
    return system;
}
void sub_020135AC(UnkStruct_02013534 *system) {
    GF_ASSERT(system != NULL);
    for (int i = 0; i < 12; i++) {
        Heap_Free(system->cellFiles[i]);
    }
    Heap_Free(system->objects);
    Heap_Free(system);
}
TextOBJ *sub_020135D8(TextOBJTemplate *template) {
    TextOBJ *object;
    FontGlyphNode list;
    int count;
    FontSpriteData *sprites;
    GF_ASSERT(template != NULL);
    object = sub_02013AD0(template->fontSystem);
    GF_ASSERT(object != NULL);
    object->unk_08 = template->sprite;
    object->unk_0C = template->x;
    object->unk_10 = template->y;
    list.prev = &list;
    list.next = &list;
    count = sub_02013BD4(template->window->width, template->window->height, template->heapID, &list);
    sprites = Heap_AllocAtEnd(template->heapID, sizeof(FontSpriteData) * count);
    object->unk_00 = Heap_Alloc(template->heapID, 12 * count);
    object->unk_04 = count;
    sub_02013C5C(template->window, &list, sprites, template->offset, template->vram, template->heapID);
    sub_02013E78(template, &list, sprites, object);
    Heap_Free(sprites);
    sub_02013FA8(&list);
    return object;
}
void FontOAM_Delete(TextOBJ *object) {
    GF_ASSERT(object != NULL);
    GF_ASSERT(object->unk_00 != NULL);
    sub_02013ECC(object);
    Heap_Free(object->unk_00);
    sub_02013AC0(object);
}
int sub_02013688(Window *window, NNS_G2D_VRAM_TYPE vram, int heapId) {
    FontGlyphNode list;
    int size;
    list.prev = &list;
    list.next = &list;
    sub_02013BD4(window->width, window->height, (enum HeapID)heapId, &list);
    size = sub_02013E24(&list, vram);
    sub_02013FA8(&list);
    return size;
}

void sub_020136B4(TextOBJ *object, int x, int y) {
    VecFx32 position;
    GF_ASSERT(object != NULL);
    object->unk_0C = x;
    object->unk_10 = y;
    x = x << FX32_SHIFT;
    y = y << FX32_SHIFT;
    if (object->unk_08 != NULL) {
        const VecFx32 *parent = Sprite_GetMatrixPtr((Sprite *)object->unk_08);
        x += parent->x;
        y += parent->y;
    }
    position.z = 0;
    for (int i = 0; i < object->unk_04; i++) {
        position.x = x + (((FontSpriteEntry *)object->unk_00)[i].x << FX32_SHIFT);
        position.y = y + (((FontSpriteEntry *)object->unk_00)[i].y << FX32_SHIFT);
        Sprite_SetMatrix(((FontSpriteEntry *)object->unk_00)[i].sprite, &position);
    }
}
void sub_02013728(TextOBJ *object) {
    fx32 baseX;
    fx32 baseY;
    VecFx32 position;
    GF_ASSERT(object != NULL);
    if (object->unk_08 != NULL) {
        baseX = object->unk_0C << FX32_SHIFT;
        baseY = object->unk_10 << FX32_SHIFT;
        const VecFx32 *parent = Sprite_GetMatrixPtr((Sprite *)object->unk_08);
        baseX += parent->x;
        baseY += parent->y;
        position.z = 0;
        for (int i = 0; i < object->unk_04; i++) {
            position.x = baseX + (((FontSpriteEntry *)object->unk_00)[i].x << FX32_SHIFT);
            position.y = baseY + (((FontSpriteEntry *)object->unk_00)[i].y << FX32_SHIFT);
            Sprite_SetMatrix(((FontSpriteEntry *)object->unk_00)[i].sprite, &position);
        }
    }
}
void sub_02013794(void *data, int *x, int *y) {
    TextOBJ *object = data;
    GF_ASSERT(object != NULL);
    GF_ASSERT(x != NULL);
    GF_ASSERT(y != NULL);
    *x = object->unk_0C;
    *y = object->unk_10;
}

void TextOBJ_SetSpritesDrawFlag(TextOBJ *object, BOOL value) {
    GF_ASSERT(object != NULL);
    for (int i = 0; i < object->unk_04; i++) {
        Sprite_SetDrawFlag(((FontSpriteEntry *)object->unk_00)[i].sprite, value);
    }
}

void sub_020137F0(TextOBJ *object, u8 value) {
    GF_ASSERT(object != NULL);
    for (int i = 0; i < object->unk_04; i++) {
        Sprite_SetPriority(((FontSpriteEntry *)object->unk_00)[i].sprite, value);
    }
}

void sub_02013820(TextOBJ *object, int value) {
    GF_ASSERT(object != NULL);
    for (int i = 0; i < object->unk_04; i++) {
        Sprite_SetDrawPriority(((FontSpriteEntry *)object->unk_00)[i].sprite, value);
    }
}

void TextOBJ_SetPaletteNum(TextOBJ *object, int value) {
    GF_ASSERT(object != NULL);
    for (int i = 0; i < object->unk_04; i++) {
        Sprite_SetPaletteOverride(((FontSpriteEntry *)object->unk_00)[i].sprite, value);
    }
}

void sub_02013880(TextOBJ *object, int value) {
    GF_ASSERT(object != NULL);
    for (int i = 0; i < object->unk_04; i++) {
        Sprite_SetPalIndexRespectVramOffset(((FontSpriteEntry *)object->unk_00)[i].sprite, value);
    }
}

void sub_020138B0(TextOBJ *object, u8 value) {
    GF_ASSERT(object != NULL);
    for (int i = 0; i < object->unk_04; i++) {
        Sprite_SetPalOffset(((FontSpriteEntry *)object->unk_00)[i].sprite, value);
    }
}

void sub_020138E0(TextOBJ *object, int value) {
    GF_ASSERT(object != NULL);
    for (int i = 0; i < object->unk_04; i++) {
        Sprite_SetPalOffsetRespectVramOffset(((FontSpriteEntry *)object->unk_00)[i].sprite, value);
    }
}
UnkStruct_02013910 *sub_02013910(Window *window, enum HeapID heapId) {
    UnkStruct_02013910 *layout = Heap_Alloc(heapId, sizeof(UnkStruct_02013910));
    layout->list.prev = &layout->list;
    layout->list.next = &layout->list;
    layout->count = sub_02013BD4(window->width, window->height, heapId, &layout->list);
    return layout;
}
void sub_02013938(UnkStruct_02013910 *layout) {
    sub_02013FA8(&layout->list);
    Heap_Free(layout);
}
u32 sub_02013948(UnkStruct_02013910 *layout, NNS_G2D_VRAM_TYPE vram) {
    return sub_02013E24(&layout->list, vram);
}
TextOBJ *TextOBJ_Create(const TextOBJTemplate *template, UnkStruct_02013910 *layout) {
    TextOBJ *object;
    FontSpriteData *sprites;
    GF_ASSERT(template != NULL);
    object = sub_02013AD0(template->fontSystem);
    GF_ASSERT(object != NULL);
    object->unk_08 = template->sprite;
    object->unk_0C = template->x;
    object->unk_10 = template->y;
    sprites = Heap_AllocAtEnd(template->heapID, sizeof(FontSpriteData) * layout->count);
    object->unk_00 = Heap_Alloc(template->heapID, sizeof(FontSpriteEntry) * layout->count);
    object->unk_04 = layout->count;
    sub_02013C5C(template->window, &layout->list, sprites, template->offset, template->vram, template->heapID);
    sub_02013E78(template, &layout->list, sprites, object);
    Heap_Free(sprites);
    return object;
}
void TextOBJ_Destroy(TextOBJ *object) {
    FontOAM_Delete(object);
}
void TextOBJ_CopyFromBGWindow(TextOBJ *object, UnkStruct_02013910 *layout, Window *window, enum HeapID heapId) {
    Sprite *sprite = ((FontSpriteEntry *)object->unk_00)[0].sprite;
    NNS_G2D_VRAM_TYPE vram = Sprite_GetVramType(sprite);
    u32 size = sub_02013948(layout, vram);
    void *buffer = Heap_AllocAtEnd(heapId, size);
    memset(buffer, 0, size);
    sub_02013D88(window, buffer, &layout->list, vram, heapId);
    DC_FlushRange(buffer, size);
    NNSG2dImageProxy *proxy = Sprite_GetImageProxy(sprite);
    if (vram == NNS_G2D_VRAM_TYPE_2DMAIN) {
        GX_LoadOBJ(buffer, NNS_G2dGetImageLocation(proxy, NNS_G2D_VRAM_TYPE_2DMAIN), size);
    } else {
        GXS_LoadOBJ(buffer, NNS_G2dGetImageLocation(proxy, NNS_G2D_VRAM_TYPE_2DSUB), size);
    }
    Heap_Free(buffer);
}

void sub_02013A50(Window *window, int width, int height, int x, int y, void *charBuf) {
    // Retain the original per-row width read and address calculation order.
    int sourceOffset;
    GF_ASSERT(window->width >= width + x);
    GF_ASSERT(window->height >= height + y);
    for (int i = 0; i < height; i++) {
        sourceOffset = ((volatile Window *)window)->width * (i + y);
        sourceOffset += x;
        memcpy((u8 *)charBuf + i * width * 32, (u8 *)window->pixelBuffer + sourceOffset * 32, width * 32);
    }
}
void sub_02013AC0(TextOBJ *object) {
    memset(object, 0, sizeof(TextOBJ));
}
TextOBJ *sub_02013AD0(UnkStruct_02013534 *input) {
    // Keep the original pool metadata reads at each iteration and on return.
    volatile UnkStruct_02013534 *system = input;
    int i = 0;
    if (i < system->capacity) {
        TextOBJ *object = system->objects;
        do {
            if (object->unk_00 == NULL) {
                return system->objects + i;
            }
            i++;
            object++;
        } while (i < system->capacity);
    }
    return NULL;
}
int sub_02013AF8(int width, int height) {
    for (int i = 0; i < 12; i++) {
        if (_020F5F2C[i][0] <= width && _020F5F2C[i][1] <= height) {
            return i;
        }
    }
    return 12;
}

BOOL sub_02013B24(FontSplit *split, FontGlyphNode *list, enum HeapID heapId) {
    int remainingWidth;
    FontGlyphNode *node = sub_02013F78(heapId);
    int remainingHeight;
    sub_02013FC0(node, list->next);
    node->index = sub_02013AF8(split->current.width, split->current.height);
    node->x = split->current.x;
    node->y = split->current.y;
    remainingWidth = split->current.width;
    remainingWidth -= _020F5F2C[node->index][0];
    remainingHeight = split->current.height;
    remainingHeight -= _020F5F2C[node->index][1];
    if (remainingWidth > 0) {
        split->remainder.height = split->current.height;
        split->remainder.width = remainingWidth;
        split->remainder.y = split->current.y;
        split->remainder.x = split->current.x + _020F5F2C[node->index][0];
        GF_ASSERT(split->hasRemainder != 1);
        split->hasRemainder = 1;
    }
    if (remainingHeight > 0) {
        split->current.y += _020F5F2C[node->index][1];
        split->current.height = remainingHeight;
    } else if (split->hasRemainder == 1) {
        split->current = split->remainder;
        split->hasRemainder = 0;
    } else {
        return TRUE;
    }
    return FALSE;
}
int sub_02013BD4(int width, int height, enum HeapID heapId, FontGlyphNode *list) {
    FontRect next;
    FontSplit split;
    int count;
    GF_ASSERT(width != 0);
    GF_ASSERT(height != 0);
    count = 0;
    split.current.height = height;
    split.current.y = 0;
    split.current.x = 0;
    split.current.width = width;
    split.hasRemainder = 0;
    next.x = 0;
    next.width = width;
    while (height != 0) {
        int index = sub_02013AF8(split.current.width, height);
        int rowHeight = _020F5F2C[index][1];
        next.y = split.current.y + rowHeight;
        next.height = split.current.height - rowHeight;
        split.current.height = rowHeight;
        do {
            count++;
        } while (!sub_02013B24(&split, list, heapId));
        split.current = next;
        height = split.current.height;
    }
    return count;
}

void sub_02013C5C(Window *window, FontGlyphNode *list, FontSpriteData *sprites, u32 offset, int vram, enum HeapID heapId) {
    GXOBJVRamModeChar mode = vram == NNS_G2D_VRAM_TYPE_2DMAIN ? GX_GetOBJVRamModeChar() : GXS_GetOBJVRamModeChar();
    int blockSize = ObjCharTransfer_GetBlockSizeFromMode(mode);
    for (FontGlyphNode *node = list->prev; node != list; node = node->prev) {
        NNS_G2dInitImageProxy(sprites);
        offset = sub_02013CD0(window, node, sprites, blockSize, mode, offset, vram, heapId);
        sprites++;
    }
}
// Volatile preserves the original stack reloads of the VRAM offset.
u32 sub_02013CD0(Window *window, FontGlyphNode *node, FontSpriteData *proxy, int blockSize, GXOBJVRamModeChar mode, volatile u32 offset, int vram, enum HeapID heapId) {
    int width = _020F5F2C[node->index][0];
    int height = _020F5F2C[node->index][1];
    u32 size = width;
    void *buffer;
    size *= height;
    if ((int)size < blockSize) {
        size = blockSize;
    }
    size *= 32;
    buffer = Heap_AllocAtEnd(heapId, size);
    sub_02013A50(window, width, height, node->x, node->y, buffer);
    DC_FlushRange(buffer, size);
    if (vram == NNS_G2D_VRAM_TYPE_2DMAIN) {
        u32 location = offset;
        GX_LoadOBJ(buffer, location, size);
        proxy->vramLocation.baseAddrOfVram[1] = location;
        proxy->attr.mappingType = GX_GetOBJVRamModeChar();
    } else {
        u32 location = offset;
        GXS_LoadOBJ(buffer, location, size);
        proxy->vramLocation.baseAddrOfVram[2] = location;
        proxy->attr.mappingType = GXS_GetOBJVRamModeChar();
    }
    proxy->attr.sizeS = (GXTexSizeS)65535;
    proxy->attr.sizeT = (GXTexSizeT)65535;
    proxy->attr.fmt = (GXTexFmt)3;
    proxy->attr.bExtendedPlt = FALSE;
    proxy->attr.plttUse = (GXTexPlttColor0)1;
    proxy->attr.mappingType = mode;
    Heap_Free(buffer);
    return offset + size;
}
void sub_02013D88(Window *window, void *buffer, FontGlyphNode *list, NNS_G2D_VRAM_TYPE vram, enum HeapID heapId) {
    GXOBJVRamModeChar mode = vram == NNS_G2D_VRAM_TYPE_2DMAIN ? GX_GetOBJVRamModeChar() : GXS_GetOBJVRamModeChar();
    int blockSize = ObjCharTransfer_GetBlockSizeFromMode(mode);
    u32 offset = 0;
    for (FontGlyphNode *node = list->prev; node != list; node = node->prev) {
        offset = sub_02013DE0(window, node, buffer, offset, blockSize, mode, heapId);
    }
}
u32 sub_02013DE0(Window *window, FontGlyphNode *node, void *buffer, u32 offset, int blockSize, GXOBJVRamModeChar mode, enum HeapID heapId) {
    int width = _020F5F2C[node->index][0];
    int height = _020F5F2C[node->index][1];
    u32 size = width * height;
    if ((int)size < blockSize) {
        size = blockSize;
    }
    sub_02013A50(window, width, height, node->x, node->y, (u8 *)buffer + offset);
    return offset + size * 32;
}
int sub_02013E24(FontGlyphNode *list, NNS_G2D_VRAM_TYPE vram) {
    GXOBJVRamModeChar mode = vram == NNS_G2D_VRAM_TYPE_2DMAIN ? GX_GetOBJVRamModeChar() : GXS_GetOBJVRamModeChar();
    int blockSize = ObjCharTransfer_GetBlockSizeFromMode(mode);
    FontGlyphNode *node = list->prev;
    u32 size = 0;
    for (; node != list; node = node->prev) {
        int tiles = _020F5F2C[node->index][0] * _020F5F2C[node->index][1];
        if (tiles < blockSize) {
            tiles = blockSize;
        }
        size += tiles * 32;
    }
    return size;
}
