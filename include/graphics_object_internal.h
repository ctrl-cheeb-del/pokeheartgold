#ifndef POKEHEARTGOLD_GRAPHICS_OBJECT_INTERNAL_H
#define POKEHEARTGOLD_GRAPHICS_OBJECT_INTERNAL_H
#include "global.h"

#include "heap.h"

typedef struct GraphicsObject {
    s16 x;
    s16 y;
    s16 width;
    s16 height;
    s16 offsetX;
    s16 offsetY;
    fx32 scaleX;
    fx32 scaleY;
    u32 depth;
    u32 rotation;
    u32 active;
    u32 visible;
    NNSG2dCharacterData *volatile character;
    u32 characterOffset;
    u32 paletteOffset;
    u32 paletteIndex;
    BOOL flipX;
    BOOL flipY;
    u16 color;
    u8 alpha;
    u8 padding_3F;
} GraphicsObject;

typedef struct ImageHandle ImageHandle;
typedef struct PaletteHandle PaletteHandle;

typedef struct GraphicsManager {
    GraphicsObject *objects;
    int objectCount;
    ImageHandle *images;
    int imageCount;
    PaletteHandle *palettes;
    int paletteCount;
} GraphicsManager;

typedef struct GraphicsManagerTemplate {
    int objectCount;
    int imageCount;
    int paletteCount;
    enum HeapID heapId;
} GraphicsManagerTemplate;

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

struct ImageHandle {
    NNSGfdTexKey key;
    NNSG2dImageProxy proxy;
};

struct PaletteHandle {
    NNSGfdPlttKey key;
    NNSG2dImagePaletteProxy proxy;
};

GraphicsObject *sub_0201605C(int, enum HeapID);
ImageHandle *sub_0201608C(int, enum HeapID);
PaletteHandle *sub_020160BC(int, enum HeapID);
void sub_02016024(GraphicsObject *);
void sub_02016044(ImageHandle *);
void sub_02016050(PaletteHandle *);
GraphicsObject *sub_020160EC(GraphicsManager *);
ImageHandle *sub_02016118(GraphicsManager *);
PaletteHandle *sub_02016144(GraphicsManager *);
NNSGfdTexKey sub_02016170(NNSG2dCharacterData *);
NNSGfdPlttKey sub_02016184(u32);
void sub_02016198(NNSG2dCharacterData *, NNSGfdTexKey, NNSG2dImageProxy *);
void sub_020161A8(NNSG2dPaletteData *, NNSGfdPlttKey, NNSG2dImagePaletteProxy *);
void sub_020161CC(GraphicsObject *);
void sub_0201630C(GraphicsObject *, GraphicsResourceTemplate *);
void sub_02015EDC(ImageHandle *);
void sub_02015F4C(PaletteHandle *);
GraphicsManager *sub_02015DDC(GraphicsManagerTemplate *);
void sub_02015E20(GraphicsManager *);
void sub_02015E64(GraphicsManager *);
ImageHandle *sub_02015EA0(GraphicsResourceTemplate *);
void sub_02015EF4(GraphicsManager *);
PaletteHandle *sub_02015F1C(GraphicsResourceTemplate *);
void sub_02015F64(GraphicsManager *);
GraphicsObject *sub_02015F8C(GraphicsResourceTemplate *);
void sub_02015FB0(GraphicsObject *, BOOL);
void sub_02015FC4(GraphicsObject *, u16, u16);
u32 sub_02015FCC(GraphicsObject *);
void sub_02015FD8(GraphicsObject *, u16, u16);
void sub_02015FE0(GraphicsObject *, u16, u16);
u32 sub_02015FE8(GraphicsObject *);
void sub_02015FF4(GraphicsObject *, u32);
u32 sub_02015FF8(GraphicsObject *);
void sub_02015FFC(GraphicsObject *, u8);
void sub_02016004(GraphicsObject *, NNSG2dCharacterData *);
void sub_02016008(GraphicsObject *, u32);
void sub_0201600C(GraphicsObject *, u32);
void sub_02016010(GraphicsObject *, u32);
void sub_02016014(GraphicsObject *, int, BOOL);
void sub_02016020(GraphicsObject *, u32);

#endif
