#include "overlay72_state_helpers_private.h"
typedef struct {u32 v[10];} BankConfig40;

void ov72_02237B80(int n){ov38_0221BE84();_0223B820[0x14]=n-1;if(ov72_02237D50(_0223B4E0,ov72_0223B834,1,ov72_0223B923,2))*(u32*)_0223B820=2;else{*(u32*)_0223B820=12;*(s32*)(_0223B820+4)=-5;ov38_0221BFEC();}}

void ov72_02237BD0(int a,int b,void*c){*(void**)(ov72_0223B920+8)=c;ov38_0221BE84();_0223B820[0x14]=a-1;_0223B820[0x15]=b-1;if(ov72_02237D50(ov72_0223B52C,ov72_0223B834,2,c,0xa38))*(u32*)_0223B820=4;else{*(u32*)_0223B820=12;*(s32*)(_0223B820+4)=-5;ov38_0221BFEC();}}
