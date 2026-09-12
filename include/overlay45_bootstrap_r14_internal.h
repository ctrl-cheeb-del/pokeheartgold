#ifndef OVERLAY45_BOOTSTRAP_R14_INTERNAL_H
#define OVERLAY45_BOOTSTRAP_R14_INTERNAL_H
#include "global.h"

typedef struct Ov45BaseState {
    u8 data[0x530];
} Ov45BaseState;
typedef struct Ov45Args {
    void *unk0;
    void *unk4;
    void *unk8;
} Ov45Args;
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
extern u8 SDK_OVERLAY_OVY_42_ID[];
#pragma require_prototypes off
void *SysTask_CreateOnVWaitQueue(void (*)(void *, void *), void *, u32);
void *OverlayManager_CreateAndGetData(void *, u32, u32);
void *OverlayManager_GetArgs(void *);
void *OverlayManager_GetData(void *);
void OverlayManager_FreeData(void *);
void *Heap_Alloc(u32, u32);
void Heap_Free(void *);
void ov45_02229FE0(void *, void *);
void *ov45_02229FF4(void *, u32);
void ov45_0222A0F0(void *);
void ov45_0222A15C(void *);
void *ov45_0222CD1C(void *, void *, void *, void *, u32);
void ov45_0222CD84(void *);
int ov45_0222CD90(void *);
void ov45_0222CD68(void *);
void ov45_0222CDC0(void *);
void ov45_0222A1F8(void *);
void ov45_0222D8A4(void *);
void ov45_0222ECB8(void *);
void ov45_0222D500(void *);
void ov45_0222B840(void *);
void ov45_0222BE5C(void *);
void ov45_0222BD30(void *);
void ov45_0222BB58(void *);
void ov45_0222BB60(void *, void *, void *, void *);
void ov45_0222BCB8(void *);
void ov45_0222C3B0(void *);
void ov45_0222CAA0(void *);
int ov45_0222CCDC(void *);
void ov45_0222AB0C(void *, u32 *);
void *sub_020318E8(void *);
void sub_020318FC(void *, u32);
void sub_02031900(void *, u32);
void ov45_0222BCD8(void *);
void ov45_0222C994(void *);
void ov45_0222EE80(void);
void ov45_0222D890(void *);
void ov45_0222E688(void);
void *ov45_0222E5D4(u32, void *, u32, void **, void *);
void *ov45_0222D860(u32);
void *PlayerProfile_New(u32);
void ov45_0222B8A0(void *, void *, u32);
void ov45_0222BD40(void *);
void ov45_0222EE20(void *, u32, void *);
void ov45_0222BC3C(void *);
void ov45_0222C388(void *);
void ov45_0222C8AC(void *);
void ov45_0222C978(void *, u32);
void ov45_0222CB44(void *, void *);
void ov45_0222BCC8(void *, u32);
extern void ov45_0222B2B4(void);
extern void ov45_0222B470(void);
extern void ov45_0222B530(void);
extern void ov45_0222B5A0(void);
extern void ov45_0222B75C(void);
extern void ov45_02254AC4(void);
#endif
