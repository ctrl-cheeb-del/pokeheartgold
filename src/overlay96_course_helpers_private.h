#ifndef OV96_R18_PRIVATE_H
#define OV96_R18_PRIVATE_H
#include "global.h"
#include "pokeathlon/pokeathlon.h"
#include "message_format.h"
#include "msgdata.h"
#include "string_util.h"
#include <nitro/mi/memory.h>

typedef struct Ov96R18Entry { u32 slot; u8 pad04[6]; u16 amount; } Ov96R18Entry;
typedef struct Ov96R18Work {
    s32 count;
    u8 pad004[0x0C];
    u32 ready;
    u32 totals[4];
    u8 pad024[0x120];
    Ov96R18Entry *entries[12];
    u32 results[10][4];
} Ov96R18Work;

extern void GF_AssertFail(void);
extern void *ov96_021E9344(void *);
extern BOOL ov96_021E5F24(PokeathlonCourseData *);
extern void ov96_021E604C(PokeathlonCourseData *);
extern void ov96_021E8484(PokeathlonCourseData *, u8);

void ov96_021E952C(Ov96R18Work *);
void ov96_021E9570(Ov96R18Work *, int);
u32 ov96_021E95D8(Ov96R18Work *, int, int);
void ov96_021E95F8(PokeathlonCourseData *, void *, u32,u32,u8,u8,u32);
void ov96_021E966C(PokeathlonCourseData *, void *, u32,u32,u32,u32,u8,u8,u8,u8,u32);
void ov96_021E96F8(u32,u32,u8 *,PokeathlonCourseData *);
void ov96_021E9718(int,u32,void *,PokeathlonCourseData *);
void ov96_021E9784(int,u32,void *,PokeathlonCourseData *);
void ov96_021E97B8(u32,u32,void *,PokeathlonCourseData *);
void ov96_021E97EC(u32,u32,u32,PokeathlonCourseData *);
void ov96_021E9820(int,u32,u8 *,PokeathlonCourseData *);
void ov96_021E9858(u32,u32,u32,PokeathlonCourseData *);
void ov96_021E9870(u32,u32,void *,PokeathlonCourseData *);
void ov96_021E98D0(u32,u32,void *,PokeathlonCourseData *);
void ov96_021E98F4(u32,u32,u32 *,PokeathlonCourseData *);
void ov96_021E9994(u32,u32,u32,PokeathlonCourseData *);
void ov96_021E99B8(u32,u32,u32,PokeathlonCourseData *);
#endif
