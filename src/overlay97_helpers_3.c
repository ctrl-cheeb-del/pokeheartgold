#include "global.h"
typedef struct {
    u8 raw[0x1000];
} State;
typedef struct {
    u32 x[10];
} Banks;
typedef struct {
    u32 x[4];
} Modes;
typedef struct {
    u32 x[4];
} ObjInit;
extern const Banks ov97_0221FCCC;
extern const Modes ov97_0221FCA8;
extern const ObjInit _0221FC98;
extern void *OverlayManager_GetArgs(void *);
extern int ov97_0221E700(void *);
extern void *OverlayManager_GetData(void *);
extern void Main_SetVBlankIntrCB(void *, void *);
extern void ov97_0221F020(void *);
extern void sub_02093354(void *);
extern void FontID_Release(int);
extern void OamManager_Free(void);
extern void ObjCharTransfer_Destroy(void);
extern void ObjPlttTransfer_Destroy(void);
extern void Heap_Free(void *);
extern void GfGfx_SetBanks(const void *);
extern void SetBothScreensModesAndDisable(const void *);
extern void ObjCharTransfer_Init(const void *);
extern void ObjPlttTransfer_Init(int, int);
extern void ObjCharTransfer_ClearBuffers(void);
extern void ObjPlttTransfer_Reset(void);
extern void NNS_G2dInitOamManagerModule(void);
extern void OamManager_Create(int, int, int, int, int, int, int, int, int);
extern void sub_02093594(void *);
extern void *PCStorage_GetMonByIndexPair(void *, int, int);
extern u32 GetBoxMonData(void *, int, void *);
extern void PCStorage_GetBoxName(void *, int, void *);
extern void CalcBoxMonPokeathlonPerformance(void *, void *);
extern void *Heap_Alloc(int, u32);
extern void ov97_0221F56C(void *);
extern void ov97_0221F428(void *, void *);
extern void ov97_0221F74C(void *);
extern void GfGfx_EngineBTogglePlanes(int, int);
extern void Sprite_DeleteAndFreeResources(void *);
extern void SpriteSystem_FreeResourcesAndManager(void *, void *);
extern void SpriteSystem_Free(void *);
extern void SpriteList_RenderAndAnimateSprites(void *);
extern void *SpriteTransfer_GetCharProxy(void *);
extern void *SpriteTransfer_GetPaletteProxy(void *, void *);
int ov97_0221E5C0(void *);
int ov97_0221E6DC(void *);
int ov97_0221E69C(void *);
void ov97_0221E7F4(void);
void ov97_0221E814(void);
void ov97_0221E834(void);
void ov97_0221E864(void);
void ov97_0221E88C(State *);
int ov97_0221E91C(void *, int, int, void *);
void ov97_0221E97C(void *, int, void *);
void ov97_0221EBD8(void *, u8 *);
void *ov97_0221EE84(int);
void ov97_0221EFD0(void *, u8 *);
void ov97_0221F010(State *);
void ov97_0221FB80(u32 *, u32, u32, u32, u32);
void ov97_0221FBA0(State *);
void ov97_0221FC54(State *);
int ov97_0221E91C(void *, int, int, void *);

void ov97_0221E7F4(void) {
    Banks b = ov97_0221FCCC;
    GfGfx_SetBanks(&b);
}

void ov97_0221E814(void) {
    Modes m = ov97_0221FCA8;
    SetBothScreensModesAndDisable(&m);
}

void ov97_0221E834(void) {
    ObjInit v = _0221FC98;
    ObjCharTransfer_Init(&v);
    ObjPlttTransfer_Init(0x14, 0x5c);
    ObjCharTransfer_ClearBuffers();
    ObjPlttTransfer_Reset();
}

void ov97_0221E864(void) {
    NNS_G2dInitOamManagerModule();
    OamManager_Create(0, 0x7e, 0, 0x20, 1, 0x7e, 0, 0x20, 0x5c);
}

void ov97_0221E88C(State *p) {
    sub_02093594(*(void **)((u8 *)p + 8));
}
