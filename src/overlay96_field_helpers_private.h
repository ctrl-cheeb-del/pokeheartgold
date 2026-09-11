#ifndef OV96_R42_PRIVATE_H
#define OV96_R42_PRIVATE_H
#include "global.h"
#define U32AT(p,o) (*(u32 *)((u8 *)(p)+(o)))
#define U16AT(p,o) (*(u16 *)((u8 *)(p)+(o)))
#define U8AT(p,o) (*(u8 *)((u8 *)(p)+(o)))
typedef struct Ov96R42Rec { u32 first; u32 low24:24; u32 high8:8; } Ov96R42Rec;
typedef struct Ov96R42Bits { u32 low3:3; u32 rest:29; } Ov96R42Bits;
typedef struct Ov96FieldRec { u32 f0; u32 f4; u32 f8; u32 fc; u32 f10; u32 f14; u32 f18; u32 f1c; } Ov96FieldRec;
typedef struct Ov96FieldData { Ov96FieldRec rec[4][3]; } Ov96FieldData;
#endif
