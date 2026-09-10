#include "overlay120_helpers_internal.h"

#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))

extern const u32 ov120_022601F4[];
extern const u32 ov120_022601F8[];
extern const u32 ov120_022601FC[];
extern const u32 ov120_02260200[];

void ov120_0225FCFC(void *a, void *b) {
    ov120_0225FF00(a, b, 1);
}

void ov120_0225FD08(void *a, void *b) {
    ov120_0225FF00(a, b, 0);
}

void *ov120_0225FD14(void *narc, int member, NNSG2dCharacterData **out, int heap) {
    void *raw = GfGfxLoader_LoadFromOpenNarc(narc, member, 0, heap, 0);
    NNS_G2dGetUnpackedBGCharacterData(raw, out);
    return raw;
}
