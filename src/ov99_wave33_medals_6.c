#include "ov99_wave33_medals_private.h"

void ov99_021E7C58(R8Work *w,u32 target){u8 x,y;const DpadMenuBox *box=GridInputHandler_GetDpadBox(w->grid,target);DpadMenuBox_GetPosition(box,&x,&y);ManagedSprite_SetPositionXY(w->all[0],x,y);w->flags=(w->flags&0xf807ffff)|((target<<24)>>5);PlaySE(0x5dc);}
