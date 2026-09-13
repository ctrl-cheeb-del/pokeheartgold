#ifndef TO41_OV40_R29U2_PRIVATE_H
#define TO41_OV40_R29U2_PRIVATE_H

#include "global.h"

#define PTR(p, off)  (*(void **)((u8 *)(p) + (off)))
#define WORD(p, off) (*(s32 *)((u8 *)(p) + (off)))

typedef struct Ov40WinTemplate {
    u8 x;
    u8 y;
    u8 width;
    u8 height;
} Ov40WinTemplate;

void TouchHitboxController_IsTriggered(void *controller);
void ManagedSprite_SetDrawFlag(void *sprite, BOOL draw);
void TextOBJ_SetSpritesDrawFlag(void *obj, BOOL draw);
void ManagedSprite_SetPositionXY(void *sprite, int x, int y);
void sub_020136B4(void *obj, int x, int y);
void InitWindow(void *window);
void AddWindowParameterized(void *bgConfig, void *window, int bgId, int x, int y, int width, int height, int palette, u16 baseTile);
void FillWindowPixelBuffer(void *window, u8 fill);
void ScheduleWindowCopyToVram(void *window);
void ClearWindowTilemapAndCopyToVram(void *window);
void RemoveWindow(void *window);
void *NewString_ReadMsgData(void *msgData, int msgId);
void *String_New(u32 maxLen, u32 heapId);
void String_Delete(void *string);
void *ov40_0222DAB0(u32 heapId);
void MessageFormat_Delete(void *format);
void CopyU16ArrayToString(void *string, const u16 *src);
void ov40_02230DCC(void *p, void *string);
void BufferString(void *format, int idx, void *string, int a, int b, int c);
void StringExpandPlaceholders(void *format, void *dst, void *src);
int ov40_022306C0(void *window, void *string);
void AddTextPrinterParameterizedWithColor(void *window, int fontId, void *string, int x, int y, int speed, u32 color, void *callback);
BOOL ov40_0222DA84(void *p, int a);
BOOL ov40_0222DA00(void *a, void *b, int c, int d);
void ov40_0222D980(void *a, void *b, int c, int d, int e, int f);
void *ov40_02230964(void *p, int a);
void ov40_02237564(void *p);
void ov40_02237410(void *p);
void GfGfx_EngineATogglePlanes(int plane, BOOL enable);
void GfGfx_EngineBTogglePlanes(int plane, BOOL enable);
void PaletteData_BlendPalettes(void *palette, int buffer, int count, int coeff, u16 color);
void sub_020879E0(void *p, int a);
void GfGfxLoader_LoadScrnDataFromOpenNarc(void *narc, int fileId, void *bgConfig, int bgId, int a, int b, int c, int heapId);
void ov40_0222BF80(void *p, int state);
void ov40_0222D874(void *p);
void ov40_0222FB90(void *p, int a);
BOOL ov40_0222FBB4(void *p);
void ov40_02230738(void *p);
void ov40_022364D0(void *p);

extern const Ov40WinTemplate ov40_022452B4[];
extern const Ov40WinTemplate ov40_022452DC[];
extern const u32 ov40_02245290[];

int ov40_022366CC(void *p);
void ov40_022368EC(void *p, int a);
int ov40_02236C64(void *p);
int ov40_02236D60(void *p);
int ov40_02236E18(void *p);
int ov40_02236A58(void *p);
void ov40_02236EB4(void *p);
void ov40_02236F38(void *p);
void ov40_02236FE0(void *p);
void ov40_02237008(void *p);
void ov40_02237030(void *p, int msgId);
void ov40_0223707C(void *p);
void ov40_02237144(void *p);
void ov40_022371A0(void *p);

#endif
