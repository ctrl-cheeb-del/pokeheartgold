#ifndef SOL_R40_FOLLOWUP_OV40_TAIL_R21_PRIVATE_H
#define SOL_R40_FOLLOWUP_OV40_TAIL_R21_PRIVATE_H
#include "global.h"
#pragma require_prototypes off
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
void GF_RunVramTransferTasks(void);
void PaletteData_PushTransparentBuffers(void *);
void DoScheduledBgGpuUpdates(void *);
typedef int (*SolStateFn)(void *);
extern SolStateFn ov40_022450F0[];
extern SolStateFn ov40_02245108[];
extern SolStateFn ov40_02245140[];
extern SolStateFn ov40_02245168[];
extern SolStateFn ov40_02245220[];
extern SolStateFn ov40_02245238[];
extern SolStateFn ov40_0224533C[];
extern SolStateFn ov40_02245368[];
extern SolStateFn ov40_02245470[];
extern SolStateFn ov40_022455F4[];
extern SolStateFn ov40_02245B98[];
extern SolStateFn ov40_02245B44[];
extern SolStateFn ov40_02245B30[];
extern SolStateFn ov40_02245CA8[];
void ov40_0222BF64(void *, int, int, void *);
void ov40_0222BF80(void *, int);
void ov40_02230D20(void *);
void Thunk_G3X_Reset(void);
void PokepicManager_DrawAll(void *);
void RequestSwap3DBuffers(int, int);
void ov40_0223D5E8(void *);
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#endif
