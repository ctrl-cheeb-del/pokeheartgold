#include "global.h"
typedef struct {
    u8 raw[0x400];
} State;
typedef struct {
    void *p;
    u32 state;
    u32 next;
    u32 x;
} Task;
extern void *_02249BE0;
extern void Heap_Free(void *);
extern void UnloadOVY38(void);
extern void UnloadDwcOverlay(void);
extern void sub_02034DE0(void);
extern void UnloadOverlayByID(int);

extern void sub_02031780(void *, int, u32);
extern u32 sub_0203186C(void *, void *);
extern void ov75_02249780(void *, void *, int);
extern void RemoveWindow(void *);
extern void *WaitingIcon_New(void *, int);
extern void sub_0200F450(void *);
extern void sub_0203957C(void);
extern void ov00_021EC8D8(void);
extern void sub_0203A914(void);
extern void Sys_ClearSleepDisableFlag(int);
extern void ov70_02237F2C(void);
extern void BeginNormalPaletteFade(int, int, int, int, int, int, int);
extern void *ov75_02247890(void *, int, int);
extern void *Heap_Alloc(int, u32);
extern int sub_0203A05C(void *);
extern void *Save_VarsFlags_Get(void *);
extern void SetFlag970(void *);
extern void GF_RunVramTransferTasks(void);
extern void OamManager_ApplyAndResetBuffers(void);
extern void DoScheduledBgGpuUpdates(void *);
extern void FreeBgTilemapBuffer(void *, int);
extern void FillWindowPixelBuffer(void *, int);
extern void CopyWindowToVram(void *);
extern void ov00_021ECD04(void);
extern void ov70_02238304(void *, void *);
extern int TextPrinterCheckActive(u8);
extern void PlaySE(int);
void ov75_02246B98(State *);
void ov75_02246BCC(State *, int, int);
void ov75_02246BD8(State *);
void ov75_02246BE0(State *, int);
u8 ov75_02246BE8(State *);
void *ov75_02246BF0(int, u32, int);
void ov75_02246C18(int, void *);
void ov75_02246C68(State *);
void ov75_02246C8C(State *);
void ov75_02246CA0(State *);
void ov75_02246CB8(State *);
void ov75_02246CCC(State *);
void ov75_02246CD8(State *, int);
u32 ov75_02246CE0(State *);
u32 ov75_02246CE8(State *);
void ov75_02246CF0(State *, u8);
u8 ov75_02246CF8(State *);
void ov75_02246D00(void);
void ov75_02246D04(void);
void *ov75_02246EAC(State *);
void ov75_02246EDC(State *);
void ov75_02247234(State *);
void ov75_0224741C(void *);
void ov75_02247838(State *);
void ov75_02247854(State *, u32, u32);
void ov75_0224785C(State *);
void ov75_02247878(State *);
int ov75_02247A78(Task *);
void ov75_02247D0C(State *);
int ov75_0224852C(Task *);
int ov75_0224854C(Task *);
int ov75_02248714(Task *);
int ov75_022488AC(Task *);
int ov75_022489F8(Task *);
int ov75_02248C64(Task *);
int ov75_0224921C(Task *);
int ov75_02249258(Task *);
int ov75_02249460(Task *);
int ov75_02249478(Task *);
int ov75_022494A4(Task *);
int ov75_02249534(int);
void ov75_02249758(void *, int, int);
void ov75_0224976C(void *, int, int);

void *ov75_02246EAC(State *p) {
    void *q = Heap_Alloc(0x73, 12);
    MI_CpuFill8(q, 0, 12);
    *(void **)q = *(void **)((u8 *)p + 4);
    *((u32 *)q + 1) = 1;
    *(u32 *)((u8 *)p + 0x7c) = 0;
    *(void **)((u8 *)p + 0x94) = q;
    return *(void **)((u8 *)p + 0x94);
}

void ov75_02246EDC(State *p) {
    if (sub_0203A05C(*(void **)((u8 *)p + 4))) {
        SetFlag970(Save_VarsFlags_Get(*(void **)((u8 *)p + 4)));
    }
    Heap_Free(*(void **)((u8 *)p + 0x94));
    ov75_02246BCC(p, 0, 0);
}
