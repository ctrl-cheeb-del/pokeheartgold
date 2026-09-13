#ifndef SOL_R40_NIGHT_OVERLAY72_RESIDUAL5_PRIVATE_H
#define SOL_R40_NIGHT_OVERLAY72_RESIDUAL5_PRIVATE_H
#include "nitro/os/interrupt.h"

#include "global.h"

#include "nnsys/fnd/expheap.h"

#include "sprite.h"
extern const u16 ov72_0223B3A4[];
extern const u16 ov72_0223B3A6[];
extern const u16 ov72_0223B364[];
extern const u16 ov72_0223B366[];
extern NNSFndHeapHandle ov72_0223B92C;
void ov72_02238688(Sprite *, int, int);
void ov72_022386F4(Sprite *, int);
void ov72_02238730(Sprite *, int, int);
void ov72_02238750(Sprite *, int, int);
void *ov72_02238778(void *, u32, int);
#endif
