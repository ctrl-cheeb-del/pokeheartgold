#ifndef OV01_022051EC_PRIVATE_H
#define OV01_022051EC_PRIVATE_H
#include "global.h"
typedef struct Vec3 {
    s32 x, y, z;
} Vec3;
typedef struct SpawnArgs {
    void *ctx;
    void *renderer;
} SpawnArgs;
extern void *ov01_021F1430(u32, u32, u32, u32);
extern void ov01_021F1448(void *);
extern void HeapExp_FndInitAllocator(void *, u32, u32);
extern void Field3dModel_LoadFromFilesystem(void *, u32, u32, u32);
extern void Field3dModelAnimation_LoadFromFilesystem(void *, void *, u32, u32, u32, void *);
extern void Field3dObject_InitFromModel(void *, void *);
extern void Field3dObject_AddAnimation(void *, void *);
extern void Field3dModelAnimation_Unload(void *, void *);
extern void Field3dModel_Unload(void *);
extern void Field3dObject_SetActiveFlag(void *, BOOL);
extern void *ov01_021F1450(void *, u32);
extern void ov01_021F1620(void *, const void *, void *, u32, SpawnArgs *, u32);
extern const u8 ov01_022096CC[];
extern void *sub_02068D74(void *);
extern void *sub_02068D98(void *);
extern void sub_02068DB8(void *, Vec3 *);
extern void Field3dObject_SetPosEx(void *, s32, s32, s32);
extern void PlaySE(u32);
extern void Field3dObject_Draw(void *);
extern BOOL Field3dModelAnimation_FrameAdvanceAndCheck(void *, s32);
extern void Field3dModelAnimation_FrameSet(void *, s32);
void *ov01_022051EC(u32);
void ov01_02205208(void *);
void ov01_02205218(void *);
void ov01_022052A4(void *);
void ov01_022052C4(void *, void *);
void *ov01_022052F4(void *);
BOOL ov01_02205300(void *, void *);
void ov01_02205350(void);
void ov01_02205354(void *, void *);
void ov01_02205364(void *, void *);
BOOL ov01_02205388(void *, u32);
void ov01_022053C4(void *, u32, s32);
#endif
