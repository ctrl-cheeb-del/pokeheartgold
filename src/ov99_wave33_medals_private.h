#ifndef OV99_R8_H
#define OV99_R8_H
#include "global.h"
#include "sprite_system.h"
#include "bg_window.h"
#include "unk_02019BA4.h"
#include "gf_gfx_planes.h"
#include "unk_02020A0C.h"
#include "unk_02005D10.h"
#include "gf_gfx_loader.h"
FS_EXTERN_OVERLAY(OVY_98);
typedef struct R8Work { BgConfig *bg; u32 unk4; NARC *narc; enum HeapID heap; u8 pad010[0x3e0]; void *alloc3f0; u32 flags; u32 unk3f8; GridInputHandler *grid; void *text; void *unk404; ManagedSprite *all[50]; } R8Work;
extern u8 ov99_021E7180(u32);
extern void *ov98_0221EEFC(void *);
extern void BufferSpeciesName(void *,u32,u32);
extern void ov98_0221EBD8(void *,u32,u32,u32);
extern void ov98_0221EE84(void *,u32);
void ov99_021E7258(R8Work *,u32);
void ov99_021E7428(R8Work *,int);
void ov99_021E7758(R8Work *,u32);
void ov99_021E77D8(R8Work *);
void ov99_021E7A54(R8Work *);
void ov99_021E7AB8(R8Work *);
extern u32 ov99_021E71B0(R8Work *);
extern void ov99_021E76D8(R8Work *,u32);
extern u32 ov99_021E7198(R8Work *,u32);
void ov99_021E7794(R8Work *);
void ov99_021E738C(R8Work *,s32,s32);
void ov99_021E73E0(R8Work *,s32,u32);
void ov99_021E7C58(R8Work *,u32);
extern void *OverlayManager_GetData(void *);
extern void OverlayManager_FreeData(void *);
extern void Heap_Free(void *);
extern void ov98_0221E684(void *,ManagedSprite **,u32);
extern void ov98_0221EB84(void *,u32);
extern void ov99_021E7EBC(R8Work *);
extern void ov98_0221F0EC(void);
extern void UnloadOverlayByID(u32);
BOOL PokeathlonMedals_Exit(void *);
extern int ov99_021E714C(void);
extern const s32 ov99_021E9F4C[];
void *ov99_021E728C(R8Work *,u32 *);
#endif
