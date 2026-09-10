#ifndef PRIVATE_RENDER_WINDOW_H
#define PRIVATE_RENDER_WINDOW_H
#include "global.h"

void CopyWindowToVram(void *);
void TextPrinter_SetDownArrowBaseTile(u32);
void Heap_Free(void *);
void SysTask_Destroy(void *);
void *SysTask_CreateOnVWaitQueue(void (*)(void *, void *), void *, u32);
void *CreateSysTaskAndEnvironment(void (*)(void *, void *), u32, u32, u32);
void *SysTask_GetData(void *);
void sub_0200F54C(void *, void *);
void *PokepicManager_Create(u32);
void PokepicManager_Delete(void *);
void GetPokemonSpriteCharAndPlttNarcIds(void *, u32, u32);
void GetMonSpriteCharAndPlttNarcIdsEx(void *, u32, u32, u32, u32, u32, u32);
void sub_0200F748(void *, void *);
void FillBgTilemapRect(void *, u32, u32, u32, u32, u32, u32, u32);
void ScheduleBgTilemapBufferTransfer(void *, u32);
void sub_0200E948(void *, u32, u32);
void sub_0200EA68(void *, u32, u32, u32, u32, u32);
void GfGfxLoader_LoadCharData(u32, u32, void *, u32, u32, u32, u32, u32);

u32 sub_0200E3D8(void);
void *sub_0200E63C(void *);
void *sub_0200E640(void *);
void DrawFrameAndWindow2(void *, BOOL, u32, u32);
void sub_0200EB68(void *, u32);
void sub_0200EC84(void *, u32, u32, BOOL, u32, u32);
void sub_0200F43C(void *, void *);
void sub_0200F450(void *);
void sub_0200F478(void *);
void sub_0200F5C4(void *, u8, u8, u8, u32);
void sub_0200F6D4(void *, u32, u32);
void sub_0200F714(void *, u32);
void sub_0200F9DC(void *);
#endif
void sub_0200E398(void *, u32, u32, BOOL, u32);
