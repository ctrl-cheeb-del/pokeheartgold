#include "field_ui_863f4_cleanup_internal.h"

#define PTR(s, off, type) (*(type **)&(s)->raw[(off)])
#define S32(s, off)       (*(int *)&(s)->raw[(off)])

void sub_020866CC(FieldUi863F4CleanupState *state) {
    int i = 0;
    if (S32(state, 0x2d0) > 0) {
        FieldUi863F4CleanupState *entry = state;
        do {
            Sprite_DeleteAndFreeResources(PTR(entry, 0xc, ManagedSprite));
            i++;
            entry = (FieldUi863F4CleanupState *)&entry->raw[0x1c];
        } while (i < S32(state, 0x2d0));
    }
    {
        FieldUi863F4CleanupState *other;
        int j = 0;
        if (S32(state, 0x3ec) > 0) {
            other = state;
            do {
                Sprite_DeleteAndFreeResources(PTR(other, 0x1cc, ManagedSprite));
                j++;
                other = (FieldUi863F4CleanupState *)&other->raw[0x1c];
            } while (j < S32(state, 0x3ec));
        }
    }
    {
        FieldUi863F4CleanupState *other;
        int j;
        j = 0;
        other = state;
        do {
            Sprite_DeleteAndFreeResources(PTR(other, 0x274, ManagedSprite));
            j++;
            other = (FieldUi863F4CleanupState *)&other->raw[0x1c];
        } while (j < 2);
    }
    {
        FieldUi863F4CleanupState *other;
        int j;
        j = 0;
        other = state;
        do {
            Sprite_DeleteAndFreeResources(PTR(other, 0x220, ManagedSprite));
            j++;
            other = (FieldUi863F4CleanupState *)&other->raw[0x1c];
        } while (j < 3);
    }
    sub_02086FE8(state);
    RemoveWindow((Window *)&state->raw[0x39c]);
}
