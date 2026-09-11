#include "ov96_wave38_misc_private.h"
typedef struct Pair109 {u16 a,b;} Pair109;

int ov96_0221454C(const void *aa,const void *bb){const Pair109 *a=aa,*b=bb;if(a->b>b->b)return -1;if(a->b<b->b)return 1;if(a->a<b->a)return -1;if(a->a>b->a)return 1;return 0;}
