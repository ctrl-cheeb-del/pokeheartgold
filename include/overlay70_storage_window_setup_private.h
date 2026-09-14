#ifndef TO47_OV70_R15_PRIVATE_H
#define TO47_OV70_R15_PRIVATE_H

#include "global.h"

typedef struct Ov70WindowEntry {
    u32 bgId;
    u32 x;
    u32 y;
    u32 width;
} Ov70WindowEntry;

typedef struct Ov70Work {
    u8 pad0000[0xF18];
    u8 windowF18[0x40];
    u8 windowF58[0x100];
    u8 windows1058[14][0x10];
    u8 pad1138[0x60];
    u8 window1198[0x10];
} Ov70Work;

extern const Ov70WindowEntry ov70_022453B8[];

void AddWindowParameterized(void *, void *, u8, u8, u8, u8, u8, u8, u16);
void FillWindowPixelBuffer(void *, u8);
void RemoveWindow(void *);
void ov70_02239D44(void *, int);
void ov70_0223A0D4(Ov70Work *);
void ov70_0223A1A0(Ov70Work *);

#endif
