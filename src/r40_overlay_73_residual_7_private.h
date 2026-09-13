#ifndef SOL_R40_OV73_RESIDUAL_7_PRIVATE_H
#define SOL_R40_OV73_RESIDUAL_7_PRIVATE_H
#include "global.h"
#pragma require_prototypes off
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define S16(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
typedef struct SolOv73Large {
    u8 pad_0000[0x4A2B];
    u8 field_4A2B;
    u8 pad_4A2C[4];
    u16 field_4A30;
} SolOv73Large;

u32 sub_02037454(void);
u32 ov73_021E746C(void);
void ov73_021E66F0(void *);
int sub_0203769C(void);
int sub_02037030(int, void *, int);
void ov73_021E670C(void *, int);
void ov73_021E67A8(void *);
extern u8 gSystem[];
void PlaySE(int);
int YesNoPrompt_HandleInput(void *);
void ov73_021E6830(void *);
void ov73_021E781C(void *, int);
void ov73_021E71E4(void *, int, int);
void GF_AssertFail(void);
#endif
