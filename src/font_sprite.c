#include "gf_gfx_loader.h"
#include "unk_02013534.h"

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
typedef struct FontSpriteData {
    u8 data[36];
} FontSpriteData;
TextOBJ *sub_02013AD0(UnkStruct_02013534 *system);
int sub_02013BD4(int width, int height, enum HeapID heapId, FontGlyphNode *list);
void sub_02013C5C(Window *window, FontGlyphNode *list, FontSpriteData *sprites, u32 offset, int vram, enum HeapID heapId);
void sub_02013E78(TextOBJTemplate *template, FontGlyphNode *list, FontSpriteData *sprites, TextOBJ *object);
void sub_02013FA8(FontGlyphNode *list);
void sub_02013ECC(TextOBJ *object);
void sub_02013AC0(TextOBJ *object);
int sub_02013E24(FontGlyphNode *list, NNS_G2D_VRAM_TYPE vram);

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
