#ifndef POKEHEARTGOLD_OVERLAY18_RESIDUAL_25_H
#define POKEHEARTGOLD_OVERLAY18_RESIDUAL_25_H

#include "global.h"

#include "sprite_system.h"
#include "system.h"

typedef struct Ov18Bits18C7 {
    u8 unk_0 : 5;
    u8 unk_5 : 1;
    u8 unk_6 : 1;
    u8 unk_7 : 1;
} Ov18Bits18C7;

void PlaySE(u16 seqNo);
int PlayerProfile_GetTrainerGender(void *profile);
u8 GetMonPicHeightBySpeciesGenderForm(u16 species, u8 gender, u8 whichFacing, u8 form, u32 pid);
void *GridInputHandler_Create(const void *hitBoxes, const void *dpadBoxes, const void *callbacks, void *callbackParam, BOOL inputState, u8 initialPos, u32 heapId);
const void *GridInputHandler_GetDpadBox(void *handler, int target);
void DpadMenuBox_GetPosition(const void *dpadBox, u8 *px, u8 *py);
int GridInputHandler_HandleInput_AllowHold(void *handler);
void MenuInputStateMgr_SetState(void *mgr, int state);
void Bg_SetTextDimAndAffineParams(void *bgConfig, u8 bgId, int op, int value, void *mtx, int centerX, int centerY);

extern const u8 ov18_021FA304[];
extern const u8 ov18_021FA310[];
extern const u8 ov18_021FBD1C[];
extern const u8 ov18_021FB688[];
extern const u8 ov18_021FB878[];
extern const u8 ov18_021FB9F0[];

u32 ov18_021F6214(void *p, int idx, const u8 *table);
int ov18_021F6230(void *p, int idx, const u8 *table, int x, u32 width);
int ov18_021F6244(void *p, int idx, const u8 *table, int x, u32 width);
void ov18_021F118C(void *p, int idx, int anim);
void ov18_021F11C0(void *p, int idx, int draw);
void ov18_021F1294(void *p, int idx, int x, int y, int a4);
void ov18_021F1A7C(void *p, u16 species, u8 form, u8 gender, int facing, int a5, int a6);
void ov18_021F3CA8(void *p, u32 index, u8 *form, u8 *gender);
void ov18_021F5EFC(void *p, s8 a1, int a2);
void ov18_021F5FFC(void *p, int idx, int value);
void ov18_021F6038(void *p);
void ov18_021F619C(void *p, s8 a1, s8 a2, int a3);

u32 ov18_021F64A4(void *p, int idx);
u32 ov18_021F64F4(void *p, int idx);
void ov18_021F65AC(void *p);
void ov18_021F65EC(void *p);
void ov18_021F6844(void *p, int idx, int value);
void ov18_021F684C(void *p, int a1, int a2, int a3);
void ov18_021F6990(void *p);
void ov18_021F6E58(void *p, int a1);

#endif
