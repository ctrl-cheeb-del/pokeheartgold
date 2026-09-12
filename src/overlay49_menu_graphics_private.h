#ifndef OVERLAY49_MENU_GRAPHICS_PRIVATE_H
#define OVERLAY49_MENU_GRAPHICS_PRIVATE_H

#include "global.h"

#define U8_AT(p, n)  (*(u8 *)((u8 *)(p) + (n)))
#define U16_AT(p, n) (*(u16 *)((u8 *)(p) + (n)))
#define U32_AT(p, n) (*(u32 *)((u8 *)(p) + (n)))
#define PTR_AT(p, n) (*(void **)((u8 *)(p) + (n)))
#define P_AT(p, n)   ((void *)((u8 *)(p) + (n)))

typedef struct Ov49Flags {
    u8 low : 4;
    u8 high : 4;
} Ov49Flags;
#define FLAGS_AT(p) (((Ov49Flags *)P_AT((p), 4))->high)

typedef struct Ov49Graphics {
    void *bgConfig;
    void *spriteList;
    u8 padding08[0x128];
    void *resourceManagers[4];
    void *cellTransfer;
    void *vramManager;
} Ov49Graphics;

#pragma require_prototypes off

extern u32 ov49_02269734[];
extern u16 ov49_02269754[];

void ov49_0225A840(void *);
void ov49_0225AA70(void *);
void *ov45_0222A394(void *);
void *Save_PlayerData_GetOptionsAddr(void *);
void *String_New(u32, u32);
void *WaitingIcon_New(void *, u32);

#endif
