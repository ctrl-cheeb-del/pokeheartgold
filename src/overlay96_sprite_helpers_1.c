#include "overlay96_sprite_helpers_private.h"

void ov96_021EB144(Ov96R31Work *w, BOOL active){u8 i=0;BOOL flag;if(w->used>0){if(active==0)flag=1;else flag=0;do{Sprite_SetAnimActiveFlag(ov96_021E8BAC(ov96_021EAA20(ov96_021EAA04(w,i))),flag);i++;}while(i<w->used);}}
