#ifndef UNK_02039BA0_PRIVATE_H
#define UNK_02039BA0_PRIVATE_H

#include "global.h"

typedef void (*NetworkStateFunc)(void);
typedef struct NetworkState39BA0 {
    void *allocation;
    u8 pad04[0x24];
    void *saveData;
    u8 pad2C[0x18];
    s32 delay44;
    u8 pad48[3];
    u8 comparison4B;
    u8 pad4C[2];
    u8 activity4E;
    u8 pad4F[4];
    u8 flag53;
} NetworkState39BA0;

extern NetworkState39BA0 *_021D4150;
extern BOOL sub_02034DB8(void);
extern int Heap_CreateAtEnd(int, int, u32);
extern int sub_02035ED8(int, int, int, int);
extern int sub_02033FC4(u16);
extern void ov00_021E5900(void *, int, int, int);
extern void ov00_021E6CA4(NetworkStateFunc);
extern void sub_02035FD8(void);
extern void ov00_021E70B8(int);
extern void sub_020378E4(int);
extern void sub_020381C0(NetworkStateFunc, int);
extern void sub_0203786C(int);
extern BOOL ov45_0222E8F4(void);
extern int sub_02037454(void);
extern int ov45_0222E6C8(void);
extern int ov00_021E5E54(int);

extern void sub_020399DC(void);
extern void sub_0203960C(void);
extern void sub_02038E90(void);
extern void sub_02038EB4(void);
extern void sub_02038EB0(void);
extern void sub_02039E7C(void);
extern void sub_02039DC0(void);

void sub_02039BA0(void);
void sub_02039C14(void);
void sub_02039C60(void);
BOOL sub_02039D3C(void);
BOOL sub_02039C6C(int value);
BOOL sub_02039D08(void);
void sub_02039D54(int *value);

#endif
