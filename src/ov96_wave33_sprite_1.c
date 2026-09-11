#include "ov96_wave33_sprite_private.h"

void *ov96_0220D13C(void *sys,void *mgr,u16 x,u16 y,u16 arg5,u16 arg6){R25Template t=ov96_0221CE84;void *sprite;if(!sys)GF_AssertFail();if(!mgr)GF_AssertFail();t.x=x;t.y=y;t.arg5=arg5;t.arg6=arg6;t.rest[8]=1;sprite=SpriteSystem_NewSpriteWithYOffset(sys,mgr,&t,0x100000);ManagedSprite_SetAnimateFlag(sprite,1);return sprite;}
