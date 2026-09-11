#include "ov96_wave37_record_private.h"

void ov96_021E7F48(Work*w){u8 i;u8*records=Save_Pokeathlon_FriendshipRecords_Get(*w->save);u8 idx=(u8)ov96_021E5F24(w);u8*src=w->records+0x7c*idx;i=0;do{*(u16*)(records+i*4)=*(u16*)(src+i*0x28);records[i*4+3]=(u8)*(u16*)(src+i*0x28+2);records[i*4+2]=src[i*0x28+0x11];i++;}while(i<3);}
