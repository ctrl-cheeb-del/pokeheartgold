#ifndef TO47_UNK_020932E0_RESIDUAL_4_PRIVATE_H
#define TO47_UNK_020932E0_RESIDUAL_4_PRIVATE_H

#include "global.h"

#include "heap.h"
#include "sprite.h"
#include "touchscreen.h"

typedef struct UnkEntry_020932E0_R4 {
    Sprite *sprite;
    u8 filler_04[0x30];
} UnkEntry_020932E0_R4;

typedef struct UnkTriple_020932E0_R4 {
    Sprite *sprite;
    int unk_04;
    u32 unk_08;
} UnkTriple_020932E0_R4;

typedef struct UnkRow_020932E0_R4 {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0C;
} UnkRow_020932E0_R4;

typedef struct UnkRowActive_020932E0_R4 {
    u32 value;
    u8 filler_04[12];
} UnkRowActive_020932E0_R4;

typedef union UnkRows_020932E0_R4 {
    UnkRow_020932E0_R4 rows[3];
    struct {
        u8 filler_00[12];
        UnkRowActive_020932E0_R4 active[1];
    } state;
} UnkRows_020932E0_R4;

typedef struct UnkPair_020932E0_R4 {
    u8 x;
    u8 y;
    u8 x2;
    u8 y2;
    u32 unk_04;
} UnkPair_020932E0_R4;

typedef struct UnkStruct_020932E0_R4 {
    void *bgConfig;                           // 0x0000
    enum HeapID heapId;                       // 0x0004
    u8 filler_0008[0x000D - 0x0008];
    u8 count;                                 // 0x000D
    u8 unk_0E;
    u8 unk_0F;
    u8 unk_10;
    u8 filler_0011[2];
    u8 unk_13;
    u8 filler_0014[0x0198 - 0x0014];
    UnkEntry_020932E0_R4 entriesB[3];         // 0x0198
    u8 filler_0234[0x07E4 - 0x0234];
    TouchscreenHitbox *hitboxes;              // 0x07E4
    UnkEntry_020932E0_R4 entries[3];          // 0x07E8
    UnkRows_020932E0_R4 rowData;               // 0x0884
    Sprite *spriteA;                          // 0x08B4
    Sprite *spriteC;                          // 0x08B8
    Sprite *spriteD;                          // 0x08BC
    Sprite *spriteB;                          // 0x08C0
    Sprite *spriteE;                          // 0x08C4
    u8 filler_08C8[8];
    UnkTriple_020932E0_R4 *list;              // 0x08D0
    u8 filler_08D4[0x4684 - 0x08D4];
    int unk_4684;
    VecFx32 unk_4688;
    int touchX;                               // 0x4694
    int touchY;                               // 0x4698
    int touchMode;                            // 0x469C
    u32 unk_46A0;
    UnkPair_020932E0_R4 *pairs;               // 0x46A4
    UnkPair_020932E0_R4 dragState;            // 0x46A8
    int unk_46B0;
} UnkStruct_020932E0_R4;

#endif
