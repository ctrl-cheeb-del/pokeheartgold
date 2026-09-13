#ifndef SOL_R40_OVERLAY_73_RESIDUAL_19_PRIVATE_H
#define SOL_R40_OVERLAY_73_RESIDUAL_19_PRIVATE_H
#include "global.h"
#pragma require_prototypes off

#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))

typedef struct SolBgTemplate {
    u32 word[7];
} SolBgTemplate;

void SpriteTransfer_DeleteCharTransferTask(void *);
void SpriteTransfer_DeletePlttTransferTask(void *);
void Destroy2DGfxResObjMan(void *);
void SpriteList_Delete(void *);
void OamManager_Free(void);
void ObjCharTransfer_Destroy(void);
void ObjPlttTransfer_Destroy(void);
void ov73_021E8B64(void *);
void BeginNormalPaletteFade(int, int, int, int, int, int, int);
void ov73_021E8628(void *);
void ov73_021E8730(void *);
void ov73_021E8A08(void *);
void GfGfx_EngineATogglePlanes(int, int);
void GfGfx_EngineBTogglePlanes(int, int);
void sub_02039418(void *);
void ov73_021EA12C(void *);
void *sub_0202D488(void *, int);
int ov00_021EC5B4(void);
void ov73_021E9FF8(void *, void *, int, int, int);
void ov73_021E83EC(void *, int, int);
void ov73_021EA15C(void *);
void ov73_021E8440(void *);
void sub_0203A930(void);
extern int (*ov73_021EA848[])(void *);
void SysTask_Destroy(void *);
void ov73_021E8BBC(void *);
void ov73_021E8B20(void *);
void ov73_021E870C(void *);
extern const SolBgTemplate ov73_021EA70C;
extern const SolBgTemplate ov73_021EA6F0;
extern const SolBgTemplate ov73_021EA728;
extern const SolBgTemplate ov73_021EA6D4;
void InitBgFromTemplate(void *, int, const void *, int);
void BgClearTilemapBufferAndCommit(void *, int);
void BG_ClearCharDataRange(int, int, int, int);

#endif
