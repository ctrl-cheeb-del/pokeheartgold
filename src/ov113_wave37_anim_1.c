#include "ov113_wave37_anim_private.h"

void ov113_021E6B1C(void*p){u8*a=p;if(a[27]==1||a[26]==0)Sprite_SetAnimCtrlSeq(*(void**)(a+0xbc),4);else Sprite_SetAnimCtrlSeq(*(void**)(a+0xbc),2);if(a[27]==1||a[26]==a[27]-1)Sprite_SetAnimCtrlSeq(*(void**)(a+0xc0),7);else Sprite_SetAnimCtrlSeq(*(void**)(a+0xc0),5);}
