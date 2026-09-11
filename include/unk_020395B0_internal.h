#ifndef PRIVATE_UNK_020395B0_H
#define PRIVATE_UNK_020395B0_H
#include "global.h"

typedef void (*NetworkStateFunc)(void);
typedef struct SaveData SaveData;
typedef struct NetworkState395 {
    void *allocation;          /* 00 */
    u8 pad04[0x20];            /* 04 */
    NetworkStateFunc callback; /* 24 */
    SaveData *saveData;        /* 28 */
    void *profile;             /* 2c */
    void *userData;            /* 30 */
    u8 pad34[0x10];            /* 34 */
    s32 delay44;               /* 44 */
    u8 pad48[6];               /* 48 */
    u8 activity4E;             /* 4e */
    u8 parameter4F;            /* 4f */
    u8 pad50[0x10];            /* 50 */
    void *field60;             /* 60 */
    u8 active64;               /* 64 */
    u8 pad65[3];               /* 65 */
} NetworkState395;
typedef char NetworkState395_size[(sizeof(NetworkState395) == 0x68) ? 1 : -1];

extern NetworkState395 *_021D4150;
void GF_AssertFail(void);
BOOL ov00_021EC11C(u32 *, u32 *);
void ov00_021EC210(void);
int ov00_021E5B6C(void);
BOOL ov45_0222E804(void *);
void sub_020381C0(NetworkStateFunc, int);
void sub_02039C14(void);
void sub_02039DC0(void);
void sub_02039144(void);
void sub_02038E90(void);
BOOL sub_02034DB8(void);
BOOL sub_02035ED8(int, int, int, int);
int sub_02033FC4(u16);
void ov00_021E5900(SaveData *, int, u32, int);
void sub_020399DC(void);
void ov00_021E6CA4(NetworkStateFunc);
void sub_02035FD8(void);
void *Save_PlayerData_GetProfile(SaveData *);
BOOL sub_02037474(void *);
void sub_0201A728(int);
BOOL Heap_CreateAtEnd(int, int, u32);
void sub_02037C98(SaveData *, int);
void *Heap_Alloc(int, u32);
void MI_CpuFill8(void *, u8, u32);
void sub_02039BA0(void);
BOOL sub_020395B0(void);
void sub_0203960C(void);
void sub_02039694(void);
void *sub_020396FC(SaveData *, u32);
void sub_0203976C(SaveData *, void *);
#endif
