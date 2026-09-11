#include "overlay72_state_helpers_private.h"
typedef struct {u32 v[10];} BankConfig40;

void ov72_02237CB0(void){ov38_0221BE84();if(ov72_02237D50(ov72_0223B5C4,ov72_0223B834,0,ov72_0223B923,2))*(u32*)_0223B820=8;else{*(u32*)_0223B820=12;*(s32*)(_0223B820+4)=-5;ov38_0221BFEC();}}

void ov72_02237CF4(void*a,void*b){OS_GetMacAddress((u8*)a+0x1c);memcpy(ov72_0223B834,a,0x64);*(void**)(ov72_0223B920+8)=b;ov38_0221BE84();if(ov72_02237D50(ov72_0223B60C,ov72_0223B834,0x64,*(void**)(ov72_0223B920+8),8))*(u32*)_0223B820=10;else{*(u32*)_0223B820=12;*(s32*)(_0223B820+4)=-5;ov38_0221BFEC();}}

int ov72_02237D50(void*a,void*b,int c,void*d,int e){int r=ov38_0221BEA8(a,*(void**)(_0223B820+8),b,c,d,e);switch(r){case 0:return 1;case 1:break;case 2:break;}return 0;}
