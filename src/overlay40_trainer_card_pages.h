#ifndef OVERLAY40_TRAINER_CARD_PAGES_H
#define OVERLAY40_TRAINER_CARD_PAGES_H

#include "global.h"

#define PTR(p, off)  (*(void **)((u8 *)(p) + (off)))
#define WORD(p, off) (*(u32 *)((u8 *)(p) + (off)))
#define HALF(p, off) (*(u16 *)((u8 *)(p) + (off)))
#define BYTE(p, off) (*(u8 *)((u8 *)(p) + (off)))

#define BLEND(p, w, a, b) \
    PaletteData_BlendPalettes(PTR(p, 0x28), a, b, (u8)WORD(w, 8), (u16)WORD(p, 0x58))

void PaletteData_BlendPalettes(void *palette, int a, int b, int coeff, int color);
void BgClearTilemapBufferAndCommit(void *bgConfig, int bgId);
void GfGfx_EngineATogglePlanes(int mask, int enable);
void GfGfx_EngineBTogglePlanes(int mask, int enable);
void GfGfxLoader_LoadCharDataFromOpenNarc(void *narc, int memberNo, void *bgConfig, int layer, int tileStart, int szByte, int isCompressed, int heapId);
void GfGfxLoader_LoadScrnDataFromOpenNarc(void *narc, int memberNo, void *bgConfig, int layer, int tileStart, int szByte, int isCompressed, int heapId);
void ManagedSprite_SetAnim(void *sprite, int anim);
void TouchHitboxController_Destroy(void *controller);
void BeginNormalPaletteFade(int a, int b, int c, int d, int e, int f, int g);
BOOL IsPaletteFadeFinished(void);
void PlaySE(u16 seqNo);
void StopSE(int seqNo, int a);
BOOL System_GetTouchNew(void);
void Heap_Free(void *ptr);

void *sub_020307F8(void);
u64 sub_0203088C(void *a, int b, int c);
void sub_0203A948(int a, int b);
int sub_0202FC48(void);
void sub_0202FC24(void);
void sub_020879E0(void *p, int a);
void sub_02087A08(void *p, int a, int b);
void sub_02087A84(void *p, int a, int b);

int ov39_0222774C(void *p, u32 lo, u32 hi);
int ov39_02227D44(void *p, u32 *out);
u64 ov39_02227FEC(void *p);
void ov39_022280D4(void *p, void *out);

void ov40_0222BF64(void *p, u32 value, BOOL valid, u32 *out);
void ov40_0222BF80(void *p, int value);
void ov40_0222D66C(void *dst, void *src, int a);
void ov40_0222D88C(void *p);
void ov40_0222D8C8(void *p);
int ov40_0222DA00(int *a, int *b, int c, int d);
int ov40_0222DA84(int *p, int direction);
void ov40_0222DAA8(void *p);
void ov40_0222DD08(void *p);
void ov40_0222DEAC(void *p);
void ov40_0222C4E8(void *p, u32 value);
void ov40_0222E79C(void *p, void *q);
void ov40_0222E7B8(void *p, void *q);
void ov40_0222E7DC(void *p, BOOL draw);
void ov40_0222F734(void *p);
void ov40_0222FB40(void *p);
void ov40_0222FB90(void *p, int a);
void *ov40_0222FBB4(void *p);
int ov40_0222FC14(void *p, u32 a, u32 b);
void ov40_0222FCCC(void *p);
void ov40_0222FDC4(void *p);
void ov40_02230638(void *p, void *q);
void ov40_0223064C(void *p, void *q);
void ov40_022306A0(void *p, BOOL draw);
void ov40_022306E0(void *p);
void ov40_0223077C(void *p, void *q, int a, int b);
void ov40_022307DC(void *p, int a, int b);
int ov40_02230410(void *p);
void ov40_02230964(void *p, void *value);
void *ov40_0223D540(void *p);
BOOL ov40_0223D5CC(void *p);

