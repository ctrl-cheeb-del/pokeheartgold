#ifndef OVERLAY_83_RESIDUAL_31_PRIVATE_H
#define OVERLAY_83_RESIDUAL_31_PRIVATE_H

#include "global.h"

BOOL ov83_022450A8(void *state, int kind, int param);
void ov83_02245104(void *state, int value);
void ov83_0224517C(void *state, int value, int selected);
void ov83_02245210(void *state, int value);
void ov83_02245248(void *state, int value);
void *Save_PlayerData_GetProfile(void *saveData);
int PlayerProfile_GetTrainerGender(void *profile);
u16 ov83_0224777C(void *saveData, u8 slot, u8 index);
int sub_0203769C(void);
int sub_02037030(int value, void *dest, int size);

#endif
