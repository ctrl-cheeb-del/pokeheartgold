#ifndef OVERLAY96_COURSE_R85_SORT_PRIVATE_H
#define OVERLAY96_COURSE_R85_SORT_PRIVATE_H

#include "global.h"

typedef struct Ov96R85Entry {
    u16 unk00;
    u16 unk02;
    u16 index;
    u16 score;
} Ov96R85Entry;

typedef struct Ov96R85Node {
    struct Ov96R85Node *prev;
    struct Ov96R85Node *next;
    Ov96R85Entry *entry;
} Ov96R85Node;

void GF_AssertFail(void);
u8 ov96_0220472C(u32 excludedGroup, Ov96R85Entry **entries, Ov96R85Entry **sorted);

#endif
