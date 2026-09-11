#include "ov96_wave38_misc_private.h"
typedef struct Pair109 {u16 a,b;} Pair109;

BOOL ov96_0221341C(const VecFx32 *a,fx32 ra,const VecFx32 *b,fx32 rb){VecFx32 d;VEC_Subtract(a,b,&d);return VEC_Mag(&d)<=ra+rb;}
