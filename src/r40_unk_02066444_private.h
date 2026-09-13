#ifndef FIELD_FOLLOW_TERRAIN_R40_PRIVATE_H
#define FIELD_FOLLOW_TERRAIN_R40_PRIVATE_H
#include "global.h"

#include "map_object.h"
#include "metatile_behavior.h"

typedef struct FourValues {
    u32 values[4];
} FourValues;
extern const FourValues _020FE3F4;
extern const FourValues _020FE434;
extern const FourValues _020FE444;

void GF_AssertFail(void);
u8 GetMetatileBehavior(FieldSystem *fieldSystem, int x, int z);
void ov01_021FF070(LocalMapObject *object, int kind);
void ov01_021FF8F0(LocalMapObject *object, int kind);
BOOL ov01_022055DC(LocalMapObject *object);
void ov01_02205604(LocalMapObject *object, int *x, int *z);
void ov01_021FF0E4(LocalMapObject *object, int kind, int x, int z, int flag);
void ov01_021FF964(LocalMapObject *object, int kind, int x, int z, int flag);
int sub_02066444(int value);
void sub_020664D8(LocalMapObject *object);
#endif
