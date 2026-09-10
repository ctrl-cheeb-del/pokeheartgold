#include "field_ui_863f4_internal.h"

#define PTR(s, off, type) (*(type **)&(s)->raw[(off)])
#define S32(s, off)       (*(int *)&(s)->raw[(off)])
#define S16(s, off)       (*(s16 *)&(s)->raw[(off)])
#define U8(s, off)        ((s)->raw[(off)])

void sub_02086AB4(ModuleState *state, int index, int draw) {
    ModuleState *entry;
    if (draw == 1) {
        entry = (ModuleState *)&state->raw[index * 0x1c];
        ManagedSprite_SetDrawFlag(PTR(entry, 0x220, ManagedSprite), 1);
    } else {
        entry = (ModuleState *)&state->raw[index * 0x1c];
        ManagedSprite_SetDrawFlag(PTR(entry, 0x220, ManagedSprite), 0);
    }
}

void sub_02086AE4(ModuleState *state, int index) {
    s16 x, y;
    if (index >= S32(state, 0x3f0)) {
        ModuleEntry *entry = (ModuleEntry *)state;
        ManagedSprite *sprite = entry[index].sprite;
        S32(state, 0x214) = index;
        ManagedSprite_GetPositionXY(sprite, &x, &y);
        ManagedSprite_SetPositionXY(PTR(state, 0x220, ManagedSprite), x, y + 0x10);
    }
}
