#include "overlay96_participant_helpers_private.h"

void ov96_021FBEA4(Obj *p) {
 void *sprite;
 p->unkC=0; sprite=ov96_021EB5B8(p->unk8);
 ov96_021EB52C(p->unk4,1,0); ov96_021EB52C(p->unk8,1,1);
 Sprite_SetAnimActiveFlag(sprite,1); Sprite_SetAnimCtrlSeq(sprite,1);
}

void ov96_021FBEDC(Obj *p, const void *v) {
 Sprite_SetMatrix(ov96_021EB5B8(p->unk4),v);
 Sprite_SetMatrix(ov96_021EB5B8(p->unk8),v);
}

void ov96_021FBEFC(Obj *p, int dy) {
 void *a; void *b; VecFx32 v;
 if (p->unk0 != 0) { a=ov96_021EB5B8(p->unk4); b=ov96_021EB5B8(p->unk8); v=*(VecFx32 *)Sprite_GetMatrixPtr(a); v.y += dy << 12; Sprite_SetMatrix(a,&v); Sprite_SetMatrix(b,&v); if (v.y >= 0x208000) ov96_021FBE54(p,0); }
}

void ov96_021FBF5C(Obj *p, s16 *out) {
 s32 *v=Sprite_GetMatrixPtr(ov96_021EB5B8(p->unk4));
 out[2]=0x40; out[3]=0x10; out[0]=(s16)(v[0]/4096-0x20); out[1]=(s16)(v[1]/4096-0x10);
}
