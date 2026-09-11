#include "overlay96_course_init_private.h"

void ov96_021E6454(u8 *w,int x){int v=(x+0x1D)/0x1E;if(v<=0){Sprite_SetDrawFlag(*(Sprite **)(w+0x714),FALSE);return;}if(v<=3){if(w[0x72B]!=v){PlaySE(0x897);w[0x72B]=v;}Sprite_SetDrawFlag(*(Sprite **)(w+0x714),TRUE);Sprite_SetAnimCtrlSeq(*(Sprite **)(w+0x714),v+1);return;}Sprite_SetDrawFlag(*(Sprite **)(w+0x714),FALSE);}

void ov96_021E64B8(Ov96Work *w){u8 i;w->dCount=0;for(i=0;i<3;i++){if(w->d[i].active!=0)GF_AssertFail();w->d[i].a=0;w->d[i].sprite=NULL;w->d[i].task=NULL;}}
