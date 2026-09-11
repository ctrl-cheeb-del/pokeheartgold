#ifndef OVERLAY40_TRAINER_CARD_PANELS_H
#define OVERLAY40_TRAINER_CARD_PANELS_H

#include "global.h"

#define PTR(p, off)  (*(void **)((u8 *)(p) + (off)))
#define WORD(p, off) (*(u32 *)((u8 *)(p) + (off)))
#define HALF(p, off) (*(u16 *)((u8 *)(p) + (off)))
#define BYTE(p, off) (*(u8 *)((u8 *)(p) + (off)))

#define BLEND(p, w, a, b) \
    PaletteData_BlendPalettes(PTR(p, 0x28), a, b, (u8)WORD(w, 8), (u16)WORD(p, 0x58))

typedef struct Ov40Window {
    u32 raw[4];
} Ov40Window;

typedef struct Ov40Quad {
    u32 v[4];
} Ov40Quad;

void PaletteData_BlendPalettes(void *palette, int a, int b, int coeff, int color);
void BgClearTilemapBufferAndCommit(void *bgConfig, int bgId);
void GfGfx_EngineATogglePlanes(int mask, int enable);
void GfGfx_EngineBTogglePlanes(int mask, int enable);
void TouchHitboxController_Destroy(void *controller);
void TouchHitboxController_IsTriggered(void *controller);
void Heap_Free(void *ptr);
BOOL System_GetTouchNew(void);

void InitWindow(void *window);
void AddWindowParameterized(void *bgConfig, void *window, int bgId, int x, int y, int width, int height, int palette, int baseTile);
void AddTextWindowTopLeftCorner(void *bgConfig, void *window, int width, int height, int a, int b);
void FillWindowPixelBuffer(void *window, int fillValue);
void AddTextPrinterParameterizedWithColor(void *window, int fontId, void *str, int x, int y, int speed, u32 color, void *callback);
void ScheduleWindowCopyToVram(void *window);
void RemoveWindow(void *window);
void TextOBJ_CopyFromBGWindow(void *a, void *b, void *window, int heapId);

void *String_New(u32 size, u32 heapId);
void String_Delete(void *str);
void *NewString_ReadMsgData(void *msgData, int msgId);
void BufferString(void *fmt, u32 fieldno, void *str, int a3, int a4, int a5);
void StringExpandPlaceholders(void *fmt, void *dst, void *src);
void MessageFormat_Delete(void *fmt);

void ManagedSprite_SetPositionXY(void *sprite, s16 x, s16 y);
void ManagedSprite_SetAnim(void *sprite, int anim);
void Sprite_DeleteAndFreeResources(void *sprite);
void TextOBJ_SetSpritesDrawFlag(void *textOBJ, int draw);
void sub_020136B4(void *p, s32 a, s32 b);

void *sub_020307F8(void);
u64 sub_0203088C(void *a, int b, int c);
void *sub_020315B8(u32 a, int heapId);
int sub_0202FC48(void);
void sub_0202FC24(void);

void *ov40_0222DAB0(int heapId);
void ov40_0222BF64(void *p, u32 value, BOOL valid, u32 *out);
void ov40_0222BF80(void *p, int value);
void ov40_0222C6C8(void *p, int a);
void ov40_0222D5AC(void *dst, void *src, int a);
void ov40_0222D66C(void *dst, void *src, int a);
void ov40_0222D6D0(void *p);
void ov40_0222D78C(void *p, int a);
void *ov40_0222D800(void *p, int a);
void ov40_0222D7DC(void *p);
void ov40_0222D88C(void *p);
int ov40_0222DA00(int *a, int *b, int c, int d);
int ov40_0222DA84(int *p, int direction);
void ov40_0222DAA8(void *p);
void ov40_0222DD08(void *p);
void ov40_0222DED0(void *p, int a);
void ov40_0222DFB0(void *p);
void ov40_0222E7B8(void *p, void *q);
void ov40_0222FB90(void *p, int a);
void *ov40_0222FBB4(void *p);
void ov40_0223064C(void *p, void *q);
void ov40_02230964(void *p, void *value);
void ov40_02230DCC(void *p, void *str);
BOOL ov40_02230D94(void *p, u64 v);
void ov40_02241A34(void *p);
void ov40_022421FC(void *p);
BOOL ov40_0224222C(void *p);
BOOL ov40_02242378(void *p);
BOOL ov40_02242490(void *p);
BOOL ov40_0224253C(void *p);
BOOL ov40_022428D4(void *p);
BOOL ov40_02242AEC(void *p);
BOOL ov40_02242CFC(void *p);

extern const Ov40Quad ov40_02245684;
extern const Ov40Quad ov40_02245694;

void ov40_02240910(void *p);
void ov40_02240D50(void *obj, void *p, int idx);
void ov40_02240E28(void *p, int msgId, int unused);
void ov40_02240F24(void *p, int msgId, int idx);
void ov40_02241054(void *p);
void ov40_02241114(void *p);

int ov40_02240B40(void *p);
int ov40_02240B58(void *p);
int ov40_02240B70(void *p);
int ov40_02240B90(void *p);

#endif
