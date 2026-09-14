#ifndef TO46_OVERLAY95_RESIDUAL7_PRIVATE_H
#define TO46_OVERLAY95_RESIDUAL7_PRIVATE_H

#include "global.h"
typedef struct Pokemon Pokemon;
typedef struct Pokepic Pokepic;
typedef struct PokepicManager PokepicManager;
typedef struct NARC NARC;
typedef struct PokepicTemplate {
    u32 raw[4];
} PokepicTemplate;
typedef struct PokepicAnimScript {
    u32 raw[10];
} PokepicAnimScript;

typedef struct Ov95WorkR7 {
    void *app;
    u8 pad04[0x38];
    PokepicManager *pokepicManager;
    NARC *narc;
    u8 pad44[0x14];
    void *animData;
    u8 pad5C[0x14];
    Pokepic *pokepic;
} Ov95WorkR7;

u32 GetMonData(Pokemon *mon, u32 attr, void *dest);
u8 sub_0207083C(Pokemon *mon, u8 facing);
void SetMonData(Pokemon *mon, u32 attr, const void *value);
void GetPokemonSpriteCharAndPlttNarcIds(PokepicTemplate *template, Pokemon *mon, u8 facing);
void NARC_ReadPokepicAnimScript(NARC *narc, PokepicAnimScript *anim, u16 species, u16 facing);
Pokepic *PokepicManager_CreatePokepic(PokepicManager *manager, PokepicTemplate *template, int x, int y, int z, int polygonId, PokepicAnimScript *anim, void *callback);
u8 GetMonNature(Pokemon *mon);
void Pokepic_StartAnim(Pokepic *pokepic, u32 anim);
void sub_0207294C(NARC *narc, void *animData, Pokepic *pokepic, u16 species, int mode, int value, int zero);

void ov95_021E623C(Ov95WorkR7 *work);
void ov95_021E62A4(Ov95WorkR7 *work);

#endif
