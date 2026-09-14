#include "global.h"

#include "pokeathlon/pokeathlon.h"

#include "bg_window.h"
#include "player_data.h"
#include "sprite_system.h"
#include "text.h"

#pragma require_prototypes off

typedef struct Ov96R106Work {
    PokeathlonCourseData *course;
    enum HeapID heap;
    SpriteSystem *spriteSystem;
    SpriteManager *spriteManager;
    BgConfig *bgConfig;
    u8 pad14[8];
    u8 selected;
    u8 pad1D[0xB];
    Window windows[4];
    ManagedSprite *sprites[31];
} Ov96R106Work;

extern const s16 ov96_0221D14C[][2];
extern ManagedSprite *ov96_022104D8(SpriteSystem *, SpriteManager *, s32, s32, u16, u32);

void ov96_0221058C(Ov96R106Work *work, s32 value) {
    u8 tiles1[3];
    u8 tiles0[3];
    u8 digit;
    u8 i;

    digit = value / 100;
    tiles1[0] = (digit % 5) * 4;
    tiles0[0] = (digit / 5) * 8;
    digit = (value - digit * 100) / 10;
    tiles1[1] = (digit % 5) * 4;
    tiles0[1] = (digit / 5) * 8;
    digit = value % 10;
    tiles1[2] = (digit % 5) * 4;
    tiles0[2] = (digit / 5) * 8;
    for (i = 0; i < 3; i++) {
        CopyRectToBgTilemapRect(work->bgConfig, 6, i * 4, 0, 4, 8, *(void **)((u8 *)work + 0x24) + 0xC, tiles1[i], tiles0[i], 20, 16);
    }
    ScheduleBgTilemapBufferTransfer(work->bgConfig, 6);
}
