#include "global.h"
extern void GF_AssertFail(void);extern void *Heap_Alloc(int,u32);extern void Heap_Free(void*);
extern void ov49_02268DB0(void*);extern int ov45_0222B1DC(void*);extern int ov45_0222B1EC(void*);extern int ov45_0222A35C(void*);extern void ov49_0225E624(void*,int);extern void ov49_02268D94(void*);extern void ov49_02268C74(void*,int,int);typedef void(*Ov49Fn)(void*,int);extern Ov49Fn ov49_0226A84C[];
int ov49_02268974(int);int ov49_022689A0(int);int ov49_022689D4(int);void ov49_02268A00(void);void*ov49_02268A0C(void*,void*,int);void ov49_02268A6C(void*);void ov49_02268A7C(void*);void ov49_02268ADC(void*,int,int);

void ov49_02268A6C(void*p){ov49_02268DB0(p);Heap_Free(p);}

void ov49_02268A7C(void*p){int a,b,c;a=ov45_0222B1DC(*(void**)p);b=ov45_0222B1EC(*(void**)p);c=ov45_0222A35C(*(void**)p);if(*(u16*)((u8*)p+10)!=c){*(u16*)((u8*)p+10)=c;if(c==1){ov49_0225E624(*(void**)((u8*)p+4),1);ov49_02268C74(p,a,b);ov49_02268D94(p);}}if(c!=0){if(*((u8*)p+8)!=a)ov49_02268C74(p,a,b);ov49_02268ADC(p,a,b);}}

void ov49_02268ADC(void*p,int i,int arg){if((u32)i>=6)GF_AssertFail();if((u32)i<6)ov49_0226A84C[i](p,arg);}
