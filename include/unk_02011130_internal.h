#ifndef PRIVATE_UNK_02011130_H
#define PRIVATE_UNK_02011130_H

typedef struct HBlankWindowBuffer {
    u8 current[192];
    u8 latched[192];
    int window;
} HBlankWindowBuffer;

typedef struct HBlankWindowWork {
    HBlankWindowBuffer buffer[2];
    u8 count;
    u8 screen;
} HBlankWindowWork;

void sub_02011130(void *data);
void GF_AssertFail(void);

#endif
