#ifndef PRIVATE_H
#define PRIVATE_H
#include "global.h"

#include "gf_gfx_loader.h"
#include "party.h"
#include "pokemon.h"
#include "pokemon_icon_idx.h"
typedef struct Work {
    u8 d[0x500];
} Work;
void ov81_022409B0(Work *, void *, u8, int, int, int, int, int, int, void *);
void ov81_022423D0(Work *, void *);
void ov81_02242420(Work *, u32);
void ov81_022424AC(Work *, u32);
void *ov81_02242F30(void *);
void ov81_02242DCC(void *, void *);
void ov81_02242D88(void *, BOOL);
void ov81_0224218C(Work *);
void ov81_02242300(Work *, u32, u32);
void ov81_02242218(Work *, Party *, u32, u32);
void ov81_02242E14(void *, void *, u32, u32);
void ov81_02242E08(void *, u32);
#endif
