#ifndef OV96_R96_H
#define OV96_R96_H
#include "global.h"
#define PTR(p, o)  (*(void **)((u8 *)(p) + (o)))
#define U32(p, o)  (*(u32 *)((u8 *)(p) + (o)))
#define SPRA(p, i) (((void **)((u8 *)(p) + 0x10))[i])
#define SPRB(p, i) (((void **)((u8 *)(p) + 0x18))[i])
typedef union W40 {
    u32 raw;
    struct {
        u32 g : 2;
        u32 h : 8;
        u32 i : 11;
        u32 j : 11;
    } b;
} W40;
typedef union W44 {
    u32 raw;
    struct {
        u32 a : 8;
        u32 e : 1;
        u32 f : 1;
        u32 s : 6;
        u32 c : 8;
        u32 d : 8;
    } b;
} W44;
typedef union WSlot {
    u32 raw;
    struct {
        u32 x : 9;
        u32 w : 9;
        u32 k : 8;
        u32 y : 6;
    } b;
} WSlot;
typedef struct R22Scene {
    void *course;
    u32 u04;
    u32 u08;
    void *ctx;
    void *spr[9];
    WSlot slot[3];
    W40 f40;
    W44 f44;
} R22Scene;
void GF_AssertFail(void);
void Sprite_DeleteAndFreeResources(void *);
void ManagedSprite_SetAnimateFlag(void *, int);
void ManagedSprite_SetAnim(void *, int);
void ManagedSprite_SetAnimNoRestart(void *, int);
void ManagedSprite_SetAnimSpeed(void *, fx32);
void ManagedSprite_SetDrawFlag(void *, int);
BOOL ManagedSprite_GetDrawFlag(void *);
BOOL ManagedSprite_IsAnimated(void *);
void ManagedSprite_SetPositionXYWithSubscreenOffset(void *, s16, s16, fx32);
void Heap_Free(void *);
void PlaySE(u16);
void ov96_0220C578(R22Scene *, int);
void ov96_021EAC5C(void *, int);
void SysTask_Destroy(void *);
void ov96_021E6168(void *, u8, u8, void *);
void ov96_021EEBE4(void *, void *, int, int, void *);
void ov96_0220B8F0(u8 *);
void ov96_0220C54C(void *, int, u8, u8, int);
void ov96_0220C680(R22Scene *);
void *ov96_0220C93C(void *, u32);
void *Heap_Alloc(u32, u32);
int PokeathlonCourse_GetParticipantCount(void *);
void ov96_0220C9F4(void *, u32, void *);
u16 ov96_0220B79C(R22Scene *);
u8 ov96_0220B7B4(R22Scene *);
u32 ov96_0220B7CC(R22Scene *);
void ov96_0220B8A0(u8 *);
void ov96_0220B8D8(u8 *);
void ov96_0220B940(void *, int);
void ov96_0220B95C(R22Scene *);
void ov96_0220B988(R22Scene *);
void ov96_0220C714(R22Scene *, int);
void ov96_0220C7C4(R22Scene *);
void ov96_0220C7FC(R22Scene *);
void ov96_0220C8B8(void *, u16, int);
void ov96_0220C90C(void *, int, s16, s16);

/* ---- Entry family: 0xC8 container = 0x14 header + Entry[3] stride 0x3c ---- */
typedef union W38 {
    u32 raw;
    struct {
        u32 a : 2;
        u32 b : 4;
        u32 c : 8;
        u32 d : 1;
        u32 e : 8;
        u32 f : 2;
        u32 g : 2;
        u32 h : 2;
        u32 z : 3;
    } b;
} W38;
typedef union RSlot {
    u32 raw;
    struct {
        u32 p : 8;
        u32 q : 8;
        u32 r : 8;
        u32 s : 2;
        u32 t : 1;
        u32 z : 5;
    } b;
} RSlot;
#define ECOURSE(p) (*(void **)((u8 *)(p)))
#define EA(p, i)   (((void **)((u8 *)(p) + 4))[i])
#define EB(p, i)   (((u32 *)((u8 *)(p) + 0x10))[i])
#define ESPR(p, i) (((void **)((u8 *)(p) + 0x1c))[i])
#define ETASK(p)   (*(void **)((u8 *)(p) + 0x34))
#define EW38(p)    (*(W38 *)((u8 *)(p) + 0x38))

typedef struct SprTmpl {
    s16 x;
    s16 y;
    s16 z;
    u16 animation;
    int drawPriority;
    int pal;
    int vram;
    int resIdList[6];
    int bgPriority;
    int vramTransfer;
} SprTmpl;

void ManagedSprite_SetPositionXY(void *, s16, s16);
void *SpriteSystem_NewSpriteWithYOffset(void *, void *, const SprTmpl *, fx32);
void *SysTask_CreateOnMainQueue(void (*)(void *, void *), void *, int);
u8 *PokeathlonCourse_GetDataCopyArea(void *);
void *ov96_021E8A20(void *);
u32 ov96_021E5F24(void *);
void ov96_021E8228(void *, u8, u8, int, int);
void *ov96_021EAA20(void *);
u16 *ov96_021E8BB0(void *);
void *ov96_021EAA04(void *, int);
void ov96_021EABA8(void *, int);
void ov96_021EAF94(void *, int, int);
void ov96_021EAC0C(void *, int);
void ov96_021EAB38(void *, u8);
void ov96_021EAB74(void *, int);
void ov96_0220C15C(void *, void *);

void ov96_0220BFB4(u8 *, int);
void ov96_0220C004(u8 *, RSlot *);
void ov96_0220C0DC(u8 *, RSlot *);
void ov96_0220C3E0(u8 *);
void ov96_0220C40C(u8 *);
void ov96_0220C490(void **, void *, void *);
BOOL ov96_0220C768(void *, fx32, fx32);
void ov96_0220C844(void *, u32);

#define SPRC(p, i) (((void **)((u8 *)(p) + 0x2c))[i])
BOOL IsSEPlaying(u16);
void ReadWholeNarcMemberByIdPair(void *, int, int);
u8 *ov96_021E60D8(void *, u32, u32);
void ov96_0220BE28(u8 *, void *, void *, void *, u8, void *, u32 *);
void ov96_0220BD38(R22Scene *);
void *ov96_0220B7F4(u32, void *, void *, void *, void *);

void *ov96_0220D13C(void *, void *, s16, int, int, int);
void ManagedSprite_SetAffineOverwriteMode(void *, u8);
void ManagedSprite_SetAffineScale(void *, f32, f32);

typedef struct Rec24 {
    u8 b[0x24];
} Rec24;

#endif
