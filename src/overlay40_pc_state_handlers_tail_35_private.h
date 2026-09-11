#ifndef OVERLAY40_PC_STATE_HANDLERS_TAIL_35_PRIVATE_H
#define OVERLAY40_PC_STATE_HANDLERS_TAIL_35_PRIVATE_H

#include "global.h"

#define PTR(p, off)  (*(void **)((u8 *)(p) + (off)))
#define WORD(p, off) (*(u32 *)((u8 *)(p) + (off)))
#define HALF(p, off) (*(u16 *)((u8 *)(p) + (off)))
#define BYTE(p, off) (*(u8 *)((u8 *)(p) + (off)))

typedef struct Ov40Entry {
    u8 raw[0xE4];
} Ov40Entry;

typedef struct Ov40Win {
    u8 raw[0x10];
} Ov40Win;

typedef struct Ov40Work {
    u8 pad0[0x2608];
    Ov40Entry *ptrs[30];
    Ov40Entry entries[30];
    s32 count;
} Ov40Work;

void TouchHitboxController_IsTriggered(void *controller);
void TouchHitboxController_Destroy(void *controller);
void ClearWindowTilemapAndCopyToVram(void *window);
void RemoveWindow(void *window);
void DestroyMsgData(void *msgData);
void Heap_Free(void *ptr);
void ManagedSprite_SetDrawFlag(void *sprite, BOOL draw);
void ManagedSprite_SetAnim(void *sprite, int anim);
void *NewString_ReadMsgData(void *msgData, s32 strno);
void FillWindowPixelBuffer(void *window, u8 fillValue);
void AddTextPrinterParameterizedWithColor(void *window, int fontId, void *str, int x, int y, int speed, u32 color, void *callback);
void ScheduleWindowCopyToVram(void *window);
void String_Delete(void *str);
void *String_New(u32 size, u32 heapId);
void CopyU16ArrayToString(void *str, u16 *arr);
void GetSpeciesNameIntoArray(u16 species, u32 heapId, u16 *dest);
void BufferCityName(void *fmt, u32 idx, u32 a, u32 b);
void BufferCountryName(void *fmt, u32 idx, u32 a);
void StringExpandPlaceholders(void *fmt, void *dst, void *src);
void MessageFormat_Delete(void *fmt);
void GfGfx_EngineATogglePlanes(int planes, int enable);
void GfGfx_EngineBTogglePlanes(int planes, int enable);
void InitWindow(void *window);
void AddWindowParameterized(void *bgConfig, void *window, u8 bgId, u8 x, u8 y, u8 width, u8 height, u8 paletteNum, u16 baseTile);
u32 FontID_String_GetWidthMultiline(u32 fontId, void *str, u32 letterSpacing);
void *Save_Pokedex_Get(void *saveData);
BOOL Pokedex_CheckMonSeenFlag(void *pokedex, u16 species);
u16 *ov40_0222DD68(u32 heapId, int a1, u32 *out);
extern const u16 ov40_02245E44[];
extern const u8 ov40_022456C4[];
extern const u8 ov40_02245708[];
extern const u8 ov40_02241D10[];
extern const u8 ov40_02241E14[];
void *TouchHitboxController_Create(const void *hitboxes, int count, const void *callbacks, void *arg, u32 heapId);
void ov40_0222DED0(void *p, int value);
void ov40_0223DBD4(void *p, int value);
void PaletteData_BlendPalettes(void *data, int bufferID, u16 selectedBuffer, u8 cur, u16 target);

