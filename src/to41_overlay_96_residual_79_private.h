#ifndef OV96_R79_PRIVATE_H
#define OV96_R79_PRIVATE_H
#include "global.h"

#include "constants/heap.h"

/* ---- house style borrowed verbatim from the overlay_96 matched corpus ---- */
#define U8P(p, o)  ((u8 *)(p) + (o))
#define PTR(p, o)  (*(void **)((u8 *)(p) + (o)))
#define WORD(p, n) (*(u32 *)((u8 *)(p) + (n)))
#define HALF(p, n) (*(u16 *)((u8 *)(p) + (n)))
#define BYTE(p, n) (*(u8 *)((u8 *)(p) + (n)))

extern void GF_AssertFail(void);
extern void sub_0200606C(u16 a, int b);
extern void ov96_021EB630(void *p, int v);
extern void ov96_021EB52C(void *p, int a, int b);
extern void ov96_021EB564(void *p, int v);
extern void ov96_021EB588(void *p, const void *v);
extern void *ov96_021EB594(void *p);
extern void *ov96_021EB5B8(void *p);
extern void ov96_021EABA8(void *p, u32 v);
extern void ov96_021EAB38(void *p, int v);
extern void AddWindow(void *bgConfig, void *window, const void *tmpl);
extern void BG_FillCharDataRange(void *bgConfig, u32 bgId, u32 fillValue, u32 ntiles, u32 offset);
extern void LoadFontPal0(int a, int b, enum HeapID heapId);
extern void FillBgTilemapRect(void *bgConfig, u32 bgId, u32 fill, u32 x, u32 y, u32 width, u32 height, u32 palette);
extern void ScheduleBgTilemapBufferTransfer(void *bgConfig, u32 bgId);
extern void Sprite_SetPaletteOverride(void *sprite, int index);
extern const u8 ov96_0221C5C4[];
extern void *PokeathlonCourse_GetDataCopyArea(void *);
extern void *PokeathlonCourse_GetHeapAllocPtr4(void *);
extern void *ov96_021E8A20(void *);
extern int ov96_021E5F24(void *);
extern void ov96_021E8318(void *p, u16 v);
extern void ov96_021FFD80(void *p, int a, int b);
extern float _ffltu(u32);
extern void Heap_Free(void *p);
extern void String_Delete(void *p);
extern void MessageFormat_Delete(void *p);
extern void DestroyMsgData(void *p);
extern void RemoveWindow(void *p);
extern void Sprite_SetAnimCtrlSeq(void *sprite, int seq);
extern void GfGfxLoader_LoadCharData(int narcId, s32 memberNo, void *bgConfig, u32 layer, u32 tileStart, u32 szByte, BOOL isCompressed, u32 heapId);
extern void GfGfxLoader_LoadScrnData(int narcId, s32 memberNo, void *bgConfig, u32 layer, u32 tileStart, u32 szByte, BOOL isCompressed, u32 heapId);
extern void *GfGfxLoader_GetScrnData(int narcId, s32 memberNo, BOOL isCompressed, void *ppScrnData, u32 heapId);
extern void GfGfxLoader_GXLoadPal(int narcId, s32 memberNo, u32 location, u32 palSlotOffset, u32 szByte, u32 heapId);
extern void ov96_021EB2BC(void *p, s32 a, s32 b, s32 c, s32 d);
extern void ov96_021EB2F4(void *p, s32 a, s32 b, s32 c, s32 d, s32 e);
extern void ov96_021EB334(void *p, s32 a, s32 b, s32 c);
extern void ov96_021EB36C(void *p, s32 a, s32 b, s32 c);
extern u32 ov96_0221C728[];
extern fx32 FX_Sqrt(fx32 x);
extern fx32 VEC_DotProduct(const VecFx32 *a, const VecFx32 *b);

void ov96_021FFE38(int a, int b, int c);
BOOL ov96_021FF574(const s32 *a, const s32 *b);
void ov96_021FFD4C(void *w);
void ov96_021FFB44(void *w);
void ov96_02200A18(void *w, int a, int b);
BOOL ov96_02200900(void *w, u32 n);
float ov96_021FF6DC(void *w, int i);
void ov96_021FFEE8(void *p);
void ov96_02200454(void *w, u32 a, u32 b);
void ov96_021FF72C(const VecFx32 *a, const VecFx32 *b, VecFx32 *out);
void ov96_021FFAEC(void *w, const VecFx32 *src, void *sprite);
void ov96_022004B4(void *w, int i, int j);
void ov96_021FFBD8(void *bgConfig, int v);
void ov96_021FFB7C(u8 *w, int a, int b);
void ov96_021FFFE8(void *w);
void ov96_02200A64(void *w, int v);
void ov96_02200068(void *w);
void ov96_022000E4(int unused, void *p);
fx32 ov96_021FF67C(const VecFx32 *a, const VecFx32 *b, const VecFx32 *c, fx32 r);
void ov96_021FEE60(void *w, int unused, int i, void *p, BOOL flag, int x);

