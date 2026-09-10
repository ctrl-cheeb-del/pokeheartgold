#include "global.h"

typedef struct FourWordsPrivate {
    u32 words[4];
} FourWordsPrivate;
typedef struct VecFx32Private {
    s32 x, y, z;
} VecFx32Private;
typedef struct EffectContextPrivate {
    void *fieldSystem, *manager, *work, *mapObject;
} EffectContextPrivate;

extern void *ov01_021F1430(void *, u32, u32, u32);
extern void ov01_021F1448(void *);
extern void ov01_021F18D4(void *, u32, u32);
extern void ov01_021F1908(void *, u32, u32);
extern void ov01_021F1930(void *, u32, u32, u32);
extern void ov01_021F1758(void *, u32, u32, u32, u32, u32, const void *);
extern void ov01_021F18FC(void *, u32);
extern void ov01_021F1924(void *, u32);
extern void ov01_021F1970(void *, u32);
extern void ov01_021F18C8(void *, u32);
extern const u32 ov01_02209200[];
extern const u32 ov01_022091EC[];
extern void *sub_02068D98(void *);
extern void sub_02068DB8(void *, VecFx32Private *);
extern u32 MapObject_GetID(void *);
extern u32 MapObject_GetMapID(void *);
extern void *ov01_021F1740(void *, u32, const VecFx32Private *);
extern void sub_02023DA4(void *);
extern void sub_02023F04(void *, s32);
extern s32 sub_02023F70(void *);
extern void ov01_021F1640(void *);
extern void sub_02023E50(void *, const VecFx32Private *);
extern void *ov01_021F146C(void *);
extern void *MapObject_GetFieldSystem(void *);
extern void *ov01_021F1450(void *, u32);
extern void MapObject_CopyPositionVector(void *, VecFx32Private *);
extern s32 MapObject_GetXCoord(void *);
extern s32 MapObject_GetZCoord(void *);
extern void sub_020611C8(s32, s32, VecFx32Private *);
extern u32 MapObject_GetPriorityPlusValue(void *, u32);
extern void ov01_021F1620(void *, const void *, const VecFx32Private *, u32, const EffectContextPrivate *, u32);

void *ov01_021FF6B0(void *);
void ov01_021FF6CC(void *);
void ov01_021FF6DC(void *);
void ov01_021FF724(void *);
void ov01_021FF74C(void *);
BOOL ov01_021FF7B0(void *, void *);
void ov01_021FF7F4(void *, void *);
void ov01_021FF800(void *, void *);
void ov01_021FF830(void *, void *);
