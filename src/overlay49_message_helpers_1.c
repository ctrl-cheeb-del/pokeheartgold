#include "global.h"
extern void GF_AssertFail(void);extern void *Heap_Alloc(int,u32);extern void Heap_Free(void*);
extern void ov49_02268DB0(void*);extern int ov45_0222B1DC(void*);extern int ov45_0222B1EC(void*);extern int ov45_0222A35C(void*);extern void ov49_0225E624(void*,int);extern void ov49_02268D94(void*);extern void ov49_02268C74(void*,int,int);typedef void(*Ov49Fn)(void*,int);extern Ov49Fn ov49_0226A84C[];
int ov49_02268974(int);int ov49_022689A0(int);int ov49_022689D4(int);void ov49_02268A00(void);void*ov49_02268A0C(void*,void*,int);void ov49_02268A6C(void*);void ov49_02268A7C(void*);void ov49_02268ADC(void*,int,int);

int ov49_02268974(int x){switch(x){case 1:case 2:case 3:case 4:case 5:case 6:return x-1;default:GF_AssertFail();return 0;}}

int ov49_022689A0(int x){switch(x){case 7:case 8:case 9:case 10:return x-7;default:GF_AssertFail();return 0;}}

int ov49_022689D4(int x){switch(x){case 11:case 12:case 13:case 14:return x-11;default:GF_AssertFail();return 0;}}

void ov49_02268A00(void){NNS_G3dGlbLightColor(GX_LIGHTID_2,0);}
