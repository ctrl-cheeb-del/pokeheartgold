#include "overlay96_course_init_private.h"

void ov96_021E6550(Ov96Work *w){u8 i;for(i=0;i<3;i++){w->d[i].active=0;w->d[i].a=0;w->d[i].sprite=NULL;SysTask_Destroy(w->d[i].task);w->d[i].task=NULL;}}

void ov96_021E658C(Ov96Work *w,int i,int seq){Sprite_TryChangeAnimSeq(w->d[i].sprite,seq);}

void ov96_021E65A4(Ov96Work *w){u8 i;for(i=0;i<3;i++){if(w->d[i].active==0)GF_AssertFail();Sprite_SetAnimActiveFlag(w->d[i].sprite,FALSE);}}

void ov96_021E65D8(Ov96Work *w){u8 i;if(w->spriteCount!=0){for(i=0;i<w->spriteCount;i++){Sprite_SetDrawFlag(w->sprites[i],TRUE);Sprite_SetAnimCtrlSeq(w->sprites[i],0);}}}

BOOL ov96_021E661C(u8 *w){u8 i;if(w[0x728]==0)return TRUE;if(!Sprite_IsAnimated(*(Sprite **)(w+0x71C))){for(i=0;i<w[0x728];i++)Sprite_SetDrawFlag(*(Sprite **)(w+0x71C+i*4),FALSE);return TRUE;}return FALSE;}
