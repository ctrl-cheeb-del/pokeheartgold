#ifndef POKEHEARTGOLD_LINK_SYNCHRONIZATION_INTERNAL_H
#define POKEHEARTGOLD_LINK_SYNCHRONIZATION_INTERNAL_H
#include "global.h"

#include "heap.h"
#include "unk_02035900.h"
#include "unk_020379A0.h"
typedef struct SyncPacket {
    u8 data[0x48];
} SyncPacket;
typedef struct LinkSync {
    u8 values[8][2];
    u8 states[8];
    SyncPacket packets[8];
    u8 received[8];
    u8 resend, completed, requested, pending;
} LinkSync;
extern LinkSync *_021D414C;
BOOL sub_02037184(int, void *);
BOOL sub_020376E0(int, void *);
void sub_020379A0(enum HeapID heap);
void sub_020379F8(void);
BOOL sub_02037A10(void);
void sub_02037A24(int sender, int unused, u8 *data);
void sub_02037A98(int sender, int unused, u8 *data);
void sub_02037AAC(int sender, int unused, u8 *data);
void sub_02037AC0(u8 state);
void sub_02037ADC(void);
BOOL sub_02037B38(u8 state);
u8 sub_02037B5C(int index);
void sub_02037B6C(int sender, int unused, u8 *data);
u32 sub_02037B88(void);
void sub_02037B8C(u32 key, u8 value);
s32 sub_02037BA0(s32 sender, s32 key);
void sub_02037BC8(void);
void sub_02037BEC(void);
u32 sub_02037C0C(u32 index, s16 *data);
u16 *sub_02037C44(s32 index);
void sub_02037C68(int sender, int unused, void *data);

void sub_020379A0(enum HeapID heap);
void sub_020379F8(void);
BOOL sub_02037A10(void);
void sub_02037A24(int sender, int unused, u8 *data);
void sub_02037A98(int sender, int unused, u8 *data);
void sub_02037AAC(int sender, int unused, u8 *data);
void sub_02037AC0(u8 state);
void sub_02037ADC(void);
BOOL sub_02037B38(u8 state);
u8 sub_02037B5C(int index);
void sub_02037B6C(int sender, int unused, u8 *data);
u32 sub_02037B88(void);
void sub_02037B8C(u32 key, u8 value);
s32 sub_02037BA0(s32 sender, s32 key);
void sub_02037BC8(void);
void sub_02037BEC(void);
u32 sub_02037C0C(u32 index, s16 *data);
u16 *sub_02037C44(s32 index);
void sub_02037C68(int sender, int unused, void *data);

#endif
