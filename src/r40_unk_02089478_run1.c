#include "r40_unk_02089478_private.h"
#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))

u32 sub_02089478(void *data) {
    Pokemon *mon;
    u8 old;
    if ((U32(gSystem, 0x48) & 3) == 0) {
        goto no_input;
    }
    if (U8(PTR(data, 0x22c), 0x11) == 2) {
        BoxPokemon *box = sub_0208A520(data);
        mon = AllocMonZeroed(0x13);
        CopyBoxPokemonToPokemon(box, mon);
    } else {
        mon = sub_0208A520(data);
    }
    U8(data, 0x7be) = 0;
    old = U8(data, 0x275);
    U8(data, 0x275) = GetMonData(mon, 0x13, NULL);
    if (old != U8(data, 0x275)) {
        U8(data, 0x7be) |= 1;
    }
    old = U8(data, 0x276);
    U8(data, 0x276) = GetMonData(mon, 0x14, NULL);
    if (old != U8(data, 0x276)) {
        U8(data, 0x7be) |= 2;
    }
    old = U8(data, 0x277);
    U8(data, 0x277) = GetMonData(mon, 0x15, NULL);
    if (old != U8(data, 0x277)) {
        U8(data, 0x7be) |= 4;
    }
    old = U8(data, 0x278);
    U8(data, 0x278) = GetMonData(mon, 0x16, NULL);
    if (old != U8(data, 0x278)) {
        U8(data, 0x7be) |= 8;
    }
    old = U8(data, 0x279);
    U8(data, 0x279) = GetMonData(mon, 0x17, NULL);
    if (old != U8(data, 0x279)) {
        U8(data, 0x7be) |= 0x10;
    }
    U8(data, 0x27a) = GetMonData(mon, 0x18, NULL);
    if (U8(PTR(data, 0x22c), 0x11) == 2) {
        Heap_Free(mon);
    }
    LoadFontPal1(0, 0x1c0, 0x13);
    LoadUserFrameGfx2(PTR(data, 0), 1, 0x3e2, 0xd, (u8)Options_GetFrame(PTR(PTR(data, 0x22c), 4)), 0x13);
    if (U8(data, 0x7be) == 0) {
        sub_0208DDA0(data, 0xfe);
        return 0x12;
    }
    sub_0208E174(data);
    sub_0208BCD4(data);
    sub_0208BDC8(data);
    return 0x11;
no_input:
    return 0x10;
}
