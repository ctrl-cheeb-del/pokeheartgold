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

void ov96_0221069C(Ov96R106Work *work) {
    u8 other = 0;
    int x;
    int y;
    u8 *spriteCursor;
    Window *windows;
    int i;
    u8 window;
    String *name;

    if (work == NULL) {
        GF_AssertFail();
    }
    windows = (Window *)work;
    i = 0;
    spriteCursor = (u8 *)work;
    windows = (Window *)((u8 *)windows + 0x28);
    do {
        if (i == work->selected) {
            x = 8;
            window = 0;
            y = 0x48;
        } else {
            window = other + 1;
            x = ov96_0221D14C[other][0];
            y = ov96_0221D14C[other][1];
            other = window;
        }
        name = PlayerProfile_GetPlayerName_NewString(PokeathlonCourse_GetPlayerProfileFromData(work->course, i), work->heap);
        FillWindowPixelBuffer(&windows[window], 0);
        AddTextPrinterParameterizedWithColor(&windows[window], 0, name, 0, 0, 0xFF, 0x000F0E00, NULL);
        CopyWindowToVram(&windows[window]);
        String_Delete(name);
        *(ManagedSprite **)(spriteCursor + 0x74) = ov96_022104D8(work->spriteSystem, work->spriteManager, x, y, (u16)i, 0x41);
        i++;
        spriteCursor += 4;
    } while (i < 4);
}
