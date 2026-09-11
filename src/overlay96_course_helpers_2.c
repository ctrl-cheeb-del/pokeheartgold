#include "overlay96_course_helpers_private.h"
#include <string.h>

void ov96_021E9784(int index,u32 size,void *src,PokeathlonCourseData *course) { memcpy(PokeathlonCourse_GetParticipantData(course,index),src,size); ov96_021E604C(course); PokeathlonCourse_SetStateTransitionType(course,3); PokeathlonCourse_SetStateField07(course,5); }

void ov96_021E97B8(u32 x,u32 size,void *src,PokeathlonCourseData *course) { if(ov96_021E5F24(course)) memcpy(PokeathlonCourse_GetPlayerProfileFromData(course,0),src,size); PokeathlonCourse_SetStateTransitionType(course,4); PokeathlonCourse_SetStateField07(course,6); }

void ov96_021E97EC(u32 a,u32 b,u32 c,PokeathlonCourseData *course) { PokeathlonCourse_IncrementField1EF(course); if(PokeathlonCourse_GetParticipantCount(course)==PokeathlonCourse_GetField1EF(course)){PokeathlonCourse_ResetField1EF(course);PokeathlonCourse_SetStateTransitionType(course,5);PokeathlonCourse_SetStateField07(course,7);} }

void ov96_021E9820(int index,u32 size,u8 *src,PokeathlonCourseData *course) { u8 *p=PokeathlonCourse_GetDataCopyArea(course); if(src[0x24]) memcpy(p+0xF0,src,size); else memcpy(p+0x50+index*0x28,src,size); }

void ov96_021E9858(u32 a,u32 b,u32 c,PokeathlonCourseData *course) { PokeathlonCourse_SetStateTransitionType(course,10);PokeathlonCourse_SetStateField07(course,0x12); }

void ov96_021E9870(u32 size,u32 b,void *src,PokeathlonCourseData *course) { u8 *p=PokeathlonCourse_GetDataCopyArea(course); if(!ov96_021E5F24(course)){u32 n=((u32 (*)(PokeathlonCourseData *))PokeathlonCourse_GetUnkConstant4)(course); memcpy(ov96_021E8A20(p+0x28)+size*n,src,n);PokeathlonCourse_IncrementField1EF(course);if(PokeathlonCourse_GetParticipantCount(course)==PokeathlonCourse_GetField1EF(course)){PokeathlonCourse_ResetField1EF(course);PokeathlonCourse_SetStateField07(course,0x15);}} }

void ov96_021E98D0(u32 a,u32 size,void *src,PokeathlonCourseData *course){memcpy(PokeathlonCourse_GetDataCopyArea(course)+0xF0,src,size);PokeathlonCourse_SetStateField07(course,0x16);}

void ov96_021E98F4(u32 index,u32 b,u32 *src,PokeathlonCourseData *course){u32 *dst; u8 i; PokeathlonCourse_GetDataCopyArea(course); if(!ov96_021E5F24(course)){dst=(u32 *)PokeathlonCourse_GetFieldData_AtIndex(course,(u8)index);for(i=0;i<3;i++){dst[i*8+0]+=src[i*8+0];dst[i*8+1]+=src[i*8+1];dst[i*8+2]+=src[i*8+2];dst[i*8+3]+=src[i*8+3];dst[i*8+4]+=src[i*8+4];dst[i*8+5]+=src[i*8+5];dst[i*8+6]+=src[i*8+6];dst[i*8+7]+=src[i*8+7];}PokeathlonCourse_IncrementField1EF(course);if(PokeathlonCourse_GetParticipantCount(course)==PokeathlonCourse_GetField1EF(course)){PokeathlonCourse_ResetField1EF(course);PokeathlonCourse_SetStateField07(course,0x1E);}}}

void ov96_021E9994(u32 a,u32 b,u32 c,PokeathlonCourseData *course){PokeathlonCourse_GetDataCopyArea(course);ov96_021E5F24(course);PokeathlonCourse_SetStateTransitionType(course,0xD);PokeathlonCourse_SetStateField07(course,0x1F);}

void ov96_021E99B8(u32 a,u32 b,u32 c,PokeathlonCourseData *course){PokeathlonCourse_GetDataCopyArea(course);PokeathlonCourse_IncrementField1EF(course);if(PokeathlonCourse_GetParticipantCount(course)==PokeathlonCourse_GetField1EF(course)){PokeathlonCourse_ResetField1EF(course);PokeathlonCourse_SetStateTransitionType(course,0xF);PokeathlonCourse_SetStateField07(course,0x24);}}
