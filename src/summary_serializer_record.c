#include "global.h"

#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))

extern u32 AcquireMonLock(void *);
extern void ReleaseMonLock(void *, u32);
extern u32 GetMonData(void *, int, void *);
extern void *Mon_GetBoxMon(void *);
extern void ReadMsgDataIntoString(void *, int, void *);
extern void BufferBoxMonSpeciesName(void *, int, void *);
extern void BufferBoxMonNickname(void *, int, void *);
extern void BufferBoxMonOTName(void *, int, void *);
extern void StringExpandPlaceholders(void *, void *, void *);
extern u32 GetMonGender(void *);
extern u32 GetMonExpBySpeciesAndLevel(u16, u32);
extern u32 GetMonNature(void *);
extern u32 GetMoveMaxPP(u16, u8);
extern u32 MonGetFlavorPreference(void *, u32);
extern u32 Pokemon_GetStatusIconId(void *);
extern u32 Pokemon_IsImmuneToPokerus(void *);
extern u32 Pokemon_HasPokerus(void *);
extern u32 MonIsShiny(void *);
extern u32 GetRibbonAttr(u8, u32);

typedef struct SummaryRecord {
    u8 pad00[0x12];
    u8 level : 7;
    u8 flag12 : 1;
    u8 gender : 2;
    u8 form : 6;
    u8 pad14[0x3c];
    u32 status : 28;
    u32 flag28 : 1;
    u32 shiny : 1;
    u32 pokerus : 2;
} SummaryRecord;

void sub_0208981C(void *, void *, void *);

