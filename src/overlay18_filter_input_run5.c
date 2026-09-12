#include "overlay18_filter_input_internal.h"

#define U8_AT(p, n)  (*(u8 *)((u8 *)(p) + (n)))
#define U16_AT(p, n) (*(u16 *)((u8 *)(p) + (n)))

typedef struct Ov18Flags5 {
    u8 value : 5;
    u8 : 3;
} Ov18Flags5;

void ov18_021F8468(u32 index, u16 *dst, u32 *dstCount, const u16 *filter, u32 filterCount, const Pokedex *pokedex) {
    u16 *resource;
    u32 resourceCount;
    switch (index) {
    case 14:
        memcpy(dst, filter, filterCount * sizeof(u16));
        *dstCount = filterCount;
        return;
    case 7:
        resource = ov18_021F8168(0x44, &resourceCount);
        break;
    case 13:
        resource = ov18_021F8168(0x45, &resourceCount);
        break;
    case 11:
        resource = ov18_021F8168(0x46, &resourceCount);
        break;
    case 5:
        resource = ov18_021F8168(0x47, &resourceCount);
        break;
    case 4:
        resource = ov18_021F8168(0x48, &resourceCount);
        break;
    case 12:
        resource = ov18_021F8168(0x49, &resourceCount);
        break;
    case 9:
        resource = ov18_021F8168(0x4A, &resourceCount);
        break;
    case 6:
        resource = ov18_021F8168(0x4B, &resourceCount);
        break;
    case 1:
        resource = ov18_021F8168(0x4C, &resourceCount);
        break;
    case 2:
        resource = ov18_021F8168(0x4D, &resourceCount);
        break;
    case 3:
        resource = ov18_021F8168(0x4E, &resourceCount);
        break;
    case 10:
        resource = ov18_021F8168(0x4F, &resourceCount);
        break;
    case 0:
        resource = ov18_021F8168(0x50, &resourceCount);
        break;
    case 8:
        resource = ov18_021F8168(0x51, &resourceCount);
        break;
    default:
        GF_ASSERT(FALSE);
        break;
    }
    ov18_021F8764(dst, dstCount, resource, resourceCount, filter, filterCount, TRUE, pokedex);
    Heap_Free(resource);
}
