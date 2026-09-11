#include "overlay40_blend_helpers_private.h"
#define BODY(p) do { ov40_0222CAD8(p);ov40_0222C480(p);sub_02088030(p);ov40_0222CCAC(p);ov40_0222CFBC(p,1);ov40_0222CE7C(p);ov40_0222CED8(p);ov40_0222CBE0(p);ov40_0222CF10(p); } while(0)

int ov40_0222DA84(int *p,int direction) { int done=1; if(direction==1) { if(*p<16){*p+=2;done=0;} } else {if(*p>0){*p-=2;done=0;}} return done; }
