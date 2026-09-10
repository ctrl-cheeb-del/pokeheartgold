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

void ov97_0221FB80(u32 *p, u32 a, u32 b, u32 c, u32 d) {
    p[0] = a;
    p[1] = b;
    p[4] = 0;
    p[5] = 0x1000;
    p[6] = 0x1000;
    p[7] = 0x1000;
    *(u16 *)(p + 8) = 0;
    p[9] = 0;
    p[10] = c;
    p[11] = d;
}

void ov97_0221FBA0(State *p) {
    void *pr = *(void **)((u8 *)p + 0x17c);
    void *c = SpriteTransfer_GetCharProxy(*(void **)((u8 *)p + 0x178));
    void *r = SpriteTransfer_GetPaletteProxy(pr, c);
    *(u32 *)((u8 *)p + 0x27c) = NNS_G2dGetImageLocation(c, NNS_G2D_VRAM_TYPE_2DSUB);
    *(u32 *)((u8 *)p + 0x280) = NNS_G2dGetImagePaletteLocation(r, NNS_G2D_VRAM_TYPE_2DSUB);
}
