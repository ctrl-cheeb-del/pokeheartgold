#ifndef TO46_OV92_TEARDOWN_R2_PRIVATE_H
#define TO46_OV92_TEARDOWN_R2_PRIVATE_H

#include "global.h"

#define U32AT(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PAT(p, o)   (*(void **)((u8 *)(p) + (o)))

void Main_SetVBlankIntrCB(void *callback, void *arg);
void HBlankInterruptDisable(void);
void GF_DestroyVramTransferManager(void);
void sub_02021238(void);
void SetLCRNGSeed(u32 seed);
void ov92_0225E03C(void *work);
void ov92_0225DEF0(void *work);
void ov92_0225DF40(void *work);
void ov92_0225E918(void *work);
void ov92_0225E9A8(void *work);
void ov92_0225DA2C(void *object);
void sub_020180F8(void *object, void *resource);
void ov90_02258C38(void *roster);
void ov92_0225D49C(void *state);
int ov92_0225D8C4(void *state);
void ov92_0225EB68(void *work);
void ov92_0225ED60(void *work);
void ov92_0225D1FC(void *state);

#endif
