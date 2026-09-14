#ifndef TO45_OVERLAY96_R43_PRIVATE_H
#define TO45_OVERLAY96_R43_PRIVATE_H

#include "global.h"

typedef struct Ov96R43Record {
    u32 field00;
    u32 field04;
    u32 field08;
    u32 field0C;
    u32 field10;
    u32 field14;
    u32 field18;
    u32 field1C;
    u32 field20;
    u32 field24;
    u32 field28;
    u32 field2C;
    u32 field30;
    u32 field34;
    u32 field38;
    u32 field3C;
    u32 field40;
    u32 field44[10];
    u32 field6C;
    u32 field70;
} Ov96R43Record;

typedef struct Ov96R43Result {
    u32 field00;
    u32 field04;
} Ov96R43Result;

extern const u32 ov96_0221B124[29];
extern const u32 ov96_0221AF54[4];
extern void GF_AssertFail(void);
extern u32 MTRandom(void);
extern void *PokeathlonCourse_GetSaveData(void *);
extern void *Save_Pokeathlon_Get(void *);
extern Ov96R43Record *PokeathlonSave_GetAgainUnkB00(void *);
extern Ov96R43Record *PokeathlonCourse_GetField974_AtIndex(void *, int);
extern int ov96_021EDF7C(int);
extern int ov96_021EDF5C(u32);
extern void *PokeathlonCourse_GetParticipantData(void *, int);
extern const u8 *ov96_021E60D8(void *, int, int);
extern int ov96_021E8448(void *, u8);

void ov96_021EDF84(Ov96R43Record *, const Ov96R43Record *);
void ov96_021EDFFC(u8 *, const u32 *);
int ov96_021EE040(const u8 *, u8 *);
void ov96_021EE0AC(Ov96R43Result *, void *);
void ov96_021EE144(Ov96R43Result *, void *, int);

#endif
