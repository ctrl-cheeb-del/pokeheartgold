#ifndef TO40_SOL_R20_PRIVATE_H
#define TO40_SOL_R20_PRIVATE_H
#include "global.h"
#include <string.h>
extern u8 _0223B820[]; extern u8 _0223B4E0[]; extern u8 ov72_0223B5C4[]; extern u8 ov72_0223B578[]; extern u8 ov72_0223B900[]; extern u8 ov72_0223B91B[]; extern u8 ov72_0223B82C[]; extern u8 ov72_0223B60C[]; extern u8 ov72_0223B52C[]; extern u8 ov72_0223B920[]; extern u8 ov72_0223B834[]; extern u8 ov72_0223B923[];
extern void ov38_0221BE84(void); extern void ov38_0221BFEC(void);
extern u32 ov72_0223B37C[10];
extern int ov38_0221BEA8(void*,void*,void*,int,void*,int);
extern void GF_RunVramTransferTasks(void);
extern void DoScheduledBgGpuUpdates(void*);
extern void OamManager_ApplyAndResetBuffers(void);
extern void GfGfx_SetBanks(void*);
void ov72_02237C30(int,int,int,void*);
void ov72_02237CF4(void*,void*);
void ov72_02237B80(int); void ov72_02237BD0(int,int,void*); void ov72_02237CB0(void);
int ov72_02237D50(void*,void*,int,void*,int);
void ov72_022380FC(void*);
void ov72_02238124(void);
#endif
