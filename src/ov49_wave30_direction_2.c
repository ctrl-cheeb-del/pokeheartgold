#include "ov49_wave30_direction_private.h"
typedef struct{u32 a;u8 state,timer,kind,flag;} R;

void *ov49_0225F2FC(void*w,void*a){u32 v[3];void*x=ov49_02258C28(ov49_02259FF0(w),a);void*y=ov49_0225A008(w);ov49_02259154(x,v);ov49_0225CC28(y,v[0],v[1],v[2]);return x;}

void ov49_0225F334(void*w,void*a,void*b,void*c,void*d){void*x=ov49_02259FF0(w);void*y=ov49_0225A008(w);void*z=ov49_02258C5C(x,a,b,c);ov49_02258E7C(x,z,0,d);ov49_0225CC40(y,z);}

void ov49_0225F374(void*p){R*r=p;r->a=0;r->state=0;r->timer=1;r->kind=MTRandom()&3;r->flag=1;}
