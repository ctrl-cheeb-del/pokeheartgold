#include "global.h"
extern void GF_AssertFail(void);
extern void ov49_0225CFA8(void *, const void *);
extern void ov49_0225CFEC(void *, int);
extern void ov49_0225D030(void *, void *);
extern void ov49_0225D04C(void *);
extern void ov49_0225D064(void *);
extern void ov49_0225D040(void *, int);
extern void ov49_0225D07C(void *, int);
extern void ov49_0225D088(void *);
extern void ov49_0225D090(void *);
typedef struct { s16 value; s16 pad; } Ov49Stride4;
extern const Ov49Stride4 ov49_02269A7C[];
extern const Ov49Stride4 ov49_02269A7E[];
void ov49_0225E3B8(void*,int,int);void ov49_0225E3F4(void*,int,int);void ov49_0225E420(void*,int,int,void*);void ov49_0225E47C(void*,int);void ov49_0225E4A4(void*,int);void ov49_0225E4CC(void*,int,int);void ov49_0225E4F8(void*,int,int);void ov49_0225E524(void*,int);void ov49_0225E54C(void*,int);
#define CHECK(p,i) do{if(*((u8*)(p)+0x613)<=(u32)(i))GF_AssertFail();}while(0)
#define OBJ(p,i) (*(void **)((u8*)(p)+0x208+(i)*4))

void ov49_0225E3B8(void*p,int i,int arg){u32 v[3];CHECK(p,i);v[2]=0x28000;v[1]=0;v[0]=arg;ov49_0225CFA8(OBJ(p,i),v);}

void ov49_0225E3F4(void*p,int i,int arg){CHECK(p,i);ov49_0225CFEC(OBJ(p,i),arg);}

void ov49_0225E420(void*p,int i,int dir,void*out){CHECK(p,i);if((u32)dir>=3)GF_AssertFail();ov49_0225D030(OBJ(p,i),out);*(s32 *)out+=ov49_02269A7C[dir].value<<12;*(s32 *)((u8*)out+8)+=ov49_02269A7E[dir].value<<12;*(s32 *)((u8*)out+4)=0x28000;}

void ov49_0225E47C(void*p,int i){CHECK(p,i);ov49_0225D04C(OBJ(p,i));}

void ov49_0225E4A4(void*p,int i){CHECK(p,i);ov49_0225D064(OBJ(p,i));}

void ov49_0225E4CC(void*p,int i,int arg){CHECK(p,i);ov49_0225D040(OBJ(p,i),arg);}

void ov49_0225E4F8(void*p,int i,int arg){CHECK(p,i);ov49_0225D07C(OBJ(p,i),arg);}

void ov49_0225E524(void*p,int i){CHECK(p,i);ov49_0225D088(OBJ(p,i));}

void ov49_0225E54C(void*p,int i){CHECK(p,i);ov49_0225D090(OBJ(p,i));}