/* ---- round-4 additions ---- */
typedef struct Ov96PokepicTemplate {
    u16 narcID;
    u16 charDataID;
    u16 palDataID;
    u16 species;
    u8 isAnimated;
    u8 filler_9[3];
    u32 personality;
} Ov96PokepicTemplate;

typedef struct Ov96ParticipantView {
    u16 species;
    u16 field2;
    u16 special;
    u8 kind;
    u8 field7;
    u32 participant;
    u32 fieldC;
} Ov96ParticipantView;

typedef struct Ov96Slot20 {
    void *unk48;
    void *unk4C;
    void *unk50;
    void *unk54;
    u8 unk58;
    u8 pad59[15];
} Ov96Slot20;

#define SLOT20(w) ((Ov96Slot20 *)((u8 *)(w) + 0x48))

typedef struct Ov96Rec1C {
    u32 f0;
    float f4;
    float f8;
    float fC;
    float f10;
    float f14;
    u8 f18;
    u8 f19;
    u8 f1A;
    u8 f1B;
} Ov96Rec1C;

typedef struct Ov96Out {
    u8 pad[0x14];
    Ov96Rec1C recs[1];
} Ov96Out;

extern void *Heap_Alloc(u32 heapId, u32 size);
extern void ov96_02200DF8(void *w);
extern void *NewMsgDataFromNarc(u32 kind, u32 narcId, u32 msgId, u32 heapId);
extern void *MessageFormat_New(u32 heapId);
extern void *String_New(u32 size, u32 heapId);
extern void CopyU16ArrayToString(void *str, const u16 *src);
extern void ov96_02200BD8(void *w, int a);
extern void ov96_02200C40(void *w);
extern u8 *PokeathlonCourse_GetParticipantUnk04(void *data, int index);
extern void FillWindowPixelBuffer(void *window, int fillValue);
extern void BufferIntegerAsString(void *fmt, u32 idx, s32 num, u32 digits, u32 mode, u32 charset);
extern void *ReadMsgData_ExpandPlaceholders(void *fmt, void *msgData, u32 msgno, u32 heapId);
extern void AddTextPrinterParameterizedWithColor(void *window, int fontId, void *str, int x, int y, int speed, u32 colors, void *cb);
extern void CopyWindowToVram(void *window);
extern u8 *ov96_021E60D8(void *a, int b, int c);
extern void GetMonSpriteCharAndPlttNarcIdsEx(Ov96PokepicTemplate *tmpl, u16 species, u8 gender, u8 whichFacing, u8 shiny, u8 form, u32 personality);
extern void *sub_0201457C(int narcId, s32 fileId, u32 heapId, u32 personality, int isAnimated, int whichFacing, int species);
extern void *sub_02014450(int narcId, s32 fileId, u32 heapId);
extern void Sprite_SetDrawPriority(void *sprite, int priority);
extern const VecFx32 ov96_0221C748;
extern const VecFx32 ov96_0221C754;

void ov96_021FFE5C(void *w, int i, int c);
void ov96_022003E8(void *w, const Ov96ParticipantView *e);
void *ov96_021FFF3C(u32 heapId, void *a2, void *a3);
void ov96_021FFD80(void *w, int a, int b);
void ov96_0220050C(void *w, int i, int a);
void ov96_021FEFE8(void *a, const int (*tbl)[5], int b, int n, Ov96Out *out);
void ov96_021FF1E0(s32 d, const void *src, s32 *out);
void ov96_02200B04(void *w, int n);
void ov96_02200950(void *w, int i, int a, int b, int c);
void ov96_022002F8(void *w, const u16 *e);
extern void *NARC_New(u32 narcId, u32 heapId);
extern void NARC_ReadWholeMember(void *narc, u32 member, void *dest);
extern void NARC_Delete(void *narc);
extern void *Heap_AllocAtEnd(u32 heapId, u32 size);
extern u32 GetMonIconNaixEx(u32 species, BOOL isEgg, u32 form);
extern u32 GetMonIconPaletteEx(u32 species, u32 form, u32 c);
extern u32 sub_02074490(void);

#endif

typedef struct Ov96SlotRec {
    void *a;
    void *b;
    void *c;
    void *d;
    u8 e;
    u8 recpad[0xf];
} Ov96SlotRec;

typedef struct Ov96SlotWork {
    u8 wpad[0x48];
    Ov96SlotRec slots[4];
} Ov96SlotWork;

typedef struct Ov96P20 {
    void *p;
    u8 p20pad[0x1c];
} Ov96P20;
typedef struct Ov96B20 {
    u8 b;
    u8 b20pad[0x1f];
} Ov96B20;
#define A48(w) ((Ov96P20 *)((u8 *)(w) + 0x48))
#define A4C(w) ((Ov96P20 *)((u8 *)(w) + 0x4c))
#define A50(w) ((Ov96P20 *)((u8 *)(w) + 0x50))
#define A58(w) ((Ov96B20 *)((u8 *)(w) + 0x58))
