#ifndef SOL_R40_OV73_RESIDUAL_6_PRIVATE_H
#define SOL_R40_OV73_RESIDUAL_6_PRIVATE_H
#include "global.h"
#pragma require_prototypes off
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
typedef struct SolOv73Large6 {
    u8 pad_0000[0x4A15];
    u8 field_4A15;
} SolOv73Large6;
typedef struct SolYesNoTemplate6 {
    void *bg;
    u32 x;
    u32 y;
    u32 z;
    u8 a;
    u8 b;
    u8 c : 4;
    u8 d : 4;
    u8 tail;
} SolYesNoTemplate6;
int ov73_021E75FC(u32);
int sub_0203769C(void);
void ov73_021E71E4(void *, int, int);
void ScheduleBgTilemapBufferTransfer(void *, int);
void ov73_021E66F0(void *);
int sub_02037030(int, void *, int);
void ov73_021E67A8(void *);
void MI_CpuFill8(void *, u8, u32);
void YesNoPrompt_InitFromTemplate(void *, const SolYesNoTemplate6 *);
int YesNoPrompt_IsInTouchMode(void *);
void YesNoPrompt_Reset(void *);
extern u8 gSystem[];
void PlaySE(int);
u32 ov73_021E746C(void);
u32 sub_02037454(void);
int YesNoPrompt_HandleInput(void *);
void ov73_021E781C(void *, int);
void ov73_021E670C(void *, int);
void ov73_021E756C(void *, int, int);
void ov73_021E6830(void *);
#endif
