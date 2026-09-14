#ifndef OV40_R27_U6_PRIVATE_H
#define OV40_R27_U6_PRIVATE_H

#include "global.h"

#define PTR(p, off)   (*(void **)((u8 *)(p) + (off)))
#define WORD(p, off)  (*(u32 *)((u8 *)(p) + (off)))
#define HALF(p, off)  (*(u16 *)((u8 *)(p) + (off)))
#define SHALF(p, off) (*(s16 *)((u8 *)(p) + (off)))
#define S32(p, off)   (*(s32 *)((u8 *)(p) + (off)))
#define BYTE(p, off)  (*(u8 *)((u8 *)(p) + (off)))

typedef void (*Ov40TaskFn)(void *task, void *arg);

void *Heap_Alloc(u32 heapId, u32 size);
void Heap_Free(void *ptr);
void MI_CpuFill8(void *dest, u8 value, u32 size);
void *SysTask_CreateOnMainQueue(Ov40TaskFn fn, void *arg, u32 priority);
void SysTask_Destroy(void *task);
void PaletteData_BlendPalettes(void *data, int buffer, u16 selected, u8 amount, u16 color);
void SetBgPriority(u8 bgId, u16 priority);
void BgClearTilemapBufferAndCommit(void *bgConfig, u32 layer);
void GfGfxLoader_LoadCharDataFromOpenNarc(void *narc, u32 memberNo, void *bgConfig, u32 layer, u32 tileStart, u32 szByte, u32 isCompressed, u32 heapId);
void GfGfx_EngineATogglePlanes(int planes, int enable);
void GfGfx_EngineBTogglePlanes(int planes, int enable);
void ManagedSprite_SetAnim(void *sprite, int anim);
void ManagedSprite_SetDrawFlag(void *sprite, BOOL draw);
void ManagedSprite_SetPaletteOverrideOffset(void *sprite, int offset);
void TextOBJ_SetSpritesDrawFlag(void *obj, BOOL draw);
void *TouchHitboxController_Create(const void *hitboxes, int count, const void *callbacks, void *arg, u32 heapId);
void sub_020136B4(void *p, int x, int y);
void sub_020878B8(void *p, s16 x, s16 y);
u64 sub_0203088C(void *summary, int field, int index);

void ov40_0222BF80(void *p, int value);
BOOL ov40_0222BFB0(void *p);
BOOL ov40_0222C018(void *p);
void ov40_0222C03C(void *p);
int ov40_0222C4DC(void *p);
void ov40_0222D288(void *sprite, s16 x, s16 y);
void ov40_0222D294(void *sprite, s16 *x, s16 *y);
void ov40_0222D3E8(void *work, void *entry, int msgId, void *selection);
void ov40_0222D874(void *p);
void ov40_0222D9E8(void *a0, void *a1, int a2);
BOOL ov40_0222DA00(void *a0, void *a1, int a2, int a3);
BOOL ov40_0222DA84(void *p, int value);
u32 ov40_0222DAC0(void *p);
void ov40_0222DBEC(void *p, u32 value);
void ov40_0222FB90(void *p, int value);
int ov40_02230410(void *p);
void ov40_02230638(void *p, void *a1);
void ov40_022306A0(void *p, BOOL draw);
void ov40_022307DC(void *p, int a1, int a2);
void ov40_02230964(void *p, int value);
void ov40_02232F50(void *p);
void ov40_02232F88(void *p);
void ov40_02233044(void *p);

extern const u8 ov40_02245134[];
extern const u8 ov40_02232ED4[];

void ov40_022318C8(void *task, void *arg);
int ov40_022319A4(void *p);
int ov40_02231C78(void *p);
int ov40_02231EA4(void *p);
int ov40_02232094(void *p);
int ov40_02232288(void *p);
int ov40_022322E0(void *p);
int ov40_02232470(void *p);

#endif
