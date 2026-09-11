#ifndef TO30_UNK_020607D8_PRIVATE_H
#define TO30_UNK_020607D8_PRIVATE_H

#include "global.h"

#include "map_object.h"
#include "metatile_behavior.h"

u8 ov01_022055DC(LocalMapObject *object);
u32 ov01_022056C4(LocalMapObject *object, u32 direction);
int sub_02060FA8(LocalMapObject *object, int direction);
void ov01_021FDF88(LocalMapObject *object, int kind);
void ov01_021FDA74(LocalMapObject *object, int kind);

typedef struct MovementEffect {
    u16 padding : 11;
    u16 kind : 2;
    u16 rest : 3;
} MovementEffect;

void sub_020607D8(LocalMapObject *object, u8 behavior, int unused, const MovementEffect *effect);
void sub_020609D4(LocalMapObject *object, int unused1, int unused2, const MovementEffect *effect);

#endif
