#ifndef POKEHEARTGOLD_FIELD_METATILE_QUERY_INTERNAL_H
#define POKEHEARTGOLD_FIELD_METATILE_QUERY_INTERNAL_H
#include "global.h"

#include "field/map_load_manager.h"
#include "field/map_prop.h"

#include "field_system.h"
#include "heap.h"
#include "map_matrix.h"
#include "terrain_attributes.h"
#include "unk_02054648.h"
#include "unk_020648EC.h"

// Inlined from the external worker's private.h. The original assembly remains
// the owner of the four tables below, so this snapshot only declares them.
typedef struct FieldAttrVTable {
    int (*getHeight)(FieldSystem *fieldSystem, int a1, fx32 x, fx32 z, u8 *outKind);
    BOOL (*getAttr)(FieldSystem *fieldSystem, int x, int z, u16 *outAttr);
} FieldAttrVTable;

#define FS_VT(fieldSystem) ((const FieldAttrVTable *)(fieldSystem)->unk60)

int sub_02054648(int a0, int a1);
int sub_02054954(FieldSystem *fieldSystem, VecFx32 *playerPos, int x, int z, u8 *outKind);

extern BOOL ov01_021FB42C(int x, int z, void *dthm, u8 *outAttr);
extern int ov01_021F6328(int idx, int stride);
extern int ov01_021F635C(int chunkIdx, int a1, MapLoadManager *mapLoadManager);
extern void *ov01_021F65D0(MapLoadManager *mapLoadManager, u8 idx);
extern int ov01_021FAE50(int a0, int a1, fx32 x, fx32 z, void *a4, fx32 *outY);
extern fx32 ov01_021FB474(u8 attr, void *dthm);
int sub_02054654(FieldSystem *fieldSystem, int a1, int a2, fx32 x, fx32 z, u8 *outKind);
int sub_02054774(FieldSystem *fieldSystem, int a1, fx32 x, fx32 z, u8 *outKind);
int sub_02054790(FieldSystem *fieldSystem, int a1, int a2, fx32 x, fx32 z, u8 *outKind);
int sub_020547A4(FieldSystem *fieldSystem, int a1, fx32 x, fx32 z, u8 *outKind);
BOOL sub_020547D8(FieldSystem *fieldSystem, int x, int z, u16 *outAttr);
BOOL sub_02054824(FieldSystem *fieldSystem, int x, int z, u16 *outAttr);
u8 sub_020548EC(FieldSystem *fieldSystem, int x, int z);
int sub_02054940(FieldSystem *fieldSystem, int a1, fx32 x, fx32 z, u8 *outKind);

extern BOOL ov01_021F654C(MapLoadManager *mapLoadManager, int x, int z, u8 *outIdx);
extern SoundplateStruct *ov01_021F6600(MapLoadManager *mapLoadManager, u8 idx);
extern int ov01_021F652C(MapLoadManager *mapLoadManager, u8 idx);
u32 sub_020549F4(FieldSystem *fieldSystem, VecFx32 *playerPos, u32 x, u32 y, u32 *a4);
void sub_02054A60(int a0, int a1, int a2, int a3, int a4, int a5, fx32 *out);
BOOL sub_02054A9C(MapProp *mapProp, fx32 *rect, VecFx32 *offset);
BOOL sub_02054AE4(FieldSystem *fieldSystem, int buildModel, fx32 *rect, MapProp **outProp);
BOOL sub_02054B74(FieldSystem *fieldSystem, int *models, u32 count, fx32 *rect, MapProp **outProp, int *outModel);
BOOL sub_02054C20(FieldSystem *fieldSystem, int buildModel, MapProp **outProp, int *outIdx);
BOOL sub_02054C90(FieldSystem *fieldSystem, int *models, u32 count, MapProp **outProp, int *outModel);
int *sub_02054D10(FieldSystem *fieldSystem, u32 heapId, int count, fx32 *rect, int fill);
void sub_02054DC8(int idx, int width, VecFx32 *pos);
BOOL sub_02054E00(u16 a0);
BOOL sub_02054E20(u16 a0);

extern const u16 _020FC5FC[];
extern const FieldAttrVTable _020FC604;
extern const u16 _020FC60C[];
extern const FieldAttrVTable _020FC614;

SoundplateStruct *sub_02054874(FieldSystem *fieldSystem, int x, int z);
void sub_0205489C(void **a0, int a1);
BOOL sub_020548C0(FieldSystem *fieldSystem, int x, int z);
u8 GetMetatileBehavior(FieldSystem *fieldSystem, int x, int z);
BOOL sub_020549A8(FieldSystem *fieldSystem, VecFx32 *playerPos, int xInFront, int yInFront, int a4);

#endif
