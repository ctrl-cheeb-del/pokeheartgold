#ifndef UNK_0208A2E0_PRIVATE_H
#define UNK_0208A2E0_PRIVATE_H

#include "global.h"

#include "constants/pokemon.h"

typedef struct SummarySelectionData {
    u8 *mons;
    u8 pad04[0xD];
    u8 source;
    u8 pad12;
    u8 count;
} SummarySelectionData;

typedef struct SummarySelectionWork {
    u8 pad000[0x22C];
    SummarySelectionData *selection;
} SummarySelectionWork;

extern int sub_02070D90(void);
extern int sub_02070D94(void);
extern void *Party_GetMonByIndex(void *, int);
extern int GetMonData(void *, int, void *);
extern int GetBoxMonData(void *, int, void *);
extern int sub_0208A3CC(SummarySelectionWork *);
extern int sub_0208A3F4(SummarySelectionWork *, int);
extern int sub_0208A45C(SummarySelectionWork *, int);
extern int sub_0208A4B8(SummarySelectionWork *, int);

int sub_0208A2E0(SummarySelectionWork *, int);
BOOL sub_0208A310(SummarySelectionWork *, int);

#endif
