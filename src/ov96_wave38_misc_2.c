#include "ov96_wave38_misc_private.h"
typedef struct Pair109 {u16 a,b;} Pair109;

fx32 ov96_02213514(const VecFx32 *a,const VecFx32 *b){VecFx32 na,nb;VEC_Normalize(a,&na);VEC_Normalize(b,&nb);return VEC_DotProduct(&na,&nb);}

BOOL ov96_02213534(const VecFx32 *a,const VecFx32 *b,u32 angle){fx32 dot=ov96_02213514(a,b);s32 i=(s32)angle>>4;i=i*2;i=i+1;return dot>=FX_SinCosTable_[i];}

void ov96_02213558(R109 *w){w[0x61]++;if(w[0x61]>=10){w[0x61]=0;w[0x71]+=2;if(w[0x71]>w[0x70])w[0x71]=w[0x70];}}
