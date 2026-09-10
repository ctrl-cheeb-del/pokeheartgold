#ifndef PRIVATE_OV01_021F8D80_H
#define PRIVATE_OV01_021F8D80_H

#include "global.h"

#include "filesystem.h"
#include "filesystem_files_def.h"
#include "heap.h"
#include "map_object.h"
#include "sprite.h"

typedef struct MModelGraphicsInfo {
    /*0x00*/ u16 spriteId;
    /*0x02*/ u16 mmodelNo;
    /*0x04*/ u16 unk4_lo : 5;
    /*0x04*/ u16 unk4_hi : 11;
} MModelGraphicsInfo; // size: 0x06

typedef struct UnkObjExtra {
    /*0x00*/ Sprite *sprite;
    /*0x04*/ VecFx32 unk04;
    /*0x10*/ s8 unk10;
    /*0x11*/ u8 unk11;
    /*0x12*/ s8 unk12;
    /*0x13*/ s8 unk13;
    /*0x14*/ s8 unk14;
    /*0x15*/ u8 unk15;
    /*0x16*/ u8 unk16;
    /*0x17*/ u8 unk17;
} UnkObjExtra; // size: 0x18

typedef void (*UnkObjExtraCallback)(LocalMapObject *object, Sprite *sprite, UnkObjExtra *extra);

extern MModelGraphicsInfo ov01_022074A8[];
extern u16 ov01_02206D00[];

BOOL ov01_021FA2D4(LocalMapObject *object);
void ov01_021FA3E8(LocalMapObject *object, Sprite *sprite);

void sub_02023EA4(Sprite *sprite, u8 a1);
void sub_02023EE0(Sprite *sprite, int a1);
void sub_02023F04(Sprite *sprite, fx32 a1);
fx32 sub_02023F30(Sprite *sprite);
void sub_02023F40(Sprite *sprite, int a1);

int ov01_02205564(LocalMapObject *object);
fx32 ov01_022054E0(LocalMapObject *object);
int ov01_021FA44C(u32 direction);
BOOL ov01_022055B0(LocalMapObject *object);
void ov01_02205808(void *a0, LocalMapObject *object, Sprite *sprite);
u32 ov01_021FA298(u32 spriteId);
void ov01_021FD9CC(u32 direction, VecFx32 *vec);
void ov01_021F9610(Sprite *sprite, VecFx32 *vec);
void ov01_021F9630(Sprite *sprite, VecFx32 *vec);
void ov01_021F95A8(LocalMapObject *object, UnkObjExtra *extra);
void ov01_021F9510(LocalMapObject *object, UnkObjExtra *extra);
void ov01_021F944C(void *a0, MapObjectManager *manager, u32 count, u32 priority, u32 a4, u32 a5, u32 a6, u32 a7);
void ov01_021F94A0(void *a0);

#endif // PRIVATE_OV01_021F8D80_H
