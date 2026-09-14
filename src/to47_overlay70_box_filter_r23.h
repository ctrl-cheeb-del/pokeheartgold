#ifndef TO47_OPUS_R2_OVERLAY_70_RESIDUAL_23_PRIVATE_H
#define TO47_OPUS_R2_OVERLAY_70_RESIDUAL_23_PRIVATE_H
#include "global.h"

extern u16 ov70_02245700[];

extern int AcquireBoxMonLock(void *);
extern void ReleaseBoxMonLock(void *, int);
extern int GetBoxMonData(void *, int, void *);

int ov70_0223E4FC(void *);
int ov70_0223E538(void *);

#endif
