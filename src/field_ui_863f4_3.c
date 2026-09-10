#include "field_ui_863f4_internal.h"

#define PTR(s, off, type) (*(type **)&(s)->raw[(off)])
#define S32(s, off)       (*(int *)&(s)->raw[(off)])
#define S16(s, off)       (*(s16 *)&(s)->raw[(off)])
#define U8(s, off)        ((s)->raw[(off)])

void sub_02086BB4(ModuleState *state) {
    int i;
    ModuleState *entry;
    ManagedSprite_TickFrame(PTR(state, 0x220, ManagedSprite));
    ManagedSprite_TickFrame(PTR(state, 0x23c, ManagedSprite));
    ManagedSprite_TickFrame(PTR(state, 0x258, ManagedSprite));
    for (i = 1, entry = (ModuleState *)&state->raw[0x1c]; i < 3; i++, entry = (ModuleState *)&entry->raw[0x1c]) {
        int anim = ManagedSprite_GetActiveAnim(PTR(entry, 0x220, ManagedSprite));
        if (anim == 3) {
            if (!ManagedSprite_IsAnimated(PTR(entry, 0x220, ManagedSprite))) {
                ManagedSprite_SetAnim(PTR(entry, 0x220, ManagedSprite), S32(entry, 0x214));
                if (S32(state, 0x374) == 1) {
                    sub_02086AB4(state, 1, 0);
                } else {
                    sub_02086AB4(state, 1, 1);
                }
                sub_02086AB4(state, 2, 0);
            }
        } else {
            if (anim != S32(entry, 0x214)) {
                ManagedSprite_SetAnim(PTR(entry, 0x220, ManagedSprite), S32(entry, 0x214));
            }
            if (ManagedSprite_GetActiveAnim(PTR(state, 0x258, ManagedSprite)) != 3) {
                if (S32(state, 0x374) == 1) {
                    sub_02086AB4(state, 1, 0);
                } else {
                    sub_02086AB4(state, 1, 1);
                }
            }
        }
    }
}

void sub_02086C80(void *obj, int x, int y) {
    if (obj != 0) {
        sub_020136B4(obj, x, y);
    }
}

void sub_02086C8C(ModuleState *state) {
    int i;
    ModuleState *entry;
    ModuleState *pos;
    for (i = 0, pos = state, entry = state; i < 2;
        pos = (ModuleState *)&pos->raw[4], i++, entry = (ModuleState *)&entry->raw[0x1c]) {
        s16 x = (s16)((pos->raw[0x36e] + pos->raw[0x36f]) / 2) - 40;
        s16 y = (s16)((pos->raw[0x36c] + pos->raw[0x36d]) / 2) - 7;
        switch (S32(entry, 0x268)) {
        case 0:
            U8(entry, 0x280) = 0;
            break;
        case 1:
            U8(entry, 0x280)
            ++;
            if (U8(entry, 0x280) == 1) {
                ManagedSprite_SetAnim(PTR(entry, 0x274, ManagedSprite), 1);
                sub_02086C80(PTR(pos, 0x37c, void), x, y);
            } else if (U8(entry, 0x280) == 2) {
                ManagedSprite_SetAnim(PTR(entry, 0x274, ManagedSprite), 2);
                sub_02086C80(PTR(pos, 0x37c, void), x, y - 1);
            } else if (U8(entry, 0x280) == 10) {
                ManagedSprite_SetAnim(PTR(entry, 0x274, ManagedSprite), 0);
                sub_02086C80(PTR(pos, 0x37c, void), x, y);
                S32(entry, 0x268)
                ++;
            }
            break;
        default:
            ManagedSprite_SetAnim(PTR(entry, 0x274, ManagedSprite), 0);
            sub_02086C80(PTR(pos, 0x37c, void), x, y);
            S32(entry, 0x268) = 0;
            break;
        }
    }
}

int sub_02086D98(int value, int flag) {
    int add = 0;
    if (flag == 0) {
        add = 11;
    }
    return add + value;
}

void sub_02086DA4(ModuleState *state) {
    int i = 0;
    if (S32(state, 0x2d0) > 0) {
        ModuleEntry *entry = (ModuleEntry *)state;
        do {
            if (i >= S32(state, 0x2dc) && i < S32(state, 0x2e0)) {
                entry->active = 1;
            } else {
                entry->active = 0;
            }
            i++;
            entry++;
        } while (i < S32(state, 0x2d0));
    }
}
