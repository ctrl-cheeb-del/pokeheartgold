#ifndef TO45_OV102_R27_PRIVATE_H
#define TO45_OV102_R27_PRIVATE_H

#include "global.h"

#include "sprite.h"
#include "yes_no_prompt.h"

void ov102_021EAD5C(void *entry, s16 *out);
void *ov102_021EA268(void *p);

void ov102_021EAFF0(u8 *p, u16 index);
void ov102_021EB088(u8 *p, int enabled);
void ov102_021EB0C0(u8 *p, int initialCursorPos);
int ov102_021EB130(u8 *p);

#endif
