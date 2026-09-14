#include "global.h"

#include "touchscreen.h"

typedef struct GraphicsObject GraphicsObject;
typedef struct GraphicsManager GraphicsManager;
typedef struct GraphicsResourceTemplate {
    GraphicsManager *manager;
    NNSG2dCharacterData *character;
    NNSG2dPaletteData *palette;
    s16 x;
    s16 y;
    u16 paletteIndex;
    u16 padding_12;
    u32 depth;
    u32 rotation;
    u16 resourceId;
    u16 padding_1E;
} GraphicsResourceTemplate;

typedef struct RawPoint {
    u16 x;
    u16 y;
} RawPoint;

extern GraphicsObject *sub_02015F8C(GraphicsResourceTemplate *template);
extern RawPoint sub_02015FCC(GraphicsObject *object);
extern RawPoint sub_02015FE8(GraphicsObject *object);

typedef struct Ov41Slot {
    u32 unk0;
    void *value;
} Ov41Slot;

typedef struct Ov41SlotList {
    Ov41Slot *slots;
    int count;
} Ov41SlotList;

typedef struct Ov41ResourceArgs {
    u32 unk0;
    GraphicsManager *manager;
    NNSG2dCharacterData *character;
    NNSG2dPaletteData *palette;
    u32 x;
    u32 y;
    u32 unk18;
    u32 resourceId;
} Ov41ResourceArgs;

extern void ov41_02245FD8(void *object, u32 *width, u32 *height);

void ov41_02246020(void *object, int *width, int *height);
Ov41Slot *ov41_0224607C(Ov41SlotList *list);
GraphicsObject *ov41_022460A8(const Ov41ResourceArgs *args);
void ov41_022460DC(const void *work, TouchscreenHitbox *hitbox);

void ov41_02246020(void *object, int *width, int *height) {
    u32 objectWidth;
    u32 objectHeight;

    ov41_02245FD8(object, &objectWidth, &objectHeight);
    switch (objectWidth) {
    case 0x10:
        *width = 0;
        break;
    case 0x20:
        *width = 10;
        break;
    case 0x40:
        *width = 20;
        break;
    }
    switch (objectHeight) {
    case 0x10:
        *height = 0;
        break;
    case 0x20:
        *height = 10;
        break;
    case 0x40:
        *height = 20;
        break;
    }
}

Ov41Slot *ov41_0224607C(Ov41SlotList *list) {
    int i;

    for (i = 0; i < list->count; i++) {
        if (list->slots[i].value == NULL) {
            return &list->slots[i];
        }
    }
    return NULL;
}

GraphicsObject *ov41_022460A8(const Ov41ResourceArgs *args) {
    GraphicsResourceTemplate template;

    template.manager = args->manager;
    template.character = args->character;
    template.palette = args->palette;
    template.x = args->x;
    template.y = args->y;
    template.paletteIndex = 0;
    template.depth = 0x1F;
    template.rotation = 0;
    template.resourceId = args->resourceId;
    return sub_02015F8C(&template);
}
