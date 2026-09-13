#ifndef SOL_R40_FOLLOWUP_UNK0205857C_PRIVATE_H
#define SOL_R40_FOLLOWUP_UNK0205857C_PRIVATE_H
#include "global.h"
typedef struct Unk0205857CField {
    u8 pad00[8];
    void *unk08;
    u32 pad0C;
    u32 unk10;
    u8 pad14[0xbe];
    u8 low6 : 6;
    u8 high2 : 2;
} Unk0205857CField;
typedef struct Unk0205857CRoot {
    void *slots[4];
    u32 pad10;
    Unk0205857CField *field;
} Unk0205857CRoot;
extern Unk0205857CRoot *_021D41C8;
int sub_02037454(void);
int sub_0203769C(void);
int sub_02037B5C(int);
void Heap_Free(void *);
void StartMapSceneScript(Unk0205857CField *, int, int);
void sub_020399FC(int, void *);
void sub_0205857C(void);
#endif
