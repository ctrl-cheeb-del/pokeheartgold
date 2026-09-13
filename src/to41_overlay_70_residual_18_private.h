#ifndef OV70_R18_PRIVATE_H
#define OV70_R18_PRIVATE_H
#include "global.h"

typedef u8 R14Work;
#define P(w, o)   (*(void **)((u8 *)(w) + (o)))
#define U8(w, o)  (*(u8 *)((u8 *)(w) + (o)))
#define U16(w, o) (*(u16 *)((u8 *)(w) + (o)))
#define U32(w, o) (*(u32 *)((u8 *)(w) + (o)))
#define S32(w, o) (*(s32 *)((u8 *)(w) + (o)))

extern void BeginNormalPaletteFade(u32, u32, u32, u32, u32, u32, u32);
extern BOOL IsPaletteFadeFinished(void);
extern void Sprite_SetDrawFlag(void *, int);
extern void Sprite_SetAnimCtrlSeq(void *, int);
extern BOOL TextPrinterCheckActive(u8);
extern void YesNoPrompt_Destroy(void *);
extern void ClearFrameAndWindow2(void *, BOOL);
extern void ClearWindowTilemapAndCopyToVram(void *);
extern void RemoveWindow(void *);
extern void FillWindowPixelBuffer(void *, u8);
extern void DrawFrameAndWindow2(void *, BOOL, u16, u8);
extern u8 AddTextPrinterParameterized(void *, int, void *, u32, u32, u32, void *);
extern void ReadMsgDataIntoString(void *, u32, void *);
extern void *NewString_ReadMsgData(void *, u32);
extern void String_Delete(void *);
extern void *String_New(u32, u32);
extern void PlaySE(u32);
extern void AddWindowParameterized(void *, void *, u32, u32, u32, u32, u32, u16);
extern void MessageFormat_ResetBuffers(void *);
extern void BufferCountryName(void *, u32, u32);
extern void BufferCityName(void *, u32, u32, u32);
extern void *ReadMsgData_ExpandPlaceholders(void *, void *, u32, u32);
extern void GfGfxLoader_LoadScrnData(u32, u32, void *, u32, u32, u32, u32, u32);
extern void BgSetPosTextAndCommit(void *, u32, u32, u32);
extern void ov70_0223F20C(void *, void *, s16, u32, u32);
extern void ov70_0223F324(void *, void *, s8, u32, u32, u32, u32);
extern int ov70_0223F864(s8, s8, u32);
extern void ov70_0223F38C(void *, void *, int, u32, u32, u32, u32, u32);
extern void ov70_02241234(R14Work *);
extern void *ov70_02238C2C(void *, int, int, int, int, int);
extern int ov70_02238C8C(R14Work *);
extern void ov70_02238D84(R14Work *, int, int);
extern void ov70_02238E50(R14Work *, int, int);
extern void ov70_02241330(R14Work *, int, int);
extern int ov70_02241164(void *);
extern int TouchscreenHitbox_FindRectAtTouchNew(const void *);
extern void ov70_02245084(void *, void *, int, int, int, int);
extern void ov70_022450B8(void *, void *, int, int, int, int);
extern const u8 ov70_022454A4[];
extern const u8 ov70_022454A5[];
extern const u8 ov70_02245498[];
typedef struct Ov70WinTmpl {
    u32 bg;
    u32 x;
    u32 y;
    u32 w;
    u32 h;
} Ov70WinTmpl;
extern const Ov70WinTmpl ov70_022454EC[];

void ov70_0223ACF4(R14Work *);
void ov70_0223AE40(R14Work *);
void ov70_0223AF30(R14Work *);
int ov70_0223AF5C(R14Work *);
void ov70_0223AFA8(R14Work *, int);
int ov70_0223AFFC(R14Work *);
int ov70_0223B12C(R14Work *);
int ov70_0223B188(R14Work *);
int ov70_0223B1B8(R14Work *);
void ov70_0223B258(R14Work *);
int ov70_0223B2C0(R14Work *);
int ov70_0223B2D0(R14Work *);
int ov70_0223B300(R14Work *);
int ov70_0223B344(R14Work *);
void ov70_0223B364(R14Work *, u32, u32);
void ov70_0223B3BC(void *, void *, u32);
void ov70_0223B3EC(void *, void *, u32);
void ov70_0223B41C(void *, void *, void *, void *);
void ov70_0223B484(void *, void *, void *);
void ov70_0223B4D4(R14Work *);

extern void Sprite_Delete(void *);
extern void FreeBgTilemapBuffer(void *, int);
extern void *Heap_Alloc(u32, u32);
extern void Heap_Free(void *);
extern void ov70_022392BC(void *);
extern void ov70_02238E58(R14Work *);
extern void *ov70_02238C14(void *, int, int, int, int);
extern void ov70_0224212C(void *);
extern void ov70_022420C4(void *, int);
extern void ov70_0223CD28(int);
extern void ov70_0223CAC4(R14Work *, int, int, int, int);
extern void *ov70_0223F684(u32);
extern void ov70_0223F948(void *);
extern const u8 ov70_022456C8[];
int ov70_0223B788(R14Work *);
void ov70_0223B8B4(void *);
void ov70_0223BAAC(R14Work *);
void ov70_0223BC2C(R14Work *);
void ov70_0223BC7C(R14Work *);
void ov70_0223BCD0(R14Work *);
int ov70_0223BD04(R14Work *);
int ov70_0223BD80(void);
u8 *ov70_0223C2EC(R14Work *);
int ov70_0223C23C(R14Work *);
int ov70_0223C19C(R14Work *);
int ov70_0223C1F8(R14Work *);
int ov70_0223C274(R14Work *);
int ov70_0223C2B0(R14Work *);
int ov70_0223C4E4(R14Work *);
int ov70_0223C4B0(R14Work *);
int ov70_0223C50C(R14Work *);
int ov70_0223C618(R14Work *);
int ov70_0223C640(R14Work *);
int ov70_0223C6F0(R14Work *);
int ov70_0223C718(R14Work *);
int ov70_0223C7C4(R14Work *);
int ov70_0223C7EC(R14Work *);
int ov70_0223C8B0(R14Work *);
int ov70_0223C8DC(R14Work *);

#endif
