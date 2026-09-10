#include "field_map_object_render_internal.h"

void ov01_021FA798(void *sys, void *obj) {
    u8 *state = *(u8 **)((u8 *)sys + 0x100);
    s16 count = *(s16 *)state;
    u8 *entry = *(u8 **)(state + 8);
    int i;
    for (i = 0; i < count; i++, entry += 12) {
        if (*(void **)(entry + 4) == obj) {
            *(void **)(entry + 4) = NULL;
            *(void **)(entry + 8) = NULL;
            return;
        }
    }
}

void ov01_021FA7C8(void *sys) {
    u8 *state = *(u8 **)((u8 *)sys + 0x100);
    int i;
    u8 *entry = *(u8 **)(state + 8);
    for (i = 0; i < *(s16 *)state; i++, entry += 12) {
        if (*(void **)(entry + 4) != NULL) {
            ov01_021FA804(sys, entry);
        }
    }
}

void ov01_021FA7F8(void *unused, void *sys) {
    ov01_021FA7C8(sys);
}

void ov01_021FA804(void *sys, void *record) {
    u8 *r = record;
    if (ov01_021F9EC4(sys, *(u32 *)r) == 2) {
        return;
    }
    **(void ***)(r + 8) = ov01_021F9528(*(void **)(r + 4), *(u32 *)r);
    if (**(void ***)(r + 8) == NULL) {
        GF_AssertFail();
    }
    ov01_021FA2B8(*(void **)(r + 4), FALSE);
    if (MapObject_TestFlagsBits(*(void **)(r + 4), 2 << 20) == TRUE) {
        sub_0205F4C0(*(void **)(r + 4));
    } else {
        sub_0205F484(*(void **)(r + 4));
    }
    *(void **)(r + 4) = NULL;
    *(void **)(r + 8) = NULL;
}
