#ifndef PRIVATE_UNK_020932E0_H
#define PRIVATE_UNK_020932E0_H

#include "global.h"

#include "bg_window.h"
#include "filesystem.h"
#include "font.h"
#include "gf_gfx_loader.h"
#include "gf_gfx_planes.h"
#include "grid_cursor_internal.h"
#include "heap.h"
#include "msgdata.h"
#include "party.h"
#include "pokemon.h"
#include "pokemon_icon_idx.h"
#include "sprite.h"
#include "sprite_system.h"
#include "system.h"
#include "text.h"
#include "touchscreen.h"
#include "unk_02009D48.h"
#include "yes_no_prompt.h"

typedef struct UnkEntry_020932E0 {
    Sprite *sprite;
    u8 filler_04[0x30];
} UnkEntry_020932E0;

typedef struct MonDisplayInfo {
    u32 species;
    u32 unk_04;
    u16 isEgg;
    u16 form;
    u16 heldItem;
    u16 unk_0E;
} MonDisplayInfo;

typedef struct UnkTriple_020932E0 {
    Sprite *sprite;
    int unk_04;
    u32 unk_08;
} UnkTriple_020932E0;

typedef struct UnkPair_020932E0 {
    u32 unk_00;
    u32 unk_04;
} UnkPair_020932E0;

typedef struct UnkRow_020932E0 {
    u32 unk_00;
    u32 unk_04;
    u8 filler_08[8];
} UnkRow_020932E0;

typedef struct UnkGfxBuf_02094758 {
    u32 offset;
    u32 unk_04;
    Sprite *sprite;
    u8 buf[0x200];
} UnkGfxBuf_02094758;

struct UnkStruct_020932E0;

typedef void (*UnkCallback_020932E0)(void *);

typedef struct UnkStruct_020932E0 {
    BgConfig *bgConfig;              // 0x0000
    enum HeapID heapId;              // 0x0004
    YesNoPrompt *yesNoPrompt;        // 0x0008
    u8 filler_0C[1];                 // 0x000C
    u8 count;                        // 0x000D
    u8 unk_0E;                       // 0x000E
    u8 unk_0F;                       // 0x000F
    u8 unk_10;                       // 0x0010
    u8 unk_11;                       // 0x0011
    u8 unk_12;                       // 0x0012
    u8 unk_13;                       // 0x0013
    u32 state;                       // 0x0014
    SpriteList *spriteList;          // 0x0018
    u8 filler_1C[0x144 - 0x1C];      // 0x001C
    void *resObjMan[6];              // 0x0144
    void *charTransferTask;          // 0x015C
    void *plttTransferTask;          // 0x0160
    u8 filler_164[0x174 - 0x164];    // 0x0164
    u8 header[0x198 - 0x174];        // 0x0174
    UnkEntry_020932E0 entriesB[3];   // 0x0198
    u8 filler_234[0x7E4 - 0x234];    // 0x0234
    TouchscreenHitbox *hitboxes;     // 0x07E4
    UnkEntry_020932E0 entries[3];    // 0x07E8
    UnkRow_020932E0 rows[3];         // 0x0884
    Sprite *spriteA;                 // 0x08B4
    u8 filler_8B8[8];                // 0x08B8
    Sprite *spriteB;                 // 0x08C0
    u8 filler_8C4[0x8D0 - 0x8C4];    // 0x08C4
    struct UnkTriple_020932E0 *list; // 0x08D0
    u8 filler_8D4[0x4640 - 0x8D4];   // 0x08D4
    Party *party;                    // 0x4640
    UnkCallback_020932E0 callback;   // 0x4644
    u8 filler_4648[8];               // 0x4648
    Window window0;                  // 0x4650
    Window window1;                  // 0x4660
    Window window2;                  // 0x4670
    int unk_4680;                    // 0x4680
    int unk_4684;                    // 0x4684
    u8 filler_4688[0x46B0 - 0x4688]; // 0x4688
    int unk_46B0;                    // 0x46B0
    UnkPair_020932E0 *pairs;         // 0x46B4
    GridCursor *cursor;              // 0x46B8
    int unk_46BC;                    // 0x46BC
    int unk_46C0;                    // 0x46C0
    int unk_46C4;                    // 0x46C4
    void *unk_46C8;                  // 0x46C8
    void *unk_46CC;                  // 0x46CC
    u8 filler_46D0[0x46E8 - 0x46D0]; // 0x46D0
} UnkStruct_020932E0;                // 0x46E8

#endif