void ov40_0222BF80(void *p, int value);
BOOL ov40_0222DA84(void *p, int value);
BOOL ov40_0222DA00(void *a0, void *a1, int a2, int a3);
void *ov40_0222DAB0(u32 heapId);
void ov40_0222DF60(void *p, int value);
void ov40_0222DFB0(void *p);
void ov40_0222D66C(void *a0, void *a1, int a2);
void ov40_0222E7B8(void *a0, void *a1);
void ov40_0222FF48(void *p, void *a1, void *sprite);
void ov40_0223064C(void *a0, void *a1);
void ov40_022307DC(void *p, int a1, int a2);
void ov40_02230964(void *p, void *value);
void ov40_022420B4(void *p, int value);
void ov40_02240910(void *p);
void ov40_02241A34(void *p);
BOOL ov40_0224222C(void *p);
BOOL ov40_02242490(void *p);
BOOL ov40_0224253C(void *p);
BOOL ov40_022428D4(void *p);
BOOL ov40_02242AEC(void *p);
BOOL ov40_02242CFC(void *p);

void ov40_0223D830(void *p, BOOL draw);
void ov40_0223D874(void *p);
BOOL ov40_0223DB94(void *p);
void ov40_0223DCF0(void *p, u32 a);
void ov40_0223DD68(void *p, u16 value);
void ov40_0223DDE8(void *p, u32 a1, u32 a2);
void ov40_0223DEB8(void *p);
void ov40_0223DF1C(void *p, int value);
void ov40_0223E024(void *p);
void ov40_0223E064(void *p);
void ov40_0223E0A4(void *p);
int ov40_0223E324(void *p);
int ov40_0223E494(void *p);
int ov40_0223E6EC(void *p);
void ov40_0223E848(void *p);
int ov40_0223EBB8(void *p, u32 idx);
void ov40_0223EDA8(void *p);
int ov40_0223EFA4(void *p);
int ov40_0223F16C(void *p);
int ov40_0223F59C(void *p);
int ov40_0223F830(void *p);
int ov40_0223F848(void *p);
int ov40_0223F860(void *p);
int ov40_0223F880(void *p);
int ov40_0223FCA0(void *p);
int ov40_0223FCB8(Ov40Work *work);
int ov40_0223FCF8(Ov40Work *work);
int ov40_0223FD38(void *p);
int ov40_0223FD50(void *p);
int ov40_0223FD68(void *p);

typedef struct Ov40Blk44 {
    u32 w[11];
} Ov40Blk44;

extern const Ov40Blk44 ov40_022457B0;
extern const u8 ov40_0224564C[];
extern const u8 ov40_02245650[];
extern const u8 ov40_02245654[];
extern const u8 ov40_02245674[];
extern const u8 ov40_022456B4[];
extern const u8 ov40_02241E40[];
extern const u8 ov40_02241ED4[];
extern const u8 ov40_02241F3C[];

BOOL TouchscreenHitbox_TouchNewIsIn(const void *hitbox);
void BgClearTilemapBufferAndCommit(void *bgConfig, u32 layer);
void GfGfxLoader_LoadCharDataFromOpenNarc(void *narc, u32 memberNo, void *bgConfig, u32 layer, u32 tileStart, u32 szByte, u32 isCompressed, u32 heapId);
BOOL sub_0202FC48(void);
void sub_0202FC24(void);
BOOL sub_020878EC(void *p, int x, int y);
BOOL sub_020879E0(void *p, int flag);
void sub_02087A08(void *p, int a1, int a2);

void ov40_02230944(void *p);
void ov40_02230738(void *p);
void ov40_0222D9E8(void *a0, void *a1, int a2);
void ov40_02242110(void *p);
void ov40_022421FC(void *p);
void ov40_0222D88C(void *p);
void ov40_0222FB90(void *p, int value);
void *ov40_0222FBB4(void *p);
void ov40_0222DD08(void *p);
void ov40_0222DAA8(void *p);
void ov40_0222BF64(void *p, u32 value, BOOL valid, u32 *out);
void ov40_022408AC(void *p);
void ov40_02230638(void *p, void *a1);
int ov40_02230410(void *p);
void ov40_022306A0(void *p, BOOL draw);
void ov40_02241AB0(void *p);
void ov40_0222FA88(void *p);
void ov40_0222F5EC(void *p, s16 value);
void ov40_0222F488(void *p, void *a1);
void ov40_0222FA24(void *p);
void ov40_0222F720(void *p);
void ov40_0222F920(void *p, void *a1);
void ov40_0222FE98(void *narc);
void ov40_0222FE68(void *p);
void ov40_0222FA18(void *p);
void ov40_0222F734(void *p);
void ov40_0222FE00(void *p);
void *ov40_0222FE8C(u32 heapId);
void ov40_0222E9B8(void *a0, void *a1, int a2, void *a3);
void ov40_0222FA5C(void *a0, void *a1);
void ov40_0222F740(void *a0, void *a1, int a2);
void ov40_0222F858(void *p, int y1, int y2);
void ov40_0222F9D4(void *p, void *a1);
void ov40_0223077C(void *p, void *a1, int a2, int a3);

