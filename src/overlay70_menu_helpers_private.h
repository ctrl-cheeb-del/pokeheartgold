#ifndef OVERLAY70_MENU_HELPERS_PRIVATE_H
#define OVERLAY70_MENU_HELPERS_PRIVATE_H

#include "global.h"

#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define S16(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))

typedef struct Ov70R36 {
    u8 pad00[4];
    u8 *windows;
    u8 pad08[4];
    void *cursorSprite;
    void *rightSprite;
    void *leftSprite;
    u8 pad18[4];
    void *listMenu;
    u8 pad20[4];
    void *msgData;
    u8 pad28[0x34 - 0x28];
    struct Ov70Item *items;
    u8 pad38[0x48 - 0x38];
    s32 cursor;
    s32 state;
    s32 nextState;
    u8 pad54[0x5a - 0x54];
    s16 page;
    s32 count;
    s32 mode;
    u8 enabled[0x1a];
    u8 savedCursor;
} Ov70R36;

typedef struct Ov70Item {
    void *text;
    s32 value;
} Ov70Item;

typedef struct Ov70SystemR36 {
    u8 pad00[0x48];
    u32 newKeys;
    u32 newAndRepeatedKeys;
} Ov70SystemR36;

extern Ov70SystemR36 gSystem;
extern const u8 ov70_02245EFC[];
extern const u8 ov70_02245EFD[];
extern const u8 ov70_02245EFE[];
extern const u8 ov70_02245EFF[];
extern const u8 ov70_02245DF8[];
extern const u8 ov70_02245DF9[];
extern const u8 ov70_02245D8A[];
extern const u8 ov70_02245D8B[];
extern const u8 ov70_02245D76[];
extern const u8 ov70_02245D77[];

void PlaySE(u16);
void Sprite_SetAnimActiveFlag(void *, int);
void Sprite_SetAnimCtrlSeq(void *, int);
void ov70_02238F9C(void *, int, int);
int ov70_02242164(Ov70R36 *, int);
int ov70_022429A0(void *, int);
int ov70_02242508(int, int);
void ov70_0224352C(Ov70R36 *, int, int);
void ov70_02243F00(void *, void *, void *, int, int);
void sub_02019688(void *, int, int, int, int);
void sub_02019B08(void *, int);
void ov70_0224190C(Ov70R36 *, int);
void MI_CpuFill8(void *, u8, u32);
void *NewString_ReadMsgData(void *, int);
void String_Delete(void *);
int ov70_02243F7C(Ov70R36 *, int);
int ov70_02243FE0(Ov70R36 *, int);
void ov70_02243EB8(void *, void *, void *, int);
void sub_020196E8(void *, int, int, int);
void sub_020197F4(void *, int);
void sub_020198FC(void *, int, int, int, int);
void *ov70_0223F7E4(void *, void *, int);
void ov70_022434C0(Ov70R36 *, int, int);
void AddTextPrinterParameterizedWithColor(void *, int, void *, int, int, int, int, int);
void CopyWindowPixelsToVram_TextMode(void *);
void sub_02019A60(void *, int, void *);

int ov70_022429B8(Ov70R36 *, const u8 *);
int ov70_02242B5C(Ov70R36 *, int);
void ov70_02242BBC(Ov70R36 *, int);
int ov70_02242C64(Ov70R36 *);
void ov70_02242D44(Ov70R36 *, int, int);
void ov70_02242E58(Ov70R36 *);
void ov70_02242EE4(Ov70R36 *);
void ov70_02242FC4(void *, void *, void *, int, int);

#endif
