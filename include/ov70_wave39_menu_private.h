#ifndef OV70_WAVE39_MENU_PRIVATE_H
#define OV70_WAVE39_MENU_PRIVATE_H
#include "global.h"
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define S16(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
typedef struct Pair39 {
    s32 a, b;
} Pair39;
typedef struct Work39 {
    u8 z0[4];
    void *windows;
    u8 z8[0x14];
    void *manager;
    u8 z20[0x14];
    void **items;
} Work39;
extern const s32 ov70_02245E84[];
extern const u8 ov70_02245D76[], ov70_02245D77[], ov70_02245DF8[], ov70_02245DF9[], ov70_02245E26[], ov70_02245E27[];
extern const Pair39 ov70_02245F5C[], ov70_02245F58[];
extern const s32 ov70_02245FA0[];
int Pokedex_CheckMonSeenFlag(void *, int);
void *ov70_0223F658(int, int, int *);
void *ListMenuItems_New(int, int);
void ListMenuItems_AppendFromMsgData(void *, void *, int, int);
void ListMenuItems_Delete(void *);
void Heap_Free(void *);
void FillWindowPixelBuffer(void *, int);
void CopyWindowPixelsToVram_TextMode(void *);
void sub_02019A60(void *, int, void *);
void ov70_02242FC4(void *, void *, void *, int, int);
void sub_02019688(void *, int, int, int, int);
void sub_02019B08(void *, int);
void sub_020196E8(void *, int, int, int);
void sub_020198FC(void *, int, int, int, int);
void ov70_0224190C(void *, int);
int ov70_02242508(int, int);
void ov70_02243F00(void *, void *, void *, int, int);
void ov70_02243EB8(void *, void *, void *, int);
void ov70_02243E8C(void *, void *, void *, int, int, int);
void Sprite_SetAnimCtrlSeq(void *, int);
void Sprite_SetDrawFlag(void *, int);
void ov70_02238F9C(void *, int, int);
int ov70_0224261C(void *);
int ov70_022429B8(void *, void *);
int ov70_02242390(void *, void *);
void ov70_02242D44(void *, int, int);
void ov70_02241DB4(void *, int);
void PlaySE(int);
void GF_AssertFail(void);
int ov70_02243FD4(void *, int);
int ov70_0224342C(void *, void *, int, const u16 *);
int ov70_02243458(void **, void *, void *, void *, int, void *);
void ov70_022434C0(void *, int, int);
void ov70_0224352C(void *, int, int);
int ov70_02243598(void *);
int ov70_02243688(void *);
int ov70_02243700(void *);
int ov70_02243750(void *);
int ov70_02243768(void *);
int ov70_022437C8(void *);
int ov70_02243848(void *);
int ov70_022438D4(void *);
int ov70_02243A6C(void *);
int ov70_02243AC4(void *);
#endif
