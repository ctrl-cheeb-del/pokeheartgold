#include "global.h"

typedef struct Overlay05State {
    u8 data[0xc00];
} Overlay05State;

extern void PlaySE(int);
extern void ManagedSprite_SetDrawFlag(void *, int);
extern void sub_020880CC(int, void *);
extern void sub_0203769C(void *);
extern int sub_020378AC(void);
extern void DoScheduledBgGpuUpdates(void *);
extern void PaletteData_PushTransparentBuffers(void *);
extern void GF_RunVramTransferTasks(void);
extern void SpriteSystem_TransferOam(void);
extern void RemoveWindow(void *);
extern void String_Delete(void *);
extern void MessageFormat_Delete(void *);
extern void DestroyMsgData(void *);
extern void sub_020136B4(void *, int, int);
extern void FontOAM_Delete(void *);
extern void sub_020135AC(void *);
extern void Thunk_G3X_Reset(void);
extern int sub_020154B0(void *);
extern void sub_0201543C(void);
extern void sub_02015460(void);
extern void sub_02014EBC(void *);
extern void Heap_Free(void *);
extern void GF_3DVramMan_Delete(void *);
extern void sub_02015354(void);
extern void sub_02015394(void);
extern void GF_AssertFail(void);
extern void GfGfx_EngineATogglePlanes(int, int);
extern void FreeBgTilemapBuffer(void *, int);
extern void AddWindow(void *, void *, const void *);
extern void FillWindowPixelRect(void *, int, int, int, int, int);
extern void DrawFrameAndWindow2(void *, int, int, int);
extern int sub_0202FC48(void *);
extern void *WaitingIcon_New(void *, int);
extern void sub_0200F450(void *);
extern const u8 ov05_0221ECE4[];
extern int IsPaletteFadeFinished(void);
typedef struct Banks40 {
    u32 words[10];
} Banks40;
extern const Banks40 ov05_0221EC00;
extern void GfGfx_SetBanks(const void *);
extern void ManagedSprite_SetAnim(void *, int);

int ov05_0221C558(Overlay05State *);
int ov05_0221C7FC(Overlay05State *);
int ov05_0221C8E0(Overlay05State *);
int ov05_0221CC58(Overlay05State *);
int ov05_0221CCF4(void *);
void ov05_0221CE88(Overlay05State *);
void ov05_0221CFF0(Overlay05State *);
void ov05_0221D020(Overlay05State *);
void ov05_0221D228(void);
void ov05_0221D664(Overlay05State *, int, int, int);
void ov05_0221D690(Overlay05State *);
int ov05_0221DAE0(Overlay05State *);
void ov05_0221DB18(Overlay05State *);
u32 ov05_0221DB4C(int, int);
u32 ov05_0221DB70(int, int);
void ov05_0221DC34(Overlay05State *);
void ov05_0221E5E4(Overlay05State *);
void ov05_0221E60C(Overlay05State *);
void ov05_0221E9C4(Overlay05State *);
int ov05_0221E9F8(Overlay05State *);
void ov05_0221EA18(Overlay05State *);
void ov05_0221EA38(Overlay05State *);
int ov05_0221C018(Overlay05State *);
int ov05_0221C568(Overlay05State *);
void ov05_0221BB00(void);
int ov05_0221C8A0(Overlay05State *);
void ov05_0221D054(Overlay05State *);

int ov05_0221DAE0(Overlay05State *state) {
    if ((*(u8 **)&state->data[0])[0x28] != 1) {
        return 0;
    }
    Thunk_G3X_Reset();
    if (sub_020154B0(*(void **)&state->data[0xb5c]) == 0) {
        return 0;
    }
    sub_0201543C();
    sub_02015460();
    return 1;
}

void ov05_0221DB18(Overlay05State *state) {
    if ((*(u8 **)&state->data[0])[0x28] == 1) {
        sub_02014EBC(*(void **)&state->data[0xb5c]);
        Heap_Free(*(void **)&state->data[0xb60]);
        GF_3DVramMan_Delete(*(void **)&state->data[0xb58]);
    }
}
