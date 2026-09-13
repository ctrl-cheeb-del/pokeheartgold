#ifndef POKEHEARTGOLD_OVERLAY96_COURSE_OBJECT_R102_GAP1_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY96_COURSE_OBJECT_R102_GAP1_PRIVATE_H

#include "global.h"

typedef struct Ov96R102Gap1ParticipantView {
    u16 species;
    u16 field2;
    u16 special;
    u8 kind;
    u8 field7;
    u32 participant;
    u32 fieldC;
} Ov96R102Gap1ParticipantView;

typedef struct Ov96R102Gap1Work {
    u32 heapId;
    void *course;
    u8 pad08[8];
    void *spriteManager;
    u8 pad14[8];
    void *field1C;
    void *objectManager;
} Ov96R102Gap1Work;

void *SpriteManager_GetSpriteList(void *);
void *ov96_021EA854(u32, u32, u32, void *, void *);
void ov96_021EB138(void *);
void ov96_021E6168(void *, int, int, Ov96R102Gap1ParticipantView *);
void *ov96_021E60C0(void *, int, int);
int ov96_021E6108(const void *);
void ov96_021EA8A8(void *, int, Ov96R102Gap1ParticipantView *, u32 *, u32, u32);

void ov96_0220F3FC(Ov96R102Gap1Work *);

#endif
