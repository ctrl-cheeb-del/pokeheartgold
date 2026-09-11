#include "overlay96_course_init_private.h"

int ov96_021E6108(const Ov96Mini *p){if(p==NULL)return 0;switch(p->type8){case 1:return 1;case 2:return 2;case 3:return 3;default:GF_AssertFail();return 0;}}

int ov96_021E6138(const Ov96Mini *p){if(p==NULL)return 0;switch(p->type6){case 1:return 1;case 2:return 2;case 3:return 3;default:GF_AssertFail();return 0;}}

void ov96_021E6168(PokeathlonCourseData *course,int participant,int which,Ov96ParticipantView *out){u8 narc[4];u8 *p;if(which>=3)GF_AssertFail();p=PokeathlonCourse_GetParticipantUnk04(course,participant)+which*0x28;out->kind=p[0x10];out->species=*(u16 *)p;out->field2=*(u16 *)(p+2);out->field7=p[0x11];out->participant=participant;out->fieldC=*(u32 *)(p+4);if(out->species==0)GF_AssertFail();if(out->species==0)out->species=1;ReadWholeNarcMemberByIdPair(narc,(NarcId)0x8D,SpeciesToOverworldModelIndexOffset(out->species));if(narc[1]!=0)out->special=1;else out->special=0;}
