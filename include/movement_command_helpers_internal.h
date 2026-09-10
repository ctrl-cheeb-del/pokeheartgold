#include "global.h"

typedef struct Movement075WorkPrivate {
    u32 parameter;
    void *effect;
} Movement075WorkPrivate;

typedef struct MovementPathWorkPrivate {
    s16 facing;
    s16 field2;
    s16 count;
    s16 index;
} MovementPathWorkPrivate;

extern void *sub_0205F3C0(void *, u32);
extern void *sub_0205F3E4(void *);
extern void *ov01_02200540(void *, u32, u32);
extern BOOL ov01_022003F4(void *);
extern void sub_02068B48(void *);
extern void MapObject_IncrementMovementStep(void *);
extern void sub_02060F24(void *, u32);
extern void MapObject_SetOrQueueFacing(void *, u32);
extern void sub_0205F328(void *, u32);
extern void MapObject_SetFlagsBits(void *, u32);
extern void sub_0206101C(void *, s32, u32);
extern void sub_02061070(void *);
extern void sub_02060F78(void *);
extern void sub_0205F484(void *);

void sub_02062F48(void *, u32);
BOOL MapObjectMovementCmd075_Step1(void *, void *);
BOOL MapObjectMovementCmd075_Step0(void *, void *);
BOOL MapObjectMovementCmd103_Step0(void *, void *);
void sub_02062FAC(void *, u32, u32, u32);
BOOL sub_02062FEC(void *, const u32 *);
