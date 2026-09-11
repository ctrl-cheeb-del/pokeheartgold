#include "global.h"

extern void GF_AssertFail(void);
extern void YesNoPrompt_Destroy(void *);
extern void GridInputHandler_Free(void *);
extern void ov81_02241DDC(void *, int);
extern void ov81_0223F320(void *);
extern void BufferBoxMonSpeciesName(void *, ...);
extern int sub_0203769C(void);
extern void ov80_02237254(int);
extern void Pokepic_SetAttr(void *, int, int);
extern void Sprite_SetDrawFlag(void *, int);
extern void Sprite_SetMatrix(void *, void *);
extern int Sprite_IsAnimated(void *);
extern void Sprite_SetPaletteOverride(void *, int);
extern void Sprite_SetPalIndexRespectVramOffset(void *, int);
extern void *Sprite_GetMatrixPtr(void *);
extern void Sprite_SetOamMode(void *, int);
extern void ov81_0224276C(void *);
extern void sub_020195C0(void *);
extern void ov81_02241A38(void *);
extern void sub_0200E5D4(void *, int);
extern void ClearWindowTilemapAndScheduleTransfer(void *);
extern void Sprite_Delete(void *);
extern void Heap_Free(void *);
extern void *YesNoPrompt_Create(int);
extern void *GridInputHandler_GetDpadBox(void *);
extern void ov81_0224141C(void *, int);
extern void ov81_022413F4(void *, int);
extern void ov81_02241650(void *, int);
extern void ov81_022416CC(void *, int);
extern void BufferIntegerAsString(void *, ...);
extern void Sprite_SetAnimationFrame(void *, int);
extern void Sprite_SetAnimCtrlSeq(void *, int);
extern void SetWindowX(void *, int);
extern void ov81_022431E0(void *, int);
extern void Sprite_SetAnimSpeed(void *, int);
extern void RemoveWindow(void *);

void ov81_02242F3C(u16 *, u16);
void *ov81_02242F8C(void **);
void *ov81_02242F90(void **);
void ov81_0224323C(void);
void ov81_022404AC(u8 *, u32 *, u32);
void ov81_0224113C(void);
void ov81_02241BC8(void *);
u8 ov81_02242F40(u16 *);
void ov81_02243220(void *);
void ov81_0223E8B0(void *);
int ov81_0223F314(void *);
void ov81_022408B8(u8 *, ...);
BOOL ov81_02241020(int);
void ov81_02242704(int);
void ov81_02242710(u8 *);
void ov81_02242CB0(void *, int);
void ov81_02242D88(void **, int);
void ov81_02242DCC(void **, void *);
BOOL ov81_02242DD8(void **);
void ov81_02242DFC(void **, int);
void ov81_02242E08(void **, int);
void ov81_02242EB8(void **, int);
void *ov81_02242F30(void **);
void ov81_02242F48(u16 *);
void ov81_02242F54(u16 *);
void ov81_02242FB0(void **, int);
void ov81_02242FBC(void **, int);
void ov81_02240448(u8 *);
BOOL ov81_02240F08(u8 *, u8);
int ov81_02240F18(int);
BOOL ov81_02240F28(u8 *);
void ov81_02240F38(u8 *, u8);
void ov81_02241BB8(void **);
void ov81_0224275C(u8 *);
void ov81_0223FC60(void *);
void ov81_022413E0(void *);
void *ov81_02242D74(void **);
void *ov81_02242EA4(void **);
void *ov81_02242FC8(void **);
void ov81_02243228(void *, void *, u32 *, u32 *);
void ov81_02243298(void *, int);
void ov81_0224335C(void *, int);
void ov81_02243444(void *, int);
void ov81_022408A0(u8 *, int, int);
void ov81_02242D94(void **, int, int);
void ov81_02242DE4(void **, int);
void ov81_022430E8(u8 *);
void ov81_02241840(u8 *);
void ov81_02241A7C(u8 *);
void ov81_02241C84(int, int, int *, int *);
void ov81_02242170(u8 *);
void ov81_02242F94(void **, int);
void ov81_0224300C(u8 *);
void ov81_02241218(u8 *, u16, u16);
void ov81_02242DAC(void **, int, int);
void ov81_02242F10(void **, int, int);

void *ov81_02242D74(void **p) {
    Sprite_Delete(p[2]);
    Heap_Free(p);
    return NULL;
}

void ov81_02242D88(void **p, int v) {
    Sprite_SetDrawFlag(p[2], v);
}

void ov81_02242D94(void **p, int x, int y) {
    VecFx32 v;
    v.x = x << 12;
    v.y = y << 12;
    Sprite_SetMatrix(p[2], &v);
}

void ov81_02242DAC(void **p, int x, int y) {
    VecFx32 v;
    v.x = x << 12;
    v.y = (y << 12) + (2 << 20);
    Sprite_SetMatrix(p[2], &v);
}

void ov81_02242DCC(void **p, void *v) {
    Sprite_SetMatrix(p[2], v);
}

BOOL ov81_02242DD8(void **p) {
    return Sprite_IsAnimated(p[2]);
}

void ov81_02242DE4(void **p, int n) {
    Sprite_SetAnimationFrame(p[2], 0);
    Sprite_SetAnimCtrlSeq(p[2], n);
}

void ov81_02242DFC(void **p, int v) {
    Sprite_SetPaletteOverride(p[2], v);
}

void ov81_02242E08(void **p, int v) {
    Sprite_SetPalIndexRespectVramOffset(p[2], v);
}
