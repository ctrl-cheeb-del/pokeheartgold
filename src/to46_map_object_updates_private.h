#ifndef POKEHEARTGOLD_UNK_0205FD20_PRIVATE_H
#define POKEHEARTGOLD_UNK_0205FD20_PRIVATE_H
#include "global.h"

#include "map_object.h"
typedef void (*MoveUpdateFunc)(LocalMapObject *, u8, u8, void *);
typedef BOOL (*TileTestFunc)(u8);
BOOL sub_02061108(LocalMapObject *);
BOOL sub_0205F73C(LocalMapObject *);
u16 sub_0205F504(LocalMapObject *);
u16 sub_0205F514(LocalMapObject *);
void *ov01_021F9318(LocalMapObject *);
void sub_02060AB8(LocalMapObject *, u8, u8, void *);
void sub_020601BC(LocalMapObject *, u8, u8, void *);
void sub_0206039C(LocalMapObject *, u8, u8, void *);
void sub_020603DC(LocalMapObject *, u8, u8, void *);
void sub_020601A4(LocalMapObject *, u8, u8, void *);
void sub_02060698(LocalMapObject *, u8, u8, void *);
void sub_02060700(LocalMapObject *, u8, u8, void *);
void sub_020607D8(LocalMapObject *, u8, u8, void *);
void sub_02060274(LocalMapObject *, u8, u8, void *);
void sub_02060328(LocalMapObject *, u8, u8, void *);
void sub_020603F8(LocalMapObject *, u8, u8, void *);
void sub_020606CC(LocalMapObject *, u8, u8, void *);
void sub_02060704(LocalMapObject *, u8, u8, void *);
void sub_02060708(LocalMapObject *, u8, u8, void *);
void sub_02060770(LocalMapObject *, u8, u8, void *);
void sub_02060AF0(LocalMapObject *, u8, u8, void *);
BOOL sub_0205B918(u8);
BOOL sub_0205B8F4(u8);
BOOL sub_0205B960(u8);
BOOL sub_0205B93C(u8);
extern const s32 _020FD49C[4];
extern const s32 _020FD4AC[4];
extern const TileTestFunc _020FD4BC[4];
extern const TileTestFunc _020FD4CC[4];
extern const s32 _020FD4DC[4];
void sub_0205FEDC(LocalMapObject *);
void sub_0205FF6C(LocalMapObject *);
#endif
