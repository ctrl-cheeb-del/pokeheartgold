#include "global.h"

#define PTR(p, off)  (*(void **)((u8 *)(p) + (off)))
#define WORD(p, off) (*(u32 *)((u8 *)(p) + (off)))
#define BYTE(p, off) (*(u8 *)((u8 *)(p) + (off)))

typedef struct Ov40PositionTable {
    s16 xy[30][2];
} Ov40PositionTable;

extern Ov40PositionTable ov40_0224557C;

void ManagedSprite_SetPositionXY(void *sprite, s16 x, s16 y);
void ManagedSprite_SetAnim(void *sprite, int anim);
void TextOBJ_SetSpritesDrawFlag(void *obj, BOOL draw);
void sub_020136B4(void *obj, int x, int y);
void ov40_0222D6EC(void *p, int which);
void *ov40_0222D800(void *p, int which);
void ov40_0222D5AC(void *dst, void *src, int id);
void ov40_0222D66C(void *dst, void *src, int id);
void ov40_0223B4BC(void *p, int value);

void *ov40_0222DAB0(int heapId);
void *String_New(u32 maxLength, int heapId);
void *sub_020315B8(u32 value, int heapId);
void ov40_02230DCC(void *p, void *value);
void *NewString_ReadMsgData(void *msgData, int msgId);
void BufferString(void *messageFormat, u32 idx, void *string, u32 a3, u32 a4, u32 a5);
void StringExpandPlaceholders(void *messageFormat, void *dest, void *src);
void String_Delete(void *string);
void MessageFormat_Delete(void *messageFormat);
void FillWindowPixelBuffer(void *window, u8 fillValue);
u8 AddTextPrinterParameterizedWithColor(void *window, int fontId, void *string, u32 x, u32 y, u32 textSpeed, u32 color, void *callback);
void ScheduleWindowCopyToVram(void *window);
BOOL ov40_0223D5CC(void *p);
void BgClearTilemapBufferAndCommit(void *bgConfig, int bgId);
void ov40_022306A0(void *obj, int value);
void ov40_0222E7DC(void *obj, int value);
int ov40_0222DA84(int *p, int direction);
BOOL ov40_0222DA00(int *a, int *b, int c, int d);
void PaletteData_BlendPalettes(void *palette, int buffer, int mask, int coeff, int color);
void ov40_0222DED0(void *p, int msgId);
void ov40_0223077C(void *p, void *obj, int x, int y);
void sub_020879E0(void *obj, int value);
void sub_02087A08(void *obj, int x, int y);
void PlaySE(u16 seqNo);
void StopSE(u16 seqNo, int fadeFrames);
void *ov40_0223D540(void *p);
BOOL ov39_02227720(void *result, void *a, void *b);
BOOL ov39_02227D44(void *p, void **result);
void ov40_0222DFB0(void *p);
void ov40_02230CDC(void *p, int kind, u32 a, u32 b);
void MI_CpuCopy8(const void *src, void *dest, u32 size);
void ov40_0222BF80(void *p, int state);
void ov40_0222FC40(void *p, int value);

void ov40_0223A3BC(void *p);
void ov40_0223A430(void *p);
void ov40_0223A510(void *p, int msgId, int index);
int ov40_0223A640(void *p);
