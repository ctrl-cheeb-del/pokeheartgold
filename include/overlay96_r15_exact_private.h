#ifndef TO45_OVERLAY96_R15_EXACT_PRIVATE_H
#define TO45_OVERLAY96_R15_EXACT_PRIVATE_H

#include "global.h"

#include "follow_mon.h"
#include "sprite.h"

void GF_AssertFail(void);
void *ov96_021E8BAC(void *object);

u8 ov96_021E9180(const u8 *data, u32 offset);
int ov96_021E91B8(int species, int form, int gender);
void ov96_021E9204(void *object, f32 x, f32 y);
void ov96_021E9290(void *state);

#endif
