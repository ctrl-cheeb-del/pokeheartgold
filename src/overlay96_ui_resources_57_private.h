#ifndef POKEHEARTGOLD_OVERLAY96_UI_RESOURCES_57_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY96_UI_RESOURCES_57_PRIVATE_H

#include "global.h"

#include "pokemon.h"
#include "sprite_transfer.h"
#include "unk_02013FDC.h"

typedef struct R57Window {
    u8 raw[0x10];
} R57Window;

typedef struct R57Vec {
    s32 x, y, z;
} R57Vec;

extern void GF_AssertFail(void);
extern void ov96_021F459C(void *, u32);
extern void ov96_021F4724(void *);
extern u32 ov96_021F46BC(void *, u32);
extern u32 ov96_021F47F0(void *, u32);
extern void ov96_021F480C(void *, void *);
extern void ov96_021F48A8(void *, void *, u32);
extern void ov96_021F4A60(void *, void *);
extern void ov96_021EB52C(void *, u32, u32);
extern void ov96_021EB2BC(void *, u32, u32, u32, u32);
extern void ov96_021EB2F4(void *, u32, u32, u32, u32, u32);
extern void ov96_021EB334(void *, u32, u32, u32);
extern void ov96_021EB36C(void *, u32, u32, u32);
extern void ov96_021EB408(void *, u32, u32, u32, u32);
extern void *ov96_021EB4F4(void *, u32, u32);
extern void *ov96_021EB5B8(void *);
extern void **ov96_021EB5EC(void *, u32, u32);
extern void FillWindowPixelBuffer(void *, u32);
extern void CopyWindowToVram(void *);
extern void AddWindow(void *, void *, const void *);
extern void BG_FillCharDataRange(void *, u32, u32, u32, u32);
extern void LoadFontPal0(u32, u32, u32);
extern void BufferIntegerAsString(void *, u32, u32, u32, u32, u32);
extern void *ReadMsgData_ExpandPlaceholders(void *, void *, u32, u32);
extern void AddTextPrinterParameterizedWithColor(void *, u32, void *, u32, u32, u32, u32, void *);
extern void PlaySE(u32);
extern u32 ov96_021E5F24(void *);

extern const u8 ov96_0221C028[];
extern const u32 ov96_0221BFF4[];

typedef struct R57ParticipantView {
    u16 species;
    u16 field2;
    u16 special;
    u8 kind;
    u8 field7;
    u32 participant;
    u32 fieldC;
} R57ParticipantView;

extern void ov96_021E6168(void *, u32, u32, R57ParticipantView *);

void ov96_021F4364(void *, u32);
void ov96_021F3E60(void *);
void ov96_021F3EC0(void *, void *);
void ov96_021F4390(void *, u32, u32);
void ov96_021F43EC(void *);
void ov96_021F440C(void *, void *);
void ov96_021F4484(void *);
void ov96_021F4504(void *, u32, u32);
void ov96_021F4558(void *);
void ov96_021F45F4(void *, u32, u32);
void ov96_021F4688(void *, u32, u32);

#endif // POKEHEARTGOLD_OVERLAY96_UI_RESOURCES_57_PRIVATE_H
