#include "overlay92_sol_partial_internal.h"

extern void SetLCRNGSeed(u32 seed);
extern void Heap_Free(void *ptr);
extern void *Heap_Alloc(u32 heapId, u32 size);
extern void ManagedSprite_TickTwoFrames(void *sprite);
extern void ManagedSprite_SetDrawFlag(void *sprite, int flag);
extern void Sprite_DeleteAndFreeResources(void *sprite);
extern void sub_02018030(void *p, int a, int b, int heapId);
extern void sub_02018068(void *p);
extern int FontID_String_GetWidth(int fontId, const void *str, int letterSpacing);
extern int GetWindowWidth(const void *window);
extern void BeginNormalPaletteFade(int a, int b, int c, int d, int e, int f, int heapId);
extern void ov92_0225D8D4(void *p);
extern void ov92_0225D8DC(void *p);
extern void ov92_022634F8(const void *src, void *dst);
extern void GF_RunVramTransferTasks(void);
extern void SpriteSystem_TransferOam(void);
extern void PaletteData_PushTransparentBuffers(void *);
extern void DoScheduledBgGpuUpdates(void *);
extern int WindowIsInUse(const void *);
extern void sub_0200E5D4(void *, int);
extern void ClearWindowTilemapAndCopyToVram(void *);
extern void RemoveWindow(void *);
extern void ov92_0225DD48(void *, int);
extern void ov92_02260AE0(void *, void *);
extern void *SysTask_CreateOnMainQueue(void (*)(void *, void *), void *, u32);
extern void *OverlayManager_GetData(void *);
extern void OverlayManager_FreeData(void *);
extern void Heap_Destroy(u32);
extern void sub_020398D4(int, int);
extern void sub_02037AC0(int);
extern int sub_02037B38(int);
extern int sub_02037454(void);
extern int sub_020347A0(void);
extern int ov90_02258B54(void *);
extern int ov90_02258B98(void *);
extern void ov90_02258A04(void *);
extern void ov90_02258938(void *);
extern int IsPaletteFadeFinished(void);
extern void sub_0200FB70(void);
extern void sub_0200FC20(int);
extern void ov92_0225E360(void *);
extern void ov92_0225D1FC(void *);
extern const u8 _0226383C[];

void ov92_0225C584(void);
int ov92_0225C588(void);
int ov92_0225C58C(void);
int ov92_0225C590(void);
int ov92_0225C594(void);
int ov92_0225C598(void);
int ov92_0225C5A4(void);
const void *ov92_0225C59C(void);
void ov92_0225D88C(void *, int, u32, u32 *);
void ov92_0225EB68(void *);
void ov92_0225ED60(void *);
void ov92_02261E80(void *);
void ov92_0225C558(void *, void *, void *, void *);
void ov92_0225C578(int, void *, const u32 *, void *);
void ov92_0225D9A8(void *, int, int);
void ov92_0225E9A8(void *);
int ov92_0225D8C4(void *);
void ov92_02260860(void *, s32, s32, s32);
void ov92_022630E8(void *);
void ov92_022630F8(Ov92Vec4 *, const Ov92Vec4 *);
void ov92_0225C564(int, void *, const u32 *, void *);
void ov92_0225DA2C(void *);
void ov92_0225C540(void *, void *, const u32 *, void *);
void ov92_0225DF28(void *);
void ov92_0225DF40(void *);
int ov92_0225EB70(void *);
int ov92_0225ED68(void *);
void ov92_0225DEF0(void *);
void ov92_0225DF0C(void *, int);
int ov92_0226077C(void *, u32);
int ov92_0225E188(const void *, const void *);
int ov92_0225D868(int);
void ov92_0225E918(void *);
void ov92_0225D344(void *);
void *ov92_0225EB40(void *, void *);
void ov92_02263824(const void *, MtxFx43 *);
void ov92_0225D894(void *);
void ov92_0225D970(void *, void *, void *);
void ov92_0225DDD8(void *, u16, u16, u32, u32, u32);
void ov92_0225E008(void *);
void ov92_0225E03C(void *);
void ov92_0225E100(void *);
void ov92_0225FEB4(void *);
void ov92_0225FEE4(void *);
void ov92_0225ED80(void *);
void ov92_022610E8(void *, void *);
void ov92_022632B4(float *, const float *, float);
float ov92_02263218(const float *);
int ov92_0225D36C(void *, int *);
int ov92_0225D8E4(void *);

void ov92_0225DEF0(void *p) {
    int i;
    for (i = 0; i < 4; i++, p = (u8 *)p + 4) {
        Sprite_DeleteAndFreeResources(PAT(p, 0xd0));
    }
}

void ov92_0225DF0C(void *p, int flag) {
    int i;
    for (i = 0; i < 0x24; i++, p = (u8 *)p + 4) {
        ManagedSprite_SetDrawFlag(PAT(p, 0x40), flag);
    }
}

void ov92_0225DF28(void *p) {
    int i;
    for (i = 0; i < 0x24; i++, p = (u8 *)p + 4) {
        ManagedSprite_TickTwoFrames(PAT(p, 0x40));
    }
}

void ov92_0225DF40(void *p) {
    int i;
    for (i = 0; i < 0x24; i++, p = (u8 *)p + 4) {
        Sprite_DeleteAndFreeResources(PAT(p, 0x40));
    }
}
