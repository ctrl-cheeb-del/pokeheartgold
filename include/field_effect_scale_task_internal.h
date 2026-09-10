#include "global.h"

typedef struct VecFx32Private {
    s32 x;
    s32 y;
    s32 z;
} VecFx32Private;

typedef struct EffectContextPrivate {
    void *manager;
    void *work;
} EffectContextPrivate;

typedef struct TwoWordsPrivate {
    u32 word0;
    u32 word4;
} TwoWordsPrivate;

typedef struct EffectWorkPrivate {
    u8 fields[0x78];
    TwoWordsPrivate source;
} EffectWorkPrivate;

extern void *ov01_021F1430(void *, u32, u32, u32);
extern void ov01_021F1448(void *);
extern void *ov01_021F146C(void *);
extern void *ov01_021F1450(void *, u32);
extern void ov01_021F19F4(void *, void *, u32, u32, u32);
extern void ov01_021F1A18(void *, void *, u32, u32, u32);
extern void sub_02069784(void *);
extern void sub_020698D0(void *);
extern void sub_020611C8(s32, s32, VecFx32Private *);
extern s32 MapObject_GetPreviousYCoord(void *);
extern u32 MapObject_GetPriorityPlusValue(void *, u32);
extern void ov01_021F1620(void *, const void *, const VecFx32Private *, u32, const EffectContextPrivate *, u32);
extern void *sub_02068D98(void *);
extern void ov01_021F1A34(u32, void *, u32, u32, u32);
extern void sub_02069998(void *, u32, void *);
extern s32 sub_02069948(void *);
extern void ov01_021F1640(void *);
extern void sub_020698E8(void *, s32, u32);
extern void sub_02068DB8(void *, VecFx32Private *);
extern void sub_020699BC(void *, const VecFx32Private *);
extern const u32 ov01_02209124[];

void *ov01_021FED9C(void *);
void ov01_021FEDB8(void *);
void ov01_021FEDC8(void *);
void ov01_021FEDF0(void *);
void ov01_021FEE04(void *, s32, s32, s32);
BOOL ov01_021FEE64(void *, void *);
void ov01_021FEE9C(void *, void *);
void ov01_021FEEA8(void *, void *);
void ov01_021FEED0(void *, void *);
