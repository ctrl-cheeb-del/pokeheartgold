#ifndef TO40_SOL_R23_PRIVATE_H
#define TO40_SOL_R23_PRIVATE_H
#include "global.h"
typedef struct {s16 species;s8 form;s8 level;} MonKey;
typedef struct {s16 species;s8 form;s8 level;s8 max;} Filter;
extern u16 ov70_02245700[];
extern int AcquireBoxMonLock(void*);extern void ReleaseBoxMonLock(void*,int);extern int GetBoxMonData(void*,int,void*);extern int CalcBoxMonLevel(void*);extern void *ov70_0223E49C(void);
int ov70_0223E4FC(void*);
int ov70_0223E59C(void*);int ov70_0223E5C8(void);int ov70_0223E5FC(void*,Filter*);void ov70_0223E738(MonKey*,void*,Filter*,void*);
int ov70_0223E658(void*,Filter*);
#endif
