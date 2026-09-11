#ifndef SOL40_OV49_R58_PRIVATE_H
#define SOL40_OV49_R58_PRIVATE_H
#include "global.h"
typedef struct{u8 p[0x44];u32 input;} Sys;extern Sys gSystem;extern const u32 ov49_02269BE0[][2],ov49_02269B78[];
void *ov49_02259FEC(void*);void *ov49_0225A010(void*);int ov49_0225A02C(void*);void *ov49_02259FE8(void*);void ov45_0222A5E8(void*,int);void ov49_0225EF98(void*,int,const void*,int);
void *ov49_02259FF0(void*);void *ov49_02258C28(void*,void*);void *ov49_0225A008(void*);void ov49_02259154(void*,void*);void ov49_0225CC28(void*,u32,u32,u32);void *ov49_02258C5C(void*,void*,void*,void*);void ov49_02258E7C(void*,void*,int,void*);void ov49_0225CC40(void*,void*);u32 MTRandom(void);
void ov49_0225F1A8(void*);void ov49_0225F1F0(void*);int ov49_0225F224(int);void *ov49_0225F2FC(void*,void*);void ov49_0225F334(void*,void*,void*,void*,void*);void ov49_0225F374(void*);
#endif
