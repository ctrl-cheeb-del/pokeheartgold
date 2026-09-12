#include "overlay18_filter_input_internal.h"

#define U8_AT(p, n)  (*(u8 *)((u8 *)(p) + (n)))
#define U16_AT(p, n) (*(u16 *)((u8 *)(p) + (n)))

typedef struct Ov18Flags5 {
    u8 value : 5;
    u8 : 3;
} Ov18Flags5;

void ov18_021F822C(u32 index, u16 *dst, u32 *dstCount, const u16 *filter, u32 filterCount, const Pokedex *pokedex) {
    u16 *resource;
    u32 resourceCount;
    BOOL seenOnly = FALSE;

    switch (index) {
    case 0:
        memcpy(dst, filter, filterCount * sizeof(u16));
        *dstCount = filterCount;
        return;
    case 1:
        resource = ov18_021F8168(2, &resourceCount);
        seenOnly = TRUE;
        break;
    case 2:
        resource = ov18_021F8168(3, &resourceCount);
        break;
    case 3:
        resource = ov18_021F8168(4, &resourceCount);
        break;
    case 4:
        resource = ov18_021F8168(5, &resourceCount);
        break;
    case 5:
        resource = ov18_021F8168(6, &resourceCount);
        break;
    default:
        GF_ASSERT(FALSE);
        break;
    }
    ov18_021F8764(dst, dstCount, filter, filterCount, resource, resourceCount, seenOnly, pokedex);
    Heap_Free(resource);
}

void ov18_021F82CC(u32 index, u16 *dst, u32 *dstCount, const u16 *filter, u32 filterCount, const Pokedex *pokedex) {
    u16 *resource;
    u32 resourceCount;

    if (index == 26) {
        memcpy(dst, filter, filterCount * sizeof(u16));
        *dstCount = filterCount;
        return;
    }
    resource = ov18_021F8168(index + 7, &resourceCount);
    ov18_021F8764(dst, dstCount, resource, resourceCount, filter, filterCount, TRUE, pokedex);
    Heap_Free(resource);
}