void sub_0208981C(void *context, void *mon, void *out) {
    u32 lock;
    void *box;
    u16 i;

    lock = AcquireMonLock(mon);
    U16(out, 0xc) = GetMonData(mon, 5, NULL);
    box = Mon_GetBoxMon(mon);

    ReadMsgDataIntoString(PTR(context, 0x7a0), 0xb, PTR(context, 0x7ac));
    BufferBoxMonSpeciesName(PTR(context, 0x7a8), 0, box);
    StringExpandPlaceholders(PTR(context, 0x7a8), PTR(context, 0x230), PTR(context, 0x7ac));

    ReadMsgDataIntoString(PTR(context, 0x7a0), 0, PTR(context, 0x7ac));
    BufferBoxMonNickname(PTR(context, 0x7a8), 0, box);
    StringExpandPlaceholders(PTR(context, 0x7a8), PTR(context, 0x234), PTR(context, 0x7ac));

    ReadMsgDataIntoString(PTR(context, 0x7a0), 0xe, PTR(context, 0x7ac));
    BufferBoxMonOTName(PTR(context, 0x7a8), 0, box);
    StringExpandPlaceholders(PTR(context, 0x7a8), PTR(context, 0x238), PTR(context, 0x7ac));

    U16(out, 0xe) = GetMonData(mon, 6, NULL);
    ((SummaryRecord *)out)->level = GetMonData(mon, 0xa1, NULL);
    ((SummaryRecord *)out)->flag28 = GetMonData(mon, 0x4c, NULL);

    if (GetMonData(mon, 0xb0, NULL) == 1 && ((SummaryRecord *)out)->flag28 == 0) {
        ((SummaryRecord *)out)->flag12 = 0;
    } else {
        ((SummaryRecord *)out)->flag12 = 1;
    }

    U8(out, 0x13) = (U8(out, 0x13) & ~3) | (GetMonGender(mon) & 3);
    ((SummaryRecord *)out)->form = GetMonData(mon, 0x9b, NULL);
    U8(out, 0x10) = GetMonData(mon, 0xb1, NULL);
    U8(out, 0x11) = GetMonData(mon, 0xb2, NULL);
    U32(out, 0x14) = GetMonData(mon, 7, NULL);
    U32(out, 0x18) = GetMonData(mon, 8, NULL);
    U8(out, 0x44) = GetMonData(mon, 0x9d, NULL);

    U32(out, 0x1c) = GetMonExpBySpeciesAndLevel(U16(out, 0xc), ((SummaryRecord *)out)->level);
    if (((SummaryRecord *)out)->level == 100) {
        U32(out, 0x20) = U32(out, 0x1c);
    } else {
        U32(out, 0x20) = GetMonExpBySpeciesAndLevel(U16(out, 0xc), ((SummaryRecord *)out)->level + 1);
    }

    U16(out, 0x24) = GetMonData(mon, 0xa3, NULL);
    U16(out, 0x26) = GetMonData(mon, 0xa4, NULL);
    U16(out, 0x28) = GetMonData(mon, 0xa5, NULL);
    U16(out, 0x2a) = GetMonData(mon, 0xa6, NULL);
    U16(out, 0x2c) = GetMonData(mon, 0xa8, NULL);
    U16(out, 0x2e) = GetMonData(mon, 0xa9, NULL);
    U16(out, 0x30) = GetMonData(mon, 0xa7, NULL);
    U8(out, 0x32) = GetMonData(mon, 0xa, NULL);
    U8(out, 0x33) = GetMonNature(mon);

    for (i = 0; i < 4; i++) {
        u16 *move = (u16 *)((u8 *)out + i * 2);
        u8 *slot = (u8 *)out + i;
        u8 ppUps;
        U16(move, 0x34) = GetMonData(mon, 0x36 + i, NULL);
        U8(slot, 0x3c) = GetMonData(mon, 0x3a + i, NULL);
        ppUps = GetMonData(mon, 0x3e + i, NULL);
        U8(slot, 0x40) = GetMoveMaxPP(U16(move, 0x34), ppUps);
    }

    U8(out, 0x45) = GetMonData(mon, 0x13, NULL);
    U8(out, 0x46) = GetMonData(mon, 0x14, NULL);
    U8(out, 0x47) = GetMonData(mon, 0x15, NULL);
    U8(out, 0x48) = GetMonData(mon, 0x16, NULL);
    U8(out, 0x49) = GetMonData(mon, 0x17, NULL);
    U8(out, 0x4a) = GetMonData(mon, 0x18, NULL);
    U8(out, 0x4b) = 5;
    for (i = 0; i < 5; i++) {
        if (MonGetFlavorPreference(mon, i) == 1) {
            U8(out, 0x4b) = i;
            break;
        }
    }

    U16(out, 0x4c) = GetMonData(mon, 0xb, NULL);
    U16(out, 0x4e) = GetMonData(mon, 0x70, NULL);
    ((SummaryRecord *)out)->status = Pokemon_GetStatusIconId(mon);
    if (Pokemon_IsImmuneToPokerus(mon) == 1) {
        ((SummaryRecord *)out)->pokerus = 2;
    } else if (Pokemon_HasPokerus(mon) == 1) {
        ((SummaryRecord *)out)->pokerus = 1;
        if (((SummaryRecord *)out)->status == 7) {
            ((SummaryRecord *)out)->status = 0;
        }
    } else {
        ((SummaryRecord *)out)->pokerus = 0;
    }

    if (MonIsShiny(mon) == 1) {
        ((SummaryRecord *)out)->shiny = 1;
    } else {
        ((SummaryRecord *)out)->shiny = 0;
    }

    U32(out, 0x54) = 0;
    U32(out, 0x58) = 0;
    U32(out, 0x5c) = 0;
    U32(out, 0x60) = 0;
    U8(context, 0x7c6) = 0;
    for (i = 0; i < 0x50; i++) {
        if (GetMonData(mon, GetRibbonAttr((u8)i, 0), NULL) != 0) {
            U32((u8 *)out + (((u32)i >> 5) * 4), 0x54) |= 1 << (i & 0x1f);
            U8(context, 0x7c6)
            ++;
        }
    }

    for (i = 0; i < 6; i++) {
        u8 *dst = (u8 *)context + i;
        U8(dst, 0x294) = GetMonData(mon, 0xb5 + i, NULL);
    }
    ReleaseMonLock(mon, lock);
}
