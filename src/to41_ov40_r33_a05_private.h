#ifndef OV40_R33_A05_PRIVATE_H
#define OV40_R33_A05_PRIVATE_H
#include "global.h"
#define PTR(p, o)         (*(void **)((u8 *)(p) + (o)))
#define WORD(p, o)        (*(u32 *)((u8 *)(p) + (o)))
#define SWORD(p, o)       (*(s32 *)((u8 *)(p) + (o)))
#define SHALF(p, o)       (*(s16 *)((u8 *)(p) + (o)))
#define BLEND(p, w, a, b) PaletteData_BlendPalettes(PTR(p, 0x28), (a), (b), (u8)WORD(w, 8), (u16)WORD(p, 0x58))
void ManagedSprite_SetDrawFlag(void *, BOOL);
void TextOBJ_SetSpritesDrawFlag(void *, BOOL);
void ManagedSprite_SetPositionXY(void *, int, int);
void sub_020136B4(void *, int, int);
void ClearWindowTilemapAndCopyToVram(void *);
void RemoveWindow(void *);
void *Heap_Alloc(int, u32);
void Heap_Free(void *);
void *memset(void *, int, u32);
void BgClearTilemapBufferAndCommit(void *, int);
void PaletteData_BlendPalettes(void *, int, int, int, int);
void SetBgPriority(int, int);
void GfGfx_EngineATogglePlanes(int, int);
void GfGfx_EngineBTogglePlanes(int, int);
void GfGfxLoader_LoadCharDataFromOpenNarc(void *, int, void *, int, int, int, int, int);
void InitWindow(void *);
void AddWindowParameterized(void *, void *, int, int, int, int, int, int, int);
void FillWindowPixelBuffer(void *, int);
void *NewString_ReadMsgData(void *, int);
u32 FontID_String_GetWidthMultiline(int, void *, int);
void AddTextPrinterParameterizedWithColor(void *, int, void *, int, int, int, u32, void *);
void ScheduleWindowCopyToVram(void *);
void String_Delete(void *);
void *TouchHitboxController_Create(const void *, int, const void *, void *, int);
void ManagedSprite_SetAnim(void *, int);
void PlaySE(u16);
void StopSE(u16, int);
BOOL TouchscreenHitbox_TouchNewIsIn(const void *);
BOOL sub_0202FC48(void);
void sub_0202FC24(void);
void sub_0203A948(int, int);
void sub_020879E0(void *, int);
void sub_02087A08(void *, int, int);
void sub_020878EC(void *, int, int);
BOOL sub_02087E1C(void *);
void GF_AssertFail(void);
void ov40_0222D9E8(void *, void *, int);
BOOL ov40_0222DA84(void *, int);
BOOL ov40_0222DA00(void *, void *, int, int);
void ov40_0222DAA8(void *);
void ov40_0222BF80(void *, int);
void ov40_0222BF64(void *, int, int, void *);
void ov40_0222FB90(void *, int);
void *ov40_0222FBB4(void *);
int ov40_0222C4DC(void);
void ov40_02230964(void *, int);
void ov40_0222D874(void *);
void ov40_0223A430(void *);
void ov40_0223077C(void *, void *, int, int);
void ov40_0222DED0(void *, int);
void *ov40_0223D540(void *);
BOOL ov40_0223D5CC(void *);
BOOL ov39_022276A4(void *);
BOOL ov39_022276E0(void *);
BOOL ov39_02227648(void *);
BOOL ov39_022275E8(void *);
BOOL ov39_02227D44(void *, void **);
void ov40_0222DFB0(void *);
void ov40_02230CDC(void *, int, int, int);
void ov40_0222D88C(void *);
void ov40_0222DD08(void *);
void ov40_0223B480(void *);
void ov40_0223D008(void *);
void ov40_0223D1AC(void *, int);
void ov40_0223D1F0(void *);
void ov40_0223D244(void *);
void ov40_02230944(void *);
void ov40_0222D66C(void *, void *, int);
void ov40_0223CD14(void *);
void ov40_0223CFA8(void *);
void ov40_02230638(void *, void *);
int ov40_02230410(void *);
void ov40_022306A0(void *, int);
void ov40_022307DC(void *, int, int);
void ov40_0222FA88(void *);
void ov40_0222F5EC(void *, s16);
void ov40_0222F488(void *, void *);
void ov40_0222FA24(void *);
void ov40_0222F720(void *);
void ov40_0222F920(void *, void *);
void ov40_0222FE98(void *);
void ov40_0222FE68(void *);
void ov40_0222FA18(void *);
void ov40_0222F734(void *);
void ov40_0222FE00(void *);
void *ov40_0222FE8C(int);
void ov40_0222E9B8(void *, void *, int, void *);
void ov40_0222FA5C(void *, void *);
void ov40_0222F740(void *, void *, int);
void ov40_0222F858(void *, int, int);
void ov40_0222F9D4(void *, void *);
typedef struct {
    u32 e[3];
} Ov40Msg3;
typedef struct {
    u32 e[11];
} Ov40Blk44;
typedef struct {
    u8 pad[0x2054];
    Ov40Blk44 block;
    void *obj;
    u32 pad2084;
    u32 value2088;
} Ov40BBWork;
typedef struct {
    u8 pad[0x2030];
    s32 count;
} Ov40Count2030;
typedef struct {
    u8 pad[0x202C];
    s32 count;
} Ov40Count202C;
extern const u32 ov40_02245494, ov40_02245498, ov40_0224549C, ov40_022454B0, ov40_022454E0;
extern const Ov40Blk44 ov40_022454F0;
extern const Ov40Msg3 ov40_022454A4;
void ov40_0223CE64(void);
void ov40_0223CF00(void);
void ov40_0223CF70(void);
void ov40_0223B4BC(void *, int);
void ov40_0223B538(void *);
void ov40_0223B574(void *);
int ov40_0223B5B0(void *);
int ov40_0223B62C(void *);
void ov40_0223BA70(void *);
int ov40_0223C0D8(void *);
int ov40_0223BF88(void *);
int ov40_0223BD98(void *);
int ov40_0223BB74(void *);
#endif
