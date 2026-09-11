#ifndef PRIVATE_H
#define PRIVATE_H
#include "global.h"
typedef struct Work{u8 d[0xe00];}Work;
void GF_AssertFail(void);extern const u16 ov96_0221AA20[];u32 PokeathlonCourse_GetHeapID(Work*);void *NARC_New(u32,u32);void NARC_ReadWholeMember(void*,u32,void*);void NARC_Delete(void*);u32 LCRandom(void);
u16 ov96_021E8424(u32);u8 ov96_021E8448(Work*,u32);void ov96_021E860C(u32,u8,u32,u8*);
#endif
