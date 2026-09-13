#ifndef TO45_OV40_R27_U8_PRIVATE_H
#define TO45_OV40_R27_U8_PRIVATE_H

#include "global.h"

#define PTR(p, off)  (*(void **)((u8 *)(p) + (off)))
#define WORD(p, off) (*(u32 *)((u8 *)(p) + (off)))

void BeginNormalPaletteFade(int, int, int, int, int, int, int);
void BgClearTilemapBufferAndCommit(void *, int);
void GfGfxLoader_LoadScrnDataFromOpenNarc(void *, int, void *, int, int, int, int, int);
void GfGfx_EngineATogglePlanes(int, int);
void GfGfx_EngineBTogglePlanes(int, int);
void Heap_Free(void *);
BOOL IsPaletteFadeFinished(void);
void PaletteData_BlendPalettes(void *, int, u16, u8, u16);
void SaveGameNormal(void *);
BOOL Save_NumModifiedPCBoxesIsMany(void *);
void *TouchHitboxController_Create(const void *, int, const void *, void *, int);
void TouchHitboxController_Destroy(void *);
BOOL TouchscreenHitbox_TouchNewIsIn(const void *);
void ov40_0222BF64(void *, int, int, void *);
void ov40_0222BF80(void *, int);
void ov40_0222C4B8(void *);
void ov40_0222C4E8(void *, void *);
void ov40_0222D88C(void *);
void ov40_0222D8C8(void *);
BOOL ov40_0222DA00(void *, void *, int, int);
BOOL ov40_0222DA84(void *, int);
void ov40_0222DAA8(void *);
void ov40_0222DD08(void *);
void ov40_0222DED0(void *, int);
void ov40_0222DF60(void *, int);
void ov40_0222DFB0(void);
void ov40_0222E7B8(void *, void *);
void ov40_0222FB90(void *, int);
BOOL ov40_0222FBB4(void);
void ov40_0222FCCC(void *);
void ov40_0222FDC4(void *);
int ov40_02230410(void *);
void ov40_02230638(void *, void *);
void ov40_0223064C(void *, void *);
void ov40_022306A0(void *, int);
void ov40_022307DC(void *, int, int);
void ov40_02230944(void *);
void ov40_02230964(void *, int);
void ov40_022326DC(void);
void ov40_022327BC(void *);
void ov40_02232F50(void *);
void ov40_02232F88(void *);
void ov40_02232FCC(void *);
void ov40_02233044(void *);
void ov40_022330B8(void *);
void ov40_02244BBC(void *, void *);
void sub_0202FC24(void);
void sub_0202FC90(void *, int, void *, int, void *);
u64 sub_0203088C(void *, int, int);
void sub_02087A84(void *, int, int);

extern const u8 ov40_0224512C[];
extern const u8 ov40_02245130[];
extern const u8 ov40_02245134[];

void ov40_02232ED4(int, int, void *);
int ov40_022327F0(void *);
int ov40_02232A48(void *);
int ov40_02232AF8(void *);
int ov40_02232BD8(void *);
int ov40_02232D44(void *);

#endif
