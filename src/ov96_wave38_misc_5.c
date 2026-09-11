#include "ov96_wave38_misc_private.h"
typedef struct Pair109 {u16 a,b;} Pair109;

void ov96_02214490(R109 *w){u8 i=0;do{if(w[0x7d4+i*16]==0)ov96_02214044(w,i,0);i++;}while(i<4);}
