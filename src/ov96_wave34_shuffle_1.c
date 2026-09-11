#include "ov96_wave34_shuffle_private.h"

u16 ov96_021E8424(u32 id){if(id!=0&&id<=100)return ov96_0221AA20[(u8)(id-1)];GF_AssertFail();return 0;}

u8 ov96_021E8448(Work*w,u32 id){u8 data[8];void*narc;if(id!=0&&id<=100){narc=NARC_New(0x104,PokeathlonCourse_GetHeapID(w));NARC_ReadWholeMember(narc,id-1,data);NARC_Delete(narc);return data[7];}GF_AssertFail();return 0;}
