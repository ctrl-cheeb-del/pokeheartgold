#ifndef OVERLAY_02_02248728_RESIDUAL_9_PRIVATE_H
#define OVERLAY_02_02248728_RESIDUAL_9_PRIVATE_H

#include "global.h"

#define S32(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))

extern VecFx32 ov02_02253384;
extern VecFx32 ov02_02253408;

void *Sprite_GetMatrixPtr(void *sprite);
void Sprite_SetMatrix(void *sprite, const VecFx32 *matrix);
u32 GetMonData(void *mon, int attr, void *ptr);
void PlayCry(u16 species, u8 form);

void *ov02_0224A418(void *, VecFx32 *);
void *ov02_0224A9B8(void *, VecFx32 *);
void ov02_0224A9D8(void *, u32);
void ov02_0224A69C(void *, u32, u32, u32, u32);
void ov02_0224A450(void *);
void ov02_02249D40(void *);
void ov02_0224B72C(void *);
void ov02_0224B768(void *);

int ov02_022495E8(void *);
int ov02_02249658(void *);
int ov02_02249690(void *);
int ov02_022496D0(void *);
int ov02_02249754(void *);
int ov02_02249774(void *);
int ov02_022497C0(void *);
int ov02_02249838(void *);
int ov02_02249858(void *);
int ov02_022498BC(void *);

#endif
