#ifndef POKEHEARTGOLD_OVERLAY18_POKEDEX_AREA_UI_H
#define POKEHEARTGOLD_OVERLAY18_POKEDEX_AREA_UI_H

#include "global.h"

#include "sprite_system.h"

void PlaySE(u16 seqNo);
void Heap_Free(void *ptr);
int Pokedex_GetInternationalViewFlag(void *pokedex);
int Pokedex_GetSeenFormByIdx(void *pokedex, int species, int idx);
int LanguageToDexFlag(u32 language);

int sub_020912AC(int a0);
int sub_02091294(int a0);

extern const ManagedSpriteTemplate ov18_021FA41C;
extern const ManagedSpriteTemplate ov18_021FA450;
extern const ManagedSpriteTemplate ov18_021FA484;
extern const ManagedSpriteTemplate ov18_021FA984[];
extern const ManagedSpriteTemplate ov18_021FAB24;
extern const ManagedSpriteTemplate ov18_021FAB58;
extern const ManagedSpriteTemplate ov18_021FAB8C;

void ov18_021E5900(void);
void ov18_021E5908(void);
int ov18_021E6D10(void *p, int a1, u16 a2);
void ov18_021F111C(void *p, int idx, void *str, int a3, int a4);
void ov18_021F118C(void *p, int idx, int anim);
void ov18_021F1324(void *p, int a1);
void ov18_021F1424(void *p, int a1);
void ov18_021F1620(void *p, int a1);
void ov18_021F17FC(void *p);
void ov18_021F1A30(void *p, int a1);
void ov18_021F1CAC(void *p, int a1, int a2, int a3);
void ov18_021F2BB0(void *p, int a1);
void ov18_021F2C10(void *p, int a1, int a2);
void ov18_021F2C5C(void *p, int a1, int a2);
void ov18_021F2E80(void *p, int a1, int a2);
void ov18_021F2EC8(void *p, int a1, int a2);
int ov18_021F8824(void *p);
int ov18_021F8838(void *p);
void *ov18_021F9694(int species, int a1);

#endif
