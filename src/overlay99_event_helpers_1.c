#include "overlay99_event_helpers_private.h"

void ov99_021E7CE4(u8 *w,u32 value,int old,int alt){int anim;if(value!=old&&value<0x20){ov99_021E7C58(w,value);if((int)value<0x1E)*(u32 *)(w+0x3F4)|=0x20000000;else ov99_021E77D8(w);if(value==0x1E)anim=12;else anim=14;if(alt)anim++;ManagedSprite_SetAnim(*(void **)(w+0x408),anim);}}
