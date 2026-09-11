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

void ov96_02219F20(void *p, s32 idx, s32 x, s32 y) {
    ManagedSprite_SetPositionXYWithSubscreenOffset(*(void **)((u8 *)p + 0x60 + idx * 4), x, y, 0x1e0000);
    ManagedSprite_SetPositionXYWithSubscreenOffset(*(void **)((u8 *)p + 0x68 + idx * 4), x, (s16)(y - 0x18), 0x1e0000);
}

void ov96_02219F50(void *p, s32 idx, u32 flag) {
    ManagedSprite_SetDrawFlag(*(void **)((u8 *)p + 0x60 + (idx + 2) * 4), flag == 0);
    ManagedSprite_SetDrawFlag(*(void **)((u8 *)p + 0x60 + (idx + 6) * 4), flag);
}
