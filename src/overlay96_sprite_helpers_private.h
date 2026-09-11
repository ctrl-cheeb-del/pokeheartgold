#ifndef OV96_R31_PRIVATE_H
#define OV96_R31_PRIVATE_H
#include "global.h"
#include "sprite.h"
#include "sprite_transfer.h"
#include "heap.h"
#include "unk_0200A090.h"
#include "unk_02009D48.h"
#include <nitro/mi/memory.h>

typedef struct Ov96R31Rec { u16 active; u16 shown; Sprite *sprite; u16 kind; u16 id; } Ov96R31Rec;
typedef struct Ov96R31Config { s32 capacity; s32 resourceCount; u8 managerCounts[4]; } Ov96R31Config;
typedef struct Ov96R31Work { u32 heap; s32 used; Ov96R31Config config; void *spriteList; u8 pad18[0x128]; void *resources[4]; u8 *resourceRecords; Ov96R31Rec *records; } Ov96R31Work;
extern void GF_AssertFail(void);
extern void *ov96_021EAA04(void *, int);
extern void *ov96_021EAA20(void *);
extern void *ov96_021E8BAC(void *);
extern void **ov96_021EB5EC(Ov96R31Work *, int, int);
extern Sprite *ov96_021EB408(Ov96R31Work *, int, int, int, u8);
extern Ov96R31Rec *ov96_021EB4F4(Ov96R31Work *, int, int);
Ov96R31Work *ov96_021EB180(enum HeapID, const Ov96R31Config *);
void ov96_021EB21C(Ov96R31Work *);
void ov96_021EB144(Ov96R31Work *, BOOL);
void ov96_021EB2BC(Ov96R31Work *, NarcId, int, int, int);
void ov96_021EB2F4(Ov96R31Work *, NarcId, int, int, int, u8);
void ov96_021EB334(Ov96R31Work *, NarcId, int, int);
void ov96_021EB36C(Ov96R31Work *, NarcId, int, int);
void ov96_021EB29C(Ov96R31Work *, int, void *);
void ov96_021EB3A4(Ov96R31Work *);
Ov96R31Rec *ov96_021EB3E4(Ov96R31Work *, int, int, int, u8);
Ov96R31Rec *ov96_021EB4F4(Ov96R31Work *, int, int);
void ov96_021EB52C(Ov96R31Rec *, BOOL, BOOL);
#endif
