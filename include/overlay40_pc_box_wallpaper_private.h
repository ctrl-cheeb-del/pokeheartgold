#ifndef OV40_PC_BOX_WALLPAPER_PRIVATE_H
#define OV40_PC_BOX_WALLPAPER_PRIVATE_H

#include "global.h"

#define PTR(p, off)  (*(void **)((u8 *)(p) + (off)))
#define WORD(p, off) (*(u32 *)((u8 *)(p) + (off)))
#define HALF(p, off) (*(u16 *)((u8 *)(p) + (off)))
#define BYTE(p, off) (*(u8 *)((u8 *)(p) + (off)))

extern void *_021D2AF8;

void GF_AssertFail(void);
void *Heap_Alloc(int heapId, u32 size);
void ManagedSprite_SetDrawFlag(void *sprite, BOOL draw);
void ManagedSprite_SetPositionXY(void *sprite, s16 x, s16 y);
void ManagedSprite_GetPositionXY(void *sprite, s16 *x, s16 *y);
void Sprite_DeleteAndFreeResources(void *sprite);
void SpriteManager_UnloadCharObjById(void *manager, int id);
void SpriteManager_UnloadPlttObjById(void *manager, int id);
void SpriteManager_UnloadCellObjById(void *manager, int id);
void SpriteManager_UnloadAnimObjById(void *manager, int id);
void InitWindow(void *window);
void AddWindowParameterized(void *bgConfig, void *window, int bgId, int x, int y, int width, int height, int palette, int baseTile);
void ClearWindowTilemapAndCopyToVram(void *window);
void RemoveWindow(void *window);
void BgClearTilemapBufferAndCommit(void *bgConfig, int bgId);
void GfGfx_EngineATogglePlanes(int planes, int enable);
void String_SetEmpty(void *str);
void *NewMsgDataFromNarc(u32 kind, u32 narcId, u32 msgId, u32 heapId);
void ReadMsgDataIntoString(void *msgData, u32 msgNo, void *str);
void DestroyMsgData(void *msgData);
u16 SaveArray_CalcCRC16(void *save, void *data, u32 size);
void sub_02030250(void *a, u32 b, u32 c);
int sub_0202FDA4(void *save, void *a, void *b, int c);
int sub_02027134(void *save, void *a, int b);
int SaveGameNormal(void *save);
void sub_0201A728(int a);
void sub_0201A738(int a);
void ov40_0222BF80(void *p, int value);
void ov40_0222C6C8(void *p, int a, int b);
void ov40_0222D9E8(void *a, void *b, int c);

int ov40_022439CC(u8 *w, int id);
int ov40_022439F4(u8 *w, int id);
void ov40_02243B48(u8 *w);
void ov40_02243B94(u8 *w);
void ov40_02243E80(u8 *w, int idx, int on);
void ov40_02243EB0(u8 *w, int idx);
int ov40_02244054(int a, int b);
void ov40_02244060(u8 *w);
void ov40_0224428C(void *w, int a);
void ov40_022442CC(void *w);
void ov40_02244494(void *w);
int ov40_022444C0(void *w);
void ov40_02244A84(void *str, u32 heapId);
int ov40_02244AB0(void *save, void *a2, int a3, u16 *state, int a5);
void ov40_02244B3C(void);
int ov40_02244B70(void *save, void *a, void *b, u16 *state, int a5);
int ov40_02244BBC(void *save, int a);

#endif
