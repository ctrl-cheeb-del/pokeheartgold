#ifndef TO40_SOL_R19_PRIVATE_H
#define TO40_SOL_R19_PRIVATE_H
#include "global.h"
typedef struct { void *bg; u32 a; u32 b; u32 c; u8 x; u8 y; u8 lo:4; u8 hi:4; u8 z; } PromptTemplate;
extern void YesNoPrompt_InitFromTemplate(void *, const void *);
extern int GridInputHandler_GetNextInput(void *);
extern void ov81_02241CA0(void *, int *, int *);
extern void Pokepic_SetAttr(void*,int,int);
extern void ov81_02242D88(void*,int);
extern void ov81_02242D94(void *, int, int);
extern void ov81_02242D74(void *);
extern void PaletteData_LoadPaletteSlotFromHardware(void *, int, int, int);
extern void ov81_0224258C(void *, int, int, int, int, int);
void ov81_02241C0C(void*);
void ov81_02241E68(void*,int,int,int);
void ov81_02241BD0(void*,void*);
void ov81_02241C84(int,int,int*,int*);
void ov81_02241CEC(void*);
int ov81_02241D0C(void*);
void ov81_02241D38(void*);
void ov81_02241D94(void*);
void ov81_02241EDC(void*,int,int,int);
void ov81_02241FC0(void*);
void ov81_02242170(void*);
void ov81_02242500(void*);
void ov81_022425C4(void*,int,int,int);
void ov81_022425D8(void*,int,int,int);
#endif
