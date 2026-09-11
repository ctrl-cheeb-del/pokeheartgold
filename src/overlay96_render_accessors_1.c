#include "overlay96_render_accessors_private.h"
extern void ov96_021EEA94(void*,u32,u32,u32);extern void ov96_021EEB84(void*,void*,u32,u32);extern void *PokeathlonCourse_GetPlayerProfileFromData(void*,u32);extern u32 PokeathlonCourse_GetHeapID(void*);extern u32 PlayerProfile_GetTrainerGender(void*);extern u16 ov96_021EEBC8(u32);extern void GF_AssertFail(void);extern const u32 ov96_0221B1BC[];extern void ov96_021EEC0C(void*,void*,u32,u32,u32,u32);extern u32 Sprite_GetVramType(void*);extern void *Sprite_GetImageProxy(void*);
void ov96_021EEA88(void**);void ov96_021EEB74(void***,u32,u32);void ov96_021EEB84(void*,void*,u32,u32);u16 ov96_021EEBC8(u32);void ov96_021EEBE4(void*,void*,u32,u32,u32);void ov96_021EEBF8(void*,void*,u32,u32,u32,u32);void ov96_021EED14(void*,void*,u32,u32);

void ov96_021EEB84(void*sprite,void*course,u32 idx,u32 flag){void*profile=PokeathlonCourse_GetPlayerProfileFromData(course,idx);u32 heap=PokeathlonCourse_GetHeapID(course);u16 member;if(PlayerProfile_GetTrainerGender(profile)==0){member=ov96_021EEBC8(0);}else{member=ov96_021EEBC8(1);}ov96_021EEA94(sprite,member,(u8)flag,heap);}

u16 ov96_021EEBC8(u32 i){if(i>=6)GF_AssertFail();return ov96_0221B1BC[i];}

void ov96_021EEBE4(void*a,void*b,u32 c,u32 d,u32 e){ov96_021EEC0C(a,b,c,d,e,1);}

void ov96_021EEBF8(void*a,void*b,u32 c,u32 d,u32 e,u32 f){ov96_021EEC0C(a,b,c,d,e,f);}
