#include "overlay72_state_helpers_private.h"
typedef struct {u32 v[10];} BankConfig40;

void ov72_022380FC(void*w){volatile u32*a=(volatile u32*)0x027e0000;GF_RunVramTransferTasks();DoScheduledBgGpuUpdates(*(void**)((u8*)w+4));OamManager_ApplyAndResetBuffers();a[0x3ff8/4]|=1;}

void ov72_02238124(void){BankConfig40 b=*(BankConfig40*)ov72_0223B37C;GfGfx_SetBanks(&b);}
