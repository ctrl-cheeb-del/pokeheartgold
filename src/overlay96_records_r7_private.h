#ifndef POKEHEARTGOLD_OVERLAY96_RECORDS_R7_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY96_RECORDS_R7_PRIVATE_H

#include "global.h"

typedef struct Ov96R7Work {
    u8 d[0xe00];
} Ov96R7Work;

#define OV96_R7_U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define OV96_R7_U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define OV96_R7_U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))

typedef struct Ov96R7FieldDataBits {
    u8 pad00[0x1d0];
    u16 flag : 1;
    u16 bit1 : 1;
    u16 value : 2;
    u16 rest : 12;
    u16 points;
} Ov96R7FieldDataBits;

extern void *PokeathlonCourse_GetDataCopyArea(Ov96R7Work *);
extern u32 ov96_021E5F24(Ov96R7Work *);
extern void GF_AssertFail(void);
extern u32 PokeathlonCourse_GetUnkConstant4(Ov96R7Work *);
extern void *ov96_021E8A20(void *);
extern void *ov96_021E9A14(void);
extern void *PokeathlonCourse_GetSystem(Ov96R7Work *);
extern BOOL ov96_021E87B4(u32, void *, void *, void *);
extern void *Save_Pokeathlon_Get(void *);
extern void *PokeathlonCourse_GetFieldData(Ov96R7Work *);
extern void *Save_VarsFlags_Get(void *);
extern void ov96_021E7FA8(Ov96R7Work *);
extern BOOL Save_VarsFlags_CheckFlagInArray(void *, u32);
extern BOOL ov96_021E8084(Ov96R7Work *);
extern void Save_VarsFlags_SetFlagInArray(void *, u32);
extern void PokeathlonSave_AddAthletePoints(void *, u32);
extern void *PokeathlonSave_GetRecordsLink2(void *);
extern void ov96_021E7A2C(Ov96R7Work *, void *);
extern void *PokeathlonSave_GetRecordsSolo(void *);
extern void *PokeathlonSave_GetUnkAEC(void *);
extern void ov96_021E7BA8(Ov96R7Work *, u16 *, u16 *);
extern void *PokeathlonSave_dummy2(void *);
extern void ov96_021E786C(Ov96R7Work *, void *);
extern BOOL ov96_021E8060(void *);
extern void *PokeathlonSave_GetRecordsSolo2(void *);
extern void ov96_021E7938(Ov96R7Work *, void *);
extern void *PokeathlonSave_GetAgainUnkB00(void *);
extern void ov96_021E7D6C(Ov96R7Work *, void *);
extern BOOL ov96_021E80C4(Ov96R7Work *);
extern BOOL ov96_021E7D18(int, int, u32);
extern const u8 _0221A7D8[];

#endif
