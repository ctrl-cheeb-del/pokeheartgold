#ifndef TO42_OV45_R12_PRIVATE_H
#define TO42_OV45_R12_PRIVATE_H

#include "nitro/mi/memory.h"

#include "global.h"

typedef struct Ov45Packet20 {
    u32 words[4];
    u8 kind;
    u8 flag;
    u8 value;
    u8 bits;
} Ov45Packet20;

extern int ov45_0222C95C(void *, int);
extern int ov45_0222C9D0(void *, int);
extern int ov45_0222C9EC(void *, int);
extern int ov45_0222C4E4(void *, int);
extern int ov45_0222C4FC(void *, int);
extern void ov45_0222EC3C(void *);
extern int ov45_0222ECA4(int);
extern int ov45_0222EC68(int);
extern u32 ov45_0222EC90(u32);
extern int ov45_0222ECDC(int);
extern void ov45_0222EEF0(int, const void *, int);
extern void GF_AssertFail(void);

int ov45_0222AB28(void *, int);
void ov45_0222AB38(void *, void *);
int ov45_0222AB48(void *, int);
int ov45_0222AB58(void *, int);
u32 ov45_0222AB68(void);
int ov45_0222AB78(int, int);
void ov45_0222AB94(int, u32, u32);
void ov45_0222ABD0(int, u32, u32, u8);
void ov45_0222ACB8(int, int, u8, u32, u32, u32, u32);
int ov45_0222AD2C(void);
int ov45_0222AD3C(void);
int ov45_0222AD4C(void);
u8 ov45_0222AD58(void *, u32);
void ov45_0222AD70(int, u32);
int ov45_0222AD80(void *, int);
int ov45_0222AD90(void *, int);

#endif
