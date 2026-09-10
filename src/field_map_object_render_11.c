#include "field_map_object_render_internal.h"

void ov01_021FA4F0(void *sys, void *obj) {
    u8 *state = *(u8 **)((u8 *)sys + 0x100);
    s16 count = *(s16 *)state;
    u8 *entry = *(u8 **)(state + 0xc);
    int i;
    for (i = 0; i < count; i++, entry += 0x10) {
        if (*(void **)(entry + 4) == obj && *(void **)(entry + 0xc) != NULL) {
            *(void **)(entry + 0xc) = NULL;
            return;
        }
    }
}

int ov01_021FA524(void *sys, u32 obj) {
    u8 *state = *(u8 **)((u8 *)sys + 0x100);
    s16 count = *(s16 *)state;
    u8 *entry = *(u8 **)(state + 0xc);
    int i;
    for (i = 0; i < count; i++, entry += 0x10) {
        if (*(u32 *)(entry + 4) == obj && *(void **)(entry + 0xc) != NULL) {
            if (*(void **)(entry + 8) == NULL) {
                return 3;
            }
            return 4;
        }
    }
    return 0;
}
