#ifndef POKEHEARTGOLD_OVERLAY90_BG_SEQUENCE_INTERNAL_H
#define POKEHEARTGOLD_OVERLAY90_BG_SEQUENCE_INTERNAL_H

#include "global.h"

typedef struct Ov90R18Work {
    u8 pad00[0x10];
    int mode10;
    void *string14;
    fx32 value18;
    u8 pad1C[0x10];
    s16 counter2C;
    s16 state2E;
} Ov90R18Work;

extern const u32 ov90_0225C258[];
extern const u32 ov90_0225C228[];
extern const u32 ov90_0225C21C[];
extern const u32 ov90_0225C210[];
extern const u32 ov90_0225C1F8[];
extern const u32 ov90_0225C204[];
extern const u32 ov90_0225C234[];
extern const u32 ov90_0225C240[];
extern const u32 ov90_0225C24C[];

void ov90_02258CF0(void *, u32, u32, u32, int);
void ov90_0225A5BC(Ov90R18Work *, void *, int);
void ov90_0225A60C(Ov90R18Work *, void *, int);
void FontID_Alloc(int, int);
int FontID_String_GetWidth(int, void *, int);
void AddTextPrinterParameterizedWithColor(void *, int, void *, int, int, int, u32, void *);
void FontID_Release(int);
void GfGfx_EngineATogglePlanes(int, int);
int ov90_02258D4C(void *, int);
void ClearWindowTilemapAndCopyToVram(void *);
void BgClearTilemapBufferAndCommit(void *, int);
void BgSetPosTextAndCommit(void *, int, int, int);
void ScheduleSetBgPosText(void *, int, int, int);
void GF_AssertFail(void);
void GfGfxLoader_GXLoadPalWithSrcOffsetFromOpenNarc(void *, int, int, int, int, int, int);
void PlaySE(int);

void ov90_0225A350(Ov90R18Work *, void *, int);
void ov90_0225A3E0(Ov90R18Work *, void *);
BOOL ov90_0225A428(Ov90R18Work *, void *);
BOOL ov90_0225A544(Ov90R18Work *, void *);
void ov90_0225A5BC(Ov90R18Work *, void *, int);
void ov90_0225A60C(Ov90R18Work *, void *, int);
void ov90_0225A65C(void *, int, int);

#endif
