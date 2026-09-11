#ifndef PRIVATE_OVERLAY_80_02236B78_H
#define PRIVATE_OVERLAY_80_02236B78_H

#include "global.h"

typedef struct Ov80LevelRange {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
} Ov80LevelRange;

typedef struct Ov80MonSetup {
    u16 species : 11;
    u16 unk0_b : 5;
    u16 unk2;
    u32 dummy[(0x38 - 4) / 4];
} Ov80MonSetup;

typedef struct Ov80FrontierWork {
    u8 pad_00[4];
    u8 unk04;
    u8 unk05;
    u8 unk06;
    u8 pad_07[7];
    u16 unk0E;
    u8 pad_10[8];
    u16 unk18[14];
    u8 pad_34[0x254 - 0x34];
    u8 unk254[0x260 - 0x254];
    u8 unk260[0x268 - 0x260];
    u8 unk268[0x280 - 0x268];
    Ov80MonSetup unk280[6];
    u8 pad_3D0[0x4D4 - 0x3D0];
    void *unk4D4;
    void *unk4D8;
    u8 pad_4DC[0x4EC - 0x4DC];
    u16 unk4EC[2];
    u8 pad_4F0[0x4F8 - 0x4F0];
    void *unk4F8;
    u8 pad_4FC[0x57E - 0x4FC];
    u16 unk57E;
    u8 pad_580[0x584 - 0x580];
    u16 unk584[2];
    u8 pad_588[0x590 - 0x588];
    u8 unk590[0x598 - 0x590];
    u8 unk598[8];
} Ov80FrontierWork;

extern const Ov80LevelRange ov80_0223C478[];
extern const Ov80LevelRange ov80_0223C4B8[];
extern const Ov80LevelRange ov80_0223C508[];
extern const Ov80LevelRange ov80_0223C558[];

extern const Ov80LevelRange *ov80_0223DD38;

u16 LCRandom(void);
void GF_AssertFail(void);
void *AllocMonZeroed(int heapId);
void Heap_Free(void *ptr);
void SaveArray_Party_Init(void *party);
int Party_GetCount(void *party);
void Party_RemoveMon(void *party, int slot);
void ov80_0222A140(void *a0, void *a1, int a2);
void ov80_0222A3BC(void *a0, void *a1, void *a2);
void ov80_0222A52C(void *a0, void *a1, void *a2, void *a3, int a4, int a5, int a6, int a7);

int ov80_02236B78(int a0, u32 a1, int a2);
void ov80_02236BE4(int a0, int a1, u16 *a2, int a3);
const Ov80LevelRange *ov80_02236C2C(int a0, int a1);
const Ov80LevelRange *ov80_02236C78(int a0, int a1);
int ov80_02236DD4(int a0);
int ov80_02236DF8(int a0, int a1);
int ov80_022370F4(int a0);
int ov80_02237120(Ov80FrontierWork *work);
BOOL ov80_02237254(int a0);
int ov80_02237264(Ov80FrontierWork *work);
u16 ov80_022372B4(Ov80FrontierWork *work);
int ov80_02236C9C(const u16 *a0, const u16 *a1, int a2, int a3, u16 *a4, int a5, const Ov80LevelRange *a6, u16 a7, u8 *a8);
void ov80_02236E24(int a0, int a1, u16 *a2, void *a3, u8 *a4, int a5, u16 a6, const u16 *a7);
void ov80_02236E90(int a0, int a1, int a2, const Ov80MonSetup *a3, u16 *a4, void *a5, u8 *a6, int a7, int a8);
void ov80_02237130(Ov80FrontierWork *work);
void ov80_022371B0(Ov80FrontierWork *work);


/* Generated integration prototypes. */
int ov80_02236B78(int a0, u32 a1, int a2);
void ov80_02236BE4(int a0, int a1, u16 *a2, int a3);
const Ov80LevelRange *ov80_02236C2C(int a0, int a1);
const Ov80LevelRange *ov80_02236C78(int a0, int a1);
int ov80_02236DD4(int a0);
int ov80_02236DF8(int a0, int a1);
int ov80_022370F4(int a0);
int ov80_02237120(Ov80FrontierWork *work);
void ov80_02236E24(int a0, int a1, u16 *a2, void *a3, u8 *a4, int a5, u16 a6, const u16 *a7);
void ov80_02236E90(int a0, int a1, int a2, const Ov80MonSetup *a3, u16 *a4, void *a5, u8 *a6, int a7, int a8);
void ov80_02237130(Ov80FrontierWork *work);
void ov80_022371B0(Ov80FrontierWork *work);
BOOL ov80_02237254(int a0);
u16 ov80_022372B4(Ov80FrontierWork *work);
int ov80_02237264(Ov80FrontierWork *work);
#endif
