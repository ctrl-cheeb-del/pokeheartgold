#ifndef TO47_OPUS_R1_OV83_11_PRIVATE_H
#define TO47_OPUS_R1_OV83_11_PRIVATE_H

#include "global.h"

#pragma require_prototypes off

#define U8_AT(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define S16_AT(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define U16_AT(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32_AT(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))
/* integer-first address form: reproduces the reference `add rd, rn=offset, rm=base` */
#define ELEM(o, b)   ((u8 *)(o) + (u32)(b))

void FillWindowPixelBuffer(void *, u8);
int GetWindowWidth(void *);
void ScheduleWindowCopyToVram(void *);
void AddTextPrinterParameterizedWithColor(void *, int, void *, int, int, int, u32, void *);
void ov83_022479E4(void *, void *, int, int, int, int, u32, int);
void ov83_02241DD8(void *, void *, void *, int, int, int, int, u32, int);
void ov83_02240C48(void *, int, int, int, int);
int ov83_02240EC4(void *, int, u8);
void ov83_02247998(void *, void *, int, int, int, u32, int);

void *Save_PlayerData_GetProfile(void *);
const u16 *PlayerProfile_GetNamePtr(void *);
u32 PlayerProfile_GetTrainerGender(void *);
void *String_New(u32, u32);
void String_Delete(void *);
void CopyU16ArrayToString(void *, const u16 *);
int FrontierSave_GetStat(void *, int, int);
int sub_0205C1F0(int);
int sub_0205C268(int);

void ov83_02240528(void *, int);
void ov83_02240664(void *);

#endif