void ov40_02240910(void *p);
void ov40_02240E28(void *p, int a, int b);
void ov40_02240F24(void *p, int a, int b);
void ov40_02241054(void *p);
void ov40_02241114(void *p);
void ov40_02241A34(void *p);
void ov40_02241A54(void *p, int a);
void ov40_02241AB0(void *p);
void ov40_02241AFC(void *p);
void ov40_02241BDC(void *p);
/* --- round 6 additions --- */
void Sprite_DeleteAndFreeResources(void *sprite);
void ManagedSprite_SetPositionXY(void *sprite, s16 x, s16 y);
void ManagedSprite_SetDrawFlag(void *sprite, int draw);
void TextOBJ_SetSpritesDrawFlag(void *textOBJ, int draw);
void sub_020136B4(void *p, s32 a, s32 b);
u32 sub_02031620(void *card);
u32 sub_0203162C(void *card);

void ov40_0222D5AC(void *dst, void *src, int a);
void ov40_0222D6D0(void *p);
void ov40_0222D6EC(void *p, int a);
void ov40_0222D7DC(void *p);
void *ov40_0222D800(void *p, int a);
void ov40_0222DF60(void *p, int a);
void ov40_02230944(void *p);
int ov40_0223DB94(void *p);
void ov40_0223DDE8(void *p, u32 a, u32 b);
void ov40_0223DEB8(void *p);
int ov40_0223EBB8(void *p, u32 a);
void ov40_0223EC40(void *p, u32 a);

typedef void (*HitboxCallback)(u32 a, int b, void *p);
extern const u8 ov40_022456B4[];
extern const u8 ov40_02245674[];
extern const u8 ov40_02245654[];
void SetBgPriority(int bgId, int priority);
void *TouchHitboxController_Create(const void *hitboxes, int count, HitboxCallback cb, void *param, int heapId);
void ov40_0222C4B8(void *p);
void ov40_0222D9E8(int *a, int *b, int c);
void ov40_0224085C(void *p);
int ov40_02241488(void *p);
void ov40_0222C480(void *p);
void ov40_0222DED0(void *p, int a);
void ov40_0222DFB0(void *p);
void ov40_0222FB28(void *p, int a);
void ov40_02230CDC(void *p, int a, u32 b, u32 c);
void ov40_02242E4C(void *w, void *p);
int ov39_02227534(void *a, void *b);
BOOL sub_0202FC90(void *a, int b, int *c, void *d, int e);
void *sub_020314A4(int a);
void sub_020314BC(void *a);
void sub_020314C4(void *a, void *b);
int ov40_022417DC(void *p);
int ov40_022417A4(void *p);
int ov40_02241948(void *p);
void InitWindow(void *window);
void AddWindowParameterized(void *bgConfig, void *window, int bgId, int x, int y, int width, int height, int palette, int baseTile);
void FillWindowPixelBuffer(void *window, int fillValue);
void AddTextPrinterParameterizedWithColor(void *window, int fontId, void *str, int x, int y, int speed, u32 color, void *callback);
void ScheduleWindowCopyToVram(void *window);
void ClearWindowTilemapAndCopyToVram(void *window);
void RemoveWindow(void *window);
void String_Delete(void *str);
void *NewString_ReadMsgData(void *msgData, int msgId);
int ov40_022306C0(void *window, void *str);

void ov40_02241C10(u32 a, int b, void *p);
void ov40_02241C70(u32 a, int b, void *p);
void ov40_02241CD8(u32 a, int b, void *p);
void ov40_02241D10(u32 a, int b, void *p);
void ov40_02241E14(u32 a, int b, void *p);
void ov40_02241E40(u32 a, int b, void *p);
void ov40_02241ED4(u32 a, int b, void *p);
void ov40_02241F3C(u32 a, int b, void *p);
void ov40_02241F74(void *p, int a);
void ov40_02241FD0(void *p);
void ov40_02242084(void *p);
void ov40_022420B4(void *p, int a);
void ov40_02242110(void *p);
void ov40_022421FC(void *p);

BOOL ov40_0224222C(void *p);
BOOL ov40_02242378(void *p);
BOOL ov40_02242490(void *p);
BOOL ov40_0224253C(void *p);
int ov40_022425E8(void *p);
BOOL ov40_022428D4(void *p);
BOOL ov40_02242AEC(void *p);
BOOL ov40_02242CFC(void *p);
void ov40_02242DF0(void *p, u32 *flag);
void ov40_02242E14(void *p, u32 *flag);

#endif
