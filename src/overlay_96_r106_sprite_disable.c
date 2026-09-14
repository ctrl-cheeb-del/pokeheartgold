#include "global.h"

#include "sprite_system.h"

#pragma require_prototypes off

typedef struct Ov96R106Work {
    u8 pad00[0x68];
    ManagedSprite *sprites[31];
} Ov96R106Work;

void ov96_022107D4(Ov96R106Work *work) {
    int i;

    for (i = 0; i < 31; i++) {
        ManagedSprite_SetAnimateFlag(work->sprites[i], 0);
    }
}
