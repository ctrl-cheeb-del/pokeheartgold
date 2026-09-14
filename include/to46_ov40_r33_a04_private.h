#include "global.h"

#define PTR(p, off)  (*(void **)((u8 *)(p) + (off)))
#define WORD(p, off) (*(u32 *)((u8 *)(p) + (off)))

void TouchHitboxController_Destroy(void *);
void GfGfx_EngineBTogglePlanes(int, BOOL);
void GfGfx_EngineATogglePlanes(int, BOOL);
void ov40_0223A83C(void *);
void ov40_02230964(void *, int);
void ov40_0223064C(void *, void *);
void ov40_0222E7B8(void *, void *);
int ov40_0222DA84(void *, int);
BOOL ov40_0222DA00(void *, void *, int, int);
void ov40_0222D66C(void *, void *, int);
void ManagedSprite_SetAnim(void *, int);
void ov40_0223B4BC(void *, int);
void PaletteData_BlendPalettes(void *, int, int, int, int);
void ov40_0222BF80(void *, int);
void *NewString_ReadMsgData(void *, int);
void *ov40_0222DAB0(int);
void *sub_020315B8(u32, int);
void ov40_02230DCC(void *, void *);
void *String_New(int, int);
void BufferString(void *, int, void *, int, int, int);
void StringExpandPlaceholders(void *, void *, void *);
void String_Delete(void *);
void MessageFormat_Delete(void *);
void InitWindow(void *);
void AddTextWindowTopLeftCorner(void *, void *, int, int, int, int, int);
u8 AddTextPrinterParameterizedWithColor(void *, int, void *, int, int, int, u32, void *);
void TextOBJ_CopyFromBGWindow(void *, void *, void *, int);
void RemoveWindow(void *);
void ov40_0222D78C(void *, int);
void *ov40_0222D800(void *, int);
void ov40_0222D5AC(void *, void *, int);
void ManagedSprite_SetPositionXY(void *, s16, s16);
void sub_020136B4(void *, int, int);
void TextOBJ_SetSpritesDrawFlag(void *, BOOL);
void ov40_0222D6D0(void *);
void Sprite_DeleteAndFreeResources(void *);
void ov40_0222D7DC(void *);
void BgClearTilemapBufferAndCommit(void *, int);
void ov40_0223A430(void *);
void ov40_0223CD14(void *);
void ov40_02230638(void *, void *);
void ov40_022306A0(void *, int);
int ov40_02230410(void *);
void ov40_022307DC(void *, int, int);
void ov40_0222E79C(void *, void *);
void ov40_0222E7DC(void *, int);
void GfGfxLoader_LoadCharDataFromOpenNarc(void *, int, void *, int, int, int, int, int);
void GfGfxLoader_LoadScrnDataFromOpenNarc(void *, int, void *, int, int, int, int, int);
typedef struct FourInts {
    int v[4];
} FourInts;
typedef struct Ov40Entry {
    u8 raw[0xe4];
} Ov40Entry;
typedef struct Ov40Outer {
    u8 pad[0x2608];
    Ov40Entry *ptrs[30];
    Ov40Entry entries[30];
    int count;
} Ov40Outer;
extern const FourInts ov40_022454C0;
extern const FourInts ov40_022454D0;
int ov40_0223AF3C(void *);
int ov40_0223B190(void *);
void ov40_0223B29C(void *, void *, int);
void ov40_0223B374(void *);
void ov40_0223B44C(void *);
