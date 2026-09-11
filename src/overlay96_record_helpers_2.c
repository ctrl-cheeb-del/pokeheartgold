#include "overlay96_record_helpers_private.h"

extern void GF_AssertFail(void);
extern void ManagedSprite_SetDrawFlag(void *, u32);
extern void ManagedSprite_SetPositionXYWithSubscreenOffset(void *, s32, s32, s32);
void ov96_02219BDC(void *, void *, void *, u32, u32, s16, s16);
extern void ov96_021E6168(void *, u32, u32, void *);
extern void ov96_021EECB8(void *, void *, u32, u32, u32, u32);
extern void ov96_021EEBE4(void *, void *, u32, u32, u32);
extern void BufferString(void *, u32, void *, u32, u32, u32);
extern const Ov96SpriteTemplate ov96_0221D910;
extern const Ov96SpriteTemplate ov96_0221D944;
extern void *SpriteSystem_NewSpriteWithYOffset(void *, void *, const void *, s32);
extern void ManagedSprite_SetAnimateFlag(void *, u32);
extern s32 PokeathlonCourse_GetParticipantCount(void *); extern void *Heap_Alloc(u32, u32); extern void ov96_0221A00C(void *, u8, void *);
extern const u8 ov96_0221D8F8[]; extern void AddWindow(void *, void *, const void *); extern void BG_FillCharDataRange(void *, u32, u32, u32, u32); extern void LoadFontPal0(u32, u32, void *);
extern void *PokeathlonCourse_GetPlayerProfileFromData(void *, u32); extern void *PlayerProfile_GetPlayerName_NewString(void *, u32);
extern void ManagedSprite_SetPaletteOverride(void *, u32); extern void *SpriteManager_GetSpriteList(void *); extern void *ov96_021EA374(void *, void *, u32, u32); extern void Sprite_SetMatrix(void *, const void *); extern void Sprite_SetDrawFlag(void *, u32);
extern void CopyRectToBgTilemapRect(void *, u32, u32, u32, u32, u32, void *, u32, u32, u32, u32); extern void ScheduleBgTilemapBufferTransfer(void *, u32);
extern void FillWindowPixelBuffer(void *, u32); extern void *ReadMsgData_ExpandPlaceholders(void *, void *, u32, u32); extern void AddTextPrinterParameterizedWithColor(void *, u32, void *, s32, s32, u32, u32, u32); extern void String_Delete(void *); extern void CopyWindowToVram(void *);

u32 ov96_02219940(void *, u32);
void ov96_02219BC4(void *, u32, u32, u32, u32);
void ov96_02219F20(void *, s32, s32, s32);
void ov96_02219F50(void *, s32, u32);
void ov96_02219DD0(void *, s32, u32);
void ov96_02219DA8(void *, u32, void *, u32, u8);
void ov96_0221996C(void *, u32, u32, u32);
void ov96_02219EE0(void *, s32);
void *ov96_022199A8(void *, void *, u16, u16, u16, u32);
void *ov96_02219E00(void *, void *, u16, u16, u16, u32);
void *ov96_02219F7C(void *, u32);
void ov96_02219A08(void *);
void ov96_02219B30(void *);
void ov96_02219E60(void *);
void ov96_02219A5C(void *, s32);

void ov96_02219A08(void *raw) {
    u8 *p = raw;
    u8 i;
    if (p == NULL) GF_AssertFail();
    if (PAT(p, 0x14) == NULL) GF_AssertFail();
    for (i = 0; i < 3; i++) {
        AddWindow(PAT(p, 0x14), p + 0x30 + i * 0x10, ov96_0221D8F8 + i * 8);
    }
    BG_FillCharDataRange(PAT(p, 0x14), 5, 0, 1, 0);
    LoadFontPal0(4, 0x1e0, PAT(p, 4));
}

void ov96_02219A5C(void *raw, s32 value) {
    u8 *p = raw;
    u8 offsets[3];
    u8 tiles[3];
    u8 digit;
    u8 i;

    digit = (u8)(value / 100);
    offsets[0] = (digit % 5) * 4;
    tiles[0] = (digit / 5) * 8;
    digit = (u8)((value - digit * 100) / 10);
    offsets[1] = (digit % 5) * 4;
    tiles[1] = (digit / 5) * 8;
    digit = (u8)(value % 10);
    offsets[2] = (digit % 5) * 4;
    tiles[2] = (digit / 5) * 8;

    for (i = 0; i < 3; i++) {
        CopyRectToBgTilemapRect(PAT(p, 0x14), 6, (u8)(0x10 + i * 4), 0xb, 4, 8, (u8 *)PAT(p, 0x2c) + 0xc, offsets[i], tiles[i], 0x14, 0x10);
    }
    ScheduleBgTilemapBufferTransfer(PAT(p, 0x14), 6);
}

void ov96_02219B30(void *raw) {
    u8 *p = raw;
    void *str;
    FillWindowPixelBuffer(p + 0x30, 0);
    str = PlayerProfile_GetPlayerName_NewString(PokeathlonCourse_GetPlayerProfileFromData(PAT(p, 0), U8AT(p, 0x22)), U32AT(p, 4));
    AddTextPrinterParameterizedWithColor(p + 0x30, 0, str, 0, 0, 0xff, 0x000f0e00, 0);
    ov96_02219BDC(p + 0x50, PAT(p, 0x1c), PAT(p, 0x18), 0x130, U32AT(p, 4), 2, 2);
    String_Delete(str);
    CopyWindowToVram(p + 0x30);
    BufferString(PAT(p, 0x1c), 0, PAT(p, 0xb4), 2, 1, 2);
    ov96_02219BC4(p + 0x40, (u32)PAT(p, 0x1c), (u32)PAT(p, 0x18), 0x9a, U32AT(p, 4));
}

void ov96_02219BC4(void *a, u32 b, u32 c, u32 d, u32 e) {
    ov96_02219BDC(a, (void *)b, (void *)c, d, e, 0, 0);
}

void ov96_02219BDC(void *win, void *msgData, void *fmt, u32 msgId, u32 field, s16 x, s16 y) {
    void *str;
    FillWindowPixelBuffer(win, 0);
    str = ReadMsgData_ExpandPlaceholders(msgData, fmt, msgId, field);
    AddTextPrinterParameterizedWithColor(win, 0, str, x, y, 0xff, 0x000f0e00, 0);
    String_Delete(str);
    CopyWindowToVram(win);
}
