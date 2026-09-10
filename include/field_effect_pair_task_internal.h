#ifndef PRIVATE_OV01_02200040_H
#define PRIVATE_OV01_02200040_H
#include "global.h"
typedef struct LocalManager {
    void *owner;
} LocalManager;
typedef struct LocalState {
    u32 stage;
    u32 objectId;
    u32 mapId;
    u32 pad0C;
    u32 args0;
    void *resource;
    u32 args8;
    void *mapObject;
    void *effect;
} LocalState;
typedef struct LocalFourWords {
    u32 v[4];
} LocalFourWords;
void *ov01_021F1430(void *, u32, u32, u32);
void ov01_021F1448(void *);
void ov01_021F18D4(void *, int, int);
void ov01_021F1908(void *, int, int);
void ov01_021F1930(void *, int, int, int);
void ov01_021F1758(void *, int, int, int, int, int, const void *);
void ov01_021F18FC(void *, int);
void ov01_021F1924(void *, int);
void ov01_021F1970(void *, int);
void ov01_021F18C8(void *, int);
void *ov01_021F146C(void *);
void *ov01_021F1450(void *, int);
void *MapObject_GetFieldSystem(void *);
void MapObject_CopyPositionVector(void *, VecFx32 *);
int MapObject_GetXCoord(void *);
int MapObject_GetZCoord(void *);
void sub_020611C8(int, int, VecFx32 *);
int MapObject_GetPriorityPlusValue(void *, int);
void ov01_021F1620(void *, const void *, const VecFx32 *, void *, const void *, int);
void *sub_02068D98(void *);
void sub_02068DB8(void *, VecFx32 *);
int MapObject_GetID(void *);
int MapObject_GetMapID(void *);
void *ov01_021F1740(void *, int, const VecFx32 *);
void sub_02023DA4(void *);
void sub_02023F04(void *, fx32);
fx32 sub_02023F70(void *);
void ov01_021F1640(void *);
void sub_02023E50(void *, const VecFx32 *);
LocalManager *ov01_02200040(void *);
void ov01_0220005C(LocalManager *);
void ov01_0220006C(LocalManager *);
void ov01_022000B4(LocalManager *);
void ov01_022000DC(void *);
BOOL ov01_02200140(void *, LocalState *);
void ov01_02200184(void *, LocalState *);
void ov01_02200190(void *, LocalState *);
void ov01_022001C0(void *, LocalState *);
#endif
