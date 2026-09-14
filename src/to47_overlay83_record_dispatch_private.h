#ifndef TO47_OVERLAY83_RECORD_DISPATCH_PRIVATE_H
#define TO47_OVERLAY83_RECORD_DISPATCH_PRIVATE_H

#include "global.h"

BOOL ov83_02241368(void *p, int kind, int param);
void ov83_022413C4(void *p, int value);
void ov83_0224140C(int id, void *unused, void *record, void *state);

/*
 * These parameters are intentionally 32-bit here. The existing shared declaration
 * uses u16, which inserts call-site narrowing and breaks ov83_02241368's match.
 * Keep this header private to this translation unit until the shared declaration
 * and its defining object can be reverified together.
 */
void ov83_0224143C(void *p, int value, int other);
void ov83_022414CC(void *p, int value);
void ov83_02241504(void *p, int value);
u16 ov83_0224777C(void *save, u8 a, u8 b);

void *Save_PlayerData_GetProfile(void *save);
int PlayerProfile_GetTrainerGender(void *profile);
int sub_0203769C(void);
int sub_02037030(int a, void *b, int c);

#endif
