#include "graphics_object_internal.h"

GraphicsManager *sub_02015DDC(GraphicsManagerTemplate *template) {
    GraphicsManager *manager = Heap_Alloc(template->heapId, sizeof(GraphicsManager));
    if (manager == NULL) {
        GF_ASSERT(FALSE);
    }
    manager->objects = sub_0201605C(template->objectCount, template->heapId);
    manager->objectCount = template->objectCount;
    manager->images = sub_0201608C(template->imageCount, template->heapId);
    manager->imageCount = template->imageCount;
    manager->palettes = sub_020160BC(template->paletteCount, template->heapId);
    manager->paletteCount = template->paletteCount;
    return manager;
}

void sub_02015E20(GraphicsManager *manager) {
    GF_ASSERT(manager != NULL);
    GF_ASSERT(manager->objects != NULL);
    GF_ASSERT(manager->images != NULL);
    GF_ASSERT(manager->palettes != NULL);
    Heap_Free(manager->objects);
    Heap_Free(manager->images);
    Heap_Free(manager->palettes);
    Heap_Free(manager);
}

void sub_02015E64(GraphicsManager *manager) {
    int i;
    *(u32 *)0x04000444 = 0;
    for (i = 0; i < manager->objectCount; i++) {
        if (manager->objects[i].visible != 0) {
            sub_020161CC(&manager->objects[i]);
        }
    }
    *(u32 *)0x04000448 = 1;
}

ImageHandle *sub_02015EA0(GraphicsResourceTemplate *template) {
    ImageHandle *handle = sub_02016118(template->manager);
    if (handle == NULL) {
        GF_ASSERT(FALSE);
    }
    if (*(u32 *)((u8 *)template->character + 8) != 0) {
        GF_ASSERT(FALSE);
    }
    handle->key = sub_02016170(template->character);
    if (handle->key == 0) {
        GF_ASSERT(FALSE);
    }
    sub_02016198(template->character, handle->key, &handle->proxy);
    return handle;
}

void sub_02015EDC(ImageHandle *handle) {
    NNS_GfdFreeTexVram(handle->key);
    sub_02016044(handle);
}

void sub_02015EF4(GraphicsManager *manager) {
    int i;
    for (i = 0; i < manager->imageCount; i++) {
        if (manager->images[i].key != 0) {
            sub_02015EDC(&manager->images[i]);
        }
    }
}

PaletteHandle *sub_02015F1C(GraphicsResourceTemplate *template) {
    PaletteHandle *handle = sub_02016144(template->manager);
    if (handle == NULL) {
        GF_ASSERT(FALSE);
    }
    handle->key = sub_02016184((u32)template->palette);
    if (handle->key == 0) {
        GF_ASSERT(FALSE);
    }
    sub_020161A8((NNSG2dPaletteData *)template->character, handle->key, &handle->proxy);
    return handle;
}

void sub_02015F4C(PaletteHandle *handle) {
    NNS_GfdFreePlttVram(handle->key);
    sub_02016050(handle);
}

void sub_02015F64(GraphicsManager *manager) {
    int i;
    for (i = 0; i < manager->paletteCount; i++) {
        if (manager->palettes[i].key != 0) {
            sub_02015F4C(&manager->palettes[i]);
        }
    }
}

GraphicsObject *sub_02015F8C(GraphicsResourceTemplate *template) {
    GraphicsObject *object = sub_020160EC(template->manager);
    if (object == NULL) {
        GF_ASSERT(FALSE);
    }
    sub_0201630C(object, template);
    object->active = TRUE;
    object->visible = TRUE;
    return object;
}

void sub_02015FB0(GraphicsObject *object, BOOL visible) {
    GF_ASSERT(object != NULL);
    object->visible = visible;
}

void sub_02015FC4(GraphicsObject *object, u16 x, u16 y) {
    object->x = x;
    object->y = y;
}
u32 sub_02015FCC(GraphicsObject *object) {
    return ((u16)object->y << 16) | (u16)object->x;
}
void sub_02015FD8(GraphicsObject *object, u16 width, u16 height) {
    object->width = width;
    object->height = height;
}
void sub_02015FE0(GraphicsObject *object, u16 x, u16 y) {
    object->offsetX = x;
    object->offsetY = y;
}
u32 sub_02015FE8(GraphicsObject *object) {
    return ((u16)object->offsetY << 16) | (u16)object->offsetX;
}
void sub_02015FF4(GraphicsObject *object, u32 value) {
    object->depth = value;
}
u32 sub_02015FF8(GraphicsObject *object) {
    return object->depth;
}
void sub_02015FFC(GraphicsObject *object, u8 alpha) {
    object->alpha = alpha;
}
void sub_02016004(GraphicsObject *object, NNSG2dCharacterData *value) {
    object->character = value;
}
void sub_02016008(GraphicsObject *object, u32 value) {
    object->characterOffset = value;
}
void sub_0201600C(GraphicsObject *object, u32 value) {
    object->paletteOffset = value;
}
void sub_02016010(GraphicsObject *object, u32 value) {
    object->paletteIndex = value;
}
void sub_02016014(GraphicsObject *object, int which, BOOL value) {
    if (which == 0) {
        object->flipX = value;
    } else {
        object->flipY = value;
    }
}
void sub_02016020(GraphicsObject *object, u32 value) {
    object->rotation = value;
}

void sub_02016024(GraphicsObject *object) {
    memset(object, 0, sizeof(GraphicsObject));
    object->alpha = 0x1F;
    object->color = 0x7FFF;
}

void sub_02016044(ImageHandle *handle) {
    handle->key = 0;
    NNS_G2dInitImageProxy(&handle->proxy);
}
void sub_02016050(PaletteHandle *handle) {
    handle->key = 0;
    NNS_G2dInitImagePaletteProxy(&handle->proxy);
}

GraphicsObject *sub_0201605C(int count, enum HeapID heapId) {
    GraphicsObject *objects = Heap_Alloc(heapId, count * sizeof(GraphicsObject));
    int i;
    if (objects == NULL) {
        GF_ASSERT(FALSE);
    }
    for (i = 0; i < count; i++) {
        sub_02016024(&objects[i]);
    }
    return objects;
}

ImageHandle *sub_0201608C(int count, enum HeapID heapId) {
    ImageHandle *handles = Heap_Alloc(heapId, count * sizeof(ImageHandle));
    int i;
    if (handles == NULL) {
        GF_ASSERT(FALSE);
    }
    for (i = 0; i < count; i++) {
        sub_02016044(&handles[i]);
    }
    return handles;
}

PaletteHandle *sub_020160BC(int count, enum HeapID heapId) {
    PaletteHandle *handles = Heap_Alloc(heapId, count * sizeof(PaletteHandle));
    int i;
    if (handles == NULL) {
        GF_ASSERT(FALSE);
    }
    for (i = 0; i < count; i++) {
        sub_02016050(&handles[i]);
    }
    return handles;
}

GraphicsObject *sub_020160EC(GraphicsManager *manager) {
    int i;
    for (i = 0; i < manager->objectCount; i++) {
        if (manager->objects[i].active == 0) {
            return &manager->objects[i];
        }
    }
    return NULL;
}
