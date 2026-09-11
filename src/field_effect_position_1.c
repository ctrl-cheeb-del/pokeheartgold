#include "field_effect_position_private.h"

BOOL MapObjectMovementCmd100_Step1(LocalMapObject *obj) {
 s32 *p=(s32 *)sub_0205F3E4(obj);(*p)++;if(*p>=8){MapObject_SetFacingDirection(obj,1);sub_0205F328(obj,0);MapObject_IncrementMovementStep(obj);}return FALSE;
}

BOOL MapObjectMovementCmd101_Step0(LocalMapObject *obj) {
 sub_0205F3C0(obj,4);if(sub_0206642C(obj))sub_02068B48();VecFx32 v={0,0,0};MapObject_SetFacingVector(obj,&v);ov01_022000DC(obj);MapObject_SetFlagsBits(obj,(MapObjectFlagBits)0x10004);MapObject_ClearFlagsBits(obj,(MapObjectFlagBits)0x100000);MapObject_IncrementMovementStep(obj);return FALSE;
}

BOOL MapObjectMovementCmd101_Step1(LocalMapObject *obj) {
 s32 *p=(s32 *)sub_0205F3E4(obj);const s32 *table=_0210FACC;VecFx32 v={0,0,0};v.y=table[*p];MapObject_SetFacingVector(obj,&v);*p+=2;if((u32)*p<16)return FALSE;v.y=0;MapObject_SetFacingVector(obj,&v);MapObject_SetFlagsBits(obj,(MapObjectFlagBits)0x20028);sub_02066438(obj);MapObject_IncrementMovementStep(obj);return TRUE;
}
