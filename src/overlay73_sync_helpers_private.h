#ifndef OV73_R9_PRIVATE_H
#define OV73_R9_PRIVATE_H
#include "global.h"
void ov73_021E756C(void *, int, int);
void ov73_021E670C(void *, int);
void ov73_021E66F0(void *);
void ov73_021E67A8(void *);
void sub_02037AC0(int);
int ov73_021E75FC(void *);
int ov73_021E6CC0(void *, int);
int ov73_021E6CDC(void *, int);
int ov73_021E6D38(void *, int);
int ov73_021E6E48(void *, int);
int ov73_021E6E6C(void *, int);
int ov73_021E6ECC(void *, int);
int ov73_021E6EF8(void *, int);
void BeginNormalPaletteFade(u32,u32,u32,u32,u32,u32,u32);
int sub_02037B38(int);
void sub_020398D4(int,int);
int sub_0203769C(void);
void *sub_02034818(int);
void BufferPlayersName(void *, int, void *);
void *sub_02037454(void);
int ov73_021E6CFC(void *, int);
int ov73_021E6DF8(void *, int);
int ov73_021E6E8C(void *, int);
typedef struct { u8 pad0[0x318]; s32 state; u8 pad31C[8]; s32 counter; u8 pad328[0x4704]; void *sync; s32 unk4A30; s32 countdown; } Ov73FarWork;
int ov73_021E6FAC(Ov73FarWork *, int);
void ov73_021E781C(void *, int);
int ov73_021E6FE8(Ov73FarWork *, int);
#endif
