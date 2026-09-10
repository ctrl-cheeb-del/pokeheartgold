#include "field_ui_863f4_internal.h"

#define PTR(s, off, type) (*(type **)&(s)->raw[(off)])
#define S32(s, off)       (*(int *)&(s)->raw[(off)])
#define S16(s, off)       (*(s16 *)&(s)->raw[(off)])
#define U8(s, off)        ((s)->raw[(off)])

void sub_02086F44(ModuleState *state) {
    int i = 0;
    if (S32(state, 0x2d0) > 0) {
        ModuleEntry *entry = (ModuleEntry *)state;
        do {
            int horizontal;
            int vertical;
            s16 y, x;
            if (i >= S32(state, 0x2dc) && i < S32(state, 0x2e0)) {
                horizontal = 16;
                vertical = 16;
            } else {
                horizontal = 4;
                vertical = 8;
            }
            ManagedSprite_GetPositionXY(entry->sprite, &x, &y);
            entry->bounds[0] = y - vertical;
            entry->bounds[2] = x - horizontal;
            entry->bounds[1] = y + vertical;
            entry->bounds[3] = x + horizontal;
            i++;
            entry++;
        } while (i < S32(state, 0x2d0));
    }
}

void sub_02086FCC(ModuleState *state) {
    PTR(state, 0x378, void) = (void *)FontSystem_NewInit(2, 0x6c);
    FontID_Alloc(2, 0x6c);
}

void sub_02086FE8(ModuleState *state) {
    FontID_Release(2);
    FontOAM_Delete(PTR(state, 0x37c, void));
    sub_02021B5C(&state->raw[0x384]);
    FontOAM_Delete(PTR(state, 0x380, void));
    sub_02021B5C(&state->raw[0x390]);
    sub_020135AC(PTR(state, 0x378, void));
}

void sub_02087028(ModuleState *state) {
    SpriteSystem_LoadPaletteBuffer(PTR(state, 0x2fc, void), 2, PTR(state, 0x2f0, void), PTR(state, 0x2f4, void), 0x10, 8, 0, 1, 1, 0x3eb);
}

void sub_02087064(ModuleState *state) {
    sub_02087028(state);
    sub_02087090(state, 0, 0x4e, 0xa5, 0);
    sub_02087090(state, 1, 0xac, 0xa5, 0);
}
