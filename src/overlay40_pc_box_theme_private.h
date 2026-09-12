#ifndef OV40_RESIDUAL_32_PRIVATE_H
#define OV40_RESIDUAL_32_PRIVATE_H

#include "global.h"

#define PTR(p, off)  (*(void **)((u8 *)(p) + (off)))
#define WORD(p, off) (*(u32 *)((u8 *)(p) + (off)))
#define S32(p, off)  (*(s32 *)((u8 *)(p) + (off)))

typedef void (*Ov40HitboxCb)(u32 sel, int flag, void *scene);

typedef struct Ov40WinTemplate {
    u32 x;
    u32 y;
    u32 width;
    u32 height;
} Ov40WinTemplate;

typedef struct Ov40Blob44 {
    u32 v[11];
} Ov40Blob44;

typedef struct Ov40Blob12 {
    u32 v[3];
} Ov40Blob12;

void *Heap_Alloc(u32 heapId, u32 size);
void Heap_Free(void *ptr);
void GF_AssertFail(void);
void MI_CpuCopy8(const void *src, void *dst, u32 size);

void InitWindow(void *window);
void RemoveWindow(void *window);
void ClearWindowTilemapAndCopyToVram(void *window);
void AddWindowParameterized(void *bgConfig, void *window, u8 bgId, u8 x, u8 y, u8 width, u8 height, u8 paletteNum, u16 baseTile);
void FillWindowPixelBuffer(void *window, u8 fillValue);
void ScheduleWindowCopyToVram(void *window);
void AddTextPrinterParameterizedWithColor(void *window, int fontId, void *str, int x, int y, int speed, u32 color, void *callback);
void BgClearTilemapBufferAndCommit(void *bgConfig, u32 bgId);
void SetBgPriority(u8 bgId, u16 priority);
void GfGfx_EngineATogglePlanes(int planes, int enable);
void GfGfx_EngineBTogglePlanes(int planes, int enable);
void GfGfxLoader_LoadCharDataFromOpenNarc(void *narc, u32 member, void *bgConfig, u32 bgId, u32 a4, u32 a5, u32 a6, u32 heapId);
void GfGfxLoader_LoadScrnDataFromOpenNarc(void *narc, u32 member, void *bgConfig, u32 bgId, u32 a4, u32 a5, u32 a6, u32 heapId);
void PaletteData_BlendPalettes(void *data, int bufferId, u16 selectedBuffer, u8 cur, u16 target);

void *NewString_ReadMsgData(void *msgData, u32 strno);
void *String_New(u32 size, u32 heapId);
void StringExpandPlaceholders(void *msgFmt, void *dst, void *src);
void CopyU16ArrayToString(void *str, const u16 *src);
void BufferString(void *msgFmt, u32 idx, void *str, u32 a3, u32 a4, u32 a5);
void BufferMonthNameAbbr(void *msgFmt, u32 idx, u32 month);
void MessageFormat_ResetBuffers(void *msgFmt);
void MessageFormat_Delete(void *msgFmt);
void GetSpeciesNameIntoArray(u32 species, u32 heapId, u16 *dst);
void *sub_020315B8(void *p, u32 heapId);
u32 sub_020315E0(void *p);
u32 sub_02031610(void *p);
u32 sub_020316F0(void *p);
u32 sub_02031700(void *p);
void *ov40_0222DAB0(u32 heapId);
void ov40_02230DCC(void *p, void *str);
void String_Delete(void *str);

void Sprite_DeleteAndFreeResources(void *sprite);
void ManagedSprite_SetDrawFlag(void *sprite, BOOL draw);
void ManagedSprite_SetPositionXY(void *sprite, s16 x, s16 y);
void TextOBJ_SetSpritesDrawFlag(void *obj, BOOL draw);
void sub_020136B4(void *p, s32 a, s32 b);

void *TouchHitboxController_Create(const void *hitboxes, int numTemplates, Ov40HitboxCb cb, void *arg, int heapId);
void TouchHitboxController_Destroy(void *controller);
void TouchHitboxController_IsTriggered(void *controller);

void *Save_GameStats_Get(void *saveData);
u32 GameStats_GetCapped(void *gameStats, int statIdx);

int sub_02087E1C(void *p);
BOOL sub_020879E0(void *p, int flag);

void *ov39_02227F14(void *a, void *b, int c);

void ov40_0222BF64(void *p, u32 value, BOOL valid, u32 *out);
void ov40_0222BF80(void *p, int value);
void ov40_0222D5AC(void *dst, void *src, int a);
void ov40_0222D66C(void *dst, void *src, int a);
void ov40_0222D6D0(void *p);
void ov40_0222D73C(void *p, int a);
void ov40_0222D7DC(void *p);
void *ov40_0222D800(void *p, int a);
void ov40_0222D874(void *p);
void ov40_0222D88C(void *p);
void ov40_0222D9E8(void *a, void *b, int c);
int ov40_0222DA00(void *a, void *b, int c, int d);
int ov40_0222DA84(void *p, int a);
void ov40_0222DAA8(void *p);
void ov40_0222DD08(void *p);
u32 ov40_0222E658(u32 a, int b);
void ov40_0222EB9C(void *a, void *b, u32 c, void *d, u32 e, u32 f, void *g);
void ov40_0222F09C(void *a, void *b, u32 c, u32 d, void *e);
void ov40_0222F6D0(void *p, s16 a);
void ov40_0222F720(void *p);
void ov40_0222F734(void *p);
void ov40_0222F740(void *p, void *q, int a);
void ov40_0222F858(void *p, int y1, int y2);
void ov40_0222F920(void *p, void *q);
void ov40_0222F9E0(void *p, void *q, int a);
void ov40_0222FA24(void *p);
void ov40_0222FA5C(void *p, void *q);
void ov40_0222FA88(void *p);
void ov40_0222FB90(void *p, int a);
void *ov40_0222FBB4(void *p);
void ov40_02230944(void *p);
void ov40_02230964(void *p, int value);
int ov40_022306C0(void *window, void *str);
void *ov40_0223D540(void *p);

extern const Ov40Blob12 ov40_022453A0;
extern const u8 ov40_022453AC[];
extern const Ov40WinTemplate ov40_022453B8[];
extern const Ov40WinTemplate ov40_022453D8[];
extern const Ov40WinTemplate ov40_022453F8[];
extern const Ov40Blob44 ov40_02245418;
extern const Ov40Blob44 ov40_02245444;
extern u32 ov40_02245CE8[];

/* module-local */
void ov40_02238EBC(void *p, u32 *a);
void ov40_02238F00(void *p);
void ov40_02238FF4(void *p);
void ov40_02239340(void *p);
void ov40_022393F4(void *p);
void ov40_02239418(void *p);
void ov40_02239514(void *p);
u32 ov40_02239538(void *p, int idx);
void ov40_02239574(void *p);
void ov40_022397BC(void *p, int a);
void ov40_02239838(void *p);
void ov40_022398F8(void *p);
void ov40_0223992C(void *p);
void ov40_02239954(u32 sel, int flag, void *scene);
int ov40_022399B8(void *p);
int ov40_02239A58(void *p);
int ov40_02239B58(void *p);
int ov40_02239EFC(void *p);
int ov40_0223A034(void *p);
int ov40_0223A080(void *p);
int ov40_0223A158(void *p);

#endif
