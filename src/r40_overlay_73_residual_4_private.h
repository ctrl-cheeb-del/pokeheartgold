#ifndef SOL_R40_OV73_RESIDUAL_4_PRIVATE_H
#define SOL_R40_OV73_RESIDUAL_4_PRIVATE_H
#include "global.h"
#pragma require_prototypes off
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
typedef struct SolOv73Large4 {
    u8 pad_0000[0x4A38];
    u32 field_4A38;
} SolOv73Large4;
void sub_020398D4(int, int);
int sub_0203769C(void);
int sub_02037454(void);
void ov73_021E756C(void *, int, int);
void ov73_021E670C(void *, int);
void ov73_021E6508(void *);
int ov73_021E7340(void);
void ov73_021E7468(void *);
int System_GetTouchHeld(void);
extern u8 gSystem[];
extern const u8 ov73_021EA534[];
int TouchscreenHitbox_FindRectAtTouchNew(const void *);
int DoesPixelAtScreenXYMatchPtrVal(void *, int, int, int, void *);
int ov73_021E746C(void);
int sub_02037030(int, void *, int);
void ov73_021E781C(void *, int);
void PlaySE(int);
void ov73_021E71E4(void *, int, int);
void ScheduleBgTilemapBufferTransfer(void *, int);
#endif
