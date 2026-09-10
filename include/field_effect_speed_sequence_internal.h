#ifndef PRIVATE_OV01_021FE590_H
#define PRIVATE_OV01_021FE590_H
#include "global.h"
typedef struct LocalManager {
    int refs, active;
    void *owner;
} LocalManager;
typedef struct LocalState {
    u32 pad0;
    int index;
    u32 finished;
    void *resource;
    LocalManager *manager;
    void *object, *effect;
} LocalState;
void *ov01_021F1430(void *, u32, u32, u32);
void ov01_021F1448(void *);
void GF_AssertFail(void);
void ov01_021F18D4(void *, int, int);
void ov01_021F1908(void *, int, int);
void ov01_021F1930(void *, int, int, int);
void ov01_021F1758(void *, int, int, int, int, int, const void *);
void ov01_021F18FC(void *, int);
void ov01_021F1924(void *, int);
void ov01_021F1970(void *, int);
void ov01_021F18C8(void *, int);
void *ov01_021F146C(void *);
void ov01_021F93AC(void *, VecFx32 *);
void *ov01_021F1450(void *, int);
void ov01_021F1620(void *, const void *, const VecFx32 *, void *, void *, int);
void *sub_02068D98(void *);
void sub_02068DB8(void *, VecFx32 *);
void *ov01_021F1740(void *, int, const VecFx32 *);
void sub_02023DA4(void *);
void sub_02023F1C(void *, fx32);
BOOL sub_02023F04(void *, fx32);
void sub_02023E50(void *, const VecFx32 *);
void ov01_021F1640(void *);
LocalManager *ov01_021FE590(void *);
void ov01_021FE5A4(LocalManager *);
void ov01_021FE5B4(LocalManager *);
void ov01_021FE5BC(LocalManager *);
void ov01_021FE5CC(LocalManager *);
void ov01_021FE61C(LocalManager *);
void ov01_021FE64C(LocalManager *);
void ov01_021FE65C(LocalManager *);
void ov01_021FE66C(void *);
BOOL ov01_021FE6B4(void *, LocalState *);
void ov01_021FE6F4(void *, LocalState *);
void ov01_021FE70C(void *, LocalState *);
void ov01_021FE768(void *, LocalState *);
#endif
