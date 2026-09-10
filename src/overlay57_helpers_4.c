#include "global.h"

extern void Heap_Free(void *);
extern void Main_SetVBlankIntrCB(void (*)(void *), void *);
extern void HBlankInterruptDisable(void);
extern void ov57_0223B828(void *, int, int, int);
extern void Pokepic_Delete(void *);
extern void Pokepic_SetAttr(void *, int, int);
extern void ov57_02238D80(void *);
extern void ov57_0223866C(void *, int);
extern void GfGfx_BothDispOn(void);
extern void GfGfx_EngineATogglePlanes(int, BOOL);
extern void GfGfx_EngineBTogglePlanes(int, BOOL);
extern void CopyCapsule(const void *, void *);
extern char SDK_OVERLAY_OVY_6_ID[];
extern char SDK_OVERLAY_OVY_7_ID[];
extern void HandleLoadOverlay(int, int);
extern void Sprite_DeleteAndFreeResources(void *);
extern void RemoveWindow(void *);
extern void TextOBJ_SetSpritesDrawFlag(void *, BOOL);
extern void ManagedSprite_SetDrawFlag(void *, BOOL);
extern void ClearWindowTilemapAndScheduleTransfer(void *);
extern void BeginNormalPaletteFade(int, int, int, int, int, int, int);

void ov57_0223A058(void);
int ov57_0223A6B4(void);
u8 ov57_02237E78(u8 *);
void ov57_02237E80(u8 *, u8);
void ov57_02237E88(u8 *, u8);
void *ov57_0223B940(u8 *);
void ov57_0223B948(u8 *, void *);
void ov57_02237CDC(void);
void ov57_02237EA8(u8 *);
void ov57_02237E90(u8 *, int, int);
int ov57_0223B6F0(void *);
int ov57_0223B73C(void *);
int ov57_0223B74C(void *);
void ov57_0223BB4C(u8 *);
int ov57_0223B700(void *);
void ov57_0223BB38(u8 *, int);
void ov57_02239B94(void);
void ov57_0223B75C(u8 *);
void ov57_0223B774(u8 *);
void ov57_022378C0(void);
BOOL ov57_02238028(u8 *);
void ov57_02239260(u8 *);
void ov57_0223864C(u8 *);
void ov57_022387C0(u8 *, BOOL);
void ov57_02239240(u8 *, BOOL);
void ov57_02239B0C(u8 *);
void ov57_02239BAC(void);
void ov57_02239BCC(void);
void ov57_0223A05C(u8 *);

BOOL ov57_02238028(u8 *p) {
    int i;
    for (i = 0; i < 8; i++) {
        if (*(u32 *)(p + 0x34C) != 1) {
            return TRUE;
        }
        p += 0x10;
    }
    return FALSE;
}
