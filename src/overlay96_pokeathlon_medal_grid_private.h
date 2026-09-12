#ifndef OV96_R71_PRIVATE_H
#define OV96_R71_PRIVATE_H
#include "global.h"
#define U32AT(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define S32AT(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define U16AT(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U8AT(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define PAT(p, o)   (*(void **)((u8 *)(p) + (o)))

typedef struct Ov96R71Rect {
    s16 x;
    s16 y;
    s16 w;
    s16 h;
} Ov96R71Rect;

typedef struct Ov96R71Node {
    struct Ov96R71Node *prev;
    struct Ov96R71Node *next;
    u16 h8;
    u16 hA;
    u16 hC;
    u16 hE;
    u32 w10;
} Ov96R71Node;

typedef struct Ov96R71Tbl3 {
    s32 v[3];
} Ov96R71Tbl3;

#define OV96_R71_INS(a, b) \
    (b)->prev->next = (a); \
    (a)->prev = (b)->prev; \
    (a)->next = (b);       \
    (b)->prev = (a)

extern void GF_AssertFail(void);
extern void *Heap_Alloc(u32 heapId, u32 size);

extern void AddWindow(void *, void *, const void *);
extern void BG_FillCharDataRange(void *, u32, u32, u32, u32);
extern void LoadFontPal0(u32, u32, void *);
extern void FillWindowPixelBuffer(void *, u32);
extern void Sprite_SetAnimCtrlSeq(void *, u32);
extern void sub_0200606C(u32, u32);
extern void sub_020061D0(u32, s32);
extern u32 ov96_021E5F24(void *);
extern void ov96_021E8228(void *, u32, u32, u32, u32);
extern void ov96_021EAE9C(void *, void *, void *);
extern void ov96_021FC0FC(void *, void *);
extern void ov96_021EB10C(void *, f32, f32);
extern void *NewMsgDataFromNarc(u32, u32, u32, void *);
extern void *MessageFormat_New(void *);
extern void BufferIntegerAsString(void *, u32, s32, u32, u32, u32);
extern void *ReadMsgData_ExpandPlaceholders(void *, void *, u32, void *);
extern void AddTextPrinterParameterizedWithColor(void *, u32, void *, s32, s32, u32, u32, u32);
extern void String_Delete(void *);
extern void MessageFormat_Delete(void *);
extern void DestroyMsgData(void *);
extern void CopyWindowToVram(void *);
extern const Ov96R71Tbl3 ov96_0221C41C;
extern const Ov96R71Tbl3 ov96_0221C428;
extern s32 LCRandom(void);
extern void ov96_021FC698(void *, u32, VecFx32 *);
extern const u8 ov96_0221C3FC[];
extern u8 ov96_0221DC2C[];
extern const s8 ov96_0221DC28[];

void ov96_021FA7BC(void *, u32, u32, void *);
u32 ov96_021FAAE0(s32, s32, const Ov96R71Rect *);
u32 ov96_021FAB04(s32, const Ov96R71Rect *);
u32 ov96_021FB514(Ov96R71Node *, Ov96R71Node *);
u32 ov96_021FB56C(Ov96R71Node *, Ov96R71Node *);
u32 ov96_021FB60C(u8 *);
void ov96_021FB6B4(void *, void *);
void ov96_021FB6C8(void *, u8 *);
u8 ov96_021FB784(void *, s32, s32);
void ov96_021FB7C8(void *);
void ov96_021FB808(void *, s32);
void ov96_021FB8B4(void *, s32);
void ov96_021FB8FC(u8 *, u32);
void ov96_021FB994(u8 *);
void ov96_021FBDBC(u8 *);
s32 ov96_021FBDEC(s32);
void *ov96_021FBE20(u32, u32);
#endif
