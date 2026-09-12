#include "overlay18_filter_input_internal.h"

#define U8_AT(p, n)  (*(u8 *)((u8 *)(p) + (n)))
#define U16_AT(p, n) (*(u16 *)((u8 *)(p) + (n)))

typedef struct Ov18Flags5 {
    u8 value : 5;
    u8 : 3;
} Ov18Flags5;

void *ov18_021F8168(u32 index, u32 *count) {
    u32 size;
    void *ret;
    GF_ASSERT(index < 82);
    ret = GfGfxLoader_LoadFromNarc_GetSizeOut(GetPokedexDataNarcID(), index + 11, FALSE, HEAP_ID_POKEDEX_APP, FALSE, &size);
    *count = size / 2;
    return ret;
}

void ov18_021F8198(u16 *dst, u32 *count, const Pokedex *pokedex, const u16 *src, u32 length) {
    u32 i;
    *count = 0;
    i = 0;
    if (length <= i) {
        return;
    }
    do {
        if (Pokedex_CheckMonSeenFlag(pokedex, *src)) {
            dst[*count] = *src;
            (*count)++;
        }
        i++;
        src++;
    } while (i < length);
}
