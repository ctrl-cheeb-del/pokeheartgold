#include "ov96_wave38_misc_private.h"
typedef struct Pair109 {u16 a,b;} Pair109;

u32 ov96_022143FC(s32 x,s32 y){if(x<128){if(y<112)return 0;return 2;}if(y<112)return 1;return 3;}
