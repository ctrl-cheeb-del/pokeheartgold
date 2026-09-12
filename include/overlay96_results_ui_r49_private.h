#ifndef POKEHEARTGOLD_OVERLAY96_RESULTS_UI_R49_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY96_RESULTS_UI_R49_PRIVATE_H

#include "global.h"

typedef struct Ov96ResultsUiR49 {
    void *course;
    void *bgConfig;
    void *narc;
    u32 heapId;
    void *spriteSystem;
    void *spriteManager;
    u8 padding_18[8];
    u8 selection;
    u8 animIndex;
    u8 participant;
    u8 padding_23;
    u32 mode;
    u32 showRecord;
    u8 padding_2C[4];
    void *message;
    void *unk34;
    void *sprites[4];
} Ov96ResultsUiR49;

void *PokeathlonCourse_GetSaveData(void *course);
void *Save_Pokeathlon_Get(void *saveData);
u16 *PokeathlonSave_GetRecordsSolo2(void *save);
void ov98_0221EBD8(void *message, int index, int value, int unused);
void ov98_0221EBEC(void *message, int index, int value, int unused, int a, int b);
void ov98_0221EC08(void *message, int index, int value, int unused, int a);
BOOL ManagedSprite_IsAnimated(void *sprite);
void ov96_021EFA04(void *work);
void SpriteSystem_LoadPlttResObjFromOpenNarc(void *, void *, void *, int, int, int, int, int);
void SpriteSystem_LoadCharResObjFromOpenNarc(void *, void *, void *, int, int, int, int);
void SpriteSystem_LoadCellResObjFromOpenNarc(void *, void *, void *, int, int, int);
void SpriteSystem_LoadAnimResObjFromOpenNarc(void *, void *, void *, int, int, int);
u16 ov96_021EF5F4(Ov96ResultsUiR49 *work, int index);
void ov96_021EF770(Ov96ResultsUiR49 *work);
void ov96_021EF7C4(Ov96ResultsUiR49 *work);
void ov96_021EF8C0(Ov96ResultsUiR49 *work);
void ov96_021EF924(Ov96ResultsUiR49 *work);

#endif
