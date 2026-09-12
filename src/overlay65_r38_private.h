#ifndef TO40_R38_OVERLAY65_PRIVATE_H
#define TO40_R38_OVERLAY65_PRIVATE_H

#include "global.h"

#include "pokemon.h"

#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))
#define U8_AT(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U32_AT(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define S32_AT(p, o) (*(s32 *)((u8 *)(p) + (o)))

typedef struct Ov65MonSummary {
    u16 species;
    u16 mail;
    u8 gender;
    u8 language;
    u8 form;
    u8 padding;
    u16 unk8;
    u16 unka;
    u32 personality;
} Ov65MonSummary;

extern BOOL ItemIdIsMail(u16 itemId);
extern const u32 ov65_0221FEEC[];
extern void GfGfxLoader_GXLoadPal(int narcId, int memberNo, int location, int offset, u32 size, int heapId);
extern void *Party_GetMonByIndex(void *party, int index);
extern void *ov65_0221D57C(int side, void *mon, void *a2, void *a3);
extern void ov65_0221D674(void *a0, int side, void *party, int index, void *work);
extern void ov65_0221D8C4(void *a0, int side, void *work);
extern BOOL ov65_0221DDC0(void *a0, void *state, void *sprite, void *summaries, int side);
extern void ov65_0221DCBC(void *state);
extern void ov65_0221DE24(void *work, int message, int selection);
void ov65_0221C9D8(Pokemon *mon, Ov65MonSummary *summary);
void ov65_0221CA64(void *work, int index, int form);
void ov65_0221CADC(void *work, int selection);
void ov65_0221CB5C(void *work);
int ov65_0221CC0C(void *work);

#endif
