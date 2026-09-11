#include "overlay96_sprite_helpers_private.h"

Ov96R31Rec *ov96_021EB4F4(Ov96R31Work *w,int id,int kind){int i=0;int cap=w->config.capacity;if(cap>0){Ov96R31Rec *r=w->records;do{if(r->active==0&&r->id==id&&r->kind==kind){r->active=1;return r;}i++;r++;}while(i<cap);}GF_AssertFail();return NULL;}

void ov96_021EB52C(Ov96R31Rec *r,BOOL active,BOOL draw){if(r->active!=0){if(active){r->shown=1;if(draw){Sprite_SetDrawFlag(r->sprite,1);return;}Sprite_SetDrawFlag(r->sprite,0);return;}r->shown=0;Sprite_SetDrawFlag(r->sprite,0);return;}GF_AssertFail();}
