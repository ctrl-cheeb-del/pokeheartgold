#include "global.h"

#define PTR(p, off)  (*(void **)((u8 *)(p) + (off)))
#define WORD(p, off) (*(u32 *)((u8 *)(p) + (off)))
#define HALF(p, off) (*(u16 *)((u8 *)(p) + (off)))
#define BYTE(p, off) (*(u8 *)((u8 *)(p) + (off)))
#define SHRT(p, off) (*(s16 *)((u8 *)(p) + (off)))

typedef struct Ov40Tbl {
    s32 e[2][6];
} Ov40Tbl;

extern Ov40Tbl ov40_0224551C;
extern Ov40Tbl ov40_0224554C;

BOOL sub_0202FC48(void);
void *sub_02030920(int heapId);
void *sub_020314A4(int heapId);
void MI_CpuCopy8(const void *src, void *dest, u32 size);
void ManagedSprite_SetDrawFlag(void *sprite, BOOL draw);
void ManagedSprite_SetDrawPriority(void *sprite, int priority);
BOOL SpriteManager_UnloadCharObjById(void *manager, u32 id);
void ov39_022271C0(const void *src, void *dst);
void ov40_0222BF80(void *p, int state);
void ov40_0222DEAC(void *p);
void *ov40_0222FEA0(void *p, void *a1, void *a2, u32 a3, u32 a4, int a5);
void ov40_0222FF48(void *p, void *a1, void *a2);
void ov40_0222FF64(void *p, void *a1, void *a2);
int ov40_022303B8(void *p);
void ov40_02230944(void *p);
void ov40_02230964(void *p, int value);
void ov40_0223A3BC(void *p);
void ov40_0223CE38(void *p);

void ov40_0223CE64(u32 a, int b, void *p);
void ov40_0223CF00(u32 a, int b, void *p);
void ov40_0223CF70(u32 a, int b, void *p);
void ov40_0223CFA8(void *p);
void ov40_0223D008(void *p);
void ov40_0223D1AC(void *p, BOOL draw);
void ov40_0223D1F0(void *p);
void ov40_0223D244(void *p);

void ov40_0223D008(void *p);
void ov40_0223D1AC(void *p, BOOL draw);
void ov40_0223D1F0(void *p);
void ov40_0223D244(void *p);

void ov40_0223CE64(u32 a, int b, void *p) {
    void *inner = PTR(p, 0x860);

    if (b != 0) {
        return;
    }
    switch (a) {
    case 0:
        ov40_02230944(p);
        ov40_0222BF80(p, 8);
        break;
    case 1:
        ov40_02230944(p);
        if (sub_0202FC48()) {
            ov40_0222BF80(p, 9);
        } else {
            WORD(inner, 0x2034) = 9;
            ov40_0222BF80(p, 0x12);
        }
        break;
    case 2:
        ov40_02230944(p);
        if (sub_0202FC48()) {
            ov40_0222BF80(p, 0xb);
        } else {
            WORD(inner, 0x2034) = 0xb;
            ov40_0222BF80(p, 0x12);
        }
        break;
    case 3:
        ov40_02230944(p);
        ov40_0222BF80(p, 0xa);
        break;
    }
}

void ov40_0223CF00(u32 a, int b, void *p) {
    void *inner = PTR(p, 0x860);

    if (b != 0) {
        return;
    }
    switch (a) {
    case 0:
    case 1:
    case 2:
        WORD(inner, 0x2028) = a + 1;
        if (PTR((u8 *)p + WORD(inner, 0x2028) * 4, 0x88c) != NULL) {
            ov40_0222BF80(p, 0xe);
        } else {
            ov40_0222BF80(p, 0x11);
        }
        ov40_02230944(p);
        break;
    case 3:
        ov40_02230944(p);
        ov40_0222DEAC(p);
        ov40_0222BF80(p, 0xd);
        break;
    }
}

void ov40_0223CF70(u32 a, int b, void *p) {
    if (b != 0) {
        return;
    }
    switch (a) {
    case 0:
        ov40_02230944(p);
        ov40_0223CE38(p);
        ov40_0222BF80(p, 0x11);
        break;
    case 1:
        ov40_02230944(p);
        ov40_0222BF80(p, 0x10);
        break;
    }
}

void ov40_0223CFA8(void *p) {
    void *inner = PTR(p, 0x860);

    PTR(inner, 0x194) = sub_020314A4(0x6d);
    ov39_022271C0(PTR((u8 *)p + WORD(p, 0x4d4) * 4, 0x2608), PTR(inner, 0x194));
    PTR(inner, 0x220) = PTR(inner, 0x194);
    PTR(inner, 0x224) = sub_02030920(0x6d);
    MI_CpuCopy8((u8 *)PTR((u8 *)p + WORD(p, 0x4d4) * 4, 0x2608) + 0x80, PTR(inner, 0x224), 0x64);
}