void ov40_0223D68C(void *p);
void ov40_0223D8D4(void *p);
void ov40_0223E730(void *p);
int ov40_0223E190(void *p);
int ov40_0223E33C(void *p);
int ov40_0223E870(void *p);
int ov40_0223F200(void *p);
int ov40_0223F3E4(void *p);
int ov40_0223F6BC(void *p);

extern const Ov40Blk44 ov40_022457DC;
extern const u8 ov40_02245758[];
extern const u8 ov40_02245784[];
extern const u8 ov40_0224572C[];

int sub_02087E1C(void *p);
u32 sub_02031620(void *p);
u32 sub_0203162C(void *p);
void ov40_0222E8C4(void *a0, void *a1, const void *a2);
void ov40_0222F6D0(void *p, s16 value);
u16 ov40_0222F38C(void *p, void *a1);

int ov40_0223E520(void *p);
int ov40_0223E9A4(void *p);
int ov40_0223EDE0(void *p);

typedef struct Ov40Pt {
    s16 x;
    s16 y;
} Ov40Pt;

typedef struct Ov40PtTbl {
    Ov40Pt e[30];
} Ov40PtTbl;

typedef struct Ov40Rec16 {
    u32 a;
    u32 b;
    u32 c;
    u32 d;
} Ov40Rec16;

extern const Ov40PtTbl ov40_02245948;

void PlaySE(u16 seq);
void StopSE(u16 seq, int fadeFrames);
void *Heap_Alloc(int heapId, u32 size);
void *NewMsgDataFromNarc(u32 kind, u32 narcId, u32 msgId, u32 heapId);
void ManagedSprite_SetPositionXY(void *sprite, int x, int y);
BOOL ov40_0223D5CC(void *p);
void *ov40_0223D540(void *p);
int ov39_02227590(void *a0, u32 a1, u8 a2, u32 a3, u32 a4);
u32 ov39_02227D44(void *work, void **out);
void ov40_022309DC(void *p, int a1, u32 a2, u32 a3);

void ov40_0223D618(void *p);
int ov40_0223F028(void *p);
void ov40_0223EC40(void *p, u32 idx);

int ov40_022306C0(void *window, void *str);
void ov40_0223E730(void *p);

void *sub_020307F8(void);
u64 sub_0203088C(void *summary, int field, int index);
BOOL ov40_02230D94(void *p, u64 value);
BOOL ov40_02242378(void *p);
void ov40_02241054(void *p);
void ov40_02241114(void *p);
void ov40_0222E79C(void *p, void *a1);
void ov40_0222E7DC(void *p, BOOL draw);
BOOL System_GetTouchNew(void);
void GfGfxLoader_LoadScrnDataFromOpenNarc(void *narc, u32 memberNo, void *bgConfig, u32 layer, u32 tileStart, u32 szByte, u32 isCompressed, u32 heapId);
int ov40_0223F984(Ov40Work *work);

typedef struct Ov40Rec16Tbl3 {
    Ov40Rec16 e[3];
} Ov40Rec16Tbl3;

typedef struct Ov40Msg3 {
    u32 e[3];
} Ov40Msg3;

extern const Ov40Rec16Tbl3 ov40_02245868;
extern const Ov40Msg3 ov40_0224565C;

#endif
