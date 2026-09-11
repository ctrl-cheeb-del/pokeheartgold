#ifndef TO40_OVERLAY64_PRIVATE_H
#define TO40_OVERLAY64_PRIVATE_H

#include "global.h"

typedef struct Overlay64Work {
    void *args;
    u8 filler_004[0x180];
    void *narc;
    u8 filler_188[0x30];
    u32 numRecords;
    u8 filler_1BC[0x14];
} Overlay64Work;

extern void HBlankInterruptDisable(void);
extern void sub_020210BC(void);
extern BOOL sub_02021148(int frequency);
extern void ov64_021E5B00(void);
extern void ov64_021E5B10(Overlay64Work *work);
extern void ov64_021E5CD0(Overlay64Work *work);
extern void ov64_021E607C(Overlay64Work *work);
extern void ov64_021E6170(Overlay64Work *work);
extern void ov64_021E622C(Overlay64Work *work);
extern void ov64_021E652C(Overlay64Work *work, int value);
extern void ov64_021E5A88(Overlay64Work *work);

#endif
